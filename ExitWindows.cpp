// ExitWindows.cpp: implementation of the CExitWindows class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Shutos.h"
#include "ExitWindows.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CExitWindows::CExitWindows()
{
	OSVERSIONINFO myoos;
	char temp[255];
    unsigned long bn;
	myoos.dwOSVersionInfoSize =sizeof(OSVERSIONINFO);
	GetVersionEx(&myoos); 
	if(myoos.dwPlatformId ==VER_PLATFORM_WIN32_NT)
	{
      HANDLE htok;
	  TOKEN_PRIVILEGES mytok;
	  LookupPrivilegeValue(NULL,SE_SHUTDOWN_NAME,&mytok.Privileges[0].Luid);
      LookupPrivilegeName(NULL,&mytok.Privileges[0].Luid,temp,&bn);
      OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES ,&htok);  
	  mytok.PrivilegeCount=1;
	  mytok.Privileges[0].Attributes =SE_PRIVILEGE_ENABLED; 
      AdjustTokenPrivileges (htok,FALSE,&mytok,NULL,NULL,0);
    }

}

CExitWindows::~CExitWindows()
{

}

void CExitWindows::Poweroff()
{
	   ExitWindowsEx(EWX_POWEROFF | EWX_FORCE,0);
}

void CExitWindows::Turnoff()
{
      ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE,0);
}

void CExitWindows::Restart()
{
       ExitWindowsEx(EWX_REBOOT |EWX_FORCE,0);

}

void CExitWindows::Logoff()
{
	ExitWindowsEx(EWX_LOGOFF |EWX_FORCE,0);
}
