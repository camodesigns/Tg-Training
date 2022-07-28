#include"PlaylistContainer.h"

FPlaylistContainer::FPlaylistContainer()
{
	PlaylistCount = 0;
}

int FPlaylistContainer::GetPlaylistCount()const
{
	return PlaylistCount;
}

FPlaylist FPlaylistContainer::GetPlaylist(int Index)const
{
	return Playlists[Index];
}

void FPlaylistContainer::AddPlaylist(FPlaylist NewPlaylist)
{
	Playlists[PlaylistCount] = NewPlaylist;
	PlaylistCount+=1;
}
