#include"PlayListContainer.h"

FPlayListContainer::FPlayListContainer()
{
	PlayListCount = 0;
}

FPlayListContainer::FPlayListContainer(FPlayList NewPlayList)
{
	PlayLists[PlayListCount] = NewPlayList;
	PlayListCount++;
}
int FPlayListContainer::GetPlayListCount()const
{
	return PlayListCount;
}
FPlayList FPlayListContainer::GetPlayList(int Index)const
{
	return PlayLists[Index];
}
void FPlayListContainer::AddPlaylist(FPlayList NewPlaylist)
{
	PlayLists[PlayListCount] = NewPlaylist;
	PlayListCount++;
}
