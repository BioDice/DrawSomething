#include "stdafx.h"
#include "sCircle.h"


sCircle::sCircle(CDC *pdc) : Shape(pdc)
{

}


sCircle::~sCircle(void)
{
}

void sCircle::DrawShape(CPoint start, CPoint end)
{
	drawField->Ellipse(start.x, start.y, start.x + (end.x - start.x), start.y + (end.x - start.x));
}

void sCircle::DrawAuxiliary(CPoint start, CPoint end)
{
	drawField->Ellipse(start.x, start.y, start.x + (end.x - start.x), start.y + (end.x - start.x));
}