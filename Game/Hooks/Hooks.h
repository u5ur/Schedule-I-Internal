#pragma once
#include <Memory.h>
#include <il2cpp.h>

namespace Hooks
{
	class Hook
	{
	public:

		DWORD64 HookCPP(void* our_func, const char* function_to_hook, const char* class_to_hook,
			const std::string& name_space = "", int argument_number = -1,
			const std::string& argument_name = "")
		{
			auto il2cpp_method = il2cpp::Method(class_to_hook, function_to_hook, argument_number, argument_name, name_space);
			void* original_func = *reinterpret_cast<void**>(il2cpp_method);

			*reinterpret_cast<void**>(il2cpp_method) = our_func;
			return il2cpp_method;
		}
	}; static Hook* hook = new Hook;

	static void InitOnGUI(void* func)
	{
		hook->HookCPP(func, "OnGUI", "AstarPath", "", 0);
	}

	inline void (*OrigUpdateVisuals)(uint64_t);

	static void InitUpdateVisuals(void* func)
	{
		OrigUpdateVisuals = reinterpret_cast<void(*)(uint64_t)>(mem.Read<uint64_t>(il2cpp::Method("EnvironmentFX", "UpdateVisuals", 0, "", "ScheduleOne.FX")));
		hook->HookCPP(func, ("UpdateVisuals"), ("EnvironmentFX"), ("ScheduleOne.FX"), 0);
	}

	inline void (*OrigUpdate)(uint64_t);

	static void InitUpdateCamera(void* func)
	{
		OrigUpdate = reinterpret_cast<void(*)(uint64_t)>(mem.Read<uint64_t>(il2cpp::Method("PlayerCamera", "Update", 0, "", "ScheduleOne.PlayerScripts")));
		hook->HookCPP(func, ("Update"), ("PlayerCamera"), ("ScheduleOne.PlayerScripts"), 0);
	}

	inline void (*OrigUpdateWeapon)(uint64_t);

	static void InitUpdateWeapon(void* func)
	{
		OrigUpdateWeapon = reinterpret_cast<void(*)(uint64_t)>(mem.Read<uint64_t>(il2cpp::Method("Equippable_RangedWeapon", "Update", 0, "", "ScheduleOne.Equipping")));
		hook->HookCPP(func, ("Update"), ("Equippable_RangedWeapon"), ("ScheduleOne.Equipping"), 0);
	}

	inline void (*OrigUpdateMoney)(uint64_t);

	static void InitUpdateMoney(void* func)
	{
		OrigUpdateMoney = reinterpret_cast<void(*)(uint64_t)>(mem.Read<uint64_t>(il2cpp::Method("MoneyManager", "Update", 0, "", "ScheduleOne.Money")));
		hook->HookCPP(func, ("Update"), ("MoneyManager"), ("ScheduleOne.Money"), 0);
	}

	inline void (*OrigUpdateRTB)(uint64_t);

	static void InitUpdateRTB(void* func)
	{
		OrigUpdateRTB = reinterpret_cast<void(*)(uint64_t)>(mem.Read<uint64_t>(il2cpp::Method("RTBGameController", "FixedUpdate", 0, "", "ScheduleOne.Casino")));
		hook->HookCPP(func, ("FixedUpdate"), ("RTBGameController"), ("ScheduleOne.Casino"), 0);
	}

	inline void (*OrigUpdateBlackjack)(uint64_t);

	static void InitUpdateBJ(void* func)
	{
		OrigUpdateBlackjack = reinterpret_cast<void(*)(uint64_t)>(mem.Read<uint64_t>(il2cpp::Method("BlackjackGameController", "FixedUpdate", 0, "", "ScheduleOne.Casino")));
		hook->HookCPP(func, ("FixedUpdate"), ("BlackjackGameController"), ("ScheduleOne.Casino"), 0);
	}

	inline void (*OrigUpdateVehicle)(uint64_t);

	static void InitUpdateVehicle(void* func)
	{
		OrigUpdateVehicle = reinterpret_cast<void(*)(uint64_t)>(mem.Read<uint64_t>(il2cpp::Method("LandVehicle", "Update", 0, "", "ScheduleOne.Vehicles")));
		hook->HookCPP(func, ("Update"), ("LandVehicle"), ("ScheduleOne.Vehicles"), 0);
	}
}