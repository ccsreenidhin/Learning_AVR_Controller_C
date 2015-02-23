#include<avr/io.h>
#include<util/delay.h>

void lcd_cmd(int a);
void lcd_data(char a);
void main()
{
char b;
char n[20];
DDRB=0XFF;
DDRF=0XFF;
DDRD=0XFF;
UBRR0L=0x19;
UCSR0B=0X18;
lcd_cmd(0X38);
lcd_cmd(0X0C);
lcd_cmd(0X06);
lcd_cmd(0X80);
lcd_data('g');
while(1)
{
while((UCSR0A&0X80)!=0x80);
UCSR0A|=0X80;
b=UDR0;
lcd_data(b);
}
while(1);
}


void lcd_cmd(int a)
{
PORTB&=~(1<<0);
PORTB&=~(1<<1);
PORTF=a;
PORTB|=(1<<2);
_delay_ms(2);
PORTB&=~(1<<2);
_delay_ms(2);
}

void lcd_data(char a)
{
PORTB|=(1<<0);
PORTB&=~(1<<1);
PORTF=a;
PORTB|=(1<<2);
_delay_ms(2);
PORTB&=~(1<<2);
_delay_ms(2);
}