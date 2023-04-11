#include <base.h>
#include "LCD1602.h"

int main() {
    LCD_Init();
    LCD_ShowString(2, 0, "Hello! 6");
    while (2) {

    }
    return 0;
}