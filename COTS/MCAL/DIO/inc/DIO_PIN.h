#ifndef DIO_PIN_H_
#define DIO_PIN_H_

#include "bit_math.h"
#include "std_types.h"

#define MIN_PORT_VAL 0
#define MAX_PORT_VAL 0xFF

#define MAX_PORT_NO 3
#define MAX_PIN_NO 7
#define MAX_PIN_VAL_NO 1
#define MAX_PORT_VAL_NO 1

//Ports
typedef enum{
    MDIO_enu_PORTA,
    MDIO_enu_PORTB,
    MDIO_enu_PORTC,
    MDIO_enu_PORTD
}MDIO_enuPORT_t;

//Pins
typedef enum{
    MDIO_enu_PIN0,
    MDIO_enu_PIN1,
    MDIO_enu_PIN2,
    MDIO_enu_PIN3,
    MDIO_enu_PIN4,
    MDIO_enu_PIN5,
    MDIO_enu_PIN6,
    MDIO_enu_PIN7,
}MDIO_enuPIN_t;

//Config modes
typedef enum{
    MDIO_enu_OUTPUT,
    MDIO_enu_INPUT_PULLUP,
    MDIO_enu_INPUT_PULLDOWN
}MDIO_enuPinConfig_t;

//Pin states
typedef enum{
    MDIO_enu_PIN_LOW,
    MDIO_enu_pin_HIGH
}MDIO_enuPinState_t;

//Port states
typedef enum{
    MDIO_enu_PORT_LOW,
    MDIO_enu_PORT_HIGH=0xFF
}MDIO_enuPortState_t;

//Error states
typedef enum{
    MDIO_enu_OK,
    MDIO_enu_NOK,
    MDIO_enu_INVALID_INPUT,
    MDIO_enu_INVALID_PORT,
    MDIO_enu_INVALID_PIN,
    MDIO_enu_INVALID_OPERATION,
    MDIO_enu_NULL_POINTER,
    MDIO_enu_INPUT_PIN,
    MDIO_enu_OUTPUT_PIN,
    MDIO_enu_INVALID_CFG
}MDIO_enuErrorStatus_t;

/*This API configures a specific pin within a port with the desired functionality, 
such as input, output, or pull-up/down configuration. It allows precise control over 
individual pins in a microcontroller's GPIO.*/
MDIO_enuErrorStatus_t MDIO_enuSetPinConfiguration(MDIO_enuPORT_t copy_enuPortNO,MDIO_enuPIN_t copy_enuPinNO,
MDIO_enuPinConfig_t copy_enuConfiguration);


/*This API configures all pins in a specific port at once, saving time when multiple
pins need the same configuration (e.g., all as inputs or outputs).*/
MDIO_enuErrorStatus_t MDIO_enuSetPortConfiguration(MDIO_enuPORT_t copy_enuPortNo,
MDIO_enuPinConfig_t copy_enuConfiguration);

/*This API sets the logical state of a specific pin (e.g., HIGH or LOW).*/
MDIO_enuErrorStatus_t MDIO_enuSetPinValue(MDIO_enuPORT_t Copy_enuPortNo,MDIO_enuPIN_t Copy_enuPinNo,
MDIO_enuPinState_t Copy_enuPinState);

/*This API sets the logical states of all pins in a specified port at once,
which is useful for initializing or modifying the state of a port efficiently.*/
MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPORT_t Copy_enuPortNo,
uint8_t Copy_u8Val);

/*This API retrieves the logical state (HIGH or LOW) of a specific pin.*/
MDIO_enuErrorStatus_t MDIO_enuGetPinVal(MDIO_enuPORT_t Copy_enuPortNo,MDIO_enuPIN_t Copy_enuPinNo,
uint8_t* Add_u8PinVal);

#endif