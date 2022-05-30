;*******************(C) COPYRIGHT 2021 Masses-Chip ******************************
;* File Name          : M8P634_Touch_M0_Lib.INC
;* Author             : MASSES CHIP
;* Version            : V2.08
;* Date               : 2021/12/01
;********************************************************************************

; 注意，触摸库中有用到间接寻址寄存器(FSR0,FSR1,HBUF)，若客户在中断中有使用，
;       请用户进入中断后先备份(push指令后备份)此3个寄存器，出中断后再恢复(pop指令前恢复)。

;================================================================================ 
#ifndef __M8P634_Touch_M0_Lib_INC__
#define __M8P634_Touch_M0_Lib_INC__
;================================================================================ 
 extern _TkInit                  ; 触摸模块初始化程序，堆栈深度4级，调用此程序前，必须打开ADC模块2V/3V/4V之任一参考电源
 extern _TkScan                  ; 触摸按键扫描程序，堆栈深度3级，必需保证主循环中调用
 extern _TkSignalHandle          ; 触摸数据处理程序，堆栈深度3级，bOneScanDone 被置"1" 后，调用一次
 extern _ScanContinue            ; 触摸扫描启动程序，堆栈深度4级，先调用TkSignalHandle，先清除bOneScanDone，后调用ScanContinue
 extern _BaseLineReset           ; 基线强制复位程序，堆栈深度3级
 
;================================================================================ 
 extern _TkLowPowerMode          ; 触摸模块低功耗程序，堆栈深度3级，要求_ScanContinue程序必须跟随在后面
                                 ; 调用此函数前必须将相关端口设置

;================================================================================ 
 extern _TK_TouchUartDebug_Init  ; 触摸串口调试初始化程序
 extern _TK_TouchUartDebug       ; 触摸串口调试程序，堆栈深度3级
 
;================================================================================  
#define bOneScanDone          _RTkBitFlag,0  ; 触摸扫描一轮完成标志，RTkBitFlag中其它BIT位用户请勿操作
#define bT_TK_CBT_F           _RTkBitFlag,1  ; 触摸更新时基标志
#define bT_TK_LBT_F           _RTkBitFlag,2  ; 长按清除时基标志

#define	bLowPowerModeReset    _RTkBitFlag,6  ; 0: Reset Touch LowPower Mode 1; LowPower Mode Reset complete 
#define	bLowPowerModeRun      _RTkBitFlag,7  ; 0: Normal; 1: LowPower

;================================================================================  
; 用户只读，不可写入操作，切记！ 
#define F_TK0_On     _RKeyOnFlgL,0  ; TK0按键触摸响应标志，1：表示被触摸；0：未被触摸。
#define F_TK1_On     _RKeyOnFlgL,1  ; TK1按键触摸响应标志，1：表示被触摸；0：未被触摸。
#define F_TK2_On     _RKeyOnFlgL,2  ; TK2按键触摸响应标志，1：表示被触摸；0：未被触摸。
#define F_TK3_On     _RKeyOnFlgL,3  ; TK3按键触摸响应标志，1：表示被触摸；0：未被触摸。
#define F_TK4_On     _RKeyOnFlgL,4  ; TK4按键触摸响应标志，1：表示被触摸；0：未被触摸。
#define F_TK5_On     _RKeyOnFlgL,5  ; TK5按键触摸响应标志，1：表示被触摸；0：未被触摸。
#define F_TK6_On     _RKeyOnFlgL,6  ; TK6按键触摸响应标志，1：表示被触摸；0：未被触摸。
#define F_TK7_On     _RKeyOnFlgL,7  ; TK7按键触摸响应标志，1：表示被触摸；0：未被触摸。
#define F_TK8_On     _RKeyOnFlgH,0  ; TK8按键触摸响应标志，1：表示被触摸；0：未被触摸。
#define F_TK9_On     _RKeyOnFlgH,1  ; TK9按键触摸响应标志，1：表示被触摸；0：未被触摸。
#define F_TK10_On    _RKeyOnFlgH,2  ; TK10按键触摸响应标志，1：表示被触摸；0：未被触摸。 
#define F_TK11_On    _RKeyOnFlgH,3  ; TK10按键触摸响应标志，1：表示被触摸；0：未被触摸。 
#define F_TK12_On    _RKeyOnFlgH,4  ; TK10按键触摸响应标志，1：表示被触摸；0：未被触摸。 
#define F_TK13_On    _RKeyOnFlgH,5  ; TK10按键触摸响应标志，1：表示被触摸；0：未被触摸。 
#define F_TK14_On    _RKeyOnFlgH,6  ; TK10按键触摸响应标志，1：表示被触摸；0：未被触摸。 
#define F_TK15_On    _RKeyOnFlgH,7  ; TK10按键触摸响应标志，1：表示被触摸；0：未被触摸。 

;================================================================================  
#define RTK_CaliBaseTime_Cnt           _RTkBuff4  
#define RTK_LongKeyBaseTime_Cnt        _RTkBuff5

#endif 
 
;*********************************END OF FILE************************************

