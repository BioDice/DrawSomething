#pragma once
#include "shape.h"

class sSquare :
	public Shape
{
public:
	sSquare(CDC *pdc);
	~sSquare(void);
	void DrawShape(CPoint start, CPoint end);
	void DrawAuxiliary(CPoint start, CPoint end);
};

