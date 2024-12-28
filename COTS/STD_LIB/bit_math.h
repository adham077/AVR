#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define MASK(x) (1<<x);
/*Bit utils*/
#define SET_BIT(reg,bit) (reg|=(1<<bit)) 
#define CLR_BIT(reg,bit) (reg &= ~(1<<bit))
#define TGL_BIT(reg,bit) (reg^=(1<<bit))
#define GET_BIT(reg,bit) ((reg>>bit)&(0x01))
/*Port utils*/
#define SET_REG(reg) (reg=0xFF)
#define CLR_REG(reg) (reg=0x00)
#define TGL_REG(reg) (reg^=0xFF)
#define ASSIGN_REG(reg,val) (reg=val)
/*Nibble utils*/
#define SET_H_NIB(reg) (reg|=0xF0)
#define SET_L_NIB(reg) (reg|=0x0F)
#define CLR_H_NIB(reg) (reg&=0x0F)
#define CLR_L_NIB(reg) (reg&=0xF0)
#define GET_H_NIB(reg) ((reg&0xF0)>>4)
#define GET_L_NIB(reg) (reg&0x0F)
#define TGL_H_NIB(reg) (reg^=0xF0)
#define TGL_L_NIB(reg) (reg^=0x0F)
#define ASSIGN_H_NIB(reg,val) (reg=(val<<4)|(reg&0x0F))
#define ASSIGN_L_NIB(reg,val) (reg=val|(reg&0xF0)) 
#define INC_H_NIB(reg) (reg=(reg&0x0F)|(((reg&0xF0)+0x10)&0xF0))
#define INC_L_NIB(reg) (reg=(reg&0xF0)|(((reg&0x0F)+0x01)&0x0F))
#define DEC_H_NIB(reg) (reg=(reg&0x0F)|(((reg&0xF0)-0x10)&0xF0))
#define DEC_L_NIB(reg) (reg=(reg&0x0F)|(((reg&0x0F)-0x01)&0x0F))
#define SWAP_NIB(reg) (reg=((reg&0x0F)<<4)|((reg&0xF0)>>4))

#endif