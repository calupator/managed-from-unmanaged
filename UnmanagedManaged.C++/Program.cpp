#include "StdAfx.h"
#include "Windows.h"

using namespace System;
using namespace Managed::Csharp;
using namespace System::Runtime::InteropServices;

typedef void* (__cdecl *GetEntityFunc)(int);

public ref class ExternalApplication: public IExternalApplication
{	

public:
	// constructor
	ExternalApplication(HMODULE win32Handle);
	virtual Entity GetEntity(int id);
private:
	GetEntityFunc m_GetEntity;
};

ExternalApplication::ExternalApplication(HMODULE win32Handle) {
	// initialize functions
	m_GetEntity = (GetEntityFunc)GetProcAddress(win32Handle, "GetEntity");
}

Entity ExternalApplication::GetEntity(int id) {	
	void *entityPtr = m_GetEntity(id);
	Entity entity = (Entity)Marshal::PtrToStructure((IntPtr)entityPtr, Entity::typeid);
	return entity;
}

// exported functions
extern "C" __declspec(dllexport) void StartApplication(HMODULE);

void StartApplication(HMODULE win32Handle) {
	Program::SetExternalApplication(gcnew ExternalApplication(win32Handle));
}
