package main

import (
	"bufio"
	"context"
	"flag"
	"fmt"
	"github.com/rjeczalik/notify"
	"golang.org/x/text/encoding/simplifiedchinese"
	"os/exec"
	"path/filepath"
	"strconv"
)

func main() {
	protocol := flag.String("P", "auto", "协议支持{stc89,stc12a,stc12b,stc12,stc15a,stc15,stc8,usb15,auto}")
	serialPortDevice := flag.String("p", "/dev/tty.wchusbserial1110", "串口设备")
	firmware := flag.String("f", ".pio/build/STC89C52RC/firmware.hex", "要烧录的固件路径")
	flag.Parse()
	if *serialPortDevice == "" {
		fmt.Println("请输入串口号 如: -p /dev/tty.wchusbserial1110")
		return
	}
	if *firmware == "" {
		fmt.Println("请输入要烧录的固件路径 如: -f firmware.hex")
		return
	}
	firmwarePath, err := filepath.Abs(*firmware)
	if err != nil {
		fmt.Println("检测文件输入有误:", err)
		return
	}
	var cancelAuto context.CancelFunc = nil
	var cancelSingle context.CancelFunc = nil
	var input int = -9999999991111199
	for {
		if input == -9999999991111199 {
			input = 3
		} else {
			if cancelSingle == nil {
				printMenu(cancelAuto)
			}
			fmt.Scanf("%d", &input)
		}
		switch input {
		case 1:
			if cancelSingle != nil {
				fmt.Print("\n已经处于待上传中了,请操作串口,输入2可以取消:")
				break
			}
			uploadContext, cancel := context.WithCancel(context.Background())
			cancelSingle = cancel
			go func() {
				update(uploadContext, *protocol, *serialPortDevice, firmwarePath)
				cancelSingle = nil
				printMenu(cancelAuto)
			}()
			break
		case 2:
			if cancelSingle != nil {
				cancelSingle()
				cancelSingle = nil
				fmt.Println("取消本次上传")
			}
			break
		case 3:
			if cancelAuto != nil {
				break
			}
			ctx, cancel := context.WithCancel(context.Background())
			cancelAuto = cancel
			fmt.Printf("\n开启自动监测上传固件: %s\n", firmwarePath)
			go func() {
				eventInfos := make(chan notify.EventInfo, 1)
				if err := notify.Watch(firmwarePath, eventInfos, notify.All); err != nil {
					fmt.Println("\n检测文件失败:", err)
					return
				}
				for {
					select {
					case event := <-eventInfos:
						if event.Event()&notify.Remove != notify.Remove && firmwarePath == event.Path() {
							if cancelSingle == nil {
								uploadContext, cancel := context.WithCancel(context.Background())
								cancelSingle = cancel
								update(uploadContext, *protocol, *serialPortDevice, firmwarePath)
								cancelSingle = nil
								fmt.Println("\n---->>>> 自动中检测,输入2取消自动烧录")
							} else {
								fmt.Println("\n---->>>> 跳过本次自动检测,输入2取消自动烧录")
							}
						}
					case <-ctx.Done():
						notify.Stop(eventInfos)
						return
					}
				}
			}()
			break
		case 4:
			if cancelAuto != nil {
				cancelAuto()
				cancelAuto = nil
				fmt.Println("取消自动上传")
			}
			break
		case 99:
			return
		default:
			break
		}
		input = -1
	}
}

func printMenu(cancelAuto context.CancelFunc) (int, error) {
	return fmt.Printf("\nstcgal 辅助工具菜单如下:\n1. 上传固件\n2. 终止本次上传固件\n3. 开启自动烧录\n4. 取消自动烧录\n99. 退出\n随时请输入数字选择(自动上传:%s)->", strconv.FormatBool(cancelAuto != nil))
}

func update(ctx context.Context, protocol, serialPortDevice, firmware string) {
	fmt.Println("\n---->>>> 上传固件,需要循环开启电源!!!!!!!!!!!!")
	getOutputContinually(ctx, "stcgal", "-P", protocol, "-p", serialPortDevice, firmware)
	fmt.Println("---->>>> 上传结束!!!!!!!!!!!!")
}

func getOutputContinually(ctx context.Context, name string, args ...string) {
	cmd := exec.CommandContext(ctx, name, args...)
	fmt.Println(cmd)
	stdoutPipe, err := cmd.StdoutPipe()
	if err != nil {
		panic(err)
	}
	defer stdoutPipe.Close()
	go func() {
		scanner := bufio.NewScanner(stdoutPipe)
		for scanner.Scan() { // 命令在执行的过程中, 实时地获取其输出
			data, err := simplifiedchinese.GB18030.NewDecoder().Bytes(scanner.Bytes()) // 防止乱码
			if err != nil {
				fmt.Println("transfer error with bytes:", scanner.Bytes())
				continue
			}
			fmt.Printf("%s\n", string(data))
		}
	}()
	if err := cmd.Run(); err != nil {
		if "signal: killed" != err.Error() {
			fmt.Println("\n!!!!!!!!!!!!!!!!!!!!!!!!---->>>> stcgal上传错误", err.Error())
		}

	}
}
