#include "segment7.h"

static const uint8_t H7SEG_arrValuesMap[10]={
    0b00111111,
    0b00000110,
    0b01011011,
    0b01001111,
    0b01100110,
    0b01101101,
    0b01111101,
    0b00000111,
    0b01111111,
    0b01101111
};

typedef struct{
    uint8_t port;
    uint8_t pin;
}H7SEG_stPinval_t;

H7SEG_stPinval_t H7SEG_arrPinVal[NO_OF_7SEG][8];

H7SEG_enuErrorStatus_t H7SEG_vInit(void){

    H7SEG_enuErrorStatus_t Local_enuStatus = H7SEG_enu_OK;
    uint8_t i=0;
    for(;i<NO_OF_7SEG;i++){
        uint8_t j=0;
        for(;j<8;j++){
            Local_enuStatus = MPORT_enuSetPinMode(H7SEG_arrConfigParam[i].segment7_pins[j],MPORT_enu_OUTPUT);
            if(Local_enuStatus != H7SEG_enu_OK){
                break;
            }
            H7SEG_arrPinVal[i][j].port = GET_HIGH_NIB(H7SEG_arrConfigParam[i].segment7_pins[j]);
            H7SEG_arrPinVal[i][j].pin = GET_LOW_NIB(H7SEG_arrConfigParam[i].segment7_pins[j]);
        }
        if(Local_enuStatus != H7SEG_enu_OK){
            break;
        }
    }
    return Local_enuStatus;
}


MDIO_enuErrorStatus_t H7SEG_enuSetValue(uint8_t Copy_u8Segment7Number,uint8_t Copy_u8Value){

    H7SEG_enuErrorStatus_t Local_enuStatus = H7SEG_enu_OK;
    if(Copy_u8Segment7Number>MAX_7SEG_NO){
        Local_enuStatus = H7SEG_enu_NOK;
    }
    else if(Copy_u8Value>9){
        Local_enuStatus = MDIO_enu_NOK;
    }
    else{
        uint8_t i=0;
        for(;i<8;i++){
            Local_enuStatus = MDIO_enuSetPinValue(H7SEG_arrPinVal[Copy_u8Segment7Number][i].port,
            H7SEG_arrPinVal[Copy_u8Segment7Number][i].pin,
            GET_BIT(H7SEG_arrValuesMap[Copy_u8Value],i)^H7SEG_arrConfigParam[Copy_u8Segment7Number].segment7_mode);
            
            if(Local_enuStatus != H7SEG_enu_OK){
                break;
            }
        }
    }
    return Local_enuStatus;
}

H7SEG_enuErrorStatus_t H7SEG_enuSetMulVal(u16 copy_u16Val){
    H7SEG_enuErrorStatus_t Local_enuStatus = H7SEG_enu_OK;
    u16 Loc_16Val = copy_u16Val;
    uint8_t i=0;
    u16 max_val = 0;
    for(i=0;i<NO_OF_7SEG;i++){
        max_val = max_val*10+9;
    }
    if(copy_u16Val>max_val){
        Local_enuStatus = H7SEG_enu_NOK;
    }
    
    else{
        for(i=0;i<NO_OF_7SEG;i++){
            Local_enuStatus = H7SEG_enuSetValue(i,Loc_16Val%10);
            if(Local_enuStatus != H7SEG_enu_OK){
                break;
            }
            Loc_16Val/=10;
        }
    }
    return Local_enuStatus;
}

