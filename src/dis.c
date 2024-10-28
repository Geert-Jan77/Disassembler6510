//disassembler6510
//print all numbers decimal, nothing hexadecimal
#include <stdio.h>

int main(int argc, char * argv[])
{
	int iNum1, iNum2, iNum3, a;
	printf("argc= %i argv[1]= %s\n\n", argc, argv[1]);
	if (argc > 1) {sscanf(argv[1], "%d", &iNum1);}
	if (argc > 2) {sscanf(argv[2], "%d", &iNum2);}
	if (argc > 3) {sscanf(argv[3], "%d", &iNum3);}
	printf("a= %i iNum1= %i iNum2= %i iNum3= %i\n\n", a, iNum1, iNum2, iNum3);
	
	char arr[5][16] = {"adress ", "opcode ", "operand ", "mnemonic ", "description "};
	
	printf("Use:\ndis <start-adress> <length>\ndis <file> <start-adress> <length>\n");
	printf("\nExamples:\n");
	printf("dis %cturbo64.prg%c 32654 256   / disassemble turbo.prg adresses 32654-32910\n", '"', '"');
	printf("dis 58360 14                  / disassemble some of the commodore 64c kernel\n");//reset routine
	printf("\nDisassembler6510 has decompiled the code into:\n");
  
	for (int i = 0; i < 5; i++) 
	{
		printf("%s", arr[i]);
	}
	printf("\n");
	FILE *file_ptr;
	char ch;
	file_ptr = fopen(argv[1], "r");
	if (NULL == file_ptr) 
	{
		printf("file can't be opened \n");
		return 1;
	}
	printf("Content of the file: \n");
	while ((ch = fgetc(file_ptr)) != EOF) 
	{
		a++;
		if ((a >= iNum2)&&(a <= iNum2 + iNum3)) 
		{
			printf("%c", ch);
		}
	}
	fclose(file_ptr);
	return 0;
}
