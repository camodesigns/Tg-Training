#include "Spotify .h"

void FSpotify::DebugApp()
{
    FSong SongOne(150, "OverLord", "The Signa1");
    FSong SongTwo(240, "OverLord2", "The Signa2");
    FSong SongThree(300, "OverLord3", "The Signa3");

    FPlaylist Playlist1("Overlord PlayList");
    Playlist1.bAddSong(SongOne);
    Playlist1.bAddSong(SongTwo);
    Playlist1.bAddSong(SongThree);

    FSong Song1(220, "Gorillas", "Re-Hash");
    FSong Song2(162, "Gorillas", "5/4");
    FSong Song3(194, "Gorillas", "Tomorrow Comes Today");
    FSong Song4(239, "Gorillas", "New Genious (Brother)");

    FPlaylist Playlist2("Gorillas");
    Playlist2.bAddSong(Song1);
    Playlist2.bAddSong(Song2);
    Playlist2.bAddSong(Song3);
    Playlist2.bAddSong(Song4);

    //Third Playlist
    FSong SongFour(192, "Nirvana", "About a Girl");;
    FSong SongFive(160, "Nirvana", "Re-Hash");

    FPlaylist Playlist3("Album Nirvana");
    Playlist3.bAddSong(SongFour);
    Playlist3.bAddSong(SongFive);


    //PlaylistContainer
    
    PlaylistContainer.AddPlaylist(Playlist1);
    PlaylistContainer.AddPlaylist(Playlist2);
    PlaylistContainer.AddPlaylist(Playlist3);
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
        case FSpotify::MenuCommand::CreatePlaylist:
            OpenCreatePlaylistMenu();
            break;
        case FSpotify::MenuCommand::BrowsePlaylists:
            OpenBrowsePlaylistMenu();
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
   
}

void FSpotify::OpenCreatePlaylistMenu()
{
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    system("CLS");
   

    std::cout << "Creating a new Playlist Fantastic, Please enter a name for Your Playlist: " << std::endl;
    std::string PlayListName;
    std::getline(std::cin, PlayListName);
    while (!std::cin.good() || PlayListName == "" || std::cin.peek() == '\n')
    {
        std::cout << "Invalid input, please enter Your playlist name again: " << std::endl;
        std::getline(std::cin, PlayListName);
    }
   
    int Choice = 1;
    FPlaylist NewPlaylist(PlayListName);
   
    do
    {
        system("CLS");
        std::cout << "Well, now add a song to " << PlayListName << " Playlist" << std::endl;
        std::cout << "Now,Follow the instructions" << std::endl;

       
     
        std::string EntrySongName;
        std::cout << "Please enter the song name: " << std::endl;
        std::getline(std::cin, EntrySongName);
        while (!std::cin.good() || EntrySongName == "" || std::cin.peek() == '\n')
        {
            std::cout << "Invalid Input or Empty space, please enter the song name again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, EntrySongName);
        }

        std::string EntryArtistName;
        std::cout << "Please enter the artist name: " << std::endl;
        std::getline(std::cin, EntryArtistName);
        while (EntryArtistName == "" || !std::cin.good() || std::cin.peek() == '\n')
        {
            std::cout << "Invalid Input or Empty space, please enter the artist name again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, EntryArtistName);
        }
        std::cin.ignore(1000, '\n');
        int EntryDuration;
        std::cout << "Please enter the song duration in integer seconds " << std::endl;
        std::cin >> EntryDuration;
        while (EntryDuration <= 0 || !std::cin.good() )
        {
            std::cout << "Invalid input, remember the duration must be greater of cero, entry the duartion again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> EntryDuration;
        }
       

        FSong NewSong(EntryDuration, EntryArtistName, EntrySongName);
        NewPlaylist.bAddSong(NewSong);

        std::cout << "Song add sucefull, What do you whant to do now?" << std::endl;
        std::cout << "1. Enter another song" << std::endl;
        std::cout << "2.Go to main menu" << std::endl;
        std::cin >> Choice;
      
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        system("CLS");
    } while (Choice == 1);

    PlaylistContainer.AddPlaylist(NewPlaylist);

    ActiveCommand = MenuCommand::MainMenu;
}


void FSpotify::OpenBrowsePlaylistMenu()
{   

    std::cout << "Here are Your Playlists!" << std::endl;
    int Choice = 1;
    do{
        system("CLS");
     for (int PlaylistIndex = 0;PlaylistIndex < 5; PlaylistIndex++)
        {
            std::cout << PlaylistIndex << "" << PlaylistContainer.GetPlaylist(PlaylistIndex).GetTitle() << std::endl;
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
   
     
     if (PlaylistContainer.GetPlaylistCount() < Index)
     {
         std::cout << "Invalid Choice, please choce a valid option" << std::endl;
     }
     else 
     {
         PlaylistContainer.GetPlaylist(Index).DisplayPlaylist();
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