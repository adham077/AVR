#define F_CPU 1000000UL
#include "segment7.h"
#include "util/delay.h"

int main(void){
    H7SEG_vInit();
    uint8_t count=0;
   

    while(1){
        H7SEG_enuSetMulVal(count);
        count++;
        count%=100;
        _delay_ms(500);
    }
    return 0;
}