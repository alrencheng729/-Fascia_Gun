Battery_Filter1:
		
		;// 采样值Battery 上次显示值为 Battery_New2
		;// 本函数的处理的是 将在上次显示值Battery_New2上下波动大于1的值 抛弃 不做处理
		;// 但本函数仅在第一次确定显示值后 才进行调用 否则会导致一直显示 00
		
		;//	Battery_New2+2 ----> Battery_1_H
		MOVIA		2
		ADDAR		Battery_New2,0
		MOVAR		Battery_1_H
		;// Battery_New2-1 ----> Battery_1_L
		DECR		Battery_New2,0
		MOVAR		Battery_1_L
		
		;// Battery_1_L <=Battery <= Battery_1_H
		MOVR		Battery,0
		JGAR		Battery_1_L
		RETURN
		; MOVR		Battery_1_H,0
		; JGAR		Battery
		; RETURN
		MOVR		Battery,0
		MOVAR		Battery_New1
		BSET		Battery_F,6
		RETURN
