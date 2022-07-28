#include"Playlist.h"

FPlaylist::FPlaylist()
{
	PlaylistTitle = "";
	SongCount = 0;
}

FPlaylist::FPlaylist(const std::string NewTitle)
{
	PlaylistTitle = NewTitle;
}

std::string FPlaylist::GetTitle()
{
	return PlaylistTitle;
}

void FPlaylist::SetTitle(std::string NewPlayListTitle)
{
	PlaylistTitle = NewPlayListTitle;
}

FSong FPlaylist::GetSong(int SongIndex)
{
	return Songs[SongIndex];
}

bool FPlaylist::bAddSong(FSong Song)
{
	if (Song.IsValid())
	{
		Songs[SongCount] = Song;
		SongCount++;
		return true;
	}
	return false;
}

void  FPlaylist::DisplayPlaylist()
{
	std::cout << "PlayList" << std::endl;
	std::cout << "Song Title\t\t\t\tArtist Name\t\t\t\tDuration" << std::endl;
	std::cout << "------------------------------------------------------------------------------------------" << std::endl;
	for (int CurrentSongIndex = 0; CurrentSongIndex < SongCount; CurrentSongIndex++)
	{
		FSong CurrentSong = Songs[CurrentSongIndex];
		std::cout << CurrentSong.GetSongName() << "\t\t\t\t" << CurrentSong.GetArtistName() << "\t\t\t\t" << CurrentSong.GetFormatedDuration() << std::endl;
		
	}
	std::cout << std::endl;
	std::cout << std::endl;

}