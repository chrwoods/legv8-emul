#include <stdio.h>
#include <stdint.h>
#include "io.h"

int main(int argc, char *argv[]) {
  if (argc > 1) {
    uint8_t* bytes = get_bytes_from_file(argv[1]);
    printf("%d, %d\n", bytes[0], bytes[1]);
  } else {
    printf("No file was given.\n");
  }
  return 0;
}
