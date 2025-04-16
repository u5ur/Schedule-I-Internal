#include "Render.h"

void Render::RenderMenu()
{
	static bool isOpen = true;
	if (mem.GetInput()->bKeyPressed(VK_DELETE))
		isOpen = !isOpen;

	if (!isOpen) return;

	const auto ThemeColor = Unity::Color(0.0f, 0.478f, 0.8f, 1.0f);
	Unity::Rect windowRect = { 300, 300, 200, 200 };
	UI::DrawWindow(windowRect, Unity::Color(0.1f, 0.1f, 0.1f, 1.0f));

	static int CurrentTab = 0;
	Unity::Rect TabRect = { windowRect.x + 10, windowRect.y + 10, 80, 25 };

	if (UI::Button(TabRect, ThemeColor, L"Aimbot", 5))
		CurrentTab = 0;

	TabRect.x += TabRect.width + 10;

	if (UI::Button(TabRect, ThemeColor, L"Visuals", 5))
		CurrentTab = 1;

	float x = windowRect.x + 20;
	float y = windowRect.y + 50;

	if (CurrentTab == 0)
	{
		UI::Checkbox({ x, y + 0, 20, 20 }, ThemeColor, L"Aimbot", &Settings::Aimbot::bAimbot);
		UI::Checkbox({ x, y + 25, 20, 20 }, ThemeColor, L"Rapid Fire", &Settings::Aimbot::bRapidFire);
	}
	else if (CurrentTab == 1)
	{
		UI::Checkbox({ x, y + 0, 20, 20 }, ThemeColor, L"Skeleton", &Settings::Visuals::bSkeleton);
		UI::Checkbox({ x, y + 25, 20, 20 }, ThemeColor, L"Chams", &Settings::Visuals::bChams);
		UI::Checkbox({ x, y + 50, 20, 20 }, ThemeColor, L"Inventory", &Settings::Visuals::bInventory);
		UI::Checkbox({ x, y + 75, 20, 20 }, ThemeColor, L"Custom Sky", &Settings::Visuals::bCustomSky);
	}
}
