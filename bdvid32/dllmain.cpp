// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
struct tagRECT Rect;

BOOL borderless = false;

BOOL CALLBACK EnumThreadWndProc(HWND argHwnd, LPARAM lParam)
{
	*(HWND *)lParam = argHwnd;
	return FALSE;
}

void MakeBorderless(){
	HWND handle;
	DWORD lThreadId = GetCurrentThreadId();
	EnumThreadWindows(lThreadId, EnumThreadWndProc, (long)&handle);
	GetClientRect(handle, &Rect);
	AdjustWindowRect(&Rect, 0x900A0000, 0);
	SetWindowLongA(handle, -16, 0x900A0000);
	SetWindowPos(handle, 0, 0, 0, Rect.right - Rect.left, Rect.bottom - Rect.top, 0x226u);
	SetWindowPos(handle, nullptr, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	borderless = true;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	return TRUE;
}


typedef signed int(__cdecl *bdvid)(int a1, DWORD *a2, int a3, int a4);

signed int __cdecl CreateBandiVideo2(int a1, DWORD *a2, int a3, int a4) {

	if (!borderless)
		MakeBorderless();

	HINSTANCE bdvidInstance = LoadLibraryA("bdvid32_2.dll");

	if (!bdvidInstance) {
		MessageBoxA(0, "Couldn't load library bdvid32_2.dll", "Error", MB_OK);
		return EXIT_FAILURE;
	}

	bdvid fn1 = (bdvid)GetProcAddress(bdvidInstance, "CreateBandiVideo2");
	return fn1(a1, a2, a3, a4);
}