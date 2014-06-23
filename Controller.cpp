#include "stdafx.h"
#include "Resource.h"
#include "DrawSomething.h"
#include "Controller.h"
#include "sRectangle.h"
#include "sCircle.h"
#include "sSquare.h"
#include "sEllipse.h"

Controller *Ctrl = 0;

Controller::Controller(void) : shapes()
{
	this->currentShape = None;
}

Controller::~Controller(void)
{
	delete Ctrl;
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
		shapes.emplace_back(shape);
		return shape;
	}
	else if (this->currentShape == Circle)
	{
		shape = new sCircle(pdc);
		shapes.emplace_back(shape);
		return shape;
	}
	else if (this->currentShape == Square)
	{
		shape = new sSquare(pdc);
		shapes.emplace_back(shape);
		return shape;
	}
	else if (this->currentShape == Ellipse)
	{
		shape = new sEllipse(pdc);
		shapes.emplace_back(shape);
		return shape;
	}

	return nullptr;	
}

void Controller::Save()
{
	CFileDialog* fd = new CFileDialog(false, _T("drsm"), _T("*.drsm"));
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

		delete fd;
	}
}

void Controller::Save()
{
	CFileDialog* fd = new CFileDialog(true, _T("jfd"), _T("*.jfd"));
	wstring fileName;

	fd->m_ofn.lpstrTitle = TEXT("Open save file");
	fd->m_ofn.lpstrFilter = TEXT("JFDraw Files (*.jfd)");

	if (fd->DoModal() == IDOK)
	{
		fileName = fd->GetPathName();

		ifstream file(fileName);
		string rawline;

		//CChildView::Reset();

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

				if (segs.size() != 7)
				{
					continue;
				}

				CPoint startp(stoi(segs[1]), stoi(segs[2]));
				CPoint endp(stoi(segs[3]), stoi(segs[4]));
				int penWidth = stoi(segs[5]);
				string text = segs[6];

				Shape* shape;

				if (segs[0] == "Circle")
				{
					shape = new sCircle(startp, endp);
				}
				else if (segs[0] == "Rectangle")
				{
					shape = new sRectangle(startp, endp);
				}
				else if (segs[0] == "Ellipse")
				{
					shape = new sEllipse(startp, endp);
				}
				else if (segs[0] == "Square")
				{
					shape = new sSquare(startp, endp);
				}
				else
				{
					continue;
				}

				shape->SetPenWidth(penWidth);
				shape->SetText(text);

				shapes.push_back(shape);
			}
		}
 
		RedrawShapes();
		file.close();
	}
}