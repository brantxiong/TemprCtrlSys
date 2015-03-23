/***********************************************************************/
/*                                                                     */
/*  interface.c:  ����ʱģ��		                     			   */
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
* ���ܣ���ʱʹ��
***************************************************************/
void StartTime()
{
	T1LD = 0x350000;	//1s����һ���ж�
	T1CON = 0xC4;
	IRQEN |= (1<<3);	
}

/***************************************************************
* ���ܣ���ʱ��ͣ
***************************************************************/
void PauseTime()
{
	IRQCLR |= (1<<3);	
}

/***************************************************************
* ���ܣ���ʼ��ʱ
***************************************************************/
void CountTime()
{
	switch (stage)
	{
	//��һ�׶�
	case 1:
		// ��ʾ���趨��ʱ��
		disp_chn(0,6,0);
		disp_chn(16,6,1);
		break;	 
	//�ڶ��׶μ���ʱ
	case 2:
		//��ʾ�����ơ�ʱ��
//		IRQCLR |= (1<<21); //�ر��ж�
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
		//����ʱ��������������׶�
		if(set_min == 0)
		{
			stage = 3;
			remain_sec = 0;
		}
		break;
	
	//�����׶μӼ�ʱ
	case 3:
		//��ʾ�����á�ʱ��
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
		   	IRQCLR |= (1<<21); //�ر��ж�
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


