#ifndef IO_H
#define IO_H

#include <stdint.h>
uint8_t* get_bytes_from_file(char* filename);
void hexdump(FILE *f, int8_t *start, size_t size);

#endif
