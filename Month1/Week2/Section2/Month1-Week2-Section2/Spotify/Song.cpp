#include "Song.h"
FSong::FSong()
{
    Duration = 0;
    ArtistName = "";
    SongName = "";
}

FSong::FSong(const int EntryDuration, const std::string EntryArtistName, const std::string EntrySongName)
{
    Duration = EntryDuration;
    ArtistName = EntryArtistName;
    SongName = EntrySongName;

}

std::string FSong::GetFormatedDuration()const
{
    std::string FormatedDuration = "";
    int Minutes, Seconds;
    Minutes = Duration / 60;
    Seconds = Duration % 60;
    FormatedDuration = "Minutes: " + std::to_string(Minutes) + "\t" "Seconds: " + std::to_string(Seconds);
    return FormatedDuration;
}

bool FSong::IsValid()const
{
    return Duration > 0 ;
}

std::string FSong::GetArtistName()const
{
    return ArtistName;
}

std::string FSong::GetSongName()const
{
    return SongName;
}

int FSong::GetDuration()const
{
    return Duration;
}

void FSong::SetArtistName(std::string NewArtistName)
{
    ArtistName = NewArtistName;
}

void FSong::SetSongName(std::string NewSongName)
{
    SongName = NewSongName;
}

void FSong::SetDuration(int NewMDuration)
{
    Duration = NewMDuration;
}


