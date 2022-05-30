;*******************(C) COPYRIGHT 2021 Masses-Chip ******************************
;* File Name          : M8P634_Touch_M0_Lib_CFG.ASM
;* Author             : MASSES CHIP
;* Version            : V2.08
;* Date               : 2021/12/01
;********************************************************************************

; 本文件用户不可自行修改

;================================================================================


;================================================================================ 
       
 LIST    p=m8P634

;================================================================================  
#include     m8P634.inc   
#include     M8R_P_MACRO.inc 
#include     M8P634_Touch_M0_Lib.inc
#include     M8P634_Touch_M0_Lib_CFG.INC   
 
;================================================================================  
 CODE 
 
;================================================================================        
#if TKLib_TouchLowerPower 
 ;FUNC 
 GLOBAL _RCOUT_OUTPUT_EN   
 GLOBAL _RCOUT_OUTPUT_DIS
 GLOBAL _WDT_WakeUp_Handle 
#endif 

 GLOBAL _ScanNextChannel 
 GLOBAL _TkSignalHandle_Next 
 
 extern TKCOM_PIN_OUT
 extern _READ_TK_EN_MASK_DATA 
 
 extern _READ_TAB_TOUCH_FN_DATA 
 
 extern TAB_TOUCH_FN_DATA 
 extern _RChannelEnL    
 extern _RChannelEnH  

 extern _RTkTemp9    
 extern _RTkTemp10 
#define RTkmaskL        _RTkTemp9
#define RTkmaskH        _RTkTemp10

 extern _RTkTemp2 
#define berror_F        _RTkTemp2,4 

 extern _RTkTemp4 
#define _R_CNT          _RTkTemp4


 extern _RTkBuff2 
#define RTk_CH            _RTkBuff2


 GLOBAL _other_lib_fun1
 GLOBAL _other_lib_fun2 

#if  (TKLib_FILTER_LEVEL > 0)
 extern _other_fun1  
 extern _other_fun2 
#endif

 EXTERN     _RTkBitFlag 

;==================================================================== 
#if TKLib_TouchLowerPower
_WDT_WakeUp_Handle:
; Stack:	Level 1
; INPUT:	 
; OUTPUT:	
; OTHER	:
;此程序是在触摸低功耗模式下，需要处理的操作，如有需要可增加操作程序  
;如RTC时钟1S计时程序,LCD时钟刷新显示程序等等
  
  
  
  
; bclr  bLowPowerModeRun ; 可根据需求，判断系统是否需要强制唤醒(清bLowPowerModeRun，强制唤醒系统)
                         
    return 
#endif
 
;================================================================================   
;以下用户可不查看 
;================================================================================    
#if TKLib_TouchLowerPower 
_RCOUT_OUTPUT_EN:
; Stack:	Level 1
; INPUT:	 
; OUTPUT:	
; OTHER	:

#if TKLPLib_RCOUT_EN	
    bclr    P_RCOUT,N_RCOUT 
    bset    OE_RCOUT,N_RCOUT
#endif 	
    return		  
#endif 
  
;================================================================================  
#if TKLib_TouchLowerPower 
_RCOUT_OUTPUT_DIS:
; Stack:	Level 1
; INPUT:	 
; OUTPUT:	
; OTHER	:
	
#if TKLPLib_RCOUT_EN
    bclr    OE_RCOUT,N_RCOUT  
#endif 
    return		  
#endif 

;==================================================================== 
_ScanNextChannel:
; Stack:	Level 3
; INPUT:	 
; OUTPUT:	
; OTHER	:	

    CALL    TKCOM_PIN_OUT 	

; set tk ch	
    clrr    TK0CHSL
    clrr    TK0CHSH  ;关闭所有连接的通道

#if EnTk0		
    jbts0   _RChannelEnL,0
    goto    scantk0_set
#endif

#if EnTk1	    
    jbts0   _RChannelEnL,1
    goto    scantk1_set
#endif

#if EnTk2	    
    jbts0   _RChannelEnL,2
    goto    scantk2_set
#endif

#if EnTk3	    
    jbts0   _RChannelEnL,3
    goto    scantk3_set
#endif

#if EnTk4	    
    jbts0   _RChannelEnL,4
    goto    scantk4_set
#endif

#if EnTk5	    
    jbts0   _RChannelEnL,5
    goto    scantk5_set
#endif

#if EnTk6	    
    jbts0   _RChannelEnL,6
    goto    scantk6_set
#endif

#if EnTk7	    
    jbts0   _RChannelEnL,7
    goto    scantk7_set
#endif

#if EnTk8	    
    jbts0   _RChannelEnH,0
    goto    scantk8_set
#endif

#if EnTk9	    
    jbts0   _RChannelEnH,1
    goto    scantk9_set
#endif

#if EnTk10	    
    jbts0   _RChannelEnH,2
    goto    scantk10_set
#endif

#if EnTk11	    
    jbts0   _RChannelEnH,3
    goto    scantk11_set
#endif

#if EnTk12	    
    jbts0   _RChannelEnH,4
    goto    scantk12_set
#endif

#if EnTk13	    
    jbts0   _RChannelEnH,5
    goto    scantk13_set
#endif

#if EnTk14	    
    jbts0   _RChannelEnH,6
    goto    scantk14_set
#endif

#if EnTk15	    
    jbts0   _RChannelEnH,7
    goto    scantk15_set
#endif

    bset    bOneScanDone
    CALL    _READ_TK_EN_MASK_DATA  
    goto    ScanNextChannel_end ;error	
    
#if EnTk0		
scantk0_set:
    bclr    _RChannelEnL,0	 
    bset    TK0CHSL,0  		
    goto    ScanNextChannel_end_1			
#endif

#if EnTk1		
scantk1_set:
    bclr    _RChannelEnL,1		 
    bset    TK0CHSL,1  		
    goto    ScanNextChannel_end_1	
#endif

#if EnTk2		 
scantk2_set:
    bclr    _RChannelEnL,2		 
    bset    TK0CHSL,2  		
    goto    ScanNextChannel_end_1
#endif

#if EnTk3	
scantk3_set:
    bclr    _RChannelEnL,3	 
    bset    TK0CHSL,3  		
    goto    ScanNextChannel_end_1
#endif

#if EnTk4			 
scantk4_set:
    bclr    _RChannelEnL,4	 
    bset    TK0CHSL,4  		
    goto    ScanNextChannel_end_1
#endif

#if EnTk5		 
scantk5_set:
    bclr    _RChannelEnL,5	 
    bset    TK0CHSL,5  		
    goto    ScanNextChannel_end_1
#endif

#if EnTk6		 
scantk6_set:
    bclr    _RChannelEnL,6	 
    bset    TK0CHSL,6 		
    goto    ScanNextChannel_end_1
#endif

#if EnTk7		 
scantk7_set:
    bclr    _RChannelEnL,7	 
    bset    TK0CHSL,7  		
    goto    ScanNextChannel_end_1
#endif

#if EnTk8		 
scantk8_set:
    bclr    _RChannelEnH,0		 
    bset    TK0CHSH,0  		
    goto    ScanNextChannel_end_1
#endif

#if EnTk9	 
scantk9_set:
    bclr    _RChannelEnH,1	 
    bset    TK0CHSH,1  		
    goto    ScanNextChannel_end_1
#endif

#if EnTk10		 
scantk10_set:
    bclr    _RChannelEnH,2	 
    bset    TK0CHSH,2  		
    goto    ScanNextChannel_end_1
#endif

#if EnTk11		 
scantk11_set:
    bclr    _RChannelEnH,3	 
    bset    TK0CHSH,3  		
    goto    ScanNextChannel_end_1
#endif

#if EnTk12		 
scantk12_set:
    bclr    _RChannelEnH,4	 
    bset    TK0CHSH,4 		
    goto    ScanNextChannel_end_1
#endif

#if EnTk13		 
scantk13_set:
    bclr    _RChannelEnH,5	 
    bset    TK0CHSH,5  		
    goto    ScanNextChannel_end_1
#endif

#if EnTk14		 
scantk14_set:
    bclr    _RChannelEnH,6	 
    bset    TK0CHSH,6  		
    goto    ScanNextChannel_end_1
#endif

#if EnTk15		 
scantk15_set:
    bclr    _RChannelEnH,7	 
    bset    TK0CHSH,7  		
    goto    ScanNextChannel_end_1
#endif

ScanNextChannel_end_1:
    incr    RTk_CH,r
	
ScanNextChannel_end:	
    CLRR    _R_CNT	
    return	
 
;==================================================================== 
_TkSignalHandle_Next: 
; Stack:	Level 2
; INPUT:	 
; OUTPUT:	
; OTHER	:

;read finger&noise data
    clrr    RTkmaskL 
    clrr    RTkmaskH

;    movia   high(TAB_TOUCH_FN_DATA)
;    movar   FSR1
;    movia   low(TAB_TOUCH_FN_DATA)
;    movar   FSR0	

   CALL _READ_TAB_TOUCH_FN_DATA

#if EnTk0	 
    jbts0   _RChannelEnL,0
    goto    READ_tk0_FN
#endif

#if EnTk1    
    jbts0   _RChannelEnL,1
    goto    READ_tk1_FN
#endif

#if EnTk2    
    jbts0   _RChannelEnL,2
    goto    READ_tk2_FN
#endif

#if EnTk3    
    jbts0   _RChannelEnL,3
    goto    READ_tk3_FN
#endif

#if EnTk4    
    jbts0   _RChannelEnL,4
    goto    READ_tk4_FN
#endif

#if EnTk5    
    jbts0   _RChannelEnL,5
    goto    READ_tk5_FN
 #endif

#if EnTk6   
    jbts0   _RChannelEnL,6
    goto    READ_tk6_FN
#endif

#if EnTk7    
    jbts0   _RChannelEnL,7
    goto    READ_tk7_FN
#endif

#if EnTk8    
    jbts0   _RChannelEnH,0
    goto    READ_tk8_FN
#endif

#if EnTk9    
    jbts0   _RChannelEnH,1
    goto    READ_tk9_FN
#endif

#if EnTk10    
    jbts0   _RChannelEnH,2
    goto    READ_tk10_FN    
#endif

#if EnTk11    
    jbts0   _RChannelEnH,3
    goto    READ_tk11_FN    
#endif

#if EnTk12    
    jbts0   _RChannelEnH,4
    goto    READ_tk12_FN    
#endif

#if EnTk13    
    jbts0   _RChannelEnH,5
    goto    READ_tk13_FN    
#endif

#if EnTk14    
    jbts0   _RChannelEnH,6
    goto    READ_tk14_FN    
#endif

#if EnTk15    
    jbts0   _RChannelEnH,7
    goto    READ_tk15_FN    
#endif

    bset    berror_F
    goto    READ_tkx_FN_end_1   ;error,no tk ch en 

#if EnTk0 
READ_tk0_FN:
    bset     RTkmaskL,0
    bclr     _RChannelEnL,0	 	
    goto     READ_tkx_FN_end_1			
#endif

#if EnTk1	
READ_tk1_FN:
    bset     RTkmaskL,1
    bclr     _RChannelEnL,1	 		
    goto     READ_tkx_FN_end_1	
#endif

#if EnTk2	 
READ_tk2_FN:
    bset     RTkmaskL,2 
    bclr     _RChannelEnL,2		 
    goto     READ_tkx_FN_end_1
#endif

#if EnTk3
READ_tk3_FN:
    bset     RTkmaskL,3 
    bclr     _RChannelEnL,3	 	
    goto     READ_tkx_FN_end_1
#endif

#if EnTk4		 
READ_tk4_FN:
    bset     RTkmaskL,4 
    bclr     _RChannelEnL,4	 		
    goto     READ_tkx_FN_end_1
#endif

#if EnTk5	 
READ_tk5_FN:
    bset     RTkmaskL,5 
    bclr     _RChannelEnL,5	 	
    goto     READ_tkx_FN_end_1
#endif

#if EnTk6	 
READ_tk6_FN:
    bset     RTkmaskL,6
    bclr     _RChannelEnL,6	 	
    goto     READ_tkx_FN_end_1
#endif

#if EnTk7	 
READ_tk7_FN:
    bset     RTkmaskL,7 
    bclr     _RChannelEnL,7	  
    goto     READ_tkx_FN_end_1
#endif

#if EnTk8	 
READ_tk8_FN:
    bset     RTkmaskH,0 
    bclr     _RChannelEnH,0		 
    goto    READ_tkx_FN_end_1
#endif

#if EnTk9	 
READ_tk9_FN:
    bset     RTkmaskH,1 
    bclr    _RChannelEnH,1	 	
    goto    READ_tkx_FN_end_1
#endif

#if EnTk10	 
READ_tk10_FN:
    bset     RTkmaskH,2 
    bclr     _RChannelEnH,2	 
    goto     READ_tkx_FN_end_1
#endif

#if EnTk11	 
READ_tk11_FN:
    bset     RTkmaskH,3 
    bclr     _RChannelEnH,3	 
    goto     READ_tkx_FN_end_1
#endif

#if EnTk12	 
READ_tk12_FN:
    bset     RTkmaskH,4 
    bclr     _RChannelEnH,4	 
    goto     READ_tkx_FN_end_1
#endif

#if EnTk13	 
READ_tk13_FN:
    bset     RTkmaskH,5 
    bclr     _RChannelEnH,5	 
    goto     READ_tkx_FN_end_1
#endif

#if EnTk14	 
READ_tk14_FN:
    bset     RTkmaskH,6 
    bclr     _RChannelEnH,6	 
    goto     READ_tkx_FN_end_1
#endif

#if EnTk15	 
READ_tk15_FN:
    bset     RTkmaskH,7 
    bclr     _RChannelEnH,7	 
    goto     READ_tkx_FN_end_1
#endif

READ_tkx_FN_end_1:

    return
  
;==================================================================== 
_other_lib_fun1

#if  (TKLib_FILTER_LEVEL==0)
  return
#endif
#if  (TKLib_FILTER_LEVEL>0)

  goto  _other_fun1

#endif

;================================================================================  
_other_lib_fun2 
#if  (TKLib_FILTER_LEVEL==0)
  return
#endif
#if  (TKLib_FILTER_LEVEL>0)

  goto  _other_fun2

#endif

;================================================================================  
  end
  
;*********************************END OF FILE************************************

                                   