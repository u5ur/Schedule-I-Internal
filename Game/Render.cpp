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

void Render::UpdateCamera(uint64_t a1)
{
	static Vector3 noclipLocation{};
	static bool wasNoClip = false;

	if (Hooks::OrigUpdate)
	{
		Hooks::OrigUpdate(a1);

		auto PlayerCamera = (ScheduleOne::PlayerScripts::PlayerCamera*)a1;
		if (!mem.IsValidPtr(PlayerCamera)) return;

		auto LocalPlayer = ScheduleOne::PlayerScripts::Player::GetLocalPlayer();
		if (!mem.IsValidPtr(LocalPlayer)) return;

		auto Character = LocalPlayer->GetCharacterController();
		if (!mem.IsValidPtr(Character)) return;

		auto Camera = PlayerCamera->GetCamera();
		if (!mem.IsValidPtr(Camera)) return;

		auto CameraTransform = Camera->GetTransform();
		if (!mem.IsValidPtr(CameraTransform)) return;

		auto Forward = CameraTransform->GetForward();
		auto Right = CameraTransform->GetRight();
		auto Up = Vector3{ 0.0f, 1.0f, 0.0f };

		bool& bNoClip = Settings::Exploit::bNoClip;

		if (bNoClip)
		{
			if (!wasNoClip)
				noclipLocation = CameraTransform->GetPosition(); // reliable init position

			float speed = 0.5f;
			if (mem.GetInput()->bIsKeyDown(VK_SHIFT)) speed *= 2.0f;

			if (mem.GetInput()->bIsKeyDown(0x57)) noclipLocation += Forward * speed;  // W
			if (mem.GetInput()->bIsKeyDown(0x53)) noclipLocation -= Forward * speed;  // S
			if (mem.GetInput()->bIsKeyDown(0x41)) noclipLocation -= Right * speed;    // A
			if (mem.GetInput()->bIsKeyDown(0x44)) noclipLocation += Right * speed;    // D
			if (mem.GetInput()->bIsKeyDown(VK_SPACE)) noclipLocation += Up * speed;
			if (mem.GetInput()->bIsKeyDown(VK_CONTROL)) noclipLocation -= Up * speed;

			Character->SetEnabled(false);
			Character->GetTransform()->SetPosition(noclipLocation);
		}
		else
		{
			if (wasNoClip)
			{
				Character->SetEnabled(true);
				Character->GetTransform()->SetPosition(noclipLocation);
			}
			else if (!LocalPlayer->GetSkateboard())
			{
				Character->SetEnabled(true);
			}
		}

		wasNoClip = bNoClip;

		if (Settings::Aimbot::bAimbot)
		{
			if (mem.IsValidPtr(ClosestNPC) &&
				mem.GetInput()->bIsKeyDown(VK_RBUTTON))
			{
				if (!Settings::Aimbot::bSilentAim) 
				{
					Vector3 Head3d = ClosestNPC->GetAvatar()->GetAvatarAnimation()->GetBonePos(0);
					if (helper::IsVisible(Camera, Head3d)) PlayerCamera->SetLookAt(Head3d, 0);
				}
				else
				{
					ClosestNPC->GetNPCMovement()->GetCapsuleCollider()->GetTransform()->SetPosition(Camera->Location + Forward * 4.0f);
				}
			}
		}
	}
}



void Render::UpdateMoney(uint64_t a1)
{
	if (Hooks::OrigUpdateMoney)
	{
		Hooks::OrigUpdateMoney(a1);

		auto MoneyManager = (ScheduleOne::Money::MoneyManager*)a1;
		if (!mem.IsValidPtr(MoneyManager)) return;

		if (Settings::Exploit::bAddBalance)
		{
			MoneyManager->AddBalance(10000);
		}
		else if (Settings::Exploit::bAddMoney)
		{
			MoneyManager->AddCash(10000);
		}
	}
}

void Render::UpdateWeapon(uint64_t a1)
{
	if (Hooks::OrigUpdateWeapon)
	{
		Hooks::OrigUpdateWeapon(a1);

		if (!Settings::Aimbot::bRapidFire) return;

		auto Weapon = (ScheduleOne::Equipping::Equippable_RangedWeapon*)a1;
		if (!mem.IsValidPtr(Weapon)) return;

		Weapon->GetAvatarEquippable()->GetAvatar()->SetChams(Shader, Unity::Color(1, 0, 1, 1));

		Weapon->SetAccuracy(1000);
		Weapon->SetRange(1000);
		Weapon->SetDamage(1000);
		Weapon->SetMaxSpread(0);
		Weapon->SetMinSpread(0);

		if (mem.GetInput()->bIsKeyDown(VK_LBUTTON))
		{
			Weapon->Fire();
		}

		return;
	}
}

void Render::UpdateSky(uint64_t a1)
{
	if (Hooks::OrigUpdateVisuals)
	{
		Hooks::OrigUpdateVisuals(a1);

		if (!Settings::Visuals::bCustomSky) return;

		auto TimeOfDayController = mem.Read<Funly::SkyStudio::TimeOfDayController*>(a1 + 0x30);
		if (!mem.IsValidPtr(TimeOfDayController)) return;

		auto SkyController = TimeOfDayController->GetSkyMaterialController();
		if (!mem.IsValidPtr(SkyController)) return;

#if USE_ASSETBUNDLE
		SkyController->SetSkyboxMaterial(Unity::Color(0.0f, 0.0f, 0.3f, 1.0f));
#else
		SkyController->SetSkyColor(Unity::Color(1.0f, 0.7f, 0.9f, 1.0f));
		SkyController->SetMiddleSkyColor(Unity::Color(0.9f, 0.4f, 0.7f, 1.0f));
		SkyController->SetHorizonSkyColor(Unity::Color(0.4f, 0.1f, 0.5f, 1.0f));
#endif

	}
}

void Render::UpdateBJ(uint64_t a1)
{
	if (Hooks::OrigUpdateBlackjack)
	{
		Hooks::OrigUpdateBlackjack(a1);

		if (!Settings::Exploit::bAlwaysWinBj) return;

		auto BJController = (ScheduleOne::Casino::BlackjackGameController*)a1;
		if (!mem.IsValidPtr(BJController)) return;

		Render::helper::SetPlayerCards(BJController);
	}
}

void Render::UpdateVehicle(uint64_t a1)
{
	if (Hooks::OrigUpdateVehicle)
	{
		Hooks::OrigUpdateVehicle(a1);

		if (!Settings::Exploit::bCarFly) return;

		auto Vehicle = (ScheduleOne::Vehicles::LandVehicle*)a1;

		Vehicle->SetOwned(true);

		if (!mem.IsValidPtr(Vehicle)) return;
		if (!Vehicle->LocalPlayerIsDriver()) return;

		auto rb = Vehicle->GetRigidBody();
		if (!mem.IsValidPtr(rb)) return;

		static float yaw = 0.0f;
		const float turnSpeed = 2.0f;

		if (mem.GetInput()->bIsKeyDown(0x41)) // A
			yaw -= turnSpeed;

		if (mem.GetInput()->bIsKeyDown(0x44)) // D
			yaw += turnSpeed;

		float rad = yaw * (3.14159265f / 180.0f);
		Vector4 rot = Vector4::FromEuler({ 0.0f, rad, 0.0f });
		rb->SetRotation(rot);

		Vector3 dir = { 0.0f, 0.0f, 0.0f };

		float speed = 20.0f;
		if (mem.GetInput()->bIsKeyDown(VK_SHIFT)) // Speed boost
			speed *= 2.0f;

		auto forward = rb->GetTransform()->GetForward();
		auto up = Vector3{ 0.0f, 1.0f, 0.0f };

		if (mem.GetInput()->bIsKeyDown(0x57)) dir += forward * speed;  // W
		if (mem.GetInput()->bIsKeyDown(0x53)) dir -= forward * speed;  // S
		if (mem.GetInput()->bIsKeyDown(VK_SPACE)) dir += up * speed;
		if (mem.GetInput()->bIsKeyDown(VK_CONTROL)) dir -= up * speed;

		rb->SetVelocity(dir);
	}
}

void Render::UpdateLocalPlayer()
{
	auto LocalPlayer = ScheduleOne::PlayerScripts::Player::GetLocalPlayer();
	if (!mem.IsValidPtr(LocalPlayer)) return;

	if (Settings::Exploit::bSkateboardFly)
	{
		auto Skateboard = LocalPlayer->GetSkateboard();
		if (!mem.IsValidPtr(Skateboard)) return;

		auto rb = Skateboard->GetRigidBody();
		if (!mem.IsValidPtr(rb)) return;

		static float yaw = 0.0f;
		const float turnSpeed = 2.0f;

		if (mem.GetInput()->bIsKeyDown(0x41)) // A
			yaw -= turnSpeed;

		if (mem.GetInput()->bIsKeyDown(0x44)) // D
			yaw += turnSpeed;

		float rad = yaw * (3.14159265f / 180.0f);
		Vector4 rot = Vector4::FromEuler({ 0.0f, rad, 0.0f });
		rb->SetRotation(rot);

		Vector3 dir = { 0.0f, 0.0f, 0.0f };

		float speed = 20.0f;
		if (mem.GetInput()->bIsKeyDown(VK_SHIFT)) // Speed boost
			speed *= 2.0f;

		auto forward = rb->GetTransform()->GetForward();
		auto up = Vector3{ 0.0f, 1.0f, 0.0f };

		if (mem.GetInput()->bIsKeyDown(0x57)) dir += forward * speed;  // W
		if (mem.GetInput()->bIsKeyDown(0x53)) dir -= forward * speed;  // S
		if (mem.GetInput()->bIsKeyDown(VK_SPACE)) dir += up * speed;
		if (mem.GetInput()->bIsKeyDown(VK_CONTROL)) dir -= up * speed;

		rb->SetVelocity(dir);
	}
}

void Render::RenderNPCs()
{
	auto NPCRegistry = ScheduleOne::NPCs::NPCManager::GetNPCRegistry();
	if (!mem.IsValidPtr(NPCRegistry)) return;

	auto Size = NPCRegistry->GetSize();
	if (Size <= 0 || Size >= 1000) return;

	float MinScreenDistanceNpc = std::numeric_limits<float>::max();
	float MinMeterDistanceNpc = std::numeric_limits<float>::max();

	ClosestNPC = nullptr;

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

		if (Settings::Visuals::bSkeleton) helper::DrawSkeleton(NPC->GetAvatar()->GetAvatarAnimation(), Camera, Unity::Color(1, 1, 1, 1));
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