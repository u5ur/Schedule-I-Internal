#include "Input.h"

typedef UINT(WINAPI* pSendInput)(UINT, LPINPUT, int);

pSendInput cSendInput = nullptr;

bool Input::Init()
{
    HMODULE User32 = LoadLibraryExW(L"user32.dll", NULL, LOAD_LIBRARY_AS_IMAGE_RESOURCE);
    if (!User32) return false;

    FARPROC Address = GetProcAddress(User32, "SendInput");
    if (!Address) return false;

    cSendInput = reinterpret_cast<pSendInput>(Address);
    return true;
}

void Input::SendMouse(float x, float y)
{
    POINT currentPos;
    GetCursorPos(&currentPos);
    LONG dx = static_cast<LONG>(x - currentPos.x);
    LONG dy = static_cast<LONG>(y - currentPos.y);

    INPUT input = { 0 };
    input.type = INPUT_MOUSE;
    input.mi.dx = dx;
    input.mi.dy = dy;
    input.mi.dwFlags = MOUSEEVENTF_MOVE;

    cSendInput(1, &input, sizeof(INPUT));
}

bool Input::bIsKeyDown(int vkey)
{
    return (GetAsyncKeyState(vkey) & 0x8000) != 0;
}

bool Input::bKeyPressed(int vkey)
{
    return (GetAsyncKeyState(vkey) & 0x0001) != 0;
}