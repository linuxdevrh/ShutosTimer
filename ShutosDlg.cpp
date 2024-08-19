// ShutosDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Shutos.h"
#include "ShutosDlg.h"
//#include "winuser.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShutosDlg dialog

CShutosDlg::CShutosDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShutosDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShutosDlg)
	m_ehour = 0;
	m_emin = 0;
	m_esec = 0;
	m_enabled = FALSE;
	m_power = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON3);
}

void CShutosDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShutosDlg)
	DDX_Control(pDX, IDC_PICT, m_pic);
	DDX_Text(pDX, IDC_EDIT1, m_ehour);
	DDV_MinMaxInt(pDX, m_ehour, 0, 23);
	DDX_Text(pDX, IDC_EDIT2, m_emin);
	DDV_MinMaxInt(pDX, m_emin, 0, 59);
	DDX_Text(pDX, IDC_EDIT3, m_esec);
	DDV_MinMaxInt(pDX, m_esec, 0, 59);
	DDX_Check(pDX, IDC_ENABLED, m_enabled);
	DDX_Radio(pDX, IDC_RADIO1, m_power);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CShutosDlg, CDialog)
	//{{AFX_MSG_MAP(CShutosDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_CLOSE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_ENABLED, OnEnabled)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_SET, OnSet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShutosDlg message handlers

BOOL CShutosDlg::OnInitDialog()
{
	
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);

	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	NOTIFYICONDATA mynot;
	mynot.cbSize=sizeof(NOTIFYICONDATA);
	mynot.hIcon=AfxGetApp()->LoadIcon(IDI_ICON3);
	mynot.hWnd=m_hWnd;
	strcpy(mynot.szTip,"Shutdown Timer");
	mynot.uFlags=NIF_ICON|NIF_TIP|NIF_MESSAGE;
	mynot.uID=0x100;
	mynot.uCallbackMessage=WM_MOUSEMOVE;
	Shell_NotifyIcon(NIM_ADD,&mynot);
    m_enabled=TRUE;
	m_power=0;
	Smode=1;
	UpdateData(FALSE);
	SetTimer(IDI_TIMER,1000,NULL);
//	GetDlgItem(IDC_OK)->SetWindowText(("ÓáÇã ÇãíÑ"));
	return TRUE;  // return TRUE  unless you set the focus to a control

}

void CShutosDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShutosDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShutosDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CShutosDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
		 CAboutDlg dlgAbout;
	 switch(point.x)
	    {
	 case(WM_LBUTTONDOWN)://Left Button Down
         ShowWindow(SW_SHOW);
		 break;
	 case(WM_RBUTTONDOWN)://Right Button Down
 		 dlgAbout.DoModal();
	     break;
	 case (WM_LBUTTONDBLCLK):
		 Shutos(Smode);
		 break;
	 }
		 CDialog::OnMouseMove(nFlags, point);
}


void CShutosDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	NOTIFYICONDATA mynot;
	mynot.cbSize=sizeof(NOTIFYICONDATA);
	mynot.hWnd=m_hWnd;
	mynot.uID=0x100;
	Shell_NotifyIcon(NIM_DELETE,&mynot); 
	CDialog::OnClose();
}




void CShutosDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CTime curtime=CTime::GetCurrentTime(); 
	GetDlgItem(IDC_CTIME)->SetWindowText(curtime.GetCurrentTime().Format("%H:%M:%S"));
	if(m_ehour==curtime.GetHour () && m_emin==curtime.GetMinute () && m_esec==curtime.GetSecond()) 
	{
	    Shutos(Smode);
	}	

		CDialog::OnTimer(nIDEvent);
}


void CShutosDlg::Shutos(int mode)
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
	switch (mode)
	{
	case (1)://Power off
	   ExitWindowsEx(EWX_POWEROFF | EWX_FORCE,0);
       break;
	case (2)://Shutdown
	   ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE,0);
       break;
	case(3)://Restart
       ExitWindowsEx(EWX_REBOOT |EWX_FORCE,0);
	   break;
	case (4)://Log Off
		ExitWindowsEx(EWX_LOGOFF |EWX_FORCE,0);
		break;
	}

}


void CShutosDlg::OnEnabled() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	NOTIFYICONDATA mynot;
	mynot.cbSize=sizeof(NOTIFYICONDATA);
	mynot.hWnd=m_hWnd;
	mynot.uID=0x100;
	mynot.uFlags=NIF_ICON|NIF_TIP|NIF_MESSAGE;
	mynot.uCallbackMessage=WM_MOUSEMOVE;

	if(m_enabled)
	{
		SetTimer(IDI_TIMER,1000,NULL);
        GetDlgItem(IDC_CTIME)->EnableWindow(TRUE);
		mynot.hIcon=AfxGetApp()->LoadIcon(IDI_ICON3);
		strcpy(mynot.szTip,"Shutdown Timer (Enabled)");
	    Shell_NotifyIcon(NIM_MODIFY,&mynot);
		m_pic.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON3));
	}
		else
	 {
		m_pic.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON4));
		mynot.hIcon=AfxGetApp()->LoadIcon(IDI_ICON4);
	    strcpy(mynot.szTip,"Shutdown Timer (Diasbled)");
	    Shell_NotifyIcon(NIM_MODIFY,&mynot);
		KillTimer(IDI_TIMER);
        GetDlgItem(IDC_CTIME)->EnableWindow(FALSE);
	 }
}

void CShutosDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	OnClose();
	OnCancel();
}



void CShutosDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
    Smode=1;	
}

void CShutosDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
    Smode=2;	
}

void CShutosDlg::OnRadio3() 
{
	// TODO: Add your control notification handler code here
	Smode=3;
}

void CShutosDlg::OnRadio4() 
{
	// TODO: Add your control notification handler code here
    Smode=4;	
}

void CShutosDlg::OnOk() 
{
	// TODO: Add your control notification handler code here
	ShowWindow(SW_HIDE);
}


void CShutosDlg::OnSet() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE);	
}
