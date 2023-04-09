#include "base.h"
#include "core/bitUtils.h"

/**
 * LED二进制递增
 */
void independentButtonLEDBinaryIncrement() {
    //0000 0000
    unsigned int num = 0;
    while (1) {
        //默认高电压
        if (P3_1 == 0) {
            DelayMs(20);
            while (P3_1 == 0);//持续按下则不做处理
            DelayMs(20);
            if (P3_1 == 1) {//抬起状态
                num++;
                //LED是在从左边开始是低位 这里翻转二进制并且 取反是为了用0低电压点亮
                P2 = ~reverse_bit(num, 8);
            }
        }
    }
}

/**
 * 开闭LED
 */
void independentButtonLEDOpenClose() {
    while (1) {
        //默认状态是高电平
        if (P3_1 == 0) {
            DelayMs(20);//按下消抖动 抖动时间10-15ms
            while (P3_1 == 0);//持续按下则不变
            DelayMs(20);//抬起消抖动
            P2_7 = ~P2_7;
        }
    }
}


/**
 * k1 k2 切换LED左右移动
 */
void independentButtonK1K2Switch() {
    unsigned char index = 0x10;
    while (1) {
        //默认高电平 低电平则为按下
        if (P3_1 == 0) {
            DelayMs(20);//消除跳动
            while (P3_1 == 0);//等待抬起
            DelayMs(20);//消除抬起跳动
            if (index != 0x01) {
                index = index >> 1;
            } else {
                index = 0x80;
            }
        } else if (P3_0 == 0) {
            DelayMs(20);//消除跳动
            while (P3_0 == 0);//等待抬起
            DelayMs(20);//消除抬起跳动
            if (index != 0x80) {
                index = index << 1;
            } else {
                index = 0x01;
            }
        }
        P2 = ~index;
    }
}

/**
* k1 控制风扇  风扇接步进电机5V与OUT1接口
*/
void independentButtonK1FanSwitch() {
    P1_0 = 0;
    while (1) {
        if (P3_1 == 0) {
            DelayMs(20);
            while (P3_1 == 0);
            DelayMs(20);
            P1_0 = ~P1_0;
        }
    }
}