#ifndef LCD_H_
#define LCD_H_

#include "lcd_cfg.h"

#define HLCD_CLR_DISP_CMD               ((u16)0x0001)
#define HLCD_RET_HOME_CMD               ((u16)0x0002)

#define HLCD_ENT_CUR_LEFT               ((u16)0x0004)
#define HLCD_ENT_SCR_LEFT               ((u16)0x0005)
#define HLCD_ENT_CUR_RIGHT              ((u16)0x0006)
#define HLCD_ENT_SCR_RIGHT              ((u16)0x0007)

#define HLCD_DISP_OFF                   ((u16)0x0008) 
#define HLCD_DISP_ON                    ((u16)0x000C) 
#define HLCD_CUR                        ((u16)0x000E) 
#define HLCD_BLINK                      ((u16)0x000F)

#define HLCD_FUNC_SET_8BIT_2LINE_5x8    ((u16)0x0038)
#define HLCD_FUNC_SET_8BIT_1LINE_5x8    ((u16)0x0030)
#define HLCD_FUNC_SET_8BIT_2LINE_5x10   ((u16)0x003C)
#define HLCD_FUNC_SET_8BIT_1LINE_5x10   ((u16)0x0034)
#define HLCD_FUNC_SET_4BIT_2LINE_5x8    ((u16)0x0028)
#define HLCD_FUNC_SET_4BIT_1LINE_5x8    ((u16)0x0020)
#define HLCD_FUNC_SET_4BIT_2LINE_5x10   ((u16)0x002C)
#define HLCD_FUNC_SET_4BIT_1LINE_5x10   ((u16)0x0024)

typedef enum{
    HLCD_enu_OK,
    HLCD_enu_INVALID_CMD,
    HLCD_enu_INVALID_ROW,
    HLCD_enu_INVALID_COL,
    HLCD_enu_NULL_POINTER,
    HLCD_enu_INVALID_BLK,
    HLCD_enu_NOK
}HLCD_enuErrorStatus_t;


/*Function Prototypes*/
extern void HLCD_vInit(void);

extern void HLCD_vWriteCMD(u16 Copy_u16CMD);

extern void HLCD_vWriteData(uint8_t Copy_u8Data);

extern HLCD_enuErrorStatus_t HLCD_enuSetCursorPos(uint8_t Copy_u8Row,uint8_t Copy_u8Col);

extern HLCD_enuErrorStatus_t HLCD_enuWriteStr(const int8_t* Add_s8Buff,uint8_t Copy_u8Row,
uint8_t Copy_u8Col);

extern HLCD_enuErrorStatus_t HLCD_enuWriteNO(int32_t Copy_s8No,uint8_t Copy_u8Row,
uint8_t Copy_u8Col);

extern HLCD_enuErrorStatus_t HLCD_enuPrintSpecialChar(uint8_t* Add_u8Pattern,uint8_t Copy_u8Blk,
uint8_t Copy_u8Row,uint8_t Copy_u8Col);

#endif
