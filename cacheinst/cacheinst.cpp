/* 
	Cache Instantiation
	(C) ultrashot 2013
*/
#include "stdafx.h"

void PutToCache(wchar_t *filter)
{
	wchar_t *folder = new wchar_t[wcslen(filter) + 1];
    if (folder)
    {
	    wcscpy(folder, filter);
	    wchar_t *t = wcsrchr(folder, L'\\') + 1;
        if (t)
            *t = L'\0';
	    WIN32_FIND_DATAW fd;
	    HANDLE hF = FindFirstFileW(filter, &fd);
	    if(hF != INVALID_HANDLE_VALUE)
	    {
		    int currentNum = 0;
		    do
		    {
			    // skip '.' and '..'
			    if(fd.cFileName[0] == L'.')
				    if((fd.cFileName[1] == L'.' && fd.cFileName[2] == L'\0') || fd.cFileName[1] == L'\0')
					    continue;

			    wchar_t atcEntry[1024];
			    wcscpy(atcEntry, folder);
			    wcscat(atcEntry, fd.cFileName);
			    wcscat(atcEntry, L"-addtocache");
			    GetFileAttributes(atcEntry);
		    } 
		    while (FindNextFileW(hF, &fd));
		    FindClose(hF);
	    }
        delete[] folder;
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
	PutToCache(L"\\Windows\\GAC_*.dll");

	// Quick Menu
	PutToCache(L"\\Applications\\Install\\04589AD3-C4FD-4C6B-AE67-10468AFF4F8F\\Install\\*");
	PutToCache(L"\\Applications\\Install\\04589AD3-C4FD-4C6B-AE67-10468AFF4F8F\\Install\\Images\\*");

	// Connected Media
	PutToCache(L"\\Applications\\Install\\9EFAF5ED-6702-40B4-A4DA-268CF5E6C12C\\Install\\*");

	// Photo Enhancer
	PutToCache(L"\\Applications\\Install\\8E17BC66-2BB2-DF11-8A2F-00237DE2DB9E\\Install\\*");
	PutToCache(L"\\Applications\\Install\\8E17BC66-2BB2-DF11-8A2F-00237DE2DB9E\\Install\\Res\\Generic\\NewImages\\*");
	PutToCache(L"\\Applications\\Install\\8E17BC66-2BB2-DF11-8A2F-00237DE2DB9E\\Install\\Res\\Generic\\Frames\\Portrait\\*");
	PutToCache(L"\\Applications\\Install\\8E17BC66-2BB2-DF11-8A2F-00237DE2DB9E\\Install\\Res\\Generic\\Frames\\Landscape\\*");
	PutToCache(L"\\Applications\\Install\\8E17BC66-2BB2-DF11-8A2F-00237DE2DB9E\\Install\\Res\\Generic\\AppBarIcons\\*");

	// File Manager
	PutToCache(L"\\Applications\\Install\\7F565B9F-8843-45F6-B95E-BF12D9BE09F1\\Install\\*");

	// Notes
	PutToCache(L"\\Applications\\Install\\44F5D0BA-49B1-DF11-8A2F-00237DE2DB9E\\Install\\*");
	PutToCache(L"\\Applications\\Install\\44F5D0BA-49B1-DF11-8A2F-00237DE2DB9E\\Install\\Res\\Generic\\Images\\*");
	PutToCache(L"\\Applications\\Install\\44F5D0BA-49B1-DF11-8A2F-00237DE2DB9E\\Install\\Res\\Generic\\Sounds\\*");
	PutToCache(L"\\Applications\\Install\\44F5D0BA-49B1-DF11-8A2F-00237DE2DB9E\\Install\\Res\\Generic\\Fonts\\*");

	// AccountManager
	PutToCache(L"\\Applications\\Install\\794EB6AE-B2F9-4BFB-9277-4161E4D9E3F5\\Install\\*");
	
	GetFileAttributes(L"\\Windows\\agcore.dll-addtocache");
	GetFileAttributes(L"\\Windows\\rsaenh.dll-addtocache");
	GetFileAttributes(L"\\Windows\\taskhost.exe-addtocache");
	GetFileAttributes(L"\\Windows\\D3DCompiler_.dll-addtocache");
	GetFileAttributes(L"\\Windows\\XNAFRAMEWORKCORE.DLL-addtocache");
	
	// HTC Watch
	PutToCache(L"\\Applications\\Install\\17DBBA84-1361-4CC6-A247-DBBB353E7679\\Install\\*");


	// HTC Flashlight
	PutToCache(L"\\Applications\\Install\\0BE0455C-C8D5-DF11-A844-00237DE2DB9E\\Install\\*");
	PutToCache(L"\\Applications\\Install\\0BE0455C-C8D5-DF11-A844-00237DE2DB9E\\Install\\Res\\Generic\\fonts\\*");
	
	// Nokia RingtoneMaker
	PutToCache(L"\\Applications\\Install\\DAE4700E-6EEB-43B1-B48D-AEE18B46FDDC\\Install\\*");
	
	// Clock Hub
	PutToCache(L"\\Applications\\Install\\F64D312E-52CE-4718-885E-997B00927FC8\\Install\\*");

	return 0;
}

