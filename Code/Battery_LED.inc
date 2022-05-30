Battery_LED:
		
		JBTS1		bT_500US_F
		RETURN	
		
		JBTS0		PWM_Work,0
		CALL		E2_Function
		JBTS0		PWM_Work,0
		GOTO		$+10

		JBTS0		Battery_F,5
		CALL		E1_Function
		JBTS0		Battery_F,5
		GOTO		$+6
		
		MOVIA		9
		JGAR		Battery_1
		GOTO		Battery_H_Count
		MOVR		Battery_1,0
		MOVAR		Battery_L
		
		MOVR		Battery_New2,0
		MOVAR		Battery_1
		
		INCR		bT_500US_Count_1,1
		MOVIA		2
		JNCMPAR		bT_500US_Count_1
		CALL		Battery_CountAdd
		MOVIA		3
		JNCMPAR		bT_500US_Count
		GOTO		Battery_LED_Switch
		CALL		COM_Clrr
		CALL		LED_Clrr
		
		MOVR		bT_500US_Count,A
		ADDAR		PCL,R
		GOTO		MainLoop
		GOTO		Battery_LED_H	
		GOTO		Battery_LED_L
Battery_CountAdd:
		INCR		bT_500US_Count,1
		CLRR		bT_500US_Count_1
		RETURN
E1_Function:
		MOVIA		10
		MOVAR		Battery_H
		MOVIA		1
		MOVAR		Battery_L
		RETURN
E2_Function:
		MOVIA		10
		MOVAR		Battery_H
		MOVIA		2
		MOVAR		Battery_L
		RETURN
Battery_H_Count:
		INCR		Battery_H,1
		MOVIA		10
		SUBRA		Battery_1,1
		GOTO		Battery_LED
		

Battery_L_Count:
		INCR		Battery_L,1
		MOVIA		10
		SUBRA		Battery_1_L,1
		MOVIA		0
		SBCRA		Battery_1_H,1
		CLRR		STATUS
		INCR		Battery_New3,1
		GOTO		Battery_LED
		
Battery_LED_H:
		BSET		Switch_F,5
		
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
Battery_LED_L:
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
Battery_TAB0:
		BSET		IOB,6
		BSET		IOB,1
		BSET		IOB,4
		BSET		IOD,6
		BSET		IOB,3
		BSET		IOB,0
		RETURN
Battery_TAB1:
		BSET		IOB,1
		BSET		IOB,4
		RETURN
Battery_TAB2:
		BSET		IOB,6
		BSET		IOB,1
		BSET		IOD,6
		BSET		IOB,3
		BSET		IOB,5
		RETURN
Battery_TAB3:
		BSET		IOB,6
		BSET		IOB,1
		BSET		IOB,4
		BSET		IOD,6
		BSET		IOB,5
		RETURN
Battery_TAB4:
		BSET		IOB,1
		BSET		IOB,4
		BSET		IOB,0
		BSET		IOB,5
		RETURN
Battery_TAB5:
		BSET		IOB,6
		BSET		IOB,4
		BSET		IOD,6
		BSET		IOB,0
		BSET		IOB,5
		RETURN
Battery_TAB6:
		BSET		IOB,6
		BSET		IOB,4
		BSET		IOD,6
		BSET		IOB,3
		BSET		IOB,0
		BSET		IOB,5
		RETURN
Battery_TAB7:
		BSET		IOB,6
		BSET		IOB,1
		BSET		IOB,4
		RETURN
Battery_TAB8:
		BSET		IOB,6
		BSET		IOB,1
		BSET		IOB,4
		BSET		IOD,6
		BSET		IOB,3
		BSET		IOB,0
		BSET		IOB,5
		RETURN
Battery_TAB9:
		BSET		IOB,6
		BSET		IOB,1
		BSET		IOB,4
		BSET		IOB,0
		BSET		IOB,5
		RETURN
Battery_TAB10:
		BSET		IOB,6
		BSET		IOD,6
		BSET		IOB,3
		BSET		IOB,0
		BSET		IOB,5
		RETURN
		
		

