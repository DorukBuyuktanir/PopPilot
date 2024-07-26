#include "FrameController.h"

int main()
{
	printf("Loading...:)");
	SystemInfo systemInfo = newSystenInfo();
	if(!functionEmpty(Awake))
		Awake(systemInfo);

	while (true) {
		if (!functionEmpty(Update))
			Update(systemInfo);


		if (!functionEmpty(LateUpdate))
			LateUpdate(systemInfo);
	}
}