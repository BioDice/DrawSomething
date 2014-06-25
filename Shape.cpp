#include "stdafx.h"
#include "Shape.h"

Shape::Shape()
{

}

Shape::~Shape(void)
{

}

void Shape::DrawShape(CDC *pdc, CPoint start, CPoint end) { }

void Shape::DrawShape(CDC *pdc) { }

void Shape::DrawAuxiliary(CDC *pdc, CPoint start, CPoint end) { }

string Shape::ToString() { return nullptr; }

bool Shape::IsOn(CPoint point)
{
	return rect.PtInRect(point);
};

void Shape::IsSelected(CDC *pdc)
{
	
}

void Shape::SetLineWidth(int width)
{
	this->lineThickness = width;
}

int Shape::GetLineWidth()
{
	return this->lineThickness;
}

CString Shape::GetText()
{
	return text;
}

void Shape::SetText(CString text)
{
	this->text = text;
}

void Shape::PaintText(CDC *pdc)
{
	if(!text.IsEmpty())
	{
		pdc->SetTextAlign(TA_CENTER);
		int tmpx = start.x + ((end.x - start.x)/2);
		int tmpy = start.y + ((end.y - start.y)/2);
		pdc->TextOutW(tmpx, tmpy , text);
	}
}

CPen* Shape::CreatePen()
{
	CPen pen;
	pen.CreatePen(this->lineType, this->lineThickness, this->lineColor);
	return &pen;
}

string Shape::GetName()
{
	return name;
}