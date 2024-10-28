#include <stdio.h>
//disassembler6510
//print all numbers decimal, nothing hexadecimal
int main()
{
  char arr[5][16] = {"adress ", "opcode ", "operand ", "mnemonic ", "description "};
  printf("Use: dis [file] [start] i.e. dis turbo64.prg 32654 \nDisassembler6510 has decompiled the code into:\n");
  
  for (int i = 0; i < 5; i++) 
  {
    printf("%s", arr[i]);
  }
printf("\n");
  return 0;
}
