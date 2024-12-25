#include "dio.h"

void delay(void);

int main(void){
    MDIO_vInit();
    uint8_t button_state = 0;
    uint8_t prev_button_state = 1;  
    uint8_t mode = 0;

    MDIO_enuGetPinValue(MDIO_enu_PORTA, MDIO_enu_PIN0, &button_state);
    MDIO_enuSetPinValue(MDIO_enu_PORTA, MDIO_enu_PIN3, mode);        

    while(1){
        MDIO_enuGetPinValue(MDIO_enu_PORTA, MDIO_enu_PIN0, &button_state);  
        if(button_state == MDIO_enu_LOW && prev_button_state == MDIO_enu_HIGH) {  
            delay();              
            mode ^= 0x01;
        }
        MDIO_enuSetPinValue(MDIO_enu_PORTA, MDIO_enu_PIN3, mode);
        prev_button_state = button_state;
    }

    return 0;
}

void delay(void){
    int i = 0;
    for(; i < 1000; i++);
}
