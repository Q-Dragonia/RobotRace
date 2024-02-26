/*
 * adc.h
 *
 * Created: 2024-02-26 21:10:22
 *  Author: ARAL0011
 */ 


#ifndef ADC_H_
#define ADC_H_

void init_ADC(){
	ADMUX |= (1 << REFS0);
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	ADCSRA |= (1 << ADEN);
}

uint16_t readADC(uint8_t channel){
	ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
	ADCSRA |= (1 << ADSC);
	// Wait for conversion to complete
	while (ADCSRA & (1 << ADSC));
	// Return ADC result (10-bit)
	return ADC;
}



#endif /* ADC_H_ */