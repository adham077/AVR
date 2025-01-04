#include "LED_CFG.h"

HLED_stCFG_t HLED_arrCFG[NUM_OF_LEDS]={
    [LED_1] = {
        .port = MDIO_enu_PORTC,
        .pin = MDIO_enu_PIN0,
        .connection = HLED_enu_forward  
    },
    [LED_2] = {
        .port = MDIO_enu_PORTC,
        .pin = MDIO_enu_PIN1,
        .connection = HLED_enu_reverse
    },

    [LED_3] = {
        .port = MDIO_enu_PORTC,
        .pin = MDIO_enu_PIN2,
        .connection = HLED_enu_forward
    }
};