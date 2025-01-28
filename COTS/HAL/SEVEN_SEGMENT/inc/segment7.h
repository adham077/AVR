#ifndef    SEGMENT7_H_
#define    SEGMENT7_H_
#include "segment7_cfg.h"

typedef unsigned short int u16; 

/*Erorr status*/
typedef enum{
    H7SEG_enu_OK,
    H7SEG_enu_NOK
}H7SEG_enuErrorStatus_t;

/*Function Prototypes*/

/*The HSEVENSEG_vInit function is responsible for initializing and configuring the pins of
 seven-segment displays based on the provided configuration.*/
H7SEG_enuErrorStatus_t H7SEG_vInit(void);

/*The H7SEG_enuSetValue function is responsible for setting the value of a specific seven-segment display.*/
MDIO_enuErrorStatus_t H7SEG_enuSetValue(uint8_t Copy_u8Segment7Number,uint8_t Copy_u8Value);

/*The function HSEVENSEG_enuSetMultiDigitValue is used to display a 
multi-digit number (Copy_u16Value) across multiple seven-segment displays, 
depending on how many are configured*/
H7SEG_enuErrorStatus_t H7SEG_enuSetMulVal(u16 copy_u16Val);


#endif