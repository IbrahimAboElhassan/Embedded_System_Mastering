#include <stdio.h>
#include "fifo_.h"

#define width1 5
element_type uart_buffer[width1];

int main() {
    element_type i, temp = 0;
    FIFO_Buf_t FIFO_UART;

    if (FIFO_init(&FIFO_UART, uart_buffer, width1) == FIFO_no_error)
        printf("Fifo init --- Done\n");

    for (i = 0; i < 7; i++) {
        printf("FIFO Enqueue (%x)\n", i);

        if (FIFO_enqueue(&FIFO_UART, i) == FIFO_no_error)
            printf("\t Fifo enqueue --- Done\n");
        else
            printf("\t Fifo enqueue --- failed\n");
    }

    FIFO_print(&FIFO_UART);

    if (FIFO_dequeue(&FIFO_UART, &temp) == FIFO_no_error)
        printf("\t Fifo dequeue %x --- Done\n", temp);
    else
        printf("\t Fifo dequeue --- failed\n");

    if (FIFO_dequeue(&FIFO_UART, &temp) == FIFO_no_error)
        printf("\t Fifo dequeue %x --- Done\n", temp);
    else
        printf("\t Fifo dequeue --- failed\n");

    FIFO_print(&FIFO_UART);

    return 0;
}
