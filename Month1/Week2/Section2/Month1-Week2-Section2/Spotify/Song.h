#pragma once
#include <string>
#include <iostream>
#include <string>
class FSong
{
private:
    int MinutesDuration;
    int SecondsDuration;
    std::string ArtistName;
    std::string SongName;
public:
    FSong();

    FSong(int EntryMinutesDuration, int EntrySecondsDuration, std::string EntryArtistName, std::string EntrySongName);
    std::string GetFormatedDuration()const;
    bool bIsvalid();
    std::string GetArtistName()const;
    std::string GetSongName()const;
    int GetMinutesDuration()const;
    int GetSecondsDuration()const;
    void SetArtistName(std::string NewArtistName);
    void SetSongName(std::string NewSongName);
    void SetMinutesDuration(int NewMinutesDuration);
    void SetSecondsDuration(int NewSecondsDuration);
};
