#pragma once
#include "Song.h"

class FPlayList {

private:
	std::string PlayListTitle;
	const static int MaxSongCount = 30;
	int SongCount = 0;
	FSong Songs[MaxSongCount];
	
public:
	FPlayList();
	FPlayList(std::string NewPlayListTitle);
	std::string GetListTitle();
	void SetListTitle(std::string NewPlayListTitle);
	bool bAddSong(FSong FSong);
	FSong GetSong(int SongIndex);
	void  PlayListDisplay();
};