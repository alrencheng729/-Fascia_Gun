Charge_LED:
		JBTS1		bT_125US_F
		RETURN	
		
		
		
		MOVIA		9
		JGAR		Battery_Charge
		GOTO		Charge_H_Count
		MOVR		Battery_Charge,0
		MOVAR		Battery_L
		
		
		INCR		bT_125US_Count_1,1
		MOVIA		200
		JNCMPAR		bT_125US_Count_1
		CALL		Charge_CountAdd_1
		MOVIA		2
		JNCMPAR		bT_125US_Count
		GOTO		Battery_LED_Switch
		CALL		COM_Clrr
		CALL		LED_Clrr
		
		MOVR		bT_125US_Count,A
		ADDAR		PCL,R
		GOTO		Charge_LED_H	
		GOTO		Charge_LED_L
Charge_Set:
		MOVIA		0
		MOVAR		Battery_Charge
		MOVIA		20
		JLAR		Battery
		GOTO		Charge_0
		MOVIA		40
		JLAR		Battery
		GOTO		Charge_20
		MOVIA		60
		JLAR		Battery
		GOTO		Charge_40
		MOVIA		80
		JLAR		Battery
		GOTO		Charge_60
		MOVIA		99
		JLAR		Battery
		GOTO		Charge_80
		GOTO		Charge_99
		
Charge_0:
		MOVIA		0
		MOVAR		Battery_Charge
		RETURN
Charge_20:
		MOVIA		20
		MOVAR		Battery_Charge
		RETURN
Charge_40:
		MOVIA		40
		MOVAR		Battery_Charge
		RETURN
Charge_60:
		MOVIA		60
		MOVAR		Battery_Charge
		RETURN
Charge_80:
		MOVIA		80
		MOVAR		Battery_Charge
		RETURN
Charge_99:
		MOVIA		99
		MOVAR		Battery_Charge
		RETURN
Charge_CountAdd_1:
		INCR		bT_125US_Count_2,1
		CLRR		bT_125US_Count_1
		MOVIA		3
		JNCMPAR		bT_125US_Count_2
		CALL		Charge_CountAdd_2
		RETURN
Charge_CountAdd_2:
		INCR		bT_125US_Count,1
		CLRR		bT_125US_Count_2
		RETURN
Charge_H_Count:
		INCR		Battery_H,1
		MOVIA		10
		SUBRA		Battery_Charge,1
		GOTO		Charge_LED
		

Charge_L_Count:
		INCR		Battery_L,1
		MOVIA		10
		SUBRA		Battery_1_L,1
		MOVIA		0
		SBCRA		Battery_1_H,1
		CLRR		STATUS
		INCR		Battery_New3,1
		GOTO		Battery_LED
		
Charge_LED_H:
		BCLR		bT_500US_F
		CALL		LED_Clrr
		BCLR		IOB,7
		BSET		IOC,3
		MOVR		Battery_H,A
		CLRR		Battery_H
		ADDAR		PCL,R
		GOTO		Battery_TAB0
		GOTO		Battery_TAB1
		GOTO		Battery_TAB2
		GOTO		Battery_TAB3
		GOTO		Battery_TAB4
		GOTO		Battery_TAB5
		GOTO		Battery_TAB6
		GOTO		Battery_TAB7
		GOTO		Battery_TAB8
		GOTO		Battery_TAB9
		;//电量小于10% 显示E1
		GOTO		Battery_TAB10
Charge_LED_L:
		
		BCLR		bT_500US_F
		CALL		LED_Clrr
		BCLR		IOC,3
		BSET		IOB,7
		MOVR		Battery_L,A
		CLRR		Battery_L
		ADDAR		PCL,R
		GOTO		Battery_TAB0
		GOTO		Battery_TAB1
		GOTO		Battery_TAB2
		GOTO		Battery_TAB3
		GOTO		Battery_TAB4
		GOTO		Battery_TAB5
		GOTO		Battery_TAB6
		GOTO		Battery_TAB7
		GOTO		Battery_TAB8
		GOTO		Battery_TAB9
		
Charge_Gear_LED:
		JBTS1		bT_125US_F
		RETURN	
		
	
		INCR		bT_125US_Count_1,1
		MOVIA		200
		JNCMPAR		bT_125US_Count_1
		CALL		Charge_CountAdd_1
		MOVIA		2
		JNCMPAR		bT_125US_Count
		GOTO		Gear_LED_Switch
		CALL		COM_Clrr
		CALL		LED_Clrr

		MOVR		bT_125US_Count,A
		ADDAR		PCL,R
		GOTO		Charge_Gear_LED_H	
		GOTO		Charge_Gear_LED_L


;Gear_H
Charge_Gear_LED_H:
		BCLR		bT_125US_F
		CALL		LED_Clrr
		BCLR		IOA,3
		BSET		IOA,2
		GOTO		Gear_TAB0
		
;Gear_L
Charge_Gear_LED_L:
		BCLR		bT_125US_F
		CALL		LED_Clrr
		BCLR		IOA,2
		BSET		IOA,3
		GOTO		Gear_TAB0
		
