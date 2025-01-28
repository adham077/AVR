#include "DIO_PIN.h"
/*Base adresses for the ports A through D*/
#define PTA_BASE 0X39
#define PTB_BASE 0x36
#define PTC_BASE 0x33
#define PTD_BASE 0x30

/*A structure which defines the registers for each port*/
typedef struct{
    volatile uint8_t PIN;
    volatile uint8_t DDR;
    volatile uint8_t PORT;
}MDIO_gstPorts_t;

/*Global Pointers of type struct to the base of each port*/
MDIO_gstPorts_t* MDIO_pPORTA = (MDIO_gstPorts_t*)(PTA_BASE);
MDIO_gstPorts_t* MDIO_pPORTB = (MDIO_gstPorts_t*)(PTB_BASE);
MDIO_gstPorts_t* MDIO_pPORTC = (MDIO_gstPorts_t*)(PTC_BASE);
MDIO_gstPorts_t* MDIO_pPORTD = (MDIO_gstPorts_t*)(PTD_BASE);

/*static function which takes the port no. and assigns the port pointer to the correct base*/
static MDIO_enuErrorStatus_t MDIO_enuGetPort(MDIO_enuPORT_t copy_enuPortNo,MDIO_gstPorts_t** Add_pPort){
    
    MDIO_enuErrorStatus_t loc_enuStatus = MDIO_enu_OK;
    switch(copy_enuPortNo){
        case MDIO_enu_PORTA:
            *Add_pPort =  MDIO_pPORTA;
            break;

        case MDIO_enu_PORTB:
            *Add_pPort =  MDIO_pPORTB;
            break;

        case MDIO_enu_PORTC:
            *Add_pPort =  MDIO_pPORTC;
            break;

        case MDIO_enu_PORTD:
            *Add_pPort =  MDIO_pPORTD;
            break;
        
        default:
            loc_enuStatus=MDIO_enu_INVALID_PORT;
            break;
    }   
    return loc_enuStatus;
}

/*Function that sets the pin config based on a port no, enum, a pin no. enum and a configuration enum */
MDIO_enuErrorStatus_t MDIO_enuSetPinConfiguration(MDIO_enuPORT_t copy_enuPortNO,MDIO_enuPIN_t copy_enuPinNO,
MDIO_enuPinConfig_t copy_enuConfiguration){

    /*Local var holding the return status for the function*/
    MDIO_enuErrorStatus_t loc_enuStatus = MDIO_enu_OK;
    /*Pointer of type struct pointing to the base of the chosen port*/
    MDIO_gstPorts_t* loc_pPort = NULL; 
    loc_enuStatus = MDIO_enuGetPort(copy_enuPortNO,&loc_pPort);
    
    if(loc_enuStatus!=MDIO_enu_OK){
        /*If the port no is not correct skip the else statements and return the status*/
    }
    else if(copy_enuPinNO>MAX_PIN_NO){
        loc_enuStatus=MDIO_enu_INVALID_PIN;
    }
    /*Setting configuration mode*/
    else{
        switch(copy_enuConfiguration){
            case MDIO_enu_OUTPUT:
                SET_BIT(loc_pPort->DDR,copy_enuPinNO);
                CLR_BIT(loc_pPort->PORT,copy_enuPinNO);
                break;
            
            case MDIO_enu_INPUT_PULLUP:
                CLR_BIT(loc_pPort->DDR,copy_enuPinNO);
                SET_BIT(loc_pPort->PORT,copy_enuPinNO);
                break;
            
            case MDIO_enu_INPUT_PULLDOWN:
                CLR_BIT(loc_pPort->DDR,copy_enuPinNO);
                CLR_BIT(loc_pPort->PORT,copy_enuPinNO);
                break;
            default:
                loc_enuStatus=MDIO_enu_INVALID_CFG;
                break;
        }
    }
    return loc_enuStatus;
}

MDIO_enuErrorStatus_t MDIO_enuSetPortConfiguration(MDIO_enuPORT_t copy_enuPortNo,
MDIO_enuPinConfig_t copy_enuConfiguration){

    MDIO_gstPorts_t* loc_pPort = NULL;
    MDIO_enuErrorStatus_t loc_enuStatus = MDIO_enuGetPort(copy_enuPortNo,&loc_pPort);
    
    //check if port no is correct
    if(loc_enuStatus==MDIO_enu_OK){
        //set config. for port
        switch(copy_enuConfiguration){
            case MDIO_enu_OUTPUT:
                SET_REG(loc_pPort->DDR);
                CLR_REG(loc_pPort->PORT);
                break;
            
            case MDIO_enu_INPUT_PULLUP:
                CLR_REG(loc_pPort->DDR);
                SET_REG(loc_pPort->PORT);
                break;
            
            case MDIO_enu_INPUT_PULLDOWN:
                CLR_REG(loc_pPort->DDR);
                CLR_REG(loc_pPort->PORT);
                break;
            default:
                loc_enuStatus=MDIO_enu_INVALID_CFG;
                break;
        }
    }
    return loc_enuStatus;           
}

MDIO_enuErrorStatus_t MDIO_enuSetPinValue(MDIO_enuPORT_t Copy_enuPortNo,MDIO_enuPIN_t Copy_enuPinNo,
MDIO_enuPinState_t Copy_enuPinState){
    
    MDIO_gstPorts_t* Loc_pPort = NULL;
    MDIO_enuErrorStatus_t Loc_enuStatus = MDIO_enuGetPort(Copy_enuPortNo,&Loc_pPort);
    
    if(Loc_enuStatus!=MDIO_enu_OK){
        /*If port no is incorrect skip to the return statement*/
    }
    else if(Copy_enuPinNo>MAX_PIN_NO){
        Loc_enuStatus = MDIO_enu_INVALID_PIN;
    }
    else if(Copy_enuPinState>MAX_PIN_VAL_NO){
        Loc_enuStatus = MDIO_enu_INVALID_INPUT;
    }
    /*If pin is defined as input return an error*/
    else if(GET_BIT(Loc_pPort->DDR,Copy_enuPinNo)==0){
        Loc_enuStatus= MDIO_enu_INPUT_PIN;
    }
    else{
        switch (Copy_enuPinState){
            case MDIO_enu_pin_HIGH:
                SET_BIT(Loc_pPort->PORT,Copy_enuPinNo);
                break;
            
            case MDIO_enu_PIN_LOW:
                CLR_BIT(Loc_pPort->PORT,Copy_enuPinNo);
                break;

            default:
                Loc_enuStatus=MDIO_enu_INVALID_INPUT;
                break;
        }
    }
    return Loc_enuStatus;
}

MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPORT_t Copy_enuPortNo,
uint8_t Copy_u8Val){
    
    MDIO_gstPorts_t* Loc_pPort = NULL;
    MDIO_enuErrorStatus_t Loc_enuStatus = MDIO_enuGetPort(Copy_enuPortNo,&Loc_pPort);

    if(Loc_enuStatus!=MDIO_enu_OK){}
    else{
        /*Changing the value of the port register without affecting any pins that may be configured
        as input pins:
        truth table for inputs/output:
        Input        |   Output
        DDR PORT VAL |   PORT  
        0   0   x    |    0
        0   1   x    |    1
        1   x   0    |    0
        1   x   1    |    1

        constructing the k-map yields the equation:
        PORT = (DDR&VAL)|(~DDR&PORT)
        */
        Loc_pPort->PORT = ((Loc_pPort->DDR)&Copy_u8Val) | (~(Loc_pPort->DDR)&(Loc_pPort->PORT));

    }
    return Loc_enuStatus;   
}

MDIO_enuErrorStatus_t MDIO_enuGetPinVal(MDIO_enuPORT_t Copy_enuPortNo,MDIO_enuPIN_t Copy_enuPinNo,
uint8_t* Add_u8PinVal){

    MDIO_gstPorts_t* Loc_pPort = NULL;
    MDIO_enuErrorStatus_t Loc_enuStatus = MDIO_enuGetPort(Copy_enuPortNo,&Loc_pPort);
    
    if(Loc_enuStatus!=MDIO_enu_OK){}    
    
    else if(Copy_enuPinNo>MAX_PIN_NO){
        Loc_enuStatus=MDIO_enu_INVALID_PIN;
    }

    else{
        *Add_u8PinVal = GET_BIT(Loc_pPort->PIN,Copy_enuPinNo);
    }
    
    return Loc_enuStatus;
}

