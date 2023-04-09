//
// Created by Mainli on 2023/4/9.
//

#ifndef TEST_DELAYTIME_H
#define TEST_DELAYTIME_H

/**
 * 自旋延迟
 * @param xms 毫秒数
 */
void DelayMs(unsigned int xms)        //@12.000MHz
{
    unsigned char i, j;
    while (xms--) {
        i = 2;
        j = 239;
        do {
            while (--j);
        } while (--i);
    }
}

#endif //TEST_DELAYTIME_H
