//dis.c compiler gcc 11.7, OS win7, dis.exe disassembles machinecode for the commodore 64 processor. github Disassembler6510

#include <stdio.h>

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
		"Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "            " 
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
		"Pull Processor Status                ", "Break                                ", "No Operation                         ", "                                     "
	};
	int iNum1, iNum2, iNum3, a;
	iNum1 = 0;
	iNum2 = 0;
	iNum3 = 0;	
	a = 0;
	if (argc > 1) {sscanf(argv[1], "%d", &iNum1); }
	if (argc > 2) {sscanf(argv[2], "%d", &iNum2); }
	if (argc > 3) {sscanf(argv[3], "%d", &iNum3); }
	if (iNum3 > 256) {iNum3 = 256; }
	int iLines = 0;
	if ((argc > 2)&&(argc <5))
	{		
		FILE *file_ptr;
		char ch;
		file_ptr = fopen(argv[1], "rb");
		if (NULL == file_ptr) 
		{
			printf("fopen() file can't be opened \n");
			return 1;
		}
		if (fseek(file_ptr, iNum2, SEEK_SET)!=0)
		{
			printf("fseek() file position can't be reached \n");
			return 1;
		}
		a = iNum2;
		int iChars=0;
		int iTest = 0;
		int iCount = 0;
		int iN1 = 1;
		int iN2 = 1;
		int iN3 = 1;
		int iOperand16 = 0;
		int iOperand8 = 0;
		int iLength = 0;
		int iIndex = 0;
		int iOffset = 0;
		int iPointer = 0;
		int iBasic = 1;
		int iLinebreak = 0;
		int iLinenumber = 0;
		int iLinenumber2 = 0;
		if (iNum2 == 0)
		{
			while (iBasic) 
			{
				ch = fgetc(file_ptr);
				if (feof(file_ptr)) 
				{
					printf("\nfeof() end of file at %i\n",a-1);
					break;
				}
				a++;
				if ((a > iNum2)&&(a <= iNum2 + iNum3)) 
				{
					int bNum1 = (int)ch;
					if (bNum1 < 0) { bNum1 = bNum1 + 256; }
					iN3 = iN2;
					iN2 = iN1;
					if (bNum1 == 0) { iN1 = 0; }
					if (bNum1 != 0) { iN1 = 1; }
					if ((iN3 == 0) && (iN2 == 0) && (iN1 == 0)) {iBasic = 0; }
					if (iCount > 1)
					{
						if (iCount == 3) {iOperand16 += bNum1;}
						if (iCount == 2) 
						{
							iOperand16 += 256 * bNum1; iOperand8 = bNum1;
							if (iLength == 3) 
							{
								printf("%5i ", iOperand16); 
								if ((iNum2 == 0) && (a == 2)) { iOffset = iOperand16 - 2; }
								if (iLinenumber2 == 1) { printf("Basic line number"); iLinenumber2 = 0; }
								if (iPointer == 1 && iOperand16!=0) { printf("Point to next line"); iPointer = 0; }
							} 	if (iPointer == 1 && iOperand16==0) { printf("End of Basic list"); iPointer = 0; }
							if (iLength == 2) {printf("%5i ", iOperand8); }
						}
						iCount--;				
					}
					else
					{
						iCount = 0;
						iOperand16 = 0;
						iOperand8 = 0;
						iLength = 0;
						iIndex = 0;
						iLines++;
						if (iLines == 1)
						{
							printf("\nDisassembler6510 has decompiled the code into:\n");
							printf("\nadr   mne mde oprnd mnemonic description                  mode description ");
							printf("\n%05i ", a - 1 + iOffset);
						}
						if (a == 1 && iNum2 == 0) 
						{ 
							iOperand16 += bNum1;
							iIndex = 151;
							iLength = 3;
							iCount = 2;
							printf(".dt     "); 
							
						}
						
						if (iLinenumber == 1) 
						{
							iLinenumber = 0;
							iLinenumber2 = 1;
							iOperand16 += bNum1;
							iIndex = 151;
							iLength = 3;
							iCount = 2;
							printf("\n%05i .dt     ", a - 1 + iOffset); 
						}
						if (a == 3 && iNum2 == 0) 
						{ 
							iOperand16 += bNum1;
							iIndex = 151;
							iLength = 3;
							iCount = 2;
							printf("\n%05i .dt     ", a - 1 + iOffset); 
							iLinenumber = 1;
							iPointer = 1;
						}
						
						if (iLinebreak == 1) 
						{ 
							iPointer = 1;
							iLinebreak = 0;
							iLinenumber = 1;
							iOperand16 += bNum1;
							iIndex = 151;
							iLength = 3;
							iCount = 2;
							printf("\n%05i .dt     ", a - 1 + iOffset); 
						}
						
						if ((bNum1 > 31)&&(bNum1 < 127)) { iChars++; } 
						if (iIndex == 0)
						{ 
							printf("\n%05i .by      %4i ", a - 1 + iOffset, bNum1);
							if ((bNum1 > 31)&&(bNum1 < 127)) { printf("'%c'", bNum1); } 
							if (bNum1 == 171) { printf("'-'"); } 
							if (bNum1 == 172) { printf("'*'"); } 
							if (bNum1 == 173) { printf("'/'"); }
							if (bNum1 == 178) { printf("'='"); } 
							
							if (bNum1 == 151) { printf("Basic token 'poke'"); }
							if (bNum1 == 158) { printf("Basic token 'sys'"); } 
							if (bNum1 == 153) { printf("Basic token 'print'"); }
							
							if (bNum1 == 0) 
							{ 
								printf("Line Break");
								iLinebreak = 1;
							}	
							
						} 
					}
				}
			}
			while (1) 
			{
				ch = fgetc(file_ptr);
				if (feof(file_ptr)) 
				{
					printf("\nfeof() end of file at %i\n", a - 1 + iOffset);
					break;
				}
			a++;
			if ((a > iNum2)&&(a <= iNum2 + iNum3)) 
			{
				int bNum1 = (int)ch;
				if (bNum1 < 0) { bNum1 = bNum1 + 256; }
				if (iCount > 1)
				{
					if (iCount == 3) {iOperand16 += bNum1;}
					if (iCount == 2) 
					{
						iOperand16 += 256 * bNum1; iOperand8 = bNum1;
						if (iLength == 3) {printf("%5i %s %s ", iOperand16, cDesc[iIndex], cMod[iIndex]); }	
						if (iLength == 2) {printf("%5i %s %s ", iOperand8, cDesc[iIndex], cMod[iIndex]); }
					}
					iCount--;				
					}
					else
					{
						iCount = 0;
						iOperand16 = 0;
						iOperand8 = 0;
						iLength = 0;
						iIndex = 0;
						for (int i = 0; i <= 150; i++) 
						{
							if (bNum1 == iOpc[i]) 
							{ 
								iIndex = i;
								iLines++;
								if (iLines == 1)
								{
									printf("\nDisassembler6510 has decompiled the code into:\n");
									printf("\nadr   mne mde oprnd mnemonic description                  mode description ");
								}
								printf("\n%05i ", a - 1  + iOffset);
								iCount = iLen[i];
								iLength = iLen[i];
								printf("%s %s ", cMne[i], cAbbrmod[i]); 
								if (iLength == 1) {printf("      %s %s ", cDesc[iIndex], cMod[iIndex]); }
							}
						}
						if ((bNum1 > 31)&&(bNum1 < 127)) { iChars++; } 
						if (iIndex == 0)
						{ 
							printf("\n%05i .by      %4i ", a - 1 + iOffset, bNum1);
							if ((bNum1 > 31)&&(bNum1 < 127)) { printf("'%c'", bNum1); } 
						} 
					}
				}
			}
		}
		fclose(file_ptr);
		if (iChars > 4) { printf("\nFound %i ascii characters, use %cdat%c for dataview.\n",iChars, '"', '"'); }
	}
	if (iLines == 0)
	{
		printf("\nDisassemble PRG files for the C64 8-bit MOS Technology 6510 microprocessor.\nInput from file; Output text to the standard output stream.\n");
		printf("Use:\nUse:\ndis <file> <start-adress> <length>\nMaximum length 256 byte.\n");
		printf("\nExamples:\n");
		printf("dis %cturbo64.prg%c 32654 256   / disassemble turbo.prg adresses 32654-32910\n", '"', '"');  // Or escape sequence /"
	}
	return 0;	
}