#include "lcd.h"
int main(void){

    uint8_t smiley_face[8] = {
        0b00000000,
        0b00010001,
        0b00000000,
        0b00000000,
        0b00010001,
        0b00001110,
        0b00000000,
    };

    HLCD_vInit();
    while(1){
        HLCD_enuWriteStr("Adham Walaa:",0,0);
        HLCD_enuWriteNO(07,0,12);
        HLCD_enuPrintSpecialChar(smiley_face,0,1,7);
    }
    return 0;
}