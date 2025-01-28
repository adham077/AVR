#ifndef LCD_CFG_H_
#define LCD_CFG_H_
#include "std_types.h"
#include "PORT.h"
#include "DIO_PIN.h"
#ifndef F_CPU
#define F_CPU   1000000UL
#endif
#include "util/delay.h"



#define HLCD_8BIT_MODE  0
#define HLCD_4BIT_MODE  1

#ifndef HLCD_MODE
#define HLCD_MODE       HLCD_8BIT_MODE
#endif

#if HLCD_MODE==HLCD_8BIT_MODE
#define HLCD_NO_OF_DATA_PINS    8
#define HLCD_NO_OF_PINS         11
#else 
#define HLCD_NO_OF_DATA_PINS    4
#define HLCD_NO_OF_PINS         7
#endif
typedef unsigned short int u16;
//pins
typedef struct{
    uint8_t RS;   
    uint8_t RW; 
    uint8_t EN;      
    uint8_t data[HLCD_NO_OF_DATA_PINS];
    u16 FunSet;
    u16 EntryMode;
    u16 DisplaySettings;

}HLCD_stPins_t;

extern HLCD_stPins_t HLCD_stPins;

#endif