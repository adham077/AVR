#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "std_types.h"
#include "bit_math.h"

#define NO_OF_PORTS 4
#define NO_OF_PINS 8

#define MAX_PORT_NO (NO_OF_PORTS-1)
#define MAX_PIN_NO (NO_OF_PINS-1)

/* Port A Pins*/
#define PIN_A0 0x00
#define PIN_A1 0x01
#define PIN_A2 0x02
#define PIN_A3 0x03
#define PIN_A4 0x04
#define PIN_A5 0x05
#define PIN_A6 0x06
#define PIN_A7 0x07

// Port B Pins
#define PIN_B0 0x10
#define PIN_B1 0x11
#define PIN_B2 0x12
#define PIN_B3 0x13
#define PIN_B4 0x14
#define PIN_B5 0x15
#define PIN_B6 0x16
#define PIN_B7 0x17

// Port C Pins
#define PIN_C0 0x20
#define PIN_C1 0x21
#define PIN_C2 0x22
#define PIN_C3 0x23
#define PIN_C4 0x24
#define PIN_C5 0x25
#define PIN_C6 0x26
#define PIN_C7 0x27

// Port D Pins
#define PIN_D0 0x30
#define PIN_D1 0x31
#define PIN_D2 0x32
#define PIN_D3 0x33
#define PIN_D4 0x34
#define PIN_D5 0x35
#define PIN_D6 0x36
#define PIN_D7 0x37

//Direction Modes
typedef enum{
    MPORT_enu_dir_OUTPUT=0,
    MPORT_enu_dir_INPUT=1
}MPORT_enuPinDir_t;

//Pin Modes
typedef enum{
    MPORT_enu_NOT_AVAILABLE,
    MPORT_enu_OUTPUT,
    MPORT_enu_INPUT_PULLUP,
    MPORT_enu_INPUT_PULLDOWN,
    MPORT_enu_UART,
    MPORT_enu_SPI,
    MPORT_enu_PWM
}MPORT_enuPinMode_t;

//Error Status
typedef enum{
    MPORT_enu_OK,
    MPORT_enu_NOK,
    MPORT_enu_INVALID_PIN,
    MPORT_enu_INVALID_DIR
}MPORT_enuErorrStatus_t;

//Struct that holds data for each pin
typedef struct{
    uint8_t pin;
    MPORT_enuPinDir_t dir;
    MPORT_enuPinMode_t mode;
}MPORT_gstPinCFG_t;

//Array of structs holding data for each pin
extern MPORT_gstPinCFG_t MPORT_garrPin_CFG[NO_OF_PINS*NO_OF_PORTS];



#endif