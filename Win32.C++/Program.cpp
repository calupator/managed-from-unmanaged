// Win32.C++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "comdef.h"

#import ".\\..\\Managed.Csharp\\bin\\Debug\\Managed.Csharp.tlb" no_namespace

// imported functions
typedef void (__cdecl *StartApplicationFunc)(HMODULE);

// exported functions
extern "C" __declspec(dllexport) void* GetEntity(int);

void* GetEntity(int id) {
	Entity *entity = new Entity();
	entity->id = id;
	entity->name = _bstr_t("I'm entity!").copy();
	return entity;
}

const HMODULE GetCurrentModule()
{
    DWORD flags = GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS;
    HMODULE hm = 0;
    ::GetModuleHandleEx( flags, reinterpret_cast<LPCTSTR>( GetCurrentModule ), &hm );   
    return hm;
}

int _tmain(int argc, _TCHAR* argv[])
{
	HMODULE bridgeHandle = LoadLibrary(L"UnmanagedManaged.C++.dll");			
	StartApplicationFunc startApplication = (StartApplicationFunc)GetProcAddress(bridgeHandle, "StartApplication");	
	HMODULE handle = GetCurrentModule();
	startApplication(handle);
	return 0;
}
