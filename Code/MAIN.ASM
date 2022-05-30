;*******************(C) COPYRIGHT 2021 Masses-Chip ******************************
;* File Name          : MAIN.ASM
;* Author             : MASSES CHIP
;* Version            : V2.08
;* Date               : 2021/12/01
;********************************************************************************
; 
; 16M/4T, WDT EN 72MS, RST IS IO ,BOR 2.4V,RST TIMER 18MS
;
;********************************************************************************
  
	 LIST P= M8P634

;================================================================================  
#include     m8P634.inc   
#include     M8R_P_MACRO.inc 

;================================================================================  
#include     M8P634_Touch_M0_Lib.inc
#include     M8P634_Touch_M0_Lib_CFG.inc 
#include     M8P634_Touch_M0_Lib_Data.inc 
#include     M8P634_Touch_M0_UartDebug_LIB_Init.inc


;================================================================================  
 CODE 
;================================================================================  
userdata  udata 

#define bT_125US_F    		R_Time_Flag,0
#define	bT_500US_F    		R_Time_Flag,1
#define	bT_10MS_F     		R_Time_Flag,2

#define	bLED_H_F			R_Time_Flag,3

LED_F						RES    1
Special_F					RES	   1
R_Time_Flag                 RES    1
bT_500US_Count				RES	   1
bT_500US_Count_1			RES	   1
bT_125US_Count_2			RES	   1
bT_125US_Count				RES	   1
bT_125US_Count_1			RES	   1
Charge_ADC_H     			RES    1
Charge_ADC_L				RES	   1
Work_ADC_H					RES    1
Work_ADC_L					RES    1
Work_ADC_H_1				RES    1
Work_ADC_L_1				RES    1
R_Count						RES    1
R_ADC_max_L					RES    1
R_ADC_max_H					RES    1
R_ADC_min_L					RES    1
R_ADC_min_H					RES    1
R_ADC_sum_L					RES    1
R_ADC_sum_H					RES    1

ADC_Count					RES	   1

PWM_Work					RES	   1
Battery						RES	   1
Battery_Charge				RES	   1
Battery_1					RES	   1
Battery_Count				RES	   1
Battery_N					RES	   1
Battery_1_H					RES	   1
Battery_1_L					RES	   1
Battery_2_H					RES	   1
Battery_2_L					RES	   1
Battery_H					RES    1
Battery_L					RES    1
Battery_New1				RES	   1
Battery_New2				RES	   1
Battery_New3				RES	   1
Gear_1						RES	   1
Gear_2						RES	   1
Gear_H						RES	   1
Gear_L						RES	   1
Delay						RES	   1
Gear						RES	   1
Switch_F					RES	   1
Battery_F					RES	   1
R_500US_COUNT               RES    1
R_10MS_COUNT                RES    1
ADC_Time_Count				RES	   1

R_GOTOLOWPOWERMODE_COUNT    RES    1

PWM_Count					RES	   1
 

OldKey    RES    1
#define 	F_TK5_On_1    		OldKey,0
#define		F_TK6_On_1			OldKey,1
#define		F_TK7_On_1			OldKey,2


;====================================================================   
; T0 BASE TIME  SET
#define	T0_125_US                     125   ;125US(1 TIMER0 CLOCK) < T0_BASE_MS <4.096MS
#define T0_LOAD_C_Init	              T0_125_US*16000000/1000000 ; FOSC 1:1

#define T_500US_C_Init_DF             D'4'
#define T_10MS_C_Init_DF              D'20'
#define T_GOTOLOWPOWERMODE_C_Init_DF  D'250'  ;无触摸下超时休眠检测次数，无触摸下超时休眠时间 = 次数*触摸通道检测数*0.5ms

;====================================================================                   
    org     .0          
    GOTO    MainProgram
           
    org     .8
ISR_Handle:
    push

T0_ISR:
    jbts0   bTC0IE
    GOTO    ISR_T0_Handle
	
T1_ISR:	
#if (TKUartDebugLib_DEBUG_MODE_SWITCH&&(TKUartDebugLib_DEBUG_UART_SELECT==0)) 	
    jbts0   bTC1IE
    GOTO    ISR_UART_TX_ACT
;    GOTO    ISR_Handle_END
#endif

ISR_Handle_END:
    pop
    retie  
     
;====================================================================   
ISR_T0_Handle:
    jbts1   bTC0IF
    GOTO    T1_ISR
    BSET    bT_125US_F
	
    DJZR    R_500US_COUNT,R
    GOTO    ISR_T0_Handle_END
    MOVI    R_500US_COUNT,T_500US_C_Init_DF
    BSET    bT_500US_F

TK_BASETIMER:
;触摸库需要的时基，不可删除，但可以调整位置，即只需要产生下列时基即可
;校准基准时基
    INCR    RTK_CaliBaseTime_Cnt,R
    MOVIA   (TKLib_CaliBaseTime-1)
    JLAR    RTK_CaliBaseTime_Cnt    
    GOTO    TK_BASETIMER_END
    CLRR    RTK_CaliBaseTime_Cnt
    BSET    bT_TK_CBT_F   ;必须定时产生此标志

;长按长按保护检测基准时基 
    INCR    RTK_LongKeyBaseTime_Cnt,R
    MOVIA   (TKLib_LongKeyBaseTime-1)
    JLAR    RTK_LongKeyBaseTime_Cnt    
    GOTO    TK_BASETIMER_END
    CLRR    RTK_LongKeyBaseTime_Cnt
    BSET    bT_TK_LBT_F   ;若开启长按保护，必须定时产生此标志

TK_BASETIMER_END:

ISR_T0_Handle_1:
    DJZR    R_10MS_COUNT,R
    GOTO    ISR_T0_Handle_END
    MOVI    R_10MS_COUNT,T_10MS_C_Init_DF
    BSET    bT_10MS_F
	
ISR_T0_Handle_END:
    BCLR    bTC0IF
    GOTO    ISR_Handle_END

;====================================================================   
#if (TKUartDebugLib_DEBUG_MODE_SWITCH&&(TKUartDebugLib_DEBUG_UART_SELECT==0)) 		
ISR_UART_TX_ACT:
    MOVR    R_UART_TX_CNT,A
    JBTS1   STATUS,Z
    GOTO    ISR_UART_TX_BODY
IST_UART_TX_START:
    BCLR    P_UART_TX,N_UART_TX
    GOTO    ISR_UART_TX_START_EXIT

ISR_UART_TX_BODY:
    JCMPAI  9
    GOTO    ISR_UART_TX_DATA
IST_UART_TX_END:
    BSET    P_UART_TX,N_UART_TX
    BCLR    bTC1IE
    GOTO    ISR_UART_TX_EXIT
	
ISR_UART_TX_DATA:
    JBTS0   R_UART_TX_BUF,0
    BSET    P_UART_TX,N_UART_TX
    JBTS1   R_UART_TX_BUF,0
    BCLR    P_UART_TX,N_UART_TX

ISR_UART_TX_DATA_EXIT:
    RRR     R_UART_TX_BUF,R	
ISR_UART_TX_START_EXIT:
    INCR    R_UART_TX_CNT,R
    GOTO    ISR_UART_TX_EXIT
;;----------------------------------
ISR_UART_TX_EXIT:
    BCLR    bTC1IF
    GOTO    ISR_Handle_END	
#endif	
	
;==================================================================== 
MainProgram:
    call    Init
    
	;通电点亮LED
	CLRR	Switch_F
	BSET	IOA,4
	MOVIA	1
	MOVAR	Gear
	
MainLoop:
	
	JBTS1	Switch_F,0
	BCLR	PWM2CR,7
    CALL    _TkScan          ;主循环一直扫描，故主循环间隔不宜过长以免影响响应时间
    JBTS1   bOneScanDone     ;查询一轮是否转换结束  
    GOTO    MainLoop_1
	

#if TKUartDebugLib_DEBUG_MODE_SWITCH 
#if(TKUartDebugLib_DEBUG_UART_SELECT==0)
    BCLR    bTC0IE	
#endif
	
    call    _TK_TouchUartDebug
	
#if(TKUartDebugLib_DEBUG_UART_SELECT==0)	
    BSET    bTC0IE	
#endif	
#endif	
	
    call    _TkSignalHandle 
    BCLR    bOneScanDone     ;一轮转换完成,清除标志
	;//10ms
 

	JBTS0	F_TK5_On
	GOTO	TT_3
	BCLR	F_TK5_On_1	
F_TK5_End:
	JBTS0	F_TK6_On
	GOTO	TT_1
	BCLR	F_TK6_On_1
F_TK6_End:
	JBTS0	F_TK7_On
	GOTO	TT_2
	BCLR	F_TK7_On_1
F_TK7_End:	
; 按键响应
    CJZ2 _RKeyOnFlgL,_RKeyOnFlgH,ALLKEY_UP_Handle  ;检查是否有按键被按下
    MOVI R_GOTOLOWPOWERMODE_COUNT,T_GOTOLOWPOWERMODE_C_Init_DF
	

	GOTO	ALLKEY_UP_Handle_end
	
TT_1:
	;//加档
	jbts1   F_TK6_On
	goto	F_TK6_Off
	jbts0	F_TK6_On_1
	goto	F_TK6_End
	GOTO	Gear_Add

TT_2:
	;//减档
	jbts1   F_TK7_On
	goto	F_TK7_Off
	jbts0	F_TK7_On_1
	goto	F_TK7_End
	GOTO	Gear_Sub

TT_3:
	;//开关
	jbts1   F_TK5_On
	goto	F_TK5_Off
	jbts0	F_TK5_On_1
	goto	F_TK5_End	
	JBTS1	Switch_F,0
	GOTO	S_1
	GOTO	S_2
	
S_1:
	BSET	Switch_F,0	
	MOVIA	1
	MOVAR	Gear
	GOTO	TT_5
S_2:
	BCLR	Switch_F,0
	MOVIA	1
	MOVAR	Gear
	GOTO	TT_5

TT_5:
	bset	F_TK5_On_1
	goto	F_TK5_End
	
TT_6:
	bset	F_TK6_On_1
	goto	F_TK6_End
	
TT_7:
	bset	F_TK7_On_1
	goto	F_TK7_End

Gear_Sub:
	MOVIA	1
	JCMPAR	Gear
	DECR	Gear,1
	GOTO	TT_7

Gear_Add:
	MOVIA	20
	JCMPAR	Gear
	INCR	Gear,1
	GOTO	TT_6
	
F_TK5_Off:
	bclr	F_TK5_On_1
	GOTO	F_TK5_End
F_TK6_Off:
	bclr	F_TK6_On_1
	GOTO	F_TK6_End
F_TK7_Off:
	bclr	F_TK7_On_1
	GOTO	F_TK7_End




    goto    ALLKEY_UP_Handle_end
    	
ALLKEY_UP_Handle:
    DJZR    R_GOTOLOWPOWERMODE_COUNT,R
    GOTO    ALLKEY_UP_Handle_end
    MOVI    R_GOTOLOWPOWERMODE_COUNT,T_GOTOLOWPOWERMODE_C_Init_DF
	
	clrr	OldKey

	
#if TKLib_TouchLowerPower 
    BSET    bLowPowerModeRun	
#endif 

ALLKEY_UP_Handle_end:

#if TKLib_TouchLowerPower 
    JBTS1   bLowPowerModeRun 
    goto    Next_OneScan

;下面加睡眠前其它需要低功耗处理的操作(除触摸外的，触摸相关的_TkLowPowerMode会自行处理)	
;如低功耗模式下端口处理，外设模块等
;WDT 与 CPU 工作模式 用户不需要处理





    BCLR    INTCR0,TC0IE   ;关闭其他唤醒源，本demo code外部只打开了T0，固只关闭T0
;触摸低功耗模式	
    call    _TkLowPowerMode

;下面加唤醒后其它需要恢复的操作		
    BSET    INTCR0,TC0IE
	



	
#endif 

Next_OneScan:
    CALL    _ScanContinue
	
	
; 其它主循环程序
MainLoop_1:
	CLRWDT
	
	;JBTS1	Switch_F,0
	;CALL 	LED_Clrr
	
	;BSET		Switch_F,3
	
	CLRR	Gear_H
	CLRR	Gear_L
	CLRR	Battery_H
	CLRR	Battery_L
	
	CALL	Charge_ADC_Work
	
	
	
	;JBTS1	Switch_F,5
	CALL	ADC_Work

	
	CALL	PWM_ADC
	
	

	
	;//显示电量
	CALL	Battery_Set
	MOVIA	10
	JNCMPAR	Battery
	BSET	Battery_F,5
	
	;//充电显示
	JBTS0	Switch_F,3
	GOTO	Charge_Program
	
	
	JBTS1	Battery_F,7
	CALL	Battery_Int
	CALL	Battery_Filter1
	
	JBTS0	Battery_F,6
	CALL	Battery_Filter
	
	

	
	JBTS1	Switch_F,1
	CALL 	Battery_LED
	
	MOVR	Battery_New2,0
	MOVAR	Battery_1
	
	;//显示档位
	;//Gear
	MOVR	Gear,0
	MOVAR	Gear_2

	
	;//Switch_F,1 == 1
	JBTS0	Switch_F,1
	CALL	Gear_LED
	
	
	JBTS0	Switch_F,0
	GOTO	MainLoop_2
	BCLR	Switch_F,2
	GOTO	MainLoop

Charge_Program:
	CALL	Charge_Set
	JBTS1	Switch_F,4
	CALL	Charge_LED
	JBTS0	Switch_F,4
	CALL	Charge_Gear_LED
	MOVR	Battery_New2,0
	MOVAR	Battery_1
	GOTO	MainLoop
	
COM_Clrr:

	BSET	IOB,7
	BSET	IOC,3
	BSET	IOA,3
	BSET	IOA,2
	RETURN
	
LED_OFF:
	CLRR	bT_500US_Count
	CALL	COM_Clrr
	CALL	LED_Clrr
	BSET	bT_500US_F
	RETURN
	
Battery_LED_Switch:
	;BCLR			Switch_F,5
	CALL	LED_OFF
	BSET	Switch_F,1
	BSET	Switch_F,4
	CLRR	bT_125US_Count
	GOTO	MainLoop
Gear_LED_Switch:
	BCLR			Switch_F,5
	CALL	LED_OFF
	BCLR	Switch_F,1
	BCLR	Switch_F,4
	CLRR	bT_125US_Count
	GOTO	MainLoop
Battery_Int:
	BSET	Battery_F,7
	MOVR	Battery,0
	MOVAR	Battery_1
	MOVAR	Battery_New2
	RETURN

MainLoop_2:

	JBTS0	Battery_F,5
	GOTO	MainLoop
	;//PWM
	BSET	Switch_F,2
	
	CALL	PWM_Set
	MOVAR	PWM2DL
	JBTS1	PWM_Work,0
	CALL	PWM_On
	
	
    GOTO    MainLoop 
	

 
;====================================================================                                                 
init: 
; Stack:	Level 5
IO_init:
;触摸口建议设置成输出模式。如输出全0或全1 
    movia   b'11111111'  ;1：output  0：input
    movar   oea
	movia	b'11111101'
    movar   ioa
    movia   b'11111111'  ;1：output  0：input
    movar   oeb
    movar   iob   
    movia   b'11111111'  ;1：output  0：input
    movar   oec
    movar    ioc
    movia   b'11111111'  ;1：output  0：input
    movar   oed
    clrr    iod
    
RAM_INIT:	
ClrRam:        
    clrr    fsr0     ;0x00
ClrRam_loop:
    clrr    indf0
    incr    fsr0,r
    movr    fsr0,a
    jcmpai  low(0xff+1)   ;0xff (clr ram addar +1)
    goto    ClrRam_loop
ClrRam_end:	

; RAM 数据赋值
    MOVI    R_500US_COUNT,T_500US_C_Init_DF
    MOVI    R_10MS_COUNT,T_10MS_C_Init_DF	
    MOVI    R_GOTOLOWPOWERMODE_COUNT,T_GOTOLOWPOWERMODE_C_Init_DF	
RAM_INIT_END:

TKM0_INIT:
#if TKUartDebugLib_DEBUG_MODE_SWITCH 
    call    _TK_TouchUartDebug_Init
#endif

;AD   
    movia   b'00001110'  ; adc ch = gnd
    movar   adcon0   
  
    bset    adcon1,0    ; CDC VREF  ;调用TkInit此程序前，必须打开ADC模块2V/3V/4V之任一参考电源
;    bset    adcon1,1   ; CDC VREF  
  
;TK  
    call    _TkInit

TKM0_INIT_END:
	
T0_INIT:
    CLRR    TC0CH
    CLRR    TC0CL
	
    MOVIA   high(T0_LOAD_C_Init)
    MOVAR   TC0PRH
    MOVIA   low(T0_LOAD_C_Init)
    MOVAR   TC0PRL
	
    MOVIA   b'10001000' ;UP FOSC 1:1
    MOVAR   T0CR
    BSET    bTC0IE
	
T0_INIT_END:	

;ENALBE gie	
    bset    option,gie	
	
    return 

#include	 ADC.inc

#include	 ADC1.inc

#include	 ADC_PWMWork.inc

#include	 Battery_Filter.inc

#include	 Battery_Filter1.inc

#include 	 Battery_LED.inc

#include	 Charge_LED.inc

#include 	 Battery.inc

;#include	 Battery_Smooth.inc

#include	 Gear_LED.inc

#include	 PWM_Work.inc

#include	 PWM_Set.inc
;====================================================================           
     END 
	 
;*********************************END OF FILE************************************
                                 
