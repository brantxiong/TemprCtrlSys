
#if 0
	//�¶ȴﵽ�趨�¶�
	if(tmp >= set_tmp)
	{						 
		BeepOn();
		DelayUs(1);
		RelayOff();
	}
	//�¶��½�10���϶�����
	if((tmp < set_tmp) && (tmp > set_tmp -10))
	{
		RelayOff();
		BeepOff();	
	}
	//�¶�С���趨�¶�
	if(tmp <= set_tmp - 10)
	{
		DelayUs(1);
		RelayOn();
	}	
#endif
