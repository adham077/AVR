#define F_CPU 1000000UL
#include "segment7.h"
#include "util/delay.h"

int main(void){
    /*Initialize the seven segment displays*/
    H7SEG_vInit();
    uint8_t count=0;
   

    while(1){
        /*Display the count value on the seven segment displays*/
        H7SEG_enuSetMulVal(count);
        count++;
        count%=100;
        _delay_ms(500);
    }
    return 0;
}