#pragma once
#include <string>
#include <iostream>
#include <string>
class FSong
{
private:
    int MinutesDuration;
    int SecondsDuration;
    std:: string ArtistName;
    std:: string SongName;
public:
    FSong();

    FSong(int EntryMinutesDuration, int EntrySecondsDuration, std:: string EntryArtistName, std:: string EntrySongName);
    std::string GetFormatedDuration();
    bool bIsvalid();
    std::string GetArtistName();
    std::string GetSongName();
    int GetMinutesDuration();
    int GetSecondsDuration();
    void SetArtistName(std:: string NewArtistName);
    void SetSongName(std:: string NewSongName);
    void SetMinutesDuration(int NewMinutesDuration);
    void SetSecondsDuration(int NewSecondsDuration);
};
