#ifndef _TIME_H_
#define _TIME_H_

// 全局变量 设置的温度
extern int set_tmp;
// 全局变量 设置的分钟
extern int set_min;
// 全局变量 剩余秒
extern int remain_sec;
// 全局变量 标志第几个阶段
extern char stage;

void StartTime(void);
void PauseTime(void);
void CountTime(void);

#endif
