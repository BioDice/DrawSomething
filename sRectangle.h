#pragma once
#include "shape.h"
class sRectangle :
	public Shape
{
public:
	sRectangle();
	sRectangle(CPoint start, CPoint end);
	~sRectangle(void);

	void DrawShape(CDC *pdc, CPoint start, CPoint end);
	void DrawShape(CDC *pdc);
	void DrawAuxiliary(CDC *pdc, CPoint start, CPoint end);
	string ToString();
	void IsSelected(CDC *pdc);
};

