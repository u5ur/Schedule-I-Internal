#pragma once
#include "Unity/Unity.h"

namespace Funly
{
	namespace SkyStudio
	{

		class SkyMaterialController
		{
		public:

			// No Static Fields

			void SetSkyColor(Unity::Color color)
			{
				if (!this) return;
				auto set_SkyColor = reinterpret_cast<void(*)(Funly::SkyStudio::SkyMaterialController*, Unity::Color)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("SkyMaterialController", "set_SkyColor", 0, "", "Funly.SkyStudio")));
				set_SkyColor(this, color);
			}

			void SetMiddleSkyColor(Unity::Color color)
			{
				if (!this) return;
				auto set_SkyMiddleColor = reinterpret_cast<void(*)(Funly::SkyStudio::SkyMaterialController*, Unity::Color)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("SkyMaterialController", "set_SkyMiddleColor", 0, "", "Funly.SkyStudio")));
				set_SkyMiddleColor(this, color);
			}

			void SetHorizonSkyColor(Unity::Color color)
			{
				if (!this) return;
				auto set_HorizonColor = reinterpret_cast<void(*)(Funly::SkyStudio::SkyMaterialController*, Unity::Color)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("SkyMaterialController", "set_HorizonColor", 0, "", "Funly.SkyStudio")));
				set_HorizonColor(this, color);
			}
		};


		class TimeOfDayController
		{
		public:

			 // Static Fields //
			//------------------//

			static TimeOfDayController* GetTimeOfDayController()
			{
				uint64_t TypeInfo = mem.Read<uint64_t>(mem.GameAssembly + 58528016);
				if (!TypeInfo) return nullptr;

				uint64_t StaticFields = mem.Read<uint64_t>(TypeInfo + 0xB8);
				if (!StaticFields) return nullptr;

				return mem.Read<TimeOfDayController*>(StaticFields + 0x0);
			}

			 // Fields //
			//-----------//

			SkyMaterialController* GetSkyMaterialController()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<SkyMaterialController*>(this + 0x30);
			}
		};
	}
}

namespace ScheduleOne
{
	namespace AvatarFramework
	{
		namespace Animation
		{
			class AvatarAnimation
			{
			public:

				// No Static Fields

				Unity::List<Unity::Transform*>* GetTransforms()
				{
					if (!mem.IsValidPtr(this)) return nullptr;
					return mem.Read<Unity::List<Unity::Transform*>*>(this + 0x48);
				}

				Vector3 GetBonePos(int idx)
				{
					if (!mem.IsValidPtr(this)) return {};

					auto BoneTransforms = GetTransforms();
					if (!mem.IsValidPtr(BoneTransforms)) return {};

					auto Transform = BoneTransforms->Get(idx);
					if (!mem.IsValidPtr(Transform)) return {};

					return Transform->GetPosition();
				}
			};
		}

		class Avatar
		{
		public:

			// No Static Fields

			AvatarFramework::Animation::AvatarAnimation* GetAvatarAnimation()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<AvatarFramework::Animation::AvatarAnimation*>(this + 0x20);
			}

			Unity::List<Unity::Renderer*>* GetRenderers()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Unity::List<Unity::Renderer*>*>(this + 0x30);
			}

			void SetChams(Unity::Shader* shader, Unity::Color color)
			{
				if (!mem.IsValidPtr(this)) return;

				auto Renderers = GetRenderers();
				if (!mem.IsValidPtr(Renderers)) return;

				auto Size = Renderers->GetSize();
				if (Size <= 0 || Size >= 100) return;

				for (int i = 0; i < Size; i++)
				{
					auto Renderer = Renderers->Get(i);
					auto material = Renderer->GetMaterial();
					material->SetShader(shader);
					material->SetColor((L"_Color"), color);
					material->SetInt((L"_ZTest"), 8);
				}
			}
		};
	}

	namespace ItemFramework
	{
		class ItemDefinition
		{
		public:

			Unity::String* GetName()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Unity::String*>(this + 0x18);
			}

			Unity::Sprite* GetSprite()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Unity::Sprite*>(this + 0x30);
			}
		};

		class ItemInstance
		{
		public:
			
			ItemDefinition* GetItemDefinition()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<ItemDefinition*>(this + 0x10);
			}
		};

		class ItemSlot
		{
		public:

			ItemInstance* GetItemInstance()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<ItemInstance*>(this + 0x10);
			}
		};
	}


	namespace NPCs
	{

		class NPCInventory
		{
		public:

			Unity::List<ItemFramework::ItemSlot*>* GetItemSlots()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Unity::List<ItemFramework::ItemSlot*>*>(this + 0x158);
			}
		};


		class NPC
		{
		public:

			AvatarFramework::Avatar* GetAvatar()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<AvatarFramework::Avatar*>(this + 0x180);
			}

			Unity::String* GetFirstName()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Unity::String*>(this + 0x118);
			}

			bool HasLastName()
			{
				if (!mem.IsValidPtr(this)) return false;
				return mem.Read<bool>(this + 0x120);
			}

			Unity::String* GetLastName()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Unity::String*>(this + 0x128);
			}

			bool IsVisible()
			{
				if (!mem.IsValidPtr(this)) return false;
				return mem.Read<bool>(this + 0x270);
			}

			NPCInventory* GetNPCInventory()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<NPCInventory*>(this + 0x1A8);
			}
		};

		class NPCManager
		{
		public:

			  // Static Fields //
			//------------------//

			static Unity::List<NPC*>* GetNPCRegistry()
			{
				uint64_t TypeInfo = mem.Read<uint64_t>(mem.GameAssembly + 58232248);
				if (!TypeInfo) return nullptr;

				uint64_t StaticFields = mem.Read<uint64_t>(TypeInfo + 0xb8);
				if (!StaticFields) return nullptr;

				return mem.Read<Unity::List<NPC*>*>(StaticFields + 0x0);
			}
		};
	}

	namespace PlayerScripts
	{
		class Player
		{
		public:

			// Static Fields //
		   //------------------//

			static Player* GetLocalPlayer()
			{
				uint64_t TypeInfo = mem.Read<uint64_t>(mem.GameAssembly + 58298816);
				if (!TypeInfo) return nullptr;

				uint64_t StaticFields = mem.Read<uint64_t>(TypeInfo + 0xb8);
				if (!StaticFields) return nullptr;

				return mem.Read<Player*>(StaticFields + 0x18);
			}

			static Unity::List<Player*>* GetPlayerList()
			{
				uint64_t TypeInfo = mem.Read<uint64_t>(mem.GameAssembly + 58298816);
				if (!TypeInfo) return nullptr;

				uint64_t StaticFields = mem.Read<uint64_t>(TypeInfo + 0xb8);
				if (!StaticFields) return nullptr;

				return mem.Read<Unity::List<Player*>*>(StaticFields + 0x18);
			}

			  // Fields //
			//-----------//

			AvatarFramework::Avatar* GetAvatar()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<AvatarFramework::Avatar*>(this + 0x128);
			}

			AvatarFramework::Animation::AvatarAnimation* GetAvatarAnimation()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<AvatarFramework::Animation::AvatarAnimation*>(this + 0x130);
			}

			Unity::String* GetPlayerName()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Unity::String*>(this + 0x1F0);
			}
		};
	}

	enum Bone : int
	{
		Head = 0,
		Pelvis = 1,
		R_UpperArm = 2,
		R_Foot = 3,
		R_Forearm = 4,
		R_Hand = 5,
		R_Toe = 16,
		R_Hip = 17,
		R_Knee = 14,
		L_UpperArm = 19,
		L_Foot = 20,
		L_Forearm = 21,
		L_Hand = 22,
		L_Knee = 31,
		L_Toe = 33,
		L_Hip = 34,
		Spine4 = 37
	};
}
