#include "segment7_cfg.h"

H7SEG_stConfig_t H7SEG_arrConfigParam[NO_OF_7SEG]={
    
    [SEGMENT7_1]={    
        .segment7_mode=H7SEG_MODE_COMMON_CATHODE,
        .segment7_pins={PIN_A0,PIN_A1,PIN_A2,PIN_A3,PIN_A4,PIN_A5,PIN_A6,PIN_A7}
    },

    [SEGMENT7_2]={
        .segment7_mode=H7SEG_MODE_COMMON_ANODE,
        .segment7_pins={PIN_C0,PIN_C1,PIN_C2,PIN_C3,PIN_C4,PIN_C5,PIN_C6,PIN_C7}
    }
};