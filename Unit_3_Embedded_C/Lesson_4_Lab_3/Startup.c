/*startup.c 
by: Ibrahim Abo Elhassan
*/

#include <stdint.h>

void _Reset_Handler(void);
extern void main(void);

void Default_Handler(void)
{
	_Reset_Handler();
}
void _NMI_Handler(void) __attribute__ ((weak,alias("Default_Handler")));;
void _Hard_Fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));;

// booking 1024 byte located by .bss through un-initialized array of int 256 element.  
static unsigned long Stack_top [256];


void (* const g_p_func_Vectors[])() __attribute__ ((section(".vectors")))  =
{
	(void (*)())  ((unsigned long)Stack_top + sizeof(Stack_top)),
	&_Reset_Handler,
	&_NMI_Handler,
	&_Hard_Fault_Handler
};

/*Extern the symbol from linker file so that the linker dosen't give an error while 
compilng the startup.c*/
extern uint32_t _S_TEXT;
extern uint32_t _E_TEXT;
extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _S_BSS;
extern uint32_t _E_BSS;

void _Reset_Handler(void)
{
	
	/* 1- Copy Data from ROM to SRAM.*/
	uint32_t DATA_SIZE 				= (unsigned char*)&_E_DATA-(unsigned char*)&_S_DATA;
	unsigned char* P_SOURCE 		= (unsigned char*)&_E_TEXT;
	unsigned char* P_DISTINATION 	= (unsigned char*)&_S_DATA;
	
	for(uint32_t i = 0; i<DATA_SIZE;i++)
	{
		*((unsigned char*)P_DISTINATION++) = *((unsigned char*)P_SOURCE++);

	}
	
	/* 2- Reserve a .bss with its size in the SRAM.*/
	uint32_t BSS_SIZE 				= (unsigned char*)&_E_BSS - (unsigned char*)(&_S_BSS);
	unsigned char* P_BSS			= (unsigned char*)&_S_BSS;
	for(uint32_t i = 0; i<BSS_SIZE;i++)
	{
		*((unsigned char*)P_BSS++)= (unsigned char)0;

	}

	/* 3- Jump to the main function.*/
	main();
	
}
