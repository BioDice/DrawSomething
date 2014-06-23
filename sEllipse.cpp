#include "stdafx.h"
#include "sEllipse.h"


sEllipse::sEllipse(CDC *pdc) : Shape(pdc)
{
	name = "Ellipse";
}


sEllipse::~sEllipse(void)
{
}

void sEllipse::DrawShape(CPoint start, CPoint end)
{
	drawField->Ellipse(start.x, start.y, end.x, end.y);
	this->start = start;
	this->end = end;
}

void sEllipse::DrawAuxiliary(CPoint start, CPoint end)
{
	drawField->Ellipse(start.x, start.y, end.x, end.y);
}

string sEllipse::ToString()
{
	return "Shape: " + name + "\r\n" +
		"Color: " + "Red" + "\r\n" +
		"Points: " + ltos(start.x) + ", " + ltos(start.y) + "; " +
		ltos(end.x) + ", " + ltos(end.y) + "\r\n";
}