/***********************************************************************/
/*                                                                     */
/*  pid_ctrl.c:  PID温度控制模块	                     			   */
/*                                                                     */
/***********************************************************************/

#include "..\\head\\common.h"
#include "..\\head\\io_ctrl.h"
#include "..\\head\\time.h"
#include "..\\head\\temperature.h"
#include "..\\head\\pid_ctrl.h"


void ControlTmp()
{
	float fOut;
	fOut = PIDCalc(); //PID 计算
	if(fOut<=0)	  	//温度高于设定值，关闭加热器
	{
		BeepOn();
		DelayUs(1);
		RelayOff();		
	}			
	else			//温度低于设定值，打开加热器
	{
		BeepOff();
		DelayUs(1);
		RelayOn();		
	}	


}

float PIDCalc()
{
	static int LastError = 70; 	// 上次偏差
	float Proportion = 2; // 比例系数 Proportional Const
	float Derivative = 5; // 微分系数 Derivative Const
		
	int dError,Error;
	Error = set_tmp - tmp; // 偏差，设定值减去当前采样值
	dError = Error - LastError; // 当前微分，偏差相减
	LastError = Error;
	return (Proportion * Error // 比例项
	+ Derivative * dError // 微分项
	);
}
