#pragma once
#include "Input.h"

class Memory
{

private:

    Input* input = new Input;

public:

    uint64_t GameAssembly;
    uint64_t UnityPlayer;

    bool Init();

    Input* GetInput() { return input; }

    uint64_t GetBaseAddress(const char* module_name);

    uint64_t GetExport(uint64_t hDll, const char* Name);

    bool IsValidPtr(void* m_pPointer);

    bool Read(uint64_t address, void* buffer, size_t size);

    template <typename T>
    T Read(uint64_t address)
    {
        T buffer{};
        if (!Read(address, &buffer, sizeof(T))) {
            return T{};
        }
        return buffer;
    }

    template <typename T>
    T Read(void* address)
    {
        if (!address) return T{};
        return Read<T>(reinterpret_cast<uint64_t>(address));
    }

    bool Write(uint64_t address, const void* buffer, size_t size);

    template <typename T>
    bool Write(uint64_t address, const T& value)
    {
        return Write(address, &value, sizeof(T));
    }

    template <typename T>
    bool Write(void* address, const T& value)
    {
        if (!address) return false;
        return Write(reinterpret_cast<uint64_t>(address), value);
    }
};

inline Memory mem;