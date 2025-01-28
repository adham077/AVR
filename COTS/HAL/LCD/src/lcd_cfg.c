#include "lcd.h"

HLCD_stPins_t HLCD_stPins = {
    .RS = PIN_A7,
    .RW = PIN_A6,
    .EN = PIN_A5,
    .data[0] = PIN_A4,
    .data[1] = PIN_A3,
    .data[2] = PIN_A2,
    .data[3] = PIN_A1,
    .data[4] = PIN_A0,
    .data[5] = PIN_B2,
    .data[6] = PIN_B1,
    .data[7] = PIN_B0,
    .FunSet = HLCD_FUNC_SET_8BIT_2LINE_5x10,
    .EntryMode = HLCD_ENT_CUR_LEFT,
    .DisplaySettings = HLCD_DISP_ON
};