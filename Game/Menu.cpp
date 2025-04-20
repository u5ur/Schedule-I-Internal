#include "Render.h"

void Render::RenderMenu()
{
	static bool isOpen = true;
	if (mem.GetInput()->bIsKeyDown(VK_DELETE))
		isOpen = !isOpen;

	if (!isOpen) return;

	const auto ThemeColor = Unity::Color(0.0f, 0.478f, 0.8f, 1.0f);
	Unity::Rect windowRect = { 300, 300, 300, 400 };
	UI::DrawWindow(windowRect, Unity::Color(0.1f, 0.1f, 0.1f, 1.0f));

	static int CurrentTab = 0;
	Unity::Rect TabRect = { windowRect.x + 10, windowRect.y + 10, 80, 25 };

	if (UI::Button(TabRect, ThemeColor, L"Aimbot", 5))
		CurrentTab = 0;

	TabRect.x += TabRect.width + 10;

	if (UI::Button(TabRect, ThemeColor, L"Visuals", 5))
		CurrentTab = 1;

	TabRect.x += TabRect.width + 10;

	if (UI::Button(TabRect, ThemeColor, L"Exploits", 5))
		CurrentTab = 2;

	float x = windowRect.x + 20;
	float y = windowRect.y + 50;

	const float sliderWidth = 150;
	const float sliderHeight = 20;
	const float spacing = 6;

	if (CurrentTab == 0)
	{
		UI::Checkbox({ x, y, 20, 20 }, ThemeColor, L"Aimbot", &Settings::Aimbot::bAimbot);
		y += 25;
		UI::Checkbox({ x, y, 20, 20 }, ThemeColor, L"Rapid Fire", &Settings::Aimbot::bRapidFire);
	}
	else if (CurrentTab == 1)
	{
		UI::Checkbox({ x, y, 20, 20 }, ThemeColor, L"Skeleton", &Settings::Visuals::bSkeleton);
		y += 25;
		UI::Checkbox({ x, y, 20, 20 }, ThemeColor, L"Chams", &Settings::Visuals::bChams);
		y += 25;
		UI::Checkbox({ x, y, 20, 20 }, ThemeColor, L"Inventory", &Settings::Visuals::bInventory);
		y += 25;
		UI::Checkbox({ x, y, 20, 20 }, ThemeColor, L"Custom Sky", &Settings::Visuals::bCustomSky);
	}
	else if (CurrentTab == 2)
	{
		UI::Checkbox({ x, y, 20, 20 }, ThemeColor, L"No Clip", &Settings::Exploit::bNoClip);
		y += 25;

		UI::Checkbox({ x, y, 20, 20 }, ThemeColor, L"Skateboard Fly", &Settings::Exploit::bSkateboardFly);
		y += 25;

		UI::Checkbox({ x, y, 20, 20 }, ThemeColor, L"Car Fly", &Settings::Exploit::bCarFly);
		y += 25;

		UI::Checkbox({ x, y, 20, 20 }, ThemeColor, L"Always Win Blackjack", &Settings::Exploit::bAlwaysWinBj);
		y += 25;

		Settings::Exploit::bAddMoney = UI::Button({ x, y, 20, 20 }, ThemeColor, L"Add $10000 Cash", 5);
		y += 25;

		Settings::Exploit::bAddBalance = UI::Button({ x, y, 20, 20 }, ThemeColor, L"Add $10000 Balance", 5);
		y += 25;

		if (UI::Button({ x, y, 20, 20 }, ThemeColor, L"Unlock All Doors", 5))
		{
			helper::UnlockAllDoors();
		}
		y += 25;

		if (UI::Button({ x, y, 20, 20 }, ThemeColor, L"Spawn Car", 5))
		{
			helper::SpawnVehicle();
		}
		y += 25;

		UI::SliderInt({ x, y, sliderWidth, sliderHeight }, L"Jump Multi", &Settings::Exploit::JumpMulti, 1, 10);
		if (UI::Button({ x + sliderWidth + spacing + 90, y, 0, 0 }, ThemeColor, L"Set", 5)) {
			ScheduleOne::PlayerScripts::PlayerMovement::SetJumpMultiplier(Settings::Exploit::JumpMulti);
		}
		y += sliderHeight + spacing;

		UI::SliderInt({ x, y, sliderWidth, sliderHeight }, L"Speed Multi", &Settings::Exploit::SpeedMulti, 1, 10);
		if (UI::Button({ x + sliderWidth + spacing + 90, y, 0, 0 }, ThemeColor, L"Set", 5)) {
			ScheduleOne::PlayerScripts::PlayerMovement::SetSprintMultiplier(Settings::Exploit::SpeedMulti);
		}
	}
}
