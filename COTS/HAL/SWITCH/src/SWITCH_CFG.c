#include "SWITCH_CFG.h"

HSWITCH_stCFG_t HSWITCH_arrCFG[NUM_OF_SWITCHES]={
    [SWITCH_1] = {
        .port = MDIO_enu_PORTA,
        .pin = MDIO_enu_PIN0,
        .mode = HSWITCH_enu_PULLUP
    },
    [SWITCH_2] = {
        .port = MDIO_enu_PORTA,
        .pin = MDIO_enu_PIN1,
        .mode = HSWITCH_enu_PULLUP
    },
    [SWITCH_3] = {
        .port = MDIO_enu_PORTA,
        .pin = MDIO_enu_PIN2,
        .mode = HSWITCH_enu_PULLDOWN
    }
};