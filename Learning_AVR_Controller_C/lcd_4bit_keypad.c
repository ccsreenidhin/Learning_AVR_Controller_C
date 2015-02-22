#include<avr/io.h>
#include<util/delay.h>
#include"avr_lcdz.c"
char keypad();
void main()
{
char x;
lcd_init();
while(1)
{
x=keypad();
lcd_data(x);
}
}


char keypad()
{
char x;
DDRF=0X0F;
   
   while(1)
   {
   PORTF|=(1<<0);
   PORTF&=~(1<<1);
   PORTF&=~(1<<2);
   PORTF&=~(1<<3);
   if((PINF&0X10)==0X10)
   {
   while((PINF&0X10)==0x10);
   x='0';
   break;
   }
   else  if((PINF&0X20)==0X20)
   {
     while((PINF&0X20)==0x20);
   x='4';
   break;
   }
   else if((PINF&0X40)==0X40)
   {
    while((PINF&0X40)==0x40);
   x='8';
   break;
   }
   else  if((PINF&0X80)==0X80)
   {
     while((PINF&0X80)==0x80);
   x='c';
   break;
   
   }
 
   PORTF&=~(1<<0);
   PORTF|=(1<<1);
   PORTF&=~(1<<2);
   PORTF&=~(1<<3);
 
   if((PINF&0X10)==0X10)
   {
    while((PINF&0X10)==0x10);
   x='1';
   break;
   }
   else if((PINF&0X20)==0X20)
   {
       while((PINF&0X20)==0x20);
   x='5';
   break;
   }
   else  if((PINF&0X40)==0X40)
   {
       while((PINF&0X40)==0x40);
   x='9';
   break;
   }
   else if((PINF&0X80)==0X80)
   {
       while((PINF&0X80)==0x80);
   x='d';
   break;
   }
     PORTF&=~(1<<0);
     PORTF&=~(1<<1);
     PORTF|=(1<<2);
	 PORTF&=~(1<<3);
  if((PINF&0X10)==0X10)
   {
       while((PINF&0X10)==0x10);
   x='2';
   break;
   }
   else if((PINF&0X20)==0X20)
   {
       while((PINF&0X20)==0x20);
   x='6';
   break;
   }
   else if((PINF&0X40)==0X40)
   {
       while((PINF&0X40)==0x40);
   x='a';
   break;
   }
   else if((PINF&0X80)==0X80)
   {
       while((PINF&0X80)==0x80);
   x='e';
   break;
   }
  
     PORTF&=~(1<<0);
     PORTF&=~(1<<1);
     PORTF&=~(1<<2);
	 PORTF|=(1<<3);
    if((PINF&0X10)==0X10)
   {
       while((PINF&0X10)==0x10);
   x='3';
   break;
   }
   else if((PINF&0X20)==0X20)
   {
       while((PINF&0X20)==0x20);
   x='7';
   break;
   }
   else  if((PINF&0X40)==0X40)
   {
       while((PINF&0X40)==0x40);
   x='b';
   break;
   }
   else if((PINF&0X80)==0X80)
   {
       while((PINF&0X80)==0x80);
   x='f';
   break;
   }
   }
 return x;
 
 }
   
