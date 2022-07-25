#pragma once
#include <string>
#include<iostream>

class FSong
{
	private:
		std::string SongTitle;
		std::string ArtistName;
		int duration;
public:
		FSong();
		FSong(std::string EntryongTitle, std::string EntryArtistName, int Entryduration) 
		{
		
		}
		const std:: string GetSongTitle()
		{

		}
		const std::string ArtisName() 
		{
		
		}

		const std::string GetFormatedDuration() 
		{

		}
		void SetSongTitle(std::string ChangeSongTitle);
		void SetArtistName(std::string ChangeArtistName);
		void SetDuration(int ChangeDuration);
		const bool IsValid();


}


		
		


};