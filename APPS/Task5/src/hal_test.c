#include "LED.h"
#include "SWITCH.h"
#include "util/delay.h"

int main(void){
    
    HLED_init();
    HSWITCH_init();
    
    LED_enuSetState(LED_1,OFF);
    LED_enuSetState(LED_2,OFF);
    LED_enuSetState(LED_3,OFF);
    
    uint8_t button_1_state = OFF;
    uint8_t button_2_state = OFF;
    uint8_t button_3_state = OFF;
    
    uint8_t led_1_state = OFF;
    uint8_t led_2_state = OFF;
    uint8_t led_3_state = OFF;

    while(1){
        HSWITCH_enuGetValue(SWITCH_1,&button_1_state);
        HSWITCH_enuGetValue(SWITCH_2,&button_2_state);
        HSWITCH_enuGetValue(SWITCH_3,&button_3_state);

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

        LED_enuSetState(LED_1,led_1_state);
        LED_enuSetState(LED_2,led_2_state);
        LED_enuSetState(LED_3,led_3_state);

    }
    return 0;
}