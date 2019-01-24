#pragma once

#include "Config.h"
#include "DefaultToolbarButtons.h"
#include "../Helper/BaseWindow.h"
#include <list>
#include <unordered_map>

/* This represents the TOTAL set off buttons that may be
placed on the toolbar. */
static const int TOOLBAR_BUTTON_SET[] =
{ TOOLBAR_BACK, TOOLBAR_FORWARD, TOOLBAR_UP, TOOLBAR_FOLDERS,
TOOLBAR_COPYTO, TOOLBAR_MOVETO, TOOLBAR_NEWFOLDER, TOOLBAR_COPY,
TOOLBAR_CUT, TOOLBAR_PASTE, TOOLBAR_DELETE, TOOLBAR_VIEWS,
TOOLBAR_SEARCH, TOOLBAR_PROPERTIES, TOOLBAR_REFRESH,
TOOLBAR_ADDBOOKMARK, TOOLBAR_NEWTAB, TOOLBAR_OPENCOMMANDPROMPT,
TOOLBAR_ORGANIZEBOOKMARKS, TOOLBAR_DELETEPERMANENTLY };

class MainToolbar : public CBaseWindow
{
public:

	static MainToolbar *Create(HWND parent, HINSTANCE instance, IExplorerplusplus *pexpp, std::shared_ptr<Config> config);

	void UpdateToolbarSize();

private:

	static const UINT_PTR PARENT_SUBCLASS_ID = 0;

	MainToolbar(HWND parent, HINSTANCE instance, IExplorerplusplus *pexpp, std::shared_ptr<Config> config);
	~MainToolbar();

	static HWND CreateMainToolbar(HWND parent);

	static LRESULT CALLBACK ParentWndProcStub(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData);
	LRESULT CALLBACK ParentWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void Initialize(HWND parent);
	void SetInitialToolbarButtons();
	void AddButtonsToMainToolbar();
	void AddButtonToMainToolbar(int iButtonId);
	TBBUTTON GetMainToolbarButtonDetails(int iButtonId);
	void AddStringsToMainToolbar();
	void AddStringToMainToolbar(int iButtonId);
	void GetMainToolbarButtonText(int iButtonId, TCHAR *szText, int bufSize);
	int LookupToolbarButtonImage(int iButtonID);
	BYTE LookupToolbarButtonExtraStyles(int iButtonID);
	int LookupToolbarButtonTextID(int iButtonID);

	BOOL OnTBQueryInsert();
	BOOL OnTBQueryDelete();
	BOOL OnTBRestore();
	BOOL OnTBGetButtonInfo(LPARAM lParam);
	void OnTBReset();
	void OnTBGetInfoTip(LPARAM lParam);

	HINSTANCE m_instance;
	IExplorerplusplus *m_pexpp;
	std::shared_ptr<Config> m_config;

	HIMAGELIST m_himlToolbarSmall;
	HIMAGELIST m_himlToolbarLarge;
	std::unordered_map<int, int> m_mainToolbarStringMap;

	std::list<ToolbarButton_t> m_tbInitial;
};