#include <Windows.h>
#include <stdio.h>
#include "../MINT.h"

int main(int argc, char* argv[]) {
	LPVOID BaseAddress = nullptr;
	SIZE_T  RegionSize = 4096;
	NTSTATUS Status = STATUS_SUCCESS;

	if (!NT_SUCCESS(Status = NtAllocateVirtualMemory(NtCurrentProcess(), &BaseAddress, NULL, &RegionSize, MEM_COMMIT, PAGE_READWRITE))) {
		printf("Failed call NtAllocateVirtualMemory, error code is 0x%08X\n", Status);
	}

	RegionSize = 0;

	if (!NT_SUCCESS(Status = NtFreeVirtualMemory(NtCurrentProcess(), &BaseAddress, &RegionSize, MEM_RELEASE))) {
		printf("Failed call NtFreeVirtualMemory, error code is 0x%08X\n", Status);
	}

	printf("Test passed!\n");

	system("pause");
}