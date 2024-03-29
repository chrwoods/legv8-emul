#ifndef IO_H
#define IO_H

#include <stdlib.h>
#include <stdint.h>
#include "emulator.h"
uint8_t* get_bytes_from_file(char* filename, long* filelen);
void print_line(char* to_print);
void print_register(short num, int64_t content);
void dump(emulator_t* emulator);
void hexdump(uint8_t* start, size_t size);

#endif
