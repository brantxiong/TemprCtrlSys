#ifndef __OCM12864_H_
#define __OCM12864_H_

#include"..\\head\\ocm12864.h"

typedef unsigned char   uchar;
typedef  unsigned int   uint;

#define  lcddata_out	  GP3DAT  							//P3
#define  lcddata_in       (char)(GP3DAT & 0x000000FF)
#define  LCD_DOUT_EN      GP3DAT=(GP3DAT|0xFF000000)
#define  LCD_DIN_EN       GP3DAT=(GP3DAT&0x00FFFFFF)
#define  set_rs()         GP4DAT=(GP4DAT|0x01010000)		//P4.0	   A0
#define  clear_rs()       GP4DAT=(GP4DAT|0x01000000)&(~0x00010000)
#define  set_rw()         GP4DAT=(GP4DAT|0x02020000)	   //P4.1
#define  clear_rw()       GP4DAT=(GP4DAT|0x02000000)&(~0x00020000)
#define  set_en()         GP4DAT=(GP4DAT|0x04040000)	   //P4.2
#define  clear_en()       GP4DAT=(GP4DAT|0x04000000)&(~0x00040000)
#define  set_cs()         GP4DAT=(GP4DAT|0x08080000)		//P4.3
#define  clear_cs()       GP4DAT=(GP4DAT|0x08000000)&(~0x00080000)
#define  set_reset()      GP4DAT=(GP4DAT|0x10100000)		//P4.4
#define  clear_reset()    GP4DAT=(GP4DAT|0x10000000)&(~0x00100000)

////*****************////
////*****º¯ÊýÉùÃ÷****////
////*****************////
void LCD_Delay(unsigned long v);
void check_busy(void);
void write_data(unsigned long dat);
void write_command(unsigned long command);
void reset(void);
void clear_screen(uchar m);
void lcd_initial(void);
void set_page_address(uchar page);
void set_colume_address(uchar colume);
void disp_word(uchar col,uchar pag,uchar ascii);
void disp_chn(uchar col,uchar pag,uchar ascii);
void disp_str(uchar col,uchar page,uchar *cn);
void setpoint(uchar x,uchar y);
void point(uchar x,uchar y);
void disp_bmp( uchar const *puts );
void shuxian(uchar n,uchar e,uchar f);
void hengxian(uchar k);
void delaynum(unsigned char num);
void write_floatNum(uchar col,uchar pag,double x,char y); 
void disp_big_word(uchar col,uchar pag,uchar ascii);
void write_BigNum(uchar col,uchar pag,float x,char y); 
void write_Num(uchar col,uchar pag,int x,char y);
void disp_huge_word(uchar col,uchar pag,uchar ascii);
void disp_huge_dot(uchar col,uchar pag);

#endif
