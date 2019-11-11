# legv8-emul
Binary emulator for LEGv8 assembly (written for COM S 321)
By Christopher Woods and Thomas Maloney

In order to run this memory flag, simply run `make` in the topmost directory (the directory containing your src/ and obj/ directories, along with the Makefile. This will compile an executable `main` file that is run by calling `./main <filename>`, where `<filename>` is the path to the binary file of LEGv8 commands that you want to emulate.

There's also a helper script `run_emul.sh`, which when called with `./run_emul.sh <filename>` will run the corresponding `<filename>.legv8asm.machine` file in the `test_files/` directory (if it exists).

All of the instructions specified have been implemented, along with the extra condition code-setting ALU instructions.