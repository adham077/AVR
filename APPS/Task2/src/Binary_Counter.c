#define F_CPU 1000000
#include "DIO_PIN.h"
#include "util/delay.h"

int main(void){
    MDIO_enuSetPortConfiguration(MDIO_enu_PORTA,MDIO_enu_OUTPUT);
    MDIO_enuSetPinConfiguration(MDIO_enu_PORTB,MDIO_enu_PIN0,MDIO_enu_INPUT_PULLUP);

    while(1){
        uint8_t buttonState = MDIO_enu_pin_HIGH;
        uint8_t startTimer = FALSE;
        uint8_t countVal=0;

        MDIO_enuGetPinVal(MDIO_enu_PORTB,MDIO_enu_PIN0,&buttonState);
        
        if(buttonState==MDIO_enu_PIN_LOW){
            _delay_ms(10);
            MDIO_enuGetPinVal(MDIO_enu_PORTB,MDIO_enu_PIN0,&buttonState);
            if(buttonState==MDIO_enu_PIN_LOW){
                startTimer = TRUE;
            }
            while(buttonState==MDIO_enu_PIN_LOW){
                MDIO_enuGetPinVal(MDIO_enu_PORTB,MDIO_enu_PIN0,&buttonState);
            }
        }

        if(startTimer==TRUE){
            while(1){
                countVal = (countVal+1)%MAX_PORT_VAL;
                MDIO_enuSetPortValue(MDIO_enu_PORTA,countVal);                
                _delay_ms(500);
            }
            }
        }
    
}

