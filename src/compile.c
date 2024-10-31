//compile.c compiler gcc 11.7, OS win7, compiler.exe compiles assembler listings for the commodore 64 processor. github Disassembler6510

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
	char ch;
	int uCh = 0;
	int iOperatorcolumn = 0;
	unsigned char byte;
	char *sText = malloc(255);
	char *sOperator = malloc(15);
	char *sMode = malloc(15);
	char *sOperand = malloc(15);
	int iLn = 0;
	int iOperand = 0;
	unsigned char iMsb = 0;
	unsigned char iLsb = 0;
	unsigned char iOpc[151] = 
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
	if (argc == 3)
	{		
		FILE *load_ptr;
		load_ptr = fopen(argv[1], "r");
		if (NULL == load_ptr) 
		{
			printf("fopen(%s, %cr%c); file can't be opened \n", '"', '"', argv[1]);
			return 1;
		}
		FILE *save_ptr;
		save_ptr = fopen(argv[2], "wb");
		if (NULL == save_ptr) 
		{
			printf("fopen(%s, %cw%c); file can't be opened \n", '"', '"', argv[2]);
			return 1;
		}
		int iNotEof = 1;
		int iNotEol = 1;
		while (iNotEof == 1) 
		{
			iOperand = 0;
			iMsb = 0;
			iLsb = 0;
			ch = fgetc(load_ptr); 
			uCh = (int)ch;
			if (uCh < 0) uCh = uCh + 256;
			if (feof(load_ptr)) { iNotEof = 0; } 
			sText[iLn] = ch;
			sText[iLn + 1] = '\0';
			iLn++;
			if ((uCh == 10) || (uCh == 13) || (iNotEof == 0)) 
			{
				iNotEol = 0; 
				sOperator[0] = sText[6];
				sOperator[1] = sText[7];
				sOperator[2] = sText[8];
				sOperator[3] = '\0';
				sMode[0] = sText[10];
				sMode[1] = sText[11];
				sMode[2] = sText[12];
				sMode[3] = '\0';
				sOperand[0] = sText[14];
				sOperand[1] = sText[15];
				sOperand[2] = sText[16];
				sOperand[3] = sText[17];
				sOperand[4] = sText[18];
				sOperand[5] = '\0';
				iLn = 0;	
				sscanf(sOperand, "%d", &iOperand);
				if (iOperand > 255) {iMsb = iOperand / 256; iLsb = iOperand - 256 * iMsb; }
				if (iOperand < 256) {iLsb = iOperand; } 
				for (int i = 0; i <= 150; i++) 
				{
					if (strcmp(sOperator, cMne[i]) == 0)
					{
						if (strcmp(sMode, cAbbrmod[i]) == 0)
						{
							byte = (unsigned char)iOpc[i];
							fputc(byte, save_ptr);
							printf("%i,", byte);
							if (iLen[i] > 1)   
							{
								byte = (unsigned char)iLsb;
								fputc(byte, save_ptr);
								printf("%i,", byte);
							}
							if (iLen[i] > 2)   
							{
								byte = (unsigned char)iMsb;
								fputc(byte, save_ptr);
								printf("%i,", byte);
							}
						}
					}
				}
				if (strcmp(sOperator, ".dt") == 0)
				{
								byte = (unsigned char)iLsb;
								fputc(byte, save_ptr);
								printf("%i,", byte);
								byte = (unsigned char)iMsb;
								fputc(byte, save_ptr);
								printf("%i,", byte);
				}
				if (strcmp(sOperator, ".by") == 0)
				{
								byte = (unsigned char)iLsb;
								fputc(byte, save_ptr);
								printf("%i,", byte);
				}
			}
		}
		fclose(load_ptr);
		fclose(save_ptr);
	}
	if (argc < 3)
	{
		printf("Compile assembler code for the C64 8-bit MOS Technology 6510 microprocessor. \n");
		printf("Input from basic list; Output to RAM. \n");
		printf("Input from file; Output to file. \n");
		printf("Use: \n");
		printf("compile %clist%c \n", '"','"' );
		printf("compile <inputfile> <outputfile> \n");
		printf("\nExamples:\n");
		printf("compile %clist%c                       / compile assembler code in the c64 list\n", '"', '"');
		printf("compile %creset.asm%c %creset.prg%c      / compile assembler code in a file\n", '"', '"', '"', '"');
	}
	return 0;
}