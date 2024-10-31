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