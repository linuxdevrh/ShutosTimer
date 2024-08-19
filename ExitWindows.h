// ExitWindows.h: interface for the CExitWindows class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXITWINDOWS_H__7490D380_708B_46F7_B383_93E294EAF4F4__INCLUDED_)
#define AFX_EXITWINDOWS_H__7490D380_708B_46F7_B383_93E294EAF4F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CExitWindows  
{
public:
	void Logoff();
	void Restart();
	void Turnoff();
	void Poweroff();
	CExitWindows();
	virtual ~CExitWindows();

};

#endif // !defined(AFX_EXITWINDOWS_H__7490D380_708B_46F7_B383_93E294EAF4F4__INCLUDED_)
