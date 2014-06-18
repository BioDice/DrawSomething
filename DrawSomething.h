
// DrawSomething.h : main header file for the DrawSomething application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDrawSomethingApp:
// See DrawSomething.cpp for the implementation of this class
//

class CDrawSomethingApp : public CWinApp
{
public:
	CDrawSomethingApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnShapeRectangle();
	afx_msg void OnShapeCircle();
	afx_msg void OnShapeSquare();
	afx_msg void OnShapeEllipse();
};

extern CDrawSomethingApp theApp;
