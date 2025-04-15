#include "Memory.h"

bool Memory::Init()
{
    GameAssembly = GetBaseAddress(("GameAssembly.dll"));
    if (!GameAssembly) return false;

    UnityPlayer = GetBaseAddress(("UnityPlayer.dll"));
    if (!UnityPlayer) return false;

    return true;
}

uint64_t Memory::GetBaseAddress(const char* module_name)
{
    HMODULE hModule = GetModuleHandleA(module_name);
    return reinterpret_cast<uint64_t>(hModule);
}

bool Memory::IsValidPtr(void* m_pPointer)
{
    if (reinterpret_cast<uint64_t>(m_pPointer) <= 0x400000 || reinterpret_cast<uint64_t>(m_pPointer) >= 0x7fffffffffff)
        return false;

    return true;
}

bool Memory::Read(uint64_t address, void* buffer, size_t size)
{
    if (!address || !buffer || !size)
        return false;

    __try {
        memcpy(buffer, reinterpret_cast<const void*>(address), size);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }

    return true;
}

bool Memory::Write(uint64_t address, const void* buffer, size_t size)
{
    if (!address || !buffer || !size)
        return false;
    try {
        std::memcpy(reinterpret_cast<void*>(address), buffer, size);
    }
    catch (const std::exception&) {
        return false;
    }
    return true;
}

uint64_t Memory::GetExport(uint64_t hDll, const char* Name)
{
    if (!hDll || !Name) return 0;

    PIMAGE_NT_HEADERS NT_Head = (PIMAGE_NT_HEADERS)(hDll + ((PIMAGE_DOS_HEADER)hDll)->e_lfanew);
    PIMAGE_EXPORT_DIRECTORY ExportDir = (PIMAGE_EXPORT_DIRECTORY)(hDll + NT_Head->OptionalHeader.DataDirectory[0].VirtualAddress);

    for (DWORD i = 0; i < ExportDir->NumberOfNames; i++)
    {
        USHORT Ordinal = ((USHORT*)(hDll + ExportDir->AddressOfNameOrdinals))[i];
        const char* ExpName = (const char*)hDll + ((DWORD*)(hDll + ExportDir->AddressOfNames))[i];

        for (int i = 0; ExpName[i] == Name[i]; i++) if (!ExpName[i])
            return hDll + ((DWORD*)(hDll + ExportDir->AddressOfFunctions))[Ordinal];
    } return 0;
}

