#ifndef _TEMPERATURE_H_
#define _TEMPERATURE_H_

// ����P2.7Ϊ����,�������ߴ�����������,���Դ�ʱ�Ǹߵ�ƽ1 
#define PIN     GP2DAT = 0x00
// ����P2.7Ϊ���,ͬʱ����͵�ƽ0  	
#define POUT_0  GP2DAT = 0x80000000
// ����P2.7Ϊ���,ͬʱ����ߵ�ƽ1  
#define POUT_1  GP2DAT = 0x80800000

// ȫ�ֱ������¶ȵ���ֵ
extern float tmp;
// ȫ�ֱ������¶ȵ��ַ���
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
