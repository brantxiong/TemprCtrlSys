/***********************************************************************/
/*                                                                     */
/*  interface.c:  倒计时模块		                     			   */
/*                                                                     */
/***********************************************************************/
#include "..\\head\\common.h"
#include "..\\head\\time.h"
#include "..\\head\\serial.h"
#include "..\\head\\io_ctrl.h"
#include "..\\head\\int.h"
#include "..\\head\\ocm12864.h"

int set_tmp = 40;
int set_min = 20;
int remain_min = 0;
int remain_sec = 0;
char stage = 1;

/***************************************************************
* 功能：计时使能
***************************************************************/
void StartTime()
{
	T1LD = 0x350000;	//1s进入一次中断
	T1CON = 0xC4;
	IRQEN |= (1<<3);	
}

/***************************************************************
* 功能：计时暂停
***************************************************************/
void PauseTime()
{
	IRQCLR |= (1<<3);	
}

/***************************************************************
* 功能：开始计时
***************************************************************/
void CountTime()
{
	switch (stage)
	{
	//第一阶段
	case 1:
		// 显示”设定“时间
		disp_chn(0,6,0);
		disp_chn(16,6,1);
		break;	 
	//第二阶段减计时
	case 2:
		//显示“倒计”时间
//		IRQCLR |= (1<<21); //关闭中断
		disp_chn(0,6,8);
		disp_chn(16,6,9);
		disp_chn(16*2,6,4);
		disp_chn(16*3,6,5);
		disp_chn(16*3,6,5);
		disp_word(3*16, 6, ':');		
		remain_sec--;
		if(remain_sec < 0)
		{
			set_min--;
			remain_sec = 59;
		}
		//倒计时结束，进入第三阶段
		if(set_min == 0)
		{
			stage = 3;
			remain_sec = 0;
		}
		break;
	
	//第三阶段加计时
	case 3:
		//显示“已用”时间
		if(remain_sec == 0 && set_min == 0)
		{
			disp_chn(0,6,10);
			disp_chn(16,6,11);
			disp_chn(16*2,6,4);
			disp_chn(16*3,6,5);
			disp_chn(16*3,6,5);
			disp_word(3*16, 6, ':');
			disp_word(16*5+8, 6, 'm');
			disp_word(16*7+8, 6, 's');
		   	IRQCLR |= (1<<21); //关闭中断
		}
	
		remain_sec++;
		if(remain_sec == 60)
		{
			set_min++;
			remain_sec = 0;
		}
		break;
	}	
}


