/* startup cortex_M3
by: Ibrahim Abo Elhassan */

.section .vectors
.word 0x20001000   /*stack top address*/
.word _reset
.word _Vector_Handler         
.word _Vector_Handler	      

							 


.section .text
_reset:
	bl main
	b .
.thumb_func 				
_Vector_Handler:
	b _reset
