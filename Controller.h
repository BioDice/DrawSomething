#pragma once
#include "MainFrm.h"
#include "Shape.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class Controller
{
public:
	static enum DrawShape{ None, Square, Rectangle, Circle, Ellipse, Polygon } Shapes;
	static enum ShapeColor{ 
							RED = RGB(255,0,0),
							GREEN = RGB(0,255,0),
							BLUE =  RGB(0,0,255),
							YELLOW = RGB(255,255,0) } Colors;

	std::vector<Shape*> shapes;
	ShapeColor currentColor;
	int currentLineThickness;
	int currentLineType;
	DrawShape currentShape;
	bool IsDrawingPolygon;
	bool selectTool;

private:
	CMainFrame *mainFrame;
	CChildView *view;
	
	
public:
	Controller();
	~Controller(void); 

	void setMainFrame(CMainFrame *mainFrame);
	void setView(CChildView *view);
	void UndoLastAction();
	void setShape(DrawShape shape);
	Shape* getShape(Shape* shape);
	void Save();
	void Open();
	void SetSelectedShapeColor(ShapeColor color);
	ShapeColor GetSelectedShapeColor();
	void SetShapeText(wchar_t ch);
	void SetSelectTool(bool value);
	bool GetSelectTool();
	void DeleteCurrentShape();
};

extern Controller *Ctrl;