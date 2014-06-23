#include "stdafx.h"
#include "sRectangle.h"


sRectangle::sRectangle(CDC *pdc) : Shape(pdc)
{
	name = "Rectangle";
}

sRectangle::~sRectangle(void)
{
}

void sRectangle::DrawShape(CPoint start, CPoint end)
{
	drawField->Rectangle(start.x, start.y, end.x, end.y);
	this->start = start;
	this->end = end;
}

void sRectangle::DrawAuxiliary(CPoint start, CPoint end)
{
	drawField->Rectangle(start.x, start.y, end.x, end.y);
}

string sRectangle::ToString()
{
	return "Shape: " + name + "\r\n" +
		"Color: " + "Red" + "\r\n" +
		"Points: " + ltos(start.x) + ", " + ltos(start.y) + "; " +
		ltos(end.x) + ", " + ltos(end.y);
}