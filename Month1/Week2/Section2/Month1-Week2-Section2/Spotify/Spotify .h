#pragma once
#include"PlaylistContainer.h"
class FSpotify
{
private:
	FPlaylistContainer PlaylistContainer;
	enum class MenuCommand { MainMenu, CreatePlaylist, BrowsePlaylists, Exit };
	MenuCommand ActiveCommand;
public:
	FSpotify();
	void DebugApp();
	void RunApp();
private:
	void OpenMainMenu();
	void OpenCreatePlaylistMenu();
	void OpenBrowsePlaylistMenu();
};