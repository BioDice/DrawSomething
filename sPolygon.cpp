#include "stdafx.h"
#include "sPolygon.h"


sPolygon::sPolygon()
{
	name = "Polygon";
}

sPolygon::sPolygon(CPoint start, CPoint end)
{
	name = "Polygon";
	this->start = start;
	this->end = end;
}


sPolygon::~sPolygon(void)
{
}

void sPolygon::DrawShape(CDC *pdc, CPoint start, CPoint end)
{
	CPen* penne = new CPen(lineType, lineThickness, lineColor);
	pdc->SelectObject(penne);
	pdc->MoveTo(start);
	pdc->LineTo(end);
	if (points.size() == 0)
		points.emplace_back(start);
	points.emplace_back(end);
}

void sPolygon::DrawShape(CDC *pdc)
{
	CPen* penne = new CPen(lineType, lineThickness, lineColor);
	pdc->SelectObject(penne);
	pdc->MoveTo(start);
	pdc->LineTo(end);

	for (int i = 0; i <= points.size()-2; i++)
	{
		pdc->MoveTo(points[i]);
		pdc->LineTo(points[i+1]);
	}
}

void sPolygon::DrawAuxiliary(CDC *pdc, CPoint start, CPoint end)
{
	pdc->MoveTo(start);
	pdc->LineTo(end);
}

string sPolygon::ToString()
{
	CT2CA pszConvertedAnsiString (text);
	std::string strStd (pszConvertedAnsiString);
	string ret = name
		+ "," + ltos(lineType)
		+ "," + ltos(lineThickness)
		+ "," + ltos(lineColor)
		+ "," + strStd;
	 for (int i = 0; i < points.size(); i++)
	 {
		 ret += "," + ltos(points[i].x) + "," + ltos(points[i].y);
	 }

	 ret += "\n";

	 return ret;
}