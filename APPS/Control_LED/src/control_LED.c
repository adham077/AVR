#include "dio.h"

void delay(void);

int main(void){
    
    MDIO_enuSetPinConfigration(MDIO_enu_PORTA,MDIO_enu_PIN0,MDIO_enu_OUTPUT);
    MDIO_enuSetPinConfigration(MDIO_enu_PORTA,MDIO_enu_PIN1,MDIO_enu_OUTPUT);
    MDIO_enuSetPinConfigration(MDIO_enu_PORTA,MDIO_enu_PIN2,MDIO_enu_OUTPUT);
    MDIO_enuSetPinConfigration(MDIO_enu_PORTB,MDIO_enu_PIN3,MDIO_enu_INPUT_PULLUP);
    MDIO_enuSetPinValue(MDIO_enu_PORTA,MDIO_enu_PIN0,MDIO_enu_LOW);
    MDIO_enuSetPinValue(MDIO_enu_PORTA,MDIO_enu_PIN1,MDIO_enu_LOW);
    MDIO_enuSetPinValue(MDIO_enu_PORTA,MDIO_enu_PIN2,MDIO_enu_LOW);
    
    uint8_t button_state = MDIO_enu_HIGH;
    uint8_t led_state = 0;
    while(1){
        
        MDIO_enuGetPinValue(MDIO_enu_PORTA,MDIO_enu_PIN3,&button_state);
        if(button_state==MDIO_enu_LOW){
            delay();
            MDIO_enuGetPinValue(MDIO_enu_PORTA,MDIO_enu_PIN3,&button_state);
            if(button_state==MDIO_enu_LOW){
                led_state++;
                led_state %= 3;
            }   
            while(button_state==MDIO_enu_LOW)
                MDIO_enuGetPinValue(MDIO_enu_PORTA,MDIO_enu_PIN3,&button_state);
        }

        switch(led_state){
            case 0:
                MDIO_enuSetPinConfigration(MDIO_enu_PORTA,MDIO_enu_PIN0,MDIO_enu_HIGH);
                MDIO_enuSetPinConfigration(MDIO_enu_PORTA,MDIO_enu_PIN1,MDIO_enu_LOW);
                MDIO_enuSetPinConfigration(MDIO_enu_PORTA,MDIO_enu_PIN2,MDIO_enu_LOW);
                break;
            case 1:
                MDIO_enuSetPinConfigration(MDIO_enu_PORTA,MDIO_enu_PIN0,MDIO_enu_LOW);
                MDIO_enuSetPinConfigration(MDIO_enu_PORTA,MDIO_enu_PIN1,MDIO_enu_HIGH);
                MDIO_enuSetPinConfigration(MDIO_enu_PORTA,MDIO_enu_PIN2,MDIO_enu_LOW);
                break;
            case 2:
                MDIO_enuSetPinConfigration(MDIO_enu_PORTA,MDIO_enu_PIN0,MDIO_enu_LOW);
                MDIO_enuSetPinConfigration(MDIO_enu_PORTA,MDIO_enu_PIN1,MDIO_enu_LOW);
                MDIO_enuSetPinConfigration(MDIO_enu_PORTA,MDIO_enu_PIN2,MDIO_enu_HIGH);
                break;
            default:
                break;
        }
    }

    return 0;
}

void delay(void){
    int i=0;
    for(;i<1000;i++);
}