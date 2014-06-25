#pragma once
#include "shape.h"

class sSquare :
	public Shape
{
public:
	sSquare();
	sSquare(CPoint start, CPoint end);
	~sSquare(void);
	void DrawShape(CDC *pdc, CPoint start, CPoint end);
	void DrawShape(CDC *pdc);
	void DrawAuxiliary(CDC *pdc, CPoint start, CPoint end);
	string ToString();
	void IsSelected(CDC *pdc);
};

