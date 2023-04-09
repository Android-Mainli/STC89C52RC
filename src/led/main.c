#include <REGX52.H>
#include <delayTime.h>

/**
 * Led灯闪烁
 */
void testLEDLightFlashes() {
    while (1) {
        P2 = 0xFE;
        DelayMs(500);
        P2 = 0xFF;
        DelayMs(500);
    }
}

/**
 * 点亮LED灯
 */
void testLightUpTheLEDLight() {
    while (1) {
        P2 = 0x55;//0101 0101
    }
}


/**
 * led流水灯实现1
 */
void testLedWaterLamp() {
    while (1) {
        P2 = 0x7F;
        DelayMs(500);
        P2 = 0xBF;
        DelayMs(500);
        P2 = 0xDF;
        DelayMs(500);
        P2 = 0xEF;
        DelayMs(500);
        P2 = 0xF7;
        DelayMs(500);
        P2 = 0xFB;
        DelayMs(500);
        P2 = 0xFD;
        DelayMs(500);
        P2 = 0xFE;
        DelayMs(500);
    }
}

/**
 * led流水灯实现2
 */
void testLedWaterLamp2() {
    unsigned int ms = 500;
    while (1) {
        unsigned int index = 0x80;
        while (index) {
            P2 = index ^ 0xFF;
            index = index >> 1;
            DelayMs(ms);
            if (ms > 50) {
                ms -= 10;
            }
        }
        index = 0x02;
        while (index != 0x80) {
            P2 = index ^ 0xFF;
            index = index << 1;
            DelayMs(ms);
            if (ms > 50) {
                ms -= 10;
            }
        }
    }
}