# Disassembler6510
## Table of Contents
1. [General Info](#general-info)
2. [Technologies](#technologies)
3. [Installation](#installation)
4. [Collaboration](#collaboration)
5. [Examples](#Examples)

## dis.prg or dis.exe
Disassemble machine code for the C64 8-bit MOS Technology 6510 microprocessor.
Input from ROM/RAM or file; Output text to the standard output stream.
Use: 
dis <start-adress> <length>
dis <file> <start-adress> <length> 

## compile.prg or compile.exe
Compile assembler code for the C64 8-bit MOS Teechnology 6510 microprocessor.
Input from basic list or file; Output to RAM.
Use: 
compile "list" <start-adress> 
compile <file> <start-adress>  

## translate.prg or translate.exe
Tranlate basic v2 to assembler code and back.
Input from basic list or .bas file or .asm file; Output from basic list or .bas file or .asm file;
Use:
translate "list"
translate <file> <file>

## Examples
all data are represented decimal, not hexadecimal.
```
dis "turbo64.prg" 32654 256           / disassemble turbo.prg adresses 32654-32910
dis 58360 14                          / disassemble the reset routine from the commodore 64c kernel
compile "turbo64.bas" 2058            / compile turbo64.bas to memory
compile "list" 2058                   / compile basic list to memory
translate list                        / translate basic list to assembler list
translate list                        / translate assembler list to basic list
translate "turbo64.bas" "turbo64.asm" / translate turbo64.bas to turbo64.asm
```
