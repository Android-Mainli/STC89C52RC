# STC89C52RC

### CLion环境准备
1. 插件商店里安装PlatformlO for CLion插件
1. 安装[platformio](https://docs.platformio.org/en/latest/core/index.html),并[配置环境变量](https://docs.platformio.org/en/latest/core/installation/shell-commands.html)
1. 设置->Build, Execution, Deployment->Cmake->添加STC89C52RC编译类型
![step1.png](images/step1.png)
1. 右击`platformio.ini`选择PlatformIO->Update All</br>
![step2.png](images/step2.png)
1. 添加执行任务
![step3.png](images/step3-1.png)
![step3.png](images/step3-2.png)
****

### 模块化
include 放入公共头文件 部分实现放在core

****

### 注意事项:
1. 取反正确方式为：
   - ！符号是位取反（是“位”），只针对位变量。
   - ~符号是按位取反（是“按位”），针对字节变量
