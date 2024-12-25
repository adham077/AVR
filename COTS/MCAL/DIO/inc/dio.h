#ifndef DIO_H_
#define DIO_H_

#include "STD_Types.h"

#define MAX_PORT_VAL 0xFF

typedef enum{
    MDIO_enu_LOW,
    MDIO_enu_HIGH
}MDIO_enu_pinState_t;

typedef enum{
    MDIO_enu_PORT_LOW,
    MDIO_enu_PORT_HIGH = 0xFF
}MDIO_enu_portState_t;

typedef enum{
    MDIO_enu_OK,
    MDIO_enu_NOK,
    MDIO_enu_INVALID_INPUT,
    MDIO_enu_INVALID_PORT,
    MDIO_enu_INVALID_PIN,
    MDIO_enu_INVALID_OPERATION,
    MDIO_enu_NULL_POINTER,
    MDIO_enu_INPUT_PIN,
    MDIO_enu_OUTPUT_PIN
}MDIO_enu_errorStatus_t;

typedef enum{
    MDIO_ENU_NOT_AVAILABLE=0,
    MDIO_enu_OUTPUT,
    MDIO_enu_INPUT_PULLUP,
    MDIO_enu_INPUT_PULLDOWN,
}MDIO_enu_pinConfig_t;

typedef enum{
    MDIO_enu_PORTA,
    MDIO_enu_PORTB,
    MDIO_enu_PORTC,
    MDIO_enu_PORTD,
}MDIO_enu_PORTS_t;

typedef enum{
    MDIO_enu_PIN0,
    MDIO_enu_PIN1,
    MDIO_enu_PIN2,
    MDIO_enu_PIN3,
    MDIO_enu_PIN4,
    MDIO_enu_PIN5,
    MDIO_enu_PIN6,
    MDIO_enu_PIN7,
}MDIO_enu_PINS_t;

MDIO_enu_errorStatus_t MDIO_enuSetPinConfigration(MDIO_enu_PORTS_t Copy_enuPortNum, MDIO_enu_PINS_t Copy_enuPinNum,
MDIO_enu_pinConfig_t Copy_enuConfigration);

MDIO_enu_errorStatus_t MDIO_enuSetPinValue(MDIO_enu_PORTS_t Copy_enuPortNum,MDIO_enu_PINS_t Copy_enuPinNum,
MDIO_enu_pinState_t Copy_enuState);

MDIO_enu_errorStatus_t MDIO_enuGetPinValue(MDIO_enu_PORTS_t Copy_enuPortNum,MDIO_enu_PINS_t Copy_enuPinNum,uint8_t* Add_pu8PinValue);

MDIO_enu_errorStatus_t MDIO_enuSetPortConfigration(MDIO_enu_PORTS_t Copy_enuPortNum,MDIO_enu_pinConfig_t Copy_enuConfigration);

MDIO_enu_errorStatus_t MDIO_enuSetPortValue(MDIO_enu_PORTS_t Copy_enuPortNum,uint8_t copy_u8PortVal);

void MDIO_vInit(void);


#endif