#ifndef LED_CFG_H_
#define LED_CFG_H_

/* LED Configuration*/
#define NUM_OF_LEDS 3
#define LED_1 0
#define LED_2 1
#define LED_3 2

#define MAX_LED_NO (NUM_OF_LEDS-1)

#include "DIO_PIN.h"
#include "PORT.h"
/* LED Connection Type*/
typedef enum{
    HLED_enu_forward,
    HLED_enu_reverse
}HLED_enuConnection_t;

/* LED Configuration Structure*/
typedef struct{
    MDIO_enuPORT_t port;
    MDIO_enuPIN_t pin;     
    HLED_enuConnection_t connection;
}HLED_stCFG_t;

/* Array of LED Configuration*/
extern HLED_stCFG_t HLED_arrCFG[NUM_OF_LEDS];

#endif