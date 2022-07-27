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
	int GetPlayListCount()const;
	FPlayList GetPlayList(int Index)const;
};