/***********************************************************************/
/*                                                                     */
/*  IR.c:  红外按键处理模块			                     			   */
/*                                                                     */
/***********************************************************************/


#include "..\\head\\common.h"
#include "..\\head\\IR.h"
#include "..\\head\\io_ctrl.h"
#include "..\\head\\serial.h"
#include "..\\head\\key.h"
#include "..\\head\\time.h"
#include "..\\head\\temperature.h"
#include "..\\head\\interface.h"

#define PHIGH 	(GP1DAT & 0x10 ) == 0x10 
#define PLOW   (GP1DAT & 0x10 ) == 0x00 
int key_id = 0;
#define BOILTMP 100

/***************************************
说明: 	IR初始化，使能红外外部中断
*****************************************/
void IRInit()
{
	IRQEN |= (1<<21);
	GP1CLR |= (1<<4);
	GP0DAT |= (1<<27);	
}

/***************************************
说明: 	蜂鸣器驱动
*****************************************/
void beep()
{
	unsigned char i;
	for (i=0;i<100;i++)
	{
		DelayUs(100);
		GP0DAT ^= (1<<17);
	} 
	BeepOff();	             //关闭蜂鸣器
}

/***************************************
说明: 	中断检测函数
*****************************************/
void CheckIR()					 
{
	unsigned char j,k,N=0;	   		
	char IRCOM[4] = {0};
//	char key_code[2] = {0};
	IRQCLR |= (1<<21); //关闭中断
//	DelayUs(200);   
	if (PLOW) 	        //IR为0，则跳出
    {
//		Write("IR = 0");
		IRQEN |= (1<<21);
	    return;
	}
 	while (PHIGH)      //等IR变为0，跳过9ms
    {
//		Write("9ms\n");
//		DelayMs(1);
	}
//	Write("4.5ms\n");
	while (PLOW)         //等待IR
	{
//		DelayUs(1);
	}
											
	for (j=0;j<4;j++)         //收集四组数据
	{ 
		for (k=0;k<8;k++)        //每组数据有8位
		{
			while (PHIGH)        //等IR变为0
	 		{
			//	DelayUs(1);
			}
			 while (PLOW)            //计算IR=0时长
			 {
				DelayUs(40);   //100us
				GP0DAT ^= (1<<19);
				N++;  
				if (N > 30){
					IRQEN |= (1<<21);
	    			return;
				}         
				//Write("Low TIME\n");             
			 }                       //高电平计数完毕                
			 //IRCOM[j]=IRCOM[j] >> 1;                  //数据最高位补“0”
			 //if (N>=8) {IRCOM[j] = IRCOM[j] | 0x80;}  //数据最高位补“1”
			 if (N < 10){
			 	IRCOM[j] |= (1<<k);
			 }
			 N=0;
		}
	}
  
	if ((IRCOM[2]|IRCOM[3]) != 0xff)	//校验数据位是否错误
	{ 
	 	IRQEN |= (1<<21);
		return; 
	}
	//PutChar(IRCOM[2]);
	//PutChar(' ');
	///PutChar(~IRCOM[3]);
	//PutChar(0xff);
//	key_code[0]=IRCOM[2] & 0x0F;   
//	key_code[1]=IRCOM[2] >> 4;	
//	for(j=0;j<2;j++)
//	{
//		if(key_code[j] > 9)
//			key_code[j] += 55;
//		else
//			key_code[j] += 48;	
//	}	

//	Write(key_code);
//	Write("\n");
	if(IRCOM[2] == 0xB8)
	{
		key_id = 11;

	}
	if(IRCOM[2] == 0xBA)
	{
		key_id = 10;
	}
	if(IRCOM[2] == 0xBF)
	{
		key_id = 12;
	}
	if(IRCOM[2] == 0xBC)
	{
		key_id = 13;
	}
	if(IRCOM[2] == 0xF8)
	{
		key_id = 14;
	}
	if(IRCOM[2] == 0xEA)
	{
		key_id = 15;
	}
	if(IRCOM[2] == 0xF6)
	{
		key_id = 16;
	}
	if(IRCOM[2] == 0xE6)
	{
		key_id = 17;
	}
	if(IRCOM[2] == 0xF2)
	{
		key_id = 18;
	}
	if(IRCOM[2] == 0xE9)
	{
		key_id = 0;
	}
	if(IRCOM[2] == 0xF3)
	{
		key_id = 1;
	}
	if(IRCOM[2] == 0xE7)
	{
		key_id = 2;
	}
	if(IRCOM[2] == 0xA1)
	{
		key_id = 3;
	}
	if(IRCOM[2] == 0xF7)
	{
		key_id = 4;
	}
	if(IRCOM[2] == 0xE3)
	{
		key_id = 5;
	}
	if(IRCOM[2] == 0xA5)
	{
		key_id = 6;
	}
	if(IRCOM[2] == 0xBD)
	{
		key_id = 7;
	}
	if(IRCOM[2] == 0xAD)
	{
		key_id = 8;
	}
	if(IRCOM[2] == 0xB5)
	{
		key_id = 9;
	}
	beep();
	IRQEN |= (1<<21);
} 

/***************************************
说明: 	处理遥控器按键
*****************************************/ 
void HandleIR()
{
	//即烧按键
	if(key_id == 10)	
	{
		Display();
		stage = 3;
		set_min = 0;
		remain_sec = 0;
		set_tmp = BOILTMP;
	}
	//100℃按键
	if(key_id == 11)
	{
		set_tmp = BOILTMP;
	}
	//设置温度按键
	if(key_id == 14)
	{
		flash = 1;
	}
	//设置时间按键
	if(key_id == 16)
	{
		flash = 2;
	}
	//加数字按键
	if(key_id == 12)
	{
		AddKey();
	}
	//减数字按键
	if(key_id == 17)
	{
		DecKey();
	}
	//确认按键
	if(key_id == 15)
	{
		AckKey();
	}
	//重新设置按键
	if(key_id == 13)
	{
		stage =1;
		set_tmp = 100;
		Display();
	}
	//清零按键
	if(key_id == 18)
	{
		if(flash == 1)
		{
			set_tmp = 0;
		}
		if(flash == 2)
		{
			set_min = 0;
		}
	}
	//数字按键
	if(key_id >= 0 && key_id <=9)
	{
		SetNum();
	}
}

/***************************************
说明: 	快速设置数字
*****************************************/ 
void SetNum()
{
	static int i=0;
	int temp[2]={0};
	if(flash == 1)
	{
		temp[0]=set_tmp/10; 	 	//取十位
		temp[1]=set_tmp%10;       	//取百位
		//第一次按数字设定十位
		if(i == 0)
		{
			temp[0] = key_id;
		}
		//第二次按数字设定个位
		if(i == 1)
		{
			temp[1] = key_id;
		}
		set_tmp = 10*temp[0] + temp[1];
		i++;
		if(i == 2) i=0;	 
	}
	if(flash == 2)
	{
		temp[0]=set_min/10; 	 	//取十位
		temp[1]=set_min%10;       	//取百位
		//第一次按数字设定十位
		if(i == 0)
		{
			temp[0] = key_id;
		}
		//第二次按数字设定个位
		if(i == 1)
		{
			temp[1] = key_id;
		}
		set_min = 10*temp[0] + temp[1];
		i++;
		if(i == 2) i=0;	
	}
}
