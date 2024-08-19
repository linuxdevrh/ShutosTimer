// Shutos.h : main header file for the SHUTOS application
//
#define _UNICODE 
#if !defined(AFX_SHUTOS_H__5A8CB549_61EE_42C2_A7F2_06A5CBA0D676__INCLUDED_)
#define AFX_SHUTOS_H__5A8CB549_61EE_42C2_A7F2_06A5CBA0D676__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CShutosApp:
// See Shutos.cpp for the implementation of this class
//

class CShutosApp : public CWinApp
{
public:
	CShutosApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShutosApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CShutosApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHUTOS_H__5A8CB549_61EE_42C2_A7F2_06A5CBA0D676__INCLUDED_)
