#ifndef LED_H_
#define LED_H_

#include "LED_CFG.h"

typedef enum{
    HLED_enu_OK,
    HLED_enu_NOK
}HLED_enuErrorStatus_t;

HLED_enuErrorStatus_t HLED_init(void);
HLED_enuErrorStatus_t LED_enuSetState(uint8_t Copy_u8LED,uint8_t Copy_u8State);

#endif