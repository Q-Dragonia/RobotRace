/*
 * app.h
 *
 * Created: 25.02.2024 21:36:09
 *  Author: quinh
 */ 


#ifndef APP_H_
#define APP_H_

unsigned char USART_IsAvailable(){
	return (UCSR0A & (1 << RXC0));
}

unsigned char USART_Receive(){
	
	//Check if data is available to read
	if(USART_IsAvailable()){
		//Get and return received data from buffer
		return UDR0;
	}
	//Return B if no data available
	return 'C';
}



#endif /* APP_H_ */