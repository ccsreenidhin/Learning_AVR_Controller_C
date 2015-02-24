#include<avr\io.h>
#include<util\delay.h>
void main()
{
	int a,b;
	DDRA=0XFF;
	DDRB=0XFF;
	DDRC=0XFF;
	DDRD=0XFF;
	DDRE=0XFF;
	DDRF=0XFF;
	TCCR0=0XAF;
	TCNT0=0X00;
	OCR0=0X9B;
	while(1)
	{
		a=1;
		b=8;
		while(b!=0)
		{
			PORTA=a;
			a=a<<1;
			_delay_ms(20);
			while(!(TIFR&0X02));
			b--;
		}
		PORTA=0;
		a=1;
		b=8;
		while(b!=0)
		{
			PORTB=a;
			a=a<<1;
			_delay_ms(20);
			while(!(TIFR&0X02));
			b--;
		}
		PORTB=0;
		a=1;
		b=8;
		while(b!=0)
		{
			PORTC=a;
			a=a<<1;
			_delay_ms(20);
			while(!(TIFR&0X02));
			b--;
		}
		PORTC=0;
		a=1;
		b=8;
		while(b!=0)
		{
			PORTD=a;
			a=a<<1;
			_delay_ms(20);
			while(!(TIFR&0X02));
			b--;
		}
		PORTD=0;
		a=1;
		b=8;
		while(b!=0)
		{
			PORTE=a;
			a=a<<1;
			_delay_ms(20);
			while(!(TIFR&0X02));
			b--;
		}
		PORTE=0;
		a=1;
		b=8;
		while(b!=0)
		{
			PORTF=a;
			a=a<<1;
			_delay_ms(20);
			while(!(TIFR&0X02));
			b--;
		}
		PORTF=0;
		a=1;
		b=8;
		while(b!=0)
		{
			PORTG=a;
			a=a<<1;
			_delay_ms(20);
			while(!(TIFR&0X02));
			b--;
		}
		PORTG=0;
		
	}
}