/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        22 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         22 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef MCAL_MPU_MPU_INTERFACE_H
#define MCAL_MPU_MPU_INTERFACE_H


/* Instruction Fetch */
#define INSTRUCTION_FETCHES_ENABLE      0
#define INSTRUCTION_FETCHES_DISABLE     1

/* Access Permission */
#define PRIVILEGED_UNPRIVILEGED_NO_ACCESS         0b000
#define PRIVILEGED_RW_UNPRIVILEGED_NO_ACCESS      0b001
#define PRIVILEGED_RW_UNPRIVILEGED_RO             0b010
#define PRIVILEGED_RW_UNPRIVILEGED_RW             0b011
#define PRIVILEGED_RO_UNPRIVILEGED_NO_ACCESS      0b101
#define PRIVILEGED_RO_UNPRIVILEGED_RO             0b111

/* Memory Attribute */
#define STRONGLY_ORDERED_MEMORY_SHAREABLE             0b000000
#define DEVICE_MEMORY_SHAREABLE                       0b000101
#define DEVICE_MEMORY_NOT_SHAREABLE                   0b010000
#define FLASH_MEMORY_NOT_SHAREABLE_WT                 0b000010
#define INTERNAL_SRAM_MEMORY_SHAREABLE_WT             0b000110
#define NORMAL_MEMORY_NOT_SHAREABLE_WB                0b000011
#define EXTERNAL_SRAM_MEMORY_SHAREABLE_WB             0b000111
#define NORMAL_MEMORY_NOT_SHAREABLE_NONCACHABLE       0b001000
#define NORMAL_MEMORY_SHAREABLE_NONCACHABLE           0b001100
#define NORMAL_MEMORY_NOT_SHAREABLE_WB_WR_ALLOCATE    0b001011
#define NORMAL_MEMORY_SHAREABLE_WB_WR_ALLOCATE        0b001111
#define NORMAL_MEMORY_NOT_SHAREABLE_NONCACHABLE_C     0b100000
#define NORMAL_MEMORY_SHAREABLE_NONCACHABLE_C         0b100100
#define NORMAL_MEMORY_NOT_SHAREABLE_WB_WR_ALLOCATE_C  0b101001
#define NORMAL_MEMORY_SHAREABLE_WB_WR_ALLOCATE_C      0b101101
#define NORMAL_MEMORY_NOT_SHAREABLE_WT_NO_ALLOCATE    0b110010
#define NORMAL_MEMORY_SHAREABLE_WT_NO_ALLOCATE        0b110110
#define NORMAL_MEMORY_NOT_SHAREABLE_WB_NO_ALLOCATE    0b111011
#define NORMAL_MEMORY_SHAREABLE_WB_NO_ALLOCATE        0b111111

/* Region Size */
#define SIZE_32B      4
#define SIZE_64B      5
#define SIZE_128B     6
#define SIZE_256B     7
#define SIZE_512B     8
#define SIZE_1K       9
#define SIZE_2K       10
#define SIZE_4K       11
#define SIZE_8K       12
#define SIZE_16K      13
#define SIZE_32K      14
#define SIZE_64K      15
#define SIZE_128K     16
#define SIZE_256K     17
#define SIZE_512K     18
#define SIZE_1M       19
#define SIZE_2M       20
#define SIZE_4M       21
#define SIZE_8M       22
#define SIZE_16M      23
#define SIZE_32M      24
#define SIZE_64M      25
#define SIZE_128M     26
#define SIZE_256M     27
#define SIZE_512M     28
#define SIZE_1G       29
#define SIZE_2G       30
#define SIZE_4G       31

/* SubRegion Number */
#define SUBREGIONS_0             0b11111111
#define DOWN_SUBREGIONS_1        0b11111110
#define DOWN_SUBREGIONS_2        0b11111100
#define DOWN_SUBREGIONS_3        0b11111000
#define DOWN_SUBREGIONS_4        0b11110000
#define DOWN_SUBREGIONS_5        0b11100000
#define DOWN_SUBREGIONS_6        0b11000000
#define DOWN_SUBREGIONS_7        0b10000000
#define UP_SUBREGIONS_1          0b01111111
#define UP_SUBREGIONS_2          0b00111111
#define UP_SUBREGIONS_3          0b00011111
#define UP_SUBREGIONS_4          0b00001111
#define UP_SUBREGIONS_5          0b00000111
#define UP_SUBREGIONS_6          0b00000011
#define UP_SUBREGIONS_7          0b00000001
#define SUBREGIONS_8             0b00000000


void MMPU_voidInit(void);

u8 MMPU_u8GetSeparationofMemoryMapStatus(void);
u8 MMPU_u8GetNumberofDataRegions(void);
u8 MMPU_u8GetNumberofInstructionRegions(void);

void MMPU_voidEnableMPU(void);
void MMPU_voidEnableMPUDuringHandler(void);
void MMPU_voidEnablePriviligedSoftwareAccess(void);
void MMPU_voidDisableMPU(void);
void MMPU_voidDisableMPUDuringHandler(void);
void MMPU_voidDisablePriviligedSoftwareAccess(void);

void MMPU_voidSetRegionNumper(u8 Copy_u8RegionNumper);
u8 MMPU_u8GetRegionNumper(void);

void MMPU_voidSetRegionBaseAddress(u32 Copy_u32RegionBaseAddress);
void MMPU_voidUpdateRegionBaseAddress(u8 Copy_u8RegionNumper, u32 Copy_u32RegionBaseAddress);
void MMPU_voidUpdateSimultaneouslyRegions(u8* Copy_pu8RegionNumperArray, u32* Copy_pu32RegionBaseAddressArray, u8 Copy_u8NumperofBaseAddresses);

void MMPU_voidSetRegionAttributes(u8 Copy_u8InstructionFetch, u8 Copy_u8AccessPermission, u8 Copy_u8MemoryAttribute);
void MMPU_voidSetRegionSize(u8 Copy_u8RegionSize);
void MMPU_voidSetSubRegion(u8 Copy_u8SubRegionNumber);
void MMPU_voidEnableRegion(void);
void MMPU_voidDisableRegion(void);
void MMPU_voidSetSizeSubregionandAttributes(u8 Copy_u8InstructionFetch, u8 Copy_u8AccessPermission, u8 Copy_u8MemoryAttribute, u8 Copy_u8SubRegionNumber, u8 Copy_u8RegionSize);
void MMPU_voidSetSizeSubregionandAttributesSimultaneously(u8* Copy_pu8InstructionFetch, u8* Copy_pu8AccessPermission, u8* Copy_pu8MemoryAttribute, u8* Copy_pu8SubRegionNumber, u8* Copy_pu8RegionSize, u8 Copy_u8NumperofBaseAddresses);

void MMPU_voidStartRegion(u8 Copy_u8RegionNumper, u32 Copy_u32RegionBaseAddress, u8 Copy_u8InstructionFetch, u8 Copy_u8AccessPermission, u8 Copy_u8MemoryAttribute, u8 Copy_u8SubRegionNumber, u8 Copy_u8RegionSize);
void MMPU_voidDisableUnusedRegions(u8 Copy_u8FirstUnusedRegion, u8 Copy_u8LastUnusedRegion);


#endif