#ifndef SEGMENT7_CFG_H_
#define SEGMENT7_CFG_H_

#include "PORT.h"
#include "DIO_PIN.h"

/*Number of seven-segment displays*/
#define NO_OF_7SEG 2
#define MAX_7SEG_NO (NO_OF_7SEG-1) 

/*Seven-segment displays:*/
#define SEGMENT7_1 0
#define SEGMENT7_2 1

/*Seven-segment display modes:*/
typedef enum{
    H7SEG_MODE_COMMON_CATHODE,
    H7SEG_MODE_COMMON_ANODE
}H7SEG_enuMode_t;

/*Seven-segment display configurations struct:*/
typedef struct{
    H7SEG_enuMode_t segment7_mode;
    uint8_t segment7_pins[8];
}H7SEG_stConfig_t;

/*Seven-segment display configurations arrray:*/
extern H7SEG_stConfig_t H7SEG_arrConfigParam[NO_OF_7SEG];

#endif