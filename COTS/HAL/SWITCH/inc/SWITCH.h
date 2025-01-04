#ifndef SWITCH_H_
#define SWITCH_H_

#include "SWITCH_CFG.h"

typedef enum{
    HSWITCH_enu_OK,
    HSWITCH_enu_NOK
}HSWITCH_enuErrorStatus_t;

HSWITCH_enuErrorStatus_t HSWITCH_init(void);

HSWITCH_enuErrorStatus_t HSWITCH_enuGetValue(uint8_t Copy_u8Switch,uint8_t* Add_u8val);

#endif