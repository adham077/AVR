#define F_CPU 1000000

#include "DIO_PORT.h"
#include "DIO_PIN.h"
#include <util/delay.h>

int main(void){
    
    MPORT_vInit();
   
    /*Button states*/
    uint8_t BUTTON1_state=MDIO_enu_pin_HIGH;
    uint8_t BUTTON2_state=MDIO_enu_pin_HIGH;
    uint8_t BUTTON3_state=MDIO_enu_pin_HIGH;
    
    /*Led States*/
    uint8_t LED1_state=MDIO_enu_PIN_LOW;
    uint8_t LED2_state=MDIO_enu_PIN_LOW;
    uint8_t LED3_state=MDIO_enu_PIN_LOW;

    while(1){
        MDIO_enuGetPinVal(MDIO_enu_PORTA,MDIO_enu_PIN3,&BUTTON1_state);
        MDIO_enuGetPinVal(MDIO_enu_PORTA,MDIO_enu_PIN4,&BUTTON2_state);
        MDIO_enuGetPinVal(MDIO_enu_PORTA,MDIO_enu_PIN5,&BUTTON3_state);
        
        /*Checking state with debounce*/
        if(BUTTON1_state==MDIO_enu_PIN_LOW){
            _delay_ms(10);
            MDIO_enuGetPinVal(MDIO_enu_PORTA,MDIO_enu_PIN3,&BUTTON1_state);
            
            /*Toggling LED flag*/
            if(BUTTON1_state==MDIO_enu_PIN_LOW){
                LED1_state ^=0x01;
            }
            while(BUTTON1_state==MDIO_enu_PIN_LOW){
                MDIO_enuGetPinVal(MDIO_enu_PORTA,MDIO_enu_PIN3,&BUTTON1_state);
            }
        }

        //repeat for 2 and 3...       
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

        /*Setting led val*/
        MDIO_enuSetPinValue(MDIO_enu_PORTA,MDIO_enu_PIN0,LED1_state);
        MDIO_enuSetPinValue(MDIO_enu_PORTA,MDIO_enu_PIN1,LED2_state);
        MDIO_enuSetPinValue(MDIO_enu_PORTA,MDIO_enu_PIN2,LED3_state);
    }
    return 0;
}
