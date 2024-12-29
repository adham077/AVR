#ifndef DIO_PORT_H_
#define DIO_PORT_H_

#include "DIO_CFG.h"


MPORT_enuErorrStatus_t MPORT_enuSetPinDirection( uint8_t Copy_enuPinNum,
uint8_t Copy_enuPinDirection );

MPORT_enuErorrStatus_t MPORT_enuSetPinMode(uint8_t Copy_enuPinNum,
uint8_t Copy_enuPinMode);

void MPORT_vInit(void);

#endif
