#ifndef _TIME_H_
#define _TIME_H_

// ȫ�ֱ��� ���õ��¶�
extern int set_tmp;
// ȫ�ֱ��� ���õķ���
extern int set_min;
// ȫ�ֱ��� ʣ����
extern int remain_sec;
// ȫ�ֱ��� ��־�ڼ����׶�
extern char stage;

void StartTime(void);
void PauseTime(void);
void CountTime(void);

#endif
