#ifndef DIO_PORT_H_
#define DIO_PORT_H_

#include "DIO_CFG.h"

/*The Port_SetPinDirection API is part of the AUTOSAR Port Driver module. it allows you to change the direction of 
a specific microcontroller pin at runtime. Pin direction determines whether the pin:*/
MPORT_enuErorrStatus_t MPORT_enuSetPinDirection( uint8_t Copy_enuPinNum,
uint8_t Copy_enuPinDirection );

/*The Port_SetPinMode function is part of the AUTOSAR Port Driver module. Its primary purpose 
is to configure the mode of a specific pin during runtime. The mode determines 
the pin's behavior -> digital communication pin (e.g., UART, SPI), or if it uses 
internal pull-up or pull-down resistors.*/
MPORT_enuErorrStatus_t MPORT_enuSetPinMode(uint8_t Copy_enuPinNum,
uint8_t Copy_enuPinMode);

/*The DIO_init function initializes all digital I/O pins based on the configuration defined 
in the PinCfg array.*/
void MPORT_vInit(void);

#endif
