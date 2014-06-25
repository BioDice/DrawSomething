#include "stdafx.h"
#include "sSquare.h"


sSquare::sSquare()
{
	name = "Square";
}

sSquare::sSquare(CPoint start, CPoint end)
{
	name = "Square";
	this->start = start;
	this->end = end;
}

sSquare::~sSquare(void)
{
}

void sSquare::DrawShape(CDC *pdc, CPoint start, CPoint end)
{
	CPen* penne = new CPen(lineType, lineThickness, lineColor);
	pdc->SelectObject(penne);
	rect.SetRect(start.x, start.y, start.x + (end.x - start.x), start.y + (end.x - start.x));
	pdc->Rectangle(rect);
	this->start = start;
	this->end = end;
	PaintText(pdc);
	delete penne;
}

void sSquare::DrawShape(CDC *pdc)
{
	CPen* penne = new CPen(lineType, lineThickness, lineColor);
	pdc->SelectObject(penne);
	rect.SetRect(start.x, start.y, start.x + (end.x - start.x), start.y + (end.x - start.x));
	pdc->Rectangle(rect);
	PaintText(pdc);
	delete penne;
}

void sSquare::IsSelected(CDC *pdc)
{
	CPen* penne = new CPen(PS_DOT, 1, RGB(150,150,150));
	pdc->SelectObject(penne);
	pdc->Rectangle(rect);
	PaintText(pdc);
	delete penne;
}

void sSquare::DrawAuxiliary(CDC *pdc, CPoint start, CPoint end)
{
	pdc->Rectangle(start.x, start.y, start.x + (end.x - start.x), start.y + (end.x - start.x));
}

string sSquare::ToString()
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