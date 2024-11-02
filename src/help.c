//help.c compiler gcc 11.7, OS win7, help.exe provides help for assembler language the commodore 64 processor. github Disassembler6510
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char * argv[])
{
	int iOpc[151] = 
	{
		41, 37, 53, 45, 61, 57, 33, 49, 73, 69, 85, 77, 93, 89, 65, 81, 9, 5, 21, 13, 29, 25, 1, 17, 10, 6, 22, 14, 30, 74, 70, 86, 
		78, 94, 42, 38, 54, 46, 62, 106, 102, 118, 110, 126, 16, 48, 80, 112, 144, 176, 208, 240, 201, 197, 213, 205, 221, 217, 193, 209, 224, 228, 236, 192, 
		196, 204, 36, 44, 24, 56, 88, 120, 216, 248, 184, 76, 108, 32, 96, 64, 105, 101, 117, 109, 125, 121, 97, 113, 233, 229, 245, 237, 253, 249, 225, 241, 
		169, 165, 181, 173, 189, 185, 161, 177, 162, 166, 182, 174, 190, 160, 164, 180, 172, 188, 133, 149, 141, 157, 153, 129, 145, 134, 150, 142, 132, 148, 140, 198, 
		214, 206, 222, 230, 246, 238, 254, 170, 168, 138, 152, 202, 136, 232, 200, 72, 8, 154, 104, 186, 40, 0, 234
	};
	char *cMne[] = 
	{
		"and", "and", "and", "and", "and", "and", "and", "and", "eor", "eor", "eor", "eor", "eor", "eor", "eor", "eor", "ora", "ora", "ora", "ora", "ora", "ora", "ora", "ora", "asl", 
		"asl", "asl", "asl", "asl", "lsr", "lsr", "lsr", "lsr", "lsr", "rol", "rol", "rol", "rol", "rol", "ror", "ror", "ror", "ror", "ror", "bpl", "bmi", "bvc", "bvs", "bcc", "bcs", 
		"bne", "beq", "cmp", "cmp", "cmp", "cmp", "cmp", "cmp", "cmp", "cmp", "cpx", "cpx", "cpx", "cpy", "cpy", "cpy", "bit", "bit", "clc", "sec", "cli", "sei", "cld", "sed", "clv", 
		"jmp", "jmp", "jsr", "rts", "rti", "adc", "adc", "adc", "adc", "adc", "adc", "adc", "adc", "sbc", "sbc", "sbc", "sbc", "sbc", "sbc", "sbc", "sbc", "lda", "lda", "lda", "lda", 
		"lda", "lda", "lda", "lda", "ldx", "ldx", "ldx", "ldx", "ldx", "ldy", "ldy", "ldy", "ldy", "ldy", "sta", "sta", "sta", "sta", "sta", "sta", "sta", "stx", "stx", "stx", "sty", 
		"sty", "sty", "dec", "dec", "dec", "dec", "inc", "inc", "inc", "inc", "tax", "tay", "txa", "tya", "dex", "dey", "inx", "iny", "pha", "php", "txs", "pla", "tsx", "plp", "brk", 
		"nop"
	};
	int iLen[151] = 
	{
		2, 2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 3, 3, 3, 2, 2, 1, 2, 2, 3, 3, 1, 2, 2, 3, 3, 1, 2, 2, 3, 3, 1, 2, 2, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 2, 2, 
		2, 2, 3, 2, 2, 3, 2, 3, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 2, 2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 3, 3, 2, 2, 2, 3, 3, 2, 2, 3, 3, 3, 2, 
		2, 2, 2, 3, 2, 2, 3, 2, 2, 3, 3, 2, 2, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	};
	char *cMod[] = 
	{
		"Immediate   ", "Zero Page   ", "Zero Page,X ", "Absolute    ", "Absolute,X  ", "Absolute,Y  ", "(Indirect,X)", "(Indirect),Y", "Immediate   ", "Zero Page   ", "Zero Page,X ", 
		"Absolute    ", "Absolute,X  ", "Absolute,Y  ", "(Indirect,X)", "(Indirect),Y", "Immediate   ", "Zero Page   ", "Zero Page,X ", "Absolute    ", "Absolute,X  ", "Absolute,Y  ", 
		"(Indirect,X)", "(Indirect),Y", "Accumulator ", "Zero Page   ", "Zero Page,X ", "Absolute    ", "Absolute,X  ", "Accumulator ", "Zero Page   ", "Zero Page,X ", "Absolute    ", 
		"Absolute,X  ", "Accumulator ", "Zero Page   ", "Zero Page,X ", "Absolute    ", "Absolute,X  ", "Accumulator ", "Zero Page   ", "Zero Page,X ", "Absolute    ", "Absolute,X  ", 
		"Relative    ", "Relative    ", "Relative    ", "Relative    ", "Relative    ", "Relative    ", "Relative    ", "Relative    ", "Immediate   ", "Zero Page   ", "Zero Page,X ", 
		"Absolute    ", "Absolute,X  ", "Absolute,Y  ", "(Indirect,X)", "(Indirect),Y", "Immediate   ", "Zero Page   ", "Absolute    ", "Immediate   ", "Zero Page   ", "Absolute    ", 
		"Zero Page   ", "Absolute    ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Absolute    ", "Indirect    ", 
		"Absolute    ", "Implied     ", "Implied     ", "Immediate   ", "Zero Page   ", "Zero Page,X ", "Absolute    ", "Absolute,X  ", "Absolute,Y  ", "(Indirect,X)", "(Indirect),Y", 
		"Immediate   ", "Zero Page   ", "Zero Page,X ", "Absolute    ", "Absolute,X  ", "Absolute,Y  ", "(Indirect,X)", "(Indirect),Y", "Immediate   ", "Zero Page   ", "Zero Page,X ", 
		"Absolute    ", "Absolute,X  ", "Absolute,Y  ", "(Indirect,X)", "(Indirect),Y", "Immediate   ", "Zero Page   ", "Zero Page,Y ", "Absolute    ", "Absolute,Y  ", "Immediate   ", 
		"Zero Page   ", "Zero Page,X ", "Absolute    ", "Absolute,X  ", "Zero Page   ", "Zero Page,X ", "Absolute    ", "Absolute,X  ", "Absolute,Y  ", "(Indirect,X)", "(Indirect),Y", 
		"Zero Page   ", "Zero Page,Y ", "Absolute    ", "Zero Page   ", "Zero Page,X ", "Absolute    ", "Zero Page   ", "Zero Page,X ", "Absolute    ", "Absolute,X  ", "Zero Page   ", 
		"Zero Page,X ", "Absolute    ", "Absolute,X  ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", 
		"Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     "
	};
	char *cAbbrmod[] = 
	{
		"imm", "zer", "zex", "abs", "abx", "aby", "inx", "iny", "imm", "zer", "zex", "abs", "abx", "abY", "inx", "iny", "imm", "zer", "zex", "abs", "abx", "aby", "inx", "iny", "acc", 
		"zer", "zex", "abs", "abx", "acc", "zer", "zex", "abs",	"abx", "acc", "zer", "zex", "abs", "abx", "acc", "zer", "zex", "abs", "abx", "   ", "   ", "   ", "   ", "   ", "   ", 
		"   ", "   ", "imm", "zer", "zex", "abs", "abx", "aby", "inx", "iny", "imm", "zer", "abs", "imm", "zer", "abs", "zer", "abs", "   ", "   ", "   ", "   ", "   ", "   ", "   ", 
		"abs", "ind", "abs", "   ", "   ", "imm", "zer", "zex", "abs", "abx", "aby", "inx", "iny", "imm", "zer", "zex", "abs", "abx", "aby", "inx", "iny", "imm", "zer", "zex", "abs", 
		"abx", "aby", "inx", "iny", "imm", "zer", "zey", "abs", "aby", "imm", "zer", "zex", "abs", "abx", "zer", "zex", "abs", "abx", "aby", "inx", "iny", "zer", "zey", "abs", "zer", 
		"zex", "abs", "zer", "zex", "abs", "abx", "zer", "zex", "abs", "abx", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", 
		"   "
	};
	char *cDesc[] = 
	{
		"Bitwise AND with Accumulator         ", "Bitwise AND with Accumulator         ", "Bitwise AND with Accumulator         ", "Bitwise AND with Accumulator         ", 
		"Bitwise AND with Accumulator         ", "Bitwise AND with Accumulator         ", "Bitwise AND with Accumulator         ", "Bitwise AND with Accumulator         ", 
		"Bitwise Exclusive-OR with Accumulator", "Bitwise Exclusive-OR with Accumulator", "Bitwise Exclusive-OR with Accumulator", "Bitwise Exclusive-OR with Accumulator", 
		"Bitwise Exclusive-OR with Accumulator", "Bitwise Exclusive-OR with Accumulator", "Bitwise Exclusive-OR with Accumulator", "Bitwise Exclusive-OR with Accumulator", 
		"Bitwise OR with Accumulator          ", "Bitwise OR with Accumulator          ", "Bitwise OR with Accumulator          ", "Bitwise OR with Accumulator          ", 
		"Bitwise OR with Accumulator          ", "Bitwise OR with Accumulator          ", "Bitwise OR with Accumulator          ", "Bitwise OR with Accumulator          ", 
		"Arithmetic Shift Left                ", "Arithmetic Shift Left                ", "Arithmetic Shift Left                ", "Arithmetic Shift Left                ", 
		"Arithmetic Shift Left                ", "Logical Shift Right                  ", "Logical Shift Right                  ", "Logical Shift Right                  ", 
		"Logical Shift Right                  ", "Logical Shift Right                  ", "Rotate Left                          ", "Rotate Left                          ", 
		"Rotate Left                          ", "Rotate Left                          ", "Rotate Left                          ", "Rotate Right                         ", 
		"Rotate Right                         ", "Rotate Right                         ", "Rotate Right                         ", "Rotate Right                         ", 
		"Branch on Plus                       ", "Branch on Minus                      ", "Branch on Overflow Clear             ", "Branch on Overflow Set               ", 
		"Branch on Carry Clear                ", "Branch on Carry Set                  ", "Branch on Not Equal                  ", "Branch on Equal                      ", 
		"Compare Accumulator                  ", "Compare Accumulator                  ", "Compare Accumulator                  ", "Compare Accumulator                  ", 
		"Compare Accumulator                  ", "Compare Accumulator                  ", "Compare Accumulator                  ", "Compare Accumulator                  ", 
		"Compare X Register                   ", "Compare X Register                   ", "Compare X Register                   ", "Compare Y Register                   ", 
		"Compare Y Register                   ", "Compare Y Register                   ", "Test Bits                            ", "Test Bits                            ", 
		"Clear Carry                          ", "Set Carry                            ", "Clear Interrupt                      ", "Set Interrupt                        ", 
		"Clear Decimal                        ", "Set Decimal                          ", "Clear Overflow                       ", "Jump                                 ", 
		"Jump                                 ", "Jump Saving Return                   ", "Return to Saved                      ", "Return from Interrupt                ", 
		"Add with Carry                       ", "Add with Carry                       ", "Add with Carry                       ", "Add with Carry                       ", 
		"Add with Carry                       ", "Add with Carry                       ", "Add with Carry                       ", "Add with Carry                       ", 
		"Subtract with Carry                  ", "Subtract with Carry                  ", "Subtract with Carry                  ", "Subtract with Carry                  ", 
		"Subtract with Carry                  ", "Subtract with Carry                  ", "Subtract with Carry                  ", "Subtract with Carry                  ", 
		"Load Accumulator                     ", "Load Accumulator                     ", "Load Accumulator                     ", "Load Accumulator                     ", 
		"Load Accumulator                     ", "Load Accumulator                     ", "Load Accumulator                     ", "Load Accumulator                     ", 
		"Load X Register                      ", "Load X Register                      ", "Load X Register                      ", "Load X Register                      ", 
		"Load X Register                      ", "Load Y Register                      ", "Load Y Register                      ", "Load Y Register                      ", 
		"Load Y Register                      ", "Load Y Register                      ", "Store Accumulator                    ", "Store Accumulator                    ", 
		"Store Accumulator                    ", "Store Accumulator                    ", "Store Accumulator                    ", "Store Accumulator                    ", 
		"Store Accumulator                    ", "Store X Register                     ", "Store X Register                     ", "Store X Register                     ", 
		"Store Y Register                     ", "Store Y Register                     ", "Store Y Register                     ", "Decrement Memory                     ", 
		"Decrement Memory                     ", "Decrement Memory                     ", "Decrement Memory                     ", "Increment Memory                     ", 
		"Increment Memory                     ", "Increment Memory                     ", "Increment Memory                     ", "Transfer A to X                      ", 
		"Transfer A to Y                      ", "Tranfer X to A                       ", "Transfer Y to A                      ", "Decrement X                          ", 
		"Decrement Y                          ", "Increment X                          ", "Increment Y                          ", "Push Accumulator                     ", 
		"Push Processor Status                ", "Transfer X to Stack Pointer          ", "Pull Accumulator                     ", "Transfer Stack Pointer to X          ", 
		"Pull Processor Status                ", "Break                                ", "No Operation                         "
	};
	char *sCat[] = 
	{
		"Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", 
		"Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", 
		"Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", 
		"Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", 
		"Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", 
		"Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", 
		"Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", "Bitwise Instructions   ", 
		"Bitwise Instructions   ", "Bitwise Instructions   ", "Branch Instructions    ", "Branch Instructions    ", "Branch Instructions    ", "Branch Instructions    ", 
		"Branch Instructions    ", "Branch Instructions    ", "Branch Instructions    ", "Branch Instructions    ", "Compare Instructions   ", "Compare Instructions   ", 
		"Compare Instructions   ", "Compare Instructions   ", "Compare Instructions   ", "Compare Instructions   ", "Compare Instructions   ", "Compare Instructions   ", 
		"Compare Instructions   ", "Compare Instructions   ", "Compare Instructions   ", "Compare Instructions   ", "Compare Instructions   ", "Compare Instructions   ", 
		"Compare Instructions   ", "Compare Instructions   ", "Flag Instructions      ", "Flag Instructions      ", "Flag Instructions      ", "Flag Instructions      ", 
		"Flag Instructions      ", "Flag Instructions      ", "Flag Instructions      ", "Jump Instructions      ", "Jump Instructions      ", "Jump Instructions      ", 
		"Jump Instructions      ", "Jump Instructions      ", "Math Instructions      ", "Math Instructions      ", "Math Instructions      ", "Math Instructions      ", 
		"Math Instructions      ", "Math Instructions      ", "Math Instructions      ", "Math Instructions      ", "Math Instructions      ", "Math Instructions      ", 
		"Math Instructions      ", "Math Instructions      ", "Math Instructions      ", "Math Instructions      ", "Math Instructions      ", "Math Instructions      ", 
		"Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", 
		"Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", 
		"Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", 
		"Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", 
		"Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", 
		"Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", 
		"Memory Instructions    ", "Memory Instructions    ", "Memory Instructions    ", "Register Instructions  ", "Register Instructions  ", "Register Instructions  ", 
		"Register Instructions  ", "Register Instructions  ", "Register Instructions  ", "Register Instructions  ", "Register Instructions  ", "Stack Instructions     ", 
		"Stack Instructions     ", "Stack Instructions     ", "Stack Instructions     ", "Stack Instructions     ", "Stack Instructions     ", "Other Instructions     ", 
		"Other Instructions     "
	};
	char *cSyn[] = 
	{
		"AND #$44     ", "AND $44      ", "AND $44,X    ", "AND $4400    ", "AND $4400,X  ", "AND $4400,Y  ", "AND ($44,X)  ", "AND ($44),Y  ", "EOR #$44     ", "EOR $44      ", 
		"EOR $44,X    ", "EOR $4400    ", "EOR $4400,X  ", "EOR $4400,Y  ", "EOR ($44,X)  ", "EOR ($44),Y  ", "ORA #$44     ", "ORA $44      ", "ORA $44,X    ", "ORA $4400    ", 
		"ORA $4400,X  ", "ORA $4400,Y  ", "ORA ($44,X)  ", "ORA ($44),Y  ", "ASL A        ", "ASL $44      ", "ASL $44,X    ", "ASL $4400    ", "ASL $4400,X  ", "LSR A        ", 
		"LSR $44      ", "LSR $44,X    ", "LSR $4400    ", "LSR $4400,X  ", "ROL A        ", "ROL $44      ", "ROL $44,X    ", "ROL $4400    ", "ROL $4400,X  ", "ROR A        ", 
		"ROR $44      ", "ROR $44,X    ", "ROR $4400    ", "ROR $4400,X  ", "BPL #$44     ", "BMI #$44     ", "BVC #$44     ", "BVS #$44     ", "BCC #$44     ", "BCS #$44     ", 
		"BNE #$44     ", "BEQ #$44     ", "CMP #$44     ", "CMP $44      ", "CMP $44,X    ", "CMP $4400    ", "CMP $4400,X  ", "CMP $4400,Y  ", "CMP ($44,X)  ", "CMP ($44),Y  ", 
		"CPX #$44     ", "CPX $44      ", "CPX $4400    ", "CPY #$44     ", "CPY $44      ", "CPY $4400    ", "BIT $44      ", "BIT $4400    ", "CLC          ", "SEC          ", 
		"CLI          ", "SEI          ", "CLD          ", "SED          ", "CLV          ", "JMP $5597    ", "JMP ($5597)  ", "JSR $5597    ", "RTS          ", "RTI          ", 
		"ADC #$44     ", "ADC $44      ", "ADC $44,X    ", "ADC $4400    ", "ADC $4400,X  ", "ADC $4400,Y  ", "ADC ($44,X)  ", "ADC ($44),Y  ", "SBC #$44     ", "SBC $44      ", 
		"SBC $44,X    ", "SBC $4400    ", "SBC $4400,X  ", "SBC $4400,Y  ", "SBC ($44,X)  ", "SBC ($44),Y  ", "LDA #$44     ", "LDA $44      ", "LDA $44,X    ", "LDA $4400    ", 
		"LDA $4400,X  ", "LDA $4400,Y  ", "LDA ($44,X)  ", "LDA ($44),Y  ", "LDX #$44     ", "LDX $44      ", "LDX $44,Y    ", "LDX $4400    ", "LDX $4400,Y  ", "LDY #$44     ", 
		"LDY $44      ", "LDY $44,X    ", "LDY $4400    ", "LDY $4400,X  ", "STA $44      ", "STA $44,X    ", "STA $4400    ", "STA $4400,X  ", "STA $4400,Y  ", "STA ($44,X)  ", 
		"STA ($44),Y  ", "STX $44      ", "STX $44,Y    ", "STX $4400    ", "STY $44      ", "STY $44,X    ", "STY $4400    ", "DEC $44      ", "DEC $44,X    ", "DEC $4400    ", 
		"DEC $4400,X  ", "INC $44      ", "INC $44,X    ", "INC $4400    ", "INC $4400,X  ", "TAX          ", "TAY          ", "TXA          ", "TYA          ", "DEX          ", 
		"DEY          ", "INX          ", "INY          ", "PHA          ", "PHP          ", "TXS          ", "PLA          ", "TSX          ", "PLP          ", "BRK          ", 
		"NOP          "
	};
	char *sExt[] = 
	{
		"Take the operand for calculation immediate.", "Take the operand as zero page address. ", "Take the operand as zero page address plus X. ", "Take the operand as address. ", 
		"Take the operand as address plus X. ", "Take the operand as address plus Y. ", "Take the operand as zero page address plus X. ", "Take the operand as zero page address, add Y. ", 
		"Take the operand for calculation immediate.", "Take the operand as zero page address.  ", "Take the operand as zero page address plus X. ", "Take the operand as address. ", 
		"Take the operand as address plus X. ", "Take the operand as address plus Y. ", "Take the operand as zero page address plus X. ", "Take the operand as zero page address, add Y. ", 
		"Take the operand for calculation immediate.", "Take the operand as zero page address.  ", "Take the operand as zero page address plus X. ", "Take the operand as address. ", 
		"Take the operand as address plus X. ", "Take the operand as address plus Y. ", "Take the operand plus X as zero page address. ", "Take the operand as zero page address, add Y to the contents.  ", 
		"ASL shifts all bits left one position. 0 is shifted into bit 0 and the original bit 7 is shifted into the Carry.", 
		"ASL shifts all bits left one position. 0 is shifted into bit 0 and the original bit 7 is shifted into the Carry.", 
		"ASL shifts all bits left one position. 0 is shifted into bit 0 and the original bit 7 is shifted into the Carry.", 
		"ASL shifts all bits left one position. 0 is shifted into bit 0 and the original bit 7 is shifted into the Carry.", 
		"ASL shifts all bits left one position. 0 is shifted into bit 0 and the original bit 7 is shifted into the Carry.", 
		"LSR shifts all bits right one position. 0 is shifted into bit 7 and the original bit 0 is shifted into the Carry.", 
		"LSR shifts all bits right one position. 0 is shifted into bit 7 and the original bit 0 is shifted into the Carry.", 
		"LSR shifts all bits right one position. 0 is shifted into bit 7 and the original bit 0 is shifted into the Carry.", 
		"LSR shifts all bits right one position. 0 is shifted into bit 7 and the original bit 0 is shifted into the Carry.", 
		"LSR shifts all bits right one position. 0 is shifted into bit 7 and the original bit 0 is shifted into the Carry.", 
		"ROL shifts all bits left one position. The Carry is shifted into bit 0 and the original bit 7 is shifted into the Carry.", 
		"ROL shifts all bits left one position. The Carry is shifted into bit 0 and the original bit 7 is shifted into the Carry.", 
		"ROL shifts all bits left one position. The Carry is shifted into bit 0 and the original bit 7 is shifted into the Carry.", 
		"ROL shifts all bits left one position. The Carry is shifted into bit 0 and the original bit 7 is shifted into the Carry.", 
		"ROL shifts all bits left one position. The Carry is shifted into bit 0 and the original bit 7 is shifted into the Carry.", 
		"ROR shifts all bits right one position. The Carry is shifted into bit 7 and the original bit 0 is shifted into the Carry.", 
		"ROR shifts all bits right one position. The Carry is shifted into bit 7 and the original bit 0 is shifted into the Carry.", 
		"ROR shifts all bits right one position. The Carry is shifted into bit 7 and the original bit 0 is shifted into the Carry.", 
		"ROR shifts all bits right one position. The Carry is shifted into bit 7 and the original bit 0 is shifted into the Carry.", 
		"ROR shifts all bits right one position. The Carry is shifted into bit 7 and the original bit 0 is shifted into the Carry.", 
		"Conditional jump counting from the next statement. Operator 0 - 127 jump forward, operator 128-255 jump backward. ", 
		"Conditional jump counting from the next statement. Operator 0 - 127 jump forward, operator 128-255 jump backward. ", 
		"Conditional jump counting from the next statement. Operator 0 - 127 jump forward, operator 128-255 jump backward. ", 
		"Conditional jump counting from the next statement. Operator 0 - 127 jump forward, operator 128-255 jump backward. ", 
		"Conditional jump counting from the next statement. Operator 0 - 127 jump forward, operator 128-255 jump backward. ", 
		"Conditional jump counting from the next statement. Operator 0 - 127 jump forward, operator 128-255 jump backward. ", 
		"Conditional jump counting from the next statement. Operator 0 - 127 jump forward, operator 128-255 jump backward. ", 
		"Conditional jump counting from the next statement. Operator 0 - 127 jump forward, operator 128-255 jump backward. ", 
		"Compare sets processor flags as if a subtraction had been carried out. If the accumulator and the compared value are equal, the result of the subtraction is zero and the Zero (Z) flag is set. If the accumulator is equal or greater than the compared value, the Carry (C) flag is set.", 
		"Compare sets processor flags as if a subtraction had been carried out. If the accumulator and the compared value are equal, the result of the subtraction is zero and the Zero (Z) flag is set. If the accumulator is equal or greater than the compared value, the Carry (C) flag is set.",
		"Compare sets processor flags as if a subtraction had been carried out. If the accumulator and the compared value are equal, the result of the subtraction is zero and the Zero (Z) flag is set. If the accumulator is equal or greater than the compared value, the Carry (C) flag is set.", 
		"Compare sets processor flags as if a subtraction had been carried out. If the accumulator and the compared value are equal, the result of the subtraction is zero and the Zero (Z) flag is set. If the accumulator is equal or greater than the compared value, the Carry (C) flag is set.",
		"Compare sets processor flags as if a subtraction had been carried out. If the accumulator and the compared value are equal, the result of the subtraction is zero and the Zero (Z) flag is set. If the accumulator is equal or greater than the compared value, the Carry (C) flag is set.",
		"Compare sets processor flags as if a subtraction had been carried out. If the accumulator and the compared value are equal, the result of the subtraction is zero and the Zero (Z) flag is set. If the accumulator is equal or greater than the compared value, the Carry (C) flag is set.",
		"Compare sets processor flags as if a subtraction had been carried out. If the accumulator and the compared value are equal, the result of the subtraction is zero and the Zero (Z) flag is set. If the accumulator is equal or greater than the compared value, the Carry (C) flag is set.",
		"Compare sets processor flags as if a subtraction had been carried out. If the accumulator and the compared value are equal, the result of the subtraction is zero and the Zero (Z) flag is set. If the accumulator is equal or greater than the compared value, the Carry (C) flag is set.",
		"Compare sets processor flags as if a subtraction had been carried out. If the accumulator and the compared value are equal, the result of the subtraction is zero and the Zero (Z) flag is set. If the accumulator is equal or greater than the compared value, the Carry (C) flag is set.",
		"Compare sets processor flags as if a subtraction had been carried out. If the accumulator and the compared value are equal, the result of the subtraction is zero and the Zero (Z) flag is set. If the accumulator is equal or greater than the compared value, the Carry (C) flag is set.",
		"Compare sets processor flags as if a subtraction had been carried out. If the accumulator and the compared value are equal, the result of the subtraction is zero and the Zero (Z) flag is set. If the accumulator is equal or greater than the compared value, the Carry (C) flag is set.",
		"Compare sets processor flags as if a subtraction had been carried out. If the accumulator and the compared value are equal, the result of the subtraction is zero and the Zero (Z) flag is set. If the accumulator is equal or greater than the compared value, the Carry (C) flag is set.",
		"Compare sets processor flags as if a subtraction had been carried out. If the accumulator and the compared value are equal, the result of the subtraction is zero and the Zero (Z) flag is set. If the accumulator is equal or greater than the compared value, the Carry (C) flag is set.",
		"Compare sets processor flags as if a subtraction had been carried out. If the accumulator and the compared value are equal, the result of the subtraction is zero and the Zero (Z) flag is set. If the accumulator is equal or greater than the compared value, the Carry (C) flag is set.",
		"BIT sets the Z flag as though the value in the address tested were ANDed with the accumulator. The N and V flags are set equal to bits 7 and 6 respectively of the value in the tested address.", 
		"BIT sets the Z flag as though the value in the address tested were ANDed with the accumulator. The N and V flags are set equal to bits 7 and 6 respectively of the value in the tested address.", 
		"Clear flag in status register", "Set flag in status register", "Clear flag in status register", "Set flag in status register", "Clear flag in status register", "Set flag in status register", 
		"Clear flag in status register", 
		"JMP loads the program counter with the absolute address, or the address stored at the memory location of the indirect address. Program execution proceeds from the new program counter value.", 
		"JMP loads the program counter with the absolute address, or the address stored at the memory location of the indirect address. Program execution proceeds from the new program counter value.", 
		"JSR pushes the address-1 of the next operation to the stack before transferring the value of the argument to the program counter. JSR behaves just like a JMP, but saves the return address to the stack first, thus creating a subroutine. Subroutines are normally terminated by an RTS instruction.",
		"RTS pulls the top two bytes off the stack (low byte first) and transfers them to the program counter. The program counter is incremented by one and then execution proceeds from there. RTS is typically used in combination with a JSR which saves the return address-1 to the stack.", 
		"RTI retrieves the Processor Status byte and Program Counter from the stack in that order. Interrupts push the program counter first and then the processor status. Unlike RTS, the return address on the stack is the actual address rather than the address-1.", 
		"ADC behavior depends on the state of the decimal flag. In decimal mode, the values upon which the addition is performed are interpreted as packed BCD (Binary Coded Decimal). There is no way to add without the carry.", 
		"ADC behavior depends on the state of the decimal flag. In decimal mode, the values upon which the addition is performed are interpreted as packed BCD (Binary Coded Decimal). There is no way to add without the carry.", 
		"ADC behavior depends on the state of the decimal flag. In decimal mode, the values upon which the addition is performed are interpreted as packed BCD (Binary Coded Decimal). There is no way to add without the carry.", 
		"ADC behavior depends on the state of the decimal flag. In decimal mode, the values upon which the addition is performed are interpreted as packed BCD (Binary Coded Decimal). There is no way to add without the carry.",
		"ADC behavior depends on the state of the decimal flag. In decimal mode, the values upon which the addition is performed are interpreted as packed BCD (Binary Coded Decimal). There is no way to add without the carry.",
		"ADC behavior depends on the state of the decimal flag. In decimal mode, the values upon which the addition is performed are interpreted as packed BCD (Binary Coded Decimal). There is no way to add without the carry.",
		"ADC behavior depends on the state of the decimal flag. In decimal mode, the values upon which the addition is performed are interpreted as packed BCD (Binary Coded Decimal). There is no way to add without the carry.",
		"ADC behavior depends on the state of the decimal flag. In decimal mode, the values upon which the addition is performed are interpreted as packed BCD (Binary Coded Decimal). There is no way to add without the carry.",
		"SBC behavior depends on the state of the decimal flag. In decimal mode, the values upon which the subtraction is performed are interpreted as packed BCD (Binary Coded Decimal). There is no way to subtract without the carry. The carry works as an inverse borrow. i.e., to subtract, first set the carry. If the carry is cleared by the operation, a borrow has occurred.", 
		"SBC behavior depends on the state of the decimal flag. In decimal mode, the values upon which the subtraction is performed are interpreted as packed BCD (Binary Coded Decimal). There is no way to subtract without the carry. The carry works as an inverse borrow. i.e., to subtract, first set the carry. If the carry is cleared by the operation, a borrow has occurred.",
		"SBC behavior depends on the state of the decimal flag. In decimal mode, the values upon which the subtraction is performed are interpreted as packed BCD (Binary Coded Decimal). There is no way to subtract without the carry. The carry works as an inverse borrow. i.e., to subtract, first set the carry. If the carry is cleared by the operation, a borrow has occurred.", 
		"SBC behavior depends on the state of the decimal flag. In decimal mode, the values upon which the subtraction is performed are interpreted as packed BCD (Binary Coded Decimal). There is no way to subtract without the carry. The carry works as an inverse borrow. i.e., to subtract, first set the carry. If the carry is cleared by the operation, a borrow has occurred.", 
		"SBC behavior depends on the state of the decimal flag. In decimal mode, the values upon which the subtraction is performed are interpreted as packed BCD (Binary Coded Decimal). There is no way to subtract without the carry. The carry works as an inverse borrow. i.e., to subtract, first set the carry. If the carry is cleared by the operation, a borrow has occurred.", 
		"SBC behavior depends on the state of the decimal flag. In decimal mode, the values upon which the subtraction is performed are interpreted as packed BCD (Binary Coded Decimal). There is no way to subtract without the carry. The carry works as an inverse borrow. i.e., to subtract, first set the carry. If the carry is cleared by the operation, a borrow has occurred.", 
		"SBC behavior depends on the state of the decimal flag. In decimal mode, the values upon which the subtraction is performed are interpreted as packed BCD (Binary Coded Decimal). There is no way to subtract without the carry. The carry works as an inverse borrow. i.e., to subtract, first set the carry. If the carry is cleared by the operation, a borrow has occurred.", 
		"SBC behavior depends on the state of the decimal flag. In decimal mode, the values upon which the subtraction is performed are interpreted as packed BCD (Binary Coded Decimal). There is no way to subtract without the carry. The carry works as an inverse borrow. i.e., to subtract, first set the carry. If the carry is cleared by the operation, a borrow has occurred.", 
		"Take the operand for calculation immediate.            ", "Take the operand as zero page address.             ", "Take the operand as zero page address plus X.           ", 
		"Take the operand as address.             ", "Take the operand as address plus X.             ", "Take the operand as address plus Y.             ", 
		"Take the operand plus X as zero page address.          ", "Take the operand as zero page address, add Y to the contents.              ", "Take the operand for calculation immediate.            ", 
		"Take the operand as zero page address.             ", "Take the operand as zero page address plus Y.            ", "Take the operand as address.             ", 
		"Take the operand as address plus Y.             ", "Take the operand for calculation immediate.     ", "Take the operand as zero page address.     ", 
		"Take the operand as zero page address plus X.       ", "Take the operand as address.      ", "Take the operand as address plus X.      ", "Take the operand as zero page address.    ", 
		"Take the operand plus X as zero page address. ", "Take the operand as address.      ", "Take the operand as address plus X.      ", "Take the operand as address plus Y.      ", 
		"Take the operand plus X as zero page address.       ", "Take the operand as zero page address, add Y to the contents.       ", "Take the operand as zero page address. ", 
		"Take the operand as zero page address plus Y.     ", "Take the operand as address.   ", "Take the operand as zero page address.   ", "Take the operand as zero page address plus X.   ", 
		"Take the operand as address.  ", "Take the operand as zero page address. ", "Take the operand as zero page address plus X.     ", "Take the operand as address. ", 
		"Take the operand as address plus X.     ", "Take the operand as zero page address. ", "Take the operand as zero page address plus X.     ", "Take the operand as address. ", 
		"Take the operand as address plus X. ", "     ", "     ", "     ", "     ", "     ", "     ", "     ", "     ", 
		"The stack is always on page $01 ($0100-$01FF) and works top down. i.e., when you push to the stack the stack pointer is decremented. When you pull from the stack the stack pointer is incremented.", 
		"The stack is always on page $01 ($0100-$01FF) and works top down. i.e., when you push to the stack the stack pointer is decremented. When you pull from the stack the stack pointer is incremented.", 
		"The stack is always on page $01 ($0100-$01FF) and works top down. i.e., when you push to the stack the stack pointer is decremented. When you pull from the stack the stack pointer is incremented.", 
		"The stack is always on page $01 ($0100-$01FF) and works top down. i.e., when you push to the stack the stack pointer is decremented. When you pull from the stack the stack pointer is incremented. The PULL operations are known as POP on most other microprocessors.", 
		"The stack is always on page $01 ($0100-$01FF) and works top down. i.e., when you push to the stack the stack pointer is decremented. When you pull from the stack the stack pointer is incremented.", 
		"The stack is always on page $01 ($0100-$01FF) and works top down. i.e., when you push to the stack the stack pointer is decremented. When you pull from the stack the stack pointer is incremented. The PULL operations are known as POP on most other microprocessors.", 
		"BRK sets the B flag, and then generates a forced interrupt. The Interrupt flag is ignored and the CPU goes through the normal interrupt process. In the interrupt service routine, the state of the B flag can be used to distinguish a BRK from a standard interrupt.BRK causes a non-maskable interrupt and increments the program counter by one. ", 
		"A NOP takes 2 machine cycles to execute, but it has no effect on any register, memory location, or processor flag. Thus, it takes up time and space but performs no operation."
	};
	char *sDescr = malloc(40);
	int iSpc = 0;
	char ch = 'A';
	int iLoop = 1;
	int iFirstline = 0;
	int iEmptymode = 0;
	if ((argc == 3))
	{		
		for (int i = 0; i <= 150; i++) 
		{
			if (strcmp(argv[1], cMne[i]) == 0)
			{
				if (strcmp(argv[2], cAbbrmod[i]) == 0)
				{
					printf("Providing help on %s %s\n",cMne[i],cAbbrmod[i]);
					printf("The mnemonic means %s \n", cDesc[i]);
					printf("The adressing mode is %s \n", cMod[i]);
					printf("The operand is %i bytes ", iLen[i] - 1);
					printf("it is a %i byte instruction \n", iLen[i]);
					printf("The category is %s \n", sCat[i]);
					printf("The operator code is %i decimal \n", iOpc[i]);
					printf("The instruction is usually written as %s \n", cSyn[i]);
					printf("%s", sExt[i]);
				}
			}
		}
	}
	if (argc == 2)
	{		
		for (int i = 0; i <= 150; i++) 
		{
			if (strcmp(argv[1], cMne[i]) == 0)
			{
				if (iFirstline == 0) 
				{
					printf("Providing help on %s \n",cMne[i]); 
					printf("The mnemonic means %s \n", cDesc[i]);
					printf("The category is %s \n", sCat[i]);
					if (strcmp(cAbbrmod[i], "   ") == 0)
					{
						printf("Use help %s %c   %c",cMne[i], '"', '"');
						iEmptymode = 1;
					}
					if (iEmptymode == 0) { printf("The adressing modes are %s", cAbbrmod[i]); }
					iFirstline = 1;
				}
				if (iEmptymode == 0) { printf(", %s", cAbbrmod[i]); }
			}
		}
		printf(".\n");
	}
	if (argc < 2)
	{		
		printf("\nShow extensive help information about a specific assembler line\n for the C64 8-bit MOS Technology 6510 microprocessor.\nInput from the standard input stream.; Output text to the standard output stream.\n");
		printf("Use:\nhelp <operator> <adressing mode> \n");
		printf("\nExamples:\n");
		printf("help %clda%c %cabs%c \n",'"','"','"','"');  
		printf("help %ccmp%c %cimm%c \n",'"','"','"','"'); 
		printf("help %crts%c %c   %c \n",'"','"','"','"'); 
	}		
	return 0;
}
