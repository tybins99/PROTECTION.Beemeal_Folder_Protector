#include "stdafx.h"
#include "argv_110.h"
#include "argv_112.h"
#include "..\\Lib\\argv_118.hpp"

using namespace std;

argv_157 logger;

bool				argv_495				= false;
bool				argv_213	= false;
HWND				argv_567;
string				argv_206			= "";
LRESULT CALLBACK	argv_127(HWND, UINT, WPARAM, LPARAM);
string				argv_191					= "48elfrad73";

// Global Variables:
#define		argv_507 100
HINSTANCE	argv_214;								// argv_173 instance
TCHAR		argv_580[argv_507];			// The title bar text
TCHAR		argv_581[argv_507];		// The title bar text

ATOM				argv_521(HINSTANCE hInstance);
BOOL				argv_474(HINSTANCE, int);
LRESULT CALLBACK	argv_598(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	argv_127(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	MSG msg;
	HACCEL hAccelTable;
	LoadString(hInstance, argv_472, argv_580, argv_507);
	LoadString(hInstance, argv_449, argv_581, argv_507);
	argv_521(hInstance);

	if (!argv_474 (hInstance, nCmdShow))  {
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)argv_449);
	while (GetMessage(&msg, NULL, 0, 0))  {
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))  {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return msg.wParam;
}

ATOM argv_521(HINSTANCE hInstance) {
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX); 
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)argv_598;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)argv_466);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)argv_449;
	wcex.lpszClassName	= argv_581;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)argv_464);
	return RegisterClassEx(&wcex);
}

bool argv_186 (const string& _filename) {
	bool bret = true;

	FILE * argv_190 = fopen (_filename.c_str(), "rb");
	if (!argv_190) {
		bret = false;
	}
	else {
		fclose(argv_190);
	}	

	return(bret);
}

BOOL argv_474(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	argv_214 = hInstance; // Store instance handle in our global variable

	hWnd = CreateWindow(argv_581, argv_580, WS_VISIBLE | WS_OVERLAPPEDWINDOW,
	  CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
	  return FALSE;
	}

	ShowWindow(hWnd, SW_SHOWMINIMIZED);
	UpdateWindow(hWnd);
	argv_567 = hWnd;

	DialogBox(argv_214, (LPCTSTR)argv_450, hWnd, (DLGPROC)argv_127);
	DestroyWindow(hWnd);
	return TRUE;
}

HDC argv_205;

LRESULT CALLBACK argv_598(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT argv_555;
	HDC argv_210;
	
	TCHAR szHello[argv_507];
	LoadString(argv_214, argv_473, szHello, argv_507);

	switch (message) 
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case argv_468:
				   DialogBox(argv_214, (LPCTSTR)argv_450, hWnd, (DLGPROC)argv_127);
				   break;
				case argv_469:
				   DestroyWindow(hWnd);
				   break;

				case argv_470:
					argv_530(hWnd,argv_531);
					break;

				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_PAINT:
			argv_210 = BeginPaint(hWnd, &argv_555);
			argv_205 = argv_210;
			// TODO: Add any drawing code here...
			RECT rt;
			GetClientRect(hWnd, &rt);
			DrawText(argv_210, szHello, strlen(szHello), &rt, DT_CENTER);
			EndPaint(hWnd, &argv_555);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}


void argv_546 () {
	string folder_plain_name = argv_155 (argv_567);
	if (folder_plain_name != "") {
		argv_586 size = folder_plain_name.size();
		if ((size >= 2) && (folder_plain_name[size-2]=='.') && (folder_plain_name[size-1]=='.')) {
			MessageBox (NULL, "Folder Already Protected !", "", MB_ICONERROR);	
		}
		else {
			string folder_ciphered_name = folder_plain_name + "...\\";
			if (MoveFile (folder_plain_name.c_str(), folder_ciphered_name.c_str()) != 0) {
				MessageBox (NULL, "Folder protected Succesfully", "", MB_OK);
			}
			else {
				MessageBox (NULL, "Failed to protect Folder !", "", MB_ICONERROR);
			}
		}
	}
}


//string plain_name		= "C:\\TEMP\\zzz";
//string ciphered_name	= plain_name + "...\\";
//string folder_name	= "C:\\TEMP\\zzz...\\";
void argv_591 () {
	string folder_ciphered_name = argv_155 (argv_567);
	if (folder_ciphered_name != "") {
		string folder_plain_name = "";
		if (argv_479() == false) {
			folder_ciphered_name += ".\\"; // correct the folder name
		}
		else {
			folder_ciphered_name += "...\\"; // correct the folder name
		}
		argv_586 size = folder_ciphered_name.size ();
		// modify the folder name to remove the dots
		for (argv_586 i=0 ; i<size ; i++) {
			if (folder_ciphered_name[i]=='.') {
				break;
			}
			folder_plain_name += folder_ciphered_name[i];
		}

		if (MoveFile (folder_ciphered_name.c_str(), folder_plain_name.c_str()) != 0) {
			MessageBox (NULL, "Folder unprotected Succesfully", "", MB_OK);
		}
		else {
			MessageBox (NULL, "Failed to unprotect Folder ! (Are you sure it was protected ?)", "", MB_ICONERROR);
		}
	}
}

LRESULT CALLBACK argv_127(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)
	{
		case WM_INITDIALOG:
			argv_567 = hDlg;
			argv_150 (hDlg);
			SendDlgItemMessage (hDlg, argv_285, WM_SETTEXT, 0, (LPARAM) "");
			SendDlgItemMessage (hDlg, argv_372, WM_SETTEXT, 0, (LPARAM) "Ready (Strong shadowing version)");
			logger.argv_537 ("C:\\log.txt");
			return TRUE;

		case WM_COMMAND:
			switch(LOWORD(wParam)) {
				case IDOK:
				case IDCANCEL:
					ShowWindow (hDlg, SW_SHOW);
					EndDialog(hDlg, LOWORD(wParam));
					return TRUE;
				break;

				case argv_366:
					argv_546 ();
					break;

				case argv_391:
					argv_591 ();
					break;
			}
	}
	return FALSE;
}