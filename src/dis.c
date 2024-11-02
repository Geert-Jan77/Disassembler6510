//dis.c compiler gcc 11.7, OS win7, dis.exe disassembles machinecode for the commodore 64 processor. github Disassembler6510

#include <stdio.h>

int main(int argc, char * argv[])
{
		void memlocation(int iMemory)
{
	if ((iMemory == 0)) { printf("6510 On-chip Data Direction Register. set= Output, clear= Input"); }
	if ((iMemory == 1)) { printf("6510 On-chip 8-bit Input/Output Register. b0 /LORAM Signal (0=Switch BASIC ROM Out)  b1 /HIRAM Signal (0=Switch Kernal ROM Out)  b2 /CHAREN Signal (O=Swith Char. ROM In)  b3 Cassette Data Output Line  b4 Cassette Switch Sense: 1 = Switch Closed b5 Cassette Motor Control O = ON, 1 = OFF"); }
	if ((iMemory == 2)) { printf("Unused. Free for user programs."); }
	if ((iMemory == 3)) { printf("Jump Vector: Convert FAC to Integer in (A/Y)(45482)."); }
	if ((iMemory == 5)) { printf("Jump Vector: Convert Integer in (A/Y) to floating point in (FAC); (45969)."); }
	if ((iMemory == 7)) { printf("Search Character"); }
	if ((iMemory == 8)) { printf("Flag: Scan for Quote at End of String"); }
	if ((iMemory == 9)) { printf("Screen Column From Last TAB"); }
	if ((iMemory == 10)) { printf("Flag: 0 = Load, 1 = Verify"); }
	if ((iMemory == 11)) { printf("Input Buffer Pointer / No. of Subscripts"); }
	if ((iMemory == 12)) { printf("Flag: Default Array DiMension"); }
	if ((iMemory == 13)) { printf("Data Type: 255 = String, 0 = Numeric"); }
	if ((iMemory == 14)) { printf("Data Type: 128 = Integer, 0 = Floating"); }
	if ((iMemory == 15)) { printf("Flag: DATA scan/LlST quote/Garbage Coll"); }
	if ((iMemory == 16)) { printf("Flag: Subscript Ref / User Function Call"); }
	if ((iMemory == 17)) { printf("Flag: 0 = INPUT, 64 = GET, 152 = READ"); }
	if ((iMemory == 18)) { printf("Flag TAN sign / Comparison Result"); }
	if ((iMemory == 19)) { printf("Flag: INPUT Prompt"); }
	if ((iMemory == 20)) { printf("Temp: Integer Value"); }
	if ((iMemory == 22)) { printf("Pointer Temporary String"); }
	if ((iMemory == 23)) { printf("Last Temp String Address"); }
	if ((iMemory >= 25)&&(iMemory <= 33)) { printf("00025 Stack for Temporary Strings"); }
	if ((iMemory >= 34)&&(iMemory <= 37)) { printf("00034 Utility Pointer Area"); }
	if ((iMemory >= 38)&&(iMemory <= 42)) { printf("00038 Floating-Point Product of Multiply"); }
	if ((iMemory == 43)) { printf("Pointer: Start of BASIC Text"); }
	if ((iMemory == 45)) { printf("Pointer: Start of BASIC Variables"); }
	if ((iMemory == 47)) { printf("Pointer: Start of BASIC Arrays"); }
	if ((iMemory == 49)) { printf("Pointer End of BASIC Arrays (+1)"); }
	if ((iMemory == 51)) { printf("Pointer: Bottom of String Storage"); }
	if ((iMemory == 53)) { printf("Utility String Pointer"); }
	if ((iMemory == 55)) { printf("Pointer: Highest Address Used by BASIC"); }
	if ((iMemory == 57)) { printf("Current BASIC Line Number"); }
	if ((iMemory == 59)) { printf("Previous BASIC Line Number"); }
	if ((iMemory == 61)) { printf("Pointer: BASIC Statement for CONT"); }
	if ((iMemory == 63)) { printf("Current DATA Line Number"); }
	if ((iMemory == 65)) { printf("Pointer: Current DATA Item Address"); }
	if ((iMemory == 67)) { printf("Vector: INPUT Routine"); }
	if ((iMemory == 69)) { printf("Current BASIC Variable Name"); }
	if ((iMemory == 71)) { printf("Pointer: Current BASIC Variable Data"); }
	if ((iMemory == 73)) { printf("Pointer: Index Variable for FOR/NEXT"); }
	if ((iMemory >= 75)&&(iMemory <= 96)) { printf("00075 Temp Pointer / Data Area"); }
	if ((iMemory == 97)) { printf("Floating-Point Accumulator #1: Exponent"); }
	if ((iMemory >= 98)&&(iMemory <= 101)) { printf("00098 Floating Accum. #1: Mantissa"); }
	if ((iMemory == 102)) { printf("Floating Accum. #1: Sign"); }
	if ((iMemory == 103)) { printf("Pointer: Series Evaluation Constant"); }
	if ((iMemory == 104)) { printf("Floating -accum. #1: Overflow Digit"); }
	if ((iMemory == 105)) { printf("Floating-Point Accumulator #2: Exponent"); }
	if ((iMemory == 106)||(iMemory == 109)) { printf("00106 Floating Accum. #2: Mantissa"); }
	if ((iMemory == 110)) { printf("Floating Accum. #2: Sign"); }
	if ((iMemory == 111)) { printf("Sign Comparison Result: Accum. # 1 vs #2"); }
	if ((iMemory == 112)) { printf("Floating Accum. #1. Low-Order (Rounding)"); }
	if ((iMemory == 113)) { printf("Pointer: Cassette Buffer"); }
	if ((iMemory >= 115)&&(iMemory <= 138)) { printf("00115 Subroutine: Get Next Byte of BASIC Text"); }
	if ((iMemory == 121)) { printf("Entry to Get Same Byte of Text Again"); }
	if ((iMemory == 122)) { printf("Pointer: Current Byte of BASIC Text"); }
	if ((iMemory >= 139)&&(iMemory <= 143)) { printf("00139 Floating RND Function Seed Value"); }
	if ((iMemory == 144)) { printf("Kernal l/O Status Word: ST"); }
	if ((iMemory == 145)) { printf("Flag: STOP key / RVS key"); }
	if ((iMemory == 146)) { printf("Timing Constant for Tape"); }
	if ((iMemory == 147)) { printf("Flag: 0 = Load, 1 = Verify"); }
	if ((iMemory == 148)) { printf("Flag: Serial Bus-Output Char. Buffered"); }
	if ((iMemory == 149)) { printf("Buffered Character for Serial Bus"); }
	if ((iMemory == 150)) { printf("Cassette Sync No."); }
	if ((iMemory == 151)) { printf("Temp Data Area"); }
	if ((iMemory == 152)) { printf("No. of Open Files / Index to File Table"); }
	if ((iMemory == 153)) { printf("Default Input Device (0)"); }
	if ((iMemory == 154)) { printf("Default Output (CMD) Device (3)"); }
	if ((iMemory == 155)) { printf("Tape Character Parity"); }
	if ((iMemory == 156)) { printf("Flag: Tape Byte-Received"); }
	if ((iMemory == 157)) { printf("Flag: 128 = Direct Mode, 0 = Program"); }
	if ((iMemory == 158)) { printf("Tape Pass 1 Error Log"); }
	if ((iMemory == 159)) { printf("Tape Pass 2 Error Log"); }
	if ((iMemory >= 160)&&(iMemory <= 162)) { printf("00160 Real-Time Jiffy Clock (approx) 1/60 Sec"); }
	if ((iMemory == 163)||(iMemory == 164)) { printf("00163 Temp Data Area"); }
	if ((iMemory == 165)) { printf("Cassette Sync Countdown"); }
	if ((iMemory == 166)) { printf("Pointer: Tape l/O Buffer"); }
	if ((iMemory == 167)) { printf("RS-232 Input Bits / Cassette Temp"); }
	if ((iMemory == 168)) { printf("RS-232 Input Bit Count / Cassette Temp"); }
	if ((iMemory == 169)) { printf("RS-232 Flag: Check for Start Bit"); }
	if ((iMemory == 170)) { printf("RS-232 Input Byte Buffer/Cassette Temp"); }
	if ((iMemory == 171)) { printf("RS-232 Input Parity / Cassette Short Cnt"); }
	if ((iMemory == 172)) { printf("Pointer: Tape Buffer/ Screen Scrolling"); }
	if ((iMemory == 174)) { printf("Tape End Addresses/End of Program"); }
	if ((iMemory == 176)) { printf("Tape Timing Constants"); }
	if ((iMemory == 178)) { printf("Pointer: Start of Tape Buffer"); }
	if ((iMemory == 180)) { printf("RS-232 Out Bit Count / Cassette Temp"); }
	if ((iMemory == 181)) { printf("RS-232 Next Bit to Send/ Tape EOT Flag"); }
	if ((iMemory == 182)) { printf("RS-232 Out Byte Buffer"); }
	if ((iMemory == 183)) { printf("Length of Current File Name"); }
	if ((iMemory == 184)) { printf("Current Logical File Number"); }
	if ((iMemory == 186)) { printf("Current Device Number"); }
	if ((iMemory == 187)) { printf("Pointer: Current File Name"); }
	if ((iMemory == 189)) { printf("RS-232 Out Parity / Cassette Temp"); }
	if ((iMemory == 190)) { printf("Cassette Read / Write Block Count"); }
	if ((iMemory == 191)) { printf("Serial Word Buffer"); }
	if ((iMemory == 192)) { printf("Tape Motor Interlock"); }
	if ((iMemory == 193)) { printf("I/O Start Address"); }
	if ((iMemory == 195)) { printf("Tape Load Temps"); }
	if ((iMemory == 197)) { printf("Current Key Pressed: CHR$(n) 0 = No Key"); }
	if ((iMemory == 198)) { printf("No. of Chars. in Keyboard Buffer (Queue)"); }
	if ((iMemory == 199)) { printf("Flag: Print Reverse Chars. -1=Yes, 0=No Used"); }
	if ((iMemory == 200)) { printf("Pointer: End of Logical Line for INPUT"); }
	if ((iMemory == 201)) { printf("Cursor X-Y Pos. at Start of INPUT"); }
	if ((iMemory == 203)) { printf("Flag: Print Shifted Chars."); }
	if ((iMemory == 204)) { printf("Cursor Blink enable: 0 = Flash Cursor"); }
	if ((iMemory == 205)) { printf("Timer: Countdown to Toggle Cursor"); }
	if ((iMemory == 206)) { printf("Character Under Cursor"); }
	if ((iMemory == 207)) { printf("Flag: Last Cursor Blink On/Off"); }
	if ((iMemory == 208)) { printf("Flag: INPUT or GET from Keyboard"); }
	if ((iMemory == 209)) { printf("Pointer: Current Screen Line Address"); }
	if ((iMemory == 211)) { printf("Cursor Column on Current Line"); }
	if ((iMemory == 212)) { printf("Flag: Editor in Quote Mode, 0 = NO"); }
	if ((iMemory == 213)) { printf("Physical Screen Line Length"); }
	if ((iMemory == 214)) { printf("Current Cursor Physical Line Number"); }
	if ((iMemory == 215)) { printf("Temp Data Area"); }
	if ((iMemory == 216)) { printf("Flag: Insert Mode, >0 = # INSTs"); }
	if ((iMemory >= 217)&&(iMemory <= 242)) { printf("00217 Screen Line Link Table / Editor Temps"); }
	if ((iMemory == 243)) { printf("Pointer: Current Screen Color RAM loc."); }
	if ((iMemory == 245)) { printf("Vector Keyboard Decode Table"); }
	if ((iMemory == 247)) { printf("RS-232 Input Buffer Pointer"); }
	if ((iMemory == 249)) { printf("RS-232 Output Buffer Pointer"); }
	if ((iMemory >= 251)&&(iMemory <= 254)) { printf("00251 Free 0-Page Space for User Programs"); }
	if ((iMemory == 255)) { printf("BASIC Temp Data Area"); }
	if ((iMemory >= 256)&&(iMemory <= 511)) { printf("00256 Micro-Processor System Stack Area"); }
	//if ((iMemory >00256)&&(iMemory <00266)) { printf("Floating to String Work Area"); }
	//if ((iMemory >00256)&&(iMemory <00318)) { printf("Tape Input Error Log"); }
	if ((iMemory >= 512)&&(iMemory <= 600)) { printf("00512 System INPUT Buffer"); }
	if ((iMemory >= 601)&&(iMemory <= 610)) { printf("00601 KERNAL Table: Active Logical File No's."); }
	if ((iMemory >= 611)&&(iMemory <= 620)) { printf("00611 KERNAL Table: Device No. for Each File"); }
	if ((iMemory >= 621)&&(iMemory <= 630)) { printf("00621 KERNAL Table: Second Address Each File"); }
	if ((iMemory >= 631)&&(iMemory <= 640)) { printf("00631 Keyboard Buffer Queue (FIFO) "); }
	if ((iMemory == 641)) { printf("Pointer: Bottom of Memory for O.S."); }
	if ((iMemory == 643)) { printf("Pointer: Top of Memory for O.S."); }
	if ((iMemory == 645)) { printf("Flag: Kernal Variable for IEEE Timeout"); }
	if ((iMemory == 646)) { printf("Current Character Color Code"); }
	if ((iMemory == 647)) { printf("Background Color Under Cursor"); }
	if ((iMemory == 648)) { printf("Top of Screen Memory (Page)"); }
	if ((iMemory == 649)) { printf("Size of Keyboard Buffer"); }
	if ((iMemory == 650)) { printf("Flag: REPEAT Key Used, 128 = Repeat"); }
	if ((iMemory == 651)) { printf("Repeat Speed Counter"); }
	if ((iMemory == 652)) { printf("Repeat Delay Counter"); }
	if ((iMemory == 653)) { printf("Flag: Keyb'rd SHIFT Key/CTRL Key/C= Key"); }
	if ((iMemory == 654)) { printf("Last Keyboard Shift Pattern"); }
	if ((iMemory == 655)) { printf("Vector: Keyboard Table Setup"); }
	if ((iMemory == 657)) { printf("Flag: 0=Disable SHIFT Keys, 128 = Enable SHIFT Keys"); }
	if ((iMemory == 658)) { printf("Flag: Auto Scroll Down, 0 = ON"); }
	if ((iMemory == 659)) { printf("RS-232: 6551 Control Register Image"); }
	if ((iMemory == 660)) { printf("RS-232: 6551 Command Register Image"); }
	if ((iMemory == 661)) { printf("RS-232 Non-Standard BPS (Time/2-100) USA"); }
	if ((iMemory == 663)) { printf("RS-232: 6551 Status Register Image"); }
	if ((iMemory == 664)) { printf("RS-232 Number of Bits Left to Send "); }
	if ((iMemory == 665)) { printf("RS-232 Baud Rate: Full Bit Time (us)"); }
	if ((iMemory == 667)) { printf("RS-232 Index to End of Input Buffer"); }
	if ((iMemory == 668)) { printf("RS-232 Start of Input Buffer (Page)"); }
	if ((iMemory == 669)) { printf("RS-232 Start of Output Buffer (Page)"); }
	if ((iMemory == 670)) { printf("RS-232 Index to End of Output Buffer"); }
	if ((iMemory == 671)) { printf("Holds IRQ Vector During Tape I/O"); }
	if ((iMemory == 673)) { printf("RS-232 Enables"); }
	if ((iMemory == 674)) { printf("TOD Sense During Cassette I/O"); }
	if ((iMemory == 675)) { printf("Temp Storage For Cassette Read"); }
	if ((iMemory == 676)) { printf("Temp D1 IRQ Indicator For Cassette Read"); }
	if ((iMemory == 677)) { printf("Temp For Line Index"); }
	if ((iMemory == 678)) { printf("PAL/NTSC Flag, O= NTSC, 1 = PAL"); }
	if ((iMemory >= 679)&&(iMemory <= 767)) { printf("00679 Unused"); }
	if ((iMemory == 768)) { printf("Vector: Print BASIC Error Message"); }
	if ((iMemory == 770)) { printf("Vector: BASIC Warm Start"); }
	if ((iMemory == 772)) { printf("Vector: Tokenize BASIC Text"); }
	if ((iMemory == 774)) { printf("Vector: BASIC Text LIST"); }
	if ((iMemory == 776)) { printf("Vector: BASIC Char. Dispatch"); }
	if ((iMemory == 778)) { printf("Vector: BASIC Token Evaluation"); }
	if ((iMemory == 780)) { printf("Storage for 6502 .A Register"); }
	if ((iMemory == 781)) { printf("Storage for 5502 .X Register"); }
	if ((iMemory == 782)) { printf("Storage for 6502 .Y Register"); }
	if ((iMemory == 783)) { printf("Storage for 6502 .SP Register"); }
	if ((iMemory == 784)) { printf("USR Function Jump Instr (4C)"); }
	if ((iMemory == 785)) { printf("USR Address Low Byte / High Byte"); }
	if ((iMemory == 787)) { printf("Unused"); }
	if ((iMemory == 788)) { printf("Vector: Hardware Interrupt"); }
	if ((iMemory == 790)) { printf("Vector: BRK Instr. Interrupt"); }
	if ((iMemory == 792)) { printf("Vector: Non-Maskable Interrupt"); }
	if ((iMemory == 794)) { printf("KERNAL OPEN Routine Vector"); }
	if ((iMemory == 796)) { printf("KERNAL CLOSE Routine Vector"); }
	if ((iMemory == 798)) { printf("KERNAL CHKIN Routine"); }
	if ((iMemory == 800)) { printf("KERNAL CHKOUT Routine"); }
	if ((iMemory == 802)) { printf("KERNAL CLRCHN Routine Vector"); }
	if ((iMemory == 804)) { printf("KERNAL CHRIN Routine"); }
	if ((iMemory == 806)) { printf("KERNAL CHROUT Routine"); }
	if ((iMemory == 808)) { printf("KERNAL STOP Routine Vector"); }
	if ((iMemory == 810)) { printf("KERNAL GETIN Routine"); }
	if ((iMemory == 812)) { printf("KERNAL CLALL Routine Vector"); }
	if ((iMemory == 814)) { printf("User-Defined Vector"); }
	if ((iMemory >= 813)&&(iMemory <= 817)) { printf("KERNAL LOAD Routine"); }
	if ((iMemory == 818)) { printf("KERNAL SAVE Routine Vector"); }
	if ((iMemory >= 820)&&(iMemory <= 827)) { printf("Unused"); }
	if ((iMemory >= 828)&&(iMemory <= 1019)) { printf("Tape l/O Buffer"); }
	if ((iMemory >= 1020)&&(iMemory <= 1023)) { printf("Unused"); }
	if ((iMemory >= 1024)&&(iMemory <= 2023)) { printf("Video Matrix: 25 Lines X 40 Columns"); }
	if ((iMemory >= 2024)&&(iMemory <= 2039)) { printf("Extra screen Memory Area 16 byte"); }
	if ((iMemory >= 2040)&&(iMemory <= 2047)) { printf("Sprite Data Pointers"); }
	if ((iMemory >= 2048)&&(iMemory <= 40959)) { printf("Program Space 38911 bytes                "); }
	if ((iMemory >= 40960)&&(iMemory < 40972)) { printf("Restart Vectors "); }
	if ((iMemory >= 40972)&&(iMemory < 41042)) { printf("BASIC Command Vectors   "); }
	if ((iMemory >= 41042)&&(iMemory < 41088)) { printf("BASIC Function Vectors "); }
	if ((iMemory >= 41088)&&(iMemory < 41118)) { printf("BASIC Operator Vectors         "); }
	if ((iMemory >= 41118)&&(iMemory < 41257)) { printf("BASIC Command Keyword Table      "); }
	if ((iMemory >= 41257)&&(iMemory < 41280)) { printf("BASIC Misc. Keyword Table     "); }
	if ((iMemory >= 41280)&&(iMemory < 41293)) { printf("BASIC Operator Keyword Table       "); }
	if ((iMemory >= 41293)&&(iMemory < 41374)) { printf("BASIC Function Keyword Table      "); }
	if ((iMemory >= 41374)&&(iMemory < 41768)) { printf("Error Message Table             "); }
	if ((iMemory >= 41768)&&(iMemory < 41828)) { printf("Error Message Pointers        "); }
	if ((iMemory >= 41828)&&(iMemory < 41866)) { printf("Misc. Messages   "); }
	if ((iMemory >= 41866)&&(iMemory < 41912)) { printf("Find FOR/GOSUB Entry on Stack"); }
	if ((iMemory >= 41912)&&(iMemory < 41979)) { printf("Open Space in Memory"); }
	if ((iMemory >= 41979)&&(iMemory < 41992)) { printf("Check Stack Depth"); }
	if ((iMemory >= 41992)&&(iMemory < 42037)) { printf("Check Memory Overlap"); }
	if ((iMemory >= 42037)&&(iMemory < 42039)) { printf("Output ?OUT OF MEMORY Error"); }
	if ((iMemory >= 42039)&&(iMemory < 42089)) { printf("Error Routine"); }
	if ((iMemory >= 42089)&&(iMemory < 42100)) { printf("Break Entry"); }
	if ((iMemory >= 42100)&&(iMemory < 42112)) { printf("Restart BASIC"); }
	if ((iMemory >= 42112)&&(iMemory < 42140)) { printf("Input & Identify BASIC Line"); }
	if ((iMemory >= 42140)&&(iMemory < 42146)) { printf("Get Line Number & Tokenise Text"); }
	if ((iMemory >= 42146)&&(iMemory < 42291)) { printf("Insert BASIC Text"); }
	if ((iMemory >= 42291)&&(iMemory < 42336)) { printf("Rechain Lines"); }
	if ((iMemory >= 42336)&&(iMemory < 42361)) { printf("Input Line Into Buffer"); }
	if ((iMemory >= 42361)&&(iMemory < 42515)) { printf("Tokenise Input Buffer"); }
	if ((iMemory >= 42515)&&(iMemory < 42562)) { printf("Search for Line Number"); }
	if ((iMemory >= 42562)&&(iMemory < 42590)) { printf("Perform [new]"); }
	if ((iMemory >= 42590)&&(iMemory < 42638)) { printf("Perform [clr]"); }
	if ((iMemory >= 42638)&&(iMemory < 42652)) { printf("Reset TXTPTR"); }
	if ((iMemory >= 42652)&&(iMemory < 42775)) { printf("Perform [list]"); }
	if ((iMemory >= 42775)&&(iMemory < 42818)) { printf("Handle LIST Character"); }
	if ((iMemory >= 42818)&&(iMemory < 42926)) { printf("Perform [for]"); }
	if ((iMemory >= 42926)&&(iMemory < 42948)) { printf("BASIC Warm Start"); }
	if ((iMemory >= 42948)&&(iMemory < 42977)) { printf("Check End of Program"); }
	if ((iMemory >= 42977)&&(iMemory < 42989)) { printf("Prepare to execute statement"); }
	if ((iMemory >= 42989)&&(iMemory < 43037)) { printf("Perform BASIC Keyword"); }
	if ((iMemory >= 43037)&&(iMemory < 43052)) { printf("Perform [restore]"); }
	if ((iMemory >= 43052)&&(iMemory < 43095)) { printf("Perform [stop], [end], break"); }
	if ((iMemory >= 43095)&&(iMemory < 43121)) { printf("Perform [cont]"); }
	if ((iMemory >= 43121)&&(iMemory < 43139)) { printf("Perform [run]"); }
	if ((iMemory >= 43139)&&(iMemory < 43168)) { printf("Perform [gosub]"); }
	if ((iMemory >= 43168)&&(iMemory < 43218)) { printf("Perform [goto]"); }
	if ((iMemory >= 43218)&&(iMemory < 43256)) { printf("Perform [return]"); }
	if ((iMemory >= 43256)&&(iMemory < 43270)) { printf("Perform [data]"); }
	if ((iMemory >= 43270)&&(iMemory < 43304)) { printf("Search for Next Statement / Line"); }
	if ((iMemory >= 43304)&&(iMemory < 43323)) { printf("Perform [if]"); }
	if ((iMemory >= 43323)&&(iMemory < 43339)) { printf("Perform [rem]"); }
	if ((iMemory >= 43339)&&(iMemory < 43371)) { printf("Perform [on]"); }
	if ((iMemory >= 43371)&&(iMemory < 43429)) { printf("Fetch linnum From BASIC"); }
	if ((iMemory >= 43429)&&(iMemory < 43460)) { printf("Perform [let]"); }
	if ((iMemory >= 43460)&&(iMemory < 43478)) { printf("Assign Integer"); }
	if ((iMemory >= 43478)&&(iMemory < 43481)) { printf("Assign Floating Point"); }
	if ((iMemory >= 43481)&&(iMemory < 43491)) { printf("Assign String"); }
	if ((iMemory >= 43491)&&(iMemory < 43564)) { printf("Assign TI$"); }
	if ((iMemory >= 43564)&&(iMemory < 43648)) { printf("Add Digit to FAC#1"); }
	if ((iMemory >= 43648)&&(iMemory < 43654)) { printf("Perform [print]#"); }
	if ((iMemory >= 43654)&&(iMemory < 43674)) { printf("Perform [cmd]"); }
	if ((iMemory >= 43674)&&(iMemory < 43680)) { printf("Print String From Memory"); }
	if ((iMemory >= 43680)&&(iMemory < 43704)) { printf("Perform [print]"); }
	if ((iMemory >= 43704)&&(iMemory < 43735)) { printf("Output Variable"); }
	if ((iMemory >= 43735)&&(iMemory < 43752)) { printf("Output CR/LF"); }
	if ((iMemory >= 43752)&&(iMemory < 43806)) { printf("Handle comma, TAB(, SPC("); }
	if ((iMemory >= 43806)&&(iMemory < 43835)) { printf("Output String"); }
	if ((iMemory >= 43835)&&(iMemory < 43853)) { printf("Output Format Character"); }
	if ((iMemory >= 43853)&&(iMemory < 43899)) { printf("Handle Bad Data"); }
	if ((iMemory >= 43899)&&(iMemory < 43941)) { printf("Perform [get]"); }
	if ((iMemory >= 43941)&&(iMemory < 43967)) { printf("Perform [input#]"); }
	if ((iMemory >= 43967)&&(iMemory < 44010)) { printf("Perform [input]"); }
	if ((iMemory >= 44010)&&(iMemory < 44025)) { printf("Read Input Buffer"); }
	if ((iMemory >= 44025)&&(iMemory < 44038)) { printf("Do Input Prompt"); }
	if ((iMemory >= 44038)&&(iMemory < 44085)) { printf("Perform [read]"); }
	if ((iMemory >= 44085)&&(iMemory < 44284)) { printf("General Purpose Read Routine"); }
	if ((iMemory >= 44284)&&(iMemory < 44318)) { printf("Input Error Messages         "); }
	if ((iMemory >= 44318)&&(iMemory < 44385)) { printf("Perform [next]"); }
	if ((iMemory >= 44385)&&(iMemory < 44426)) { printf("Check Valid Loop"); }
	if ((iMemory >= 44426)&&(iMemory < 44446)) { printf("Confirm Result"); }
	if ((iMemory >= 44446)&&(iMemory < 44675)) { printf("Evaluate Expression in Text"); }
	if ((iMemory >= 44675)&&(iMemory < 44712)) { printf("Evaluate Single Term"); }
	if ((iMemory >= 44712)&&(iMemory < 44717)) { printf("Constant - pi                "); }
	if ((iMemory >= 44717)&&(iMemory < 44785)) { printf("Continue Expression"); }
	if ((iMemory >= 44785)&&(iMemory < 44791)) { printf("Expression in Brackets"); }
	if ((iMemory >= 44791)&&(iMemory < 44791)) { printf("Confirm Character"); }
	if ((iMemory >= 44791)&&(iMemory < 44794)) { printf("-test ')'-"); }
	if ((iMemory >= 44794)&&(iMemory < 44797)) { printf("-test '('-"); }
	if ((iMemory >= 44797)&&(iMemory < 44808)) { printf("-test comma-"); }
	if ((iMemory >= 44808)&&(iMemory < 44813)) { printf("Output ?SYNTAX Error"); }
	if ((iMemory >= 44813)&&(iMemory < 44820)) { printf("Set up NOT Function"); }
	if ((iMemory >= 44820)&&(iMemory < 44840)) { printf("Identify Reserved Variable"); }
	if ((iMemory >= 44840)&&(iMemory < 44872)) { printf("Search for Variable"); }
	if ((iMemory >= 44872)&&(iMemory < 44967)) { printf("Convert TI to ASCII String"); }
	if ((iMemory >= 44967)&&(iMemory < 44977)) { printf("Identify Function Type"); }
	if ((iMemory >= 44977)&&(iMemory < 45009)) { printf("Evaluate String Function"); }
	if ((iMemory >= 45009)&&(iMemory < 45030)) { printf("Evaluate Numeric Function"); }
	if ((iMemory >= 45030)&&(iMemory < 45078)) { printf("Perform [or], [and]"); }
	if ((iMemory >= 45078)&&(iMemory < 45083)) { printf("Perform <, =, >"); }
	if ((iMemory >= 45083)&&(iMemory < 45102)) { printf("Numeric Comparison"); }
	if ((iMemory >= 45102)&&(iMemory < 45182)) { printf("String Comparison"); }
	if ((iMemory >= 45182)&&(iMemory < 45195)) { printf("Perform [dim]"); }
	if ((iMemory >= 45195)&&(iMemory < 45287)) { printf("Identify Variable"); }
	if ((iMemory >= 45287)&&(iMemory < 45341)) { printf("Locate Ordinary Variable"); }
	if ((iMemory >= 45341)&&(iMemory < 45352)) { printf("Create New Variable"); }
	if ((iMemory >= 45352)&&(iMemory < 45460)) { printf("Create Variable"); }
	if ((iMemory >= 45460)&&(iMemory < 45477)) { printf("Allocate Array Pointer Space"); }
	if ((iMemory >= 45477)&&(iMemory < 45482)) { printf("Constant 32768 in Flpt           "); }
	if ((iMemory >= 45482)&&(iMemory < 45490)) { printf("FAC#1 to Integer in (AC/YR)"); }
	if ((iMemory >= 45490)&&(iMemory < 45503)) { printf("Evaluate Text for Integer"); }
	if ((iMemory >= 45503)&&(iMemory < 45521)) { printf("FAC#1 to Positive Integer"); }
	if ((iMemory >= 45521)&&(iMemory < 45592)) { printf("Get Array Parameters"); }
	if ((iMemory >= 45592)&&(iMemory < 45637)) { printf("Find Array"); }
	if ((iMemory >= 45637)&&(iMemory < 45665)) { printf("?BAD SUBSCRIPT/?ILLEGAL QUANTITY"); }
	if ((iMemory >= 45665)&&(iMemory < 45838)) { printf("Create Array"); }
	if ((iMemory >= 45838)&&(iMemory < 45900)) { printf("Locate Element in Array"); }
	if ((iMemory >= 45900)&&(iMemory < 45949)) { printf("Number of Bytes in Subscript"); }
	if ((iMemory >= 45949)&&(iMemory < 45969)) { printf("Perform [fre]"); }
	if ((iMemory >= 45969)&&(iMemory < 45982)) { printf("Convert Integer in (AC/YR) to Flpt"); }
	if ((iMemory >= 45982)&&(iMemory < 45990)) { printf("Perform [pos]"); }
	if ((iMemory >= 45990)&&(iMemory < 46049)) { printf("Confirm Program Mode"); }
	if ((iMemory >= 46049)&&(iMemory < 46068)) { printf("Check Syntax of FN"); }
	if ((iMemory >= 46068)&&(iMemory < 46181)) { printf("Perform [fn]"); }
	if ((iMemory >= 46181)&&(iMemory < 46215)) { printf("Perform [str$]"); }
	if ((iMemory >= 46215)&&(iMemory < 46293)) { printf("Set Up String"); }
	if ((iMemory >= 46293)&&(iMemory < 46324)) { printf("Save String Descriptor"); }
	if ((iMemory >= 46324)&&(iMemory < 46374)) { printf("Allocate Space for String"); }
	if ((iMemory >= 46374)&&(iMemory < 46525)) { printf("Garbage Collection"); }
	if ((iMemory >= 46525)&&(iMemory < 46598)) { printf("Search for Next String"); }
	if ((iMemory >= 46598)&&(iMemory < 46653)) { printf("Collect a String"); }
	if ((iMemory >= 46653)&&(iMemory < 46714)) { printf("Concatenate Two Strings"); }
	if ((iMemory >= 46714)&&(iMemory < 46755)) { printf("Store String in High RAM"); }
	if ((iMemory >= 46755)&&(iMemory < 46811)) { printf("Perform String Housekeeping"); }
	if ((iMemory >= 46811)&&(iMemory < 46828)) { printf("Clean Descriptor Stack"); }
	if ((iMemory >= 46828)&&(iMemory < 46848)) { printf("Perform [chr$]"); }
	if ((iMemory >= 46848)&&(iMemory < 46892)) { printf("Perform [left$]"); }
	if ((iMemory >= 46892)&&(iMemory < 46903)) { printf("Perform [right$]"); }
	if ((iMemory >= 46903)&&(iMemory < 46945)) { printf("Perform [mid$]"); }
	if ((iMemory >= 46945)&&(iMemory < 46972)) { printf("Pull sTring Parameters"); }
	if ((iMemory >= 46972)&&(iMemory < 46978)) { printf("Perform [len]"); }
	if ((iMemory >= 46978)&&(iMemory < 46987)) { printf("Exit String Mode"); }
	if ((iMemory >= 46987)&&(iMemory < 47003)) { printf("Perform [asc]"); }
	if ((iMemory >= 47003)&&(iMemory < 47021)) { printf("Evaluate Text to 1 Byte in XR"); }
	if ((iMemory >= 47021)&&(iMemory < 47029)) { printf("Perform [val]"); }
	if ((iMemory >= 47029)&&(iMemory < 47083)) { printf("Convert ASCII String to Flpt"); }
	if ((iMemory >= 47083)&&(iMemory < 47095)) { printf("Get parameters for POKE/WAIT"); }
	if ((iMemory >= 47095)&&(iMemory < 47117)) { printf("Convert FAC#1 to Integer in LINNUM"); }
	if ((iMemory >= 47117)&&(iMemory < 47140)) { printf("Perform [peek]"); }
	if ((iMemory >= 47140)&&(iMemory < 47149)) { printf("Perform [poke]"); }
	if ((iMemory >= 47149)&&(iMemory < 47177)) { printf("Perform [wait]"); }
	if ((iMemory >= 47177)&&(iMemory < 47184)) { printf("Add 0.5 to FAC#1"); }
	if ((iMemory >= 47184)&&(iMemory < 47202)) { printf("Perform Subtraction"); }
	if ((iMemory >= 47202)&&(iMemory < 47207)) { printf("Normalise Addition"); }
	if ((iMemory >= 47207)&&(iMemory < 47431)) { printf("Perform Addition"); }
	if ((iMemory >= 47431)&&(iMemory < 47486)) { printf("2's Complement FAC#1"); }
	if ((iMemory >= 47486)&&(iMemory < 47491)) { printf("Output ?OVERFLOW Error"); }
	if ((iMemory >= 47491)&&(iMemory < 47548)) { printf("Multiply by Zero Byte"); }
	if ((iMemory >= 47548)&&(iMemory < 47594)) { printf("Table of Flpt Constants        "); }
	if ((iMemory >= 47594)&&(iMemory < 47656)) { printf("Perform [log]"); }
	if ((iMemory >= 47656)&&(iMemory < 47705)) { printf("Perform Multiply"); }
	if ((iMemory >= 47705)&&(iMemory < 47756)) { printf("Multiply by a Byte"); }
	if ((iMemory >= 47756)&&(iMemory < 47799)) { printf("Load FAC#2 From Memory"); }
	if ((iMemory >= 47799)&&(iMemory < 47828)) { printf("Test Both Accumulators"); }
	if ((iMemory >= 47828)&&(iMemory < 47842)) { printf("Overflow / Underflow"); }
	if ((iMemory >= 47842)&&(iMemory < 47865)) { printf("Multiply FAC#1 by 10"); }
	if ((iMemory >= 47865)&&(iMemory < 47870)) { printf("Constant 10 in Flpt         "); }
	if ((iMemory >= 47870)&&(iMemory < 47879)) { printf("Divide FAC#1 by 10"); }
	if ((iMemory >= 47879)&&(iMemory < 47887)) { printf("Divide FAC#2 by Flpt at (AC/YR)"); }
	if ((iMemory >= 47887)&&(iMemory < 48034)) { printf("Divide FAC#2 by FAC#1"); }
	if ((iMemory >= 48034)&&(iMemory < 48071)) { printf("Load FAC#1 From Memory"); }
	if ((iMemory >= 48071)&&(iMemory < 48124)) { printf("Store FAC#1 in Memory"); }
	if ((iMemory >= 48124)&&(iMemory < 48140)) { printf("Copy FAC#2 into FAC#1"); }
	if ((iMemory >= 48140)&&(iMemory < 48155)) { printf("Copy FAC#1 into FAC#2"); }
	if ((iMemory >= 48155)&&(iMemory < 48171)) { printf("Round FAC#1"); }
	if ((iMemory >= 48171)&&(iMemory < 48185)) { printf("Check Sign of FAC#1"); }
	if ((iMemory >= 48185)&&(iMemory < 48216)) { printf("Perform [sgn]"); }
	if ((iMemory >= 48216)&&(iMemory < 48219)) { printf("Perform [abs]"); }
	if ((iMemory >= 48219)&&(iMemory < 48283)) { printf("Compare FAC#1 With Memory"); }
	if ((iMemory >= 48283)&&(iMemory < 48332)) { printf("Convert FAC#1 to Integer"); }
	if ((iMemory >= 48332)&&(iMemory < 48371)) { printf("Perform [int]"); }
	if ((iMemory >= 48371)&&(iMemory < 48563)) { printf("Convert ASCII String to a Number in FAC#1"); }
	if ((iMemory >= 48563)&&(iMemory < 48578)) { printf("String Conversion Constants   "); }
	if ((iMemory >= 48578)&&(iMemory < 48605)) { printf("Output 'IN' and Line Number"); }
	if ((iMemory >= 48605)&&(iMemory < 48744)) { printf("Convert FAC#1 to ASCII String"); }
	if ((iMemory >= 48744)&&(iMemory < 48913)) { printf("Convert TI to String"); }
	if ((iMemory >= 48913)&&(iMemory < 49009)) { printf("Table of Constants          "); }
	if ((iMemory >= 49009)&&(iMemory < 49019)) { printf("Perform [sqr]"); }
	if ((iMemory >= 49019)&&(iMemory < 49076)) { printf("Perform power ($)"); }
	if ((iMemory >= 49076)&&(iMemory < 49087)) { printf("Negate FAC#1"); }
	if ((iMemory >= 49087)&&(iMemory < 49133)) { printf("Table of Constants         "); }
	if ((iMemory >= 49133)&&(iMemory < 49152)) { printf("Perform [exp]"); }
	if ((iMemory >= 49152)&&(iMemory <= 53247)) { printf("RAM 4096 bytes                           "); }
	if ((iMemory == 53248)) { printf("Sprite 0 X Pos"); }
	if ((iMemory == 53249)) { printf("Sprite 0 Y Pos"); }
	if ((iMemory == 53250)) { printf("Sprite 1 X Pos"); }
	if ((iMemory == 53251)) { printf("Sprite 1 Y Pos"); }
	if ((iMemory == 53252)) { printf("Sprite 2 X Pos"); }
	if ((iMemory == 53253)) { printf("Sprite 2 Y Pos"); }
	if ((iMemory == 53254)) { printf("Sprite 3 X Pos"); }
	if ((iMemory == 53255)) { printf("Sprite 3 Y Pos"); }
	if ((iMemory == 53256)) { printf("Sprite 4 X Pos"); }
	if ((iMemory == 53257)) { printf("Sprite 4 Y Pos"); }
	if ((iMemory == 53258)) { printf("Sprite 5 X Pos"); }
	if ((iMemory == 53259)) { printf("Sprite 5 Y Pos"); }
	if ((iMemory == 53260)) { printf("Sprite 6 X Pos"); }
	if ((iMemory == 53261)) { printf("Sprite 6 Y Pos"); }
	if ((iMemory == 53262)) { printf("Sprite 7 X Pos"); }
	if ((iMemory == 53263)) { printf("Sprite 7 Y Pos"); }
	if ((iMemory == 53264)) { printf("Sprites 0-7 X Pos (msb of X coord.)"); }
	if ((iMemory == 53265)) { printf("Video interface control register b7 Raster Compare 53266 b6 Extended Color Text Mode b5 Bit Map Mode. b4 Clear to blank screen to border color b3 Select 24/25 row Text Display b2-b0 Smooth Scroll to Y 0 - 7"); }
	if ((iMemory == 53266)) { printf("Read Raster / Write Rasterline Value for Compare IRQ"); }
	if ((iMemory == 53267)) { printf("Light-Pen Latch X Pos"); }
	if ((iMemory == 53268)) { printf("Light-Pen Latch Y Pos"); }
	if ((iMemory == 53269)) { printf("Sprite display Enable"); }
	if ((iMemory == 53270)) { printf("VIC Control Register b5 ALWAYS CLEAR THIS BIT! b4 Multi-Color Mode b3 Select 38/40 Column Text Display b2-b0 Smooth Scroll to X Pos"); }
	if ((iMemory == 53271)) { printf("Sprites 0-7 Expand 2x Vertical (Y)"); }
	if ((iMemory == 53272)) { printf("VIC Memory Control Register b7-b4 Video Matrix Base Address (inside VIC) b3-b1 Character Dot-Data Base Address (inside VIC) b0 Select upper/lower Character Set"); }
	if ((iMemory == 53273)) { printf("VIC Interrupt Flag Register (set when IRQ Occurred)7 Set on Any Enabled VIC IRQ Condition b3 Light-Pen Triggered IRQ Flag b2 Sprite to Sprite Collision b1 Sprite to Background Collision b0 Raster Compare"); }
	if ((iMemory == 53274)) { printf("IRQ Mask Register: set = Interrupt Enabled"); }
	if ((iMemory == 53275)) { printf("Sprite to Background Display Priority: set = Sprite"); }
	if ((iMemory == 53276)) { printf("Sprites 0-7 Multi-Color Mode Select: set = M.C.M."); }
	if ((iMemory == 53277)) { printf("Sprites 0-7 Expand 2x Horizontal (X)"); }
	if ((iMemory == 53278)) { printf("Sprite to Sprite Collision Detect"); }
	if ((iMemory == 53279)) { printf("Sprite to Background Collision Detect"); }
	if ((iMemory == 53280)) { printf("Border Color"); }
	if ((iMemory == 53281)) { printf("Background Color 0"); }
	if ((iMemory == 53282)) { printf("Background Color 1"); }
	if ((iMemory == 53283)) { printf("Background Color 2"); }
	if ((iMemory == 53284)) { printf("Background Color 3"); }
	if ((iMemory == 53285)) { printf("Sprite Multi-Color Register 0"); }
	if ((iMemory == 53286)) { printf("Sprite Multi-Color Register 1"); }
	if ((iMemory == 53287)) { printf("Sprite 0 Color"); }
	if ((iMemory == 53288)) { printf("Sprite 1 Color"); }
	if ((iMemory == 53289)) { printf("Sprite 2 Color"); }
	if ((iMemory == 53290)) { printf("Sprite 3 Color"); }
	if ((iMemory == 53291)) { printf("Sprite 4 Color"); }
	if ((iMemory == 53292)) { printf("Sprite 5 Color"); }
	if ((iMemory == 53293)) { printf("Sprite 6 Color"); }
	if ((iMemory == 53294)) { printf("Sprite 7 Color  "); }
	if ((iMemory >= 53295)&&(iMemory <= 54271)) { printf("MOS 6566 VIDEO INTERFACE CONTROLLER (VIC)  "); }
	if ((iMemory == 54272)) { printf("Voice 1: Frequency Control - Low-Byte"); }
	if ((iMemory == 54273)) { printf("Voice 1: Frequency Control - High-Byte"); }
	if ((iMemory == 54274)) { printf("Voice 1: Pulse Waveform Width - Low-Byte"); }
	if ((iMemory == 54275)) { printf("Voice 1: Pulse Waveform Width - High-Nybble b3-b0 "); }
	if ((iMemory == 54276)) { printf("Voice 1: Control Register b7 Noise b6 Pulse, b5 Sawtooth b4 Triangle b3 Disable oscillator b2 Ring Modulate osc. b1 synchronize osc. b0 set att/dec/sus, clear release"); }
	if ((iMemory == 54277)) { printf("Voice 1: Envelope Generator attack / decay b7-b4 Select Attack Cycle Duration: 0-15 b3-b0 Select Decay Cycle Duration: 0-15"); }
	if ((iMemory == 54278)) { printf("Voice 1: Envelope Generator sustain / release b7-b4 sustain duration: 0-15 b3-b0 release duration: 0-15"); }
	if ((iMemory == 54279)) { printf("Voice 2: Frequency Control - Low-Byte"); }
	if ((iMemory == 54280)) { printf("Voice 2: Frequency Control - High-Byte"); }
	if ((iMemory == 54281)) { printf("Voice 2: Pulse Waveform Width - Low-Byte"); }
	if ((iMemory == 54282)) { printf("Voice 2: Pulse Waveform Width - High-Nybble b3-b0 "); }
	if ((iMemory == 54283)) { printf("Voice 2: Control Register b7 Noise b6 Pulse, b5 Sawtooth b4 Triangle b3 Disable oscillator b2 Ring Modulate osc. b1 synchronize osc. b0 set att/dec/sus, clear release"); }
	if ((iMemory == 54284)) { printf("Voice 2: Envelope Generator attack / decay b7-b4 Select Attack Cycle Duration: 0-15 b3-b0 Select Decay Cycle Duration: 0-15"); }
	if ((iMemory == 54285)) { printf("Voice 2: Envelope Generator sustain / release b7-b4 sustain duration: 0-15 b3-b0 release duration: 0-15"); }
	if ((iMemory == 54286)) { printf("Voice 3: Frequency Control - Low-Byte"); }
	if ((iMemory == 54287)) { printf("Voice 3: Frequency Control - High-Byte"); }
	if ((iMemory == 54288)) { printf("Voice 3: Pulse Waveform Width - Low-Byte"); }
	if ((iMemory == 54289)) { printf("Voice 3: Pulse Waveform Width - High-Nybble b3-b0 "); }
	if ((iMemory == 54290)) { printf("Voice 3: Control Register b7 Noise b6 Pulse, b5 Sawtooth b4 Triangle b3 Disable oscillator b2 Ring Modulate osc. b1 synchronize osc. b0 set att/dec/sus, clear release"); }
	if ((iMemory == 54291)) { printf("Voice 3: Envelope Generator attack / decay b7-b4 Select Attack Cycle Duration: 0-15 b3-b0 Select Decay Cycle Duration: 0-15"); }
	if ((iMemory == 54292)) { printf("Voice 3: Envelope Generator sustain / release b7-b4 sustain duration: 0-15 b3-b0 release duration: 0-15"); }
	if ((iMemory == 54293)) { printf("Filter Cutoff Frequency: Low-Nybble(Bits 2-0)"); }
	if ((iMemory == 54294)) { printf("Filter Cutoff Frequency: High-Byte"); }
	if ((iMemory == 54295)) { printf("Filter b7-b4 Select Filter Resonance: 0-15 b3 Filter External Input b2 Filter Voice 3 Output b1 Filter Voice 2 Output b0 Filter Voice 1 Output"); }
	if ((iMemory == 54296)) { printf("Select Filter Mode and Volume b7 Cut-Off Voice 3 Output: 1 = Off, 0 = On b6 Select Filter High-Pass Mode: 1 = On b5 Select Filter Band-Pass Mode: 1 = On b4 Select Filter Low-Pass Mode: 1 = On b3-b0 Select Output Volume: 0-15"); }
	if ((iMemory == 54297)) { printf("Analog/Digital Converter Game Paddle 1 0-470kOhm"); }
	if ((iMemory == 54298)) { printf("Analog/Digital Converter Game Paddle 2 0-470kOhm"); }
	if ((iMemory == 54299)) { printf("Oscillator 3 Random Number Generator"); }
	if ((iMemory == 54230)) { printf("Envelope Generator 3 Output"); }
	if ((iMemory >= 54232)&&(iMemory <= 54595)) { printf("MOS 6581 SOUND INTERFACE DEVICE (SID)"); }
	if ((iMemory >= 55296)&&(iMemory <= 56319)) { printf("Color RAM 4 bit nybbles memory          "); }
	if ((iMemory == 56320)) { printf("Data Port A (Keyboard, Joystick, Paddles, Light-Pen) b4 Joystick A Fire b3-b0 Joystick A Direction b7 Paddle Port B b6 Paddle Port A b3-b2 Paddle Fire Buttons "); }
	if ((iMemory == 56321)) { printf("Data Port B (Keyboard, Joystick, Paddles) Game Port 1 b7-b0 Read Keyboard Row Values for Keyboard Scan b7 Timer B Toggle/Pulse Output b6 Timer A: Toggle/Pulse Output b4 Joystick 1 Fire Button: 1 = Fire b3-b2 Paddle Fire Buttons b3-b0 Joystick 1 Direction"); }
	if ((iMemory == 56322)) { printf("Data Direction Register - Port A (56320)"); }
	if ((iMemory == 56323)) { printf("Data Direction Register - Port B (56321)"); }
	if ((iMemory == 56324)) { printf("Timer A: Low-Byte"); }
	if ((iMemory == 56325)) { printf("Timer A: High-Byte"); }
	if ((iMemory == 56326)) { printf("Timer B: Low-Byte"); }
	if ((iMemory == 56327)) { printf("Timer B: High-Byte"); }
	if ((iMemory == 56328)) { printf("Time-of-Day Clock: 1/10 Seconds"); }
	if ((iMemory == 56329)) { printf("Time-of-Day Clock: Seconds"); }
	if ((iMemory == 56330)) { printf("Time-of-Day Clock: Minutes"); }
	if ((iMemory == 56331)) { printf("Time-of-Day Clock: Hours + AM/PM Flag (Bit 7)"); }
	if ((iMemory == 56332)) { printf("Synchronous Serial I/O Data Buffer"); }
	if ((iMemory == 56333)) { printf("Complex interface adapter Interrupt control register (Read IRQs/Write Mask) b7 IRQ Flag (1 = IRQ Occurred) / Set-Clear Flag b4 FLAG1 IRQ (Cassette Read / Serial Bus SRQ Input) b3 Serial Port Interrupt b2 Time-of-Day Clock Alarm Interrupt b1 Timer B Interrupt b0 Timer A Interrupt"); }
	if ((iMemory == 56334)) { printf("Complex interface adapter Register A b7 Time-of-Day Clock Frequency: 1 = 50 Hz, 0 = 60 Hz b6 Serial Port I/O Mode Output, 0 = Input b5 Timer A Counts: 1 = CNT Signals, 0 = System 02 Clock b4 Force Load Timer A: 1 = Yes b3 Timer A Run Mode: 1 = One-Shot, 0 = Continuous b2 Timer A Output Mode to PB6: 1 = Toggle, 0 = Pulse b1 Timer A Output on PB6: 1 = Yes, 0 = No b0 Start/Stop Timer A: 1 = Start, 0 = Stop"); }
	if ((iMemory == 56335)) { printf("Complex interface adapter Register B b7 Set Alarm/TOD-Clock: 1 = Alarm, 0 = Clock b6-b5  Timer B Mode Select: 0 = Count System 02 Clock Pulses 1 = Count Positive CNT Transitions 2 = Count Timer A Underflow Pulses 3 = Count Timer A Underflows While CNT Positive b4 Force Load Timer B: 1 = Yes b3 Timer B Run Mode: 1 = One-Shot, 0 = Continuous b2 Timer B Output Mode to PB6: 1 = Toggle, 0 = Pulse b1 Timer B Output on PB6: 1 = Yes, 0 = No b0 Start/Stop Timer A: 1 = Start, 0 = Stop"); }
	if ((iMemory >= 56336)&&(iMemory <= 56575)) { printf("MOS 6526 Complex Interface Adapter(CIA)#1 "); }
	if ((iMemory == 56576)) { printf("Data Port A (Serial Bus, RS-232, VIC Memory Control) b7 Serial Bus Data Input b6 Serial Bus Clock Pulse Input b5 Serial Bus Data Output b4 Serial Bus Clock Pulse Output b3 Serial Bus ATN Signal Output b2 RS-232 Data Output (User Port) b1-b0 VIC Chip System Memory Bank Select (Default = 3)"); }
	if ((iMemory == 56577)) { printf("Data Port B (User Port or RS-232 b7 Data Set Ready b6 Clear to Send b4 Carrier Detect b3 Ring Indicator b2 Data Terminal Ready b1 Request to Sendb0 Received Data)"); }
	if ((iMemory == 56578)) { printf("Data Direction Register - Port A"); }
	if ((iMemory == 56579)) { printf("Data Direction Register - Port B"); }
	if ((iMemory == 56580)) { printf("Timer A: Low-Byte"); }
	if ((iMemory == 56581)) { printf("Timer A: High-Byte"); }
	if ((iMemory == 56582)) { printf("Timer B: Low-Byte"); }
	if ((iMemory == 56583)) { printf("Timer B: High-Byte"); }
	if ((iMemory == 56584)) { printf("Time-of-Day Clock: 1/10 Seconds"); }
	if ((iMemory == 56585)) { printf("Time-of-Day Clock: Seconds"); }
	if ((iMemory == 56586)) { printf("Time-of-Day Clock: Minutes"); }
	if ((iMemory == 56587)) { printf("Time-of-Day Clock: Hours + AM/PM Flag (Bit 7)"); }
	if ((iMemory == 56588)) { printf("Synchronous Serial I/O Data Buffer"); }
	if ((iMemory == 56589)) { printf("Complex interface adapter Interrupt Control Register (Read NMls/Write Mask) b7 NMI Flag (1 = NMI Occurred) / Set-Clear Flag b4 FLAG1 NMI (User/RS-232 Received Data Input) b3 Serial Port Interrupt b1 Timer B Interrupt b0 Timer A Interrupt"); }
	if ((iMemory == 56590)) { printf("Complex interface adapter Register A b7 Time-of-Day Clock Frequency: 1 = 50 Hz, 0 = 60 Hz b6 Serial Port I/O Mode Output, 0 = Input b5 Timer A Counts: 1 = CNT Signals, 0 = System 02 Clock b4 Force Load Timer A: 1 = Yes b3 Timer A Run Mode: 1 = One-Shot, 0 = Continuous b2 Timer A Output Mode to PB6: 1 = Toggle, 0 = Pulse b1 Timer A Output on PB6: 1 = Yes, 0 = No b0 Start/Stop Timer A: 1 = Start, 0 = Stop"); }
	if ((iMemory == 56591)) { printf("Complex interface adapter Register B b7 Set Alarm/TOD-Clock: 1 = Alarm, 0 = Clock b6-b5 Timer B Mode Select: 0 = Count System 02 Clock Pulses 1 = Count Positive CNT Transitions 2 = Count Timer A Underflow Pulses 3 = Count Timer A Underflows While CNT Positive b4 Force Load Timer B: 1 = Yes b3 Timer B Run Mode: 1 = One-Shot, 0 = Continuous b2 Timer B Output Mode to PB6: 1 = Toggle, 0 = Pulse b1 Timer B Output on PB6: 1 = Yes, 0 = No b0 Start/Stop Timer B: 1 = Start, 0 = Stop"); }
	if ((iMemory >= 56592)&&(iMemory <= 57343)) { printf("MOS 6526 Complex Interface Adapter(CIA)#2 "); }
	if ((iMemory >= 57344)&&(iMemory <57411)) { printf("(exp continues) EXP continued From BASIC ROM"); }
	if ((iMemory >= 57411)&&(iMemory <57485)) { printf("polyx Series Evaluation"); }
	if ((iMemory >= 57485)&&(iMemory <57495)) { printf("rmulc Constants for RND "); }
	if ((iMemory >= 57495)&&(iMemory <57593)) { printf("rnd Perform [rnd]"); }
	if ((iMemory >= 57593)&&(iMemory <57612)) { printf("bioerr Handle I/O Error in BASIC"); }
	if ((iMemory >= 57612)&&(iMemory <57618)) { printf("bchout Output Character"); }
	if ((iMemory >= 57618)&&(iMemory <57624)) { printf("bchin Input Character"); }
	if ((iMemory >= 57624)&&(iMemory <57630)) { printf("bckout Set Up For Output"); }
	if ((iMemory >= 57630)&&(iMemory <57636)) { printf("bckin Set Up For Input"); }
	if ((iMemory >= 57636)&&(iMemory <57642)) { printf("bgetin Get One Character"); }
	if ((iMemory >= 57642)&&(iMemory <57686)) { printf("sys Perform [sys]"); }
	if ((iMemory >= 57686)&&(iMemory <57701)) { printf("savet Perform [save]"); }
	if ((iMemory >= 57701)&&(iMemory <57790)) { printf("verfyt Perform [verify / load]"); }
	if ((iMemory >= 57790)&&(iMemory <57799)) { printf("opent Perform [open]"); }
	if ((iMemory >= 57799)&&(iMemory <57812)) { printf("closet Perform [close]"); }
	if ((iMemory >= 57812)&&(iMemory <57856)) { printf("slpara Get Parameters For LOAD/SAVE"); }
	if ((iMemory >= 57856)&&(iMemory <57862)) { printf("combyt Get Next One Byte Parameter"); }
	if ((iMemory >= 57862)&&(iMemory <57870)) { printf("deflt Check Default Parameters"); }
	if ((iMemory >= 57870)&&(iMemory <57881)) { printf("cmmerr Check For Comma"); }
	if ((iMemory >= 57881)&&(iMemory <57956)) { printf("ocpara Get Parameters For OPEN/CLOSE"); }
	if ((iMemory >= 57956)&&(iMemory <57963)) { printf("cos Perform [cos]"); }
	if ((iMemory >= 57963)&&(iMemory <58036)) { printf("sin Perform [sin]"); }
	if ((iMemory >= 58036)&&(iMemory <58080)) { printf("tan Perform [tan]"); }
	if ((iMemory >= 58080)&&(iMemory <58085)) { printf("1/2*pi (5 byte float) 1.570796327 "); }
	if ((iMemory >= 58085)&&(iMemory <58090)) { printf("pi*2 (5 byte float) 6.28318531 "); }
	if ((iMemory >= 58090)&&(iMemory <58095)) { printf("0.25 (5 byte float) 0.25"); }
	if ((iMemory >= 58095)&&(iMemory <58126)) { printf("Table of Constants, byte counter followed by 5 byte floats [-14.3813907, 42.0077971, -76.7041703, 81.6052237, -41.3417021, 6.28318531]"); }
	if ((iMemory >= 58126)&&(iMemory <58174)) { printf("atn Perform [atn]"); }
	if ((iMemory >= 58174)&&(iMemory <58235)) { printf("atncon Table of ATN Constants, byte counter followed by 5 byte floats[-0.000684793912, 0.00485094216, -0.161117018, 0.034209638, -0.0542791328, 0.0724571965, -0.0898023954, 0.110932413, -0.142839808, 0.19999912, -0.333333316, 1.00]"); }
	if ((iMemory >= 58235)&&(iMemory <58260)) { printf("bassft BASIC Warm Start [RUNSTOP-RESTORE]"); }
	if ((iMemory >= 58260)&&(iMemory <58274)) { printf("init BASIC Cold Start"); }
	if ((iMemory >= 58274)&&(iMemory <58290)) { printf("initat CHRGET For Zero-page"); }
	if ((iMemory >= 58290)&&(iMemory <58298)) { printf("0.811635157"); }
	if ((iMemory >= 58298)&&(iMemory <58303)) { printf("rndsed RND Seed For zero-page "); }
	if ((iMemory >= 58303)&&(iMemory <58402)) { printf("initcz Initialize BASIC RAM"); }
	if ((iMemory >= 58402)&&(iMemory <58439)) { printf("initms Output Power-Up Message"); }
	if ((iMemory >= 58439)&&(iMemory <58451)) { printf("bvtrs Table of BASIC Vectors (for 0300) "); }
	if ((iMemory >= 58451)&&(iMemory <58463)) { printf("initv Initialize Vectors"); }
	if ((iMemory >= 58463)&&(iMemory <58541)) { printf("words Power-Up Message "); }
	if ((iMemory >= 58541)&&(iMemory <58551)) { printf("Patch for BASIC Call to CHKOUT"); }
	if ((iMemory >= 58551)&&(iMemory <58586)) { printf("Unused Bytes For Future Patches "); }
	if ((iMemory >= 58586)&&(iMemory <58592)) { printf("Reset Character Colour"); }
	if ((iMemory >= 58592)&&(iMemory <58604)) { printf("Pause After Finding Tape File"); }
	if ((iMemory >= 58604)&&(iMemory <58624)) { printf("RS-232 Timing Table - PAL "); }
	if ((iMemory >= 58624)&&(iMemory <58629)) { printf("iobase Get I/O Address"); }
	if ((iMemory >= 58629)&&(iMemory <58634)) { printf("screen Get Screen Size"); }
	if ((iMemory >= 58634)&&(iMemory <58648)) { printf("plot Put / Get Row And Column"); }
	if ((iMemory >= 58648)&&(iMemory <58692)) { printf("cint1 Initialize I/O"); }
	if ((iMemory >= 58692)&&(iMemory <58726)) { printf("Clear Screen"); }
	if ((iMemory >= 58726)&&(iMemory <58732)) { printf("Home Cursor"); }
	if ((iMemory >= 58732)&&(iMemory <58778)) { printf("Set Screen Pointers"); }
	if ((iMemory >= 58778)&&(iMemory <58784)) { printf("Set I/O Defaults (Unused Entry)"); }
	if ((iMemory >= 58784)&&(iMemory <58804)) { printf("Set I/O Defaults"); }
	if ((iMemory >= 58804)&&(iMemory <58826)) { printf("lp2 Get Character From Keyboard Buffer"); }
	if ((iMemory >= 58826)&&(iMemory <58930)) { printf("Input From Keyboard"); }
	if ((iMemory >= 58930)&&(iMemory <59012)) { printf("Input From Screen or Keyboard"); }
	if ((iMemory >= 59012)&&(iMemory <59025)) { printf("Quotes Test"); }
	if ((iMemory >= 59025)&&(iMemory <59062)) { printf("Set Up Screen Print"); }
	if ((iMemory >= 59062)&&(iMemory <59117)) { printf("Advance Cursor"); }
	if ((iMemory >= 59117)&&(iMemory <59137)) { printf("Retreat Cursor"); }
	if ((iMemory >= 59137)&&(iMemory <59158)) { printf("Back on to Previous Line"); }
	if ((iMemory >= 59158)&&(iMemory <59178)) { printf("Output to Screen"); }
	if ((iMemory >= 59178)&&(iMemory <59348)) { printf("-unshifted characters-"); }
	if ((iMemory >= 59348)&&(iMemory <59516)) { printf("-shifted characters-"); }
	if ((iMemory >= 59516)&&(iMemory <59537)) { printf("Go to Next Line"); }
	if ((iMemory >= 59537)&&(iMemory <59553)) { printf("Output <CR>"); }
	if ((iMemory >= 59553)&&(iMemory <59571)) { printf("Check Line Decrement"); }
	if ((iMemory >= 59571)&&(iMemory <59595)) { printf("Check Line Increment"); }
	if ((iMemory >= 59595)&&(iMemory <59610)) { printf("Set Colour Code"); }
	if ((iMemory >= 59610)&&(iMemory <59626)) { printf("Colour Code Table"); }
	if ((iMemory >= 59626)&&(iMemory <59749)) { printf("Scroll Screen"); }
	if ((iMemory >= 59749)&&(iMemory <59848)) { printf("Open A Space On The Screen"); }
	if ((iMemory >= 59848)&&(iMemory <59872)) { printf("Move A Screen Line"); }
	if ((iMemory >= 59872)&&(iMemory <59888)) { printf("Syncronise Colour Transfer"); }
	if ((iMemory >= 59888)&&(iMemory <59903)) { printf("Set Start of Line"); }
	if ((iMemory >= 59903)&&(iMemory <59923)) { printf("Clear Screen Line"); }
	if ((iMemory >= 59923)&&(iMemory <59940)) { printf("Print To Screen"); }
	if ((iMemory >= 59940)&&(iMemory <59953)) { printf("Syncronise Colour Pointer"); }
	if ((iMemory >= 59953)&&(iMemory <60039)) { printf("Main IRQ Entry Point"); }
	if ((iMemory >= 60039)&&(iMemory <60125)) { printf("scnkey Scan Keyboard"); }
	if ((iMemory >= 60125)&&(iMemory <60281)) { printf("Process Key Image"); }
	if ((iMemory >= 60281)&&(iMemory <60289)) { printf("Pointers to Keyboard decoding tables "); }
	if ((iMemory >= 60289)&&(iMemory <60354)) { printf("Keyboard 1 - unshifted "); }
	if ((iMemory >= 60354)&&(iMemory <60419)) { printf("Keyboard 2 - Shifted "); }
	if ((iMemory >= 60419)&&(iMemory <60484)) { printf("Keyboard 3 - Commodore "); }
	if ((iMemory >= 60484)&&(iMemory <60536)) { printf("Graphics/Text Control"); }
	if ((iMemory >= 60536)&&(iMemory <60601)) { printf("Keyboard 4 - Control "); }
	if ((iMemory >= 60601)&&(iMemory <60647)) { printf("Video Chip Setup Table "); }
	if ((iMemory >= 60647)&&(iMemory <60656)) { printf("Shift-Run Equivalent"); }
	if ((iMemory >= 60656)&&(iMemory <60681)) { printf("Low Byte Screen Line Addresses "); }
	if ((iMemory >= 60681)&&(iMemory <60684)) { printf("talk Send TALK Command on Serial Bus"); }
	if ((iMemory >= 60684)&&(iMemory <60736)) { printf("listn Send LISTEN Command on Serial Bus"); }
	if ((iMemory >= 60736)&&(iMemory <60845)) { printf("Send Data On Serial Bus"); }
	if ((iMemory >= 60845)&&(iMemory <60845)) { printf("Flag Errors"); }
	if ((iMemory >= 60845)&&(iMemory <60848)) { printf("Status #80 device not present"); }
	if ((iMemory >= 60848)&&(iMemory <60857)) { printf("Status #03 write timeout"); }
	if ((iMemory >= 60857)&&(iMemory <60862)) { printf("second Send LISTEN Secondary Address"); }
	if ((iMemory >= 60862)&&(iMemory <60871)) { printf("Clear ATN"); }
	if ((iMemory >= 60871)&&(iMemory <60876)) { printf("tksa Send TALK Secondary Address"); }
	if ((iMemory >= 60876)&&(iMemory <60893)) { printf("Wait For Clock"); }
	if ((iMemory >= 60893)&&(iMemory <60911)) { printf("ciout Send Serial Deferred"); }
	if ((iMemory >= 60911)&&(iMemory <60947)) { printf("untlk Send UNTALK / UNLISTEN"); }
	if ((iMemory >= 60947)&&(iMemory <61061)) { printf("acptr Receive From Serial Bus"); }
	if ((iMemory >= 61061)&&(iMemory <61070)) { printf("Serial Clock On"); }
	if ((iMemory >= 61070)&&(iMemory <61079)) { printf("Serial Clock Off"); }
	if ((iMemory >= 61079)&&(iMemory <61088)) { printf("Serial Output 1"); }
	if ((iMemory >= 61088)&&(iMemory <61097)) { printf("Serial Output 0"); }
	if ((iMemory >= 61097)&&(iMemory <61107)) { printf("Get Serial Data And Clock In"); }
	if ((iMemory >= 61107)&&(iMemory <61115)) { printf("Delay 1 ms"); }
	if ((iMemory >= 61115)&&(iMemory <61190)) { printf("RS-232 Send"); }
	if ((iMemory >= 61190)&&(iMemory <61230)) { printf("Send New RS-232 Byte"); }
	if ((iMemory >= 61230)&&(iMemory <61241)) { printf("'No DSR' / 'No CTS' Error"); }
	if ((iMemory >= 61241)&&(iMemory <61258)) { printf("Disable Timer"); }
	if ((iMemory >= 61258)&&(iMemory <61273)) { printf("Compute Bit Count"); }
	if ((iMemory >= 61273)&&(iMemory <61310)) { printf("RS-232 Receive"); }
	if ((iMemory >= 61310)&&(iMemory <61328)) { printf("Set Up To Receive"); }
	if ((iMemory >= 61328)&&(iMemory <61409)) { printf("Process RS-232 Byte"); }
	if ((iMemory >= 61409)&&(iMemory <61453)) { printf("Submit to RS-232"); }
	if ((iMemory >= 61453)&&(iMemory <61463)) { printf("No DSR (Data Set Ready) Error"); }
	if ((iMemory >= 61463)&&(iMemory <61517)) { printf("Send to RS-232 Buffer"); }
	if ((iMemory >= 61517)&&(iMemory <61574)) { printf("Input From RS-232"); }
	if ((iMemory >= 61574)&&(iMemory <61604)) { printf("Get From RS-232"); }
	if ((iMemory >= 61604)&&(iMemory <61629)) { printf("Serial Bus Idle"); }
	if ((iMemory >= 61629)&&(iMemory <61739)) { printf("Table of Kernal I/O Messages "); }
	if ((iMemory >= 61739)&&(iMemory <61743)) { printf("Print Message if Direct"); }
	if ((iMemory >= 61743)&&(iMemory <61758)) { printf("Print Message"); }
	if ((iMemory >= 61758)&&(iMemory <61783)) { printf("getin Get a byte"); }
	if ((iMemory >= 61783)&&(iMemory <61849)) { printf("chrin Input a byte"); }
	if ((iMemory >= 61849)&&(iMemory <61898)) { printf("Get From Tape / Serial / RS-232"); }
	if ((iMemory >= 61898)&&(iMemory <61966)) { printf("chrout Output One Character"); }
	if ((iMemory >= 61966)&&(iMemory <62032)) { printf("chkin Set Input Device"); }
	if ((iMemory >= 62032)&&(iMemory <62097)) { printf("chkout Set Output Device"); }
	if ((iMemory >= 62097)&&(iMemory <62223)) { printf("close Close File"); }
	if ((iMemory >= 62223)&&(iMemory <62239)) { printf("Find File"); }
	if ((iMemory >= 62239)&&(iMemory <62255)) { printf("Set File values"); }
	if ((iMemory >= 62255)&&(iMemory <62259)) { printf("clall Abort All Files"); }
	if ((iMemory >= 62259)&&(iMemory <62282)) { printf("clrchn Restore Default I/O"); }
	if ((iMemory >= 62282)&&(iMemory <62421)) { printf("open Open File"); }
	if ((iMemory >= 62421)&&(iMemory <62473)) { printf("Send Secondary Address"); }
	if ((iMemory >= 62473)&&(iMemory <62622)) { printf("Open RS-232"); }
	if ((iMemory >= 62622)&&(iMemory <62648)) { printf("load Load RAM"); }
	if ((iMemory >= 62648)&&(iMemory <62771)) { printf("Load File From Serial Bus"); }
	if ((iMemory >= 62771)&&(iMemory <62927)) { printf("Load File From Tape"); }
	if ((iMemory >= 62927)&&(iMemory <62913)) { printf("Print \"SEARCHING\" "); }
	if ((iMemory >= 62913)&&(iMemory <62930)) { printf("Print Filename"); }
	if ((iMemory >= 62930)&&(iMemory <62941)) { printf("Print \"LOADING / VERIFYING\" "); }
	if ((iMemory >= 62941)&&(iMemory <62970)) { printf("save Save RAM"); }
	if ((iMemory >= 62970)&&(iMemory <63065)) { printf("Save to Serial Bus"); }
	if ((iMemory >= 63065)&&(iMemory <63119)) { printf("Save to Tape"); }
	if ((iMemory >= 63119)&&(iMemory <63131)) { printf("Print \"SAVING\" "); }
	if ((iMemory >= 63131)&&(iMemory <63197)) { printf("udtim Bump Clock"); }
	if ((iMemory >= 63197)&&(iMemory <63204)) { printf("rdtim Get Time"); }
	if ((iMemory >= 63204)&&(iMemory <63213)) { printf("settim Set Time"); }
	if ((iMemory >= 63213)&&(iMemory <63227)) { printf("stop Check STOP Key"); }
	if ((iMemory >= 63227)&&(iMemory <63227)) { printf("Output I/O Error Messages"); }
	if ((iMemory >= 63227)&&(iMemory <63230)) { printf("'too many files'"); }
	if ((iMemory >= 63230)&&(iMemory <63233)) { printf("'file open'"); }
	if ((iMemory >= 63233)&&(iMemory <63236)) { printf("'file not open'"); }
	if ((iMemory >= 63236)&&(iMemory <63239)) { printf("'file not found'"); }
	if ((iMemory >= 63239)&&(iMemory <63242)) { printf("'device not present'"); }
	if ((iMemory >= 63242)&&(iMemory <63245)) { printf("'not input file'"); }
	if ((iMemory >= 63245)&&(iMemory <63248)) { printf("'not output file'"); }
	if ((iMemory >= 63248)&&(iMemory <63251)) { printf("'missing filename'"); }
	if ((iMemory >= 63251)&&(iMemory <63277)) { printf("'illegal device number'"); }
	if ((iMemory >= 63277)&&(iMemory <63338)) { printf("Find Any Tape Header"); }
	if ((iMemory >= 63338)&&(iMemory <63440)) { printf("Write Tape Header"); }
	if ((iMemory >= 63440)&&(iMemory <63447)) { printf("Get Buffer Address"); }
	if ((iMemory >= 63447)&&(iMemory <63466)) { printf("Set Buffer Stat / End Pointers"); }
	if ((iMemory >= 63466)&&(iMemory <63501)) { printf("Find Specific Tape Header"); }
	if ((iMemory >= 63501)&&(iMemory <63511)) { printf("Bump Tape Pointer"); }
	if ((iMemory >= 63511)&&(iMemory <63534)) { printf("Print \"PRESS PLAY ON TAPE\" "); }
	if ((iMemory >= 63534)&&(iMemory <63544)) { printf("Check Tape Status"); }
	if ((iMemory >= 63544)&&(iMemory <63553)) { printf("Print \"PRESS RECORD...\" "); }
	if ((iMemory >= 63553)&&(iMemory <63588)) { printf("Initiate Tape Read"); }
	if ((iMemory >= 63588)&&(iMemory <63605)) { printf("Initiate Tape Write"); }
	if ((iMemory >= 63605)&&(iMemory <63696)) { printf("Common Tape Code"); }
	if ((iMemory >= 63696)&&(iMemory <63714)) { printf("Check Tape Stop"); }
	if ((iMemory >= 63714)&&(iMemory <63788)) { printf("Set Read Timing"); }
	if ((iMemory >= 63788)&&(iMemory <64096)) { printf("Read Tape Bits"); }
	if ((iMemory >= 64096)&&(iMemory <64398)) { printf("Store Tape Characters"); }
	if ((iMemory >= 64398)&&(iMemory <64407)) { printf("Reset Tape Pointer"); }
	if ((iMemory >= 64407)&&(iMemory <64422)) { printf("New Character Setup"); }
	if ((iMemory >= 64422)&&(iMemory <64456)) { printf("Send Tone to Tape"); }
	if ((iMemory >= 64456)&&(iMemory <64461)) { printf("Write Data to Tape"); }
	if ((iMemory >= 64461)&&(iMemory <64599)) { printf("IRQ Entry Point"); }
	if ((iMemory >= 64599)&&(iMemory <64659)) { printf("Write Tape Leader"); }
	if ((iMemory >= 64659)&&(iMemory <64696)) { printf("Restore Normal IRQ"); }
	if ((iMemory >= 64696)&&(iMemory <64714)) { printf("Set IRQ Vector"); }
	if ((iMemory >= 64714)&&(iMemory <64721)) { printf("Kill Tape Motor"); }
	if ((iMemory >= 64721)&&(iMemory <64731)) { printf("Check Read / Write Pointer"); }
	if ((iMemory >= 64731)&&(iMemory <64738)) { printf("Bump Read / Write Pointer"); }
	if ((iMemory >= 64738)&&(iMemory <64770)) { printf("Power-Up RESET Entry"); }
	if ((iMemory >= 64770)&&(iMemory <64786)) { printf("Check For 8-ROM"); }
	if ((iMemory >= 64786)&&(iMemory <64789)) { printf("8-ROM Mask '80CBM' "); }
	if ((iMemory >= 64789)&&(iMemory <64794)) { printf("restor Restore Kernal Vectors (at 0314)"); }
	if ((iMemory >= 64794)&&(iMemory <64816)) { printf("vector Change Vectors For User"); }
	if ((iMemory >= 64816)&&(iMemory <64848)) { printf("Kernal Reset Vectors "); }
	if ((iMemory >= 64848)&&(iMemory <64923)) { printf("ramtas Initialise System Constants"); }
	if ((iMemory >= 64923)&&(iMemory <64931)) { printf("IRQ Vectors For Tape I/O "); }
	if ((iMemory >= 64931)&&(iMemory <64989)) { printf("ioinit Initialise I/O"); }
	if ((iMemory >= 64989)&&(iMemory <65017)) { printf("Enable Timer"); }
	if ((iMemory >= 65017)&&(iMemory <65024)) { printf("setnam Set Filename"); }
	if ((iMemory >= 65024)&&(iMemory <65031)) { printf("setlfs Set Logical File Parameters"); }
	if ((iMemory >= 65031)&&(iMemory <65048)) { printf("readst Get I/O Status Word"); }
	if ((iMemory >= 65048)&&(iMemory <65057)) { printf("setmsg Control OS Messages"); }
	if ((iMemory >= 65057)&&(iMemory <65061)) { printf("settmo Set IEEE Timeout"); }
	if ((iMemory >= 65061)&&(iMemory <65076)) { printf("memtop Read / Set Top of Memory"); }
	if ((iMemory >= 65076)&&(iMemory <65091)) { printf("membot Read / Set Bottom of Memory"); }
	if ((iMemory >= 65091)&&(iMemory <65126)) { printf("NMI Transfer Entry"); }
	if ((iMemory >= 65126)&&(iMemory <65212)) { printf("Warm Start Basic [BRK]"); }
	if ((iMemory >= 65212)&&(iMemory <65218)) { printf("Exit Interrupt"); }
	if ((iMemory >= 65218)&&(iMemory <65238)) { printf("RS-232 Timing Table NTSC "); }
	if ((iMemory >= 65238)&&(iMemory <65287)) { printf("NMI RS-232 In"); }
	if ((iMemory >= 65287)&&(iMemory <65347)) { printf("NMI RS-232 Out"); }
	if ((iMemory >= 65347)&&(iMemory <65352)) { printf("Fake IRQ Entry"); }
	if ((iMemory >= 65352)&&(iMemory <65371)) { printf("IRQ Entry"); }
	if ((iMemory >= 65371)&&(iMemory <65408)) { printf("cint Initialize screen editor"); }
	if ((iMemory >= 65408)&&(iMemory <65409)) { printf("Kernal Version Number [03] "); }
	if ((iMemory >= 65409)&&(iMemory <65412)) { printf("jmp abs 65371 cint Init Editor & Video Chips"); }
	if ((iMemory >= 65412)&&(iMemory <65415)) { printf("jmp abs 64803 ioinit Init I/O Devices, Ports & Timers"); }
	if ((iMemory >= 65415)&&(iMemory <65418)) { printf("jmp abs 64848 ramtas Init Ram & Buffers"); }
	if ((iMemory >= 65418)&&(iMemory <65421)) { printf("jmp abs 64789 restor Restore Vectors"); }
	if ((iMemory >= 65421)&&(iMemory <65424)) { printf("jmp abs 64794 vector Change Vectors For User"); }
	if ((iMemory >= 65424)&&(iMemory <65427)) { printf("jmp abs 65084 setmsg Control OS Messages"); }
	if ((iMemory >= 65427)&&(iMemory <65430)) { printf("jmp abs 60857 secnd Send SA After Listen"); }
	if ((iMemory >= 65430)&&(iMemory <65433)) { printf("jmp abs 60873 tksa Send SA After Talk"); }
	if ((iMemory >= 65433)&&(iMemory <65436)) { printf("jmp abs 65061 memtop Set/Read System RAM Top"); }
	if ((iMemory >= 65436)&&(iMemory <65439)) { printf("jmp abs 65076 membot Set/Read System RAM Bottom"); }
	if ((iMemory >= 65439)&&(iMemory <65442)) { printf("jmp abs 60039 scnkey Scan Keyboard"); }
	if ((iMemory >= 65442)&&(iMemory <65445)) { printf("jmp abs 65057 settmo Set Timeout In IEEE"); }
	if ((iMemory >= 65445)&&(iMemory <65448)) { printf("jmp abs 60947 acptr Handshake Serial Byte In"); }
	if ((iMemory >= 65448)&&(iMemory <65451)) { printf("jmp abs 60893 ciout Handshake Serial Byte Out"); }
	if ((iMemory >= 65451)&&(iMemory <65454)) { printf("jmp abs 60911 untalk Command Serial Bus UNTALK"); }
	if ((iMemory >= 65454)&&(iMemory <65457)) { printf("jmp abs 60926 unlsn Command Serial Bus UNLISTEN"); }
	if ((iMemory >= 65457)&&(iMemory <65460)) { printf("jmp abs 60684 listn Command Serial Bus LISTEN"); }
	if ((iMemory >= 65460)&&(iMemory <65463)) { printf("jmp abs 60681 talk Command Serial Bus TALK"); }
	if ((iMemory >= 65463)&&(iMemory <65466)) { printf("jmp abs 65031 readss Read I/O Status Word"); }
	if ((iMemory >= 65466)&&(iMemory <65469)) { printf("jmp abs 65024 setlfs Set Logical File Parameters"); }
	if ((iMemory >= 65469)&&(iMemory <65472)) { printf("jmp abs 65017 setnam Set Filename"); }
	if ((iMemory >= 65472)&&(iMemory <65475)) { printf("jmp ind Open Vector [62282]"); }
	if ((iMemory >= 65475)&&(iMemory <65478)) { printf("jmp ind Close Vector [62097]"); }
	if ((iMemory >= 65478)&&(iMemory <65481)) { printf("jmp ind Set Input [61966]"); }
	if ((iMemory >= 65481)&&(iMemory <65484)) { printf("jmp ind Set Output [62032]"); }
	if ((iMemory >= 65484)&&(iMemory <65487)) { printf("jmp ind Restore I/O Vector [62259]"); }
	if ((iMemory >= 65487)&&(iMemory <65490)) { printf("jmp ind Input Vector, chrin [61783]"); }
	if ((iMemory >= 65490)&&(iMemory <65493)) { printf("jmp ind Output Vector, chrout [61898]"); }
	if ((iMemory >= 65493)&&(iMemory <65496)) { printf("jmp abs 62622 Load RAM From Device"); }
	if ((iMemory >= 65496)&&(iMemory <65499)) { printf("jmp abs 62941 Save RAM To Device"); }
	if ((iMemory >= 65499)&&(iMemory <65502)) { printf("jmp abs 63204 Set Real-Time Clock"); }
	if ((iMemory >= 65502)&&(iMemory <65505)) { printf("jmp abs 63197 Read Real-Time Clock"); }
	if ((iMemory >= 65505)&&(iMemory <65508)) { printf("jmp ind Test-Stop Vector [63213]"); }
	if ((iMemory >= 65508)&&(iMemory <65511)) { printf("jmp ind Get From Keyboad [61758]"); }
	if ((iMemory >= 65511)&&(iMemory <65514)) { printf("jmp ind Close All Channels And Files [62255]"); }
	if ((iMemory >= 65514)&&(iMemory <65517)) { printf("jmp abs 63131 Increment Real-Time Clock"); }
	if ((iMemory >= 65517)&&(iMemory <65520)) { printf("jmp abs 58628 Return Screen Organization"); }
	if ((iMemory >= 65520)&&(iMemory <65523)) { printf("jmp abs 58634 Read / Set Cursor X/Y Position"); }
	if ((iMemory >= 65523)&&(iMemory <65526)) { printf("jmp abs 58624 Return I/O Base Address"); }
	if ((iMemory >= 65526)&&(iMemory <65528)) { printf("[21074] -"); }
	if ((iMemory >= 65528)&&(iMemory <65530)) { printf("[22850] SYSTEM"); }
	if ((iMemory >= 65530)&&(iMemory <65532)) { printf("[65091] NMI"); }
	if ((iMemory >= 65532)&&(iMemory <65534)) { printf("[64739] RESET"); }
	if ((iMemory >= 65534)&&(iMemory <=65535)) { printf("[65352] IRQ"); }
}
	
	int iOpc[151] = 
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
	char *cMod[] = 
	{
		"Immediate   ", "Zero Page   ", "Zero Page,X ", "Absolute    ", "Absolute,X  ", "Absolute,Y  ", "(Indirect,X)", "(Indirect),Y", "Immediate   ", "Zero Page   ", "Zero Page,X ", 
		"Absolute    ", "Absolute,X  ", "Absolute,Y  ", "(Indirect,X)", "(Indirect),Y", "Immediate   ", "Zero Page   ", "Zero Page,X ", "Absolute    ", "Absolute,X  ", "Absolute,Y  ", 
		"(Indirect,X)", "(Indirect),Y", "Accumulator ", "Zero Page   ", "Zero Page,X ", "Absolute    ", "Absolute,X  ", "Accumulator ", "Zero Page   ", "Zero Page,X ", "Absolute    ", 
		"Absolute,X  ", "Accumulator ", "Zero Page   ", "Zero Page,X ", "Absolute    ", "Absolute,X  ", "Accumulator ", "Zero Page   ", "Zero Page,X ", "Absolute    ", "Absolute,X  ", 
		"Relative    ", "Relative    ", "Relative    ", "Relative    ", "Relative    ", "Relative    ", "Relative    ", "Relative    ", "Immediate   ", "Zero Page   ", "Zero Page,X ", 
		"Absolute    ", "Absolute,X  ", "Absolute,Y  ", "(Indirect,X)", "(Indirect),Y", "Immediate   ", "Zero Page   ", "Absolute    ", "Immediate   ", "Zero Page   ", "Absolute    ", 
		"Zero Page   ", "Absolute    ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Absolute    ", "Indirect    ", 
		"Absolute    ", "Implied     ", "Implied     ", "Immediate   ", "Zero Page   ", "Zero Page,X ", "Absolute    ", "Absolute,X  ", "Absolute,Y  ", "(Indirect,X)", "(Indirect),Y", 
		"Immediate   ", "Zero Page   ", "Zero Page,X ", "Absolute    ", "Absolute,X  ", "Absolute,Y  ", "(Indirect,X)", "(Indirect),Y", "Immediate   ", "Zero Page   ", "Zero Page,X ", 
		"Absolute    ", "Absolute,X  ", "Absolute,Y  ", "(Indirect,X)", "(Indirect),Y", "Immediate   ", "Zero Page   ", "Zero Page,Y ", "Absolute    ", "Absolute,Y  ", "Immediate   ", 
		"Zero Page   ", "Zero Page,X ", "Absolute    ", "Absolute,X  ", "Zero Page   ", "Zero Page,X ", "Absolute    ", "Absolute,X  ", "Absolute,Y  ", "(Indirect,X)", "(Indirect),Y", 
		"Zero Page   ", "Zero Page,Y ", "Absolute    ", "Zero Page   ", "Zero Page,X ", "Absolute    ", "Zero Page   ", "Zero Page,X ", "Absolute    ", "Absolute,X  ", "Zero Page   ", 
		"Zero Page,X ", "Absolute    ", "Absolute,X  ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", 
		"Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "Implied     ", "            " 
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
	char *cDesc[] = 
	{
		"Bitwise AND with Accumulator         ", "Bitwise AND with Accumulator         ", "Bitwise AND with Accumulator         ", "Bitwise AND with Accumulator         ", 
		"Bitwise AND with Accumulator         ", "Bitwise AND with Accumulator         ", "Bitwise AND with Accumulator         ", "Bitwise AND with Accumulator         ", 
		"Bitwise Exclusive-OR with Accumulator", "Bitwise Exclusive-OR with Accumulator", "Bitwise Exclusive-OR with Accumulator", "Bitwise Exclusive-OR with Accumulator", 
		"Bitwise Exclusive-OR with Accumulator", "Bitwise Exclusive-OR with Accumulator", "Bitwise Exclusive-OR with Accumulator", "Bitwise Exclusive-OR with Accumulator", 
		"Bitwise OR with Accumulator          ", "Bitwise OR with Accumulator          ", "Bitwise OR with Accumulator          ", "Bitwise OR with Accumulator          ", 
		"Bitwise OR with Accumulator          ", "Bitwise OR with Accumulator          ", "Bitwise OR with Accumulator          ", "Bitwise OR with Accumulator          ", 
		"Arithmetic Shift Left                ", "Arithmetic Shift Left                ", "Arithmetic Shift Left                ", "Arithmetic Shift Left                ", 
		"Arithmetic Shift Left                ", "Logical Shift Right                  ", "Logical Shift Right                  ", "Logical Shift Right                  ", 
		"Logical Shift Right                  ", "Logical Shift Right                  ", "Rotate Left                          ", "Rotate Left                          ", 
		"Rotate Left                          ", "Rotate Left                          ", "Rotate Left                          ", "Rotate Right                         ", 
		"Rotate Right                         ", "Rotate Right                         ", "Rotate Right                         ", "Rotate Right                         ", 
		"Branch on Plus                       ", "Branch on Minus                      ", "Branch on Overflow Clear             ", "Branch on Overflow Set               ", 
		"Branch on Carry Clear                ", "Branch on Carry Set                  ", "Branch on Not Equal                  ", "Branch on Equal                      ", 
		"Compare Accumulator                  ", "Compare Accumulator                  ", "Compare Accumulator                  ", "Compare Accumulator                  ", 
		"Compare Accumulator                  ", "Compare Accumulator                  ", "Compare Accumulator                  ", "Compare Accumulator                  ", 
		"Compare X Register                   ", "Compare X Register                   ", "Compare X Register                   ", "Compare Y Register                   ", 
		"Compare Y Register                   ", "Compare Y Register                   ", "Test Bits                            ", "Test Bits                            ", 
		"Clear Carry                          ", "Set Carry                            ", "Clear Interrupt                      ", "Set Interrupt                        ", 
		"Clear Decimal                        ", "Set Decimal                          ", "Clear Overflow                       ", "Jump                                 ", 
		"Jump                                 ", "Jump Saving Return                   ", "Return to Saved                      ", "Return from Interrupt                ", 
		"Add with Carry                       ", "Add with Carry                       ", "Add with Carry                       ", "Add with Carry                       ", 
		"Add with Carry                       ", "Add with Carry                       ", "Add with Carry                       ", "Add with Carry                       ", 
		"Subtract with Carry                  ", "Subtract with Carry                  ", "Subtract with Carry                  ", "Subtract with Carry                  ", 
		"Subtract with Carry                  ", "Subtract with Carry                  ", "Subtract with Carry                  ", "Subtract with Carry                  ", 
		"Load Accumulator                     ", "Load Accumulator                     ", "Load Accumulator                     ", "Load Accumulator                     ", 
		"Load Accumulator                     ", "Load Accumulator                     ", "Load Accumulator                     ", "Load Accumulator                     ", 
		"Load X Register                      ", "Load X Register                      ", "Load X Register                      ", "Load X Register                      ", 
		"Load X Register                      ", "Load Y Register                      ", "Load Y Register                      ", "Load Y Register                      ", 
		"Load Y Register                      ", "Load Y Register                      ", "Store Accumulator                    ", "Store Accumulator                    ", 
		"Store Accumulator                    ", "Store Accumulator                    ", "Store Accumulator                    ", "Store Accumulator                    ", 
		"Store Accumulator                    ", "Store X Register                     ", "Store X Register                     ", "Store X Register                     ", 
		"Store Y Register                     ", "Store Y Register                     ", "Store Y Register                     ", "Decrement Memory                     ", 
		"Decrement Memory                     ", "Decrement Memory                     ", "Decrement Memory                     ", "Increment Memory                     ", 
		"Increment Memory                     ", "Increment Memory                     ", "Increment Memory                     ", "Transfer A to X                      ", 
		"Transfer A to Y                      ", "Tranfer X to A                       ", "Transfer Y to A                      ", "Decrement X                          ", 
		"Decrement Y                          ", "Increment X                          ", "Increment Y                          ", "Push Accumulator                     ", 
		"Push Processor Status                ", "Transfer X to Stack Pointer          ", "Pull Accumulator                     ", "Transfer Stack Pointer to X          ", 
		"Pull Processor Status                ", "Break                                ", "No Operation                         ", "                                     "
	};
	int iNum1, iNum2, iNum3, a;
	iNum1 = 0;
	iNum2 = 0;
	iNum3 = 0;	
	a = 0;
	if (argc > 1) {sscanf(argv[1], "%d", &iNum1); }
	if (argc > 2) {sscanf(argv[2], "%d", &iNum2); }
	if (argc > 3) {sscanf(argv[3], "%d", &iNum3); }
	if (iNum3 > 256) {iNum3 = 256; }
	int iLines = 0;
	if ((argc > 2)&&(argc <5))
	{		
		FILE *file_ptr;
		char ch;
		file_ptr = fopen(argv[1], "rb");
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
		int iChars=0;
		int iTest = 0;
		int iCount = 0;
		int iN1 = 1;
		int iN2 = 1;
		int iN3 = 1;
		int iOperand16 = 0;
		int iOperand8 = 0;
		int iLength = 0;
		int iIndex = 0;
		int iOffset = 0;
		int iPointer = 0;
		int iBasic = 1;
		int iLinebreak = 0;
		int iLinenumber = 0;
		int iLinenumber2 = 0;
		if (iNum2 == 0)
		{
			while (iBasic) 
			{
				ch = fgetc(file_ptr);
				if (feof(file_ptr)) 
				{
					printf("\nfeof() end of file at %i\n",a-1);
					break;
				}
				a++;
				if ((a > iNum2)&&(a <= iNum2 + iNum3)) 
				{
					int bNum1 = (int)ch;
					if (bNum1 < 0) { bNum1 = bNum1 + 256; }
					iN3 = iN2;
					iN2 = iN1;
					if (bNum1 == 0) { iN1 = 0; }
					if (bNum1 != 0) { iN1 = 1; }
					if ((iN3 == 0) && (iN2 == 0) && (iN1 == 0)) { iBasic = 0; }
					if (iCount > 1)
					{
						if (iCount == 3) {iOperand16 += bNum1;}
						if (iCount == 2) 
						{
							iOperand16 += 256 * bNum1; iOperand8 = bNum1;
							if (iLength == 3) 
							{
								printf("%5i ", iOperand16); 
								if ((iNum2 == 0) && (a == 2)) 
								{ 
									iOffset = iOperand16 - 2; 
									if (iOffset != 2049) { iBasic = 0;}
								}
								if (iLinenumber2 == 1) { printf("Basic line number"); iLinenumber2 = 0; }
								if (iPointer == 1 && iOperand16!=0) { printf("Point to next line"); iPointer = 0; }
							} 	if (iPointer == 1 && iOperand16==0) { printf("End of Basic list"); iPointer = 0; }
							if (iLength == 2) {printf("%5i ", iOperand8); }
						}
						iCount--;				
					}
					else
					{
						iCount = 0;
						iOperand16 = 0;
						iOperand8 = 0;
						iLength = 0;
						iIndex = 0;
						iLines++;
						if (iLines == 1)
						{
							printf("\nDisassembler6510 has decompiled the code into:\n");
							printf("\nadr   mne mde oprnd mnemonic description                  mode description ");
							printf("\n%05i ", a - 1 + iOffset);
						}
						if (a == 1 && iNum2 == 0) 
						{ 
							iOperand16 += bNum1;
							iIndex = 151;
							iLength = 3;
							iCount = 2;
							printf(".dt     "); 
							
						}
						
						if (iLinenumber == 1) 
						{
							iLinenumber = 0;
							iLinenumber2 = 1;
							iOperand16 += bNum1;
							iIndex = 151;
							iLength = 3;
							iCount = 2;
							printf("\n%05i .dt     ", a - 1 + iOffset); 
						}
						if (a == 3 && iNum2 == 0) 
						{ 
							iOperand16 += bNum1;
							iIndex = 151;
							iLength = 3;
							iCount = 2;
							printf("\n%05i .dt     ", a - 1 + iOffset); 
							iLinenumber = 1;
							iPointer = 1;
						}
						
						if (iLinebreak == 1) 
						{ 
							iPointer = 1;
							iLinebreak = 0;
							iLinenumber = 1;
							iOperand16 += bNum1;
							iIndex = 151;
							iLength = 3;
							iCount = 2;
							printf("\n%05i .dt     ", a - 1 + iOffset); 
						}
						
						if ((bNum1 > 31)&&(bNum1 < 127)) { iChars++; } 
						if (iIndex == 0)
						{ 
							printf("\n%05i .by      %4i ", a - 1 + iOffset, bNum1);
							if ((bNum1 > 31)&&(bNum1 < 127)) { printf("'%c'", bNum1); } 
							if (bNum1 == 171) { printf("'-'"); } 
							if (bNum1 == 172) { printf("'*'"); } 
							if (bNum1 == 173) { printf("'/'"); }
							if (bNum1 == 178) { printf("'='"); } 
							if (bNum1 == 151) { printf("Basic token 'poke'"); }
							if (bNum1 == 158) { printf("Basic token 'sys'"); } 
							if (bNum1 == 153) { printf("Basic token 'print'"); }
							
							if (bNum1 == 0) 
							{ 
								printf("Line Break");
								iLinebreak = 1;
							}	
							
						} 
					}
				}
			}
			while (1) 
			{
				ch = fgetc(file_ptr);
				if (feof(file_ptr)) 
				{
					printf("\nfeof() end of file at %i\n", a - 1 + iOffset);
					break;
				}
			a++;
			if ((a > iNum2)&&(a <= iNum2 + iNum3)) 
			{
				int bNum1 = (int)ch;
				if (bNum1 < 0) { bNum1 = bNum1 + 256; }
				if (iCount > 1)
				{
					if (iCount == 3) {iOperand16 += bNum1;}
					if (iCount == 2) 
					{
						iOperand16 += 256 * bNum1; iOperand8 = bNum1;
						if (iLength == 3) 
						{
							printf("%5i %s %s ", iOperand16, cDesc[iIndex], cMod[iIndex]);
							printf("//adress %i=",iOperand16);
							memlocation(iOperand16);
						}	// Insert memlocation(iOperand16) here
						if (iLength == 2) {printf("%5i %s %s ", iOperand8, cDesc[iIndex], cMod[iIndex]); }
					}
					iCount--;				
					}
					else
					{
						iCount = 0;
						iOperand16 = 0;
						iOperand8 = 0;
						iLength = 0;
						iIndex = 0;
						for (int i = 0; i <= 150; i++) 
						{
							if (bNum1 == iOpc[i]) 
							{ 
								iIndex = i;
								iLines++;
								if (iLines == 1)
								{
									printf("\nDisassembler6510 has decompiled the code into:\n");
									printf("\nadr   mne mde oprnd mnemonic description                  mode description ");
								}
								printf("\n%05i ", a - 1  + iOffset);
								iCount = iLen[i];
								iLength = iLen[i];
								printf("%s %s ", cMne[i], cAbbrmod[i]); 
								if (iLength == 1) {printf("      %s %s ", cDesc[iIndex], cMod[iIndex]); }
							}
						}
						if ((bNum1 > 31)&&(bNum1 < 127)) { iChars++; } 
						if (iIndex == 0)
						{ 
							printf("\n%05i .by      %4i ", a - 1 + iOffset, bNum1);
							if ((bNum1 > 31)&&(bNum1 < 127)) { printf("'%c'", bNum1); } 
						} 
					}
				}
			}
		}
		fclose(file_ptr);
		if (iChars > 4) { printf("\nFound %i ascii characters, use %cdat%c for dataview.\n",iChars, '"', '"'); }
	}
	if (iLines == 0)
	{
		printf("\nDisassemble PRG files for the C64 8-bit MOS Technology 6510 microprocessor.\nInput from file; Output text to the standard output stream.\n");
		printf("Use:\nUse:\ndis <file> <start-adress> <length>\nMaximum length 256 byte.\n");
		printf("\nExamples:\n");
		printf("dis %cturbo64.prg%c 32654 256   / disassemble turbo.prg adresses 32654-32910\n", '"', '"');  // Or escape sequence /"
	}
	return 0;	


				
}