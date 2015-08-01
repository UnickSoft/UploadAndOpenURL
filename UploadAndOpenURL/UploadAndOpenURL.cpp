/**
 * Small utility to upload images using WinSCP.com 
 * ans open url of this image.
 */

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	if (argc == 4)
	{
		std::string script(argv[1]);
		std::string filePath(argv[2]);
		std::string url(argv[3]);

		// Get exe dir.
		char exePath[MAX_PATH] = {0};
		GetModuleFileNameA(NULL, exePath, MAX_PATH);
		std::string strExePath(exePath);
		int pos = strExePath.rfind('\\');
		std::string exeDir = strExePath.substr(0, pos + 1);

		// Run WinSCP
		std::string ftpCommand = "/script=\""  + script + "\" /parameter // \"\"\"" + filePath + "\"\"\"";
		ShellExecuteA (NULL, "open", (exeDir + "\\WinSCP.com").c_str(), ftpCommand.c_str(), NULL, SW_SHOWNORMAL);
		
		// Wait 
		Sleep(500);

		// Open URL
		int lastindex = filePath.find_last_of("\\"); 
		std::string rawName = filePath.substr(lastindex + 1);
		ShellExecuteA(NULL, "open", (url + rawName).c_str(), NULL, NULL, SW_SHOWNORMAL);
	}
	else
	{
		printf("This program run WinSCP with SCRIPT_NAME\n");
		printf("and open url: URL_PREFIX + FILE_NAME.\n");
		printf("Command line sample:\n");
		printf("program SCRIPT_NAME FILE_PATH URL_PREFIX\n");
		printf("program upload.txt c:\1.jpg http://unick-soft.ru/");
	}
	return 0;
}

