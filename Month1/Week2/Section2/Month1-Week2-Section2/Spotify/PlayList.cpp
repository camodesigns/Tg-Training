#include"PlayList.h"

FPlayList::FPlayList()
{
	PlayListTitle = "";
	SongCount = 0;
}
FPlayList::FPlayList(std::string NewTitle)
{
	PlayListTitle = NewTitle;
}

std::string FPlayList::GetListTitle()
{
	return PlayListTitle;
}

void FPlayList::SetListTitle(std::string NewPlayListTitle)
{
	PlayListTitle = NewPlayListTitle;
}
FSong FPlayList::GetSong(int SongIndex)
{
	return Songs[SongIndex];
}
bool FPlayList::bAddSong(FSong Song)
{
	if (Song.bIsvalid())
	{
		Songs[SongCount] = Song;
		SongCount++;
		return true;
	}
	return false;
}


void  FPlayList::PlayListDisplay()
{
	std::cout << "PlayList" << std::endl;
	std::cout << "Song Title\t\t\t\tArtist Name\t\t\t\tDuration" << std::endl;
	std::cout << "------------------------------------------------------------------------------------------" << std::endl;
	for (int CurrentSong = 0; CurrentSong < SongCount; CurrentSong++)
	{
		FSong ListedSong = Songs[CurrentSong];
		std::cout << ListedSong.GetSongName() << "\t\t\t\t" << ListedSong.GetArtistName() << "\t\t\t\t" << ListedSong.GetFormatedDuration() << std::endl;
		
	}
	std::cout << std::endl;
	std::cout << std::endl;

}