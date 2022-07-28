#pragma once
#include <string>
#include <iostream>
class FSong
{
private:
    int Duration;
    std::string ArtistName;
    std::string SongName;
public:
    FSong();
    FSong(const int EntryDuration, const std::string EntryArtistName, const std::string EntrySongName);
    std::string GetFormatedDuration()const;
    bool IsValid()const;
    std::string GetArtistName()const;
    std::string GetSongName()const;
    int GetDuration()const;
    void SetArtistName(std::string NewArtistName);
    void SetSongName(std::string NewSongName);
    void SetDuration(int NewMDuration);
  
};
