/*
 * usart.h
 *
 * Created: 2024-02-26 21:12:02
 *  Author: ARAL0011
 */ 


#ifndef USART_H_
#define USART_H_

void custom_delay_ms(uint16_t ms) {
	for (uint16_t i = 0; i < ms; i++) {
		for (volatile uint16_t j = 0; j < 850; j++) { // Adjust this value for the desired delay
			asm("nop"); // No operation, helps in preventing optimization
		}
	}
}


void init_USART(unsigned int ubrr){
	// Set baud rate
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	// Enable transmitter and receiver
	UCSR0B = (1 << TXEN0) | (1 << RXEN0);
	// Set frame format: 8 data bits, 1 stop bit
	UCSR0C = (3 << UCSZ00);
}

void transferMessage(int data) {
	char buffer[20]; // Assuming a max of 20 characters for the number
	snprintf(buffer, sizeof(buffer), "%d\n", data);
	
	for (int i = 0; buffer[i] != '\0'; i++) {
		while (!(UCSR0A & (1 << UDRE0)));
		UDR0 = buffer[i];
	}
}

char receiveMessage(){
	// Wait for data to be received
	if (!(UCSR0A & (1 << RXC0))) {
		return '\0';
	}
	// Get and return received data from buffer
	return UDR0;
}

#endif /* USART_H_ */