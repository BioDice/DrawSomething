#include "stdafx.h"
#include "Resource.h"
#include "DrawSomething.h"
#include "Controller.h"
#include <vld.h>


Controller *Ctrl = 0;

Controller::Controller(void) : shapes()
{
	this->currentShape = None;
	this->currentLineType = PS_SOLID;
	this->currentLineThickness = 1;
	this->currentColor = Controller::ShapeColor::RED;
	this->IsDrawingPolygon = false;
	this->selectTool = false;
	this->connectTool = false;
}

Controller::~Controller(void)
{
	for ( int i = 0; i < shapes.size(); i++ ) 
    {       
        delete shapes[i];    
    }
    shapes.clear(); 
}

void Controller::setMainFrame(CMainFrame *mainFrame)
{
	this->mainFrame = mainFrame;
}

void Controller::setView(CChildView *view)
{
	this->view = view;
}

void Controller::SetSelectedShapeColor(ShapeColor color)
{
	this->currentColor = color;
	CToolBar *m = mainFrame->GetToolbar();

	m->GetToolBarCtrl().CheckButton(COLOR_GREEN, MF_BYCOMMAND | (color == ShapeColor::GREEN ? MF_CHECKED : MF_UNCHECKED));
	m->GetToolBarCtrl().CheckButton(COLOR_RED, MF_BYCOMMAND | (color == ShapeColor::RED ? MF_CHECKED : MF_UNCHECKED));
	m->GetToolBarCtrl().CheckButton(COLOR_BLUE, MF_BYCOMMAND | (color == ShapeColor::BLUE ? MF_CHECKED : MF_UNCHECKED));
	m->GetToolBarCtrl().CheckButton(COLOR_YELLOW, MF_BYCOMMAND | (color == ShapeColor::YELLOW ? MF_CHECKED : MF_UNCHECKED));
}

Controller::ShapeColor Controller::GetSelectedShapeColor()
{
	return currentColor;
}

void Controller::setShape(DrawShape shape)
{
	this->currentShape = shape;
	CMenu *m = mainFrame->GetMenu();

	m->CheckMenuItem(ID_SHAPE_SQUARE, MF_BYCOMMAND | (shape == Square ? MF_CHECKED : MF_UNCHECKED));
	m->CheckMenuItem(ID_SHAPE_ELLIPSE, MF_BYCOMMAND | (shape == Ellipse ? MF_CHECKED : MF_UNCHECKED));
	m->CheckMenuItem(ID_SHAPE_CIRCLE, MF_BYCOMMAND | (shape == Circle ? MF_CHECKED : MF_UNCHECKED));
	m->CheckMenuItem(ID_SHAPE_RECTANGLE, MF_BYCOMMAND | (shape == Rectangle ? MF_CHECKED : MF_UNCHECKED));
	m->CheckMenuItem(ID_SHAPE_POLYGON, MF_BYCOMMAND | (shape == Polygon ? MF_CHECKED : MF_UNCHECKED));
}

Shape* Controller::getShape(Shape* shape)
{
	if (this->currentShape == Rectangle)
	{
		shape = new sRectangle();
		shapes.emplace_back(shape);
		IsDrawingPolygon = false;
		return shape;
	}
	else if (this->currentShape == Circle)
	{
		shape = new sCircle();
		shapes.emplace_back(shape);
		IsDrawingPolygon = false;
		return shape;
	}
	else if (this->currentShape == Square)
	{
		shape = new sSquare();
		shapes.emplace_back(shape);
		IsDrawingPolygon = false;
		return shape;
	}
	else if (this->currentShape == Ellipse)
	{
		shape = new sEllipse();
		shapes.emplace_back(shape);
		IsDrawingPolygon = false;
		return shape;
	}
	else if (this->currentShape == Polygon)
	{
		if (!IsDrawingPolygon)
		{
			shape = new sPolygon();
			shapes.emplace_back(shape);
			IsDrawingPolygon = true;
			return shape;
		}
	}
	return NULL;	
}

void Controller::Save()
{
	CFileDialog* fd = new CFileDialog(false, _T("drsm"), _T("Untitled.drsm"));
	wstring fileName;

	fd->m_ofn.lpstrTitle = TEXT("Save file");
	fd->m_ofn.lpstrFilter = TEXT("Draw Something Files (*.drsm)");
	if (fd->DoModal() == IDOK)
	{
		fileName = fd->GetPathName();

		ofstream file;
		file.open(fileName);

		if (shapes.empty() == false)
		{
			for (auto i : shapes)
			{
				file << i->ToString() << endl;
			}
		}

		file.close();
	}
	delete fd;
}

void Controller::Open()
{
	shapes.clear();
	CFileDialog* fd = new CFileDialog(true, _T("drsm"), _T("Untitled.drsm"));
	wstring fileName;
	
	fd->m_ofn.lpstrTitle = TEXT("Open save file");
	fd->m_ofn.lpstrFilter = TEXT("Draw Something Files (*.drsm)");

	if (fd->DoModal() == IDOK)
	{
		fileName = fd->GetPathName();

		ifstream file(fileName);
		string rawline;

		view->Reset();

		while (getline(file, rawline))
		{
			if (!rawline.empty())
			{
				stringstream line(rawline);
				string seg;
				vector<string> segs;

				while (getline(line, seg, ','))
				{
					segs.push_back(seg);
				}

				string shapeType = segs[0];
				int lineType = stoi(segs[1]);
				int lineThickness = stoi(segs[2]);
				int lineColor = stoi(segs[3]);
				CString text(segs[4].c_str());
				CPoint startp(stoi(segs[5]), stoi(segs[6]));
				CPoint endp(stoi(segs[7]), stoi(segs[8]));
				
				Shape* shape;

				if (shapeType == "Circle")
				{
					shape = new sCircle(startp, endp);
				}
				else if (shapeType == "Rectangle")
				{
					shape = new sRectangle(startp, endp);
				}
				else if (shapeType == "Ellipse")
				{
					shape = new sEllipse(startp, endp);
				}
				else if (shapeType == "Square")
				{
					shape = new sSquare(startp, endp);
				}
				else if (shapeType == "Connector")
				{
					shape = new sConnector(startp, endp);
				}
				else if (shapeType == "Polygon")
				{
					shape = new sPolygon(startp, endp);
					for (int i = 5; i <= segs.size()-2; i++)
					{
						CPoint point(stoi(segs[i]), stoi(segs[i+1]));
						i += 1;
						shape->points.emplace_back(point);
					}
				}
				else
				{
					continue;
				}
				
				shape->lineType = lineType;
				shape->lineThickness = lineThickness;
				shape->lineColor = lineColor;
				shape->SetText(text);
				
				shapes.emplace_back(shape);
			}
		}
		
		view->RedrawShapes();
		file.close();
	}
	delete fd;
}

void Controller::UndoLastAction()
{
	if(!shapes.empty())
	{
		shapes.pop_back();
		view->RedrawShapes();
	}
}

void Controller::SetShapeText(wchar_t ch)
{	
	if(view->currentShape != NULL)
	{
		CString cstmp = view->currentShape->GetText();
		if(ch == '\b')
			cstmp.Delete(cstmp.GetLength()-1);
		else
			cstmp.AppendChar(ch);
		view->currentShape->text = cstmp;
		view->RedrawShapes();
	}
}

void Controller::SetSelectTool(bool value)
{
	this->selectTool = value;
	CToolBar *m = mainFrame->GetToolbar();
	if (value)
		this->connectTool = false;
	m->GetToolBarCtrl().CheckButton(SELECT_SHAPE_OBJECT, MF_BYCOMMAND | (this->selectTool == true ? MF_CHECKED : MF_UNCHECKED));
	m->GetToolBarCtrl().CheckButton(CONNECTOR, MF_BYCOMMAND | (this->connectTool == true ? MF_CHECKED : MF_UNCHECKED));
	if (!value && view->currentShape != NULL)
	{
		//delete view->currentShape;
		view->currentShape = NULL;
	}
}

bool Controller::GetSelectTool()
{
	return this->selectTool;
}

void Controller::DeleteCurrentShape()
{
	if (view->currentShape != NULL)
	{
		for (int i = 0; i < shapes.size(); i++)
		{
			if (shapes[i] == view->currentShape)
			{
				delete shapes[i];
				shapes.erase(shapes.begin() + i);
				view->currentShape = NULL;
				view->RedrawShapes();
				break;
			}
		}
	}
}

void Controller::SetConnectTool(bool value)
{
	this->connectTool = value;
	CToolBar *m = mainFrame->GetToolbar();
	if (value)
		this->selectTool = false;
	m->GetToolBarCtrl().CheckButton(SELECT_SHAPE_OBJECT, MF_BYCOMMAND | (this->selectTool == true ? MF_CHECKED : MF_UNCHECKED));
	m->GetToolBarCtrl().CheckButton(CONNECTOR, MF_BYCOMMAND | (this->connectTool == true ? MF_CHECKED : MF_UNCHECKED));
}

bool Controller::GetConnectTool()
{
	return connectTool;
}