#pragma once
#include <exception>
#include <Windows.h>

class Input
{
public:

	bool Init();

	void SendMouse(float x, float y);
	bool bIsKeyDown(int vkey);
    bool bKeyPressed(int vkey);
};
