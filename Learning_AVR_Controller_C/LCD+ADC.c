#include<avr/io.h>
#include<util/delay.h>
#include<string.h>

void lcd_cmd(int a);

void lcd_data(char a);

void main()
{
int h=0,g=0,i,l=0;
char n[4],p[4];
DDRB=0XFF;
DDRE=0XFF;
lcd_cmd(0X38);
lcd_cmd(0X0C);
lcd_cmd(0X06);
lcd_cmd(0X80);
ADMUX=0X21;
ADCSRA=0X83;
while(1)
{
ADCSRA|=0X40;
while((ADCSRA&0X10)!=0x10);
ADCSRA|=0X10;
g=ADCL;
h=ADCH;
if(l!=h)
{
	l=h;
	sprintf(n,"%d",(h<<2)+(g>>6));
	lcd_cmd(0X01);
	for(i=0;n[i]!='\0';i++)
	{
	lcd_data(n[i]);
	}
}
}
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