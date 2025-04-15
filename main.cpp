#include <fstream>
#include "Render.h"

#define DEBUG = true;

HANDLE g_ConsoleHandle = NULL;
FILE* g_ConsoleOutput = NULL;

bool Init()
{

#ifdef DEBUG
	g_ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	AllocConsole();

	freopen_s(&g_ConsoleOutput, "CONOUT$", "w", stdout);
#endif

	bool Result;

	Result = mem.Init();
	if (!Result) {
#ifdef DEBUG
		printf("Failed to init memory!\n");
#endif
		return false;
	}

	Result = mem.GetInput()->Init();
	if (!Result) {
#ifdef DEBUG
		printf("Failed to init input!\n");
#endif
		return false;
	}

	il2cpp::Init();
	Unity::Methods::Init();
	Hooks::InitOnGUI((void*)render->OnGUI);
	Hooks::InitUpdateVisuals((void*)render->UpdateSky);

	return Result;
}

bool CleanUp()
{
	// Other functions

#ifdef DEBUG
	if (g_ConsoleOutput)
	{
		fclose(g_ConsoleOutput);
		g_ConsoleOutput = NULL;
	}

	if (g_ConsoleHandle)
	{
		FreeConsole();
		g_ConsoleHandle = NULL;
	}
#endif

	return true;
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		return Init();
	case DLL_PROCESS_DETACH:
		return CleanUp();

	default:
		return TRUE;
	}
}