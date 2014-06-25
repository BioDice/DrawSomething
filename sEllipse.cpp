#include "stdafx.h"
#include "sEllipse.h"


sEllipse::sEllipse()
{
	name = "Ellipse";
}

sEllipse::sEllipse(CPoint start, CPoint end)
{
	name = "Ellipse";
	this->start = start;
	this->end = end;
}

sEllipse::~sEllipse(void)
{
}

void sEllipse::DrawShape(CDC *pdc, CPoint start, CPoint end)
{
	CPen* penne = new CPen(lineType, lineThickness, lineColor);
	pdc->SelectObject(penne);
	rect.SetRect(start.x, start.y, end.x, end.y);
	pdc->Ellipse(start.x, start.y, end.x, end.y);
	this->start = start;
	this->end = end;
	PaintText(pdc);
	delete penne;
}

void sEllipse::DrawShape(CDC *pdc)
{
	CPen* penne = new CPen(lineType, lineThickness, lineColor);
	pdc->SelectObject(penne);
	rect.SetRect(start.x, start.y, end.x, end.y);
	pdc->Ellipse(start.x, start.y, end.x, end.y);
	PaintText(pdc);
	delete penne;
}

void sEllipse::IsSelected(CDC *pdc)
{
	CPen* penne = new CPen(PS_DOT, 1, RGB(150,150,150));
	pdc->SelectObject(penne);
	pdc->Ellipse(rect);
	PaintText(pdc);
	delete penne;
}

void sEllipse::DrawAuxiliary(CDC *pdc, CPoint start, CPoint end)
{
	pdc->Ellipse(start.x, start.y, end.x, end.y);
}

string sEllipse::ToString()
{
	CT2CA pszConvertedAnsiString (text);
	std::string strStd (pszConvertedAnsiString);
	return name
		+ "," + ltos(lineType)
		+ "," + ltos(lineThickness)
		+ "," + ltos(lineColor)
		+ "," + strStd
		+ "," + ltos(start.x) + "," + ltos(start.y) 
		+ "," + ltos(end.x) + "," + ltos(end.y) 
		+ "\n";
}