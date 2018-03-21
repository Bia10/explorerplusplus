/******************************************************************
*
* Project: ShellBrowser
* File: ListView.cpp
* License: GPL - See LICENSE in the top level directory
*
* Written by David Erceg
* www.explorerplusplus.com
*
*****************************************************************/

#include "stdafx.h"
#include "IShellView.h"

LRESULT CALLBACK CShellBrowser::ListViewProcStub(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
{
	UNREFERENCED_PARAMETER(uIdSubclass);

	CShellBrowser *shellBrowser = reinterpret_cast<CShellBrowser *>(dwRefData);
	return shellBrowser->ListViewProc(hwnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK CShellBrowser::ListViewProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_APP_SHELL_NOTIFY:
		OnShellNotify(wParam, lParam);
		return 0;
	}

	return DefSubclassProc(hwnd, uMsg, wParam, lParam);
}