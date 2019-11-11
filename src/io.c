#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include "emulator.h"

uint8_t* get_bytes_from_file(char* filename, long* filelen) {
  FILE* file = fopen(filename, "rb");
  if (!file) return NULL;
  
  fseek(file, 0, SEEK_END);
  *filelen = ftell(file);
  rewind(file);

  uint8_t* bytes = (uint8_t*) malloc((*filelen + 1));
  fread(bytes, *filelen, 1, file);
  fclose(file);

  return bytes;
}

char printable_char(uint8_t c) {
  return isprint(c) ? c : '.';
}

void print_line(char* to_print) {
  printf("%s\n", to_print);
}

void print_register(short num, int64_t content) {
  char* spacing = "  ";
  if (num > 9) spacing = " ";
  printf("X%d:%s%016lx (%ld)\n", num, spacing, (uint64_t)content, content);
}

void hexdump(uint8_t* start, size_t size) {
  for (size_t i = 0; i < size - (size % 16); i += 16) {
    printf("%08x "
	   " %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx "
	   " %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx "
	   " |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",
	   (int32_t) i,
	   start[i +  0], start[i +  1], start[i +  2], start[i +  3],
	   start[i +  4], start[i +  5], start[i +  6], start[i +  7],
	   start[i +  8], start[i +  9], start[i + 10], start[i + 11],
	   start[i + 12], start[i + 13], start[i + 14], start[i + 15],
	   printable_char(start[i +  0]), printable_char(start[i +  1]),
	   printable_char(start[i +  2]), printable_char(start[i +  3]),
	   printable_char(start[i +  4]), printable_char(start[i +  5]),
	   printable_char(start[i +  6]), printable_char(start[i +  7]),
	   printable_char(start[i +  8]), printable_char(start[i +  9]),
	   printable_char(start[i + 10]), printable_char(start[i + 11]),
	   printable_char(start[i + 12]), printable_char(start[i + 13]),
	   printable_char(start[i + 14]), printable_char(start[i + 15]));
  }
  printf("%08x\n", (int32_t) size);
}

void dump(emulator_t* emulator) {
  print_line("Registers:");
  for (int i = 0; i < 32; i++) {
    print_register(i, emulator->registers[i]);
  }
  print_line("");
  print_line("Stack:");
  hexdump(emulator->stack, STACK_SIZE);
  print_line("");
  print_line("Main Memory:");
  hexdump(emulator->memory, MEM_SIZE);
  //TODO: compile machine code into assembly for some godforsaken reason
}
