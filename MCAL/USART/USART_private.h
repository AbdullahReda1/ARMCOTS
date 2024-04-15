/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        5 Jun, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         5 Jun, 2023       Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef 	MCAL_USART_USART_PRIVATE_H_
#define 	MCAL_USART_USART_PRIVATE_H_





/******************************Register Description*******************************/

typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}USART_t;

#define USART1_BASE_ADDRESS       0x40011000
#define USART2_BASE_ADDRESS       0x40004400
#define USART6_BASE_ADDRESS       0x40011400

#define USART1 ((volatile USART_t *)USART1_BASE_ADDRESS)
#define USART2 ((volatile USART_t *)USART2_BASE_ADDRESS)
#define USART6 ((volatile USART_t *)USART6_BASE_ADDRESS)


#define SR_PE               0
#define SR_FE               1
#define SR_NF               2
#define SR_ORE              3
#define SR_IDLE             4
#define SR_RXNE             5
#define SR_TC               6
#define SR_TXE              7
#define SR_LBD              8
#define SR_CTS              9

#define BRR_FRC             0
#define BRR_MNTS            4

#define	CR1_SBK				0
#define	CR1_RWU				1
#define	CR1_RE				2
#define	CR1_TE				3
#define	CR1_IDLEIE			4
#define	CR1_RXNEIE			5	
#define	CR1_TCIE			6
#define	CR1_TXEIE			7
#define	CR1_PEIE			8
#define	CR1_PS				9
#define	CR1_PCE				10
#define	CR1_WAKE			11
#define	CR1_M				12
#define	CR1_UE				13
#define	CR1_OVER8			15

#define CR2_ADD             0
#define CR2_LBDL            5
#define CR2_LBDIE           6
#define CR2_LBCL            8
#define CR2_CPHA            9
#define CR2_CPOL            10
#define CR2_CLKEN           11
#define CR2_STOP            12
#define CR2_LINEN           14

#define CR3_EIE             0
#define CR3_IREN            1
#define CR3_IRLP            2
#define CR3_HDSEL           3
#define CR3_NACK            4
#define CR3_SCEN            5
#define CR3_DMAR            6
#define CR3_DMAT            7
#define CR3_RTSE            8
#define CR3_CTSE            9
#define CR3_CTSIE           10
#define CR3_ONEBIT          11

#define GTPR_PSC            0
#define GTPR_GT             8


#endif