;******************* (C) COPYRIGHT 2014~2018 MASSES CHIP ************************
; File Name          : M8R_P_MACRO.INC
; Author             : MASSES CHIP
; Version            : V1.01
; Date               : 2018/12/18
;********************************************************************************


;================================================================================
; noexpand
;================================================================================
;MACRO
;================================================================================
MOV             MACRO           REG0,REG1
                MOVR            REG1,A
                MOVAR           REG0
		ENDM
;================================================================================
MOVI            MACRO           REG0,IMM0
                MOVIA           IMM0
                MOVAR           REG0
		ENDM
;================================================================================
ADDIR           MACRO           REG0,IMM0
                MOVIA           IMM0
                ADDAR           REG0,R
		ENDM				
;================================================================================
SUBIR           MACRO           REG0,IMM0
                MOVIA           IMM0
                SUBRA           REG0,R
		ENDM				
;================================================================================
ANDIR           MACRO           REG0,IMM0
                MOVIA           IMM0
                ANDAR           REG0,R
		ENDM
;================================================================================
ORIR            MACRO           REG0,IMM0
                MOVIA           IMM0
                ORAR            REG0,R
		ENDM
;================================================================================
ORRR            MACRO           REG0,REG1
                MOVR            REG1,A 
                ORAR            REG0,R
		ENDM		
;================================================================================
XORIR           MACRO           REG0,IMM0
                MOVIA           IMM0
                XORAR           REG0,R
		ENDM
;================================================================================
CJZ1            MACRO           REG0,ADDRESS	         ; (REG0==0)?ADDRESS,SETP INTO
                MOVR            REG0,A
                JBTS0           STATUS,Z
                GOTO            ADDRESS
		ENDM
;================================================================================
CJNZ1           MACRO           REG0,ADDRESS	         ; (REG0!=0)?ADDRESS,SETP INTO
                MOVR            REG0,A
                JBTS1           STATUS,Z
                GOTO            ADDRESS
		ENDM
;================================================================================
CJZ2            MACRO           REG0,REG1,ADDRESS        ; (REG0==0&&REG1==0)?ADDRESS,SETP INTO
                MOVR            REG0,A
                ORAR            REG1,A
                JBTS0           STATUS,Z
                GOTO            ADDRESS
                ENDM
;================================================================================
CJNZ2           MACRO           REG0,REG1,ADDRESS        ;(REG0!=0||REG1!=0)?ADDRESS,SETP INTO
                MOVR            REG0,A
                ORAR            REG1,A
                JBTS1           STATUS,Z
                GOTO            ADDRESS
		ENDM
;================================================================================
CJZ3            MACRO           REG0,REG1,REG2,ADDRESS	 ; (REG0==0&&REG1==0&&REG2==0)?ADDRESS,SETP INTO
                MOVR            REG0,A
                ORAR            REG1,A
                ORAR            REG2,A
                JBTS0           STATUS,Z
                GOTO            ADDRESS
		ENDM
;================================================================================
CJNZ3           MACRO           REG0,REG1,REG2,ADDRESS ; (REG0=!0||REG1!=0||REG2!=0)?ADDRESS,SETP INTO
                MOVR            REG0,A
                ORAR            REG1,A
                ORAR            REG2,A
                JBTS1           STATUS,Z
                GOTO            ADDRESS
		ENDM
;================================================================================
CJZ4            MACRO           REG0,REG1,REG2,REG3,ADDRESS ; (REG0==0&&REG1==0&&REG2==0&&REG3==0)?ADDRESS,SETP INTO
                MOVR            REG0,A
                ORAR            REG1,A
                ORAR            REG2,A
                ORAR            REG3,A
                JBTS0           STATUS,Z
                GOTO            ADDRESS
		ENDM
;================================================================================
CJNZ4           MACRO           REG0,REG1,REG2,REG3,ADDRESS ; (REG0==0||REG1==0||REG2==0||REG3==0)?ADDRESS,SETP INTO
                MOVR            REG0,A
                ORAR            REG1,A
                ORAR            REG2,A
                ORAR            REG3,A
                JBTS1           STATUS,Z
                GOTO            ADDRESS
		ENDM
;================================================================================
CJE1            MACRO           REG0,IMM0,ADDRESS ; (REG0==IMM0)?ADDRESS,SETP INTO	
                MOVR            REG0,A
				JNCMPAI         IMM0
                GOTO            ADDRESS
		ENDM
;================================================================================
CJNE1           MACRO           REG0,IMM0,ADDRESS ; (REG0!=IMM0)?ADDRESS,SETP INTO
                MOVR            REG0,A
				JCMPAI          IMM0								
                GOTO            ADDRESS
		ENDM
;================================================================================
CJE2            MACRO           REG0,REG1,IMM0,IMM1,ADDRESS ; (REG0==IMM0&&REG1==IMM1)?ADDRESS,SETP INTO
                MOVR            REG0,A
                JCMPAI          IMM0				
				GOTO            $+4
                MOVR            REG1,A
                JNCMPAI          IMM1				
                GOTO            ADDRESS
		ENDM
;================================================================================
CJNE2           MACRO           REG0,REG1,IMM0,IMM1,ADDRESS ; (REG0!=IMM0||REG1!=IMM1)?ADDRESS,SETP INTO		
                MOVR            REG0,A
                JCMPAI          IMM0				
				GOTO            ADDRESS				
                MOVR            REG1,A
                JCMPAI          IMM1				
                GOTO            ADDRESS
		ENDM
;================================================================================
CJS1            MACRO           REG0,IMM0,ADDRESS  ; (REG0<IMM0)?ADDRESS,SETP INTO
                MOVIA           IMM0
                SUBRA           REG0,A
                JBTS1           STATUS,C
                GOTO            ADDRESS
		ENDM
;================================================================================
CJB1            MACRO           REG0,IMM0,ADDRESS ; (REG0>=IMM0)?ADDRESS,SETP INTO
                MOVIA           IMM0
                SUBRA           REG0,A
                JBTS0           STATUS,C
                GOTO            ADDRESS
		ENDM
;================================================================================
CPE1            MACRO           REG0,REG1,ADDRESS ;(REG0==REG1)?ADDRESS,SETP INTO
                MOVR            REG1,A
				JNCMPAR         REG0
                GOTO            ADDRESS
		ENDM
;================================================================================
CPNE1           MACRO           REG0,REG1,ADDRESS ;(REG0!=REG1)?ADDRESS,SETP INTO
                MOVR            REG1,A
				JCMPAR          REG0
                GOTO            ADDRESS
		ENDM

;================================================================================
CPGRR1           MACRO          REG0,REG1,ADDRESS ;(REG0>REG1)?ADDRESS,SETP INTO
                 MOVR           REG1,A
                 JGAR           REG0
                 GOTO           ADDRESS
		ENDM

;================================================================================
CPLRR1           MACRO          REG0,REG1,ADDRESS ;(REG0<=REG1)?ADDRESS,SETP INTO
                 MOVR           REG1,A
                 JLAR           REG0
                 GOTO           ADDRESS
		ENDM

;================================================================================
CPGRI1           MACRO          REG0,IMM0,ADDRESS ;(REG0>IMM0)?ADDRESS,SETP INTO
                 MOVIA           IMM0
                 JGAR           REG0
                 GOTO           ADDRESS
		ENDM

;================================================================================
CPLRI1           MACRO          REG0,IMM0,ADDRESS ;(REG0<=IMM0)?ADDRESS,SETP INTO
                 MOVIA          IMM0
                 JLAR           REG0
                 GOTO           ADDRESS
		ENDM		
;================================================================================	
CP_R16R16	MACRO	REG0H,REG0L,REG1H,REG1L,ADDRESS	;(REG0H:REG0L<REG1H:REG1L)?ADDRESS,SETP INTO
	MOVR	REG1H,A
	SUBRA	REG0H,A
	JBTS1	STATUS,C
	GOTO	ADDRESS
	JBTS1	STATUS,Z
	GOTO	$+5
	MOVR	REG1L,A
	SUBRA	REG0L,A
	JBTS1	STATUS,C
	GOTO	ADDRESS
	ENDM
;================================================================================
CP_R16J16 MACRO REGH,REGL,IMMH,IMML,ADDRESS ;(REGH:REGL<IMMH:IMML)?ADDRESS,SETP INTO	
	MOVIA	IMMH
	SUBRA	REGH,A
	JBTS1	STATUS,C
	GOTO	ADDRESS
	JBTS1	STATUS,Z
	GOTO	$+5
	MOVIA	IMML
	SUBRA	REGL,A
	JBTS1	STATUS,C
	GOTO	ADDRESS
	ENDM
;*********************************END OF FILE************************************
;*******************(C) COPYRIGHT 2018 Masses-Chip ******************************	
							