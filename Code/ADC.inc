Charge_ADC_Work:

		BSET		ANSC,4
		BCLR		OEC,4

		MOVIA		0x99
		MOVAR		ADCON0
		MOVIA		0x37
		MOVAR		ADCON1
		MOVIA		0x00
		MOVAR		ADCON2		
		
		BSET		ADCON0,6
		JBTS0		ADCON0,6
		GOTO		$-1
		
		MOVR		ADH,A
		MOVAR		Charge_ADC_H
		MOVR		ADL,A
		MOVAR		Charge_ADC_L
		
		MOVIA		0x0F
		JNCMPAR		Charge_ADC_H
		GOTO		Charge_On
		BCLR		Switch_F,3
		RETURN
Charge_On:
		BSET		Switch_F,3
		RETURN