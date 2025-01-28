#include "SWITCH.h"

HSWITCH_enuErrorStatus_t HSWITCH_init(void){

    HSWITCH_enuErrorStatus_t Loc_enuStatus = MPORT_enu_OK;
    uint8_t i=0;
    for(;i<NUM_OF_SWITCHES;i++){
        uint8_t Loc_u8PinVal = 0;
        ASSIGN_LOW_NIB(Loc_u8PinVal,HSWITCH_arrCFG[i].pin);
        ASSIGN_HIGH_NIB(Loc_u8PinVal,HSWITCH_arrCFG[i].port);
        if(HSWITCH_arrCFG[i].mode==HSWITCH_enu_PULLUP){
            Loc_enuStatus = MPORT_enuSetPinMode(Loc_u8PinVal,MPORT_enu_INPUT_PULLUP);
            if(Loc_enuStatus!=MPORT_enu_OK){
                break;
            }
        }
        else if(HSWITCH_arrCFG[i].mode==HSWITCH_enu_PULLDOWN){
            Loc_enuStatus = MPORT_enuSetPinMode(Loc_u8PinVal,MPORT_enu_INPUT_PULLDOWN);
            if(Loc_enuStatus!=MPORT_enu_OK){
                break;
            }
        }
        else{
            Loc_enuStatus = HSWITCH_enu_NOK;
            break;
        }
    }
    return Loc_enuStatus;
}

HSWITCH_enuErrorStatus_t HSWITCH_enuGetValue(uint8_t Copy_u8Switch,uint8_t* Add_u8val){

    HSWITCH_enuErrorStatus_t Loc_enuStatus = HSWITCH_enu_OK;
    if(Copy_u8Switch>MAX_SWITCH_NO){
        Loc_enuStatus = MDIO_enu_NOK;
    }
    else{
        Loc_enuStatus = MDIO_enuGetPinVal(HSWITCH_arrCFG[Copy_u8Switch].port,
        HSWITCH_arrCFG[Copy_u8Switch].pin,Add_u8val);
    }

    if(HSWITCH_arrCFG[Copy_u8Switch].mode==HSWITCH_enu_PULLUP){
        *Add_u8val = !(*Add_u8val);
    }
    else{
        /*Keep the value as it is*/
    }
    return Loc_enuStatus;
}