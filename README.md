# Disassembler6510

Assembler listings look like:&nbsp;
```
40964 wd 58360 word data
40962 wd 58235 word data
40964 by 67,66,77,66,65,83,73,67 byte data cbmbasic
40972 wd 43056 word data 43056

58360 jsr 58451 jump to subroutine
(todo e397 20bfe3 jsr $e3bf
e39a 2022e4 jsr $e422
e39d a2fb ldx #$fb
e3a0 d0e4 bne $e386)
```

## Table of Contents
1. [dis.prg or dis.exe](#dis.prg-or-dis.exe)
2. [compile.prg or compile.exe](#compile.prg-or-compile.exe)
3. [translate.prg or translate.exe](#installation)
4. [Examples](#Examples)
5. [Compile Dissassembler6510](#Compile-Dissassmbler6510)
6. [c64 File transfers](#File-transfers-between-a-Windows-7-PC-and-a-Commodore-64)

## dis.prg or dis.exe
Disassemble machine code for the C64 8-bit MOS Technology 6510 microprocessor.<br />
Input from ROM/RAM or file; Output text to the standard output stream.<br />
Use: <br />
dis \<start-adress\> \<length\><br />
dis \<file\> \<start-adress\> \<length\><br />

## compile.prg or compile.exe
Compile assembler code for the C64 8-bit MOS Teechnology 6510 microprocessor.<br />
Input from basic list or file; Output to RAM.<br />
Use: <br />
compile \"list\" <start-adress> <br />
compile \<file\> <start-adress>  <br />

## translate.prg or translate.exe
Tranlate basic v2 to assembler code and back.<br />
Input from basic list or .bas file or .asm file; Output from basic list or .bas file or .asm file;<br />
Use:<br />
translate \"list\"<br />
translate \<file\> \<file\><br />

## Examples
all data are represented decimal, not hexadecimal.<br />
```
dis "turbo64.prg" 32654 256           / disassemble turbo.prg adresses 32654-32910
dis 58360 14                          / disassemble the reset routine from the commodore 64c kernel
compile "turbo64.bas" 2058            / compile turbo64.bas to memory
compile "list" 2058                   / compile basic list to memory
translate list                        / translate basic list to assembler list
translate list                        / translate assembler list to basic list
translate "turbo64.bas" "turbo64.asm" / translate turbo64.bas to turbo64.asm
```

## Compile Dissassmbler6510

## File transfers 

For a file transfer from the commodore 64c to a windows 7 PC free software and a cassette recorder are used.<br />
The software resource goes from physical tape via .wav file and .tap file to .prg file.<br />

**Example 1:** The _turbo tape 64_ program is on a commodore 64c tape. <br />
Put the tape in a Philips D6280 **mono** cassette recorder, or even a cassette stereo. <br />
Use **audacity 3.6.4** recording software on the windows 7 PC to create a .wav file of the tape. <br />
Convert from .wav to .tap using **audiotap 2.2.1**, Check the .tap file using **tapclean 0.38**.<br />
Convert from .tap to .prg using **dirmaster 3.1.5**. Check the .prg file on the pc running a _commodore 64 emulator_ like **gtk3vice 3.8**<br />

![From wav to tap.](https://github.com/Geert-Jan77/Disassembler6510/blob/main/doc/audiotap2.png)

**Example 2:** The _turbo tape 64_ program is on a *.prg file. <br />
Check the .prg file on the pc running a _commodore 64 emulator_ like **gtk3vice 3.8**. <br />
Convert from .tap to sound using **audiotap 2.2.1** Put a type I ferro tape in a Philips D6280 **mono** cassette recorder. <br />
Record the sound at high volume. Check the physical tape on a commodore 64c.<br />

![From tap to sound.](https://github.com/Geert-Jan77/Disassembler6510/blob/main/doc/audiotap1.png)
