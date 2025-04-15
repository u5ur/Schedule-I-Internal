#include "il2cpp.h"
#include <Memory.h>
#include <iostream>

namespace il2cpp
{
    il2cpp_method_get_param_name method_get_param_name = nullptr;
    il2cpp_method_get_name method_get_name = nullptr;
    Ptr class_get_methods = nullptr;
    Ptr class_get_fields = nullptr;
    Dm domain_get = nullptr;
    Dm thread_attach = nullptr;
    DGA domain_get_assemblies = nullptr;
    AGI assembly_get_image = nullptr;
    CFN class_from_name = nullptr;
    AGI field_get_offset = nullptr;
    Ptr field_static_get_value = nullptr;
    GPC method_get_param_count = nullptr;
    Call array_new = nullptr;
    resolve new_string = nullptr;
    AGI type_get_object = nullptr;
    AGI class_get_type = nullptr;
    resolve resolve_icall = nullptr;
    AGI object_new = nullptr;
    AGI runtime_class_init = nullptr;

    void Init()
    {
        auto base = mem.GameAssembly;
        runtime_class_init = (AGI)(mem.GetExport(base, "il2cpp_runtime_class_init"));
        method_get_param_name = (il2cpp_method_get_param_name)(mem.GetExport(base, "il2cpp_method_get_param_name"));
        method_get_name = (il2cpp_method_get_name)(mem.GetExport(base, "il2cpp_method_get_name"));
        class_get_methods = (Ptr)(mem.GetExport(base, "il2cpp_class_get_methods"));
        class_get_fields = (Ptr)(mem.GetExport(base, "il2cpp_class_get_fields"));
        domain_get = (Dm)(mem.GetExport(base, "il2cpp_domain_get"));
        thread_attach = (Dm)(mem.GetExport(base, "il2cpp_thread_attach"));
        domain_get_assemblies = (DGA)(mem.GetExport(base, "il2cpp_domain_get_assemblies"));
        assembly_get_image = (AGI)(mem.GetExport(base, "il2cpp_assembly_get_image"));
        class_from_name = (CFN)(mem.GetExport(base, "il2cpp_class_from_name"));
        field_get_offset = (AGI)(mem.GetExport(base, "il2cpp_field_get_offset"));
        field_static_get_value = (Ptr)(mem.GetExport(base, "il2cpp_field_static_get_value"));
        method_get_param_count = (GPC)(mem.GetExport(base, "il2cpp_method_get_param_count"));
        array_new = (Call)(mem.GetExport(base, "il2cpp_array_new"));
        new_string = (resolve)(mem.GetExport(base, "il2cpp_string_new"));
        type_get_object = (AGI)(mem.GetExport(base, "il2cpp_type_get_object"));
        class_get_type = (AGI)(mem.GetExport(base, "il2cpp_class_get_type"));
        resolve_icall = (resolve)(mem.GetExport(base, "il2cpp_resolve_icall"));
        object_new = (AGI)(mem.GetExport(base, "il2cpp_object_new"));
    }

    uint64_t NewObject(uint64_t addr)
    {
        return object_new(addr);
    }

    uint64_t ResolveICall(const char* str)
    {
        return resolve_icall(str);
    }

    uint64_t NewString(const char* str)
    {
        return il2cpp::new_string(str);
    }

    DWORD64 InitClass(const char* name, const std::string& name_space)
    {
        DWORD64 domain = domain_get();
        DWORD64 num_assemblies = 0;
        DWORD64* assemblies = domain_get_assemblies((void*)domain, &num_assemblies);

        for (int i = 0; i < num_assemblies; i++) {
            DWORD64 image = assembly_get_image(assemblies[i]);
            DWORD64 klass = class_from_name(image, name_space.c_str(), name);
            if (klass) return klass;
        }
        return 0;
    }

    DWORD64 TypeGetObject(const std::string& name_space, const char* name)
    {
        auto klass = InitClass(name, name_space);
        return mem.IsValidPtr((void*)klass) ? type_get_object(class_get_type(klass)) : 0;
    }

    DWORD64 TypeGetObject(uintptr_t klass)
    {
        return type_get_object(class_get_type(klass));
    }

    DWORD64 GetObjectTypeNew(const std::string& name_space, const char* name)
    {
        auto klass = InitClass(name, name_space);
        return object_new(klass);
    }

    DWORD64 Method(const char* kl, const char* name, int arg_count, const std::string& arg_name, const std::string& name_space, int selected_arg)
    {
        DWORD64 iter = 0;
        auto klass = InitClass(kl, name_space);
        if (!mem.IsValidPtr((void*)klass)) return 0;

        DWORD64 method = 0;
        while ((method = class_get_methods(klass, &iter))) {
            if (!mem.IsValidPtr((void*)method)) continue;
            const auto method_name = method_get_name(method);
            if (!mem.IsValidPtr((void*)method_name) || strcmp(method_name, name) != 0) continue;

            if (selected_arg >= 0 && !arg_name.empty()) {
                int param_count = method_get_param_count(method);
                if ((arg_count >= 0 && param_count != arg_count) || selected_arg > param_count) continue;
                const char* param_name = param_count > 0 ? method_get_param_name(method, selected_arg - 1) : "-";
                if (!param_name || strcmp(param_name, arg_name.c_str()) != 0) continue;
            }
            return method;
        }
        return 0;
    }

    DWORD64 Field(DWORD64 klass, const std::string& field_name, bool get_offset)
    {
        DWORD64 iter = 0, field;
        while ((field = class_get_fields(klass, &iter))) {
            char* name = reinterpret_cast<char*>(mem.Read<DWORD64>(field));
            if (!name || strcmp(name, field_name.c_str()) != 0) continue;
            return get_offset ? field_get_offset(field) : field;
        }
        return 0;
    }

    DWORD64 GetValue(const char* kl, const std::string& name, bool get_offset)
    {
        auto klass = InitClass(kl);
        if (!klass) return 0;

        if (get_offset) return Field(klass, name);

        DWORD64 field = Field(klass, name, false);
        if (!field) return 0;

        DWORD64 result;
        field_static_get_value(field, &result);
        return result;
    }

    DWORD64 GetOffset(const char* kl, const std::string& name, const std::string& name_space, bool get_offset)
    {
        auto klass = InitClass(kl, name_space);
        return Field(klass, name, get_offset);
    }

    PBYTE FindPattern(const char* pattern, const char* module)
    {
        auto InRange = [](char x, char a, char b) { return x >= a && x <= b; };
        auto GetBits = [&](char x) { return InRange(x, '0', '9') ? x - '0' : (x - 'A' + 0xA); };
        auto GetByte = [&](const char* str) { return (BYTE)((GetBits(str[0]) << 4) | GetBits(str[1])); };

        PBYTE start = (PBYTE)mem.GetBaseAddress(module);
        if (!start) return nullptr;

        PIMAGE_NT_HEADERS nt = (PIMAGE_NT_HEADERS)(start + ((PIMAGE_DOS_HEADER)start)->e_lfanew);
        PBYTE end = start + nt->OptionalHeader.SizeOfImage - 0x1000;
        start += 0x1000;

        PBYTE match = nullptr;
        const char* cur = pattern;

        for (; start < end; ++start)
        {
            bool skip = (*cur == '?');
            if (skip || *start == GetByte(cur)) {
                if (!match) match = start;
                cur += skip ? 2 : 3;
                if (*cur == 0) return match;
            }
            else if (match) {
                start = match;
                match = nullptr;
                cur = pattern;
            }
        }
        return nullptr;
    }
}