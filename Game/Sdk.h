#pragma once
#include "Settings.h"
#include "Unity/Unity.h"

namespace ScheduleOne 
{
	namespace PlayerScripts
	{
		class PlayerCamera;
	}

	namespace Equipping
	{
		class Equippable_RangedWeapon;
	}

	namespace Money
	{
		class MoneyManager;
	}

	namespace Casino
	{
		class RTBGameController;
		class SlotReel;
		class SlotMachine;
		class PlayingCard;
		class CardSprite;
		class CardController;
	}
}

namespace Sdk
{
	namespace Methods
	{
		inline auto Fire = reinterpret_cast<void(*)(ScheduleOne::Equipping::Equippable_RangedWeapon*)>(0);
		inline auto LookAt = reinterpret_cast<void(*)(ScheduleOne::PlayerScripts::PlayerCamera*, Vector3, float)>(0);
		inline auto ChangeCashBalance = reinterpret_cast<void(*)(ScheduleOne::Money::MoneyManager*, float, bool, bool)>(0);
		inline auto ReceiveOnlineTransaction = reinterpret_cast<void(*)(ScheduleOne::Money::MoneyManager*, Unity::String*, float, float, Unity::String*)>(0);
		inline auto set_CurrentSymbol = reinterpret_cast<void(*)(ScheduleOne::Casino::SlotReel*, uint32_t)>(0);
		inline auto GetCardSprite = reinterpret_cast<ScheduleOne::Casino::CardSprite*(*)(ScheduleOne::Casino::PlayingCard*, uint32_t, uint32_t)>(0);
		inline auto get_Suit = reinterpret_cast<uint32_t(*)(ScheduleOne::Casino::PlayingCard*)>(0);
		inline auto get_Value = reinterpret_cast<uint32_t(*)(ScheduleOne::Casino::PlayingCard*)>(0);
		inline auto set_IsFaceUp = reinterpret_cast<void(*)(ScheduleOne::Casino::PlayingCard*, bool)>(0);
		inline auto set_Suit = reinterpret_cast<void(*)(ScheduleOne::Casino::PlayingCard*, uint32_t)>(0);
		inline auto set_Value = reinterpret_cast<void(*)(ScheduleOne::Casino::PlayingCard*, uint32_t)>(0);
		inline auto SendCardFaceUp = reinterpret_cast<void(*)(ScheduleOne::Casino::CardController*, Unity::String*, bool)>(0);
		inline auto SetCardValue = reinterpret_cast<void(*)(ScheduleOne::Casino::CardController*, Unity::String*, uint32_t, uint32_t)>(0);
		inline auto SendCardValue = reinterpret_cast<void(*)(ScheduleOne::Casino::CardController*, Unity::String*, uint32_t, uint32_t)>(0);
		inline auto GetQuestionsAndAnswers = reinterpret_cast<uint32_t(*)(ScheduleOne::Casino::RTBGameController*, uint32_t, Unity::String*&, Unity::Array<Unity::String*>*&)>(0);

		static void Init()
		{
			Fire = reinterpret_cast<void(*)(ScheduleOne::Equipping::Equippable_RangedWeapon*)>(mem.GameAssembly + 0x84A270);
			LookAt = reinterpret_cast<void(*)(ScheduleOne::PlayerScripts::PlayerCamera*, Vector3, float)>(mem.GameAssembly + 0x6A6880);
			ChangeCashBalance = reinterpret_cast<void(*)(ScheduleOne::Money::MoneyManager*, float, bool, bool)>(mem.GameAssembly + 0x945C30);
			ReceiveOnlineTransaction = reinterpret_cast<void(*)(ScheduleOne::Money::MoneyManager*, Unity::String*, float, float, Unity::String*)>(mem.GameAssembly + 0x9478D0);
			set_CurrentSymbol = reinterpret_cast<void(*)(ScheduleOne::Casino::SlotReel*, uint32_t)>(mem.GameAssembly + 0x460AA0);
			GetCardSprite = reinterpret_cast<ScheduleOne::Casino::CardSprite*(*)(ScheduleOne::Casino::PlayingCard*, uint32_t, uint32_t)>(mem.GameAssembly + 0x780590);
			get_Suit = reinterpret_cast<uint32_t(*)(ScheduleOne::Casino::PlayingCard*)>(mem.GameAssembly + 0x4608D0);
			get_Value = reinterpret_cast<uint32_t(*)(ScheduleOne::Casino::PlayingCard*)>(mem.GameAssembly + 0x460A60);
			GetQuestionsAndAnswers = reinterpret_cast<uint32_t(*)(ScheduleOne::Casino::RTBGameController*, uint32_t, Unity::String*&, Unity::Array<Unity::String*>*&)>(mem.GameAssembly + 0x781E20);
			set_IsFaceUp = reinterpret_cast<void(*)(ScheduleOne::Casino::PlayingCard*, bool)>(mem.GameAssembly + 0x49C3D0);
			SendCardFaceUp = reinterpret_cast<void(*)(ScheduleOne::Casino::CardController*, Unity::String*, bool)>(mem.GameAssembly + 0x75F630);
			SetCardValue = reinterpret_cast<void(*)(ScheduleOne::Casino::CardController*, Unity::String*, uint32_t, uint32_t)>(mem.GameAssembly + 0x75E190);
			set_Suit = reinterpret_cast<void(*)(ScheduleOne::Casino::PlayingCard*, uint32_t)>(mem.GameAssembly + 0x460AA0);
			set_Value = reinterpret_cast<void(*)(ScheduleOne::Casino::PlayingCard*, uint32_t)>(mem.GameAssembly + 0x460B20);
			SendCardValue = reinterpret_cast<void(*)(ScheduleOne::Casino::CardController*, Unity::String*, uint32_t, uint32_t)>(mem.GameAssembly + 0x75F880);

		}
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

				Unity::Array<Unity::Transform*>* GetTransforms()
				{
					if (!mem.IsValidPtr(this)) return nullptr;
					return mem.Read<Unity::Array<Unity::Transform*>*>(this + 0x48);
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

			Unity::Array<Unity::Renderer*>* GetRenderers()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Unity::Array<Unity::Renderer*>*>(this + 0x30);
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

				#if USE_ASSETBUNDLE
					Unity::Bundles::HologramMaterial->SetShader(Unity::Bundles::HologramShader);
					Unity::Bundles::HologramMaterial->SetColor(L"_Color", { 1, 0, 0, 1 });
					Unity::Bundles::HologramMaterial->SetInt(L"_ZTest", 8);
					Renderer->SetMaterial(Unity::Bundles::HologramMaterial);
				#else
					material->SetShader(shader);
					material->SetColor(L"_Color", color);
					material->SetInt(L"_ZTest", 8);
				#endif

				}
			}
		};
	}

	namespace Casino
	{
		static enum ECardSuit : uint32_t
		{
			Spades = 0,
			Hearts = 1,
			Diamonds = 2,
			Clubs = 3,
		};

		static enum ECardValue : uint32_t
		{
			Blank = 0,
			Ace = 1,
			Two = 2,
			Three = 3,
			Four = 4,
			Five = 5,
			Six = 6,
			Seven = 7,
			Eight = 8,
			Nine = 9,
			Ten = 10,
			Jack = 11,
			Queen = 12,
			King = 13,
		};

		static class CardSprite
		{
		public:

			Unity::Sprite* GetSprite()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Unity::Sprite*>(this + 0x18);
			}

			ECardSuit GetSuit()
			{
				if (!mem.IsValidPtr(this)) return ECardSuit::Spades;
				return mem.Read<ECardSuit>(this + 0x10);
			}

			ECardValue GetValue()
			{
				if (!mem.IsValidPtr(this)) return ECardValue::Blank;
				return mem.Read<ECardValue>(this + 0x14);
			}
		};

		class CardController
		{
		public:

			void SendCardFaceUp(Unity::String* cardid, bool face_up)
			{
				if (!mem.IsValidPtr(this)) return;
				Sdk::Methods::SendCardFaceUp(this, cardid, face_up);
			}

			void SetCardValue(Unity::String* card_id, ECardSuit suit, ECardValue value)
			{
				if (!mem.IsValidPtr(this)) return;
				Sdk::Methods::SetCardValue(this, card_id, suit, value);
				Sdk::Methods::SendCardValue(this, card_id, suit, value);
			}

		};


		class PlayingCard
		{
		public:

			struct CardData
			{
			public:

				ECardSuit Suit;
				ECardValue Value;
			};

			ECardSuit GetSuit()
			{
				if (!mem.IsValidPtr(this)) return ECardSuit::Spades;
				return mem.Read<ECardSuit>(this + 0x24);
			}

			ECardValue GetValue()
			{
				if (!mem.IsValidPtr(this)) return ECardValue::Blank;
				return mem.Read<ECardValue>(this + 0x28);
			}

			void SetSuit(ECardSuit suit)
			{
				if (!mem.IsValidPtr(this)) return;
				Sdk::Methods::set_Suit(this, suit);
			}

			void SetValue(ECardValue value)
			{
				if (!mem.IsValidPtr(this)) return;
				Sdk::Methods::set_Value(this, value);
			}

			CardController* GetCardController()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<CardController*>(this + 0x30);
			}

			Unity::String* GetCardID()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Unity::String*>(this + 0x38);
			}

			void SetFaceUp(bool value)
			{
				if (!mem.IsValidPtr(this)) return;
				return Sdk::Methods::set_IsFaceUp(this, value);
			}

			std::string ToString(ECardSuit suit, ECardValue value)
			{
				if (!mem.IsValidPtr(this)) return "";

				const char* valueStr[] = {
					"Blank", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
					"Eight", "Nine", "Ten", "Jack", "Queen", "King"
				};

				const char* suitStr[] = {
					"Spades", "Hearts", "Diamonds", "Clubs"
				};

				if (value < Blank || value > King || suit > Clubs)
					return "Invalid Card";

				return std::string(valueStr[value]) + " of " + suitStr[suit];
			}

			Unity::SpriteRenderer* GetSpriteRenderer()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Unity::SpriteRenderer*>(this + 0x40);
			}

			CardSprite* GetCardSprite(uint32_t suit, uint32_t value)
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return Sdk::Methods::GetCardSprite(this, suit, value);
			}
		};

		class RTBGameController
		{
		public:

			static enum EStage : uint32_t
			{
				WaitingForPlayers = 0,
				RedOrBlack = 1,
				HigherOrLower = 2,
				InsideOrOutside = 3,
				Suit = 4,
			};

			EStage GetCurrentStage()
			{
				if (!mem.IsValidPtr(this)) return EStage::WaitingForPlayers;
				return mem.Read<EStage>(this + 0x178);
			}

			void GetQuestionsAndAnswers(EStage stage, Unity::String*& question, Unity::Array<Unity::String*>*& answers)
			{
				if (!mem.IsValidPtr(this)) return;
				Sdk::Methods::GetQuestionsAndAnswers(this, stage, question, answers);
			}

			Unity::List<PlayingCard::CardData>* GetDrawnCards()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Unity::List<PlayingCard::CardData>*>(this + 0x1D8);
			}

			Unity::Array<PlayingCard*>* GetPlayingCards()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Unity::Array<PlayingCard*>*>(this + 0x158);
			}
		};

		class BlackjackGameController
		{
		public:

			Unity::List<PlayingCard*>* GetDealerCards()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Unity::List<PlayingCard*>*>(this + 0x1E0);
			}

			Unity::List<PlayingCard*>* GetPlayerCards()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Unity::List<PlayingCard*>*>(this + 0x1C0);
			}

			Unity::List<PlayingCard*>* GetPlayStack()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Unity::List<PlayingCard*>*>(this + 0x1B8);
			}
		};

		class SlotMachine
		{
		public:
			static enum ESymbol : uint32_t
			{
				Cherry = 0,
				Lemon = 1,
				Grape = 2,
				Watermelon = 3,
				Bell = 4,
				Seven = 5,
			};
		};

		class SlotReel
		{
		public:

			static enum EOutcome : uint32_t
			{
				Jackpot = 0,
				BigWin = 1,
				SmallWin = 2,
				MiniWin = 3,
				NoWin = 4,
			};

			bool IsSpinning()
			{
				if (!mem.IsValidPtr(this)) return false;
				return mem.Read<bool>(this + 0x20);
			}

			void SetCurrentSymbol(SlotMachine::ESymbol symbol)
			{
				if (!mem.IsValidPtr(this)) return;
				Sdk::Methods::set_CurrentSymbol(this, symbol);
			}
		};
	}

	namespace Vehicles
	{
		class LandVehicle
		{
		public:

			bool LocalPlayerIsDriver()
			{
				if (!mem.IsValidPtr(this)) return false;
				return mem.Read<bool>(this + 0x270);
			}

			Unity::RigidBody* GetRigidBody()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Unity::RigidBody*>(this + 0x188);
			}

			void SetSpeed(float value)
			{
				if (!mem.IsValidPtr(this)) return;
				mem.Write<float>(this + 0x280, value);
			}

		};
	}

	namespace Map
	{
		class TimedAccessZone
		{
		public:

			static Unity::Array<TimedAccessZone*>* GetTimedAccessZones()
			{
				return (Unity::Array<TimedAccessZone*>*)Unity::Object::FindObjectsOfType((Unity::Type*)il2cpp::TypeGetObject(("ScheduleOne.Map"), ("TimedAccessZone")));
			}

			void SetOpenTime(float time)
			{
				if (!mem.IsValidPtr(this)) return;
				mem.Write<int>(this + 0x48, time);
			}

			void SetCloseTime(float time)
			{
				if (!mem.IsValidPtr(this)) return;
				mem.Write<int>(this + 0x4C, time);
			}
		};
	}

	namespace Money
	{
		class MoneyManager
		{
		public:

			void AddCash(float amount)
			{
				if (!mem.IsValidPtr(this)) return;
				Sdk::Methods::ChangeCashBalance(this, amount, true, true);
			}

			void AddBalance(float amount)
			{
				if (!mem.IsValidPtr(this)) return;
				Sdk::Methods::ReceiveOnlineTransaction(this, Unity::String::New("za"), amount, 1, Unity::String::New("za"));
			}
		};
	}

	namespace Equipping
	{

		class AvatarEquippable
		{
		public:

			AvatarFramework::Avatar* GetAvatar()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<AvatarFramework::Avatar*>(this + 0x48);
			}
		};

		class Equippable_RangedWeapon
		{
		public:

			AvatarEquippable* GetAvatarEquippable()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<AvatarEquippable*>(this + 0x60);
			}

			void SetMinSpread(float value)
			{
				if (!mem.IsValidPtr(this)) return;
				mem.Write<float>(this + 0xDC, value);
			}

			void SetMaxSpread(float value)
			{
				if (!mem.IsValidPtr(this)) return;
				mem.Write<float>(this + 0xE0, value);
			}

			void SetAccuracy(float value)
			{
				if (!mem.IsValidPtr(this)) return;
				mem.Write<float>(this + 0x94, value);
			}

			void SetRange(float value)
			{
				if (!mem.IsValidPtr(this)) return;
				mem.Write<float>(this + 0xD4, value);
			}

			void SetDamage(float value)
			{
				if (!mem.IsValidPtr(this)) return;
				mem.Write<float>(this + 0xE4, value);
			}

			void Fire()
			{
				Sdk::Methods::Fire(this);
			}
		};
	}

	namespace Skating
	{
		class Skateboard
		{
		public:

			float GetJumpForce()
			{
				if (!mem.IsValidPtr(this)) return 0;
				return mem.Read<float>(this + 0x1D0);
			}

			void SetJumpForce(float force)
			{
				if (!mem.IsValidPtr(this)) return;
				mem.Write<float>(this + 0x1D0, force);
			}

			float GetCurrentSpeed()
			{
				if (!mem.IsValidPtr(this)) return 0;
				return mem.Read<float>(this + 0x118);
			}

			void SetCurrentSpeed(float speed)
			{
				if (!mem.IsValidPtr(this)) return;
				mem.Write<float>(this + 0x118, speed);
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

		
		namespace Relation
		{
			class NPCRelationData
			{
			public:

				bool IsUnlocked()
				{
					if (!mem.IsValidPtr(this)) return false;
					return mem.Read<bool>(this + 0x14);
				}

				void SetUnlocked()
				{
					if (!mem.IsValidPtr(this)) return;
					mem.Write<bool>(this + 0x14, true);
				}
			};
		}

		class NPCInventory
		{
		public:

			Unity::List<ItemFramework::ItemSlot*>* GetItemSlots()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Unity::List<ItemFramework::ItemSlot*>*>(this + 0x158);
			}
		};

		class NPCHealth
		{
		public:

			float GetHealth()
			{
				if (!mem.IsValidPtr(this)) return 0;
				return mem.Read<float>(this + 0x118);
			}

			float GetMaxHealth()
			{
				if (!mem.IsValidPtr(this)) return 0;
				return mem.Read<float>(this + 0x128);
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

			NPCHealth* GetNPCHealth()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<NPCHealth*>(this + 0x1B8);
			}

			Relation::NPCRelationData* GetRelationData()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Relation::NPCRelationData*>(this + 0x1F0);
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

		namespace Health
		{
			class PlayerHealth
			{
			public:

				float GetHealth()
				{
					if (!mem.IsValidPtr(this)) return 0;
					return mem.Read<float>(this + 0x11C);
				}

				float GetMaxHealth()
				{
					if (!mem.IsValidPtr(this)) return 0;
					return 100.0f;
				}
			};
		}

		class PlayerMovement
		{
		public:

			static void SetWalkSpeed(float value)
			{
				uint64_t TypeInfo = mem.Read<uint64_t>(mem.GameAssembly + 58300688);
				if (!TypeInfo) return;

				uint64_t StaticFields = mem.Read<uint64_t>(TypeInfo + 0xb8);
				if (!StaticFields) return;

				mem.Write<float>(StaticFields + 0x0, value);
			}

			static void SetSprintMultiplier(float value)
			{
				uint64_t TypeInfo = mem.Read<uint64_t>(mem.GameAssembly + 58300688);
				if (!TypeInfo) return;

				uint64_t StaticFields = mem.Read<uint64_t>(TypeInfo + 0xb8);
				if (!StaticFields) return;

				mem.Write<float>(StaticFields + 0x4, value);
			}

			static void SetJumpMultiplier(float value)
			{
				uint64_t TypeInfo = mem.Read<uint64_t>(mem.GameAssembly + 58300688);
				if (!TypeInfo) return;

				uint64_t StaticFields = mem.Read<uint64_t>(TypeInfo + 0xb8);
				if (!StaticFields) return;

				mem.Write<float>(StaticFields + 0xC, value);
			}

			static void SetGravityMultiplier(float value)
			{
				uint64_t TypeInfo = mem.Read<uint64_t>(mem.GameAssembly + 58300688);
				if (!TypeInfo) return;

				uint64_t StaticFields = mem.Read<uint64_t>(TypeInfo + 0xb8);
				if (!StaticFields) return;

				mem.Write<float>(StaticFields + 0x20, value);
			}
		};

		class PlayerCamera
		{
		public:

			void SetLookAt(Vector3 pos, float duration)
			{
				if (!mem.IsValidPtr(this)) return;
				Sdk::Methods::LookAt(this, pos, duration);
			}
		};


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


			Unity::Array<ItemFramework::ItemSlot*>* GetItemSlots()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Unity::Array<ItemFramework::ItemSlot*>*>(this + 0x2A0);
			}

			Health::PlayerHealth* GetPlayerHealth()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Health::PlayerHealth*>(this + 0x178);
			}

			Skating::Skateboard* GetSkateboard()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<Skating::Skateboard*>(this + 0x240);
			}
			
			bool IsSkating()
			{
				if (!mem.IsValidPtr(this)) return false;
				return mem.Read<bool>(this + 0x239);
			}
		};

		class ViewmodelAvatar
		{
		public:

			AvatarFramework::Avatar* GetAvatar()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<AvatarFramework::Avatar*>(this + 0x40);
			}

			AvatarFramework::Avatar* GetParentAvatar()
			{
				if (!mem.IsValidPtr(this)) return nullptr;
				return mem.Read<AvatarFramework::Avatar*>(this + 0x30);
			}

			Vector3 GetBaseOffset()
			{
				if (!mem.IsValidPtr(this)) return {};
				return mem.Read<Vector3>(this + 0x50);
			}

			void SetBaseOffset(Vector3 offset)
			{
				if (!mem.IsValidPtr(this)) return;
				mem.Write<Vector3>(this + 0x50, offset);
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
				if (!mem.IsValidPtr(this)) return;
				auto set_SkyColor = reinterpret_cast<void(*)(Funly::SkyStudio::SkyMaterialController*, Unity::Color)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("SkyMaterialController", "set_SkyColor", 0, "", "Funly.SkyStudio")));
				set_SkyColor(this, color);
			}

			void SetMiddleSkyColor(Unity::Color color)
			{
				if (!mem.IsValidPtr(this)) return;
				auto set_SkyMiddleColor = reinterpret_cast<void(*)(Funly::SkyStudio::SkyMaterialController*, Unity::Color)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("SkyMaterialController", "set_SkyMiddleColor", 0, "", "Funly.SkyStudio")));
				set_SkyMiddleColor(this, color);
			}

			void SetHorizonSkyColor(Unity::Color color)
			{
				if (!mem.IsValidPtr(this)) return;
				auto set_HorizonColor = reinterpret_cast<void(*)(Funly::SkyStudio::SkyMaterialController*, Unity::Color)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("SkyMaterialController", "set_HorizonColor", 0, "", "Funly.SkyStudio")));
				set_HorizonColor(this, color);
			}

			void SetSkyboxMaterial(Unity::Color color)
			{
				if (!mem.IsValidPtr(this)) return;
				auto set_SkyboxMaterial = reinterpret_cast<void(*)(Funly::SkyStudio::SkyMaterialController*, Unity::Material*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("SkyMaterialController", "set_SkyboxMaterial", 0, "", "Funly.SkyStudio")));
				auto get_SkyboxMaterial = reinterpret_cast<Unity::Material * (*)(Funly::SkyStudio::SkyMaterialController*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("SkyMaterialController", "get_SkyboxMaterial", 0, "", "Funly.SkyStudio")));

				auto material = get_SkyboxMaterial(this);
				auto shader = material->GetShader();
				if (shader == Unity::Bundles::StarNestShader) return;

				Unity::Bundles::StarNestMaterial->SetShader(Unity::Bundles::StarNestShader);
				Unity::Bundles::StarNestMaterial->SetColor((L"_Color"), color);
				set_SkyboxMaterial(this, Unity::Bundles::StarNestMaterial);
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

			float GetSkyTime()
			{
				if (!mem.IsValidPtr(this)) return -1;
				return mem.Read<float>(this + 0x28);
			}

			void SetSkyTime(float time)
			{
				if (!mem.IsValidPtr(this)) return;
				mem.Write<float>(this + 0x28, time);
			}
		};
	}
}
