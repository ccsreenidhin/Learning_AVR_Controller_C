#include<avr/io.h>
#include<util/delay.h>

void lcd_cmd(int a);
void lcd_data(char a);
char keypad();
void main()
{
int i;
char x;
DDRB=0XFF;
DDRE=0XFF;
lcd_cmd(0X38);
lcd_cmd(0X0C);
lcd_cmd(0X06);
lcd_cmd(0X80);
while(1)
{
   x=keypad();
   lcd_data(x);
   _delay_ms(2);
}
   while(1);
}


void lcd_cmd(int a)
{
PORTB&=~(1<<0);
PORTB&=~(1<<1);
PORTE=a;
PORTB|=(1<<2);
_delay_ms(2);
PORTB&=~(1<<2);
_delay_ms(2);
}

void lcd_data(char a)
{
PORTB|=(1<<0);
PORTB&=~(1<<1);
PORTE=a;
PORTB|=(1<<2);
_delay_ms(2);
PORTB&=~(1<<2);
_delay_ms(2);
}






char keypad()
{
char x;
while(1)
   {
   PORTF|=(1<<0);
   PORTF&=~(1<<1);
   PORTF&=~(1<<2);
   PORTF&=~(1<<3);
   if(PINF==0X10)
   {
   while((PINF&0X10)!=0x10);
   x='0';
   break;
   }
   else if(PINF==0X20)
   {
     while((PINF&0X20)!=0x20);
   x='4';
   break;
   }
   else if(PINF==0X40)
   {
    while((PINF&0X40)!=0x40);
   x='8';
   break;
   }
   else if(PINF==0X80)
   {
     while((PINF&0X80)!=0x80);
   x='c';
   break;
   }
 
   PORTF&=~(1<<0);
   PORTF|=(1<<1);
   PORTF&=~(1<<2);
   PORTF&=~(1<<3);
 
   if(PINF==0X10)
   {
    while((PINF&0X10)!=0x10);
   x='1';
   break;
   }
   else if(PINF==0X20)
   {
       while((PINF&0X20)!=0x20);
   x='5';
   break;
   }
   else if(PINF==0X40)
   {
       while((PINF&0X40)!=0x40);
   x='9';
   break;
   }
   else if(PINF==0X80)
   {
       while((PINF&0X80)!=0x80);
   x='d';
   break;
   }
     PORTF&=~(1<<0);
     PORTF&=~(1<<1);
     PORTF|=(1<<2);
	 PORTF&=~(1<<3);
   if(PINF==0X10)
   {
       while((PINF&0X10)!=0x10);
   x='2';
   break;
   }
   else if(PINF==0X20)
   {
       while((PINF&0X20)!=0x20);
   x='6';
   break;
   }
   else if(PINF==0X40)
   {
       while((PINF&0X40)!=0x40);
   x='a';
   break;
   }
   else if(PINF==0X80)
   {
       while((PINF&0X80)!=0x80);
   x='e';
   break;
   }
  
     PORTF&=~(1<<0);
     PORTF&=~(1<<1);
     PORTF&=~(1<<2);
	 PORTF|=(1<<3);
   if(PINF==0X10)
   {
       while((PINF&0X10)!=0x10);
   x='3';
   break;
   }
   else if(PINF==0X20)
   {
       while((PINF&0X20)!=0x20);
   x='7';
   break;
   }
   else if(PINF==0X40)
   {
       while((PINF&0X40)!=0x40);
   x='b';
   break;
   }
   else if(PINF==0X80)
   {
       while((PINF&0X80)!=0x80);
   x='f';
   break;
   }
   }
   return x;
}