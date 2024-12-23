#include "DIO_Config.h"
#include "dio.h"
#define  MASK(X)  ((uint8_t)(1<<X))
#define NULL ((void*)0)

#define PTA_BASE 0x39
#define PTB_BASE 0x36
#define PTC_BASE 0x33
#define PTD_BASE 0x30

typedef struct{
    volatile uint8_t PIN;
    volatile uint8_t DDR;
    volatile uint8_t DOR;    
}MDIO_gst_PORT_t;

MDIO_gst_PORT_t* MDIO_gst_PORTA = (MDIO_gst_PORT_t*)PTA_BASE;
MDIO_gst_PORT_t* MDIO_gst_PORTB = (MDIO_gst_PORT_t*)PTB_BASE;
MDIO_gst_PORT_t* MDIO_gst_PORTC = (MDIO_gst_PORT_t*)PTC_BASE;
MDIO_gst_PORT_t* MDIO_gst_PORTD = (MDIO_gst_PORT_t*)PTD_BASE;

static MDIO_enu_errorStatus_t MDIO_enuGetPORT(MDIO_enu_PORTS_t Copy_enuPortNum,MDIO_gst_PORT_t** add_stPort){
    
    switch(Copy_enuPortNum){
        #ifdef PORTA
        case MDIO_enu_PORTA:
            *add_stPort = MDIO_gst_PORTA;
            break;
        #endif

        #ifdef PORTB
        case MDIO_enu_PORTB:
            *add_stPort = MDIO_gst_PORTB;
            break;
        #endif

        #ifdef PORTC
        case MDIO_enu_PORTC:
            *add_stPort = MDIO_gst_PORTC;
            break;
        #endif

        #ifdef PORTD
        case MDIO_enu_PORTD:
            *add_stPort = MDIO_gst_PORTD;
            break;
        #endif

        default:
            return MDIO_enu_INVALID_PORT;
    }
    return MDIO_enu_OK;
}


MDIO_enu_errorStatus_t MDIO_enuSetPinConfigration(MDIO_enu_PORTS_t Copy_enuPortNum, MDIO_enu_PINS_t Copy_enuPinNum,
MDIO_enu_pinConfig_t Copy_enuConfigration){
    
    if(Copy_enuPinNum>7){
        return MDIO_enu_INVALID_PIN;
    }

    if(Copy_enuConfigration>2){
        return MDIO_enu_INVALID_INPUT;
    }
    
    MDIO_gst_PORT_t* port = NULL;
    MDIO_enu_errorStatus_t status;

    status = MDIO_enuGetPORT(Copy_enuPortNum,&port);

    if(status!=MDIO_enu_OK){
        return status;
    }

    if(port==NULL){
        return MDIO_enu_NULL_POINTER;
    }

    switch(Copy_enuConfigration){
        case MDIO_enu_OUTPUT:
            port->DDR |= MASK(Copy_enuPinNum);
            break;
        
        case MDIO_enu_INPUT_PULLDOWN:
            port->DDR &= ~MASK(Copy_enuPinNum);
            port->DOR &= ~MASK(Copy_enuPinNum);
            break;

        case MDIO_enu_INPUT_PULLUP:
            port->DDR &= ~MASK(Copy_enuPinNum);
            port->DOR |= MASK(Copy_enuPinNum);
            break;
    }
    return status;
}

MDIO_enu_errorStatus_t MDIO_enuSetPinValue(MDIO_enu_PORTS_t Copy_enuPortNum,MDIO_enu_PINS_t Copy_enuPinNum,
MDIO_enu_pinState_t Copy_enuState){

    if(Copy_enuPinNum>7){
        return MDIO_enu_INVALID_PIN;
    }

    if(Copy_enuState>2){
        return MDIO_enu_INVALID_INPUT;
    }

    MDIO_gst_PORT_t* port = NULL;
    MDIO_enu_errorStatus_t status = MDIO_enuGetPORT(Copy_enuPortNum,&port);

    if(status!=MDIO_enu_OK){
        return status;
    }

    if(!((port->DDR>>Copy_enuPinNum)&0x1)){
        return MDIO_enu_INPUT_PIN;
    }

    switch(Copy_enuState){
        case MDIO_enu_LOW:
            port->DOR &= ~MASK(Copy_enuPinNum);
            break;
        
        case MDIO_enu_HIGH:
            port->DOR |= MASK(Copy_enuPinNum);
            break;
        
        default:
            return MDIO_enu_INVALID_INPUT;
    }

    return status;
}

MDIO_enu_errorStatus_t MDIO_enuGetPinValue(MDIO_enu_PORTS_t Copy_enuPortNum,MDIO_enu_PINS_t Copy_enuPinNum,uint8_t* Add_pu8PinValue){
    
    if(Copy_enuPinNum>7){
        return MDIO_enu_INVALID_PIN;
    }

    MDIO_gst_PORT_t* port = NULL;
    MDIO_enu_errorStatus_t status = MDIO_enuGetPORT(Copy_enuPortNum,&port);
    if(status!=MDIO_enu_OK){
        return status;
    }

    if((port->DDR>>Copy_enuPinNum)&0x1){
        return MDIO_enu_OUTPUT_PIN;
    }

    *Add_pu8PinValue = ((port->PIN>>Copy_enuPinNum)&0x01);
    return status;
}

MDIO_enu_errorStatus_t MDIO_enuSetPortConfigration(MDIO_enu_PORTS_t Copy_enuPortNum,MDIO_enu_pinConfig_t Copy_enuConfigration){    
    
    MDIO_gst_PORT_t* port = NULL;
    MDIO_enu_errorStatus_t status = MDIO_enuGetPORT(Copy_enuPortNum,&port);
    if(status != MDIO_enu_OK){
        return status;
    }

    switch(Copy_enuConfigration){
        case MDIO_enu_OUTPUT:
            port->DDR = MDIO_enu_PORT_HIGH;
            break;
        
        case MDIO_enu_INPUT_PULLDOWN:
            port->DDR = MDIO_enu_PORT_LOW;
            port->DOR = MDIO_enu_PORT_LOW;
            break;
        case MDIO_enu_INPUT_PULLUP:
            port->DDR = MDIO_enu_PORT_LOW;
            port->DOR = MDIO_enu_PORT_HIGH;
            break;
        default:
            return MDIO_enu_INVALID_INPUT;
    }

    return status;
}

MDIO_enu_errorStatus_t MDIO_enuSetPortValue(MDIO_enu_PORTS_t Copy_enuPortNum,uint8_t copy_u8PortVal){
    if(copy_u8PortVal>MAX_PORT_VAL){
        return MDIO_enu_INVALID_INPUT;
    }
    MDIO_gst_PORT_t* port = NULL;
    MDIO_enu_errorStatus_t status = MDIO_enuGetPORT(Copy_enuPortNum,&port);
    if(status!=MDIO_enu_OK){
        return status;
    }

    uint8_t value = ((port->DDR)&copy_u8PortVal) | (~(port->DDR)&(port->DOR));

    if(value&(~copy_u8PortVal)){
        return MDIO_enu_INPUT_PIN;
    }

    port->DOR = copy_u8PortVal;
    return status;
}

