/***********************************************************************/
/*                                                                     */
/*  pid_ctrl.c:  PID�¶ȿ���ģ��	                     			   */
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
	fOut = PIDCalc(); //PID ����
	if(fOut<=0)	  	//�¶ȸ����趨ֵ���رռ�����
	{
		BeepOn();
		DelayUs(1);
		RelayOff();		
	}			
	else			//�¶ȵ����趨ֵ���򿪼�����
	{
		BeepOff();
		DelayUs(1);
		RelayOn();		
	}	


}

float PIDCalc()
{
	static int LastError = 70; 	// �ϴ�ƫ��
	float Proportion = 2; // ����ϵ�� Proportional Const
	float Derivative = 5; // ΢��ϵ�� Derivative Const
		
	int dError,Error;
	Error = set_tmp - tmp; // ƫ��趨ֵ��ȥ��ǰ����ֵ
	dError = Error - LastError; // ��ǰ΢�֣�ƫ�����
	LastError = Error;
	return (Proportion * Error // ������
	+ Derivative * dError // ΢����
	);
}
