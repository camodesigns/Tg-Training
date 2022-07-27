#pragma once
#include "PlayList.h"


class FPlayListContainer {
private:
	const static int MaxPlayListCount = 5;
	FPlayList PlayLists[MaxPlayListCount];
	int PlayListCount;
public:
	FPlayListContainer();
	FPlayListContainer(FPlayList NewPlayList);
	void AddPlaylist(FPlayList AddedPlaylist);
	int GetPlayListCount();
	FPlayList GetPlayList(int Index);
	FPlayList GetPlayList(int index) const;
};