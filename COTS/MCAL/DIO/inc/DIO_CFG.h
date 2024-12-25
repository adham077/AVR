#ifndef DIO_CFG_H_
#define DIO_CFG_H_
#include "dio.h"
#include "DIO_Config.h"
#define NO_OF_PORTS 4
#define NO_OF_PINS 8


extern MDIO_enu_pinConfig_t MDIO_arrPinConfig[NO_OF_PORTS][NO_OF_PINS];
extern void MDIO_vpinsInit(void) ;

#endif