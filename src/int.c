/***********************************************************************/
/*                                                                     */
/*  int.c:  按键处理模块			                     			   */
/*                                                                     */
/***********************************************************************/
#include "..\\head\\common.h"
#include "..\\head\\int.h"
#include "..\\head\\time.h"
#include "..\\head\\io_ctrl.h"
#include "..\\head\\key.h"
#include "..\\head\\IR.h"
#include "..\\head\\serial.h"
#include "..\\head\\temperature.h"

	 
void IRQ_Handler(void) __irq 
{
	if((IRQSTA & (1<<3) ) != 0)	//判断是否为Timer1 IRQ
	{
		CountTime();
		T1CLRI = 0;
		T1LD = 0x350000;
	}
	if((IRQSTA & (1<<22)) != 0)
	{		
		PauseTime();
		CheckKey();
		StartTime();
	}
	if((IRQSTA & (1<<21)) != 0)
	{
		PauseTime();
		CheckIR();
		HandleIR();
		DelayMs(10);
		StartTime();
	}

	return;

}
