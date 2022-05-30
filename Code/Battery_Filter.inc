Battery_Filter:
		
		BCLR		Battery_F,6
		
		MOVIA		255
		MOVAR		Battery_N
		
		MOVR		Battery_New1,0
		
		;//相等
		JNCMPAR		Battery_New2
		RETURN
		
		;// Battery_New1 > Battery_1
		;JLAR		Battery_New2
		;GOTO		Function1
		
		;// Battery_New1 < Battery_1
		JGAR		Battery_New2
		GOTO		Function2
		
Function1:
		JBTS1		Battery_F,0
		CALL		Set1
		INCR		Battery_Count,1
		MOVR		Battery_N,0
		JNCMPAR		Battery_Count
		CALL		B_Add
		RETURN
Function2:
		JBTS1		Battery_F,1
		CALL		Set2
		INCR		Battery_Count,1
		MOVR		Battery_N,0
		JNCMPAR		Battery_Count
		CALL		B_Sub
		RETURN
Set1:
		BSET		Battery_F,0
		BCLR		Battery_F,1
		CLRR		Battery_Count
		RETURN
Set2:
		BSET		Battery_F,1
		BCLR		Battery_F,0
		CLRR		Battery_Count
		RETURN
B_Add:
		CLRR		Battery_F
		CLRR		Battery_Count
		
		;//仅在关机充电的时候 才使电量增加
		;JBTS1		Switch_F,0
		;CALL		Charge_Add
		
		;MOVR		Battery_New2,0
		;MOVAR		Battery_1
		;MOVAR		Battery_New2
		RETURN
B_Sub:
		CLRR		Battery_F
		CLRR		Battery_Count
		DECR		Battery_New2,1
		MOVR		Battery_New2,0
		MOVAR		Battery_1
		MOVAR		Battery_New2
		RETURN	
Charge_Add:
		INCR		Battery_New2,1
		;//置 充电的标志
		BSET		Switch_F,3
		RETURN