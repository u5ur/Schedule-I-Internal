#pragma once
#include <Windows.h>
#include <string>
#include <unordered_map>

namespace il2cpp
{
    using il2cpp_method_get_param_name = const char* (*)(DWORD64, uint32_t);
    using il2cpp_method_get_name = const char* (*)(DWORD64);
    using GPC = int (*)(DWORD64);
    using AGI = DWORD64(*)(DWORD64);
    using resolve = DWORD64(*)(const char*);
    using Dm = DWORD64(*)();
    using CFN = DWORD64(*)(DWORD64, const char*, const char*);
    using Call = DWORD64(*)(DWORD64, DWORD64);
    using Ptr = DWORD64(*)(DWORD64, DWORD64*);
    using DGA = DWORD64 * (*)(void*, DWORD64*);

    void Init();
    DWORD64 InitClass(const char* name, const std::string& name_space = "");
    DWORD64 TypeGetObject(const std::string& name_space, const char* name);
    DWORD64 TypeGetObject(uintptr_t klass);
    uint64_t NewString(const char* str);
    uint64_t ResolveICall(const char* str);
    uint64_t NewObject(uint64_t addr);
    DWORD64 GetObjectTypeNew(const std::string& name_space, const char* name);
    DWORD64 Method(const char* kl, const char* name, int argument_number = -1, const std::string& arg_name = "", const std::string& name_space = "", int selected_argument = -1);
    DWORD64 Field(DWORD64 klass, const std::string& field_name, bool get_offset = true);
    DWORD64 GetValue(const char* kl, const std::string& name, bool get_offset = true);
    DWORD64 GetOffset(const char* kl, const std::string& name, const std::string& name_space = "", bool get_offset = true);
    PBYTE FindPattern(const char* Pattern, const char* Module = nullptr);
}