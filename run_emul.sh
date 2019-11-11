#!/bin/bash

FILE=$1
if [ ! -f main ]; then
  echo "Please compile the program."
  exit 1
fi

if [ ! -f test_files/$FILE.legv8asm.machine ]; then
  echo "File $FILE.legv8asm has not been assembled or does not exist."
  exit 1
fi

./main test_files/$FILE.legv8asm.machine
