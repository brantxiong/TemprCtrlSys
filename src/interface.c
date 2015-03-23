/***********************************************************************/
/*                                                                     */
/*  interface.c:  界面显示模块		                     			   */
/*                                                                     */
/***********************************************************************/
#include "..\\head\\common.h"
#include "..\\head\\interface.h"
#include "..\\head\\temperature.h"
#include "..\\head\\ocm12864.h"
#include "..\\head\\time.h"
#include "..\\head\\key.h"

int flash_time = 1;

/***************************************************************
* 功能：整体界面显示
***************************************************************/
void Display()
{
	// 显示“设定温度：”
	disp_chn(0,4,0);
	disp_chn(16,4,1);
	disp_chn(16*2,4,2);
	disp_chn(16*3,4,3);
	disp_word(4*16, 4, ':');

	// 显示℃（16*16）	
	disp_chn(16*6, 4, 7);

	// 显示“设定时间：”
	disp_chn(0,6,0);
	disp_chn(16,6,1);
	disp_chn(16*2,6,4);
	disp_chn(16*3,6,5);
	disp_word(4*16, 6, ':');
	// 显示 m 和 s
	disp_word(16*5+8, 6, 'm');
	disp_word(16*7+8, 6, 's');
}

/***************************************************************
* 功能：更新界面数据
***************************************************************/
void UpdateDisplay()
{
	disp_chn(16*6, 4, 7);
	// 更新当前温度
	if(tmp < 100)
	{
		write_BigNum(16*1.25,0,tmp,3);
		disp_huge_word(16*4.75,0,58);
	}
	else
	{
		write_BigNum(16*0.75,0,tmp,4);
		disp_huge_word(16*5.25,0,58);
	}
	
	/***************更新设置的温度********************/
	if(set_tmp < 100)
	{
		//* 闪烁显示*// 
		if(flash  == 1)
		{
			switch (flash_time)
			{
				case 1:
						disp_str(16*4+8 , 4, " ");
						disp_str(16*5 , 4, "  ");	
						flash_time = 0;
						break;
				case 0:
						disp_str(16*4+8 , 4, " ");
						write_Num(16*5 , 4, set_tmp, 2);
						flash_time = 1;
						break;
			}					
		}
		else
		{
			disp_str(16*4+8 , 4, " ");
			write_Num(16*5 , 4, set_tmp, 2);
		}

	}
	else
	{
		//* 闪烁显示*//
		if(flash  == 1)
		{
			switch (flash_time)
			{
				case 1:
						disp_str(16*4+8 , 4, "   ");	
						flash_time = 0;
						break;
				case 0:
						write_Num(16*4+8, 4, set_tmp, 3);
						flash_time = 1;
						break;
			}			
		}
		else
		{
			write_Num(16*4+8, 4, set_tmp, 3);
		}
	}

	/***************更新倒计时分********************/
	if (set_min >=10)
	{
		 //*闪烁显示*//
		if(flash  == 2)	  
		{			
			switch (flash_time)
			{
				case 1:
						disp_str(4*16+8 , 6, "  ");		
						flash_time = 0;
						break;
				case 0:
						write_Num(4*16+8, 6, set_min, 2);
						flash_time = 1;
						break;
			}			
		}
		else
		{
			write_Num(4*16+8, 6, set_min, 2);
		}	
	}
	else
	{   
		//*闪烁显示*//
		if(flash  == 2)	 
			{
				switch (flash_time)
				{
					case 1:
							disp_str(4*16+8 , 6, "  ");		
							flash_time = 0;
							break;
					case 0:
							disp_word(4*16+8, 6, ' ');
							write_Num(5*16, 6, set_min, 1);
							flash_time = 1;
							break;
				}				
			}
			else
			{
				disp_word(4*16+8, 6, ' ');
				write_Num(5*16, 6, set_min, 1);
			}	

	}


	/***************更新倒计时秒********************/
	if (remain_sec >=10)
	{
		write_Num(6*16+8, 6, remain_sec, 2);
	}
	else
	{	
		disp_word(6*16+8, 6, ' ');
		write_Num(7*16, 6, remain_sec, 1);
	}
}


