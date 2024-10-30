//dat.c compiler gcc 11.7, OS win7, dat.exe gives a dataview of the file showing bits, bytes, words, adresses, ascii. github Disassembler6510

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	int iNum1, iNum2, iNum3, a;
	iNum1 = 0;
	iNum2 = 0;
	iNum3 = 0;	
	char * sText = malloc(255);
	a = 0;
	unsigned char byte = 34;
	unsigned char mask = 1; 
	unsigned char bits[8];
	if (argc > 1) {sscanf(argv[1], "%d", &iNum1); }
	if (argc > 2) {sscanf(argv[2], "%d", &iNum2); }
	if (argc > 3) {sscanf(argv[3], "%d", &iNum3); }
	if (iNum3 > 256) {iNum3 = 256; }
	int iLines = 0;
	if ((argc > 2)&&(argc <5))
	{		
		FILE *file_ptr;
		char ch1,ch2;
		file_ptr = fopen(argv[1], "r");
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
		int iChar1 = 0;
		int iChar2 = 0;
		int iLen = 0;
		int iOperand16 = 0;
		int iNotEof = 1;
		while (iNotEof == 1) 
		{
			ch1 = fgetc(file_ptr); if (feof(file_ptr)) { iNotEof = 0; break;}
			a++; iLen++;
			ch2 = fgetc(file_ptr); if (feof(file_ptr)) { iNotEof = 0; }
			a++; iLen++;
			if ((a > iNum2)&&(a <= iNum2 + iNum3 + 2)) 
			{
				int bNum1 = (int)ch1;
				int bNum2 = (int)ch2;
				if (bNum1 < 0) { bNum1 = bNum1 + 256; }
				if (bNum2 < 0) { bNum2 = bNum2 + 256; }
				iChar1 = 0;
				iChar2 = 0;
				if ((bNum1 > 31)&&(bNum1 < 127)) { iChar1 = 1; } 
				if ((bNum2 > 31)&&(bNum2 < 127)) { iChar2 = 1; }
				iOperand16 = 256 * bNum1 + bNum2;
				printf("\n%05i bits ", a - 2);
				byte = bNum1;
				for (int i = 0; i <= 7; i++) { bits[i] = (byte & (mask << i)) != 0; }
				for (int i = 0; i <= 7; i++) { printf("%d", bits[ 7 - i ]); }
				if (iNotEof == 1)
				{
					byte = bNum2;
					for (int i = 0; i <= 7; i++) { bits[i] = (byte & (mask << i)) != 0; }
					for (int i = 0; i <= 7; i++) { printf("%d", bits[ 7 - i ]); }
					printf(" bytes %3i %3i words %5i adress %5i ", bNum1, bNum2, 256 * bNum1 + bNum2, bNum1 + 256 * bNum2);
					if ((iChar2 == 1) && (iChar1 == 0)) {printf(" "); }
					if (iChar1 == 0) {sText[iLen - 2] = ' '; }
					if (iChar1 == 1) {printf("%c", ch1); sText[iLen - 2] = ch1; }
					if (iChar2 == 1) {printf("%c", ch2); sText[iLen - 1] = ch2; }
					if (iChar2 == 0) {sText[iLen - 1] = ' '; }
					sText[iLen] = '\0';
					iLines++;
				}
				if (iNotEof == 0)
				{
					printf("         bytes %3i     words %5i adress %5i ", bNum1, 256 * bNum1, bNum1 );
					if (iChar1 == 0) {sText[iLen - 2] = ' '; }
					if (iChar1 == 1) {printf("%c", ch1); sText[iLen - 2] = ch1; }
					sText[iLen - 1 ] = '\0';
					iLines++;
				}
			}
		}
		fclose(file_ptr);
		printf("\n\nAll Text is:%s\n", sText);
	}
	if (iLines == 0)
	{
		printf("\nView data specially for the C64 8-bit MOS Technology 6510 microprocessor.\nInput from ROM/RAM or file; Output text to the standard output stream.\n");
		printf("Use:\ndat <start-adress> <length>\ndat <file> <start-adress> <length>\n");
		printf("Maximum length 256 bytes\n");
		printf("\nExamples:\n");
		printf("dat %cturbo64.prg%c 32654 256   / view data of turbo.prg adresses 32654-32910\n", '"', '"');
		printf("dat 58360 14                  / view data of some commodore 64c kernel\n");//reset routine
	}
	return 0;
}