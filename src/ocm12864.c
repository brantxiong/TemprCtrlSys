#include"..\\head\\ocm12864.h"
#include "..\\head\\common.h"

/*****将字符生产软件得到的每个汉字的32个字符依次存于tab表中*****/
/*****用PCtoLCD2002软件设置列行式和顺向输出得到对于汉字字符串*****/

/*--  宋体16*16;  此字体下对应的点阵为：宽x高=16x16   --*/
const uchar tab[12*32]={                          
0x02,0x02,0x42,0x33,0x00,0x02,0x05,0x79,0x41,0x41,0x41,0x79,0x05,0x04,0x04,0x00,
0x00,0x00,0x00,0xFC,0x09,0x11,0x02,0xC2,0x34,0x08,0x14,0x62,0x82,0x01,0x01,0x00,/*"设",0*/

0x08,0x30,0x22,0x22,0x22,0x22,0xA2,0x63,0x22,0x22,0x22,0x22,0x22,0x28,0x30,0x00,
0x01,0x02,0x04,0x78,0x04,0x02,0x02,0xFE,0x22,0x22,0x22,0x22,0x22,0x02,0x02,0x00,/*"定",1*/

0x08,0x06,0x40,0x31,0x00,0x00,0x7F,0x49,0x49,0x49,0x49,0x49,0x7F,0x00,0x00,0x00,
0x20,0x20,0x7E,0x80,0x02,0x7E,0x42,0x42,0x7E,0x42,0x7E,0x42,0x42,0x7E,0x02,0x00,/*"温",2*/

0x00,0x00,0x3F,0x24,0x24,0x24,0x3F,0xA4,0x64,0x24,0x3F,0x24,0x24,0x24,0x20,0x00,
0x02,0x0C,0xF1,0x01,0x21,0x32,0xAA,0xA4,0xA4,0xA4,0xAA,0x32,0x01,0x01,0x01,0x00,/*"度",3*/


0x00,0x3F,0x21,0x21,0x21,0x3F,0x00,0x08,0x08,0x08,0x08,0x08,0xFF,0x08,0x08,0x00,
0x00,0xFC,0x08,0x08,0x08,0xFC,0x00,0x00,0x80,0x60,0x02,0x01,0xFE,0x00,0x00,0x00,/*"时",4*/

0x00,0x1F,0x80,0x60,0x00,0x0F,0x48,0x48,0x48,0x4F,0x40,0x40,0x40,0x7F,0x00,0x00,
0x00,0xFF,0x00,0x00,0x00,0xF8,0x88,0x88,0x88,0xF8,0x00,0x02,0x01,0xFE,0x00,0x00,/*"间",5*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x6C,0x6C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"：",6*/

0x00,0x00,0x18,0x15,0x1B,0x04,0x08,0x08,0x08,0x08,0x08,0x0C,0x1E,0x00,0x00,0x00,
0x00,0x00,0x00,0xE0,0xF8,0x0C,0x04,0x04,0x04,0x04,0x04,0x08,0x18,0x00,0x00,0x00,/*"℃",7*/

0x01,0x06,0x1F,0xE0,0x20,0x26,0x3A,0x23,0x26,0x22,0x00,0x1F,0x00,0xFF,0x00,0x00,
0x00,0x00,0xFF,0x00,0x04,0x46,0x44,0xF8,0x48,0x48,0x00,0xF2,0x01,0xFE,0x00,0x00,/*"倒",8*/

0x02,0x02,0x42,0x33,0x00,0x02,0x02,0x02,0x02,0xFF,0x02,0x02,0x02,0x02,0x02,0x00,
0x00,0x00,0x00,0xFE,0x04,0x08,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,/*"计",9*/

0x00,0x00,0x47,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x7F,0x00,0x00,0x00,0x00,
0x00,0x00,0xFC,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x1E,0x00,0x00,/*"已",10*/

0x00,0x00,0x7F,0x44,0x44,0x44,0x44,0x7F,0x44,0x44,0x44,0x44,0x7F,0x00,0x00,0x00,
0x01,0x06,0xF8,0x40,0x40,0x40,0x40,0xFE,0x40,0x40,0x42,0x41,0xFE,0x00,0x00,0x00,/*"用",11*/


};

const uchar dian[32] = {

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,/*".",0*/

} ;

const uchar adj_page[]={7,6,5,4,3,2,1,0};

// 16*32大数字
const uchar BigNum[12*64] = {
0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x02,0x02,0x02,0x03,0x01,0x00,0x00,0x00,0x00,
0x00,0x00,0x0F,0x7F,0xF0,0x80,0x00,0x00,0x00,0x00,0x00,0x80,0xE0,0x7F,0x0F,0x00,
0x00,0x00,0xF8,0xFF,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xF8,0x00,
0x00,0x00,0x00,0x00,0x80,0xC0,0x60,0x20,0x20,0x20,0x60,0xC0,0x80,0x00,0x00,0x00,/*"0",0*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x80,0x80,0x80,0x80,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x20,0x20,0x20,0x60,0xE0,0xE0,0x60,0x20,0x20,0x20,0x00,0x00,0x00,/*"1",1*/

0x00,0x00,0x00,0x00,0x01,0x02,0x02,0x02,0x02,0x02,0x03,0x01,0x01,0x00,0x00,0x00,
0x00,0x00,0x78,0x98,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x83,0xFE,0x7C,0x00,0x00,
0x00,0x00,0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x00,0x00,0x07,0x00,0x00,
0x00,0x00,0xE0,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0xE0,0x80,0x00,0x00,/*"2",2*/

0x00,0x00,0x00,0x01,0x01,0x02,0x02,0x02,0x02,0x03,0x01,0x01,0x00,0x00,0x00,0x00,
0x00,0x00,0xF0,0xF0,0x00,0x00,0x01,0x01,0x01,0x03,0x86,0xFC,0x78,0x00,0x00,0x00,
0x00,0x00,0x07,0x07,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0xC0,0x7F,0x1E,0x00,0x00,
0x00,0x00,0x80,0xC0,0x40,0x20,0x20,0x20,0x20,0x20,0x40,0xC0,0x80,0x00,0x00,0x00,/*"3",3*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x03,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x01,0x06,0x0C,0x30,0x40,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,
0x00,0x08,0x38,0x48,0x88,0x08,0x08,0x08,0x08,0xFF,0xFF,0xFF,0x08,0x08,0x08,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x10,0xF0,0xF0,0xF0,0x10,0x10,0x10,0x00,/*"4",4*/

0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x00,0x00,
0x00,0x00,0x00,0x1F,0xE1,0x02,0x04,0x04,0x04,0x04,0x06,0x03,0x01,0x00,0x00,0x00,
0x00,0x00,0x07,0x86,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0x7E,0x00,0x00,
0x00,0x00,0x80,0x40,0x20,0x20,0x20,0x20,0x20,0x20,0x40,0xC0,0x80,0x00,0x00,0x00,/*"5",5*/

0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x02,0x02,0x02,0x02,0x01,0x00,0x00,0x00,
0x00,0x00,0x07,0x3F,0x70,0x81,0x01,0x02,0x02,0x02,0x02,0x03,0xC1,0xC0,0x00,0x00,
0x00,0x00,0xFC,0xFF,0xC3,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xFF,0x7E,0x00,
0x00,0x00,0x00,0x00,0x80,0xC0,0x60,0x20,0x20,0x20,0x20,0x40,0xC0,0x80,0x00,0x00,/*"6",6*/

0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x00,0x00,
0x00,0x00,0xF0,0xC0,0x80,0x00,0x00,0x00,0x01,0x06,0x18,0x60,0x80,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x3F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"7",7*/

0x00,0x00,0x00,0x00,0x01,0x03,0x02,0x02,0x02,0x02,0x03,0x01,0x00,0x00,0x00,0x00,
0x00,0x00,0x78,0xFC,0x8E,0x07,0x03,0x01,0x01,0x01,0x01,0x86,0xFC,0x78,0x00,0x00,
0x00,0x1F,0x3F,0x60,0xC0,0x80,0x00,0x80,0x80,0xC0,0xE0,0x70,0x3F,0x1F,0x00,0x00,
0x00,0x00,0x80,0xC0,0x40,0x20,0x20,0x20,0x20,0x20,0x40,0xC0,0x80,0x00,0x00,0x00,/*"8",8*/

0x00,0x00,0x00,0x01,0x01,0x02,0x02,0x02,0x02,0x02,0x01,0x00,0x00,0x00,0x00,0x00,
0x00,0x3F,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC1,0x7F,0x1F,0x00,0x00,
0x00,0x00,0x81,0xC1,0x60,0x20,0x20,0x20,0x20,0x40,0xC1,0x8F,0xFE,0xF0,0x00,0x00,
0x00,0x00,0xC0,0xC0,0x20,0x20,0x20,0x20,0x60,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,/*"9",9*/


0x00,0x00,0x00,0x00,0x07,0x04,0x08,0x04,0x07,0x00,0x00,0x00,0x00,0x01,0x03,0x02,
0x06,0x06,0x04,0x04,0x04,0x04,0x02,0x02,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x80,0x40,0x40,0x40,0x80,0x00,0x1F,0x7F,0xE0,0x80,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xFC,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x07,0x01,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0x60,
0x30,0x30,0x30,0x30,0x30,0x20,0x20,0x60,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,/*"℃",0*/

} ;
// 8*16字符
const uchar ASCIIchardot[16*96]= {
/*      */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/*!     */
0x00,0x00,0x00,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCC,0x0C,0x00,0x00,0x00,
/*"     */
0x00,0x08,0x30,0x60,0x08,0x30,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/*#     */
0x02,0x03,0x1E,0x02,0x03,0x1E,0x02,0x00,0x20,0xFC,0x20,0x20,0xFC,0x20,0x20,0x00,
/*$     */
0x00,0x0E,0x11,0x3F,0x10,0x0C,0x00,0x00,0x00,0x18,0x04,0xFF,0x84,0x78,0x00,0x00,
/*%     */
0x0F,0x10,0x0F,0x00,0x07,0x18,0x00,0x00,0x00,0x84,0x38,0xC0,0x78,0x84,0x78,0x00,
/*&     */
0x00,0x0F,0x10,0x11,0x0E,0x00,0x00,0x00,0x78,0x84,0xC4,0x24,0x98,0xE4,0x84,0x08,
/*'     */
0x08,0x68,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/*(     */
0x00,0x00,0x00,0x07,0x18,0x20,0x40,0x00,0x00,0x00,0x00,0xE0,0x18,0x04,0x02,0x00,
/*)     */
0x00,0x40,0x20,0x18,0x07,0x00,0x00,0x00,0x00,0x02,0x04,0x18,0xE0,0x00,0x00,0x00,
/**     */
0x02,0x02,0x01,0x0F,0x01,0x02,0x02,0x00,0x40,0x40,0x80,0xF0,0x80,0x40,0x40,0x00,
/*+     */
0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0xF8,0x80,0x80,0x80,0x00,
/*,     */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x0D,0x0E,0x00,0x00,0x00,0x00,0x00,
/*-     */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
/*.     */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x00,0x00,0x00,
/*/     */
0x00,0x00,0x00,0x00,0x01,0x06,0x18,0x20,0x00,0x06,0x18,0x60,0x80,0x00,0x00,0x00,
/*0     */
0x00,0x07,0x08,0x10,0x10,0x08,0x07,0x00,0x00,0xF0,0x08,0x04,0x04,0x08,0xF0,0x00,
/*1     */
0x00,0x08,0x08,0x1F,0x00,0x00,0x00,0x00,0x00,0x04,0x04,0xFC,0x04,0x04,0x00,0x00,
/*2     */
0x00,0x0E,0x10,0x10,0x10,0x11,0x0E,0x00,0x00,0x0C,0x14,0x24,0x44,0x84,0x0C,0x00,
/*3     */
0x00,0x0C,0x10,0x11,0x11,0x12,0x0C,0x00,0x00,0x18,0x04,0x04,0x04,0x88,0x70,0x00,
/*4     */
0x00,0x00,0x03,0x04,0x08,0x1F,0x00,0x00,0x00,0xE0,0x20,0x24,0x24,0xFC,0x24,0x00,
/*5     */
0x00,0x1F,0x10,0x11,0x11,0x10,0x10,0x00,0x00,0x98,0x84,0x04,0x04,0x88,0x70,0x00,
/*6     */
0x00,0x07,0x08,0x11,0x11,0x18,0x00,0x00,0x00,0xF0,0x88,0x04,0x04,0x88,0x70,0x00,
/*7     */
0x00,0x1C,0x10,0x10,0x13,0x1C,0x10,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,
/*8     */
0x00,0x0E,0x11,0x10,0x10,0x11,0x0E,0x00,0x00,0x38,0x44,0x84,0x84,0x44,0x38,0x00,
/*9     */
0x00,0x07,0x08,0x10,0x10,0x08,0x07,0x00,0x00,0x00,0x8C,0x44,0x44,0x88,0xF0,0x00,
/*:     */
0x00,0x00,0x00,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x00,
/*;     */
0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x06,0x00,0x00,0x00,0x00,
/*<     */
0x00,0x00,0x01,0x02,0x04,0x08,0x10,0x00,0x00,0x80,0x40,0x20,0x10,0x08,0x04,0x00,
/*=     */
0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x00,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00,
/*>     */
0x00,0x10,0x08,0x04,0x02,0x01,0x00,0x00,0x00,0x04,0x08,0x10,0x20,0x40,0x80,0x00,
/*?     */
0x00,0x0E,0x12,0x10,0x10,0x10,0x0F,0x00,0x00,0x00,0x00,0x0C,0x6C,0x80,0x00,0x00,
/*@     */
0x03,0x0C,0x13,0x14,0x17,0x08,0x07,0x00,0xE0,0x18,0xE4,0x24,0xC4,0x28,0xD0,0x00,
/*A     */
0x00,0x00,0x03,0x1C,0x07,0x00,0x00,0x00,0x04,0x3C,0xC4,0x40,0x40,0xE4,0x1C,0x04,
/*B     */
0x10,0x1F,0x11,0x11,0x11,0x0E,0x00,0x00,0x04,0xFC,0x04,0x04,0x04,0x88,0x70,0x00,
/*C     */
0x03,0x0C,0x10,0x10,0x10,0x10,0x1C,0x00,0xE0,0x18,0x04,0x04,0x04,0x08,0x10,0x00,
/*D     */
0x10,0x1F,0x10,0x10,0x10,0x08,0x07,0x00,0x04,0xFC,0x04,0x04,0x04,0x08,0xF0,0x00,
/*E     */
0x10,0x1F,0x11,0x11,0x17,0x10,0x08,0x00,0x04,0xFC,0x04,0x04,0xC4,0x04,0x18,0x00,
/*F     */
0x10,0x1F,0x11,0x11,0x17,0x10,0x08,0x00,0x04,0xFC,0x04,0x00,0xC0,0x00,0x00,0x00,
/*G     */
0x03,0x0C,0x10,0x10,0x10,0x1C,0x00,0x00,0xE0,0x18,0x04,0x04,0x44,0x78,0x40,0x00,
/*H     */
0x10,0x1F,0x10,0x00,0x00,0x10,0x1F,0x10,0x04,0xFC,0x84,0x80,0x80,0x84,0xFC,0x04,
/*I     */
0x00,0x10,0x10,0x1F,0x10,0x10,0x00,0x00,0x00,0x04,0x04,0xFC,0x04,0x04,0x00,0x00,
/*J     */
0x00,0x00,0x10,0x10,0x1F,0x10,0x10,0x00,0x03,0x01,0x01,0x01,0xFE,0x00,0x00,0x00,
/*K     */
0x10,0x1F,0x11,0x03,0x14,0x18,0x10,0x00,0x04,0xFC,0x04,0x80,0x64,0x1C,0x04,0x00,
/*L     */
0x10,0x1F,0x10,0x00,0x00,0x00,0x00,0x00,0x04,0xFC,0x04,0x04,0x04,0x04,0x0C,0x00,
/*M     */
0x10,0x1F,0x1F,0x00,0x1F,0x1F,0x10,0x00,0x04,0xFC,0x00,0xFC,0x00,0xFC,0x04,0x00,
/*N     */
0x10,0x1F,0x0C,0x03,0x00,0x10,0x1F,0x10,0x04,0xFC,0x04,0x00,0xE0,0x18,0xFC,0x00,
/*O     */
0x07,0x08,0x10,0x10,0x10,0x08,0x07,0x00,0xF0,0x08,0x04,0x04,0x04,0x08,0xF0,0x00,
/*P     */
0x10,0x1F,0x10,0x10,0x10,0x10,0x0F,0x00,0x04,0xFC,0x84,0x80,0x80,0x80,0x00,0x00,
/*Q     */
0x07,0x08,0x10,0x10,0x10,0x08,0x07,0x00,0xF0,0x18,0x24,0x24,0x1C,0x0A,0xF2,0x00,
/*R     */
0x10,0x1F,0x11,0x11,0x11,0x11,0x0E,0x00,0x04,0xFC,0x04,0x00,0xC0,0x30,0x0C,0x04,
/*S     */
0x00,0x0E,0x11,0x10,0x10,0x10,0x1C,0x00,0x00,0x1C,0x04,0x84,0x84,0x44,0x38,0x00,
/*T     */
0x18,0x10,0x10,0x1F,0x10,0x10,0x18,0x00,0x00,0x00,0x04,0xFC,0x04,0x00,0x00,0x00,
/*U     */
0x10,0x1F,0x10,0x00,0x00,0x10,0x1F,0x10,0x00,0xF8,0x04,0x04,0x04,0x04,0xF8,0x00,
/*V     */
0x10,0x1E,0x11,0x00,0x00,0x13,0x1C,0x10,0x00,0x00,0xE0,0x1C,0x70,0x80,0x00,0x00,
/*W     */
0x1F,0x10,0x00,0x1F,0x00,0x10,0x1F,0x00,0xC0,0x3C,0xE0,0x00,0xE0,0x3C,0xC0,0x00,
/*X     */
0x10,0x18,0x16,0x01,0x01,0x16,0x18,0x10,0x04,0x0C,0x34,0xC0,0xC0,0x34,0x0C,0x04,
/*Y     */
0x10,0x1C,0x13,0x00,0x13,0x1C,0x10,0x00,0x00,0x00,0x04,0xFC,0x04,0x00,0x00,0x00,
/*Z     */
0x08,0x10,0x10,0x10,0x13,0x1C,0x10,0x00,0x04,0x1C,0x64,0x84,0x04,0x04,0x18,0x00,
/*[     */
0x00,0x00,0x00,0x7F,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0xFE,0x02,0x02,0x02,0x00,
/*\     */
0x00,0x30,0x0C,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x60,0x1C,0x03,0x00,
/*]     */
0x00,0x40,0x40,0x40,0x7F,0x00,0x00,0x00,0x00,0x02,0x02,0x02,0xFE,0x00,0x00,0x00,
/*^     */
0x00,0x00,0x20,0x40,0x40,0x40,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/*_     */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
/*`     */
0x00,0x40,0x40,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/*a     */
0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x98,0x24,0x44,0x44,0x44,0xFC,0x04,
/*b     */
0x10,0x1F,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0xFC,0x88,0x04,0x04,0x88,0x70,0x00,
/*c     */
0x00,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x70,0x88,0x04,0x04,0x04,0x88,0x00,
/*d     */
0x00,0x00,0x00,0x01,0x01,0x11,0x1F,0x00,0x00,0x70,0x88,0x04,0x04,0x08,0xFC,0x04,
/*e     */
0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0xF8,0x44,0x44,0x44,0x44,0xC8,0x00,
/*f     */
0x00,0x01,0x01,0x0F,0x11,0x11,0x11,0x18,0x00,0x04,0x04,0xFC,0x04,0x04,0x00,0x00,
/*g     */
0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0xD6,0x29,0x29,0x29,0xC9,0x06,0x00,
/*h     */
0x10,0x1F,0x00,0x01,0x01,0x01,0x00,0x00,0x04,0xFC,0x84,0x00,0x00,0x04,0xFC,0x04,
/*i     */
0x00,0x01,0x19,0x19,0x00,0x00,0x00,0x00,0x00,0x04,0x04,0xFC,0x04,0x04,0x00,0x00,
/*j     */
0x00,0x00,0x00,0x01,0x19,0x19,0x00,0x00,0x00,0x03,0x01,0x01,0x01,0xFE,0x00,0x00,
/*k     */
0x10,0x1F,0x00,0x00,0x01,0x01,0x01,0x00,0x04,0xFC,0x24,0x40,0xB4,0x0C,0x04,0x00,
/*l     */
0x00,0x10,0x10,0x1F,0x00,0x00,0x00,0x00,0x00,0x04,0x04,0xFC,0x04,0x04,0x00,0x00,
/*m     */
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x04,0xFC,0x04,0x00,0xFC,0x04,0x00,0xFC,
/*n     */
0x01,0x01,0x00,0x01,0x01,0x01,0x00,0x00,0x04,0xFC,0x84,0x00,0x00,0x04,0xFC,0x04,
/*o     */
0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0xF8,0x04,0x04,0x04,0x04,0xF8,0x00,
/*p     */
0x01,0x01,0x00,0x01,0x01,0x00,0x00,0x00,0x01,0xFF,0x85,0x04,0x04,0x88,0x70,0x00,
/*q     */
0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00,0x70,0x88,0x04,0x04,0x05,0xFF,0x01,
/*r     */
0x01,0x01,0x01,0x00,0x01,0x01,0x01,0x00,0x04,0x04,0xFC,0x84,0x04,0x00,0x80,0x00,
/*s     */
0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0xCC,0x24,0x24,0x24,0x24,0x98,0x00,
/*t     */
0x00,0x01,0x01,0x07,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0xF8,0x04,0x04,0x00,0x00,
/*u     */
0x01,0x01,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0xF8,0x04,0x04,0x04,0x08,0xFC,0x04,
/*v     */
0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x00,0x80,0x70,0x0C,0x10,0x60,0x80,0x00,
/*w     */
0x01,0x01,0x00,0x01,0x00,0x01,0x01,0x01,0xF0,0x0C,0x30,0xC0,0x30,0x0C,0xF0,0x00,
/*x     */
0x00,0x01,0x01,0x00,0x01,0x01,0x01,0x00,0x00,0x04,0x8C,0x74,0x70,0x8C,0x04,0x00,
/*y     */
0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x81,0x71,0x0E,0x18,0x60,0x80,0x00,
/*z     */
0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x84,0x0C,0x34,0x44,0x84,0x0C,0x00,
/*{     */
0x00,0x00,0x00,0x00,0x01,0x3E,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0xFC,0x02,0x02,
/*|     */
0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,
/*}     */
0x00,0x40,0x40,0x3E,0x01,0x00,0x00,0x00,0x00,0x02,0x02,0xFC,0x00,0x00,0x00,0x00,
/*~     */
0x00,0x60,0x80,0x80,0x40,0x40,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/*      */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};




/***************************************************************
* 功能：判忙函数
***************************************************************/
void check_busy()
{
	 uchar read_data=0xff;   
	 clear_rs();        
	 set_rw();
	 clear_cs();
	 LCD_DIN_EN ;
	 
	 do
	 {
	 set_en();

	 delaynum(1);
	 delaynum(1);
	 read_data=lcddata_in;
	 clear_en();
	 }while(read_data&0x80);
	 
	 set_cs();
	 LCD_DOUT_EN;
}

/***************************************************************
* 功能：写数据函数
***************************************************************/
void write_data(unsigned long dat)
{
	check_busy();
	set_rs();
	clear_rw();
	clear_cs();
	lcddata_out=(dat<<16)|0XFF000000;
	set_en();

	delaynum(1);
	delaynum(1);
	clear_en(); 
	set_cs();
}

/***************************************************************
* 功能：写命令函数
***************************************************************/
void write_command(unsigned long command)
{
	check_busy();
	clear_rs();
	clear_rw();
	clear_cs();
	lcddata_out = (command<<16)|0xff000000;
	set_en();

	delaynum(1);
	delaynum(1);
	clear_cs();
	set_cs();
}

/***************************************************************
* 功能：复位函数
***************************************************************/
void reset(void)
{
	clear_reset();
	LCD_Delay(200);
	set_reset();
}

/***************************************************************
* 功能：清屏函数
***************************************************************/
void clear_screen(uchar m)
{
	uchar i,j;
	write_command(0x40);        //设置起始行
	for(i=0;i<8;i++)
	{
	write_command(i|0xb0);     //设置起始页
	write_command(0x10);       //设置列的高八位
	write_command(0x00);       //设置列的低八位
	for(j=0;j<128;j++)
	{
		write_data(m);           //设置清屏方式
	}
	}
}

/***************************************************************
* 功能：初始化函数
***************************************************************/
void lcd_initial()
{
	LCD_DOUT_EN;
	clear_en();
	clear_rw();
	clear_cs();
	reset();

	write_command(0xe2);          //复位函数
	write_command(0xa2);          //液晶背光电压选择
	write_command(0xa0);          //液晶驱动输出和内部RAM列选择
	write_command(0xc0);          //控制输出模式选择
	write_command(0x24);          //液晶背光灯电压设置为总电压的50%
	write_command(0x81);          //液晶背光灯电压设置控制使能
	write_command(0x28);          //对比度控制，液晶所有控制电压全关
	write_command(0x2f);          //对比度控制，液晶所有控制电压全开
	write_command(0xa6);          //现实模式设置（正常）
	write_command(0xaf);          //开显示
	write_command(0xa5);          //液晶上所有显示点开
	LCD_Delay(1000);  
	write_command(0xa4);          //液晶正常显示
	clear_screen(0);              //以清屏
	write_command(0x40);          //显示起始行设置
	write_command(0xb0);          //设置起始页
	write_command(0x10);          //设定列高八位
	write_command(0x00);          //设定列低八位
	LCD_Delay(10);
	clear_screen(0);

}

/***************************************************************
* 功能：设行起始页位置
***************************************************************/
void set_page_address(uchar page)
{
	write_command(0xb0|page);
}

/***************************************************************
* 功能：设定起始列位置
***************************************************************/
void set_colume_address(uchar colume)
{
	uchar temp;
	temp=colume>>4;
	write_command(temp|0x10);     //先送列的高三位
	temp=colume&0x0f;
	write_command(temp|0x00);     //再送列的低四位
}

/***************************************************************
* 功能：在指定位置显示一个字符（8*16）
***************************************************************/
void disp_word(uchar col,uchar pag,uchar ascii)    //列col 0～127  小行pag 0～7  字符ascii
{                                                  //4行16列时(8*i,2*j,ascii);
	uchar i,tmp;
	uint x;
	x=(ascii-0x20)*0x10;                        //字符从0x20开始起，每个16位
	write_command((adj_page[pag]&0x07)|0xb0);   //设置页地址
	tmp=col>>4;
	write_command(tmp|0x10);                    //显示列的高四位
	tmp=col&0x0f;                              
	write_command(tmp);                         //显示列的低四位
	for(i=0;i<8;i++)
	{
		write_data(ASCIIchardot[x]);               //通过查找ASCIIchardot表得到相应字符串
		x++;
	} 
	pag++;//写下半页
	write_command((adj_page[pag]&0x07)|0xb0);   //设置页地址
	tmp=col>>4;
	write_command(tmp|0x10);                    //显示列的高四位
	tmp=col&0x0f;
	write_command(tmp);                         //显示列的低四位
	for(i=0;i<8;i++)
	{
		write_data(ASCIIchardot[x]);
		x++;
	}
	pag--;                                       //写完一个字符页还原
}

/***************************************************************
* 功能：在指定位置显示一个超大数字（32*32）
***************************************************************/
void disp_huge_word(uchar col,uchar pag,uchar ascii)    //列col 0～127  小行pag 0～7  字符ascii
{                                                  //4行16列时(8*i,2*j,ascii);
	uchar i,tmp;
	uint x;
	x=(ascii- 48)*64;                        	//字符从0x20开始起，每个64位
	
	write_command((adj_page[pag]&0x07)|0xb0);   //设置页地址
	tmp=col>>4;
	write_command(tmp|0x10);                    //显示列的高四位
	tmp=col&0x0f;                              
	write_command(tmp);                         //显示列的低四位
	for(i=0;i<32;i++)
	{
		write_data(BigNum[x]);               //通过查找ASCIIchardot表得到相应字符串
		x++;
	}
	 
	pag++;										//写第二页
	write_command((adj_page[pag]&0x07)|0xb0);   //设置页地址
	tmp=col>>4;
	write_command(tmp|0x10);                    //显示列的高四位
	tmp=col&0x0f;
	write_command(tmp);                         //显示列的低四位
	for(i=0;i<32;i++)
	{
		write_data(BigNum[x]);
		x++;
	}
	
	pag++;										//写第三页
	write_command((adj_page[pag]&0x07)|0xb0);   //设置页地址
	tmp=col>>4;
	write_command(tmp|0x10);                    //显示列的高四位
	tmp=col&0x0f;
	write_command(tmp);                         //显示列的低四位
	for(i=0;i<32;i++)
	{
		write_data(BigNum[x]);
		x++;
	}
	
	pag++;										//写第四页
	write_command((adj_page[pag]&0x07)|0xb0);   //设置页地址
	tmp=col>>4;
	write_command(tmp|0x10);                    //显示列的高四位
	tmp=col&0x0f;
	write_command(tmp);                         //显示列的低四位
	for(i=0;i<32;i++)
	{
		write_data(BigNum[x]);
		x++;
	}
}

/***************************************************************
* 功能：在指定位置显示一个超大点（8*32）
***************************************************************/
void disp_huge_dot(uchar col,uchar pag)    //列col 0～127  小行pag 0～7  字符ascii
{                                                  //4行16列时(8*i,2*j,ascii);
	uchar i,tmp;
	uint x = 0;
	
	write_command((adj_page[pag]&0x07)|0xb0);   //设置页地址
	tmp=col>>4;
	write_command(tmp|0x10);                    //显示列的高四位
	tmp=col&0x0f;                              
	write_command(tmp);                         //显示列的低四位
	for(i=0;i<8;i++)
	{
		write_data(dian[x]);               //通过查找ASCIIchardot表得到相应字符串
		x++;
	}
	 
	pag++;										//写第二页
	write_command((adj_page[pag]&0x07)|0xb0);   //设置页地址
	tmp=col>>4;
	write_command(tmp|0x10);                    //显示列的高四位
	tmp=col&0x0f;
	write_command(tmp);                         //显示列的低四位
	for(i=0;i<8;i++)
	{
		write_data(dian[x]);
		x++;
	}
	
	pag++;										//写第三页
	write_command((adj_page[pag]&0x07)|0xb0);   //设置页地址
	tmp=col>>4;
	write_command(tmp|0x10);                    //显示列的高四位
	tmp=col&0x0f;
	write_command(tmp);                         //显示列的低四位
	for(i=0;i<8;i++)
	{
		write_data(dian[x]);
		x++;
	}
	
	pag++;										//写第四页
	write_command((adj_page[pag]&0x07)|0xb0);   //设置页地址
	tmp=col>>4;
	write_command(tmp|0x10);                    //显示列的高四位
	tmp=col&0x0f;
	write_command(tmp);                         //显示列的低四位
	for(i=0;i<8;i++)
	{
		write_data(dian[x]);
		x++;
	}
}
/***************************************************************
* 功能：在指定位置显示一个大数字（16*32）
***************************************************************/
void disp_big_word(uchar col,uchar pag,uchar ascii)    //列col 0～127  小行pag 0～7  字符ascii
{                                                  //4行16列时(8*i,2*j,ascii);
	uchar i,tmp;
	uint x;
	x=(ascii- 48)*64;                        	//字符从0x20开始起，每个64位
	
	write_command((adj_page[pag]&0x07)|0xb0);   //设置页地址
	tmp=col>>4;
	write_command(tmp|0x10);                    //显示列的高四位
	tmp=col&0x0f;                              
	write_command(tmp);                         //显示列的低四位
	for(i=0;i<16;i++)
	{
		write_data(BigNum[x]);               //通过查找ASCIIchardot表得到相应字符串
		x++;
	}
	 
	pag++;										//写第二页
	write_command((adj_page[pag]&0x07)|0xb0);   //设置页地址
	tmp=col>>4;
	write_command(tmp|0x10);                    //显示列的高四位
	tmp=col&0x0f;
	write_command(tmp);                         //显示列的低四位
	for(i=0;i<16;i++)
	{
		write_data(BigNum[x]);
		x++;
	}
	
	pag++;										//写第三页
	write_command((adj_page[pag]&0x07)|0xb0);   //设置页地址
	tmp=col>>4;
	write_command(tmp|0x10);                    //显示列的高四位
	tmp=col&0x0f;
	write_command(tmp);                         //显示列的低四位
	for(i=0;i<16;i++)
	{
		write_data(BigNum[x]);
		x++;
	}
	
	pag++;										//写第四页
	write_command((adj_page[pag]&0x07)|0xb0);   //设置页地址
	tmp=col>>4;
	write_command(tmp|0x10);                    //显示列的高四位
	tmp=col&0x0f;
	write_command(tmp);                         //显示列的低四位
	for(i=0;i<16;i++)
	{
		write_data(BigNum[x]);
		x++;
	}
}

/***************************************************************
* 功能：在指定位置显示一个汉字（16*16）
***************************************************************/
void disp_chn(uchar col,uchar pag,uchar cn)    //列col 0～127  小行pag 0～7  汉字cn tab表中的序号0～x
{                                              //4行8列时(16*i,2*j,cn);
	uchar i,tmp;
	uint x;
	x=cn<<5;
	write_command((adj_page[pag]&0x07)|0xb0);   //设置页地址
	tmp=col>>4;
	write_command(tmp|0x10);                    //显示列的高四位
	tmp=col&0x0f;                              
	write_command(tmp);                         //显示列的低四位
	for(i=0;i<16;i++)
	{
	write_data(tab[x]);                        //通过查找tab表得到相应字符串
	x++;
	}
	pag++;                                      //写下半页
	write_command((adj_page[pag]&0x07)|0xb0);   //设置页地址
	tmp=col>>4;
	write_command(tmp|0x10);                    //显示列的高四位
	tmp=col&0x0f;
	write_command(tmp);                         //显示列的低四位
	for(i=0;i<16;i++)
	{
	write_data(tab[x]);
	x++;
	}
	pag--;                                       //写完一个字符页还原
}

/***************************************************************
* 功能：在指定位置显示一个字符串
***************************************************************/
void disp_str(uchar col,uchar pag,uchar *cn)    
{
	while(*cn!=0)
	{
		if(col==128)
		{
			  pag+=2;
			  col=0;
		}
		if(pag==8)
		{
			pag=0;
		}
		disp_word(col,pag,*cn++);
		col+=8;
	}
}

/***************************************************************
* 功能：在指定的位置显示一个点
***************************************************************/
void setpoint(uchar x,uchar y)     //x横坐标 0-127 往右   y纵坐标 0-63 往下
{
	set_page_address(y/8);      //y用以确定某一页，0-7页
	set_colume_address(x);   //x用于确定某一列，0-127列
	write_data(0x01<<(y%8));  //再y确定某一页的具体点
 
}

/***************************************************************
* 功能：在指定行pag低端的位置显示一个点
***************************************************************/
void point(uchar x,uchar y)
{
	set_page_address(x);      //x用以确定某一页，0-7页
	set_colume_address(y);   //Y用于确定某一列，0-127列
	write_data(0x80);
}

/***************************************************************
* 功能：显示图片
***************************************************************/
void disp_bmp( uchar const *puts )
{
	uchar i,j;
	write_command(0x40);     
	for(i=8;i>0;i--)
	{
	 write_command((i-1)|0xB0);
	 write_command(0x10);      
	 write_command(0x00);      
	 for(j=0;j<128;j++)
	 {
	   write_data( *puts++ );                       
	  }

	}
}

/***************************************************************
* 功能：显示竖线
***************************************************************/
void shuxian(uchar n,uchar e,uchar f)  //列 n 0-127  e,f行 0-7 从e行到f行画竖线
{
	uint i;
	for(i=e;i<(f+1);i++)
	{
		set_page_address(i);
		set_colume_address(n); 
		write_data(0xff);
	}
}

/***************************************************************
* 功能：显示横线
***************************************************************/
void hengxian(uchar k)     //行 k 0-7 底端画横线
{
 uint i;
 for(i=0;i<128;i++)
 {
  point(k,i);
  //write_data(0xff);
 }
}

/***************************************************************
* 功能：显示大整数
***************************************************************/
void write_BigNum(uchar col,uchar pag,float x,char y)   //x为要显示的浮点数,y为要显示的有效位数.最多显示8位有效数字 //列col 0～127  小行pag 0～7 
 {
    unsigned char dian = 0,k;
	unsigned char N[4]={0};
	int num0;
	long dis_num;
	
	num0=x;       	//取出欲显示的数的整数部分,以便判断小数点的位置
	if(num0>0&&num0<10)	             dian=1; //表示小数点在第1位数后面	
	if(num0>=10&&num0<100)	         dian=2;
	if(num0>=100&&num0<1000)         dian=3;

	if(dian==1)			   dis_num=x*1000;	//对x进行放大
	if(dian==2)            dis_num=x*100;  
	if(dian==3)            dis_num=x*10;
		
  

   	N[0]=dis_num%10000/1000;	//取出数字的高位
    N[1]=dis_num%1000/100;	   	//取出数字的次高位
	N[2]=dis_num%100/10;
	N[3]=dis_num%10;


	for(k = 0; k<y; k++)
	{
		disp_big_word(col,pag,N[k]+0x30);
		col+=16;
		if(dian-1 == k)  
		{	
			disp_huge_dot(col,pag);
			col+=8;  
		}
	} 	
}

/***************************************************************
* 功能：显示正常整数
***************************************************************/
void write_Num(uchar col,uchar pag,int x,char y)   //x为要显示的浮点数,y为要显示的有效位数.最多显示8位有效数字 //列col 0～127  小行pag 0～7 
 {
    unsigned char dian = 0,k;
	unsigned char N[4]={0};
	int num0;
	long dis_num;
	
	num0=x;       	//取出欲显示的数的整数部分,以便判断小数点的位置
	if(num0>0&&num0<10)	             dian=1; //表示小数点在第1位数后面	
	if(num0>=10&&num0<100)	         dian=2;
	if(num0>=100&&num0<1000)         dian=3;

	if(dian==1)			   dis_num=x*100;	//对x进行放大
	if(dian==2)            dis_num=x*10;  
	if(dian==3)            dis_num=x*1;	//以保证x中的小数都能显示
  

   	N[1]=dis_num/100;	       //取出数字的高位
    N[2]=dis_num%100/10;	   //取出数字的次高位
	N[3]=dis_num%10;

	k=0;
   
	if(k<y)
	{
	  disp_word(col,pag,N[1]+0x30);  col+=8;	k=k+1;//显示第一个数字,并用K计数
	}	  
	   
	if(k<y)						      //如果中K在有效的位数之内则继续显示
	{
	  disp_word(col,pag,N[2]+0x30);  col+=8;	  k=k+1;//显示第二个数字,并用K计数
	}		 
	   
	if(k<y)
	{
	  disp_word(col,pag,N[3]+0x30); col+=8;		k=k+1;
	}		
	
}
/***************************************************************
* 功能：显示浮点数
***************************************************************/
void write_floatNum(uchar col,uchar pag,double x,char y)   //x为要显示的浮点数,y为要显示的有效位数.最多显示8位有效数字 //列col 0～127  小行pag 0～7 
 {
    unsigned char dian,k;
	unsigned char N[9]={0};
	long num0;
	long dis_num;
	
	num0=x;       //取出欲显示的数的整数部分,以便判断小数点的位置
	if(num0<=0)                      dian=0; //依次判断小数点的位置
	if(num0>0&&num0<10)	             dian=1; //表示小数点在第1位数后面
	if(num0>=10&&num0<100)	         dian=2;
	if(num0>=100&&num0<1000)         dian=3;
	if(num0>=1000&&num0<10000)	     dian=4; //表示小数点在第4位数后面
	if(num0>=10000&&num0<100000)     dian=5; 
	if(num0>=100000&&num0<1000000)	 dian=6;
	if(num0>=1000000&&num0<10000000) dian=7;

	if(dian==0)			   dis_num=x*100000000;	//放大
	if(dian==1)			   dis_num=x*10000000;	//对x进行放大
	if(dian==2)            dis_num=x*1000000;  
	if(dian==3)            dis_num=x*100000;	//以保证x中的小数都能显示
	if(dian==4)            dis_num=x*10000;
	if(dian==5)            dis_num=x*1000;
	if(dian==6)            dis_num=x*100;
	if(dian==7)            dis_num=x*10;
	  

   	N[1]=dis_num/10000000;	           //取出数字的高位
    N[2]=dis_num%10000000/1000000;	   //取出数字的次高位
	N[3]=dis_num%1000000/100000;
	N[4]=dis_num%100000/10000;
	N[5]=dis_num%10000/1000;
	N[6]=dis_num%1000/100;
	N[7]=dis_num%100/10;
	N[8]=dis_num%10;

	k=0;
    if(dian==0)
	  {
	   disp_word(col,pag,0+0x30);	col+=8;   //列col 0～127  小行pag 0～7  
	   disp_word(col,pag,'.');	  	col+=8;
	   }
	   
	if(k<y)
	{
	  disp_word(col,pag,N[1]+0x30);  col+=8;	k=k+1;//显示第一个数字,并用K计数
	  if(dian==1)  {disp_word(col,pag,'.');	  	col+=8;  }//输入小数点'.'或2e
	  }	  
	   
	if(k<y)						      //如果中K在有效的位数之内则继续显示
	 {
	  disp_word(col,pag,N[2]+0x30);  col+=8;	  k=k+1;//显示第二个数字,并用K计数
	  if(dian==2) {disp_word(col,pag,'.');	  	col+=8;}	  //输入小数点'.'或2e
	  }		 
	   
	if(k<y)
	 {
	  disp_word(col,pag,N[3]+0x30);col+=8;		k=k+1;
	  if(dian==3) {disp_word(col,pag,'.');	  	col+=8;	  }
	  }		
	   
	if(k<y)
	 {
	 disp_word(col,pag,N[4]+0x30);  col+=8;	  k=k+1;
	  if(dian==4) {disp_word(col,pag,'.');	  	col+=8;	  }
	  }		
	   
	if(k<y)
	 {
	  disp_word(col,pag,N[5]+0x30);col+=8;	k=k+1;
	  if(dian==5) {disp_word(col,pag,'.');	  	col+=8;	  }
	  }		
	   
	if(k<y)
 	 {
	  disp_word(col,pag,N[6]+0x30);col+=8;	k=k+1;
	  if(dian==6)  {disp_word(col,pag,'.');	  	col+=8;	  }
	  }		
	   
	if(k<y)
	 {
	  disp_word(col,pag,N[7]+0x30);	col+=8;	k=k+1;
	  if(dian==7)  {disp_word(col,pag,'.');	  	col+=8;	  }
	  }		
	   
	if(k<y)
	{
	disp_word(col,pag,N[8]+0x30);  	 	col+=8;
     }  
}

/***************************************************************
* 功能：延时函数
***************************************************************/
void LCD_Delay(unsigned long v)
{
 while(v--);
}
/***************************************************************
* 功能：延时函数
***************************************************************/
void delaynum(unsigned char num)
{
  while(num--) ;
}
