/*
 * usart.h
 *
 * Created: 2024-02-26 21:12:02
 *  Author: ARAL0011
 */ 


#ifndef USART_H_
#define USART_H_

void init_USART(unsigned int ubrr){
	// Set baud rate
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	// Enable transmitter
	UCSR0B = (1 << TXEN0) | (1 << RXEN0);
	// Set frame format: 8 data bits, 1 stop bit
	UCSR0C = (3 << UCSZ00);
}

void transferMessage(unsigned char data){
	while (!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
}

void recieveMessage(){
	char receiveMessage(){
		if (!(UCSR0A & (1<<RXC0))){
			return '\0';
		}else{return UDR0;}
	}

}


#endif /* USART_H_ */