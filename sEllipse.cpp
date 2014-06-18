#include "stdafx.h"
#include "sEllipse.h"


sEllipse::sEllipse(CDC *pdc) : Shape(pdc)
{
}


sEllipse::~sEllipse(void)
{
}



void sEllipse::DrawShape(CPoint start, CPoint end)
{
	drawField->Ellipse(start.x, start.y, end.x, end.y);
}

void sEllipse::DrawAuxiliary(CPoint start, CPoint end)
{
	drawField->Ellipse(start.x, start.y, end.x, end.y);
}