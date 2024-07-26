#include "SystemInfo.h"

SystemInfo newSystenInfo() {
	register SystemInfo* systemInfoPtr = (SystemInfo*)malloc(sizeof(SystemInfo));

	if (systemInfoPtr == NULL) {
		printf("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	return *systemInfoPtr;
}