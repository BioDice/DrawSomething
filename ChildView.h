
// ChildView.h : interface of the CChildView class
//


#pragma once

#include "Shape.h"
#include <vector>

// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();
	
	CPoint StartPoint, LastPoint;
	Shape *currentShape;
	enum CMouseMode { Ready, Clicked, Moving } MouseMode;
	void Reset();

public:
	void RedrawShapes();
	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

private:
	void DrawFinal(CPoint EndPoint);
	void DrawAuxiliary(CPoint EndPoint);
	//int tmpxmin, tmpymin, tmpxmax, tmpymax;

public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

