#include "stdafx.h"
#include "sRectangle.h"


sRectangle::sRectangle(CDC *pdc) : Shape(pdc)
{
}


sRectangle::~sRectangle(void)
{
}

void sRectangle::DrawShape(CPoint start, CPoint end)
{
	drawField->Rectangle(start.x, start.y, end.x, end.y);
}

void sRectangle::DrawAuxiliary(CPoint start, CPoint end)
{
	drawField->Rectangle(start.x, start.y, end.x, end.y);
}