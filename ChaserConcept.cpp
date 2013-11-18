// ChaserConcept.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ChaserConcept.h"
#include "rgb.h"
#include "pixel.h"
#include "chaser.h"
#include <iostream>
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;
	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: change error code to suit your needs
			_tprintf(_T("Fatal Error: MFC initialization failed\n"));
			nRetCode = 1;
		}
		else
		{
			pixel pixels[2];
			_tprintf(_T("Created Pixels\n"));

			//First pixel
			pixels[0].colorDest = new rgb(100, 0, 0);
			pixels[0].colorSrc = new rgb(0, 0, 0);
			pixels[0].direction = 1;//going forward
			pixels[0].jumpInterval = 1;
			pixels[0].position = -1; //one before the start of the strip
			_tprintf(_T("Pixels[0] initialized\n"));

			//second pixel
			pixels[1].colorDest = new rgb(100, 0, 0);
			pixels[1].colorSrc = new rgb(0, 0, 0);
			pixels[1].direction = -1; //going backward
			pixels[1].jumpInterval = 1;
			pixels[1].position = 5; //halfway the strip
			_tprintf(_T("Pixels[1] initialized\n"));

			chaser csr(10, pixels, 2);
			csr.step();
			_tprintf(_T("Steped"));

		}
	}
	else
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: GetModuleHandle failed\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
