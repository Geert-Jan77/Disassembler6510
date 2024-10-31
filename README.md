# Disassembler6510

Disassemble machine code for the **Commodore 64** 8-bit MOS Technology 6510 microprocessor to an assembler list.<br />
Output listings look like this:&nbsp;
```
Disassembler6510 has decompiled the code into:

adr   mne mde oprnd mnemonic description                  mode description 
00000 .dt      2049 
02049 .dt      2059 Point to next line
02051 .dt        10 Basic line number
02053 .by       158 Basic token 'sys'
02054 .by        50 '2'
02055 .by        48 '0'
02056 .by        54 '6'
02057 .by        49 '1'
02058 .by         0 Line Break
02059 .dt         0 End of Basic list
02061 lda imm    12 Load Accumulator                      Immediate    
02063 sta abs 53280 Store Accumulator                     Absolute     
02066 rts           Return to Saved                       Implied      
feof() end of file at 2066

Found 5 ascii characters, use "dat" for dataview.
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
