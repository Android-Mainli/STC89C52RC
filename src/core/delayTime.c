//
// Created by Mainli on 2023/4/9.
//

#include "delayTime.h"
/**
 * 自旋延迟
 * @param xms 毫秒数
 */
void DelayMs(unsigned int xms) {
    unsigned char i, j;
    while (xms--) {
        i = 2;
        j = 239;
        do {
            while (--j);
        } while (--i);
    }
}