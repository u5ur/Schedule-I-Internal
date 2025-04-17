#include <fstream>
#include "Game/Render.h"

HANDLE g_ConsoleHandle = NULL;
FILE* g_ConsoleOutput = NULL;

bool Init()
{

#if DEBUG
	g_ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	AllocConsole();
	freopen_s(&g_ConsoleOutput, "CONOUT$", "w", stdout);
#endif

	bool Result;

	Result = mem.Init();
	if (!Result) {
#if DEBUG
		printf("Failed to init memory!\n");
#endif
		return false;
	}

	Result = mem.GetInput()->Init();
	if (!Result) {
#if DEBUG
		printf("Failed to init input!\n");
#endif
		return false;
	}

#if USE_ASSETBUNDLE && DEBUG
	printf("(USE_ASSETBUNDLE is true) Asset Bundles will attempt to be loaded!\n");
#endif

	il2cpp::Init();
	Unity::Methods::Init();
	Sdk::Methods::Init();

	Hooks::InitOnGUI((void*)Render::OnGUI);
	Hooks::InitUpdateVisuals((void*)Render::UpdateSky);
	Hooks::InitUpdate((void*)Render::UpdateCamera);
	Hooks::InitUpdateWeapon((void*)Render::UpdateWeapon);
	Hooks::InitUpdateMoney((void*)Render::UpdateMoney);

	return Result;
}

bool CleanUp()
{
	// Other functions

#if DEBUG
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