#include "stdafx.h"
#include "sCircle.h"


sCircle::sCircle(CDC *pdc) : Shape(pdc)
{
	name = "Circle";
}

sCircle::~sCircle(void)
{
}

void sCircle::DrawShape(CPoint start, CPoint end)
{
	drawField->Ellipse(start.x, start.y, start.x + (end.x - start.x), start.y + (end.x - start.x));
	this->start = start;
	this->end = end;
	//Ctrl->shapes.emplace_back(this);
}

void sCircle::DrawAuxiliary(CPoint start, CPoint end)
{
	drawField->Ellipse(start.x, start.y, start.x + (end.x - start.x), start.y + (end.x - start.x));
}

string sCircle::ToString()
{
	return "Shape: " + name + "\r\n" +
		"Color: " + "Red" + "\r\n" +
		"Points: " + ltos(start.x) + ", " + ltos(start.y) + "; " +
		ltos(end.x) + ", " + ltos(end.y);
}