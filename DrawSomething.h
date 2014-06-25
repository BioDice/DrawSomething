
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
	afx_msg void OnShapePolygon();
	afx_msg void OnFileSave32776();
	afx_msg void OnFileOpen32777();
	afx_msg void ShapeColorGreen();
	afx_msg void ShapeColorRed();
	afx_msg void ShapeColorBlue();
	afx_msg void ShapeColorYellow();
	afx_msg void LineType();
	afx_msg void IncrLineThickness();
	afx_msg void DecrLineThickness();
	afx_msg void SelectShapeObject();
	afx_msg void OnEditUndo();
	afx_msg void DeleteShape();
	afx_msg void Connector();
};

extern CDrawSomethingApp theApp;
