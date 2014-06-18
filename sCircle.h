#pragma once
#include "shape.h"
class sCircle :
	public Shape
{
public:
	sCircle(CDC *pdc);
	~sCircle(void);
	void DrawShape(CPoint start, CPoint end);
	void DrawAuxiliary(CPoint start, CPoint end);
};

