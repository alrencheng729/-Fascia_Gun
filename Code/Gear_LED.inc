;显示当前档位
;传进来的值为 Gear_1

Gear_LED:
		JBTS1		bT_500US_F
		RETURN	
		
		
		JBTS0		Switch_F,2
		CALL 		Gear_Count
	
		INCR		bT_500US_Count_1,1
		MOVIA		2
		JNCMPAR		bT_500US_Count_1
		CALL		Battery_CountAdd
		MOVIA		3
		JNCMPAR		bT_500US_Count
		
		GOTO		Gear_LED_Switch
		CALL		COM_Clrr
		CALL		LED_Clrr

		MOVR		bT_500US_Count,A
		ADDAR		PCL,R
		GOTO		MainLoop
		GOTO		Gear_LED_H	
		GOTO		Gear_LED_L
Gear_Count:
		MOVIA		9
		JGAR		Gear_2
		GOTO		Gear_H_Count
		MOVR		Gear_2,0
		MOVAR		Gear_L
		RETURN
Gear_H_Count:
		INCR		Gear_H,1
		MOVIA		10
		SUBRA		Gear_2,1
		GOTO		Gear_LED

;Gear_H
Gear_LED_H:
		BCLR		bT_500US_F
		CALL		LED_Clrr
		BCLR		IOA,3
		BSET		IOA,2
		MOVR		Gear_H,A
		ADDAR		PCL,R
		GOTO		Gear_TAB0
		GOTO		Gear_TAB1
		GOTO		Gear_TAB2
;Gear_L
Gear_LED_L:
		BCLR		bT_500US_F
		CALL		LED_Clrr
		BCLR		IOA,2
		BSET		IOA,3
		MOVR		Gear_L,A
		ADDAR		PCL,R
		GOTO		Gear_TAB0
		GOTO		Gear_TAB1
		GOTO		Gear_TAB2
		GOTO		Gear_TAB3
		GOTO		Gear_TAB4
		GOTO		Gear_TAB5
		GOTO		Gear_TAB6
		GOTO		Gear_TAB7
		GOTO		Gear_TAB8
		GOTO		Gear_TAB9
		
Gear_TAB0:
		BSET		IOB,0
		BSET		IOB,2
		BSET		IOB,1
		BSET		IOB,4
		BSET		IOB,5
		BSET		IOD,5
		BSET		IOB,6
		GOTO		MainLoop
Gear_TAB1:
		BSET		IOB,1
		BSET		IOB,4
		RETURN
Gear_TAB2:
		BSET		IOB,0
		BSET		IOB,1
		BSET		IOB,5
		BSET		IOD,5
		BSET		IOD,6
		;RETURN
		GOTO		MainLoop
Gear_TAB3:
		BSET		IOB,0
		BSET		IOB,1
		BSET		IOB,4
		BSET		IOB,5
		BSET		IOD,6
		GOTO		MainLoop
Gear_TAB4:
		BSET		IOB,1
		BSET		IOB,4
		BSET		IOB,6
		BSET		IOD,6
		GOTO		MainLoop
Gear_TAB5:
		BSET		IOB,0
		BSET		IOB,4
		BSET		IOB,5
		BSET		IOB,6
		BSET		IOD,6
		GOTO		MainLoop
Gear_TAB6:
		BSET		IOB,0
		BSET		IOB,4
		BSET		IOB,5
		BSET		IOD,5
		BSET		IOB,6
		BSET		IOD,6
		GOTO		MainLoop
Gear_TAB7:
		BSET		IOB,0
		BSET		IOB,1
		BSET		IOB,4
		GOTO		MainLoop
Gear_TAB8:
		BSET		IOB,0
		BSET		IOB,1
		BSET		IOB,4
		BSET		IOB,5
		BSET		IOD,5
		BSET		IOB,6
		BSET		IOD,6
		GOTO		MainLoop
Gear_TAB9:
		BSET		IOB,0
		BSET		IOB,1
		BSET		IOB,4
		BSET		IOB,6
		BSET		IOD,6
		GOTO		MainLoop
LED_Clrr:
		BCLR		IOB,0		;// F
		BCLR		IOB,1		;// B
		BCLR		IOB,3		;//	E
		BCLR		IOB,4		;// C
		BCLR		IOB,5		;//	G
		BCLR		IOB,6		;//	A
		BCLR		IOD,5		;//	DP
		BCLR		IOD,6		;//	D
		RETURN
		

		
