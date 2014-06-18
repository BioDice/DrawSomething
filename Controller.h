#pragma once
#include "MainFrm.h"
#include "Shape.h"

class Controller
{
public:
	static enum DrawShape{None, Square, Rectangle, Circle, Ellipse} Shapes;

private:
	CMainFrame *mainFrame;
	CChildView *view;
	DrawShape currentShape;

public:
	Controller();
	~Controller(void); 

	void setMainFrame(CMainFrame *mainFrame);
	void setView(CChildView *view);

	void setShape(DrawShape shape);
	Shape* getShape(CDC *pdc);
	DrawShape getShape()
	{
		return currentShape;
	}

};

extern Controller *Ctrl;