PWM_ADC:
		BSET		ANSA,0
		BCLR		OEA,0

		MOVIA		0x90
		MOVAR		ADCON0
		MOVIA		0x35
		MOVAR		ADCON1
		MOVIA		0x00
		MOVAR		ADCON2		
		
		BSET		ADCON0,6
		JBTS0		ADCON0,6
		GOTO		$-1
		
		JBTS1		Special_F,7
		CALL		Special_Init
		
		
		
		;// 当 Work_ADC_L 的值 大于 0x20 即判断电机被堵住 
		;// 执行电机被堵住的程序
		MOVR		ADH,A
		MOVAR		Work_ADC_H
		MOVR		ADL,A
		MOVAR		Work_ADC_L
	
		MOVIA		0xFF
		JNCMPAR		Work_ADC_L
		RETURN
		
		
		MOVIA		0x3E
		JGAR		Work_ADC_L
		GOTO		Special_Work
		
		RETURN
Special_Work:
		BSET		PWM_Work,0
		BCLR		PWM2CR,7
		
		BCLR		Switch_F,0
		
		RETURN
		
Special_End:
		RETURN
		
		
		; GOTO		Special_Work
		
		
		; ;//下面为电机堵住 但是检测值 小于预设 即 进入正常状态
		; ;//首先要确认Gear_1的值 是否 与设定的 Gear 的值相等  
		; ;//如果实在加档过程中 进入了正常状态 则 首先需要清除标志 再减档
		
		; JBTS0		Special_F,0
		; BCLR		Special_F,0
		
		; MOVR		Gear,0
		; JCMPAR		Gear_1
		; DECR		Gear_1,1
		
		
		; ; JBTS0		Switch_F,0
		; ; CALL		MEMORY
		
		; RETURN
Special_Init:
		MOVR		Gear,0
		MOVAR		Gear_1

		RETURN
			
		
; Special_Work:
		; JBTS1		Special_F,0
		; GOTO		Special_Gear_Add
		
		; GOTO		Special_Gear_Sub
		
; Special_Gear_Add:
		; INCR		Gear_1,1
		
		; MOVIA		20
		; JNCMPAR		Gear_1
		; BSET		Special_F,0
		
		; RETURN

; Special_Gear_Sub:
		; DECR		Gear_1,1
		
		; MOVR		Gear,0
		; JNCMPAR		Gear_1
		; BCLR		Special_F,0
		; RETURN
		
