#pragma once
#include"PlayListContainer.h"
class FSpotify
{
private:
	FPlayListContainer PlayListContainer;
	enum class MenuCommand { MainMenu, CreatePlayList, BrowsePlayLists, Exit };
	MenuCommand ActiveCommand;
public:
	void DebugApp();
	FSpotify();
	void RunApp();
private:
	void OpenMainMenu();
	void OpenCreatePlayListMenu();
	void OpenBrowsePlayListMenu();
};