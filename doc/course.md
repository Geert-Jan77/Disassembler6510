Copy from [DusteDs home in cyberspace](https://dusted.dk/pages/c64/C64-programming/) :: Commodore 64 programming notes 

# C64 assembly programming in 2020

Mostly for myself, since this machine is super well documented. I had some false starts, wanting to do everything the hard way, first wrote a text-editor in basic, on a C64, and then started writing an assembler, but realized that my basic skills are too weak and I gave up.. My plan had been to bootstrap everything, from editor, to assembler, to sprite editor, and THEN use those to program some simple game "because".. but, yeah, I don't have that kind of time anymore.

So instead, I'm going to learn how to program in a bit more modern environment, I'll try not to take TOO much advantage of the emulator capabilities, but, to be honest, having an Internet connection and targeting what is probably the most well-documented machine ever, EZ mode is perma-enabled.. I'd have liked to have the experience of figuring out this stuff "the authentic way" but how do you deprive yourself of just enough information while still making progress?

So for my learning experience, I'm choosing to make use of the documentation available, and to use a modern editor and graphics tools, and then cross-assemble and run in the emulator (EZ mode indeed)

## Index

1.  [Memory Map](https://dusted.dk/pages/c64/C64-programming/#mmap)
2.  [Instruction Set](https://dusted.dk/pages/c64/C64-programming/#instructionset)
3.  [Development Environment](https://dusted.dk/pages/c64/C64-programming/#devenv)
4.  [Hello World 1.0](https://dusted.dk/pages/c64/C64-programming/#hello1)
5.  [Hello World 1.5](https://dusted.dk/pages/c64/C64-programming/#hello1_5)
6.  [Hello Numbers](https://dusted.dk/pages/c64/C64-programming/#hellonum)
7.  [Hello Macros](https://dusted.dk/pages/c64/C64-programming/#hellomac)
8.  [Hello Raster Interrupt](https://dusted.dk/pages/c64/C64-programming/#hellorasterint)
9.  [Hello CPU usage](https://dusted.dk/pages/c64/C64-programming/#hellocpusage)
10.  [Hello Color Memory](https://dusted.dk/pages/c64/C64-programming/#hellocolormemory)
11.  [List of tools and references](https://dusted.dk/pages/c64/C64-programming/#list)

## Memory map

If you're used to modern development, think of the memory map as a kind of API overview, it shows a lot about what functionality is available in the machine, and gives a nice entrypoint for investigating further.

There are plenty of them, and they all seem to have their strength and weaknesses, I've not yet found "the perfect one" if it exists.. I'll maybe try to make my own. What I would really like, is a memory map where I can visually see which block a given address is inside, and how relatively big or small that block is, and what it is often used for by people who know what they're doing. If there is IO or roms, I'd like to see what they are. Ideally, if something is a pointer, for example, the "sprite pointers", I'd like to be able to expand and get some explaination of what the default values (if any) are, and how the pointers are used. If it's a register, I'd like to know what the bits do and how they're initially set.

By far the best memory map I've found so far is [https://sta.c64.org/cbm64mem.html](https://sta.c64.org/cbm64mem.html) there is a nice graphic on [C64-Wiki.com](https://www.c64-wiki.com/wiki/Memory_Map) but it lacks some of the details.

## Instruction set

So, the memory map is kind of this nice overview of what stuff is in the machine, but [the instruction set](https://www.masswerk.at/6502/6502_instruction_set.html) is a listing of all the cool stuff you can actually write.

## Development environment

I'm using [Kick Assembler](http://www.theweb.dk/KickAssembler/Main.html) for cross-assembly. It's a java program and can be easily run from the command line. I chose to make a small script called "kickass" and place in my $PATH so that calling the assembler is as easy as possible.

kickass:
#!/bin/bash
java -jar /home/dusted/code/c64/kickass/KickAss.jar $@

And that's that, to assemble a file, I just do:

~$ kickass awesome.asm

For editor, I use vim with this [kickassembler syntax file](https://www.vim.org/scripts/script.php?script_id=4121), there's also a kickassembler extension for Visual Studio Code.

I could assemble the code, copy the PRG file to my Ultimate64 or to a floppy or tape, but that takes a long time, and instead, I'll just use x64 from [VICE](https://dusted.dk/pages/c64/C64-programming/), as it can even take the prg file as an argument:

~$ kickass awesome.asm && x64 awesome.prg

This tries to assemble the program, and if the assembler didn't return error, runs the program in VICE.

## Hello World 1.0

Before writing hello world, you need to know a few things about the C64 specifically. First, the machine is not as primitive as the Atari2600, you don't need to control the raster beam directly to get something on the screen. The C64 has multiple screen modes, the default one is text mode, which is perfect for hello world. In text-mode, the VIC (Video Interface Chip) looks somewhere ($0400 to $07ff)) in memory for what characters to put on screen, somewhere else (the character ROM at $D000 to $DFFF) for the pixel pattern defining those characters and a third place ($D800 to $DBFF)for the color of those pixels for that character (probably not in that order, but that doesn't matter).

So, in order to put hello world on the screen, even before figuring out which instructions to use, you must consult the memory map, figure out the (default) memory location of the screen and of the colors. Note that at boot, the character colors for the blank part of the screen is actually set to the background color, so you can't even see the letters you're putting there without changing their color too (unless you change the background color). Below is a simple hello world program I wrote:

//world.asm
BasicUpstart2(start) // Macro that outputs a bit of BASIC program to SYS into our assembly code

// Define some constants
.const bgcolor = [$D021](https://dusted.dk/pages/c64/C64-programming/files/Commodore%2064%20memory%20map%20named.html#D021)
.const screen = [$0400](https://dusted.dk/pages/c64/C64-programming/files/Commodore%2064%20memory%20map%20named.html#0400)
.const color = [$D800](https://dusted.dk/pages/c64/C64-programming/files/Commodore%2064%20memory%20map%20named.html#D800)

// Store our program in "upper memory" above BASIC (there is a 4k unused block)
\*= $C000
start:  // So far, no actual instructions/output has been produced (except for the BASIC program)
        // but this label gets the value of the next outputted byte, and that byte is going to
        // be located at $C000, so, this label gets $C000.

// Set background color black
lda #0          // Load 0 into register A (0 = black)
sta bgcolor     // Store value of register a (the 0) into the memory location 
                // that holds the background color ($D021)

// clear screen (set every character to a space)
ldx #0
    lda #' '
loop:       // There are 1000 bytes of characters
    sta screen,x
    sta screen+256,x
    sta screen+512,x
    sta screen+768-24,x// start this a bit earlier so we don't overwrite those 24 bytes not on screen
    inx
bne loop

// Print the string to the screen
ldx #0              // Let's use the X register as the index into our text string.

stringLoop:
    lda txt,x       // Load the character at txt+x bytes
    beq exit        // If lda set zero bit we loaded the "null" byte after the string and we exit.
    sta screen,x    // Else put it on the screen.
    lda #2          // Load 2 (the color red) into the A register
    sta color,x     // And put it at the corrosponding color-memory.
    inx             // Increase the index
    jmp stringLoop  // and repet

//return to basic
exit:
lda #1     // But first, move cursor to line 1 (the line after the one we wrote)
sta $00d6  // We just do this so the READY prompt appears after our own message..
rts

// Store a zero terminated string
txt:
    .text "hello world"
    .byte 0

    

And here's a hexdump of the resulting world.prg file:

00000000  01 08 0c 08 0a 00 9e 34  39 31 35 32 00 00 00 00  |.......49152....|
00000010  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
\*
0000b800  00 a9 00 8d 21 d0 a2 00  a9 20 9d 00 04 9d 00 05  |....!.... ......|
0000b810  9d 00 06 9d e8 06 e8 d0  f1 a2 00 bd 30 c0 f0 0c  |............0...|
0000b820  9d 00 04 a9 02 9d 00 d8  e8 4c 1a c0 a9 01 85 d6  |.........L......|
0000b830  60 08 05 0c 0c 0f 20 17  0f 12 0c 04 00           |\`..... ......|

A closer examination of the bytes in the PRG file. Note that C64 uses little-endian byte-ordering.

 01 08 = $0801
When a prg file is loaded with ",1" at the end of the LOAD command ( load "world",8,1 )
the the first two bytes are used by the KERNAL as the first address of memory at which to place
the rest of the file. That means that the first two bytes are not descibing anything to be but
in memory, but rather, where to put the rest of the file. So, when loading this program, the
KERNAL will place the first byte ( 0c ) in memory location $0801, and the next byte ( 08 )
in location $0802, and so on. $0801 is the first usable byte of BASIC memory, so, the bytes
will be loaded into basic memory. That is because the BasicUpstart2 macro at the beginning of
our assembler listing, generated this load address and a little BASIC program for us, the content
of the BASIC program is: "10 SYS 49152"

Let's take a look at the next two bytes of our prg file,
these are the bytes loaded into $0801 and $0802.
0c 08 = $080c 
BASIC programs are stored in memory in the following format:
PP PP LL LL TT  NN     PP PP ...
  |     |    |  |        |
  |     |    |  |        +--------------------------------------------+
  |     |    |  |                                                     | 
  |     |    |  + Null byte, indicating end of basic line             |
  |     |    + Token/ASCII/Data, multiple tokens/data bytes allowed.  |
  |     + Line number (16 bit)                                        |
  + Memory address of the NEXT line (so, the byte right after NN) ----+

0c 08 is thus the pointer to the NEXT BASIC line after the one that comes now.
 
0a 00 is the BASIC line number for the lines that comes now ( $000a = 10 ).

9e is the BASIC token for the SYS command, so, in BASIC, the letters for each
command is not saved, but rather converted to and from single-byte tokens,
much faster and takes up a lot less memory and storage.

34  39 31 35 32 = The PETSCII string "49152", which is the argument to the SYS command.
It is the decimal notation for $c000, the address of our first
assembler instruction. Note that this is treated as TEXT and not an integer,
which is why it takes up so many bytes, and why it is not in little-endian order.

00 This is the terminator for the BASIC line.

00 00 This is the pointer to the next basic line, it having a value of zero means
end of BASIC program. These two zeroes, are what the pointer 0c 08 points to.
Try, from $0801, add the number of bytes of our basic program, you end up at $080c.

The following zeroes are simply padding until address $C000.
Note that the hexdump shows the first byte as being at b801, but recall that
the prg file was loaded into memory beginnning at $0801.
Well, the first two bytes of the file is not loaded into memory, so
if we do 0x0801 + 0x0b801 - 2 we get the value: 0xc000

Time has come for our assembler program, the first byte located at $0c000
thanks to being offset by all that zero padding.

a9 =  OPcode for immediate-addressing-mode LDA, produced by LDA #0
00 = The single-byte operand for that instruction.
8d = OPcode for absolute-addressing-mode STA
21 d0 = $d021 = The two-byte operand for that instruction.
You can do the rest if you want to.

## hello world 1.5

The next iteration of the hello-world program makes a routine out of the code that printed the characters. That was done by adding some code to calculate the offset into screen memory and a bit of code to handle taking "arguments" in different ways.

Useful subroutines often take one or more arguments, and there are different ways of provding those arguments, depending on whether the routine needs to be re-entrant. The print routine does not. So I use in-place modification of some of the parameters, this can be done by placing a label at the instruction, and jumping the over the instrunction (thus reaching the operand address) by adding 1 to the label address.

Find the relevant parts below: (or [download full hello1\_5.asm program here](https://dusted.dk/pages/c64/C64-programming/files/asm/hello1_5.asm))

// Put our texts a few places on screen
lda #txt
sta strPtr+2

lda #1
sta col+1
lda #0
ldy #0
jsr puts

lda #2
sta col+1
lda #10
ldy #8
jsr puts

lda #3
sta col+1
lda #17
ldy #15
jsr puts


lda #<txt2
sta strPtr+1
lda #>txt2
sta strPtr+2
lda #4
sta col+1
lda #20
ldy #24
jsr puts

// exit to basic, for example
rts

// puts: Print a string to the screen
// strPtr+1 = 16 bit pointer to the string to show
// col +1 = the color
// a = column, y = row

puts:                     // First, calculate offsets into screen and color memory
            sta scrOffs+1 // screen lowbyte is 00, so we just put the column directly.
            sta colOffs+1 // same goes for color lowbyte
            lda #>screen
            sta scrOffs+2
            lda #>color
            sta colOffs+2

            iny // add one to y so we can have y = 0 on first iteration.
  rloop:    dey
            beq putnext // skip when y reaches zero

            lda #40 // there are 40 columns to a row
            adc scrOffs+1
            clc // Clear the carry flag for the next add instruction.
            sta scrOffs+1
            lda #40
            adc colOffs+1
            sta colOffs+1
            bcc rloop     // if the carry bit was not set, just loop more
            clc           // if it was set, clear it and handle high-bytes
            inc scrOffs+2
            inc colOffs+2
            jmp rloop

  putnext:  ldx #0        // Let's use the X register as the index into our text string.

  strPtr:   lda $ffff,x   // Load the character at txt+x bytes
            beq exit      // If lda set zero bit we loaded the "null" byte after the string and we exit.
  scrOffs:  sta $ffff,x   // Else put it on the screen.
  col:      lda #00       // Load 2 (the color red) into the A register
  colOffs:  sta $ffff,x   // And put it at the corrosponding color-memory.
            inx           // Increase the index
            jmp strPtr    // and repeat
  exit:     rts



    

## hello numbers!

I spent a fair deal of time wrapping my head around how to implement a simple "itoa" (integer to string) routine, and finally decided that for my uses, dealing with binary coded decimal is waaaahy easier.. I'm pretty satisfied that I was able to come up with these small routines myself, after failing to get the math behind the ones I've read online. Sure, they have disadvantages, and they probably run slow, but they're mine and I understand how they work. Integrating them into the hello-world program, is left as an exercise for the reader. I've not implemented a nice way of passing parameters to them yet, I will have to read up on zero-page addressing modes for that I'm afraid.

// Convert the number in the 10 bcd bytes to a string

// What's neat about decimal mode, is that instead of a byte holding from 0 to 255
// It holds from 0-99, and the way the bits are packed, is that the first
// nibble is the "tens" and the last nibble is the "ones"
// So the byte 0101 0011 in hex is $53 right, the decimal value when
// interpreting the number as binary, is 83, but look at those nibbles!
// 0101 = 5, and 0011 = 3.. so if we interpret it as BCD, the decimal value
// is actually 53, just as the hex representation.

// So now, to convert to strings, we simply go through the bytes in our decimal
// number one nibble at a time, and emit a character code for each. And find the
// character codes is easy as well:
// The reason we can OR with '$30' is because the last 4 bytes
// of the character code is zero, and the BCD number is 4 bytes long, so it
// "just so happens" to fit there. Otherwise, we could have added instead.
// The logic is: $30 = 0011 0000 = '0' so if we had.. A nibble of decimal value 5
// then we'd have for example a byte '0000 0101' in binary, if we OR those values:
// 0011 0000 O
// 0000 0101 R
// ---------
// 0011 0101 = 35 = '5'

// But wait! There are two decimal numbers in each byte?
// Easy, we just take them one at a time. First we mask out the high nibble,
// and emit our character code for that number, then we mask out the low nibble
// and shift the remainding bits down into the low nibble and use the same method
// to emit the next byte.
// Just note that the bytes come out "in reverse", so we store them from
// the end of the string towards the start, so it comes out in the right order.

bcdtos:
    ldx #$00        // Counter into the bcd number
    ldy #19         // counter into the string, starting from rightmost byte
bcdtosLoop:
    lda score,x     // Load a byte from the number
    and #$0f        // Keep only last 4 bits
    ora #$30        // OR them with the character code for '0'
    sta scoreStr,y  // Store the character in the string
    dey             // Move one left in the string
    lda score,x     // Load the same byte again
    and #$f0        // Keep only the first 4 bits
    ror             // Rotate those bits so they are the last 4 bits.
    ror
    ror
    ror
    ora #$30        // OR with the '0' character again.
    sta scoreStr,y  // and store it in the next location
    dey             // and move one more to the left in the string
    inx             // Next byte in the BCD number
    cpx #10         // Check if that was the last (our number is 10 bytes)
    bne bcdtosLoop  // if now, repeat.
    rts


// Add number (from 0 to 99) to the 10 byte bcd number.
// Note, to add the decimal number 53, do lda #$53 and then jsr bcdAdd
// Parameter: A - Number to add
bcdAdd:
    sei               // Disable interrupts, it may be bad when in BCD mode
    ldx #0            // Start from first byte in number (little endian
    sed               // Set Decimal mode
bcdCarryLoop:
    clc               // Clear the carry
    adc score,x       // Add whatever was in A with the byte
    sta score,x       // Store the result
    bcc bcdAddEnd     // If no carry, we're done.
    lda #1            // Otherwise, we'll add 1 to the NEXT byte
    inx               // So we target the next byte
    jmp bcdCarryLoop  // to add it (it's in A, remember!)
bcdAddEnd:            // When we're done
    cld               // Clear Decimal mode
    cli               // Enable interrupts
    rts


// Strips leading zeroes from the string
stripZero:
    ldx #0          // Start from first byte (leftmost) in string
stripZLoop:
    lda scoreStr,x  // Load that byte
    cmp #'0'        // See if it's the 0 character
    bne stripZEnd   // If it is NOT a zero, we're done
    lda #' '        // Else, a space is
    sta scoreStr,x  // saved instead.
    inx             // Target next byte
    jmp stripZLoop
stripZEnd:
    rts


// In the "constants" part of the program, which I chose to be after all the
// instructions, I added two labels, one for the destination string, and one
// for storing a giant bcd number.
scoreStr:
    .text "                                        "
    .byte 0
score:
    .byte $00, $00, $00, $00, $00, $00, $00, $00, $00, $00 // 10 byte little endian bcd number,
                                                           // Max = 99999999999999999999.



    

## Hello Macros

So, recall how to use puts.. First, we load and store lowbyte and highbyte and color, then we load two registers, a with row and x with column where we want the text placed and THEN we jsr to the subroutine..

    lda #<txt     // 1
    sta strPtr+1  // 2
    lda #>txt     // ...
    sta strPtr+2

    lda #1
    sta col+1
    
    lda #10
    ldx #15

    jsr puts     // 9 instructions!

And if that's not enough, the subroutine uses another 21 instructions on calculating and storing the offsets.. Now, how many instruction does it take to copy the string into screen memory? It takes 8.. and a 9th to return from the subroutine. I'm \_SURE\_ there are shorther ways to do this, (that is, to write a subroutine that allows you to place any string anywhere in any color), but this was what I came up with and it's not terrible as such, but it is wasteful for all those cases where I don't need that kind of flexibility.. For instance, what if it's always the same string to the same position, maybe even in the same color? Then I'm actually only needing those 8 instructions, and I don't need a subroutine at all!

### enter the macro

So, a less flexible, but faster and shorter way of placing "the same string in the same place" is to use a macro to generate the 8 instructions for us, let's call it sputs (static puts):

.macro sputs(strPtr, row, column, colorNum) {
            .var offset = row \* 40 + column
            ldx #0        // Let's use the X register as the index into our text string.
putsLoop:   lda strPtr,x   // Load the character at txt+x bytes
            beq exit      // If lda set zero bit we loaded the "null" byte after the string and we exit.
            sta screen+ offset,x   // Else put it on the screen.
            lda #colorNum       // Load color into the A register
            sta color+offset,x   // And put it at the corrosponding color-memory.
            inx           // Increase the index
            jmp putsLoop  // and repeat
  exit: // label points to "whatever comes after these instructions"
}

Now, look at that! it looks like a function! And we get to do math in there, like multiplication and stuff! Like everywhere else where we do "label+something" the assembler does the calculations on those labels for us, and inserts the new result. So, this is NOT a function even if it looks like it, the assembler will simply inser the code wherever the macro is called. And this is how we'd call it:

sputs(txt, 10, 15, 1)

Note that we cannot make the text move around with this, and we cannot change which string it points to (but we can chance the contents of the string), we can also chance the color, but to do that, we'd hack a bit, we can count that the color lda is just around the 12th byte into the macro, so if we labelled the macro, we can easily poke another number in there:

lda colorPtr
sta colorChangingString+12
colorChangingString: sputs(txt, 10, 15, 1)

And those BCD routines, they're a bit longer than the number of instructions it takes to set them up, but not much, and if you think about it, then unless you're running out of memory, maybe it'd be nicer to not spend so many instructions on "doing nothing" and instead spend a bit more memory on duplicating the code where it's needed. This is something I'm finding difficult to get my head around, because I come from C with all its fancy functions any types and other modern conveniences.

If you're interested, I've put some of my macros into this file: [hello\_macro.asm](https://dusted.dk/pages/c64/C64-programming/files/asm/hello_macro.asm)

Stay tuned for Hello Sprite...

## Hello Raster Interrupt

For many kinds of real-time interactive software, like games and demos, it's desirable to have some control over the speed that our program execute. For example, being able to run some code "every frame" and also know that the time between each time the code runs (assuming the code is fast enough to finish within the time a frame takes, which at PAL speed is 1/50 of a second, or 20 milliseconds.

The C64 supports us configuring an interrupt to occur when the VIC chip reaches a raster-line of our choice. We can then have our code be executed when that happens, in effect giving us control over when our code is run.

Another happy side effect of this, is that it enables some neat trick to measure CPU usage. But more about that in the next section.

// Setup raster interrupt
    lda #%01111111
    sta [$DC0D](https://dusted.dk/pages/c64/C64-programming/files/Commodore%2064%20memory%20map%20named.html#DC0D)       // Disable interrupt on timer-a underflow 
    and [$D011](https://dusted.dk/pages/c64/C64-programming/files/Commodore%2064%20memory%20map%20named.html#D011)
    sta $D011       // Bit 7 is the "msb" of the "interrupt on raster-line", because there are over 255 raster lines.
    lda #20         // We just want our interrupt at line 20.
    sta $D012       // So we store that in the lowbyte of the "interrupt on raster line"
    lda #<Irq       // Highbyte of the code we want to have run on interrupt
    sta [$0314](https://dusted.dk/pages/c64/C64-programming/files/Commodore%2064%20memory%20map%20named.html#0314)
    lda #>Irq       // Lowbyte of that code
    sta $0315       // Store the pointer to the code (it's called an ISR, Interrupt Service Routine)
    lda #%00000001  // Then set bit 0, which enables raster interrupt from the VIC
    sta [$D01A](https://dusted.dk/pages/c64/C64-programming/files/Commodore%2064%20memory%20map%20named.html#D01A)

// Loop forever
forever: jmp forever

// Executed each time the VIC chip hits line 20.
Irq:
    // Do whatever we want..
    nop
    asl [$D019](https://dusted.dk/pages/c64/C64-programming/files/Commodore%2064%20memory%20map%20named.html#D019) // Acknowledge the interrupt
    jmp $EA31 // And jump to the kernal interrupt service routine, so we can still 
              // use kernal functions, like the keyboard scanning.

## Hello CPU usage

Now that we know our code starts once per frame, we can exploit the stability to "see" how much time our code takes. It's really neat, visually, we can get a good idea about how much "frame time" we're using. The idea is super simple: Before running some piece of code, we change the border color.. Then after the piece of code, we change it back.

![CPU usage can be seen by changing border color](./DusteDs home in cyberspace __ Commodore 64 programming notes_files/hello_cpusage.jpg)

    .const border = [$D020](https://dusted.dk/pages/c64/C64-programming/files/Commodore%2064%20memory%20map%20named.html#D020)
    .const black = 0
    .const white = 1
    .const red = 2
    .const cyan = 3
    .macro borCol(col) {
        lda #col
        sta border
    }

//setup interrupt as before..
...


// Let's loop forever, changing the color of the border to black
forever:
    borCol(black)
    jmp forever

Irq:
    // Change border color to white to "measure" how much time this block takes.
    borCol(white)
    jsr someRoutine
    // Let's see how long the next thing takes
    borCol(red)
    jsr somethingElse
    // Then, since we do let the kernal stuff run, let's also measure that
    borCol(cyan)
    asl [$D019](https://dusted.dk/pages/c64/C64-programming/files/Commodore%2064%20memory%20map%20named.html#D019) // ack the interrupt
    jmp $EA31 // and let kernal run

## Hello Color Memory

The color memory is normally located at [$D800](https://dusted.dk/pages/c64/C64-programming/files/Commodore%2064%20memory%20map%20named.html#D800), note how it says "only bits 0-3", that's important. The memory for the colors is a 4 bit chip, so only the lower 4 bits of the byte is valid. Therefore, if you read from color memory for any reason, you must mask off the upper 4 bits. Otherwise, you may read trash bits along with your 4 color bits, this is important if you want to for example compare a value you read from color memory.

        lda $D810 // read the color of character 11.
        and #$0F  // AND the value, so only the lower 4 bits are kept in register A
        // now A is ready to use, containing the correct value of what was at that memory location.
    

## Tools and references

*   KickAssembler [Official website](http://theweb.dk/KickAssembler/Main.html) ([V5.16 locally archived](https://dusted.dk/pages/c64/C64-programming/files/KickAssembler.zip))
*   KickAssembler Manual [Official website](http://theweb.dk/KickAssembler/webhelp/content/cpt_Introduction.html) ([V5.16 pdf locally archived](https://dusted.dk/pages/c64/C64-programming/files/KickAssembler.pdf))
*   Memory Map [https://sta.c64.org/cbm64mem.html](https://sta.c64.org/cbm64mem.html) ([locally archived 2020-09-01](https://dusted.dk/pages/c64/C64-programming/files/Commodore%2064%20memory%20map.html))
*   STAs C64 documentations: [https://sta.c64.org/cbmdocs.html](https://sta.c64.org/cbmdocs.html) ([locally archived 2020-09-01](https://dusted.dk/pages/c64/C64-programming/files/sta_c64_org/cbmdocs.html))
*   Instruction Set [https://www.masswerk.at/6502/6502\_instruction\_set.html](https://www.masswerk.at/6502/6502_instruction_set.html) ([locally archived 2020-09-01](https://dusted.dk/pages/c64/C64-programming/files/6502%20Instruction%20Set.html))
*   Ultimate Documentation (not really, but nice) [Official github](https://github.com/mist64/c64ref) ([locally archived and rendered 2020-09-01](https://dusted.dk/pages/c64/C64-programming/files/c64ref/kernal/index.html))
*   VIM Syntax highlight [Official website](https://bitbucket.org/gryf/kickass-syntax-vim/src/master/) ([locally archived 2020-09-01](https://dusted.dk/pages/c64/C64-programming/files/kickass.vim))
*   Visual Studio Code KickAssembler extension [Official website](https://marketplace.visualstudio.com/items?itemName=paulhocker.kick-assembler-vscode-ext)
*   PETSCII Editor (is awesome) [petscii.krissz.hu](http://petscii.krissz.hu/)
*   Online Sprite Editor [https://spritemate.com/](https://spritemate.com/)

- - -

Last edited: 2020-09-01 - No need for a disclaimer, I've done nothing wrong!

[<‐ Back](https://dusted.dk/pages/c64/)
