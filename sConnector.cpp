#include "stdafx.h"
#include "sConnector.h"

sConnector::sConnector()
{
	name = "Connector";
	this->lineColor = RGB(0,0,0);
	this->lineThickness = 1;
	this->lineType = BS_SOLID;
}

sConnector::sConnector(CPoint start, CPoint end)
{
	name = "Connector";
	this->lineColor = RGB(0,0,0);
	this->lineThickness = 1;
	this->lineType = BS_SOLID;
	this->start = start;
	this->end = end;
}

sConnector::~sConnector(void)
{
}

void sConnector::DrawShape(CDC *pdc, CPoint start, CPoint end)
{
	CPen* penne = new CPen(lineType, lineThickness, lineColor);
	pdc->SelectObject(penne);
	pdc->MoveTo(start);
	pdc->LineTo(end);
	this->start = start;
	this->end = end;
	delete penne;
}

void sConnector::DrawShape(CDC *pdc)
{
	CPen* penne = new CPen(lineType, lineThickness, lineColor);
	pdc->SelectObject(penne);
	pdc->MoveTo(start);
	pdc->LineTo(end);
	this->start = start;
	this->end = end;
	delete penne;
}

string sConnector::ToString()
{
	CT2CA pszConvertedAnsiString (text);
	std::string strStd (pszConvertedAnsiString);
	return name
		+ "," + ltos(lineType)
		+ "," + ltos(lineThickness)
		+ "," + ltos(lineColor)
		+ "," + strStd //formatted text
		+ "," + ltos(start.x) + "," + ltos(start.y) 
		+ "," + ltos(end.x) + "," + ltos(end.y) 
		+ "\n";
}