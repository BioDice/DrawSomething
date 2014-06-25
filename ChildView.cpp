
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "DrawSomething.h"
#include "ChildView.h"
#include "Controller.h"

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
	ON_WM_SIZING()
	ON_WM_SIZE()
	ON_WM_SHOWWINDOW()
	ON_WM_ACTIVATE()
	ON_WM_SETFOCUS()
	ON_WM_KEYDOWN()
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

void CChildView::RedrawShapes()
{
	CWnd::RedrawWindow();
	CWnd::UpdateWindow();

	if (Ctrl->shapes.empty() == false)
	{
		for (auto i : Ctrl->shapes)
		{
			CPen pen;
			pen.CreatePen(i->lineType, i->lineThickness, i->lineColor);
			CDC* pDC = GetDC();
			i->DrawShape(pDC);
			ReleaseDC(pDC);
		}
	}
}

void CChildView::DrawAuxiliary(CPoint EndPoint)
{
	CDC* pDC = GetDC();
	CPen pen;
	pDC->SelectStockObject(HOLLOW_BRUSH);
	pen.CreatePen(PS_DOT, 1, RGB(255,0,0));
	pDC->SelectObject(&pen);
	//pDC->SelectStockObject(BLACK_PEN);
	pDC->SetROP2(R2_NOTXORPEN);
	if(MouseMode == Moving)
		currentShape->DrawAuxiliary(pDC, StartPoint, LastPoint);
	currentShape->DrawAuxiliary(pDC, StartPoint, EndPoint);

	ReleaseDC(pDC);
	LastPoint = EndPoint;
	//shape->~Shape();
}

void CChildView::DrawFinal(CPoint EndPoint)
{
	CDC* pDC = GetDC();
	Controller::ShapeColor color = Ctrl->GetSelectedShapeColor();
	currentShape->lineColor = Ctrl->currentColor;
	currentShape->lineThickness = Ctrl->currentLineThickness;
	currentShape->lineType = Ctrl->currentLineType;
	currentShape->DrawShape(pDC, StartPoint, EndPoint);
	
	ReleaseDC(pDC);
	/*if (!Ctrl->IsDrawingPolygon)
	{
		delete currentShape;
		currentShape = NULL;
	}*/
}

void CChildView::Reset()
{
	vector<Shape*> str;
	if (str.empty() == false)
	{
		for (auto i : str)
		{
			InvalidateRect(i->GetRect());
		}

		str.clear();
		RedrawShapes();
	}
};

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (Ctrl->selectTool)
	{
		for (int i = Ctrl->shapes.size()-1; i >= 0; i--)
		{
			
			if (Ctrl->shapes[i]->IsOn(point) && Ctrl->shapes[i]->GetName() != "Polygon")
			{
				RedrawShapes();
				CDC* pdc = GetDC();
				currentShape = Ctrl->shapes[i];
				currentShape->IsSelected(pdc);;
				ReleaseDC(pdc);
				break;
			}
		}
		return;
	}
	if (!Ctrl->IsDrawingPolygon)
	{
		Shape *shape = NULL;
		currentShape = Ctrl->getShape(shape);
		delete shape;
	}
	if (Ctrl->currentShape == Controller::DrawShape::Polygon && StartPoint.x != 0 && StartPoint.y != 0)
	{
		DrawFinal(LastPoint);
		StartPoint = LastPoint;
		MouseMode = Clicked;

		int tmpxmin = currentShape->points[0].x -10;
		int tmpymin = currentShape->points[0].y -10;
		int tmpxmax = currentShape->points[0].x +10;
		int tmpymax = currentShape->points[0].y +10;
		if(point.x < tmpxmax && point.x > tmpxmin && point.y < tmpymax && point.y > tmpymin)
		{
			MouseMode = Ready;
			Ctrl->IsDrawingPolygon = false;
			StartPoint = false;
		}
	}
	else
	{
		if (currentShape != NULL)
		{
			StartPoint = point;
			MouseMode = Clicked;
		}
	}
}

void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (Ctrl->selectTool)
		return;
	if (currentShape != NULL && Ctrl->currentShape != Controller::DrawShape::Polygon)
	{
		DrawFinal(point);
		MouseMode = Ready;
		StartPoint = NULL;
	}
}

void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (Ctrl->currentShape == Controller::DrawShape::Polygon && MouseMode != Ready)
	{
		DrawAuxiliary(point);
		MouseMode = Moving;
	}
	else
	{
		if (MouseMode != Ready && currentShape != NULL)
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
}

void CChildView::OnSize(UINT nType, int cx, int cy)
{
	RedrawShapes();
}

void CChildView::OnSetFocus(CWnd* pOldWnd)
{
	RedrawShapes();
}

void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	Ctrl->SetShapeText(nChar);
}
