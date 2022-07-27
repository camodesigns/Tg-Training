#include "Spotify .h"

void FSpotify::DebugApp()
{
    FSong SongOne(2, 15, "OverLord", "The Signa1");
    FSong SongTwo(3, 15, "OverLord2", "The Signa2");
    FSong SongThree(4, 15, "OverLord3", "The Signa3");

    FPlayList Playlist1("Overlord PlayList");
    Playlist1.bAddSong(SongOne);
    Playlist1.bAddSong(SongTwo);
    Playlist1.bAddSong(SongThree);

    FSong Song1(3, 40, "Gorillas", "Re-Hash");
    FSong Song2(2, 42, "Gorillas", "5/4");
    FSong Song3(3, 14, "Gorillas", "Tomorrow Comes Today");
    FSong Song4(3, 59, "Gorillas", "New Genious (Brother)");

    FPlayList Playlist2("Gorillas");
    Playlist2.bAddSong(Song1);
    Playlist2.bAddSong(Song2);
    Playlist2.bAddSong(Song3);
    Playlist2.bAddSong(Song4);

    //Third Playlist
    FSong SongFour(3, 12, "Nirvana", "About a Girl");;
    FSong SongFive(2, 40, "Nirvana", "Re-Hash");

    FPlayList Playlist3("Album Nirvana");
    Playlist3.bAddSong(SongFour);
    Playlist3.bAddSong(SongFive);


    //PlaylistContainer
    
    PlayListContainer.AddPlaylist(Playlist1);
    PlayListContainer.AddPlaylist(Playlist2);
    PlayListContainer.AddPlaylist(Playlist3);
}
FSpotify::FSpotify()
{
    ActiveCommand = MenuCommand::MainMenu;
}
void FSpotify::RunApp()
{
    while (ActiveCommand != MenuCommand::Exit)
    {
        switch (ActiveCommand)
        {
        case FSpotify::MenuCommand::MainMenu:
            OpenMainMenu();
            break;
        case FSpotify::MenuCommand::CreatePlayList:
            OpenCreatePlayListMenu();
            break;
        case FSpotify::MenuCommand::BrowsePlayLists:
            OpenBrowsePlayListMenu();
            break;
        case FSpotify::MenuCommand::Exit:
            break;
        default:
            break;
        }

    }

}


void FSpotify::OpenMainMenu()
{
    do {
        system("CLS");

        std::cout << "Welcome to Spotify!What would you like to do?" << std::endl;
        std::cout << "1. Create a PlayList" << std::endl;
        std::cout << "2. Browse a PlayList" << std::endl;
        std::cout << "3. Exit" << std::endl;
        int OptionChoice;
        std::cin >> OptionChoice;
        while (!std::cin.good() || OptionChoice < 1 || OptionChoice > 3)
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input,Please enter Your new choice or selection" << std::endl;
            std::cin >> OptionChoice;
        }
        ActiveCommand = (MenuCommand)OptionChoice;
        system("CLS");
    } while (!std::cin.good());
}


void FSpotify::OpenCreatePlayListMenu()
{
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    system("CLS");
    int AddSongs;

    std::cout << "Creating a new Playlist Fantastic, Please enter a name for Your Playlist: " << std::endl;
    std::string PlayListName;
    std::getline(std::cin, PlayListName);
    while (!std::cin.good() || PlayListName == "" || std::cin.peek() == '\n')
    {
        std::cout << "Invalid input, please enter Your playlist name again: " << std::endl;
        std::getline(std::cin, PlayListName);
    }
    FPlayList ANewPlayList(PlayListName);
    do
    {
        system("CLS");
        std::cout << "Well, now add a song to " << PlayListName << " Playlist" << std::endl;
        std::cout << "Now,Follow the instructions" << std::endl;

        int EntryMinutesDuration;
        std::string EntryArtistName;
        std::string EntrySongName;
        int EntrySecondsDuration;
        std::cout << "Please enter the song name: " << std::endl;
        std::getline(std::cin, EntrySongName);
        while (!std::cin.good() || EntrySongName == "" || std::cin.peek() == '\n')
        {
            std::cout << "Invalid Input or Empty space, please enter the song name again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, EntrySongName);
        }
        std::cout << "Please enter the artist name: " << std::endl;
        std::getline(std::cin, EntryArtistName);
        while (EntryArtistName == "" || !std::cin.good() || std::cin.peek() == '\n')
        {
            std::cout << "Invalid Input or Empty space, please enter the artist name again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, EntryArtistName);
        }
        std::cout << "Please enter the song duration in minutes and seconds" << std::endl;
        std::cout << "Minutes: " << std::endl;
        std::cin >> EntryMinutesDuration;
        while (EntryMinutesDuration < 0 || !std::cin.good() )
        {
            std::cout << "Invalid input, remember the duration must be greater of cero  " << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> EntryMinutesDuration;
        }
        std::cout << "Seconds: " << std::endl;
        std::cin >> EntrySecondsDuration;
        while (!std::cin.good() || EntrySecondsDuration > 60 || EntrySecondsDuration < 0 )
        {
            std::cout << "Invalid input, remember the seconds duration must be lower of 60 and equal o greater of cero " << std::endl;
            std::cout << "Please enter Your second sduration again:" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> EntrySecondsDuration;
        }
        while (EntryMinutesDuration == 0 && EntrySecondsDuration == 0)
        {
            std::cout << "Remember te duration of the song can not be cero. Enter Your Song Duration again (minutes and seconds ): " << std::endl;
            std::cout << "Minutes: " << std::endl;
            std::cin >> EntryMinutesDuration;
            std::cout << "Seconds:" << std::endl;
            std::cin >> EntrySecondsDuration;
        }
        FSong NewSong(EntryMinutesDuration, EntrySecondsDuration, EntryArtistName, EntrySongName);
        ANewPlayList.bAddSong(NewSong);
        std::cout << "Song add sucefull, What do you whant to do now?" << std::endl;
        std::cout << "1. Enter another song" << std::endl;
        std::cout << "2.Go to main menu" << std::endl;
        std::cin >> AddSongs;
      
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        system("CLS");
    } while (AddSongs == 1);
    PlayListContainer.AddPlaylist(ANewPlayList);
    ActiveCommand = MenuCommand::MainMenu;
}


void FSpotify::OpenBrowsePlayListMenu()
{   

    std::cout << "Here are Your Playlists!" << std::endl;
    int Choice = 1;
    do{
        system("CLS");
     for (int ListWalker = 0;ListWalker < 5; ListWalker++)
        {
            std::cout << ListWalker << "" << PlayListContainer.GetPlayList(ListWalker).GetListTitle() << std::endl;
        }
    
     std::cout << "Which playlist do you want to see: " << std::endl;
     int Index;
     std::cin.clear();
     std::cin.ignore(1000, '\n');
     if (std::cin.peek() == '\n')
     {
         ActiveCommand = MenuCommand::MainMenu;
         break;
     }
     std::cin >> Index;
   
     
     if (PlayListContainer.GetPlayListCount() < Index)
     {
         std::cout << "Invalid Choice, please choce a valid option" << std::endl;
     }
     else 
     {
         PlayListContainer.GetPlayList(Index).PlayListDisplay();
     }
     std::cout << "Well,make a choice" << std::endl;
     std::cout << "1. look another playlist" << std::endl;
     std::cout << "2. Go to the main menu" << std::endl;
     std::cin.ignore(1000, '\n');
     if (std::cin.peek() == '\n')
     {
         ActiveCommand = MenuCommand::MainMenu;
         break;
     }
     std::cin >> Choice;
     while (!std::cin.good() || Choice > 2 || Choice < 1)
     {
         std::cout << "Invalid input, Please enter Your choice Again" << std::endl;
         std::cin.clear();
         std::cin.ignore(1000, '\n');
         if (std::cin.peek() == '\n')
         {
             ActiveCommand = MenuCommand::MainMenu;
             break;
         }
         std::cin >> Choice;
     }
     
     std::cin.clear();
     std::cin.ignore(1000, '\n');
    } while (Choice == 1);
  
}