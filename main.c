#include <stdio.h>
//disassembler6510
//print all numbers decimal, nothing hexadecimal
int main()
{
  char arr[6][16] = {"adress ", "opcode ", "operand", "mnemonic", "adress mode ", "description "};
  printf("Disassembler6510 has decompiled the code into:\n");
  
  for (int i = 0; i < 3; i++) 
  {
    printf("%s", arr[i]);
  }
printf("\n");
  return 0;
}
