00000 .dt      2049 
02049 .dt      2059 Point to next line
02051 .dt        10 Basic line number
02053 .by       158 Basic token 'sys'
02054 .by        50 '2'
02055 .by        48 '0'
02056 .by        55 '7'
02057 .by        53 '5'
02058 .by         0 Line Break
02059 .dt         0 End of Basic list
02061 lda imm     1 Load Accumulator                      Immediate    //start of interrupt service routine, load color white
02063 sta abs 53280 Store Accumulator                     Absolute     //adress 53280=Border Color
02066 sta abs 53281 Store Accumulator                     Absolute     //adress 53281=Background Color 
02069 inc abs 53270 Increment Memory                      Absolute     //adress 53270=VIC Control Register b5 ALWAYS CLEAR THIS BIT! b4 Multi-Color Mode b3 Select 38/40 Column Text Display b2-b0 Smooth Scroll to X Pos
02072 jmp abs 59953 Jump                                  Absolute     //adress 59953=Main IRQ Entry Point
02075 lda imm    13 Load Accumulator                      Immediate    //start the routine sys 2075 
02077 sta abs   788 Store Accumulator                     Absolute     //adress 788=Vector: Hardware Interrupt
02080 lda imm     8 Load Accumulator                      Immediate    //store 2061 in the hardware interrupt vector  
02082 sta abs   789 Store Accumulator                     Absolute     
02085 rts           Return to Saved                       Implied 