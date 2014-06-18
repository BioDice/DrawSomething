#pragma once
class Shape
{
protected:
	CDC *drawField;

public:
	Shape(CDC *pdc);
	~Shape(void);

	virtual void DrawShape(CPoint start, CPoint end);
	virtual void DrawAuxiliary(CPoint start, CPoint end);
};

