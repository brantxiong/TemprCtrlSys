#ifndef _TEMPERATURE_H_
#define _TEMPERATURE_H_

// 设置P2.7为输入,由于总线存在上拉电阻,所以此时是高电平1 
#define PIN     GP2DAT = 0x00
// 设置P2.7为输出,同时输出低电平0  	
#define POUT_0  GP2DAT = 0x80000000
// 设置P2.7为输出,同时输出高电平1  
#define POUT_1  GP2DAT = 0x80800000

// 全局变量，温度的数值
extern float tmp;
// 全局变量，温度的字符串
extern char tmp_str[7];
																
void DelayUs(int);
void DelayMs(int);
void SysClkInit(void);
void TmpBusInit(void);
unsigned char ReadTmpBus(void);
void WriteTmpBus(unsigned char);
void ReadTmp(void);
void ConvertTmp(unsigned char, unsigned char);

#endif
