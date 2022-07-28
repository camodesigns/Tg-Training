#pragma once
#include "Song.h"

class FPlaylist 
{

private:
	std::string PlaylistTitle;
	const static int MaxSongCount = 30;
	int SongCount = 0;
	FSong Songs[MaxSongCount];
	
public:
	FPlaylist();
	FPlaylist(const std::string NewPlayListTitle);
	std::string GetTitle();
	void SetTitle(std::string NewPlayListTitle);
	bool bAddSong(FSong FSong);
	FSong GetSong(int SongIndex);
	void  DisplayPlaylist();
};