
#if 0
	//温度达到设定温度
	if(tmp >= set_tmp)
	{						 
		BeepOn();
		DelayUs(1);
		RelayOff();
	}
	//温度下降10摄氏度以内
	if((tmp < set_tmp) && (tmp > set_tmp -10))
	{
		RelayOff();
		BeepOff();	
	}
	//温度小于设定温度
	if(tmp <= set_tmp - 10)
	{
		DelayUs(1);
		RelayOn();
	}	
#endif
