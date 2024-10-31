02047 .dt      2049     // pointer to start adress dat = 2byte data lsb-msb byt = 1 byte data
02049 .dt      2059     // pointer to next basic line
02051 .dt        10     // basic line number 10
02053 .by       158     // 158 is the token 'SYS' (153 is the token 'PRINT')
02054 .by        50     // petscii 2
02055 .by        48     // petscii 0
02056 .by        54     // petscii 6 
02057 .by        49     // petscii 1 
02058 .by         0     // terminate line
02059 .dt         0     // pointer to 3rd basic line
02061 rts               // no end of line here