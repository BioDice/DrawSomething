#pragma once
#include "shape.h"
#include <vector>

using namespace std;

class sPolygon :
	public Shape
{
public:

public:
	sPolygon();
	sPolygon(CPoint start, CPoint end);
	~sPolygon(void);
	void DrawShape(CDC *pdc, CPoint start, CPoint end);
	void DrawShape(CDC *pdc);
	void DrawAuxiliary(CDC *pdc, CPoint start, CPoint end);
	string ToString();
};

