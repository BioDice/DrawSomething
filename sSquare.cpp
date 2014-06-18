#include "stdafx.h"
#include "sSquare.h"


sSquare::sSquare(CDC *pdc) : Shape(pdc)
{
}


sSquare::~sSquare(void)
{
}

void sSquare::DrawShape(CPoint start, CPoint end)
{
	drawField->Rectangle(start.x, start.y, start.x + (end.x - start.x), start.y + (end.x - start.x));
}

void sSquare::DrawAuxiliary(CPoint start, CPoint end)
{
	drawField->Rectangle(start.x, start.y, start.x + (end.x - start.x), start.y + (end.x - start.x));
}