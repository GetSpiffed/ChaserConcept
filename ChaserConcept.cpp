// ChaserConcept.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ChaserConcept.h"
#include "RGB.h"
#include "Pixel.h"
#include "Chaser.h"
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
			Pixel pixels[2];
			_tprintf(_T("Created Pixels\n"));

			//First pixel
			pixels[0].primaryColor->red = 100;
			pixels[0].primaryColor->green = 0;
			pixels[0].primaryColor->blue = 0;
			pixels[0].direction = 1;//going forward
			pixels[0].jumpStepInterval = 1;
			pixels[0].position = -1; //one before the start of the strip
			_tprintf(_T("Pixels[0] initialized\n"));

			//second pixel
			pixels[1].primaryColor->red = 100;
			pixels[1].primaryColor->green = 0;
			pixels[1].primaryColor->blue = 0;
			pixels[1].direction = -1; //going backward
			pixels[1].jumpStepInterval = 1;
			pixels[1].position = 5; //halfway the strip
			_tprintf(_T("Pixels[1] initialized\n"));

			Chaser csr(10, pixels, 2);

			for (int j = 0; j < 100; j++)
			{
				csr.step();
				_tprintf(TEXT("Steped %d\n"), j);

				for (int i = 0; i < 10; i++)
				{
					//print stripmask
					_tprintf(TEXT("(%d) r=%d g=%d b=%d\n"), i, csr.stripMask[i].red, csr.stripMask[i].green, csr.stripMask[i].blue);
				}
			}
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
