#include "DIO_CFG.h"
// All pins are not available by default
MDIO_enu_pinConfig_t MDIO_arrPinConfig[NO_OF_PORTS][NO_OF_PINS] = {0};

void MDIO_vpinsInit(void){
    #ifdef PORTA
        #ifdef PORTA_PIN0_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN0] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTA_PIN0_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN0] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTA_PIN0_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN0] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTA_PIN1_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN1] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTA_PIN1_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN1] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTA_PIN1_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN1] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTA_PIN2_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN2] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTA_PIN2_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN2] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTA_PIN2_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN2] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTA_PIN3_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN3] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTA_PIN3_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN3] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTA_PIN3_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN3] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTA_PIN4_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN4] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTA_PIN4_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN4] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTA_PIN4_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN4] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTA_PIN5_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN5] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTA_PIN5_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN5] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTA_PIN5_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN5] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTA_PIN6_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN6] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTA_PIN6_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN6] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTA_PIN6_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN6] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTA_PIN7_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN7] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTA_PIN7_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN7] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTA_PIN7_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTA][MDIO_enu_PIN7] = MDIO_enu_INPUT_PULLDOWN;
        #endif
    #endif

    #ifdef PORTB
        #ifdef PORTB_PIN0_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN0] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTB_PIN0_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN0] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTB_PIN0_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN0] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTB_PIN1_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN1] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTB_PIN1_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN1] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTB_PIN1_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN1] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTB_PIN2_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN2] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTB_PIN2_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN2] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTB_PIN2_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN2] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTB_PIN3_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN3] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTB_PIN3_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN3] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTB_PIN3_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN3] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTB_PIN4_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN4] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTB_PIN4_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN4] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTB_PIN4_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN4] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTB_PIN5_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN5] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTB_PIN5_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN5] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTB_PIN5_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN5] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTB_PIN6_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN6] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTB_PIN6_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN6] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTB_PIN6_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN6] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTB_PIN7_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN7] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTB_PIN7_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN7] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTB_PIN7_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTB][MDIO_enu_PIN7] = MDIO_enu_INPUT_PULLDOWN;
        #endif
    #endif

    #ifdef PORTC
        #ifdef PORTC_PIN0_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN0] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTC_PIN0_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN0] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTC_PIN0_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN0] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTC_PIN1_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN1] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTC_PIN1_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN1] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTC_PIN1_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN1] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTC_PIN2_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN2] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTC_PIN2_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN2] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTC_PIN2_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN2] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTC_PIN3_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN3] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTC_PIN3_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN3] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTC_PIN3_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN3] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTC_PIN4_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN4] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTC_PIN4_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN4] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTC_PIN4_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN4] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTC_PIN5_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN5] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTC_PIN5_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN5] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTC_PIN5_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN5] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTC_PIN6_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN6] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTC_PIN6_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN6] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTC_PIN6_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN6] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTC_PIN7_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN7] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTC_PIN7_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN7] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTC_PIN7_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTC][MDIO_enu_PIN7] = MDIO_enu_INPUT_PULLDOWN;
        #endif
    #endif

    #ifdef PORTD
        #ifdef PORTD_PIN0_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN0] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTD_PIN0_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN0] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTD_PIN0_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN0] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTD_PIN1_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN1] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTD_PIN1_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN1] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTD_PIN1_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN1] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTD_PIN2_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN2] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTD_PIN2_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN2] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTD_PIN2_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN2] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTD_PIN3_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN3] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTD_PIN3_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN3] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTD_PIN3_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN3] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTD_PIN4_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN4] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTD_PIN4_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN4] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTD_PIN4_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN4] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTD_PIN5_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN5] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTD_PIN5_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN5] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTD_PIN5_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN5] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTD_PIN6_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN6] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTD_PIN6_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN6] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTD_PIN6_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN6] = MDIO_enu_INPUT_PULLDOWN;
        #endif

        #ifdef PORTD_PIN7_OUTPUT
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN7] = MDIO_enu_OUTPUT;
        #endif

        #ifdef PORTD_PIN7_INPUT_PULLUP
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN7] = MDIO_enu_INPUT_PULLUP;
        #endif

        #ifdef PORTD_PIN7_INPUT_PULLDOWN
            MDIO_arrPinConfig[MDIO_enu_PORTD][MDIO_enu_PIN7] = MDIO_enu_INPUT_PULLDOWN;
        #endif
    #endif   
}