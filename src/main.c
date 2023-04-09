//<editor-fold desc="LED灯相关">
// Led灯
extern void testLightUpTheLEDLight();

// Led灯闪烁
extern void testLEDLightFlashes();

// Led流水灯
extern void testLedWaterLamp();

// Led流水灯2
extern void testLedWaterLamp2();
//</editor-fold>

//<editor-fold desc="数码管相关">
// digitalTube
extern void scanDigitalTube();
//</editor-fold>

//<editor-fold desc="独立按键">
// 独立按键 - k1 LED二进制递增
extern void independentButtonLEDBinaryIncrement();

// 独立按键 - k1 LED开关
extern void independentButtonLEDOpenClose();

// 独立按键 - k1 k2 控制LED左右移动
extern void independentButtonK1K2Switch();

// 独立按键 - k1 控制风扇
extern void independentButtonK1FanSwitch();

//</editor-fold>

int main() {
    testLEDLightFlashes();
    return 0;
}