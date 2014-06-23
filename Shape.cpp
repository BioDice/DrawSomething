#include "stdafx.h"
#include "Shape.h"


Shape::Shape(CDC *pdc)
{
	this->drawField = pdc;
}


Shape::~Shape(void)
{

}

void Shape::DrawShape(CPoint start, CPoint end) { }

void Shape::DrawAuxiliary(CPoint start, CPoint end) { }

string Shape::ToString() { return nullptr; }