#pragma once
#include <Memory.h>
#include <il2cpp.h>
#include <Hooks.h>
#include "Sdk.h"

static Unity::Shader* Shader = nullptr;

class Render
{
private:

	static void DrawLine(Vector2 start, Vector2 end, Unity::Color color)
	{
		Unity::GL::PushMatrix();
		if (Unity::Material::material->SetPass(0)) {
			Unity::GL::Begin(1);
			Unity::GL::GLColor(color);
			Unity::GL::Vertex({ start.x, start.y, 0 });
			Unity::GL::Vertex({ end.x, end.y, 0 });
			Unity::GL::End();
			Unity::GL::PopMatrix();
		}
	}

	static void DrawSkeleton(ScheduleOne::AvatarFramework::Animation::AvatarAnimation* anim, Unity::Camera* cam, Unity::Color color)
	{
		auto head_b = anim->GetBonePos(ScheduleOne::Bone::Head);
		auto spine4_b = anim->GetBonePos(ScheduleOne::Bone::Spine4);
		auto l_upperarm_b = anim->GetBonePos(ScheduleOne::Bone::L_UpperArm);
		auto l_forearm_b = anim->GetBonePos(ScheduleOne::Bone::L_Forearm);
		auto l_hand_b = anim->GetBonePos(ScheduleOne::Bone::L_Hand);
		auto r_upperarm_b = anim->GetBonePos(ScheduleOne::Bone::R_UpperArm);
		auto r_forearm_b = anim->GetBonePos(ScheduleOne::Bone::R_Forearm);
		auto r_hand_b = anim->GetBonePos(ScheduleOne::Bone::R_Hand);
		auto pelvis_b = anim->GetBonePos(ScheduleOne::Bone::Pelvis);
		auto l_hip_b = anim->GetBonePos(ScheduleOne::Bone::L_Hip);
		auto l_knee_b = anim->GetBonePos(ScheduleOne::Bone::L_Knee);
		auto l_foot_b = anim->GetBonePos(ScheduleOne::Bone::L_Foot);
		auto r_hip_b = anim->GetBonePos(ScheduleOne::Bone::R_Hip);
		auto r_knee_b = anim->GetBonePos(ScheduleOne::Bone::R_Knee);
		auto r_foot_b = anim->GetBonePos(ScheduleOne::Bone::R_Foot);
		auto r_toe_b = anim->GetBonePos(ScheduleOne::Bone::R_Toe);
		auto l_toe_b = anim->GetBonePos(ScheduleOne::Bone::L_Toe);

		Vector2 head = cam->WorldToScreen(head_b);
		Vector2 spine = cam->WorldToScreen(spine4_b);
		Vector2 l_upperarm = cam->WorldToScreen(l_upperarm_b);
		Vector2 l_forearm = cam->WorldToScreen(l_forearm_b);
		Vector2 l_hand = cam->WorldToScreen(l_hand_b);
		Vector2 r_upperarm = cam->WorldToScreen(r_upperarm_b);
		Vector2 r_forearm = cam->WorldToScreen(r_forearm_b);
		Vector2 r_hand = cam->WorldToScreen(r_hand_b);
		Vector2 pelvis = cam->WorldToScreen(pelvis_b);
		Vector2 l_hip = cam->WorldToScreen(l_hip_b);
		Vector2 l_knee = cam->WorldToScreen(l_knee_b);
		Vector2 l_foot = cam->WorldToScreen(l_foot_b);
		Vector2 r_hip = cam->WorldToScreen(r_hip_b);
		Vector2 r_knee = cam->WorldToScreen(r_knee_b);
		Vector2 r_foot = cam->WorldToScreen(r_foot_b);
		Vector2 r_toe = cam->WorldToScreen(r_toe_b);
		Vector2 l_toe = cam->WorldToScreen(l_toe_b);

		DrawLine(head, spine, color);
		DrawLine(spine, l_upperarm, color);
		DrawLine(l_upperarm, l_forearm, color);
		DrawLine(l_forearm, l_hand, color);
		DrawLine(spine, r_upperarm, color);
		DrawLine(r_upperarm, r_forearm, color);
		DrawLine(r_forearm, r_hand, color);
		DrawLine(spine, pelvis, color);
		DrawLine(pelvis, l_hip, color);
		DrawLine(l_hip, l_knee, color);
		DrawLine(l_knee, l_foot, color);
		DrawLine(pelvis, r_hip, color);
		DrawLine(r_hip, r_knee, color);
		DrawLine(r_knee, r_foot, color);
		DrawLine(r_foot, r_toe, color);
		DrawLine(l_foot, l_toe, color);
	}

public:
	
	static void UpdateSky(uintptr_t* a1)
	{
		if (Hooks::OrigUpdateVisuals)
		{
			Hooks::OrigUpdateVisuals(a1);

			auto TimeOfDayController = Funly::SkyStudio::TimeOfDayController::GetTimeOfDayController();
			if (!mem.IsValidPtr(TimeOfDayController)) return;

			auto SkyController =TimeOfDayController->GetSkyMaterialController();
			if (!mem.IsValidPtr(SkyController)) return;

			SkyController->SetSkyColor(Unity::Color(1.0f, 0.7f, 0.9f, 1.0f));
			SkyController->SetMiddleSkyColor(Unity::Color(0.9f, 0.4f, 0.7f, 1.0f));
			SkyController->SetHorizonSkyColor(Unity::Color(0.4f, 0.1f, 0.5f, 1.0f));
		}
	}

	static void OnGUI(uintptr_t* ui)
	{
		static bool HasInit = false;

		auto currenEvent = Unity::Event::GetCurrent();
		auto eventType = currenEvent->GetType();
		if (eventType != Unity::EventType::Repaint) return;

		if (!HasInit)
		{
			if (Init()) HasInit = true;
		}

		auto Camera = Unity::Camera::GetMain();
		if (!mem.IsValidPtr(Camera)) return;

		Camera->GetViewMatrix();
		Camera->GetLocation();

		auto NPCRegistry = ScheduleOne::NPCs::NPCManager::GetNPCRegistry();
		if (!mem.IsValidPtr(NPCRegistry)) return;

		auto Size = NPCRegistry->GetSize();
		if (Size <= 0 || Size >= 1000) return;

		for (int i = 0; i < Size; i++)
		{
			auto NPC = NPCRegistry->GetValue(i);
			if (!mem.IsValidPtr(NPC)) continue;

			if (!NPC->IsVisible()) continue;

			Vector3 Head3d = NPC->GetAvatar()->GetAvatarAnimation()->GetBonePos(0);
			if (Head3d.Empty()) continue;

			Vector2 Head2d = Camera->WorldToScreen(Head3d);
			if (Head2d.Empty()) continue;

			float Distance = Camera->Location.Distance(Head3d);
			if (Distance >= 300 || Distance <= 0) continue;

			NPC->GetAvatar()->SetChams(Shader, Unity::Color{ 1, 0, 0, 1 });

			DrawSkeleton(NPC->GetAvatar()->GetAvatarAnimation(), Camera, Unity::Color(1, 1, 1, 1));
		}

		return;
	}

	static bool Init()
	{
		auto skin = Unity::GUI::GetSkin();
		if (!mem.IsValidPtr(skin)) return false;

		Unity::GUISkin::label = mem.Read<Unity::GUIStyle*>(skin + 0x38);
		if (!mem.IsValidPtr(Unity::GUISkin::label)) return false;

		Shader = Unity::Shader::Find((L"Hidden/Internal-Colored"));
		Unity::Material::material = (Unity::Material*)il2cpp::NewObject(il2cpp::InitClass(("Material"), ("UnityEngine")));
		Unity::Material::CreateWithShader(Unity::Material::material, Shader);
		Unity::Material::material->SetInt((L"_SrcBlend"), 5);
		Unity::Material::material->SetInt((L"_DstBlend"), 10);
		Unity::Material::material->SetInt((L"_Cull"), 0);
		Unity::Material::material->SetInt((L"_ZWrite"), 0);
		Unity::GameObject::DontDestroyOnLoad(Unity::Material::material);

		return true;
	}
};

static Render* render = new Render;