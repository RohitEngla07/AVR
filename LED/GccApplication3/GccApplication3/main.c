/*
 * GccApplication2.c
 *
 * Created: 16-06-2017 19:44:00
 * Author : Rohit Engl
 */
//this is rohit engla and i had added this while learning github
unsigned char A=9;
#include <avr/io.h>
#define FOSC 1843200 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1
void USART_Init( unsigned int ubrr)
{
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
	}
void main(void)
{
	USART_Init(MYUBRR);
    /* Replace with your application code */
	USART_Transmit(A);
}
void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR = data;
}

