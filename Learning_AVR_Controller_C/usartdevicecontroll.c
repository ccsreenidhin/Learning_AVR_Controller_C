#include<avr/io.h>
#include<util/delay.h>
#include<string.h>

void main()
{
int i,r=0xff,t=0xff,u=0xff,v=0xff,w=0xff;
char m;
 DDRB=0XFF;
 DDRC=0XFF;
 DDRD=0XFF;
 DDRE=0XFF;
 DDRF=0XFF;
 UBRR0L=0x19;
 UCSR0B=0X18;
 while(1)
 {
 while((UCSR0A&0X80)!=0x80);
 UCSR0A|=0X80;
 m=UDR0;
 switch(m)
 {
 case 'a':
   PORTB=r;
   r=~r;
   break;
 case 'b':
   PORTC=t;
   t=~t;
   break;
 case 'c':
   PORTD=u;
   u=~u;
   break;
 case 'd':
   PORTE=v;
   v=~v;
   break;
 case 'e':
   PORTF=w;
   w=~w;
   break;
 }
 }
 }