/*
 * GccApplication5.c
 *
 * Created: 24-06-2017 18:55:30
 * Author : Rohit Engl
 */
#include <avr/io.h> 
#define F_CPU 14745600UL
#include <util/delay.h>
//#define BAUDRATE 9600
//#define BAUD_PRESCALER 95
//void USART_Init( unsigned int ubrr)
//{
	///*Set baud rate */
	//UBRRH = (unsigned char)(95>>8);
	//UBRRL = (unsigned char)95;
	//UCSRB = (1<<RXEN)|(1<<TXEN);
	///* Set frame format: 8data, 2stop bit */
	//UCSRC = (1<<URSEL)|(3<<UCSZ0);
//}
//void USART_Transmit( unsigned char data )
//{
	///* Wait for empty transmit buffer */
	//while ( !( UCSRA & (1<<UDRE)) )
	//{
		//;
	//}
	///* Put data into buffer, sends the data */
	//UDR = data;
//}
//unsigned char USART_receive(void)
//{
	//while (!(UCSRA & (1<<RXC)))
	//{
		//;
	//}
	//return UDR;
//}
void SPI_MasterInit(void)
{
	/* Set MOSI and SCK output, all others input */
	DDRB = 0b10110000;
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}
void SPI_MasterTransmit(unsigned char cData)
{
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)))
	{
		;
	}
}
int main(void)
{
	SPI_MasterInit();
	//USART_Transmit('3');
    /* Replace with your application code */
    while (1) 
    {
		
		//USART_Transmit('4');
		//unsigned char c;
		//c=USART_receive();
		//USART_Transmit('5');
		//unsigned char b;
		SPI_MasterTransmit('a');
		_delay_ms(100);
		//USART_Transmit('6');
		//USART_Transmit('7');
		//USART_Transmit('8');
    }
}

