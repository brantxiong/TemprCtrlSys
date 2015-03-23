#ifndef  _KEY_H_
#define  _KEY_H	


extern char flash;

void KeyInit(void);
void CheckKey(void);
void SwitchKey(void);
void AddKey(void);
void DecKey(void);
void AckKey(void);


#endif
