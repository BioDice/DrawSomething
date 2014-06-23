#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Shape
{
protected:
	CDC *drawField;

public:
	CPoint start, end;
	string name;

public:
	Shape(CDC *pdc);
	~Shape(void);

	string ltos(long l)
	{
		ostringstream s;
		s << l;

		return s.str();
	};

	virtual void DrawShape(CPoint start, CPoint end);
	virtual void DrawAuxiliary(CPoint start, CPoint end);
	virtual string ToString();
};

