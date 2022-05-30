ADC_Work:

		BSET		ANSC,5
		BCLR		OEC,5

		MOVIA		0x9A
		MOVAR		ADCON0
		MOVIA		0x35
		MOVAR		ADCON1
		MOVIA		0x00
		MOVAR		ADCON2
		
		MOVIA		10
		MOVAR		R_Count
		MOVIA		0xFF				;//初始化ADC值有关寄存器
		MOVAR		R_ADC_min_L
		MOVAR		R_ADC_min_H
		CLRR		R_ADC_max_L
		CLRR		R_ADC_max_H
		CLRR		R_ADC_sum_L
		CLRR		R_ADC_sum_H
ADC_Collect:
		CALL		Start_ADC_Convert
		CALL		Compare_Data

		DJZR        R_Count,R
		GOTO        ADC_collect	
		MOVR        R_ADC_max_L,A		;//减去最大值
		SUBRA		R_ADC_sum_L,R
		MOVR        R_ADC_max_H,A
		SBCRA 		R_ADC_sum_H,R

		MOVR        R_ADC_min_L,A		;//减去最小值
		SUBRA		R_ADC_sum_L,R
		MOVR        R_ADC_min_H,A
		SBCRA 		R_ADC_sum_H,R

		MOVIA       3
		MOVAR       R_Count
Compute_Average:						;//计算平均值
		BCLR		STATUS,C	
		RRR			R_ADC_sum_H,R
		RRR         R_ADC_sum_L,R
		DJZR		R_Count,R
		GOTO		Compute_Average
		
		GOTO		ADC_End


;//-------------------------------------------------------------
;//开启ADC转换，累加采集到的ADC值
Start_ADC_Convert:
		BSET		ADCON0,6
		JBTS0		ADCON0,6
		GOTO		$-1
		MOVR		ADL,A
		ADDAR		R_ADC_sum_L,R
		MOVR		ADH,A
		ADCAR		R_ADC_sum_H,R
		
		GOTO		ADC_End
		


;//-------------------------------------------------------------
;//数据比较，确定最大、小值
Compare_Data:
Compare_max:							;//最大值比较
		MOVR		ADH,A
		JGAR        R_ADC_max_H
		GOTO        Compare_min
		JBTS1       STATUS,Z
		GOTO        Updata_max
		MOVR		ADL,A
		JGAR        R_ADC_max_L
		GOTO        Compare_min
Updata_max:								;//更新最大值
		MOVR		ADH,A
		MOVAR		R_ADC_max_H
		MOVR		ADL,A
		MOVAR		R_ADC_max_L
Compare_min:							;//最小值比较
        MOVR		ADH,A
		JGAR        R_ADC_min_H
		GOTO        Updata_min
		JBTS1       STATUS,Z
		GOTO        ADC_End
		MOVR		ADL,A
		JLAR        R_ADC_min_L
		GOTO        ADC_End
Updata_min:								;//更新最大值
		MOVR		ADH,A				
		MOVAR		R_ADC_min_H
		MOVR		ADL,A
		MOVAR		R_ADC_min_L
ADC_End:
		RETURN