#include "stdafx.h"
#include "Resource.h"
#include "DrawSomething.h"
#include "Controller.h"
#include "sRectangle.h"
#include "sCircle.h"
#include "sSquare.h"
#include "sEllipse.h"

Controller *Ctrl = 0;

Controller::Controller(void)
{
	this->currentShape = None;
}


Controller::~Controller(void)
{
}

void Controller::setMainFrame(CMainFrame *mainFrame)
{
	this->mainFrame = mainFrame;
}

void Controller::setView(CChildView *view)
{
	this->view = view;
}

void Controller::setShape(DrawShape shape)
{
	this->currentShape = shape;
	CMenu *m = mainFrame->GetMenu();

	m->CheckMenuItem(ID_SHAPE_SQUARE, MF_BYCOMMAND | (shape == Square ? MF_CHECKED : MF_UNCHECKED));
	m->CheckMenuItem(ID_SHAPE_ELLIPSE, MF_BYCOMMAND | (shape == Ellipse ? MF_CHECKED : MF_UNCHECKED));
	m->CheckMenuItem(ID_SHAPE_CIRCLE, MF_BYCOMMAND | (shape == Circle ? MF_CHECKED : MF_UNCHECKED));
	m->CheckMenuItem(ID_SHAPE_RECTANGLE, MF_BYCOMMAND | (shape == Rectangle ? MF_CHECKED : MF_UNCHECKED));
}

Shape* Controller::getShape(CDC *pdc)
{
	Shape *shape;
	if (this->currentShape == Rectangle)
	{
		shape = new sRectangle(pdc);
		return shape;
	}
	else if (this->currentShape == Circle)
	{
		shape = new sCircle(pdc);
		return shape;
	}
	else if (this->currentShape == Square)
	{
		shape = new sSquare(pdc);
		return shape;
	}
	else if (this->currentShape == Ellipse)
	{
		shape = new sEllipse(pdc);
		return shape;
	}

	return nullptr;
		
}