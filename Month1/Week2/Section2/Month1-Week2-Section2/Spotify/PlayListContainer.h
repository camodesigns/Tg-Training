#pragma once
#include "Playlist.h"


class FPlaylistContainer {
private:
	const static int MaxPlaylistCount = 5;
	FPlaylist Playlists[MaxPlaylistCount];
	int PlaylistCount;
public:
	FPlaylistContainer();
	void AddPlaylist(FPlaylist AddedPlaylist);
	int GetPlaylistCount()const;
	FPlaylist GetPlaylist(int Index)const;
};