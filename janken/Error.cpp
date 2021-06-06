#include "DxLib.h"
#include "Error.h"
#include "Define.h"
#include <string>

using namespace std;

void Error::finish(const char* errorMessage, LPCTSTR lpszFuncName, int lineN) 
{
	char funcName[1024];
	sprintf_s(funcName, sizeof(funcName), "%s", lpszFuncName);
	printfDx("àŸèÌÇ™î≠ê∂ÇµÇ‹ÇµÇΩÅB\n%s\n%s(%d)"
			,errorMessage
			,funcName
			,lineN
	);
	while (!ProcessMessage()) {
		ClearDrawScreen();
		ScreenFlip();
	}
	DxLib_End();
	exit(99);
}