Battery_Set:
		
		MOVIA		0x05
		JLAR		R_ADC_sum_H
		GOTO		Battery_E1
		MOVIA		0x06
		JLAR		R_ADC_sum_H
		GOTO		Battery_Cmp_1
		MOVIA		0x07
		JLAR		R_ADC_sum_H
		GOTO		Battery_Cmp_2
		GOTO		Battery_Cmp_3
Battery_Cmp_1:

		MOVIA		0x90
		JLAR		R_ADC_sum_L
		GOTO		Battery_E1

		MOVIA		0x96
		JLAR		R_ADC_sum_L
		GOTO		Battery_11

		MOVIA		0x9C
		JLAR		R_ADC_sum_L
		GOTO		Battery_12

		MOVIA		0xA2
		JLAR		R_ADC_sum_L
		GOTO		Battery_13
		
		MOVIA		0xA8
		JLAR		R_ADC_sum_L
		GOTO		Battery_14
		;//			10
		MOVIA		0xAE
		JLAR		R_ADC_sum_L
		GOTO		Battery_15
		;//			11
		MOVIA		0xB4
		JLAR		R_ADC_sum_L
		GOTO		Battery_16
		;//			12
		MOVIA		0xBA
		JLAR		R_ADC_sum_L
		GOTO		Battery_17
		;//			13
		MOVIA		0xC0
		JLAR		R_ADC_sum_L
		GOTO		Battery_18
		;//			14
		MOVIA		0xC6
		JLAR		R_ADC_sum_L
		GOTO		Battery_19
		;//			15
		MOVIA		0xCC
		JLAR		R_ADC_sum_L
		GOTO		Battery_20
		;//			16
		MOVIA		0xD2
		JLAR		R_ADC_sum_L
		GOTO		Battery_21
		;//			17
		MOVIA		0xD8
		JLAR		R_ADC_sum_L
		GOTO		Battery_22
		;//			18
		MOVIA		0xDE
		JLAR		R_ADC_sum_L
		GOTO		Battery_23
		;//			19
		MOVIA		0xE4
		JLAR		R_ADC_sum_L
		GOTO		Battery_24
		;//			20
		MOVIA		0xEA
		JLAR		R_ADC_sum_L
		GOTO		Battery_25
		;//			21
		MOVIA		0xF0
		JLAR		R_ADC_sum_L
		GOTO		Battery_26
		;//			22
		MOVIA		0xF6
		JLAR		R_ADC_sum_L
		GOTO		Battery_27
		;//			23
		MOVIA		0xFC
		JLAR		R_ADC_sum_L
		GOTO		Battery_28

		GOTO		Battery_29

Battery_Cmp_2:
		;//			24
		MOVIA		0x02
		JLAR		R_ADC_sum_L
		GOTO		Battery_29
		;//			25
		MOVIA		0x08
		JLAR		R_ADC_sum_L
		GOTO		Battery_30
		;//			26
		MOVIA		0x0E
		JLAR		R_ADC_sum_L
		GOTO		Battery_31
		;//			27
		MOVIA		0x14
		JLAR		R_ADC_sum_L
		GOTO		Battery_32
		;//			28
		MOVIA		0x1A
		JLAR		R_ADC_sum_L
		GOTO		Battery_33
		;//			29
		MOVIA		0x20
		JLAR		R_ADC_sum_L
		GOTO		Battery_34
		;//			30
		MOVIA		0x26
		JLAR		R_ADC_sum_L
		GOTO		Battery_35
		;//			31
		MOVIA		0x2C
		JLAR		R_ADC_sum_L
		GOTO		Battery_36
		;//			32
		MOVIA		0x32
		JLAR		R_ADC_sum_L
		GOTO		Battery_37
		;//			33
		MOVIA		0x38
		JLAR		R_ADC_sum_L
		GOTO		Battery_38
		;//			34
		MOVIA		0x3E
		JLAR		R_ADC_sum_L
		GOTO		Battery_39
		;//			35
		MOVIA		0x44
		JLAR		R_ADC_sum_L
		GOTO		Battery_40
		;//			36
		MOVIA		0x4A
		JLAR		R_ADC_sum_L
		GOTO		Battery_41
		;//			37
		MOVIA		0x50
		JLAR		R_ADC_sum_L
		GOTO		Battery_42
		;//			38
		MOVIA		0x56
		JLAR		R_ADC_sum_L
		GOTO		Battery_43
		;//			39
		MOVIA		0x5C
		JLAR		R_ADC_sum_L
		GOTO		Battery_44
		;//			40
		MOVIA		0x62
		JLAR		R_ADC_sum_L
		GOTO		Battery_45
		;//			41
		MOVIA		0x68
		JLAR		R_ADC_sum_L
		GOTO		Battery_46
		;//			42
		MOVIA		0x6E
		JLAR		R_ADC_sum_L
		GOTO		Battery_47
		;//			43
		MOVIA		0x74
		JLAR		R_ADC_sum_L
		GOTO		Battery_48
		;//			44
		MOVIA		0x7A
		JLAR		R_ADC_sum_L
		GOTO		Battery_49
		;//			45
		MOVIA		0x80
		JLAR		R_ADC_sum_L
		GOTO		Battery_50
		;//			46
		MOVIA		0x86
		JLAR		R_ADC_sum_L
		GOTO		Battery_51
		;//			47
		MOVIA		0x8C
		JLAR		R_ADC_sum_L
		GOTO		Battery_52
		;//			48
		MOVIA		0x92
		JLAR		R_ADC_sum_L
		GOTO		Battery_53
		;//			49
		MOVIA		0x98
		JLAR		R_ADC_sum_L
		GOTO		Battery_54
		;//			50
		MOVIA		0x9E
		JLAR		R_ADC_sum_L
		GOTO		Battery_55
		;//			51
		MOVIA		0xA4
		JLAR		R_ADC_sum_L
		GOTO		Battery_56
		;//			52
		MOVIA		0xAA
		JLAR		R_ADC_sum_L
		GOTO		Battery_57
		;//			53
		MOVIA		0xB0
		JLAR		R_ADC_sum_L
		GOTO		Battery_58
		;//			54
		MOVIA		0xB6
		JLAR		R_ADC_sum_L
		GOTO		Battery_59
		;//			55
		MOVIA		0xBC
		JLAR		R_ADC_sum_L
		GOTO		Battery_60
		;//			56
		MOVIA		0xC2
		JLAR		R_ADC_sum_L
		GOTO		Battery_61
		;//			57
		MOVIA		0xC8
		JLAR		R_ADC_sum_L
		GOTO		Battery_62
		;//			58
		MOVIA		0xCE
		JLAR		R_ADC_sum_L
		GOTO		Battery_63
		;//			59
		MOVIA		0xD4
		JLAR		R_ADC_sum_L
		GOTO		Battery_64
		;//			60
		MOVIA		0xDA
		JLAR		R_ADC_sum_L
		GOTO		Battery_65
		;//			61
		MOVIA		0xE0
		JLAR		R_ADC_sum_L
		GOTO		Battery_66
		;//			62
		MOVIA		0xE6
		JLAR		R_ADC_sum_L
		GOTO		Battery_67
		;//			63
		MOVIA		0xEC
		JLAR		R_ADC_sum_L
		GOTO		Battery_68
		;//			64
		MOVIA		0xF2
		JLAR		R_ADC_sum_L
		GOTO		Battery_69
		;//			65
		MOVIA		0xF8
		JLAR		R_ADC_sum_L
		GOTO		Battery_70
		;//			66
		MOVIA		0xFE
		JLAR		R_ADC_sum_L
		GOTO		Battery_71

		GOTO		Battery_72

Battery_Cmp_3:
		;//			67
		MOVIA		0x04
		JLAR		R_ADC_sum_L
		GOTO		Battery_72
		;//			68
		MOVIA		0x0A
		JLAR		R_ADC_sum_L
		GOTO		Battery_73
		;//			69
		MOVIA		0x10
		JLAR		R_ADC_sum_L
		GOTO		Battery_74
		;//			70
		MOVIA		0x16
		JLAR		R_ADC_sum_L
		GOTO		Battery_75
		;//			71
		MOVIA		0x1C
		JLAR		R_ADC_sum_L
		GOTO		Battery_76
		;//			72
		MOVIA		0x22
		JLAR		R_ADC_sum_L
		GOTO		Battery_77
		;//			73
		MOVIA		0x28
		JLAR		R_ADC_sum_L
		GOTO		Battery_78
		;//			74
		MOVIA		0x2E
		JLAR		R_ADC_sum_L
		GOTO		Battery_79
		;//			75
		MOVIA		0x34
		JLAR		R_ADC_sum_L
		GOTO		Battery_80
		;//			76
		MOVIA		0x3A
		JLAR		R_ADC_sum_L
		GOTO		Battery_81
		;//			77
		MOVIA		0x40
		JLAR		R_ADC_sum_L
		GOTO		Battery_82
		;//			78
		MOVIA		0x46
		JLAR		R_ADC_sum_L
		GOTO		Battery_83
		;//			79
		MOVIA		0x4C
		JLAR		R_ADC_sum_L
		GOTO		Battery_84
		;//			80
		MOVIA		0x52
		JLAR		R_ADC_sum_L
		GOTO		Battery_85
		;//			81
		MOVIA		0x58
		JLAR		R_ADC_sum_L
		GOTO		Battery_86
		;//			82
		MOVIA		0x5E
		JLAR		R_ADC_sum_L
		GOTO		Battery_87
		;//			83
		MOVIA		0x64
		JLAR		R_ADC_sum_L
		GOTO		Battery_88
		;//			84
		MOVIA		0x6A
		JLAR		R_ADC_sum_L
		GOTO		Battery_89
		;//			85
		MOVIA		0x70
		JLAR		R_ADC_sum_L
		GOTO		Battery_90
		;//			86
		MOVIA		0x76
		JLAR		R_ADC_sum_L
		GOTO		Battery_91
		;//			87
		MOVIA		0x7C
		JLAR		R_ADC_sum_L
		GOTO		Battery_92
		;//			88
		MOVIA		0x82
		JLAR		R_ADC_sum_L
		GOTO		Battery_93
		;//			89
		MOVIA		0x88
		JLAR		R_ADC_sum_L
		GOTO		Battery_94
		;//			90
		MOVIA		0x8E
		JLAR		R_ADC_sum_L
		GOTO		Battery_95
		;//			91
		MOVIA		0x94
		JLAR		R_ADC_sum_L
		GOTO		Battery_96
		;//			92
		MOVIA		0x9A
		JLAR		R_ADC_sum_L
		GOTO		Battery_97
		;//			93
		MOVIA		0xA0
		JLAR		R_ADC_sum_L
		GOTO		Battery_98
		;//			94
		MOVIA		0xF0
		JLAR		R_ADC_sum_L
		GOTO		Battery_99
		;GOTO		ADC_Work
		GOTO		MainLoop_2
		
Battery_E1:
		MOVIA		10
		MOVAR		Battery
		RETURN
Battery_11:
		MOVIA		11
		MOVAR		Battery
		RETURN
Battery_12:
		MOVIA		12
		MOVAR		Battery
		RETURN
Battery_13:
		MOVIA		13
		MOVAR		Battery
		RETURN
Battery_14:
		MOVIA		14
		MOVAR		Battery
		RETURN
Battery_15:
		MOVIA		15
		MOVAR		Battery
		RETURN
Battery_16:
		MOVIA		16
		MOVAR		Battery
		RETURN
Battery_17:
		MOVIA		17
		MOVAR		Battery
		RETURN
Battery_18:
		MOVIA		18
		MOVAR		Battery
		RETURN
Battery_19:
		MOVIA		19
		MOVAR		Battery
		RETURN
Battery_20:
		MOVIA		20
		MOVAR		Battery
		RETURN
Battery_21:
		MOVIA		21
		MOVAR		Battery
		RETURN
Battery_22:
		MOVIA		22
		MOVAR		Battery
		RETURN
Battery_23:
		MOVIA		23
		MOVAR		Battery
		RETURN
Battery_24:
		MOVIA		24
		MOVAR		Battery
		RETURN
Battery_25:
		MOVIA		25
		MOVAR		Battery
		RETURN
Battery_26:
		MOVIA		26
		MOVAR		Battery
		RETURN
Battery_27:
		MOVIA		27
		MOVAR		Battery
		RETURN
Battery_28:
		MOVIA		28
		MOVAR		Battery
		RETURN
Battery_29:
		MOVIA		29
		MOVAR		Battery
		RETURN
Battery_30:
		MOVIA		30
		MOVAR		Battery
		RETURN
Battery_31:
		MOVIA		31
		MOVAR		Battery
		RETURN
Battery_32:
		MOVIA		32
		MOVAR		Battery
		RETURN
Battery_33:
		MOVIA		33
		MOVAR		Battery
		RETURN
Battery_34:
		MOVIA		34
		MOVAR		Battery
		RETURN
Battery_35:
		MOVIA		35
		MOVAR		Battery
		RETURN
Battery_36:
		MOVIA		36
		MOVAR		Battery
		RETURN
Battery_37:
		MOVIA		37
		MOVAR		Battery
		RETURN
Battery_38:
		MOVIA		38
		MOVAR		Battery
		RETURN
Battery_39:
		MOVIA		39
		MOVAR		Battery
		RETURN
Battery_40:
		MOVIA		40
		MOVAR		Battery
		RETURN
Battery_41:
		MOVIA		41
		MOVAR		Battery
		RETURN
Battery_42:
		MOVIA		42
		MOVAR		Battery
		RETURN
Battery_43:
		MOVIA		43
		MOVAR		Battery
		RETURN
Battery_44:
		MOVIA		44
		MOVAR		Battery
		RETURN
Battery_45:
		MOVIA		45
		MOVAR		Battery
		RETURN
Battery_46:
		MOVIA		46
		MOVAR		Battery
		RETURN
Battery_47:
		MOVIA		47
		MOVAR		Battery
		RETURN
Battery_48:
		MOVIA		48
		MOVAR		Battery
		RETURN
Battery_49:
		MOVIA		49
		MOVAR		Battery
		RETURN
Battery_50:
		MOVIA		50
		MOVAR		Battery
		RETURN
Battery_51:
		MOVIA		51
		MOVAR		Battery
		RETURN
Battery_52:
		MOVIA		52
		MOVAR		Battery
		RETURN
Battery_53:
		MOVIA		53
		MOVAR		Battery
		RETURN
Battery_54:
		MOVIA		54
		MOVAR		Battery
		RETURN
Battery_55:
		MOVIA		55
		MOVAR		Battery
		RETURN
Battery_56:
		MOVIA		56
		MOVAR		Battery
		RETURN
Battery_57:
		MOVIA		57
		MOVAR		Battery
		RETURN
Battery_58:
		MOVIA		58
		MOVAR		Battery
		RETURN
Battery_59:
		MOVIA		59
		MOVAR		Battery
		RETURN
Battery_60:
		MOVIA		60
		MOVAR		Battery
		RETURN
Battery_61:
		MOVIA		61
		MOVAR		Battery
		RETURN
Battery_62:
		MOVIA		62
		MOVAR		Battery
		RETURN
Battery_63:
		MOVIA		63
		MOVAR		Battery
		RETURN
Battery_64:
		MOVIA		64
		MOVAR		Battery
		RETURN
Battery_65:
		MOVIA		65
		MOVAR		Battery
		RETURN
Battery_66:
		MOVIA		66
		MOVAR		Battery
		RETURN
Battery_67:
		MOVIA		67
		MOVAR		Battery
		RETURN
Battery_68:
		MOVIA		68
		MOVAR		Battery
		RETURN
Battery_69:
		MOVIA		69
		MOVAR		Battery
		RETURN
Battery_70:
		MOVIA		70
		MOVAR		Battery
		RETURN
Battery_71:
		MOVIA		71
		MOVAR		Battery
		RETURN
Battery_72:
		MOVIA		72
		MOVAR		Battery
		RETURN
Battery_73:
		MOVIA		73
		MOVAR		Battery
		RETURN
Battery_74:
		MOVIA		74
		MOVAR		Battery
		RETURN
Battery_75:
		MOVIA		75
		MOVAR		Battery
		RETURN
Battery_76:
		MOVIA		76
		MOVAR		Battery
		RETURN
Battery_77:
		MOVIA		77
		MOVAR		Battery
		RETURN
Battery_78:
		MOVIA		78
		MOVAR		Battery
		RETURN
Battery_79:
		MOVIA		79
		MOVAR		Battery
		RETURN
Battery_80:
		MOVIA		80
		MOVAR		Battery
		RETURN
Battery_81:
		MOVIA		81
		MOVAR		Battery
		RETURN
Battery_82:
		MOVIA		82
		MOVAR		Battery
		RETURN
Battery_83:
		MOVIA		83
		MOVAR		Battery
		RETURN
Battery_84:
		MOVIA		84
		MOVAR		Battery
		RETURN
Battery_85:
		MOVIA		85
		MOVAR		Battery
		RETURN
Battery_86:
		MOVIA		86
		MOVAR		Battery
		RETURN
Battery_87:
		MOVIA		87
		MOVAR		Battery
		RETURN
Battery_88:
		MOVIA		88
		MOVAR		Battery
		RETURN
Battery_89:
		MOVIA		89
		MOVAR		Battery
		RETURN
Battery_90:
		MOVIA		90
		MOVAR		Battery
		RETURN
Battery_91:
		MOVIA		91
		MOVAR		Battery
		RETURN
Battery_92:
		MOVIA		92
		MOVAR		Battery
		RETURN
Battery_93:
		MOVIA		93
		MOVAR		Battery
		RETURN
Battery_94:
		MOVIA		94
		MOVAR		Battery
		RETURN
Battery_95:
		MOVIA		95
		MOVAR		Battery
		RETURN
Battery_96:
		MOVIA		96
		MOVAR		Battery
		RETURN
Battery_97:
		MOVIA		97
		MOVAR		Battery
		RETURN
Battery_98:
		MOVIA		98
		MOVAR		Battery
		RETURN
Battery_99:
		MOVIA		99
		MOVAR		Battery
		RETURN