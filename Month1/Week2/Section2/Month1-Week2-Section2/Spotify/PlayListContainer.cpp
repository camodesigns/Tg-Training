#include"PlayListContainer.h"

FPlayListContainer:: FPlayListContainer()
{
	PlayListCount = 0;
}

FPlayListContainer:: FPlayListContainer(FPlayList NewPlayList)
{
	PlayLists[PlayListCount] = NewPlayList;
	PlayListCount++;
}
int FPlayListContainer:: GetPlayListCount()
{
	return PlayListCount;
}
FPlayList FPlayListContainer:: GetPlayList(int Index)
{
	return PlayLists[Index];
}
void FPlayListContainer:: AddPlaylist(FPlayList NewPlaylist)
{
	PlayLists[PlayListCount] = NewPlaylist;
	PlayListCount++;
}
FPlayList FPlayListContainer:: GetPlayList(int index) const
{
	return PlayLists[index];
}