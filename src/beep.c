//char value = *(char*)0x01f4b274; 
//CHAR * pointer = (CHAR*)0x01f4b274; 
#include <stdio.h>
#include <Windows.h>
#include <string.h>

int main(void)
{
	HMODULE libHandle;
	BOOL bRet;
	UINT uFreq, uDuration;
	// pointer to int (4bytes) that points to memory address 0x01f4b274
	int* address = (int *)0x01f4b274; 
	printf("Memory address is: 0x%x\n", address);
	// Note that this address should exist on your process' memory or 
	// the line below will cause a Segmentation Fault
	// *address = 0xdead; //assign a value to that address
	//printf("Content of that address is: 0x%x\n", *address);
	if ((libHandle = LoadLibrary(TEXT("C:/Windows/System32/kernel32.dll"))) == NULL)
    {
        printf("load failed\n");
        return 1;
    }
	
	FARPROC beep;
    if ((beep = GetProcAddress(libHandle, "Beep")) == NULL)
    {
        printf("GetProcAddress failed\n");
        printf("%d\n", GetLastError());
        return 1;
    }
	printf("beep handle %d\n", beep);
	uFreq = 1000;
	uDuration = 200;
	if (!(bRet = beep(uFreq, uDuration)))
	{
		printf("Beep failed\n");
		return 1;
	}
	
	FARPROC openprocess;
    if ((openprocess = GetProcAddress(libHandle, "OpenProcess")) == NULL)
    {
        printf("GetProcAddress failed\n");
        printf("%d\n", GetLastError());
        return 1;
    }
	printf("openprocess handle %d\n", openprocess);
	UINT uFlags = 0x00000010;
	BOOL bInherit = 0;
	UINT uProcess = 0x18c0;
	INT_PTR hProcess;
	if (!(hProcess = openprocess(uFlags, bInherit, uProcess)))
	{
		printf("OpenProcess failed\n");
		return 1;
	}
	printf("Game Process handle %d\n", hProcess);
	
	// read
	//void *addr; // target process address
	SIZE_T written;
	//ReadProcessMemory(proc, addr, &value, sizeof(value), &written);
	FARPROC ReadProcessMemory;
	//INT_PTR hProcess;
    INT_PTR lpBaseAddress;
    INT_PTR lpBuffer;
    UINT dwSize;
    INT_PTR lpNumberOfBytesRead;
	lpBaseAddress = 0x01f4b274;
	FLOAT f = 0.0f;
	lpBuffer = (INT_PTR)&f;
	dwSize = 4;
	CHAR buffer[20];
	lpNumberOfBytesRead = 0;
	if ((ReadProcessMemory = GetProcAddress(libHandle, "ReadProcessMemory")) == NULL)
    {
        printf("GetProcAddress failed\n");
        printf("%d\n", GetLastError());
        return 1;
    }
	printf("ReadProcessMemory handle %d\n", ReadProcessMemory);
	if (!(bRet = ReadProcessMemory(hProcess, lpBaseAddress, &buffer, sizeof(f), lpNumberOfBytesRead)))
    //if (!(bRet = ReadProcessMemory(hProcess, lpBaseAddress, lpBuffer, dwSize, lpNumberOfBytesRead)))
	{
		printf("ReadProcessMemory failed\n");
		return 1;
	}
	printf("Buffer0 %d\n", (byte)buffer[0]);
	printf("Buffer1 %d\n", (byte)buffer[1]);
	printf("Buffer2 %d\n", (byte)buffer[2]);
	printf("Buffer3 %d\n", (byte)buffer[3]);

byte b[] = {(byte)buffer[0], (byte)buffer[1], (byte)buffer[2], (byte)buffer[3]};
memcpy(&f, &b, sizeof(f));

	printf("f %f\n", f);
	FARPROC CloseHandle;
	if ((CloseHandle = GetProcAddress(libHandle, "CloseHandle")) == NULL)
    {
        printf("GetProcAddress failed\n");
        printf("%d\n", GetLastError());
        return 1;
    }
	printf("CloseProcess handle %d\n", CloseHandle);
	if (!(bRet = CloseHandle(hProcess)))
	{
		printf("CloseHandle failed\n");
		return 1;
	}
	

  return 0;
}