// Trinity Of Warcraft.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Trinity Of Warcraft.h"
#include <windows.h>
#include <string>
#include <iostream>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_TRINITYOFWARCRAFT, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TRINITYOFWARCRAFT));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TRINITYOFWARCRAFT));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_TRINITYOFWARCRAFT);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	
	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }
   
   
   ShowWindow(hWnd, nCmdShow);
   RECT rect;
	GetWindowRect(hWnd, &rect);
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;

	/*if (WM_LBUTTONDOWN == true)
	{
		CreateWindowEx(NULL, L"Edit", L"", WS_VISIBLE | WS_CHILD, width / 2.2f, height / 2.2f, 200, 20, hWnd, NULL, hInstance, NULL);
		UpdateWindow(hWnd);
	}
	else
	{
		CreateWindowEx(NULL, L"Edit", L"Username", WS_VISIBLE | WS_CHILD, width / 2.2f, height / 2.2f, 200, 20, hWnd, NULL, hInstance, NULL);
		UpdateWindow(hWnd);
	}*/

   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;		
	static HBITMAP bmpSource = NULL;
    static HDC hdcSource = NULL;     
    HDC hdcDestination;
	RECT rect;
	std::cout << "fhgfghfghfga";

	GetWindowRect(hWnd, &rect);
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;
	hdcDestination = BeginPaint(hWnd, &ps);
	bmpSource = (HBITMAP)LoadImage(NULL, L".\\data\\images\\bg.bmp", IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
    hdcSource = CreateCompatibleDC(GetDC(0));
    SelectObject(hdcSource, bmpSource);
	BitBlt(hdcDestination, 0, 0, width, height, hdcSource, 0, 0, SRCCOPY);

	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;	
		
	}	

	return DefWindowProc(hWnd, message, wParam, lParam);
}


