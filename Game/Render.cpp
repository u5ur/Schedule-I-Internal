#include "Render.h"

bool Render::Init()
{
	auto skin = Unity::GUI::GetSkin();
	if (!mem.IsValidPtr(skin)) return false;

	Unity::GUISkin::label = mem.Read<Unity::GUIStyle*>(skin + 0x38);
	if (!mem.IsValidPtr(Unity::GUISkin::label)) return false;

	if (!Shader)
		Shader = Unity::Shader::Find((L"Hidden/Internal-Colored"));

#if USE_ASSETBUNDLE
	Unity::Bundles::Init();
#endif

	Unity::Material::material = (Unity::Material*)il2cpp::NewObject(il2cpp::InitClass(("Material"), ("UnityEngine")));
	Unity::Material::CreateWithShader(Unity::Material::material, Shader);
	Unity::Material::material->SetInt((L"_SrcBlend"), 5);
	Unity::Material::material->SetInt((L"_DstBlend"), 10);
	Unity::Material::material->SetInt((L"_Cull"), 0);
	Unity::Material::material->SetInt((L"_ZWrite"), 0);
	Unity::GameObject::DontDestroyOnLoad(Unity::Material::material);

	return true;
}

void Render::UpdateSky(uintptr_t* a1)
{
	if (Hooks::OrigUpdateVisuals)
	{
		Hooks::OrigUpdateVisuals(a1);

		if (!Settings::Visuals::bCustomSky) return;

		auto TimeOfDayController = Funly::SkyStudio::TimeOfDayController::GetTimeOfDayController();
		if (!mem.IsValidPtr(TimeOfDayController)) return;

		auto SkyController = TimeOfDayController->GetSkyMaterialController();
		if (!mem.IsValidPtr(SkyController)) return;

#if USE_ASSETBUNDLE == true
		SkyController->SetSkyboxMaterial(Unity::Color(0.0f, 0.0f, 0.3f, 1.0f));
#else
		SkyController->SetSkyColor(Unity::Color(1.0f, 0.7f, 0.9f, 1.0f));
		SkyController->SetMiddleSkyColor(Unity::Color(0.9f, 0.4f, 0.7f, 1.0f));
		SkyController->SetHorizonSkyColor(Unity::Color(0.4f, 0.1f, 0.5f, 1.0f));
#endif

	}
}

void Render::RenderNPCs()
{
	auto Camera = Unity::Camera::GetMain();
	if (!mem.IsValidPtr(Camera)) return;

	Camera->GetViewMatrix();
	Camera->GetLocation();

	auto NPCRegistry = ScheduleOne::NPCs::NPCManager::GetNPCRegistry();
	if (!mem.IsValidPtr(NPCRegistry)) return;

	auto Size = NPCRegistry->GetSize();
	if (Size <= 0 || Size >= 1000) return;

	float MinScreenDistanceNpc = std::numeric_limits<float>::max();
	float MinMeterDistanceNpc = std::numeric_limits<float>::max();
	ScheduleOne::NPCs::NPC* ClosestNPC = nullptr;

	for (int i = 0; i < Size; i++)
	{
		auto NPC = NPCRegistry->Get(i);
		if (!mem.IsValidPtr(NPC)) continue;

		if (!NPC->IsVisible()) continue;

		Vector3 Head3d = NPC->GetAvatar()->GetAvatarAnimation()->GetBonePos(0);
		if (Head3d.Empty()) continue;

		Vector2 Head2d = Camera->WorldToScreen(Head3d);
		if (Head2d.Empty()) continue;

		float Health = NPC->GetNPCHealth()->GetHealth();
		if (Health <= 0) continue;

		float Distance = Camera->Location.Distance(Head3d);
		if (Distance >= 300 || Distance <= 0) continue;

		if (!NPC->GetRelationData()->IsUnlocked())
		{
			NPC->GetRelationData()->SetUnlocked();
		}

		float dx = Head2d.x - (1920 / 2.0f);
		float dy = Head2d.y - (1080 / 2.0f);
		float ScreenDist = std::sqrt(dx * dx + dy * dy);

		if (ScreenDist <= 100 &&
			ScreenDist < MinScreenDistanceNpc)
		{
			MinScreenDistanceNpc = ScreenDist;

			if (Distance < MinMeterDistanceNpc)
			{
				MinMeterDistanceNpc = Distance;
				ClosestNPC = NPC;
			}
		}

		if (Settings::Visuals::bChams) NPC->GetAvatar()->SetChams(Shader, Unity::Color{ 1, 0, 0, 1 });

		if (Settings::Visuals::bSkeleton) DrawSkeleton(NPC->GetAvatar()->GetAvatarAnimation(), Camera, Unity::Color(1, 1, 1, 1));
	}

	if (mem.IsValidPtr(ClosestNPC) && 
		Settings::Visuals::bInventory)
	{
		auto ItemSlots = ClosestNPC->GetNPCInventory()->GetItemSlots();
		if (mem.IsValidPtr(ItemSlots))
		{
			float startX = Unity::Screen::GetWidth() / 2;
			float startY = 30.0f;
			float spacing = 10.0f;

			auto Size = ItemSlots->GetSize();

			for (int i = 0; i < Size; i++)
			{
				auto ItemSlot = ItemSlots->Get(i);
				if (!mem.IsValidPtr(ItemSlot)) continue;

				auto Sprite = ItemSlot->GetItemInstance()->GetItemDefinition()->GetSprite();
				if (!mem.IsValidPtr(Sprite)) continue;

				auto Texture = Sprite->GetTexture();
				if (!mem.IsValidPtr(Texture)) continue;

				auto Rect = Sprite->GetRect();

				Unity::Rect DrawRect;
				DrawRect.x = startX;
				DrawRect.y = startY;
				DrawRect.width = Rect.width / 7;
				DrawRect.height = Rect.height / 7;

				Unity::GUI::DrawTexture(DrawRect, Texture);

				startX += (Rect.width / 10) + spacing;
			}
		}
	}
}