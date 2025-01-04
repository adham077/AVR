#include "LED.h"

HLED_enuErrorStatus_t HLED_init(void){
    
    int i=0;
    HLED_enuErrorStatus_t Loc_enuStatus = HLED_enu_OK;
    for(;i<NUM_OF_LEDS;i++){
        uint8_t Loc_u8PinVal = 0;
        ASSIGN_LOW_NIB(Loc_u8PinVal,HLED_arrCFG[i].pin);
        ASSIGN_HIGH_NIB(Loc_u8PinVal,HLED_arrCFG[i].port);
        Loc_enuStatus = MPORT_enuSetPinMode(Loc_u8PinVal,MPORT_enu_OUTPUT);
        if(Loc_enuStatus!=MDIO_enu_OK){
            break;
        }
    }
    return Loc_enuStatus;
}


HLED_enuErrorStatus_t LED_enuSetState(uint8_t Copy_u8LED,uint8_t Copy_u8State){

    HLED_enuErrorStatus_t Loc_enuStatus = HLED_enu_OK;
    if(Copy_u8LED>MAX_LED_NO){
        Loc_enuStatus = HLED_enu_NOK;
    }
    else{
        if(HLED_arrCFG[Copy_u8LED].connection==HLED_enu_forward){
            Loc_enuStatus = MDIO_enuSetPinValue(HLED_arrCFG[Copy_u8LED].port,HLED_arrCFG[Copy_u8LED].pin,
            Copy_u8State);            
        }
        else{
            Loc_enuStatus = MDIO_enuSetPinValue(HLED_arrCFG[Copy_u8LED].port,HLED_arrCFG[Copy_u8LED].pin,
            !Copy_u8State);  
        }
    }    
}

