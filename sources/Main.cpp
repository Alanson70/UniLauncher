

#include "stdafx.h"
#include <iostream>
#include <Windows.h>


void hide_show_all()
{
	keybd_event(VK_LWIN, 0, 0, 0);
	keybd_event('D', 0, 0, 0);

	keybd_event('D', 0, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_LWIN, 0, KEYEVENTF_KEYUP, 0);
}


int open_file(TCHAR* dir, TCHAR* file)
{
	auto res = ShellExecute(NULL, L"Open", file, NULL, NULL, SW_SHOWNORMAL);

	if (res != NULL)

		return 0;

	return 1;
}


// with console
#ifdef _DEBUG
int _tmain(int count, TCHAR* argv[])
#else
// without console
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR LpCmdLine, int nCmdShow)
#endif
{
	int w_argc = 0;
	LPWSTR* w_argv = CommandLineToArgvW(GetCommandLineW(), &w_argc);
	if (w_argv)
	{
		char** my_argv = new char* [w_argc];

		if (2 == w_argc)
		{
			std::wcout << "try to open : " << w_argv[1] << std::endl;

			// to do something with any document's types:
			//auto n = s.rfind(L".docx");
			//if (std::string::npos != n)
			
			open_file(w_argv[0], w_argv[1]);			
			
		}
		else
		if (1 == w_argc)		
		{
#ifdef _DEBUG
			std::wcout << "Hide or show all" << std::endl;
#endif
			hide_show_all();
		}
#ifdef _DEBUG
		std::cout << "Press any key..." << std::endl;
		std::cin.get();
#endif
	}

	return 0;
}






