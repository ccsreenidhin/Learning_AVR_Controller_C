#include<avr/io.h>
#include<util/delay.h>

void lcd_cmd(int a);
void lcd_data(char a);
void lcd_cmd1(int a);
void lcd_data1(char a);
void main()
{
int i;
char b[20]="WELCOME",c[20]="C C";
DDRB=0XFF;
DDRE=0XFF;
DDRD=0XFF;
DDRF=0XFF;
lcd_cmd(0X38);
lcd_cmd(0X0C);
lcd_cmd(0X06);
lcd_cmd(0X80);
for(i=0;i<7;i++)
{
lcd_data(b[i]);
}


lcd_cmd1(0X38);
lcd_cmd1(0X0C);
lcd_cmd1(0X06);
lcd_cmd1(0X80);
for(i=0;i<7;i++)
{
lcd_data1(c[i]);
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

void lcd_cmd1(int a)
{
PORTD&=~(1<<0);
PORTD&=~(1<<1);
PORTF=a;
PORTD|=(1<<2);
_delay_ms(2);
PORTD&=~(1<<2);
_delay_ms(2);
}

void lcd_data1(char a)
{
PORTD|=(1<<0);
PORTD&=~(1<<1);
PORTF=a;
PORTD|=(1<<2);
_delay_ms(2);
PORTD&=~(1<<2);
_delay_ms(2);
}

