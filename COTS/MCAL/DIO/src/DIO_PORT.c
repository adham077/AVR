#include "DIO_PORT.h"

#define PORTS_BASE 0X39

#define GET_PORT(portNum) (PORTS_BASE-(3*(uint8_t)(portNum)))

typedef struct{
    volatile uint8_t PIN;
    volatile uint8_t DDR;
    volatile uint8_t PORT;
}MPORT_gstPorts_t;

MPORT_enuErorrStatus_t MPORT_enuSetPinDirection( uint8_t Copy_enuPinNum,uint8_t Copy_enuPinDirection ){

    MPORT_enuErorrStatus_t Loc_enuStatus = MPORT_enu_OK;
    uint8_t Loc_u8PinVal = GET_LOW_NIB(Copy_enuPinNum);
    uint8_t Loc_u8PortVal = GET_HIGH_NIB(Copy_enuPinNum);

    if((Loc_u8PortVal>MAX_PORT_NO)||(Loc_u8PinVal>MAX_PIN_NO)){
        Loc_enuStatus = MPORT_enu_INVALID_PIN;
    }
    else{
        MPORT_gstPorts_t* Loc_pPort = (MPORT_gstPorts_t*)(GET_PORT(Loc_u8PortVal));
        switch (Copy_enuPinDirection){
            case MPORT_enu_dir_OUTPUT:
                SET_BIT(Loc_pPort->DDR,Loc_u8PinVal);
                break;

            case MPORT_enu_dir_INPUT:
                CLR_BIT(Loc_pPort->DDR,Loc_u8PinVal);
                break;

            default:
                Loc_enuStatus = MPORT_enu_INVALID_DIR;
                break;
        }
    }
    if(Loc_enuStatus==MPORT_enu_OK){
        uint8_t pos_in_arr = Loc_u8PortVal*MAX_PORT_NO+Loc_u8PinVal;
        MPORT_garrPin_CFG[pos_in_arr].dir = Copy_enuPinDirection; 
    }
    return Loc_enuStatus;
}

MPORT_enuErorrStatus_t MPORT_enuSetPinMode(uint8_t Copy_enuPinNum,uint8_t Copy_enuPinMode){

    MPORT_enuErorrStatus_t Loc_enuStatus = MPORT_enu_OK;
    uint8_t Loc_u8PinVal = GET_LOW_NIB(Copy_enuPinNum);
    uint8_t Loc_u8PortVal = GET_HIGH_NIB(Copy_enuPinNum);

    if((Loc_u8PortVal>MAX_PORT_NO)||(Loc_u8PinVal>MAX_PIN_NO)){
        Loc_enuStatus = MPORT_enu_INVALID_PIN;
    }
    else{
        MPORT_gstPorts_t* Loc_pPort = (MPORT_gstPorts_t*)(GET_PORT(Loc_u8PortVal));
        switch (Copy_enuPinMode){
            case MPORT_enu_OUTPUT:
                SET_BIT(Loc_pPort->DDR,Loc_u8PinVal);
                CLR_BIT(Loc_pPort->PORT,Copy_enuPinNum);
                break;

            case MPORT_enu_INPUT_PULLUP:
                CLR_BIT(Loc_pPort->DDR,Loc_u8PinVal);
                SET_BIT(Loc_pPort->PORT,Copy_enuPinNum);
                break;

            case MPORT_enu_INPUT_PULLDOWN:
                CLR_BIT(Loc_pPort->DDR,Loc_u8PinVal);
                CLR_BIT(Loc_pPort->PORT,Copy_enuPinNum);
                break;

            default:
                Loc_enuStatus = MPORT_enu_INVALID_DIR;
                break;
        }
    }
    if(Loc_enuStatus==MPORT_enu_OK){
        uint8_t pos_in_arr = Loc_u8PortVal*MAX_PORT_NO+Loc_u8PinVal;
        MPORT_garrPin_CFG[pos_in_arr].mode = Copy_enuPinMode; 
    }
    return Loc_enuStatus;
}

void MPORT_vInit(void){
    
    uint8_t i = 0;
    for(;i<(NO_OF_PINS*NO_OF_PORTS);i++){
        switch (MPORT_garrPin_CFG[i].mode){
            case MPORT_enu_OUTPUT:
                MPORT_enuSetPinMode(MPORT_garrPin_CFG[i].pin,MPORT_enu_OUTPUT);
                break;
            case MPORT_enu_INPUT_PULLDOWN:
                MPORT_enuSetPinMode(MPORT_garrPin_CFG[i].pin,MPORT_enu_INPUT_PULLDOWN);
                break;
            case MPORT_enu_INPUT_PULLUP:
                MPORT_enuSetPinMode(MPORT_garrPin_CFG[i].pin,MPORT_enu_INPUT_PULLUP);
                break;
            default:
                break;

        }
    }
}


