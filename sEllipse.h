#pragma once
#include "shape.h"

class sEllipse :
	public Shape
{
public:
	sEllipse(CDC *pdc);
	~sEllipse(void);
	void DrawShape(CPoint start, CPoint end);
	void DrawAuxiliary(CPoint start, CPoint end);
};

