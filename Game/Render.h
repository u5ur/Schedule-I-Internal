#pragma once
#include <Memory.h>
#include <il2cpp.h>
#include <Hooks.h>
#include "Sdk.h"

inline Unity::Shader* Shader = nullptr;

namespace Render
{

	namespace UI
	{
		void DrawLine(Vector2 start, Vector2 end, Unity::Color color);
		void DrawFilledRect(Unity::Rect r, Unity::Color c, float round);
		bool Button(Unity::Rect r, Unity::Color col, Unity::String txt, float round);
		void SliderInt(Unity::Rect rect, Unity::String label, int* value, int min, int max);
		void DrawWindow(Unity::Rect pos, Unity::Color color);
		void Checkbox(Unity::Rect rect, Unity::Color color, Unity::String text, bool* value);
	}

	static ScheduleOne::NPCs::NPC* ClosestNPC = nullptr;

	void DrawSkeleton(ScheduleOne::AvatarFramework::Animation::AvatarAnimation* anim, Unity::Camera* cam, Unity::Color color);

	bool IsVisible(Unity::Camera* cam, Vector3 target_pos);

	void UpdateSky(uint64_t a1);

	void UpdateCamera(uint64_t a1);

	void UpdateWeapon(uint64_t a1);

	void UpdateAvatarWeapon(uint64_t a1);

	bool Init();

	void RenderNPCs();

	void RenderMenu();

	static void OnGUI(uint64_t ui)
	{
		static bool HasInit = false;

		if (!HasInit)
		{
			if (Init()) HasInit = true;
			return;
		}

		RenderNPCs();
		RenderMenu();

		return;
	}
}