#ifndef    SEGMENT7_H_
#define    SEGMENT7_H_
#include "segment7_cfg.h"
typedef unsigned short int u16; 

typedef enum{
    H7SEG_enu_OK,
    H7SEG_enu_NOK
}H7SEG_enuErrorStatus_t;

H7SEG_enuErrorStatus_t H7SEG_vInit(void);
MDIO_enuErrorStatus_t H7SEG_enuSetValue(uint8_t Copy_u8Segment7Number,uint8_t Copy_u8Value);
H7SEG_enuErrorStatus_t H7SEG_enuSetMulVal(u16 copy_u16Val);


#endif