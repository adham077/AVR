#include "segment7.h"

/*This array maps the values 0->9 to their corresponding output configuration
on the seven segment display*/
static const uint8_t H7SEG_arrValuesMap[10]={
    /*0->9*/
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

/*Structure for spliting the port and pin values*/
typedef struct{
    uint8_t port;
    uint8_t pin;
}H7SEG_stPinval_t;

/*Array of the pin values for each seven segment display*/
H7SEG_stPinval_t H7SEG_arrPinVal[NO_OF_7SEG][8];

H7SEG_enuErrorStatus_t H7SEG_vInit(void){
    
    H7SEG_enuErrorStatus_t Local_enuStatus = H7SEG_enu_OK;
    uint8_t i=0;
    for(;i<NO_OF_7SEG;i++){
        uint8_t j=0;
        for(;j<8;j++){
            /*Set the pins as output*/
            Local_enuStatus = MPORT_enuSetPinMode(H7SEG_arrConfigParam[i].segment7_pins[j],MPORT_enu_OUTPUT);
            if(Local_enuStatus != H7SEG_enu_OK){
                break;
            }
            /*Split the port and pin values*/
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
            uint8_t Loc_u8Port = H7SEG_arrPinVal[Copy_u8Segment7Number][i].port;
            uint8_t loc_u8Pin = H7SEG_arrPinVal[Copy_u8Segment7Number][i].pin;
            uint8_t loc_u8Mode = GET_BIT(H7SEG_arrValuesMap[Copy_u8Value],i);
            /*The XOR operation is used to invert the value of the pin 
            if the seven segment display is common anode*/
            loc_u8Mode^=H7SEG_arrConfigParam[Copy_u8Segment7Number].segment7_mode;
            /*Set the value of the pins based on the value of the seven segment display*/

            Local_enuStatus = MDIO_enuSetPinValue(Loc_u8Port,loc_u8Pin,loc_u8Mode);
            
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
    /*Calculate the maximum value that can be displayed on the configured seven segment displays*/
    for(i=0;i<NO_OF_7SEG;i++){
        max_val = max_val*10+9;
    }
    if(copy_u16Val>max_val){
        Local_enuStatus = H7SEG_enu_NOK;
    }
    
    else{
        for(i=0;i<NO_OF_7SEG;i++){
            /*Set the value of each seven segment display*/
            Local_enuStatus = H7SEG_enuSetValue(i,Loc_16Val%10);
            if(Local_enuStatus != H7SEG_enu_OK){
                break;
            }
            /*Get the next digit*/
            Loc_16Val/=10;
        }
    }
    return Local_enuStatus;
}

