// ShutosDlg.h : header file
//

#if !defined(AFX_SHUTOSDLG_H__057EBD7F_05EA_490E_8C9D_46D0E1BAC854__INCLUDED_)
#define AFX_SHUTOSDLG_H__057EBD7F_05EA_490E_8C9D_46D0E1BAC854__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CShutosDlg dialog

class CShutosDlg : public CDialog
{
// Construction
public:
	int Smode;
	char temp[10];
	void Shutos(int);
	CShutosDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CShutosDlg)
	enum { IDD = IDD_SHUTOS_DIALOG };
	CStatic	m_pic;
	int		m_ehour;
	int		m_emin;
	int		m_esec;
	BOOL	m_enabled;
	int		m_power;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShutosDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CShutosDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnEnabled();
	afx_msg void OnExit();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	afx_msg void OnOk();
	afx_msg void OnSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHUTOSDLG_H__057EBD7F_05EA_490E_8C9D_46D0E1BAC854__INCLUDED_)
