/***********************************************************************/
/*                                                                     */
/*  read_tmp.c:  温度读取模块                     					   */
/*                                                                     */
/***********************************************************************/

#include "..\\head\\common.h"
#include "..\\head\\temperature.h"

float tmp;
char tmp_str[7] = {0};

/***************************************************************
* 功能：微妙延时子程序
***************************************************************/
void DelayUs(int lengh)
{
	int i=lengh*9;
	while(i>0)
	 i--;
}

/***************************************************************
* 功能：毫妙延时子程序
***************************************************************/
void DelayMs(int a)
{
	int i;
	for(i=0;i<1000*a;i++)
		DelayUs(1);
}

/***************************************************************
* 功能：系统时钟配置子程序 41.78MHz
***************************************************************/
void SysClkInit(void)
{
	PLLKEY1 = 0xAA;
	PLLCON = 0x01;
	PLLKEY2 = 0x55;

	POWKEY1 = 0x01;
	POWCON = 0x00;		
	POWKEY2 = 0xF4;
}

/***************************************************************
* 功能：总线初始化子程序
***************************************************************/
void TmpBusInit(void)     
{        
	POUT_1;          			// 复位脉冲（下降沿）
	POUT_0; 
	DelayUs(600);   			// 延时480-960us 
	PIN;        				// 拉高总线
	DelayUs(45);    			// 延时15-60us
	if((GP2DAT&0x80)==0x80)   // 判断DS18B20是否存在，如果存在会产生一个低电平60-240us
		while(1);
	PIN;             			// 拉高总线 
	DelayUs(300); 
}

/***************************************************************
* 功能：读数据子程序(先传输低位后传输高位)
***************************************************************/
unsigned char ReadTmpBus(void) 
{ 
	unsigned char data_18b20=0;   
	unsigned char n= 1;  
	while(n) 
	{ 
		POUT_1;
		POUT_0; 
		DelayUs(1);        // 拉低总线1-3us,通知从机准备收发数据 
		PIN;                // 释放总线 
		DelayUs(2);        // 从机在1-15us内会向总线输出数据的某一位(1或者0)
		 if((GP2DAT&0x80)==0x80) 
		   data_18b20+=n;    // 读取总线数据 
		DelayUs(45);       // 等待从机释放总线 
		n<<=1; 
	}  
	return data_18b20; 
}

/***************************************************************
* 功能：写数据子程序(先写低位再写高位) 
***************************************************************/  
void WriteTmpBus(unsigned char data) 
{  
	unsigned char n= 1;  
	while(n) 
	{ 
	POUT_1;
	POUT_0;
	DelayUs(1);
	if(data&n)
		{ POUT_1;} 
	else    
		POUT_0;      	// 向总线写数据的某一位(1或者0) 
	DelayUs(60);  		// 等待60us保证从机有足够的时间进行采样 
	PIN;           		// 释放总线     
	DelayUs(2);   		// 释放总线时间要大于1us    
	n<<=1; 
	} 
}


/***************************************************************
* 功能：读取温度函数 
***************************************************************/
void ReadTmp(void)   
{
	unsigned char data_H, data_L;
	TmpBusInit();        // 调用初始化子程序 
	WriteTmpBus(0xCC);   // 跳过ID码匹配,适用于一个DS18B20 
	
	//可以使用8条语句代替上面的那条语句依次写入8个ID码,这样就是ID码匹配了 
	//如果不知道18B20的ID码,可以在总线上接入单个18B20 
	//然后参考下面的读取语句,依次读取18B20的8个ID码 
	//记得使用CRC8校验一下是否正确 
	
	WriteTmpBus(0x44);   		// 启动温度转换           
	DelayMs(100);         		// 等待转换结束
	TmpBusInit();        		// 调用初始化子程序 
	WriteTmpBus(0xCC);   		// 跳过ID码匹配 
	WriteTmpBus(0xBE);   		// 通知DS18B20,准备读数据
	
	data_L = ReadTmpBus();   	// 读取第一个数据(温度低字节) 
	data_H = ReadTmpBus();   	// 读取第二个数据(温度高字节) 
	
	
	if(data_H>0x7f)      		//最高位为1时温度是负
	{
		data_L = ~data_L;       //补码转换，取反加一
		data_H = ~data_H + 1;       
	}
	
	ConvertTmp(data_H, data_L);      
}

/***************************************************************
* 功能：转换温度函数 
***************************************************************/
void ConvertTmp(unsigned char data_H, unsigned char data_L)
{
	unsigned char zhengshu;
	unsigned char xiaoshu1;
	unsigned char xiaoshu2;

	zhengshu = data_L/16 + data_H*16;      	//整数部分
	xiaoshu1 = (data_L & 0x0f)*10/16; 		//小数第一位
	xiaoshu2 = (data_L & 0x0f)*100/16%10;	//小数第二位 
	// 更新温度
	tmp =  zhengshu + xiaoshu1 * 0.1 + xiaoshu2 * 0.01;
	// 将温度转换为字符串
	if(zhengshu < 100)
	{ 
		tmp_str[0] = zhengshu / 10 + 0x30;
		tmp_str[1] = zhengshu % 10 + 0x30;
		tmp_str[2] = '.';
		tmp_str[3] = xiaoshu1 + 0x30;
		tmp_str[4] = xiaoshu2 + 0x30; 
		tmp_str[5] = 0x0A;
		tmp_str[6] = 0x00;
	}
	if(zhengshu >= 100)
	{
		tmp_str[0] = zhengshu / 100 + 0x30;
		tmp_str[1] = (zhengshu/10)%10 + 0x30;
		tmp_str[2] = zhengshu % 10 + 0x30;
		tmp_str[3] = '.';
		tmp_str[4] = xiaoshu1 + 0x30;
		tmp_str[5] = xiaoshu2 + 0x30; 
		tmp_str[6] = 0x0A;
	}	
}
