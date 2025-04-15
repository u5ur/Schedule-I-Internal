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

	void InitOnGUI(void* func)
	{
		hook->HookCPP(func, "OnGUI", "AstarPath", "", 0);
	}

	void (*OrigUpdateVisuals)(uintptr_t*);

	void InitUpdateVisuals(void* func)
	{
		OrigUpdateVisuals = reinterpret_cast<void(*)(uintptr_t*)>(mem.GameAssembly + 0x6D2A10);
		(void(*)(uintptr_t*))hook->HookCPP(func, ("UpdateVisuals"), ("EnvironmentFX"), ("ScheduleOne.FX"), 0);
	}
}
