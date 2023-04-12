/**
 * 矩阵键盘扫描,默认管脚为高电平 扫描流程为一行先置低电位,
 * 然后逐列判断是否接通与低点位接通就变低点位
 */
#include "MatrixKeys.h"

#define MATRIX_ROW_1 P1_7
#define MATRIX_ROW_2 P1_6
#define MATRIX_ROW_3 P1_5
#define MATRIX_ROW_4 P1_4
#define MATRIX_COLUMN_1 P1_3
#define MATRIX_COLUMN_2 P1_2
#define MATRIX_COLUMN_3 P1_1
#define MATRIX_COLUMN_4 P1_0

int MatrixKeySanLocation() {
    //扫描矩阵键盘第一行P17
    MATRIX_ROW_1 = 0;
    MATRIX_ROW_2 = 1;
    MATRIX_ROW_3 = 1;
    MATRIX_ROW_4 = 1;
    if (MATRIX_COLUMN_1 == 0) {
        DelayMs(20);
        while (MATRIX_COLUMN_1 == 0);
        DelayMs(20);
        return 1;
    } else if (MATRIX_COLUMN_2 == 0) {
        DelayMs(20);
        while (MATRIX_COLUMN_2 == 0);
        DelayMs(20);
        return 2;
    } else if (MATRIX_COLUMN_3 == 0) {
        DelayMs(20);
        while (MATRIX_COLUMN_3 == 0);
        DelayMs(20);
        return 3;
    } else if (MATRIX_COLUMN_4 == 0) {
        DelayMs(20);
        while (MATRIX_COLUMN_4 == 0);
        DelayMs(20);
        return 4;
    }
    MATRIX_ROW_1 = 1;
    MATRIX_ROW_2 = 0;
    MATRIX_ROW_3 = 1;
    MATRIX_ROW_4 = 1;
    if (MATRIX_COLUMN_1 == 0) {
        DelayMs(20);
        while (MATRIX_COLUMN_1 == 0);
        DelayMs(20);
        return 5;
    } else if (MATRIX_COLUMN_2 == 0) {
        DelayMs(20);
        while (MATRIX_COLUMN_2 == 0);
        DelayMs(20);
        return 6;
    } else if (MATRIX_COLUMN_3 == 0) {
        DelayMs(20);
        while (MATRIX_COLUMN_3 == 0);
        DelayMs(20);
        return 7;
    } else if (MATRIX_COLUMN_4 == 0) {
        DelayMs(20);
        while (MATRIX_COLUMN_4 == 0);
        DelayMs(20);
        return 8;
    }
    MATRIX_ROW_1 = 1;
    MATRIX_ROW_2 = 1;
    MATRIX_ROW_3 = 0;
    MATRIX_ROW_4 = 1;
    if (MATRIX_COLUMN_1 == 0) {
        DelayMs(20);
        while (MATRIX_COLUMN_1 == 0);
        DelayMs(20);
        return 9;
    } else if (MATRIX_COLUMN_2 == 0) {
        DelayMs(20);
        while (MATRIX_COLUMN_2 == 0);
        DelayMs(20);
        return 10;
    } else if (MATRIX_COLUMN_3 == 0) {
        DelayMs(20);
        while (MATRIX_COLUMN_3 == 0);
        DelayMs(20);
        return 11;
    } else if (MATRIX_COLUMN_4 == 0) {
        DelayMs(20);
        while (MATRIX_COLUMN_4 == 0);
        DelayMs(20);
        return 12;
    }
    MATRIX_ROW_1 = 1;
    MATRIX_ROW_2 = 1;
    MATRIX_ROW_3 = 1;
    MATRIX_ROW_4 = 0;
    if (MATRIX_COLUMN_1 == 0) {
        DelayMs(20);
        while (MATRIX_COLUMN_1 == 0);
        DelayMs(20);
        return 13;
    } else if (MATRIX_COLUMN_2 == 0) {
        DelayMs(20);
        while (MATRIX_COLUMN_2 == 0);
        DelayMs(20);
        return 14;
    } else if (MATRIX_COLUMN_3 == 0) {
        DelayMs(20);
        while (MATRIX_COLUMN_3 == 0);
        DelayMs(20);
        return 15;
    } else if (MATRIX_COLUMN_4 == 0) {
        DelayMs(20);
        while (MATRIX_COLUMN_4 == 0);
        DelayMs(20);
        return 16;
    }
    return -1;
}

///**
// * 密码为1234的密码程序 S1-S10是1-9-0 S11删除一位 S12校验密码是否正确
// */
//#include "LCD1602.h"
//
//int main() {
//    LCD_Init();
//    LCD_ShowString(1, 0, "Passworld!");
//    unsigned int password = 0;
//    while (1) {
//        int location = MatrixKeySanLocation();
//        unsigned char input = location;
//        if (input < 0) {
//            continue;
//        }
//        if (input == 10) {
//            input = 0;
//        }
//        if (input < 9) {
//            if (password / 100000 < 1) {
//                password = password * 10 + input;
//            }
//        }
//        if (input == 11) {//删除以为
//            password /= 10;
//        }
//        if (input == 12) {//确认
//            if (password == 1234) {
//                LCD_ShowString(1, 14, " OK");
//            } else {
//                LCD_ShowString(1, 14, "ERR");
//            }
//            password = 0;
//        }
//        LCD_ShowNum(2, 0, password, 4);
//    }
//    return 0;
//}