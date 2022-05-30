;*******************(C) COPYRIGHT 2021 Masses-Chip ******************************
;* File Name          : M8P634_Touch_M0_Lib_Data.INC
;* Author             : MASSES CHIP
;* Version            : V2.08
;* Date               : 2021/12/01
;********************************************************************************

; 本文件用户不可自行修改

;================================================================================ 
#include     M8P634_Touch_M0_Lib_CFG.INC 

;================================================================================ 
#define TKLib_TS_FAC             5  ;3~5
  
#define TKLib_TKMODE                  0  
  
;================================================================================ 
;触摸库RAM分配起始地址，不建议修改，或保证修改后有足够地址分配到触摸库使用
; RAM RTKLibGroup0 分配的起始地址 ~ 0xff 被触摸库中使用
#if  (TKLib_FILTER_LEVEL==0)
#undefine   TKLib_STRENGTHEN
#define TKLib_STRENGTHEN              0 
RTKLibGroup0 udata (0xff+1-13-11-2-6*TKLib_M0_OPENED_TK_AMOUNT-2*TKLib_TouchLowerPower*TKLib_M0_LP_OPENEDGROUP_AMOUNT)  
#endif
#if  (TKLib_FILTER_LEVEL==1)
RTKLibGroup0 udata (0xff+1-13-11-8-6*TKLib_M0_OPENED_TK_AMOUNT-2*TKLib_TouchLowerPower*TKLib_M0_LP_OPENEDGROUP_AMOUNT)  
#endif
#if  (TKLib_FILTER_LEVEL==2)
RTKLibGroup0 udata (0xff+1-13-11-16-6*TKLib_M0_OPENED_TK_AMOUNT-2*TKLib_TouchLowerPower*TKLib_M0_LP_OPENEDGROUP_AMOUNT)  
#endif
#if  (TKLib_FILTER_LEVEL>2)
RTKLibGroup0 udata (0xff+1-13-11-16-6*TKLib_M0_OPENED_TK_AMOUNT-2*TKLib_TouchLowerPower*TKLib_M0_LP_OPENEDGROUP_AMOUNT)  
#endif

#if (TKLib_TouchLowerPower==1)
#undefine   TKLib_STRENGTHEN
#define TKLib_STRENGTHEN             0  
#endif 

#if (TKLib_TKMODE == 1)
#undefine   TKLib_STRENGTHEN
#define TKLib_STRENGTHEN             0  
#endif

;================================================================================ 
_RTkTemp0        res        1
_RTkTemp1        res        1 
_RTkTemp2        res        1 
_RTkTemp3        res        1 
_RTkTemp4        res        1 
_RTkTemp5        res        1
_RTkTemp6        res        1          
_RTkTemp7        res        1         
_RTkTemp8        res        1         
_RTkTemp9        res        1        
_RTkTemp10       res        1        
_RTkTemp11       res        1          
_RTkTemp12       res        1  

_RTkBuff0        res        1        
_RTkBuff1        res        1 
_RTkBuff2        res        1        
_RTkBuff3        res        1 
_RTkBuff4        res        1  
_RTkBuff5        res        1 

#if  TKLib_M0_OPENED_TK_AMOUNT
_RTkGBuff0       res        2*TKLib_M0_OPENED_TK_AMOUNT          
_RTkGBuff1       res        2*TKLib_M0_OPENED_TK_AMOUNT         
_RTkGBuff2       res        1*TKLib_M0_OPENED_TK_AMOUNT
_RTkGBuff3       res        1*TKLib_M0_OPENED_TK_AMOUNT
#if  (TKLib_FILTER_LEVEL==0)
_RTkGBuff4       res        2  
#endif
#if  (TKLib_FILTER_LEVEL==1)
_RTkGBuff4       res        8  
#endif
#if  (TKLib_FILTER_LEVEL==2)
_RTkGBuff4       res        16  
#endif
#if  (TKLib_FILTER_LEVEL>2)
_RTkGBuff4       res        16  
#endif  
#endif

#if TKLib_TouchLowerPower 
#if  TKLib_M0_LP_OPENEDGROUP_AMOUNT
_RTkLPGBuff0     res        2*TKLib_M0_LP_OPENEDGROUP_AMOUNT             
#endif
#endif

_RChannelEnL     res        1       
_RChannelEnH     res        1       
_RKeyOnFlgL      res        1        
_RKeyOnFlgH      res        1 
_RTkBitFlag      res        1  

;================================================================================  
; 程序区  ~ 0x0FEF，用户不可使用
;================================================================================ 
#if TKLib_TouchLowerPower
TAB_TOUCH_TKLP_CFG_DATA:
#if (TKLib_STRENGTHEN==0)
 org    (0x0FEF+1-1-12-TKLib_M0_OPENED_TK_AMOUNT-5)
#endif
#if (TKLib_STRENGTHEN==1)
 org    (0x0FEF+1-1-17-TKLib_M0_OPENED_TK_AMOUNT-5)
#endif
 
TAB_TOUCH_TKLP_OPENEDGROUP_MASK:
 RETIA     (TKLib_M0_LP_TKLPGROUP_MASK&0xff)
 
TAB_TOUCH_TKLP_F_THRESHOLD: 
 RETIA     (TKLib_Sleep_F_THRESHOLD&0xff) 
 
TAB_TOUCH_TKLP_MASK_DATA: 
 DW     TKLib_M0_TKLPGroup0_MASK
 DW     TKLib_M0_TKLPGroup1_MASK
 DW     TKLib_M0_TKLPGroup2_MASK 
#endif
 
TAB_TOUCH_CFG_DATA:
#if (TKLib_STRENGTHEN==0)
 org    (0x0FEF+1-1-12-TKLib_M0_OPENED_TK_AMOUNT) 
#endif
#if (TKLib_STRENGTHEN==1)
 org    (0x0FEF+1-1-17-TKLib_M0_OPENED_TK_AMOUNT) 
#endif
             
TAB_TOUCH_TK_EN_MASK_L_DATA:
 RETIA     (TKLib_M0_TK_EN_MASK&0X00FF)
 
TAB_TOUCH_TK_EN_MASK_H_DATA:
 RETIA     (TKLib_M0_TK_EN_MASK>>8)

TAB_TOUCH_OPENED_TK_AMOUNT_DATA: 
 RETIA     (TKLib_M0_OPENED_TK_AMOUNT&0x0F) 

TAB_TOUCH_TKCKS_DATA:
 RETIA     (((TKLib_TKMODE&0x01)<<3)+((TKLib_M0_TKCKS&0x03)<<4))
 
TAB_TOUCH_NUM_DATA:  
 RETIA     (((TKLib_TOUCH_NUM&0x1F)<<0)+((TKLib_STRENGTHEN&0x01)<<6)+((TKLib_Multi_TOUCH_RST&0x01)<<7))

TAB_TOUCH_LONG_TOUCH_TIME_AND_FILTER_LEVEL_DATA:  
 RETIA     ((TKLib_LONG_TOUCH_TIME&0x0F)+((TKLib_FILTER_LEVEL&0x03)<<4))

TAB_TOUCH_CONFIRM_TIME_DATA: 
 RETIA     ((TKLib_EFFECTIVE_TOUCH_TIME&0x0F)+((TKLib_INVALID_TOUCH_TIME&0x0F)<<4))

TAB_TOUCH_Debounce_TIME_DATA: 
 RETIA     (TKLib_Debounce_TIME&0x0FF)

TAB_TOUCH_Down_Calibration_Rate_DATA:
 RETIA     (TKLib_Down_Calibration_Rate&0x07)
 
TAB_TOUCH_Up_Calibration_Rate_DATA:
 RETIA     (TKLib_Up_Calibration_Rate&0x07)

TAB_TOUCH_NOISE1_DATA:
 RETIA      0x05

TAB_TOUCH_NOISE2_DATA:
 RETIA      0xff ;0x07

TAB_TOUCH_OTHER_DATA:
#if TKLib_STRENGTHEN
 DW         0xC3BA
 RETIA      0X90
 RETIA      0X80
 RETIA      0X90
 RETIA      0XA0
#endif

TAB_TOUCH_FN_DATA:
#if EnTk0  
 DW     (((TKLib_TK0_F_THRESHOLD/TKLib_TS_FAC)&0xff)+((TKLib_TK0_F_THRESHOLD&0xff)<<8))
#endif

#if EnTk1 
 DW     (((TKLib_TK1_F_THRESHOLD/TKLib_TS_FAC)&0xff)+((TKLib_TK1_F_THRESHOLD&0xff)<<8))
#endif

#if EnTk2 
 DW     (((TKLib_TK2_F_THRESHOLD/TKLib_TS_FAC)&0xff)+((TKLib_TK2_F_THRESHOLD&0xff)<<8))
#endif

#if EnTk3 
 DW     (((TKLib_TK3_F_THRESHOLD/TKLib_TS_FAC)&0xff)+((TKLib_TK3_F_THRESHOLD&0xff)<<8))
#endif

#if EnTk4 
 DW     (((TKLib_TK4_F_THRESHOLD/TKLib_TS_FAC)&0xff)+((TKLib_TK4_F_THRESHOLD&0xff)<<8))
#endif

#if EnTk5 
 DW     (((TKLib_TK5_F_THRESHOLD/TKLib_TS_FAC)&0xff)+((TKLib_TK5_F_THRESHOLD&0xff)<<8))
#endif

#if EnTk6 
 DW     (((TKLib_TK6_F_THRESHOLD/TKLib_TS_FAC)&0xff)+((TKLib_TK6_F_THRESHOLD&0xff)<<8))
#endif

#if EnTk7 
 DW     (((TKLib_TK7_F_THRESHOLD/TKLib_TS_FAC)&0xff)+((TKLib_TK7_F_THRESHOLD&0xff)<<8))
#endif

#if EnTk8 
 DW     (((TKLib_TK8_F_THRESHOLD/TKLib_TS_FAC)&0xff)+((TKLib_TK8_F_THRESHOLD&0xff)<<8))
#endif

#if EnTk9 
 DW     (((TKLib_TK9_F_THRESHOLD/TKLib_TS_FAC)&0xff)+((TKLib_TK9_F_THRESHOLD&0xff)<<8))
#endif

#if EnTk10 
 DW     (((TKLib_TK10_F_THRESHOLD/TKLib_TS_FAC)&0xff)+((TKLib_TK10_F_THRESHOLD&0xff)<<8))
#endif

#if EnTk11 
 DW     (((TKLib_TK11_F_THRESHOLD/TKLib_TS_FAC)&0xff)+((TKLib_TK11_F_THRESHOLD&0xff)<<8))
#endif

#if EnTk12 
 DW     (((TKLib_TK12_F_THRESHOLD/TKLib_TS_FAC)&0xff)+((TKLib_TK12_F_THRESHOLD&0xff)<<8))
#endif

#if EnTk13 
 DW     (((TKLib_TK13_F_THRESHOLD/TKLib_TS_FAC)&0xff)+((TKLib_TK13_F_THRESHOLD&0xff)<<8))
#endif

#if EnTk14 
 DW     (((TKLib_TK14_F_THRESHOLD/TKLib_TS_FAC)&0xff)+((TKLib_TK14_F_THRESHOLD&0xff)<<8))
#endif

#if EnTk15 
 DW     (((TKLib_TK15_F_THRESHOLD/TKLib_TS_FAC)&0xff)+((TKLib_TK15_F_THRESHOLD&0xff)<<8))
#endif

 DW     (0x0309)
 
;================================================================================         
 ; RAM
 GLOBAL _RTkTemp0   
 GLOBAL _RTkTemp1   
 GLOBAL _RTkTemp2    
 GLOBAL _RTkTemp3   
 GLOBAL _RTkTemp4  
 GLOBAL _RTkTemp5      
 GLOBAL _RTkTemp6    
 GLOBAL _RTkTemp7    
 GLOBAL _RTkTemp8    
 GLOBAL _RTkTemp9    
 GLOBAL _RTkTemp10   
 GLOBAL _RTkTemp11     
 GLOBAL _RTkTemp12 
 
 GLOBAL _RTkBitFlag     
 GLOBAL _RKeyOnFlgL   
 GLOBAL _RKeyOnFlgH   
 GLOBAL _RChannelEnL     
 GLOBAL _RChannelEnH 

 GLOBAL _RTkBuff0     
 GLOBAL _RTkBuff1  
 GLOBAL _RTkBuff2     
 GLOBAL _RTkBuff3 
 GLOBAL _RTkBuff4
 GLOBAL _RTkBuff5  

 GLOBAL _RTkGBuff0     
 GLOBAL _RTkGBuff1    
 GLOBAL _RTkGBuff2     
 GLOBAL _RTkGBuff3 
 GLOBAL _RTkGBuff4 
  
 ; CODE
 GLOBAL TAB_TOUCH_TK_EN_MASK_L_DATA 
 GLOBAL TAB_TOUCH_TK_EN_MASK_H_DATA 
 GLOBAL TAB_TOUCH_OPENED_TK_AMOUNT_DATA           
 GLOBAL TAB_TOUCH_TKCKS_DATA   
 GLOBAL TAB_TOUCH_NUM_DATA
 GLOBAL TAB_TOUCH_LONG_TOUCH_TIME_AND_FILTER_LEVEL_DATA
 GLOBAL TAB_TOUCH_CONFIRM_TIME_DATA 
 GLOBAL TAB_TOUCH_Debounce_TIME_DATA 
 GLOBAL TAB_TOUCH_Down_Calibration_Rate_DATA 
 GLOBAL TAB_TOUCH_Up_Calibration_Rate_DATA   
 GLOBAL TAB_TOUCH_NOISE1_DATA   
 GLOBAL TAB_TOUCH_NOISE2_DATA  
 GLOBAL TAB_TOUCH_OTHER_DATA  
 GLOBAL TAB_TOUCH_FN_DATA 

#if TKLib_TouchLowerPower 
 ; RAM 
 GLOBAL _RTkLPGBuff0     

 ; CODE
 GLOBAL TAB_TOUCH_TKLP_OPENEDGROUP_MASK    
 GLOBAL TAB_TOUCH_TKLP_F_THRESHOLD   
 GLOBAL TAB_TOUCH_TKLP_MASK_DATA 
#endif

;================================================================================
#ifndef __M8P634_Touch_M0_Lib_Build_Message_INC__
#define __M8P634_Touch_M0_Lib_Build_Message_INC__
;================================================================================
;CDC MODE
#if (TKLib_TKMODE > 1)
    Error "    Error: Please setting TKLib_TKMODE ∈ {0,1}  "  
#endif

;================================================================================
#if EnTk0
    MESSG "    TK0: Enable"  
#endif
#if EnTk1
    MESSG "    TK1: Enable"  
#endif
#if EnTk2
    MESSG "    TK2: Enable"  
#endif
#if EnTk3
    MESSG "    TK3: Enable"  
#endif
#if EnTk4
    MESSG "    TK4: Enable"  
#endif
#if EnTk5
    MESSG "    TK5: Enable"  
#endif
#if EnTk6
    MESSG "    TK6: Enable"  
#endif
#if EnTk7
    MESSG "    TK7: Enable"  
#endif
#if EnTk8
    MESSG "    TK8: Enable"  
#endif
#if EnTk9
    MESSG "    TK9: Enable"  
#endif
#if EnTk10
    MESSG "    TK10: Enable"  
#endif
#if EnTk11
    MESSG "    TK11: Enable"  
#endif
#if EnTk12
    MESSG "    TK12: Enable"  
#endif
#if EnTk13
    MESSG "    TK13: Enable"  
#endif
#if EnTk14
    MESSG "    TK14: Enable"  
#endif
#if EnTk15
    MESSG "    TK15: Enable"  
#endif
;================================================================================
#if (TKLib_M0_OPENED_TK_AMOUNT == 0)
    Error "    No channel is enabled,Please reconfigure EnTk0~EnTk10"  
#endif	

;================================================================================
;CDC clock
#if (TKLib_M0_TKCKS == 0)
    MESSG "    CDC0 Clock: Fosc/4"  
#endif
#if (TKLib_M0_TKCKS == 1)
    MESSG "    CDC0 Clock: Fosc/8"  
#endif
#if (TKLib_M0_TKCKS == 2)
    MESSG "    CDC0 Clock: Fosc/16"  
#endif
#if (TKLib_M0_TKCKS == 3)
    MESSG "    CDC0 Clock: Fosc/32" 
#endif

;================================================================================
#if (TKLib_TOUCH_NUM == 0)
    Error "    Error: Please setting TKLib_TOUCH_NUM > 0"  
#endif

;================================================================================
#if (TKLib_Debounce_TIME == 0)
    Error "    Error: Please setting TKLib_Debounce_TIME > 0"  
#endif
#if (TKLib_Debounce_TIME > 255)
    Error "    Error: Please setting TKLib_Debounce_TIME <= 255"  
#endif

;================================================================================
#if (TKLib_LONG_TOUCH_TIME == 0)
    MESSG "    屏蔽按键最长输出时间功能，即触摸不离开，按键标志一直会置位 " 
#endif
#if (TKLib_LONG_TOUCH_TIME == 1)
    Error "    禁止配置 " 
#endif
#if (TKLib_LONG_TOUCH_TIME > 15)
    Error "    Error: Please setting TKLib_LONG_TOUCH_TIME <= 15"  
#else
#if (TKLib_LONG_TOUCH_TIME > 1)
    MESSG "    开启按键最长输出时间功能，若触摸不离开，按键标志会输出一段时间后，会清零 " 
#endif
#endif

;================================================================================
#if (TKLib_Multi_TOUCH_RST > 1)
    Error "    Error: Please setting TKLib_Multi_TOUCH_RST ∈ {0,1}  "  
#endif

;================================================================================
#if (TKLib_Up_Calibration_Rate < 1)
    Error "    Error: Please setting TKLib_Up_Calibration_Rate >= 1" 
#endif
#if (TKLib_Up_Calibration_Rate > 7)
    Error "    Error: Please setting TKLib_Up_Calibration_Rate <= 7"  
#endif

#if (TKLib_Down_Calibration_Rate < 1)
    Error "    Error: Please setting TKLib_Down_Calibration_Rate >= 1" 
#endif
#if (TKLib_Down_Calibration_Rate > 7)
    Error "    Error: Please setting TKLib_Down_Calibration_Rate <= 7"  
#endif

;================================================================================
#if (TKLib_CaliBaseTime < 1)
    Error "    Error: Please setting TKLib_CaliBaseTime >= 1" 
#endif
#if (TKLib_CaliBaseTime > 254)
    Error "    Error: Please setting TKLib_CaliBaseTime <= 254"  
#endif

#if (TKLib_LongKeyBaseTime < 1)
    Error "    Error: Please setting TKLib_LongKeyBaseTime >= 1" 
#endif
#if (TKLib_LongKeyBaseTime > 254)
    Error "    Error: Please setting TKLib_LongKeyBaseTime <= 254"  
#endif

;================================================================================
#if (TKLib_EFFECTIVE_TOUCH_TIME == 0)
    Error "    Error: Please setting TKLib_EFFECTIVE_TOUCH_TIME > 0"  
#endif
#if (TKLib_EFFECTIVE_TOUCH_TIME > 15)
    Error "    Error: Please setting TKLib_EFFECTIVE_TOUCH_TIME <= 15"  
#endif

;================================================================================
#if (TKLib_INVALID_TOUCH_TIME == 0)
    Error "    Error: Please setting TKLib_INVALID_TOUCH_TIME > 0"  
#endif
#if (TKLib_INVALID_TOUCH_TIME > 15)
    Error "    Error: Please setting TKLib_INVALID_TOUCH_TIME <= 15"  
#endif

;================================================================================
#if (TKLib_FILTER_LEVEL == 0)
    MESSG "    触摸采样滤波等级：普通 " 
#endif
#if (TKLib_FILTER_LEVEL == 1)
    MESSG "    触摸采样滤波等级：中 " 
#endif
#if (TKLib_FILTER_LEVEL == 2)
    MESSG "    触摸采样滤波等级：高 " 
#endif
#if (TKLib_FILTER_LEVEL > 2)    
    Error "    Error: Please setting TKLib_FILTER_LEVEL <= 2"  
#endif

;================================================================================
;#if (TKLib_STRENGTHEN == 0)
;    MESSG "    抗干扰加强：未开启 " 
;#endif
#if (TKLib_STRENGTHEN == 1)
    MESSG "    抗干扰加强：开启 " 
#endif
#if (TKLib_STRENGTHEN > 1)
    Error "    Error: Please setting TKLib_STRENGTHEN ∈ {0,1}  " 
#endif

;================================================================================
#if (TKLib_TK0_F_THRESHOLD > 255)
    Error "    Error: Please setting TKLib_TK0_F_THRESHOLD <= 255"  
#endif
#if (TKLib_TK1_F_THRESHOLD > 255)
    Error "    Error: Please setting TKLib_TK1_F_THRESHOLD <= 255"  
#endif
#if (TKLib_TK2_F_THRESHOLD > 255)
    Error "    Error: Please setting TKLib_TK2_F_THRESHOLD <= 255"  
#endif
#if (TKLib_TK3_F_THRESHOLD > 255)
    Error "    Error: Please setting TKLib_TK3_F_THRESHOLD <= 255"  
#endif
#if (TKLib_TK4_F_THRESHOLD > 255)
    Error "    Error: Please setting TKLib_TK4_F_THRESHOLD <= 255"  
#endif
#if (TKLib_TK5_F_THRESHOLD > 255)
    Error "    Error: Please setting TKLib_TK5_F_THRESHOLD <= 255"  
#endif
#if (TKLib_TK6_F_THRESHOLD > 255)
    Error "    Error: Please setting TKLib_TK6_F_THRESHOLD <= 255"  
#endif
#if (TKLib_TK7_F_THRESHOLD > 255)
    Error "    Error: Please setting TKLib_TK7_F_THRESHOLD <= 255"  
#endif
#if (TKLib_TK8_F_THRESHOLD > 255)
    Error "    Error: Please setting TKLib_TK8_F_THRESHOLD <= 255"  
#endif
#if (TKLib_TK9_F_THRESHOLD > 255)
    Error "    Error: Please setting TKLib_TK9_F_THRESHOLD <= 255"  
#endif
#if (TKLib_TK10_F_THRESHOLD > 255)
    Error "    Error: Please setting TKLib_TK10_F_THRESHOLD <= 255"  
#endif
#if (TKLib_TK11_F_THRESHOLD > 255)
    Error "    Error: Please setting TKLib_TK11_F_THRESHOLD <= 255"  
#endif
#if (TKLib_TK12_F_THRESHOLD > 255)
    Error "    Error: Please setting TKLib_TK12_F_THRESHOLD <= 255"  
#endif
#if (TKLib_TK13_F_THRESHOLD > 255)
    Error "    Error: Please setting TKLib_TK13_F_THRESHOLD <= 255"  
#endif
#if (TKLib_TK14_F_THRESHOLD > 255)
    Error "    Error: Please setting TKLib_TK14_F_THRESHOLD <= 255"  
#endif
#if (TKLib_TK15_F_THRESHOLD > 255)
    Error "    Error: Please setting TKLib_TK15_F_THRESHOLD <= 255"  
#endif

;================================================================================
#if (TKLib_TK0_F_THRESHOLD <9)
    Error "    Error: Please setting TKLib_TK0_F_THRESHOLD >= 9"
#endif
#if (TKLib_TK1_F_THRESHOLD <9)
    Error "    Error: Please setting TKLib_TK1_F_THRESHOLD >= 9"
#endif
#if (TKLib_TK2_F_THRESHOLD <9)
    Error "    Error: Please setting TKLib_TK2_F_THRESHOLD >= 9"
#endif
#if (TKLib_TK3_F_THRESHOLD <9)
    Error "    Error: Please setting TKLib_TK3_F_THRESHOLD >= 9"  
#endif
#if (TKLib_TK4_F_THRESHOLD <9)
    Error "    Error: Please setting TKLib_TK4_F_THRESHOLD >= 9"
#endif
#if (TKLib_TK5_F_THRESHOLD <9)
    Error "    Error: Please setting TKLib_TK5_F_THRESHOLD >= 9"
#endif
#if (TKLib_TK6_F_THRESHOLD <9)
    Error "    Error: Please setting TKLib_TK6_F_THRESHOLD >= 9"
#endif
#if (TKLib_TK7_F_THRESHOLD <9)
    Error "    Error: Please setting TKLib_TK7_F_THRESHOLD >= 9"
#endif
#if (TKLib_TK8_F_THRESHOLD <9)
    Error "    Error: Please setting TKLib_TK8_F_THRESHOLD >= 9"
#endif
#if (TKLib_TK9_F_THRESHOLD <9)
    Error "    Error: Please setting TKLib_TK9_F_THRESHOLD >= 9"
#endif
#if (TKLib_TK10_F_THRESHOLD <9)
    Error "    Error: Please setting TKLib_TK10_F_THRESHOLD >= 9"
#endif
#if (TKLib_TK11_F_THRESHOLD <9)
    Error "    Error: Please setting TKLib_TK11_F_THRESHOLD >= 9"
#endif
#if (TKLib_TK12_F_THRESHOLD <9)
    Error "    Error: Please setting TKLib_TK12_F_THRESHOLD >= 9"
#endif
#if (TKLib_TK13_F_THRESHOLD <9)
    Error "    Error: Please setting TKLib_TK13_F_THRESHOLD >= 9"
#endif
#if (TKLib_TK14_F_THRESHOLD <9)
    Error "    Error: Please setting TKLib_TK14_F_THRESHOLD >= 9"
#endif
#if (TKLib_TK15_F_THRESHOLD <9)
    Error "    Error: Please setting TKLib_TK15_F_THRESHOLD >= 9"
#endif

;================================================================================
#if (TKLib_TouchLowerPower==1)
    MESSG "    触摸低功耗模式：已开启 " 
#endif   
#if (TKLib_TouchLowerPower==0)
    MESSG "    触摸低功耗模式：未开启 "	
#endif
#if (TKLib_TouchLowerPower>1)
    MESSG "    触摸低功耗模式：配置错误，TKLib_TouchLowerPower ∈ {0,1} "	
#endif
;================================================================================
;--------------------------------------------------------------------------------
#if TKLib_TouchLowerPower
;--------------------------------------------------------------------------------
#if TKLPGroup0
#if (TKLib_M0_TKLPGroup0_MASK==0)
    Error "    Error: Please setting TKLib_M0_TKLPGroup0_MASK != 0"
#endif
#endif

#if TKLPGroup1
#if (TKLib_M0_TKLPGroup1_MASK==0)
    Error "    Error: Please setting TKLib_M0_TKLPGroup1_MASK != 0"
#endif
#endif

#if TKLPGroup2
#if (TKLib_M0_TKLPGroup2_MASK==0)
    Error "    Error: Please setting TKLib_M0_TKLPGroup2_MASK != 0"
#endif
#endif

;--------------------------------------------------------------------------------
#if (TKLib_Sleep_F_THRESHOLD <3)
    Error "    Error: Please setting TKLib_Sleep_F_THRESHOLD >= 3"
#endif

;--------------------------------------------------------------------------------
#if TKLPLib_RCOUT_EN
    MESSG "    触摸低功耗模式下辅助端口：使用 " 
#else
    MESSG "    触摸低功耗模式下辅助端口：不使用 "	
#endif

;--------------------------------------------------------------------------------
#endif
;--------------------------------------------------------------------------------

;================================================================================
#endif

;*********************************END OF FILE************************************

                                   