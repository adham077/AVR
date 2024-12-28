#define F_CPU 1000000
#include <util/delay.h>
#include "DIO_PIN.h"

int main(void){
    /*Setting pin0/pin1/pin2 as output on port A*/
    MDIO_enuSetPinConfiguration(MDIO_enu_PORTA,MDIO_enu_PIN0,MDIO_enu_OUTPUT);
    MDIO_enuSetPinConfiguration(MDIO_enu_PORTA,MDIO_enu_PIN1,MDIO_enu_OUTPUT);
    MDIO_enuSetPinConfiguration(MDIO_enu_PORTA,MDIO_enu_PIN2,MDIO_enu_OUTPUT);

    /*Setting pin3/pin4/pin5 as input on port A*/
    MDIO_enuSetPinConfiguration(MDIO_enu_PORTA,MDIO_enu_PIN3,MDIO_enu_INPUT_PULLUP);
    MDIO_enuSetPinConfiguration(MDIO_enu_PORTA,MDIO_enu_PIN4,MDIO_enu_INPUT_PULLUP);
    MDIO_enuSetPinConfiguration(MDIO_enu_PORTA,MDIO_enu_PIN5,MDIO_enu_INPUT_PULLUP);
    
    uint8_t BUTTON1_state=MDIO_enu_PIN_LOW;
    uint8_t BUTTON2_state=MDIO_enu_PIN_LOW;
    uint8_t BUTTON3_state=MDIO_enu_PIN_LOW;
    uint8_t LED1_state=MDIO_enu_PIN_LOW;
    uint8_t LED2_state=MDIO_enu_PIN_LOW;
    uint8_t LED3_state=MDIO_enu_PIN_LOW;

    while(1){
        MDIO_enuGetPinVal(MDIO_enu_PORTA,MDIO_enu_PIN3,&BUTTON1_state);
        MDIO_enuGetPinVal(MDIO_enu_PORTA,MDIO_enu_PIN4,&BUTTON2_state);
        MDIO_enuGetPinVal(MDIO_enu_PORTA,MDIO_enu_PIN5,&BUTTON3_state);
        
        if(BUTTON1_state==MDIO_enu_PIN_LOW){
            _delay_ms(10);
            MDIO_enuGetPinVal(MDIO_enu_PORTA,MDIO_enu_PIN3,&BUTTON1_state);
            if(BUTTON1_state==MDIO_enu_PIN_LOW){
                LED1_state ^=0x01;
            }
            while(BUTTON1_state==MDIO_enu_PIN_LOW){
                MDIO_enuGetPinVal(MDIO_enu_PORTA,MDIO_enu_PIN3,&BUTTON1_state);
            }
        }
        
        if(BUTTON2_state==MDIO_enu_PIN_LOW){
            _delay_ms(10);
            MDIO_enuGetPinVal(MDIO_enu_PORTA,MDIO_enu_PIN4,&BUTTON2_state);
            if(BUTTON2_state==MDIO_enu_PIN_LOW){
                LED2_state ^=0x01;
            }
            while(BUTTON2_state==MDIO_enu_PIN_LOW){
                MDIO_enuGetPinVal(MDIO_enu_PORTA,MDIO_enu_PIN4,&BUTTON2_state);
            }
        }
        
        if(BUTTON3_state==MDIO_enu_PIN_LOW){
            _delay_ms(10);
            MDIO_enuGetPinVal(MDIO_enu_PORTA,MDIO_enu_PIN5,&BUTTON3_state);
            if(BUTTON3_state==MDIO_enu_PIN_LOW){
                LED3_state ^=0x01;
            }
            while(BUTTON3_state==MDIO_enu_PIN_LOW){
                MDIO_enuGetPinVal(MDIO_enu_PORTA,MDIO_enu_PIN5,&BUTTON3_state);
            }
        }

        MDIO_enuSetPinValue(MDIO_enu_PORTA,MDIO_enu_PIN0,LED3_state);
        MDIO_enuSetPinValue(MDIO_enu_PORTA,MDIO_enu_PIN1,LED2_state);
        MDIO_enuSetPinValue(MDIO_enu_PORTA,MDIO_enu_PIN0,LED3_state);
    }
    return 0;
}