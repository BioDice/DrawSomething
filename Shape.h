#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Shape
{
protected:
	CPoint start, end;
	CRect rect;
	string name;
	
	

public:
	int lineType;
	int lineThickness;
	int lineColor;
	CString text;

public:
	Shape();
	~Shape(void);

	string ltos(long l)
	{
		ostringstream s;
		s << l;

		return s.str();
	};

	virtual void DrawShape(CDC *pdc, CPoint start, CPoint end);
	virtual void DrawShape(CDC *pdc);
	virtual void DrawAuxiliary(CDC *pdc, CPoint start, CPoint end);
	virtual string ToString();
	CRect GetRect() { return rect; };
	bool IsOn(CPoint point);
	void SetLineWidth(int width);
	int GetLineWidth();
	CString GetText();
	void SetText(CString text);
	CPen* CreatePen();
	vector<CPoint> points;
	void PaintText(CDC *pdc);
	string GetName();
	virtual void IsSelected(CDC *pdc);
};

