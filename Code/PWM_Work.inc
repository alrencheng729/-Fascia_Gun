PWM_On:

		; 16kHz
		BSET		OEA,1
		
		MOVIA		b'00001011'
		MOVAR		T0CR
		CLRR		TC0CL
		CLRR		TC0CH
		CLRR		TC0PRH
		MOVIA		123
		MOVAR		TC0PRL
	
 		MOVIA		0x00
		MOVAR		PWM2DH
		
		BSET		T0CR,7
		BSET		PWM2CR,7
		
		BSET		PWM2CR,6
		
		
		RETURN
		
