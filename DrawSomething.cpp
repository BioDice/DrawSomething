
// DrawSomething.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "DrawSomething.h"
#include "Controller.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawSomethingApp

BEGIN_MESSAGE_MAP(CDrawSomethingApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CDrawSomethingApp::OnAppAbout)
	ON_COMMAND(ID_SHAPE_RECTANGLE, &CDrawSomethingApp::OnShapeRectangle)
	ON_COMMAND(ID_SHAPE_CIRCLE, &CDrawSomethingApp::OnShapeCircle)
	ON_COMMAND(ID_SHAPE_SQUARE, &CDrawSomethingApp::OnShapeSquare)
	ON_COMMAND(ID_SHAPE_ELLIPSE, &CDrawSomethingApp::OnShapeEllipse)
	ON_COMMAND(ID_SHAPE_POLYGON, &CDrawSomethingApp::OnShapePolygon)
	ON_COMMAND(ID_FILE_SAVE32776, &CDrawSomethingApp::OnFileSave32776)
	ON_COMMAND(ID_FILE_OPEN32777, &CDrawSomethingApp::OnFileOpen32777)
	ON_COMMAND(COLOR_GREEN, &CDrawSomethingApp::ShapeColorGreen)
	ON_COMMAND(COLOR_RED, &CDrawSomethingApp::ShapeColorRed)
	ON_COMMAND(COLOR_BLUE, &CDrawSomethingApp::ShapeColorBlue)
	ON_COMMAND(COLOR_YELLOW, &CDrawSomethingApp::ShapeColorYellow)
	ON_COMMAND(LINE_TYPE, &CDrawSomethingApp::LineType)
	ON_COMMAND(INCREMENT_LINE_THICKNESS, &CDrawSomethingApp::IncrLineThickness)
	ON_COMMAND(DECREASE_LINE_THICKNESS, &CDrawSomethingApp::DecrLineThickness)
	ON_COMMAND(SELECT_SHAPE_OBJECT, &CDrawSomethingApp::SelectShapeObject)
	ON_COMMAND(ID_EDIT_UNDO, &CDrawSomethingApp::OnEditUndo)
	ON_COMMAND(DELETE_SHAPE, &CDrawSomethingApp::DeleteShape)
	ON_COMMAND(CONNECTOR, &CDrawSomethingApp::Connector)
END_MESSAGE_MAP()


// CDrawSomethingApp construction

CDrawSomethingApp::CDrawSomethingApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// If the application is built using Common Language Runtime support (/clr):
	//     1) This additional setting is needed for Restart Manager support to work properly.
	//     2) In your project, you must add a reference to System.Windows.Forms in order to build.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("DrawSomething.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CDrawSomethingApp object

CDrawSomethingApp theApp;

// CDrawSomethingApp initialization

BOOL CDrawSomethingApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// AfxInitRichEdit2() is required to use RichEdit control	
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));


	// To create the main window, this code creates a new frame window
	// object and then sets it as the application's main window object
	CMainFrame* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// create and load the frame with its resources
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);

	// The one and only window has been initialized, so show and update it
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	
	return TRUE;
}

int CDrawSomethingApp::ExitInstance()
{
	//TODO: handle additional resources you may have added
	delete m_pMainWnd;
	AfxOleTerm(FALSE);
	delete Ctrl;
	return CWinApp::ExitInstance();
}

// CDrawSomethingApp message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// App command to run the dialog
void CDrawSomethingApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();

}

// CDrawSomethingApp message handlers

void CDrawSomethingApp::OnShapeRectangle()
{
	Ctrl->setShape(Controller::DrawShape::Rectangle);
}


void CDrawSomethingApp::OnShapeCircle()
{
	Ctrl->setShape(Controller::DrawShape::Circle);
}


void CDrawSomethingApp::OnShapeSquare()
{
	Ctrl->setShape(Controller::DrawShape::Square);
}


void CDrawSomethingApp::OnShapeEllipse()
{
	Ctrl->setShape(Controller::DrawShape::Ellipse);
}

void CDrawSomethingApp::OnShapePolygon()
{
	Ctrl->setShape(Controller::DrawShape::Polygon);
}

void CDrawSomethingApp::OnFileSave32776()
{
	Ctrl->Save();
}


void CDrawSomethingApp::OnFileOpen32777()
{
	Ctrl->Open();
}

void CDrawSomethingApp::ShapeColorGreen()
{
	Ctrl->SetSelectedShapeColor(Controller::ShapeColor::GREEN);
}

void CDrawSomethingApp::ShapeColorBlue()
{
	Ctrl->SetSelectedShapeColor(Controller::ShapeColor::BLUE);
}

void CDrawSomethingApp::ShapeColorRed()
{
	Ctrl->SetSelectedShapeColor(Controller::ShapeColor::RED);
}

void CDrawSomethingApp::ShapeColorYellow()
{
	Ctrl->SetSelectedShapeColor(Controller::ShapeColor::YELLOW);
}

void CDrawSomethingApp::LineType()
{
	if (Ctrl->currentLineType == PS_SOLID)
		Ctrl->currentLineType = PS_DOT;
	else
		Ctrl->currentLineType = PS_SOLID;
}

void CDrawSomethingApp::IncrLineThickness()
{
	Ctrl->currentLineThickness++;
}

void CDrawSomethingApp::DecrLineThickness()
{
	if (Ctrl->currentLineThickness > 1)
		Ctrl->currentLineThickness--;
}

void CDrawSomethingApp::SelectShapeObject()
{
	if (!Ctrl->GetSelectTool())
		Ctrl->SetSelectTool(true);
	else
		Ctrl->SetSelectTool(false);
}

void CDrawSomethingApp::OnEditUndo()
{
	Ctrl->UndoLastAction();
}

void CDrawSomethingApp::DeleteShape()
{
	Ctrl->DeleteCurrentShape();
}

void CDrawSomethingApp::Connector()
{
	if (!Ctrl->GetConnectTool())
		Ctrl->SetConnectTool(true);
	else
		Ctrl->SetConnectTool(false);
}
