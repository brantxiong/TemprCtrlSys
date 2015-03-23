#ifndef _IO_CTRL_H_
#define _IO_CTRL_H_


// IO口初始化函数
void IOInit(void);
// 蜂鸣器使用P0.1控制
void BeepOn(void);
void BeepOff(void);
// 继电器使用P0.2和P0.3控制
void RelayOn(void);
void RelayOff(void);


#endif
