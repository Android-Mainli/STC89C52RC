#include <8051.h>
#include <delayTime.h>

/**
 * 数码管
 */
unsigned char DigitalTubeNum[] = {0x3F, 0x6, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x7, 0x7F, 0x6F};

/**
* @parme location 位置 0-7
* @parme num 显示数字 0-9
*/
void DigitalTube(unsigned char location, unsigned char num) {
    /**
     *  消影 不消除本次位置会有上一个显示位置的影子
     *  原因如下：
     *      位选&数显 位选&数显 这样的顺序,不消除
     *      则扫描起来会出出现数显&位选的情况。
     */
    P0 = 0;
    P2_2 = 0x1 & location;
    P2_3 = 0x2 & location;
    P2_4 = 0x4 & location;
    P0 = DigitalTubeNum[num];
    DelayMs(1);//稳定显示一会，提高连续扫描切换时导致的亮度降低延时越长越亮
}

// 扫描数码管
void scanDigitalTube() {
    while (1) {
        int a;
        for (a = 0; a < 8; a++) {
            DigitalTube(a, a);
        }
    }
}