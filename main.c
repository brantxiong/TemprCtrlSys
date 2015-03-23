#include "head\\common.h"
#include "head\\temperature.h"
#include "head\\serial.h"
#include "head\\ocm12864.h"
#include "head\\io_ctrl.h"
#include "head\\interface.h"
#include "head\\time.h"
#include "head\\int.h"
#include "head\\key.h"	   
#include "head\\IR.h"
#include "head\\pid_ctrl.h"
#include "irq_arm.c" 

int main (void)  
{
	SysClkInit();
	SerialInit();
	IOInit();
	GP3CON=0x00000000;
  	GP4CON=0x00000000;
	lcd_initial();
	StartTime();
	KeyInit();
	IRInit();

	Display();	
	RelayOff();
	while(1)
	{
		ReadTmp();
		tmp += 5;
		UpdateDisplay();
		switch (stage)
		{
			case 1:
				RelayOff();
				break;
			case 2:
				RelayOff();
				break;
			case 3:
				ControlTmp();
				break;
			default:
				break;
		}	
	}
}

