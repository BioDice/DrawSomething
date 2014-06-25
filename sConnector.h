#pragma once
#include "shape.h"
class sConnector :
	public Shape
{
public:
	sConnector();
	sConnector(CPoint start, CPoint end);
	~sConnector(void);
	void DrawShape(CDC *pdc, CPoint start, CPoint end);
	void DrawShape(CDC *pdc);
	string ToString();
};

