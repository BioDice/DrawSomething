
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "DrawSomething.h"
#include "ChildView.h"

#include "Controller.h"
#include "Shape.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	MouseMode = Ready;
	Ctrl = new Controller();
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages
}

void CChildView::DrawAuxiliary(CPoint EndPoint)
{
	
	CDC* pDC = GetDC();
	Shape *shape = Ctrl->getShape(pDC);
	CPen pen;
	pDC->SelectStockObject(HOLLOW_BRUSH);
	pen.CreatePen(PS_DOT, 1, RGB(255,0,0));
	pDC->SelectObject(&pen);
	//pDC->SelectStockObject(BLACK_PEN);
	pDC->SetROP2(R2_NOTXORPEN);
	if(MouseMode == Moving)
		shape->DrawAuxiliary(StartPoint, LastPoint);
	shape->DrawAuxiliary(StartPoint, EndPoint);

	ReleaseDC(pDC);
	LastPoint = EndPoint;
	shape->~Shape();
}

void CChildView::DrawFinal(CPoint EndPoint)
{
	CDC* pDC = GetDC();
	Shape *shape = Ctrl->getShape(pDC);
	pDC->SelectStockObject(WHITE_BRUSH);
	pDC->SelectStockObject(BLACK_PEN);
	pDC->SetROP2(R2_COPYPEN);
	shape->DrawShape(StartPoint, EndPoint);

	{
		RECT r;
		r.left = StartPoint.x;
		r.top = StartPoint.y;
		r.bottom = LastPoint.y;
		r.right = LastPoint.x;

		//pDC->DrawTextW(L"Há!", &r, 0);
	}
	
	ReleaseDC(pDC);
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (Ctrl->getShape() != Controller::None)
	{
		StartPoint = point;
		MouseMode = Clicked;
	}
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (Ctrl->getShape() != Controller::None)
	{
		DrawFinal(point);
		MouseMode = Ready;
	}
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (MouseMode != Ready && Ctrl->getShape() != Controller::None)
	{
		if(!(nFlags & MK_LBUTTON)) // might have missed mouse up
		{
			DrawFinal(LastPoint);
			MouseMode = Ready;
		}
		else
		{
			DrawAuxiliary(point);
			MouseMode = Moving;
		}
	}
}
