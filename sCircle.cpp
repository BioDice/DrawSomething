#include "stdafx.h"
#include "sCircle.h"


sCircle::sCircle()
{
	name = "Circle";
}

sCircle::sCircle(CPoint start, CPoint end)
{
	name = "Circle";
	this->start = start;
	this->end = end;
}

sCircle::~sCircle(void)
{
}

void sCircle::DrawShape(CDC *pdc, CPoint start, CPoint end)
{
	CPen* penne = new CPen(lineType, lineThickness, lineColor);
	pdc->SelectObject(penne);
	rect.SetRect(start.x, start.y, start.x + (end.x - start.x), start.y + (end.x - start.x));
	pdc->Ellipse(rect);
	this->start = start;
	this->end = end;
	PaintText(pdc);
	delete penne;
}

void sCircle::DrawShape(CDC *pdc)
{
	CPen* penne = new CPen(lineType, lineThickness, lineColor);
	pdc->SelectObject(penne);
	rect.SetRect(start.x, start.y, start.x + (end.x - start.x), start.y + (end.x - start.x));
	rect.NormalizeRect();
	pdc->Ellipse(rect);
	PaintText(pdc);
	delete penne;
}

void sCircle::IsSelected(CDC *pdc)
{
	CPen* penne = new CPen(PS_DOT, 1, RGB(150,150,150));
	pdc->SelectObject(penne);
	pdc->Ellipse(rect);
	rect.NormalizeRect();
	PaintText(pdc);
	delete penne;
}

void sCircle::DrawAuxiliary(CDC *pdc, CPoint start, CPoint end)
{
	pdc->Ellipse(start.x, start.y, start.x + (end.x - start.x), start.y + (end.x - start.x));
}

string sCircle::ToString()
{
	CT2CA pszConvertedAnsiString (text);
	std::string strStd (pszConvertedAnsiString);
	return name
		+ "," + ltos(lineType)
		+ "," + ltos(lineThickness)
		+ "," + ltos(lineColor)
		+ "," + strStd //formatted text
		+ "," + ltos(start.x) + "," + ltos(start.y) 
		+ "," + ltos(end.x) + "," + ltos(end.y) 
		+ "\n";
}