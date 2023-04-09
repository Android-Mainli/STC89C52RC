//
// Created by Mainli on 2023/4/8.
//

#ifndef KEILPROJECT_BIT_UTIL_H
#define KEILPROJECT_BIT_UTIL_H

#include <stdio.h>

//右移31位，从最高为开始和1做&运算，得到每一位的二进制数值
void printbinry(int num) {
    int count = (sizeof(num) << 3) - 1;//值为31
    while (count >= 0) {
        int bitnum = num >> count; //除去符号位，从最高位开始得到每一位
        int byte = bitnum & 1; //和1进行与运算得到每一位的二进制数
        printf("%d", byte);

        if (count % 4 == 0) {//每隔四位打印空格
            printf(" ");
        }

        count--;
    }
    printf("\n");

}

unsigned int reverse_bit(unsigned int x, unsigned char num) {
    int bit_ = 0;
    int i;
    unsigned int sum = 0;
    for (i = 0; i < num; i++) {
        sum = sum << 1;
        bit_ = 1 & x;
        x = x >> 1;
        sum = sum | bit_;
    }
    return (sum);
}

#endif //KEILPROJECT_BIT_UTIL_H
