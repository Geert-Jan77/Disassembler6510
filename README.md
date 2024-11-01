# Disassembler6510

Disassemble machine code for the **Commodore 64** 8-bit MOS Technology 6510 microprocessor to an assembler list.<br />
Output listings look like this:&nbsp;
```
Disassembler6510 has decompiled the code into:

02047 .dt     02049     // pointer to start adress dat = 2byte data lsb-msb byt = 1 byte data
02049 .dt     02059     // pointer to next basic line
02051 .dt     00010     // basic line number 10
02053 .by     00158     // 158 is the token 'SYS' (153 is the token 'PRINT')
02054 .by     00050     // petscii 2
02055 .by     00048     // petscii 0
02056 .by     00054     // petscii 6 
02057 .by     00049     // petscii 1 
02058 .by     00000     // terminate line
02059 .dt     00000     // pointer to next basic line
02061 lda imm 00012     // color grey
02063 sta abs 53280     // set border color 53280	Border color (only bits #0-#3). 2 red 1 white 6 blue 53281	Background color (only bits #0-#3).
02066 rts               // no linebreak
```
all data are represented decimal, not hexadecimal.<br />
The assemblercode can also be compiled with the compiler in this project. <br />
![screenshot](https://github.com/Geert-Jan77/Disassembler6510/blob/main/doc/changecolor.png)


## Table of Contents
1. [dis.prg or dis.exe](#disprg-or-disexe)
2. [compile.prg or compile.exe](#compileprg-or-compileexe)
3. [help.prg or help.exe](#helpprg-or-helpexe)
4. [dat.prg or dat.exe](#datprg-or-datexe)
6. [Examples](#Examples)
7. [Compile Dissassembler6510](#compile-dissassembler6510)
8. [c64 File transfers](#File-transfers)

## dis.prg or dis.exe
Disassemble machine code for the C64 8-bit MOS Technology 6510 microprocessor.<br />
Input from file; Output text to the standard output stream.<br />
Use: <br />
dis \<file\> \<start-adress\> \<length\><br />

## compile.prg or compile.exe
Compile assembler code for the C64 8-bit MOS Technology 6510 microprocessor. <br />
Input from file; Output to file. <br />
Use: <br />
compile \<inputfile\> \<outputfile\> <br />

## help.prg or help.exe
Show extensive help information about a specific assembler line <br />
for the C64 8-bit MOS Technology 6510 microprocessor. <br />
Input from the standard input stream.; Output text to the standard output stream. <br />
Use: <br />
help \<operator\> \<adressing mode\> <br />

## dat.prg or dat.exe
View data specially for the C64 8-bit MOS Technology 6510 microprocessor.<br />
Input from file; Output text to the standard output stream.<br />
Use: <br />
dat \<file\> \<start-adress\> \<length\><br />

## Examples
```
dis "changecolor.prg" 0 256 > changecolor.asm           
compile "changecolor.asm" "changecolor.prg" // trim the header and footer before compiling. delete the newline after the last code line.
help "rts" "   "
dat "changecolor.prg" 0 256
```

## Compile Dissassembler6510
To compile Dissassember from source, see _doc_ folder [Compile windows.md](https://github.com/Geert-Jan77/Disassembler6510/blob/main/doc/Compile%20windows.md)

## File transfers 
For a file transfer from the commodore 64c to a windows 7 PC free software and a cassette recorder are used.<br />
The software resource goes from physical tape via .wav file and .tap file to .prg file.<br />

**Example 1:** The _turbo tape 64_ program is on a commodore 64c tape. <br />
Put the tape in a Philips D6280 **mono** cassette recorder, or even a cassette stereo. <br />
Use **audacity 3.6.4** recording software on the windows 7 PC to create a .wav file of the tape. <br />
Convert from .wav to .tap using **audiotap 2.2.1**, Check the .tap file using **tapclean 0.38**.<br />
Convert from .tap to .d64 file on the pc running a _commodore 64 emulator_ like **gtk3vice 3.8**<br />
and save from tape to diskette on the emulator. You need a tape to disk copier like [Giantcopy 64 v1.0](https://commodore.software/downloads/download/132-tape-transfer-tools/337-giantcopy-64-v1-0) to copy a complete tape to a disk. Convert from .d64 to a batch of .prg using **dirmaster 3.1.5**. <br />

![From wav to tap.](https://github.com/Geert-Jan77/Disassembler6510/blob/main/doc/audiotap2.png)

**Example 2:** The _turbo tape 64_ program is on a *.prg file. <br />
Check the .prg file on the pc running a _commodore 64 emulator_ like **gtk3vice 3.8**. <br />
Convert from .tap to sound using **audiotap 2.2.1** Put a type I ferro tape in a Philips D6280 **mono** cassette recorder. <br />
Record the sound at high volume and wired. Check the physical tape on a commodore 64c.<br />

![From tap to sound.](https://github.com/Geert-Jan77/Disassembler6510/blob/main/doc/audiotap1.png)
