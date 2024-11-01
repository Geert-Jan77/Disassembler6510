00000 .dt     49152 
49152 sei           Set Interrupt                            
49153 lda imm    84 Load Accumulator                         
49155 sta abs   788 Store Accumulator                        //adress 788=Vector: Hardware Interrupt, Store adress 49236. This is now the new hardware interrupt service routine.
49158 lda imm   192 Load Accumulator                         
49160 sta abs   789 Store Accumulator                        
49163 lda imm   188 Load Accumulator                         
49165 sta abs   792 Store Accumulator                        //adress 792=Vector: Non-Maskable Interrupt, Store adress 49340. This is now the new nonmaskable interrupt service routine.
49168 lda imm   192 Load Accumulator                         
49170 sta abs   793 Store Accumulator                        
49173 lda imm   214 Load Accumulator                         
49175 sta abs   790 Store Accumulator                        //adress 790=Vector: BRK Instr. Interrupt, Store adress 49366. This is now the new Brk interrupt service routine.
49178 lda imm   192 Load Accumulator                         
49180 sta abs   791 Store Accumulator                        
49183 lda abs 53265 Load Accumulator                         //adress 53265=Video interface control register b7 Raster Compare 
49186 and imm   127 Bitwise AND with Accumulator             
49188 sta abs 53265 Store Accumulator                        //adress 53265=Video interface control register b7 Raster Compare 
49191 lda imm     1 Load Accumulator                         // white
49193 sta abs 53273 Store Accumulator                        //adress 53273=VIC Interrupt Flag Register (set when IRQ Occurred)7 Set on Any Enabled VIC IRQ Condition b3 Light-Pen Triggered IRQ Flag b2 Sprite to Sprite Collision b1 Sprite to Background Collision b0 Raster Compare
49196 sta abs 53274 Store Accumulator                        //adress 53274=IRQ Mask Register: set = Interrupt Enabled
49199 sta zer     2 Store Accumulator                        
49201 sta abs   646 Store Accumulator                        //adress 646=Current Character Color Code
49204 lda imm     6 Load Accumulator                         // blue
49206 sta abs 53281 Store Accumulator                        //adress 53281=Background Color 
49209 lda imm   147 Load Accumulator                         
49211 ldy imm    60 Load Y Register                          
49213 sty abs   648 Store Y Register                         //adress 648=Top of Screen Memory (Page)
49216 jsr abs 65490 Jump Saving Return                       //adress 65490=jmp ind Output Vector, chrout [61898]
49219 ldy imm     4 Load Y Register                          
49221 sty abs   648 Store Y Register                         //adress 648=Top of Screen Memory (Page)
49224 jsr abs 65490 Jump Saving Return                       //adress 65490=jmp ind Output Vector, chrout [61898]
49227 lda imm   226 Load Accumulator                         
49229 ldy imm   192 Load Y Register                          
49231 jsr abs 43806 Jump Saving Return                       //adress 43806=Output String
49234 cli           Clear Interrupt                          
49235 rts           Return to Saved                          
49236 lda imm     1 Load Accumulator                         // Start of new hardware interrupt service routine.
49238 and abs 53273 Bitwise AND with Accumulator             //adress 53273=VIC Interrupt Flag Register (set when IRQ Occurred)7 Set on Any Enabled VIC IRQ Condition b3 Light-Pen Triggered IRQ Flag b2 Sprite to Sprite Collision b1 Sprite to Background Collision b0 Raster Compare
49241 bne         7 Branch on Not Equal                      
49243 lda abs 56333 Load Accumulator                         //adress 56333=Complex interface adapter Interrupt control register (Read IRQs/Write Mask) b7 IRQ Flag (1 = IRQ Occurred) / Set-Clear Flag b4 FLAG1 IRQ (Cassette Read / Serial Bus SRQ Input) b3 Serial Port Interrupt b2 Time-of-Day Clock Alarm Interrupt b1 Timer B Interrupt b0 Timer A Interrupt
49246 cli           Clear Interrupt                          
49247 jmp abs 59953 Jump                                     //adress 59953=Main IRQ Entry Point
49250 sta abs 53273 Store Accumulator                        //adress 53273=VIC Interrupt Flag Register (set when IRQ Occurred)7 Set on Any Enabled VIC IRQ Condition b3 Light-Pen Triggered IRQ Flag b2 Sprite to Sprite Collision b1 Sprite to Background Collision b0 Raster Compare
49253 ldy zer     2 Load Y Register                          
49255 bne        11 Branch on Not Equal                      //to 49268
49257 nop           No Operation                             
49258 jsr abs 49308 Jump Saving Return                       //adress 49308                            
49261 inc zer     2 Increment Memory                         
49263 ldy imm   152 Load Y Register                          
49265 jmp abs 49275 Jump                                     //adress 49275                         
49268 jsr abs 49324 Jump Saving Return                       //adress 49324                          
49271 dec zer     2 Decrement Memory                         
49273 ldy imm     2 Load Y Register                          
49275 sty abs 53266 Store Y Register                         //adress 53266=Read Raster / Write Rasterline Value for Compare IRQ
49278 ldy zer   204 Load Y Register                          
49280 bne        20 Branch on Not Equal                      
49282 ldy imm    60 Load Y Register                          
49284 lda zer   210 Load Accumulator                         
49286 and imm     3 Bitwise AND with Accumulator             
49288 cmp imm     2 Compare Accumulator                      
49290 bcs         2 Branch on Carry Set                      //to 49294
49292 ldy imm     4 Load Y Register                          
49294 sty abs   648 Store Y Register                         //adress 648=Top of Screen Memory (Page)
49297 ora abs   648 Bitwise OR with Accumulator              //adress 648=Top of Screen Memory (Page)
49300 sta zer   210 Store Accumulator                        
49302 pla           Pull Accumulator                         
49303 tay           Transfer A to Y                          
49304 pla           Pull Accumulator                         
49305 tax           Transfer A to X                          
49306 pla           Pull Accumulator                         
49307 rti           Return from Interrupt                    
49308 ldx imm     2 Load X Register                          //* Red
49310 stx abs 53280 Store X Register                         //adress 53280=Border Color 
49313 lda abs 53272 Load Accumulator                         //adress 53272=VIC Memory Control Register b7-b4 Video Matrix Base Address (inside VIC) b3-b1 Character Dot-Data Base Address (inside VIC) b0 Select upper/lower Character Set
49316 and imm    15 Bitwise AND with Accumulator             
49318 ora imm    16 Bitwise OR with Accumulator              
49320 sta abs 53272 Store Accumulator                        //adress 53272=VIC Memory Control Register b7-b4 Video Matrix Base Address (inside VIC) b3-b1 Character Dot-Data Base Address (inside VIC) b0 Select upper/lower Character Set
49323 rts           Return to Saved                          
49324 ldx imm     1 Load X Register                          //* White
49326 stx abs 53280 Store X Register                         //adress 53280=Border Color 
49329 lda abs 53272 Load Accumulator                         //adress 53272=VIC Memory Control Register b7-b4 Video Matrix Base Address (inside VIC) b3-b1 Character Dot-Data Base Address (inside VIC) b0 Select upper/lower Character Set
49332 and imm    15 Bitwise AND with Accumulator             
49334 ora imm   240 Bitwise OR with Accumulator              
49336 sta abs 53272 Store Accumulator                        //adress 53272=VIC Memory Control Register b7-b4 Video Matrix Base Address (inside VIC) b3-b1 Character Dot-Data Base Address (inside VIC) b0 Select upper/lower Character Set
49339 rts           Return to Saved                          
49340 pha           Push Accumulator                         // Start of new nonmaskable interrupt service routine.                  
49341 txa           Tranfer X to A                           
49342 pha           Push Accumulator                         
49343 tya           Transfer Y to A                          
49344 pha           Push Accumulator                         
49345 lda imm   127 Load Accumulator                         
49347 sta abs 56589 Store Accumulator                        //adress 56589=Complex interface adapter Interrupt Control Register (Read NMls/Write Mask) b7 NMI Flag (1 = NMI Occurred) / Set-Clear Flag b4 FLAG1 NMI (User/RS-232 Received Data Input) b3 Serial Port Interrupt b1 Timer B Interrupt b0 Timer A Interrupt
49350 ldy abs 56589 Load Y Register                          //adress 56589=Complex interface adapter Interrupt Control Register (Read NMls/Write Mask) b7 NMI Flag (1 = NMI Occurred) / Set-Clear Flag b4 FLAG1 NMI (User/RS-232 Received Data Input) b3 Serial Port Interrupt b1 Timer B Interrupt b0 Timer A Interrupt
49353 bpl         3 Branch on Plus                           
49355 jmp abs 65138 Jump                                     //adress 65138=Warm Start Basic [BRK]
49358 jsr abs 63164 Jump Saving Return                       //adress 63164=udtim Bump Clock
49361 jsr abs 65505 Jump Saving Return                       //adress 65505=jmp ind Test-Stop Vector [63213]
49364 bne       245 Branch on Not Equal                      //to 49355                  
49366 jsr abs 64931 Jump Saving Return                       //adress 64931=ioinit Initialise I/O
49369 jsr abs 58648 Jump Saving Return                       //adress 58648=cint1 Initialize I/O
49372 jsr abs 49152 Jump Saving Return                       //adress 49152=RAM 4096 bytes                           
49375 jmp ind 40962 Jump                                     //adress 40962=Restart Vectors  
49378 .by        13 'return'          
49379 .by        68 'd'
49380 .by        73 'i'
49381 .by        83 's'
49382 .by        65 'a'
49383 .by        83 's'
49384 .by        83 's'
49385 .by        69 'e'
49386 .by        77 'm'
49387 .by        66 'b'
49388 .by        76 'l'
49389 .by        69 'e'
49390 .by        82 'r'
49391 .by        54 '6'
49392 .by        53 '5'
49393 .by        49 '1'
49394 .by        48 '0'
49395 .by        13 'return'
49396 .by        83 's'
49397 .by        80 'p'
49398 .by        76 'l'
49399 .by        73 'i'
49400 .by        84 't'
49401 .by        83 's'
49402 .by        67 'c'
49403 .by        82 'r'
49404 .by        69 'e'
49405 .by        69 'e'
49406 .by        78 'n'
49407 .by        0  'end of string'