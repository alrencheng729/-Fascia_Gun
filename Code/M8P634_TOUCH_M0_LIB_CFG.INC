;*******************(C) COPYRIGHT 2021 Masses-Chip ******************************
;* File Name          : M8P634_Touch_M0_Lib_CFG.INC
;* Author             : MASSES CHIP
;* Version            : V2.08
;* Date               : 2021/12/01
;********************************************************************************

;================================================================================
#ifndef __M8P634_Touch_M0_Lib_CFG_INC__
#define __M8P634_Touch_M0_Lib_CFG_INC__

;================================================================================
; 触摸正常模式设定
;================================================================================
; 设置CDC模块0需要检测的通道  0: 该通道按键不检测；1: 该通道按键需检测。
#define EnTk0    0
#define EnTk1    0
#define EnTk2    0
#define EnTk3    0
#define EnTk4    0
#define EnTk5    1
#define EnTk6    0
#define EnTk7    0
#define EnTk8    0
#define EnTk9    0
#define EnTk10   0
#define EnTk11   0
#define EnTk12   0
#define EnTk13   0
#define EnTk14   0
#define EnTk15   0


; 设置确认允许响应的最多按键数量     (1 <= value <= TKLib_M0_OPENED_TK_AMOUNT)
#define TKLib_TOUCH_NUM               1

; 设置触摸消抖次数                   (1 <= value <= 255) 
                                      ;消抖时间 = TKLib_Debounce_TIME * BASE_TIME * TKLib_M0_OPENED_TK_AMOUNT，
                                      ;其中BASE_TIME 为 TkScan 调用间隔,其中本例程BASE_TIME为1MS；TKLib_M0_OPENED_TK_AMOUNT为开启的按键数量
#define TKLib_Debounce_TIME           5    

; 设置手指触摸最长有效时间           (0<= value <=15) ; 0: 屏蔽此功能；1: 禁止配置；2~15：时间 = value*长按保护检测基准时基
#define TKLib_LONG_TOUCH_TIME         15

; 设置向上自动校准速度               (1<= value <=7) ; 值越小，校准越快
; 如手指先触摸后上电，一开始不能按，需等待一段时间才能按，若想调节等待时间，可修改此部分
#define TKLib_Up_Calibration_Rate     4

; 设置向下自动校准速度               (1<= value <=7) ; 值越小，校准越快
; 手指慢慢靠近触摸，系统会强制校准保护，若想调节靠近保护时间，可修改此部分
; 若调节此处还不能达到你想要的效果，可修改后面的TKLib_CaliBaseTime 
#define TKLib_Down_Calibration_Rate   4

; 设置CDC时钟分频选择位               0->Fosc/4, 1->Fosc/8, 2->Fosc/16, 3->Fosc/32 ; 一般不需要修改
#define TKLib_M0_TKCKS                1

; 设置手指有效触摸检测次数           (1<= value <=15) ; 一般不需要修改
#define TKLib_EFFECTIVE_TOUCH_TIME    3

; 设置手指无效触摸检测次数           (1<= value <=15) ; 一般不需要修改
#define TKLib_INVALID_TOUCH_TIME      2

; 设置触摸采样滤波等级               (0<= value <=2) ; 一般不需要修改; 0->无,1->中,2->高
#define TKLib_FILTER_LEVEL            1

; 设置抗干扰加强是否开启     
; 									                  0->不开启, 1->开启
;                                     只在电荷转移模式且滤波等级在中或高时才有效，
;                                     低功耗模式开启下无效
;                                     振荡模式下无效及低功耗模式下也无效    
#define TKLib_STRENGTHEN              1

; 设置当被响应按键超过允许响应的最多按键数量时，是否需要复位触摸      
; 									                  0->不复位触摸系统, 1->复位触摸系统 ; 一般不需要修改
#define TKLib_Multi_TOUCH_RST         0

; 设置校准基准时基                   (1<= value <=254) ; 可根据时基需求调整
; 校准基准时基  = TKLib_CaliBaseTime * 调用时基，调用时基 Demo code 为0.5ms，可根据时基需求修改
#define TKLib_CaliBaseTime            200    

; 设置长按保护检测基准时基           (1<= value <=254) ; 可根据时基需求调整
; 长按保护检测基准时基 = TKLib_LongKeyBaseTime * 校准基准时基，Democode为校准基准时基产生后计数，可根据时基需求修改
#define TKLib_LongKeyBaseTime         10

;================================================================================
; 触摸阈值： 取值需具体应用环境决定，最小9，最大255，值越小越灵敏
#define TKLib_TK0_F_THRESHOLD         15       
#define TKLib_TK1_F_THRESHOLD         15
#define TKLib_TK2_F_THRESHOLD         15
#define TKLib_TK3_F_THRESHOLD         15 
#define TKLib_TK4_F_THRESHOLD         15 
#define TKLib_TK5_F_THRESHOLD         12;9 
#define TKLib_TK6_F_THRESHOLD         12;9
#define TKLib_TK7_F_THRESHOLD         12;9
#define TKLib_TK8_F_THRESHOLD         15       
#define TKLib_TK9_F_THRESHOLD         15 
#define TKLib_TK10_F_THRESHOLD        15 
#define TKLib_TK11_F_THRESHOLD        15 
#define TKLib_TK12_F_THRESHOLD        15 
#define TKLib_TK13_F_THRESHOLD        15 
#define TKLib_TK14_F_THRESHOLD        15 
#define TKLib_TK15_F_THRESHOLD        15 

;================================================================================
; 触摸省电模式设定，一般运用请关闭此模式
;================================================================================
; 设置触摸低功耗模式是否开启  0: 不使用触摸省电模式；1: 使用触摸省电模式。
#define TKLib_TouchLowerPower         0

; 设置CDC模块0需要检测的通道  0: 该通道按键不检测；1: 该通道按键需检测。
#define TKLPGroup0                    1
#define TKLPGroup1                    0
#define TKLPGroup2                    0

;================================================================================
; 低功耗下触摸通道分组设置， 数据 = {tk0chsh:tk0chsl}，若触摸按键较多时，建议分组检测
; 分组原则要求需要检测的组通道数应相同，减少不同组之间的检测差异，若实际产品tk0~tk6为开启检测的通道
; 例：若分2组，7/2 = 3余1，则建议4个一组 ,即一组TKLib_M0_TKLPGroup0_MASK = 0x000F; 另一组TKLib_M0_TKLPGroup0_MASK = 0x0078
#define TKLib_M0_TKLPGroup0_MASK    0x0007       
#define TKLib_M0_TKLPGroup1_MASK    0x0038 
#define TKLib_M0_TKLPGroup2_MASK    0x003F
 
;================================================================================
; 触摸阈值： 取值需具体应用环境决定，最小3，最大255，值越小越灵敏
#define TKLib_Sleep_F_THRESHOLD     5      
 
;================================================================================ 
; 触摸低功耗模式下辅助端口是否使能   0：不使用辅助端口；1：使用辅助端口
; 此端口用来调整触摸低功耗模式下触摸检测灵敏度，可接电阻或接电容，具体接法请查看触摸低功耗电路设计参考原理图
; 如每组分配的通道数较多时，低功耗下触摸检测灵敏度会较低，此时可以考虑辅助端口来调节低功耗模式下触摸检测灵敏度
#define TKLPLib_RCOUT_EN            0

; 触摸低功耗模式下，辅助端口选择
#if TKLPLib_RCOUT_EN
	
#define OE_RCOUT    OEC    ; 对应端口方向寄存器
#define P_RCOUT     IOC    ; 对应端口数据寄存器
#define N_RCOUT     4      ; 对应端口编号 
 
#endif 
 
; 以下用户不可修改
;================================================================================
#define TKLib_M0_OPENED_TK_AMOUNT (EnTk0+EnTk1+EnTk2+EnTk3+EnTk4+EnTk5+EnTk6+EnTk7+EnTk8+EnTk9+EnTk10+EnTk11+EnTk12+EnTk13+EnTk14+EnTk15)
#define TKLib_M0_TK_EN_MASK       ((EnTk0<<0)|(EnTk1<<1)|(EnTk2<<2)|(EnTk3<<3)|(EnTk4<<4)|(EnTk5<<5)|(EnTk6<<6)|(EnTk7<<7)|(EnTk8<<8)|(EnTk9<<9)|(EnTk10<<10)|(EnTk11<<11)|(EnTk12<<12)|(EnTk13<<13)|(EnTk14<<14)|(EnTk15<<15))             

;================================================================================
#define TKLib_M0_LP_OPENEDGROUP_AMOUNT   (TKLPGroup0+TKLPGroup1+TKLPGroup2)
#define TKLib_M0_LP_TKLPGROUP_MASK       ((TKLPGroup0<<0)|(TKLPGroup1<<1)|(TKLPGroup2<<2))             

;================================================================================

#endif

;*********************************END OF FILE************************************
