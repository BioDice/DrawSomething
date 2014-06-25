#pragma once
#include "shape.h"
class sCircle :
	public Shape
{
public:
	sCircle();
	sCircle(CPoint start, CPoint end);
	~sCircle(void);
	void DrawShape(CDC *pdc, CPoint start, CPoint end);
	void DrawShape(CDC *pdc);
	void DrawAuxiliary(CDC *pdc, CPoint start, CPoint end);
	string ToString();
	void IsSelected(CDC *pdc);
};

