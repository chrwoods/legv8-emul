#ifndef OPCODES_H
#define OPCODES_H

/* R Format */
#define OP_ADD "10001011000"
#define OP_ADDS "10101011000"
#define OP_SUB "11001011000"
#define OP_SUBS "11101011000"
#define OP_AND "10001010000"
#define OP_ANDS "11101010000"
#define OP_ORR "10101010000"
#define OP_EOR "11101010000"
#define OP_BR "11010110000"
#define OP_PRNL "11111111100"
#define OP_PRNT "11111111101"
#define OP_DUMP "11111111110"
#define OP_HALT "11111111111"

/* I Format */
#define OP_ADDI "1001000100"
#define OP_ADDIS "1011000100"
#define OP_SUBI "1101000100"
#define OP_SUBIS "1111000100"
#define OP_ANDI "1001001000"
#define OP_ANDIS "1111001000"
#define OP_ORRI "1011001000"
#define OP_EORI "1101001000"

/* D Format */
#define OP_LDUR "11111000010"
#define OP_STUR "11111000000"

#endif