#include "LED.h"

HLED_enuErrorStatus_t HLED_init(void){
    
    int i=0;
    HLED_enuErrorStatus_t Loc_enuStatus = HLED_enu_OK;
    /*Initialize all LEDs*/
    for(;i<NUM_OF_LEDS;i++){
        uint8_t Loc_u8PinVal = 0;
        /*Formatting input arguments for compatibility with port driver*/
        ASSIGN_LOW_NIB(Loc_u8PinVal,HLED_arrCFG[i].pin);
        ASSIGN_HIGH_NIB(Loc_u8PinVal,HLED_arrCFG[i].port);
        /*Set pin mode to output*/
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
        /*Set LED state*/
        if(HLED_arrCFG[Copy_u8LED].connection==HLED_enu_forward){
            Loc_enuStatus = MDIO_enuSetPinValue(HLED_arrCFG[Copy_u8LED].port,HLED_arrCFG[Copy_u8LED].pin,
            Copy_u8State);            
        }
        else{
            /*Reverse LED state if it is connected in reverse direction*/
            Loc_enuStatus = MDIO_enuSetPinValue(HLED_arrCFG[Copy_u8LED].port,HLED_arrCFG[Copy_u8LED].pin,
            !Copy_u8State);  
        }
    }    
}

