;// Battery_1 = (3*Battery_1 + 7*Battery_New)/10
Battery_Smooth:
	
		MOVIA	2
		JLAR	Battery_Count
		GOTO	Battery_Count1
		
		MOVIA	5
		JLAR	Battery_Count
		GOTO	Battery_Count2
		
		MOVIA	9
		JLAR	Battery_Count
		GOTO	Battery_Count3
		CLRR	Battery_Count
		
		MOVR	Battery_2_L,0
		MOVAR	Battery_1_L
		MOVR	Battery_2_H,0
		MOVAR	Battery_1_H
		CLRR	Battery_2_L
		CLRR	Battery_2_H
		
		RETURN
		
Battery_Count1:
		INCR	Battery_Count,1
		MOVR	Battery_New1,0
		ADDAR	Battery_2_L,1
		MOVIA	0
		ADCAR	Battery_2_H,1
		CLRR	STATUS
		GOTO	Battery_Smooth
		
Battery_Count2:
		INCR	Battery_Count,1
		MOVR	Battery_New2,0
		ADDAR	Battery_2_L,1
		MOVIA	0
		ADCAR	Battery_2_H,1
		CLRR	STATUS
		GOTO	Battery_Smooth
		
Battery_Count3:
		INCR	Battery_Count,1
		MOVR	Battery_New3,0
		ADDAR	Battery_2_L,1
		MOVIA	0
		ADCAR	Battery_2_H,1
		CLRR	STATUS
		GOTO	Battery_Smooth