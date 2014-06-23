#include "stdafx.h"
#include "sSquare.h"


sSquare::sSquare(CDC *pdc) : Shape(pdc)
{
	name = "Square";
}


sSquare::~sSquare(void)
{
}

void sSquare::DrawShape(CPoint start, CPoint end)
{
	drawField->Rectangle(start.x, start.y, start.x + (end.x - start.x), start.y + (end.x - start.x));
	this->start = start;
	this->end = end;
}

void sSquare::DrawAuxiliary(CPoint start, CPoint end)
{
	drawField->Rectangle(start.x, start.y, start.x + (end.x - start.x), start.y + (end.x - start.x));
}

string sSquare::ToString()
{
	return "Shape: " + name + "\r\n" +
		"Color: " + "Red" + "\r\n" +
		"Points: " + ltos(start.x) + ", " + ltos(start.y) + "; " +
		ltos(end.x) + ", " + ltos(end.y);
}