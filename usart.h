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
	// Enable transmitter
	UCSR0B = (1 << TXEN0) | (1 << RXEN0);
	// Set frame format: 8 data bits, 1 stop bit
	UCSR0C = (3 << UCSZ00);
	
	// Enable USART Receive Complete (RXC) interrupt
	UCSR0B |= (1 << RXCIE0);
}

void transferMessage(unsigned char data){
	while (!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
}

char receiveMessage(){
	if (rxBufferIndex > 0) {
		char receivedChar = rxBuffer[0];
		// Shift elements in the buffer
		for (uint8_t i = 0; i < rxBufferIndex - 1; i++) {
			rxBuffer[i] = rxBuffer[i + 1];
		}
		rxBufferIndex--;
		return receivedChar;
	}
	return '\0';
}

ISR(USART_RX_vect){
	char receivedData = UDR0;
	rxBuffer[rxBufferIndex++] = receivedData;
}

ISR(USART_UDRE_vect){
	if (txBufferIndex > 0) {
		UDR0 = txBuffer[0];
		// Shift elements in the buffer
		for (uint8_t i = 0; i < txBufferIndex - 1; i++) {
			txBuffer[i] = txBuffer[i + 1];
		}
		txBufferIndex--;
		} else {
		// Disable UDRE interrupt if buffer is empty
		UCSR0B &= ~(1 << UDRIE0);
	}
}

#endif /* USART_H_ */