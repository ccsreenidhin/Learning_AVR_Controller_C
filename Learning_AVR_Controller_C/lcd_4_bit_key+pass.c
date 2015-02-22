#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include"avr_lcdz.c"
char keypad();
void main()
{
char x,a[20],b[20]="123";
int m,i=0;
lcd_init();
while(1)
{
i=0;
lcd_cmd(0x01);
lcd_str("enter password");
lcd_cmd(0xc0);

while(1)
{
x=keypad();
if(x=='f')
{
lcd_cmd(0x01);
break;
}
a[i]=x;
i++;
lcd_data('*');
}
m=strcmp(a,b);
if(m!=0)
{
lcd_cmd(0x01);
lcd_str("Wrong Password");
_delay_ms(500);
}
else
{
lcd_cmd(0x01);
lcd_str("Access Granted");
while(1);
}
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
   
