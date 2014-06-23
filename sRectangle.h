#pragma once
#include "shape.h"
class sRectangle :
	public Shape
{
public:
	sRectangle(CDC *pdc);
	~sRectangle(void);

	void DrawShape(CPoint start, CPoint end);
	void DrawAuxiliary(CPoint start, CPoint end);
	string ToString();
};

