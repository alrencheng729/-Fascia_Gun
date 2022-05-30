;*******************(C) COPYRIGHT 2021 Masses-Chip ******************************
;* File Name          : M8P634_Touch_M0_UartDebug_LIB_Init.INC
;* Author             : MASSES CHIP
;* Version            : V2.08
;* Date               : 2021/12/01
;********************************************************************************

;==================================================================== 
#ifndef __M8P634_Touch_M0_UartDebug_LIB_Init_INC__
#define __M8P634_Touch_M0_UartDebug_LIB_Init_INC__
;==================================================================== 
;触摸串口调试开关  
; 0：禁止编译时加载触摸调试程序，触摸调试完成后，请设为“0”
; 1：允许编译时加载触摸调试程序，此时可以通过触摸调试工具及配套软件获取内部相关数据，方便用户开发时调试触摸参数
#define TKUartDebugLib_DEBUG_MODE_SWITCH    0

;触摸串口方式选择
; 0：软件模拟串口
; 1：MCU硬件串口
#define TKUartDebugLib_DEBUG_UART_SELECT    1

; 触摸串口调试波特率设定，不建议修改，必需修改时，请用户自行确认所设波特率是否正常
; 软件模拟串口时,若Fcpu 速率较低时，若发现通讯不正常，请降低波特率
; MCU硬件串口时，波特率最高可达2M，且与Fcpu无关，但使用高速波特率时，请确认使用的串口工具是否支持
#define TKUartDebugLib_BAUDRATE             1000000

; 软件模拟串口，端口选择
#if (TKUartDebugLib_DEBUG_UART_SELECT==0)
	
#define OE_UART_TX    OEB    ; 对应端口方向寄存器
#define P_UART_TX     IOB    ; 对应端口数据寄存器
#define N_UART_TX     6      ; 对应端口编号


;==================================================================== 
;以下不可修改
#define R_UART_TX_CNT    _RTkTemp9
#define R_UART_TX_BUF    _RTkTemp10

#endif

#endif

;*********************************END OF FILE************************************
                         
