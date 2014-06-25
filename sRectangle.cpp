#include "stdafx.h"
#include "sRectangle.h"


sRectangle::sRectangle()
{
	name = "Rectangle";
}

sRectangle::sRectangle(CPoint start, CPoint end)
{
	name = "Rectangle";
	this->start = start;
	this->end = end;
}

sRectangle::~sRectangle(void)
{
}

void sRectangle::DrawShape(CDC *pdc, CPoint start, CPoint end)
{
	CPen* penne = new CPen(lineType, lineThickness, lineColor);
	pdc->SelectObject(penne);
	pdc->SetROP2(R2_COPYPEN);
	rect.SetRect(start.x, start.y, end.x, end.y);
	rect.NormalizeRect();
	pdc->Rectangle(rect);
	this->start = start;
	this->end = end;
	PaintText(pdc);
	delete penne;
}

void sRectangle::DrawShape(CDC *pdc)
{
	CPen* penne = new CPen(lineType, lineThickness, lineColor);
	pdc->SelectObject(penne);
	pdc->SetROP2(R2_COPYPEN);
	rect.SetRect(start.x, start.y, end.x, end.y);
	rect.NormalizeRect();
	pdc->Rectangle(rect);
	PaintText(pdc);
	delete penne;
}

void sRectangle::IsSelected(CDC *pdc)
{
	CPen* penne = new CPen(PS_DOT, 1, RGB(150,150,150));
	pdc->SelectObject(penne);
	pdc->Rectangle(rect);
	PaintText(pdc);
	delete penne;
}

void sRectangle::DrawAuxiliary(CDC *pdc, CPoint start, CPoint end)
{
	pdc->Rectangle(start.x, start.y, end.x, end.y);
}

string sRectangle::ToString()
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