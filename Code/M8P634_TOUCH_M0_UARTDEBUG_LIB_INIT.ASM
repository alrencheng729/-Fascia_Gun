;*******************(C) COPYRIGHT 2020 Masses-Chip ******************************
;* File Name          : M8P634_Touch_M0_UartDebug_LIB_Init.ASM
;* Author             : MASSES CHIP
;* Version            : V2.08
;* Date               : 2021/12/01
;********************************************************************************
; 
; 
;
;********************************************************************************

 LIST    p=m8P634
#include m8P634.inc
#include M8R_P_MACRO.inc 
#include M8P634_Touch_M0_UartDebug_LIB_Init.INC
	
;================================================================================
#if TKUartDebugLib_DEBUG_MODE_SWITCH
 GLOBAL _TK_TouchUartDebug_Init   
 GLOBAL _TK_Debug_Mode_Uart_SendChar   
 GLOBAL _TK_Debug_Mode_SendWord   
#endif 
;================================================================================ 
 extern _RTkTemp1   
 extern _RTkTemp2

#if (TKUartDebugLib_DEBUG_UART_SELECT==0) 
 extern _RTkTemp9
 extern _RTkTemp10

#define    T1_LOAD_C_Init	(16000000/TKUartDebugLib_BAUDRATE) 
 
#endif	
 
;================================================================================
 
 CODE
 
;================================================================================
#if TKUartDebugLib_DEBUG_MODE_SWITCH

 
_TK_TouchUartDebug_Init:
; Stack:	Level 1
; INPUT:	 
; OUTPUT:	
; OTHER	:	
    MESSG "    串口调试功能：已开启，请调试结束后关闭" 

#if TKUartDebugLib_DEBUG_UART_SELECT
;tx  PIN PB6
    bset    oeb,6	     ;tx pin out put
    movia   b'10000000'  ; txen 异步 8bit 1:4
    movar   TX0CR	
	
    movia   high(16000000/4/TKUartDebugLib_BAUDRATE-1)
    movar   BRGDH	
    movia   low(16000000/4/TKUartDebugLib_BAUDRATE-1)  ; 16M(fosc)/4/(0x03+1) = 1M Baudrate = fosc/n/(BRGDH+1) 
    movar   BRGDL
    	
    MESSG "    串口调试端口：使用的是MCU硬件资源，端口只能在PB6上 "
     	
#else	
    BSET    OE_UART_TX,N_UART_TX	     ;tx pin out put
     		
    MOVIA   b'00001000' ; UP FOSC 1:1
    MOVAR   T1CR

    MOVIA   high(T1_LOAD_C_Init)
    MOVAR   TC1PRH
    MOVIA   low(T1_LOAD_C_Init)
    MOVAR   TC1PRL
    
    MESSG "    串口调试端口：使用的是IO软件模拟，端口可根据需求配置，软件串口使用的是定时器TC1，若与其它程序有冲突，请做调整 "	
    		
#endif	

   return
   
#endif	   

;================================================================================
#if TKUartDebugLib_DEBUG_MODE_SWITCH 
_TK_Debug_Mode_Uart_SendChar:
; Stack:	Level 1
; INPUT:	ACC 
; OUTPUT:	
; OTHER	:	
#if TKUartDebugLib_DEBUG_UART_SELECT
    MOVAR   TX0REG
    jbts1   TX0CR,6 
    goto    $-1
#else	
    MOVAR   R_UART_TX_BUF
    CALL    _TASK_UART_DATATX		
#endif	   
    return 
    
#endif	

;================================================================================
#if TKUartDebugLib_DEBUG_MODE_SWITCH 	
_TK_Debug_Mode_SendWord:
; Stack:	Level 1
; INPUT:	RTkTemp1&RTkTemp2 
; OUTPUT:	
; OTHER	:	  
#if TKUartDebugLib_DEBUG_UART_SELECT
    MOV    TX0REG,_RTkTemp2 ;high
    jbts1  INTF0,TXIF
    goto   $-1
	
    MOV    TX0REG,_RTkTemp1	;low
    jbts1  TX0CR,6  
    goto   $-1
#else	
	
    MOV		R_UART_TX_BUF,_RTkTemp2  ;high
	CALL	_TASK_UART_DATATX
	
    MOV    	R_UART_TX_BUF,_RTkTemp1	;low
	CALL	_TASK_UART_DATATX	
#endif		
    return
	
#endif

#if (TKUartDebugLib_DEBUG_MODE_SWITCH&&(TKUartDebugLib_DEBUG_UART_SELECT==0))
;====================================================================
_TASK_UART_DATATX:
	BCLR		bTC1IF
	BSET		bTC1IE
	CLRR		TC1CH
	CLRR		TC1CL
	BSET		T1CR,7
	CLRR		R_UART_TX_CNT

UART_LOOP:
	JBTS0		bTC1IE
	GOTO		UART_LOOP

	BCLR		T1CR,7
	RETURN
	
#endif		
;================================================================================
	
  end
  
;*********************************END OF FILE************************************

	