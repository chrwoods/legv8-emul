#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t* get_bytes_from_file(char* filename) {
  FILE* file = fopen(filename, "rb");
  if (!file) return NULL;
  
  fseek(file, 0, SEEK_END);
  long filelen = ftell(file);
  rewind(file);

  uint8_t* bytes = (uint8_t*) malloc((filelen + 1));
  fread(bytes, filelen, 1, file);
  fclose(file);

  return bytes;
}
