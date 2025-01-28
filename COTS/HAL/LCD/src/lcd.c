#include "lcd.h"

#define RS_  0
#define RW_  1
#define EN_  2
#define D0_  3
#define D1_  4
#define D2_  5
#define D3_  6
#if HLCD_MODE==HLCD_8BIT_MODE
#define D4_  7
#define D5_  8
#define D6_  9
#define D7_  10
#endif

#define HLCD_CHAR_BUFF_SIZE              32

#define HLCD_CLR_DIS_CMD_MASK       ((u16)0x0001)
#define HLCD_RET_HOME_CMD_MASK      ((u16)0x0002)

#define HLCD_DRAM_CMD_MASK          ((u16)0x0080)
#define HLCD_CGRAM_CMD_MASK          ((u16)0x0040)

typedef struct{
    uint8_t PortNo;
    uint8_t PinNo;
}HLCD_stPinData_t;



static HLCD_stPinData_t  HLCD_arrPinMap[HLCD_NO_OF_PINS];

static void HLCD_reverseStr(int8_t* Add_s8Buff,uint8_t Copy_u8Size){
 
    uint8_t Loc_u8Beg = 0;
    uint8_t Loc_u8End = Copy_u8Size - 1;
    uint8_t Loc_u8Temp = 0;
    while (Loc_u8Beg<Loc_u8End){
        Loc_u8Temp = Add_s8Buff[Loc_u8Beg];
        Add_s8Buff[Loc_u8Beg] = Add_s8Buff[Loc_u8End];
        Add_s8Buff[Loc_u8End] = Loc_u8Temp;
        Loc_u8Beg++;    
        Loc_u8End--;
    }
    
}


static void HLCD_itoa(int32_t Copy_s32No,int8_t* Add_s8Buff){
   
    uint8_t i=0;
    int32_t Loc_s32Char = 0;
    if(Copy_s32No == 0){
        Add_s8Buff[i++] = '0';
        Add_s8Buff[i] = '\0';
    }
    else if(Copy_s32No>0){
        while (Copy_s32No>0){
            Loc_s32Char = Copy_s32No%10 + '0';
            Add_s8Buff[i++] = Loc_s32Char;
            Copy_s32No /=10;
        }
        Add_s8Buff[i] = '\0';
        HLCD_reverseStr(Add_s8Buff,i);
    }
    else{
        Copy_s32No *= -1;
        while (Copy_s32No>0){
            Loc_s32Char = Copy_s32No%10 + '0';
            Add_s8Buff[i++] = Loc_s32Char;
            Copy_s32No /=10;
        }
        Add_s8Buff[i++] = '-';
        Add_s8Buff[i] = '\0';
        HLCD_reverseStr(Add_s8Buff,i);
    }
}

void HLCD_vWriteCMD(u16 Copy_u16CMD){
    
    uint8_t Loc_u8PinState = 0; 
    uint8_t i=0;
    
    MDIO_enuSetPinValue(HLCD_arrPinMap[EN_].PortNo,HLCD_arrPinMap[EN_].PinNo,
    MDIO_enu_PIN_LOW);

    MDIO_enuSetPinValue(HLCD_arrPinMap[RW_].PortNo,HLCD_arrPinMap[RW_].PinNo,
    MDIO_enu_PIN_LOW);

    MDIO_enuSetPinValue(HLCD_arrPinMap[RS_].PortNo,HLCD_arrPinMap[RS_].PinNo,
    MDIO_enu_PIN_LOW);

    #if HLCD_MODE==HLCD_8BIT_MODE
    for(i=0;i<HLCD_NO_OF_DATA_PINS;i++){
        Loc_u8PinState = (uint8_t)(GET_BIT(Copy_u16CMD,i)); 
        MDIO_enuSetPinValue(HLCD_arrPinMap[i+D0_].PortNo,HLCD_arrPinMap[i+D0_].PinNo,
        Loc_u8PinState);
    }
    MDIO_enuSetPinValue(HLCD_arrPinMap[EN_].PortNo,HLCD_arrPinMap[EN_].PinNo,
    MDIO_enu_pin_HIGH);
    _delay_us(20);
    MDIO_enuSetPinValue(HLCD_arrPinMap[EN_].PortNo,HLCD_arrPinMap[EN_].PinNo,
    MDIO_enu_PIN_LOW);
    _delay_us(20);
    #else
    for(i=0; i<HLCD_NO_OF_DATA_PINS; i++){
        Loc_u8PinState = (uint8_t)(GET_BIT(Copy_u16CMD, i + 4));
        MDIO_enuSetPinValue(HLCD_arrPinMap[i + D0_].PortNo, HLCD_arrPinMap[i + D0_].PinNo, Loc_u8PinState);
    }

    MDIO_enuSetPinValue(HLCD_arrPinMap[EN_].PortNo, HLCD_arrPinMap[EN_].PinNo, MDIO_enu_PIN_HIGH);
    _delay_us(20);
    MDIO_enuSetPinValue(HLCD_arrPinMap[EN_].PortNo, HLCD_arrPinMap[EN_].PinNo, MDIO_enu_PIN_LOW);
    
    for(i=0; i<HLCD_NO_OF_DATA_PINS; i++){
        Loc_u8PinState = (uint8_t)(GET_BIT(Copy_u16CMD, i));
        MDIO_enuSetPinValue(HLCD_arrPinMap[i + D0_].PortNo, HLCD_arrPinMap[i + D0_].PinNo, Loc_u8PinState);
    }

    MDIO_enuSetPinValue(HLCD_arrPinMap[EN_].PortNo, HLCD_arrPinMap[EN_].PinNo, MDIO_enu_PIN_HIGH);
    _delay_us(20);
    MDIO_enuSetPinValue(HLCD_arrPinMap[EN_].PortNo, HLCD_arrPinMap[EN_].PinNo, MDIO_enu_PIN_LOW);
    #endif
}

void HLCD_vWriteData(uint8_t Copy_u8Data){
    
    uint8_t Loc_u8PinState = 0; 
    uint8_t i=0;

    MDIO_enuSetPinValue(HLCD_arrPinMap[EN_].PortNo,HLCD_arrPinMap[EN_].PinNo,
    MDIO_enu_PIN_LOW);

    MDIO_enuSetPinValue(HLCD_arrPinMap[RW_].PortNo,HLCD_arrPinMap[RW_].PinNo,
    MDIO_enu_PIN_LOW);

    MDIO_enuSetPinValue(HLCD_arrPinMap[RS_].PortNo,HLCD_arrPinMap[RS_].PinNo,
    MDIO_enu_pin_HIGH);
    #if HLCD_MODE==HLCD_8BIT_MODE
    for(;i<HLCD_NO_OF_DATA_PINS;i++){
        Loc_u8PinState = (uint8_t)(GET_BIT(Copy_u8Data,i)); 
        MDIO_enuSetPinValue(HLCD_arrPinMap[i+D0_].PortNo,HLCD_arrPinMap[i+D0_].PinNo,
        Loc_u8PinState);
    }
    MDIO_enuSetPinValue(HLCD_arrPinMap[EN_].PortNo,HLCD_arrPinMap[EN_].PinNo,
    MDIO_enu_pin_HIGH);
    _delay_us(20);
    MDIO_enuSetPinValue(HLCD_arrPinMap[EN_].PortNo,HLCD_arrPinMap[EN_].PinNo,
    MDIO_enu_PIN_LOW);
    _delay_us(20);
    #else
    for(i=0; i<HLCD_NO_OF_DATA_PINS; i++){
        Loc_u8PinState = (uint8_t)(GET_BIT(Copy_u8Data, i + 4));
        MDIO_enuSetPinValue(HLCD_arrPinMap[i + D0_].PortNo, HLCD_arrPinMap[i + D0_].PinNo, Loc_u8PinState);
    }

    MDIO_enuSetPinValue(HLCD_arrPinMap[EN_].PortNo, HLCD_arrPinMap[EN_].PinNo, MDIO_enu_PIN_HIGH);
    _delay_us(20);
    MDIO_enuSetPinValue(HLCD_arrPinMap[EN_].PortNo, HLCD_arrPinMap[EN_].PinNo, MDIO_enu_PIN_LOW);
    
    for(i=0; i<HLCD_NO_OF_DATA_PINS; i++){
        Loc_u8PinState = (uint8_t)(GET_BIT(Copy_u8Data, i));
        MDIO_enuSetPinValue(HLCD_arrPinMap[i + D0_].PortNo, HLCD_arrPinMap[i + D0_].PinNo, Loc_u8PinState);
    }

    MDIO_enuSetPinValue(HLCD_arrPinMap[EN_].PortNo, HLCD_arrPinMap[EN_].PinNo, MDIO_enu_PIN_HIGH);
    _delay_us(20);
    MDIO_enuSetPinValue(HLCD_arrPinMap[EN_].PortNo, HLCD_arrPinMap[EN_].PinNo, MDIO_enu_PIN_LOW);
    _delay_us(20);
    #endif
}


HLCD_enuErrorStatus_t HLCD_enuSetCursorPos(uint8_t Copy_u8Row,uint8_t Copy_u8Col){
    
    HLCD_enuErrorStatus_t Loc_enuStatus = HLCD_enu_OK;
    u16 Loc_u16DRAM_Add = 0;
    if(Copy_u8Row>2){
        Loc_enuStatus = HLCD_enu_INVALID_ROW;
    }
    else if(Copy_u8Col>16){
        Loc_enuStatus = HLCD_enu_INVALID_COL;
    }
    else{
        Loc_u16DRAM_Add = Copy_u8Row*(0x40) + Copy_u8Col;
        Loc_u16DRAM_Add |= HLCD_DRAM_CMD_MASK;
        HLCD_vWriteCMD(Loc_u16DRAM_Add);
    }
    return Loc_enuStatus;
}

HLCD_enuErrorStatus_t HLCD_enuWriteStr(const int8_t* Add_s8Buff,uint8_t Copy_u8Row,
uint8_t Copy_u8Col){
  
    HLCD_enuErrorStatus_t Loc_enuStatus = HLCD_enu_OK;
    uint8_t i = 0;
    uint8_t Loc_8Row = 0;
    if(Add_s8Buff==NULL){
        Loc_enuStatus = HLCD_enu_NULL_POINTER;
    }
    else if(Copy_u8Row>2){
        Loc_enuStatus = HLCD_enu_INVALID_ROW;
    }
    else if(Copy_u8Col>16){
        Loc_enuStatus = HLCD_enu_INVALID_COL;
    }
    else{
        HLCD_enuSetCursorPos(Copy_u8Row,Copy_u8Col);
        for(;Add_s8Buff[i]!='\0';i++){
            if(Loc_8Row==0 && (i-Copy_u8Col)>15){
                HLCD_enuSetCursorPos(1,(i-15));
                HLCD_vWriteData(Add_s8Buff[i]);
            }
            else{
                HLCD_vWriteData(Add_s8Buff[i]);
            }
        }
    }
    return Loc_enuStatus;
}

HLCD_enuErrorStatus_t HLCD_enuWriteNO(int32_t Copy_s8No,uint8_t Copy_u8Row,
uint8_t Copy_u8Col){

    HLCD_enuErrorStatus_t Loc_enuStatus = HLCD_enu_OK;
    int8_t Loc_arrBuff[HLCD_CHAR_BUFF_SIZE] = {0};
    if(Copy_u8Row>2){
        Loc_enuStatus = HLCD_enu_INVALID_ROW;
    }
    else if(Copy_u8Col>16){
        Loc_enuStatus = HLCD_enu_INVALID_COL;
    }
    else{
        HLCD_itoa(Copy_s8No,Loc_arrBuff);
        HLCD_enuWriteStr(Loc_arrBuff,Copy_u8Row,Copy_u8Col);
    }
    return Loc_enuStatus;
}

static void HLCD_vStoreSpecialChar(uint8_t* Add_u8Pattern,
uint8_t Copy_u8Block){

    uint8_t i =0;
    uint8_t Loc_u8CMD = Copy_u8Block*8;
    Loc_u8CMD |= HLCD_CGRAM_CMD_MASK;
    HLCD_vWriteCMD(Loc_u8CMD);
    for(;i<8;i++){
        HLCD_vWriteData(Add_u8Pattern[i]);
    }
}

HLCD_enuErrorStatus_t HLCD_enuPrintSpecialChar(uint8_t* Add_u8Pattern,uint8_t Copy_u8Blk,
uint8_t Copy_u8Row,uint8_t Copy_u8Col){

    HLCD_enuErrorStatus_t Loc_enuStatus = HLCD_enu_OK;
    if(Add_u8Pattern==NULL){
        Loc_enuStatus = HLCD_enu_NULL_POINTER;
    }
    else if(Copy_u8Blk>7){
        Loc_enuStatus = HLCD_enu_INVALID_BLK;
    }
    else if(Copy_u8Row>1){
        Loc_enuStatus = HLCD_enu_INVALID_ROW;
    }
    else if(Copy_u8Col>15){
        Loc_enuStatus = HLCD_enu_INVALID_COL;
    }
    else{
        HLCD_vStoreSpecialChar(Add_u8Pattern,Copy_u8Blk);
        HLCD_enuSetCursorPos(Copy_u8Row,Copy_u8Col);
        HLCD_vWriteData(Copy_u8Blk);
    }
    return Loc_enuStatus;
}

void HLCD_vInit(void){
    
    uint8_t i=0;
    MPORT_enuSetPinMode(HLCD_stPins.RS,MDIO_enu_OUTPUT);
    MPORT_enuSetPinMode(HLCD_stPins.EN,MDIO_enu_OUTPUT);
    MPORT_enuSetPinMode(HLCD_stPins.RW,MDIO_enu_OUTPUT);
    HLCD_arrPinMap[RW_].PortNo = GET_HIGH_NIB(HLCD_stPins.RW); 
    HLCD_arrPinMap[RW_].PinNo = GET_LOW_NIB(HLCD_stPins.RW);
    HLCD_arrPinMap[EN_].PortNo = GET_HIGH_NIB(HLCD_stPins.EN);
    HLCD_arrPinMap[EN_].PinNo = GET_LOW_NIB(HLCD_stPins.EN);
    HLCD_arrPinMap[RS_].PortNo = GET_HIGH_NIB(HLCD_stPins.RS);
    HLCD_arrPinMap[RS_].PinNo = GET_LOW_NIB(HLCD_stPins.RS);
    for(;i<HLCD_NO_OF_DATA_PINS;i++){
        MPORT_enuSetPinMode(HLCD_stPins.data[i],MPORT_enu_OUTPUT);
        HLCD_arrPinMap[i+D0_].PortNo = GET_HIGH_NIB(HLCD_stPins.data[i]);
        HLCD_arrPinMap[i+D0_].PinNo = GET_LOW_NIB(HLCD_stPins.data[i]);
    }
    _delay_ms(50);
    #if HLCD_MODE==HLCD_4BIT_MODE
    HLCD_vWriteCMD(0x22);
    #endif
    HLCD_vWriteCMD(HLCD_stPins.FunSet);
    _delay_ms(50);
    HLCD_vWriteCMD(HLCD_stPins.DisplaySettings);
    _delay_ms(50);
    HLCD_vWriteCMD(HLCD_CLR_DISP_CMD);
    _delay_ms(5);
}

#undef RS_  
#undef RW_  
#undef EN_  
#undef D0_  
#undef D1_  
#undef D2_  
#undef D3_  
#if HLCD_MODE==HLCD_8BIT_MODE
#undef D4_  
#undef D5_  
#undef D6_  
#undef D7_ 
#endif 