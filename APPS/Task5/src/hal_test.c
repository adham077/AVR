#include "LED.h"
#include "SWITCH.h"
#include "util/delay.h"

int main(void){
    /*Initialization for led and switch pins
    led pins on port C
    led1 -> pin 0  forward 
    led2 -> pin 1  reverse
    led3 -> pin 2  forward

    Switch pins on port A
    switch1 -> pin 0  pull up
    switch2 -> pin 1  pull up
    switch3 -> pin 2  pull down
    */    
    HLED_init();
    HSWITCH_init();
    
    /*LED states*/
    LED_enuSetState(LED_1,OFF);
    LED_enuSetState(LED_2,OFF);
    LED_enuSetState(LED_3,OFF);
    /*Button states*/
    uint8_t button_1_state = OFF;
    uint8_t button_2_state = OFF;
    uint8_t button_3_state = OFF;
    /*LED states*/
    uint8_t led_1_state = OFF;
    uint8_t led_2_state = OFF;
    uint8_t led_3_state = OFF;

    while(1){
        /*Get the state of the buttons with debounce*/
        HSWITCH_enuGetValue(SWITCH_1,&button_1_state);
        HSWITCH_enuGetValue(SWITCH_2,&button_2_state);
        HSWITCH_enuGetValue(SWITCH_3,&button_3_state);
        /*Check if the button is pressed and toggle the led state*/
        if(button_1_state==ON){
            _delay_ms(10);
            HSWITCH_enuGetValue(SWITCH_1,&button_1_state);
            if(button_1_state==ON){
                led_1_state^=0x01;        
            }
            while (button_1_state==ON){
                HSWITCH_enuGetValue(SWITCH_1,&button_1_state);   
            }
        }
        /*Check if the button is pressed and toggle the led state*/
        if(button_2_state==ON){
            _delay_ms(10);
            HSWITCH_enuGetValue(SWITCH_2,&button_2_state);
            if(button_2_state==ON){
                led_2_state^=0x01;        
            }
            while (button_2_state==ON){
                HSWITCH_enuGetValue(SWITCH_2,&button_2_state);   
            }
        }
        /*Check if the button is pressed and toggle the led state*/
        if(button_3_state==ON){
            _delay_ms(10);
            HSWITCH_enuGetValue(SWITCH_3,&button_3_state);
            if(button_3_state==ON){
                led_3_state^=0x01;        
            }
            while (button_3_state == ON){
                HSWITCH_enuGetValue(SWITCH_3, &button_3_state);   
            }
        }
        /*Set the led state*/
        LED_enuSetState(LED_1,led_1_state);
        LED_enuSetState(LED_2,led_2_state);
        LED_enuSetState(LED_3,led_3_state);

    }
    return 0;
}