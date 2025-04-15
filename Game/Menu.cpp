#include "Render.h"

void Render::RenderMenu()
{
	static bool isOpen = true;

	if (mem.GetInput()->bKeyPressed(VK_DELETE))
		isOpen = !isOpen;

	if (!isOpen) return;

	const auto ThemeColor = Unity::Color(0.0f, 0.478f, 0.8f, 1.0f);

	Unity::Rect windowRect = { 300, 300, 300, 200 };
	UI::DrawWindow(windowRect, Unity::Color(0.1f, 0.1f, 0.1f, 1.0f));

	float x = windowRect.x + 20;
	float y = windowRect.y + 40;

	UI::Checkbox({ x, y + 0, 20, 20 }, ThemeColor, L"Skeleton", &Settings::Visuals::bSkeleton);
	UI::Checkbox({ x, y + 25, 20, 20 }, ThemeColor, L"Chams", &Settings::Visuals::bChams);
	UI::Checkbox({ x, y + 50, 20, 20 }, ThemeColor, L"Custom Sky", &Settings::Visuals::bCustomSky);
}