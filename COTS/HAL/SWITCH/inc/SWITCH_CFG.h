#ifndef SWITCH_CFG_H_
#define SWITCH_CFG_H_

#include "PORT.h"
#include "DIO_PIN.h"

#define NUM_OF_SWITCHES 3
#define MAX_SWITCH_NO (NUM_OF_SWITCHES-1)

#define SWITCH_1 0
#define SWITCH_2 1
#define SWITCH_3 2


typedef enum{
    HSWITCH_enu_PULLUP,
    HSWITCH_enu_PULLDOWN
}HSWITCH_enuMode_t;

typedef struct{
    MDIO_enuPORT_t port;
    MDIO_enuPIN_t pin;
    HSWITCH_enuMode_t mode;
}HSWITCH_stCFG_t;

extern HSWITCH_stCFG_t HSWITCH_arrCFG[NUM_OF_SWITCHES];

#endif