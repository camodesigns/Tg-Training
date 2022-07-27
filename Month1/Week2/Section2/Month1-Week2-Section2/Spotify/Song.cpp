#include "Song.h"
FSong::FSong()
{
    MinutesDuration = 0;
    SecondsDuration = 0;
    ArtistName = "";
    SongName = "";
}
FSong::FSong(int EntryMinutesDuration, int EntrySecondsDuration, std::string EntryArtistName, std::string EntrySongName)
{
    MinutesDuration = EntryMinutesDuration;
    SecondsDuration = EntrySecondsDuration;
    ArtistName = EntryArtistName;
    SongName = EntrySongName;

}



std::string FSong::GetFormatedDuration()const
{
    std::string FormatedDuration = "";
    FormatedDuration = "Minutes: " + std::to_string(MinutesDuration) + "\t" "Seconds" + std::to_string(SecondsDuration);
    return FormatedDuration;
}
bool FSong::bIsvalid()
{
    if (MinutesDuration <= 0 && SecondsDuration < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

std::string FSong::GetArtistName()const
{
    return ArtistName;
}
std::string FSong::GetSongName()const
{
    return SongName;
}
int FSong::GetMinutesDuration()const
{
    return MinutesDuration;
}
int FSong::GetSecondsDuration()const
{
    return SecondsDuration;
}
void FSong::SetArtistName(std::string NewArtistName)
{
    ArtistName = NewArtistName;
}
void FSong::SetSongName(std::string NewSongName)
{
    SongName = NewSongName;
}
void FSong::SetMinutesDuration(int NewMinutesDuration)
{
    MinutesDuration = NewMinutesDuration;
}
void FSong::SetSecondsDuration(int NewSecondsDuration)
{
    SecondsDuration = NewSecondsDuration;
}

