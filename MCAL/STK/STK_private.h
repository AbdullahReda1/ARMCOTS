/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        8 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         8 MAY, 2023       Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef MCAL_STK_STK_PRIVATE_H
#define MCAL_STK_STK_PRIVATE_H


#define AHB_DEVIDED_BY_8    0
#define AHB_DEVIDED_BY_1    1

#define ENABLE_INTERRUPT	1
#define DISABLE_INTERRUPT	0

#define STK_ENABLE			1
#define STK_DISABLE			0

#define	SINGLE_INTERVAL     0
#define PERIODIC_INTERVAL   1

#define MAX_REG_VAL   		31


/**************************** Register Description ******************************/


typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}STK_t;

#define STK_BASE_ADDRESS	0xE000E010

#define STK    ((volatile STK_t*)STK_BASE_ADDRESS)


#define CTRL_ENABLE          	0
#define CTRL_TICKINT         	1
#define CTRL_CLKSOURCE       	2
#define CTRL_COUNTFLAG       	16

#define LOAD_RELOAD     		0
#define LOAD_RELOAD0    		0
#define LOAD_RELOAD1    		1
#define LOAD_RELOAD2    		2
#define LOAD_RELOAD3    		3
#define LOAD_RELOAD4    		4
#define LOAD_RELOAD5    		5
#define LOAD_RELOAD6    		6
#define LOAD_RELOAD7    		7
#define LOAD_RELOAD8    		8
#define LOAD_RELOAD9    		9
#define LOAD_RELOAD10   		10
#define LOAD_RELOAD11   		11
#define LOAD_RELOAD12   		12
#define LOAD_RELOAD13   		13
#define LOAD_RELOAD14   		14
#define LOAD_RELOAD15   		15
#define LOAD_RELOAD16   		16
#define LOAD_RELOAD17   		17
#define LOAD_RELOAD18   		18
#define LOAD_RELOAD19   		19
#define LOAD_RELOAD20   		20
#define LOAD_RELOAD21   		21
#define LOAD_RELOAD22   		22
#define LOAD_RELOAD23   		23

#define VAL_CURRENT     		0
#define VAL_CURRENT0    		0
#define VAL_CURRENT1    		1
#define VAL_CURRENT2    		2
#define VAL_CURRENT3    		3
#define VAL_CURRENT4    		4
#define VAL_CURRENT5    		5
#define VAL_CURRENT6    		6
#define VAL_CURRENT7    		7
#define VAL_CURRENT8    		8
#define VAL_CURRENT9    		9
#define VAL_CURRENT10   		10
#define VAL_CURRENT11   		11
#define VAL_CURRENT12   		12
#define VAL_CURRENT13   		13
#define VAL_CURRENT14   		14
#define VAL_CURRENT15   		15
#define VAL_CURRENT16   		16
#define VAL_CURRENT17   		17
#define VAL_CURRENT18   		18
#define VAL_CURRENT19   		19
#define VAL_CURRENT20   		20
#define VAL_CURRENT21   		21
#define VAL_CURRENT22   		22
#define VAL_CURRENT23   		23

#define CALIB_TENMS      		0
#define CALIB_TENMS0     		0
#define CALIB_TENMS1     		1
#define CALIB_TENMS2     		2
#define CALIB_TENMS3     		3
#define CALIB_TENMS4     		4
#define CALIB_TENMS5     		5
#define CALIB_TENMS6     		6
#define CALIB_TENMS7     		7
#define CALIB_TENMS8     		8
#define CALIB_TENMS9     		9
#define CALIB_TENMS10    		10
#define CALIB_TENMS11    		11
#define CALIB_TENMS12    		12
#define CALIB_TENMS13    		13
#define CALIB_TENMS14    		14
#define CALIB_TENMS15    		15
#define CALIB_TENMS16    		16
#define CALIB_TENMS17    		17
#define CALIB_TENMS18    		18
#define CALIB_TENMS19    		19
#define CALIB_TENMS20    		20
#define CALIB_TENMS21    		21
#define CALIB_TENMS22    		22
#define CALIB_TENMS23    		23
#define CALIB_SKEW				30
#define CALIB_NOREF	    		31


#endif