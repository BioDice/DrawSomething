#pragma once
#include "shape.h"

class sEllipse :
	public Shape
{
public:
	sEllipse();
	sEllipse(CPoint start, CPoint end);
	~sEllipse(void);
	void DrawShape(CDC *pdc, CPoint start, CPoint end);
	void DrawShape(CDC *pdc);
	void DrawAuxiliary(CDC *pdc, CPoint start, CPoint end);
	string ToString();
	void IsSelected(CDC *pdc);
};

