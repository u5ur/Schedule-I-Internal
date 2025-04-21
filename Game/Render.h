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

		void DrawFilledRect(Unity::Rect rect, Unity::Color color, float round);

		void DrawString(Unity::Rect pos, Unity::String text, Unity::Color clr, bool centered = false, float font_size = 12);

		void DrawRect(Unity::Rect rect, Unity::Color color, float round = 1, float thickness = 1);

		bool Button(Unity::Rect rect, Unity::Color color, Unity::String text, float round);

		void SliderInt(Unity::Rect rect, Unity::String text, int* value, int min, int max);

		void DrawWindow(Unity::Rect pos, Unity::Color color);

		void Checkbox(Unity::Rect rect, Unity::Color color, Unity::String text, bool* value);
	}

	static ScheduleOne::NPCs::NPC* ClosestNPC = nullptr;

	namespace helper
	{
		void DrawSkeleton(ScheduleOne::AvatarFramework::Animation::AvatarAnimation* anim, Unity::Camera* cam, Unity::Color color);

		bool IsVisible(Unity::Camera* cam, Vector3 target_pos);

		void UnlockAllDoors();

		void SetPlayerCards(ScheduleOne::Casino::BlackjackGameController* bj);

		void SpawnVehicle();

		void DrawAvatarBox(Vector2 head2d, Vector2 root2d, Unity::Color color);
	}

	inline bool IsPaused = false;

	void UpdateSky(uint64_t a1);

	void UpdateCamera(uint64_t a1);

	void UpdateWeapon(uint64_t a1);

	void UpdateMoney(uint64_t a1);

	void UpdateBJ(uint64_t a1);

	void UpdateVehicle(uint64_t a1);

	void UpdateLocalPlayer();

	bool Init();

	void RenderNPCs();

	void RenderMenu();

	static Unity::Camera* Camera;

	static void OnGUI(uint64_t ui)
	{
		static bool HasInit = false;

		if (!HasInit)
		{
			if (Init()) HasInit = true;
			return;
		}

		Camera = Unity::Camera::GetMain();
		if (!mem.IsValidPtr(Camera)) return;

		Camera->GetViewMatrix();
		Camera->GetLocation();

		RenderNPCs();
		UpdateLocalPlayer();
		RenderMenu();

		return;
	}
}