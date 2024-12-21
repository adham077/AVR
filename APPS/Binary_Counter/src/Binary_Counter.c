#include "dio.h"

void delay(void);

int main(void){
    
    MDIO_enuSetPortConfigration(MDIO_enu_PORTA,MDIO_enu_OUTPUT); 
    MDIO_enuSetPortValue(MDIO_enu_PORTA,MDIO_enu_PORT_LOW); 
    MDIO_enuSetPinConfigration(MDIO_enu_PORTB,MDIO_enu_PIN0,MDIO_enu_INPUT_PULLUP);
    uint8_t button_state = MDIO_enu_LOW;
    uint8_t counter = 0;
    while(1){
        MDIO_enuGetPinValue(MDIO_enu_PORTB,MDIO_enu_PIN0,&button_state);
        if (button_state == MDIO_enu_LOW) {
            delay();
            MDIO_enuGetPinValue(MDIO_enu_PORTB, MDIO_enu_PIN0, &button_state);
            if (button_state == MDIO_enu_LOW) {
                counter++;
                counter %= MAX_PORT_VAL;
                while (button_state == MDIO_enu_LOW) {
                    MDIO_enuGetPinValue(MDIO_enu_PORTB, MDIO_enu_PIN0, &button_state);
                }
            }
        }

        MDIO_enuSetPortValue(MDIO_enu_PORTA,counter); 
    }
    return 0;
}

void delay(void){
    int i=0;
    for(;i<1000;i++);
}


