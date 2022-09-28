#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"


class FlappyBird: public olc::PixelGameEngine
{
public:
	FlappyBird() 
	{
		sAppName = "FlappyBird";
	}
private:
	
	float BirdPosition = 0.0f;
	float BirdVelocity = 0.0f;
	float BirdAceleration = 0.0f;
	float Gravity = 300.0f;

	float SectionWidth;
	std::list <int> ListSection;
	float LevelPosition = 0.0f;

protected:
	virtual bool OnUserCreate() 
	{

		ListSection = { 0,0,0,0 };
		SectionWidth = (float)ScreenWidth() / (float)(ListSection.size() - 1);
		return true;
	}
	
	virtual bool OnUserUpdate(float FElapsedTime) 
	{
		if ( GetKey(olc::Key::SPACE).bPressed)
		{
			BirdAceleration = 0.0f;
			BirdVelocity = -Gravity / 4.0f;
		}
		else
		{
			BirdAceleration += Gravity * FElapsedTime;
		}
		
		if (BirdAceleration >= Gravity) 
		{
			BirdAceleration = Gravity;
		}

		BirdVelocity += BirdAceleration * FElapsedTime;
		BirdPosition += BirdVelocity * FElapsedTime;

		LevelPosition += 50.0f * FElapsedTime;

		if (LevelPosition > SectionWidth)
		{
			LevelPosition -= SectionWidth;
			ListSection.pop_front();
			int i = rand() % (int)(ScreenHeight() * 0.75);
			if (i <= 10) i = 0;
			ListSection.push_back(i);
		}

		FillRect(0,0,ScreenWidth(),ScreenHeight(), olc::BLACK);

		int Section = 0;
		for (auto S : ListSection) 
		{
			if(S != 0)
			{
				FillRect(Section * SectionWidth + 10 - LevelPosition,
					ScreenHeight() - S,
					SectionWidth / 4,
					ScreenHeight(),
					olc::GREEN);
				FillRect(Section * SectionWidth + 10 - LevelPosition,
					0,
					SectionWidth / 4 ,
					ScreenHeight() - S - (ScreenHeight() / 3), olc::GREEN);
			}
			Section++;
		}

		int BirdX = (int)(ScreenWidth() / 6.0);
		
		if (BirdVelocity > 0) 
		{
			DrawString(BirdX, BirdPosition - 8, "  /");
			DrawString(BirdX, BirdPosition + 0, "  //"); 
			DrawString(BirdX, BirdPosition + 8, "<///=Q>");
		}
		else
		{
			DrawString(BirdX, BirdPosition + 0, "<///=Q>");
			DrawString(BirdX, BirdPosition + 8, "  //");
			DrawString(BirdX, BirdPosition + 12, "  /");
			
		}
		return true;
	}
};


int main() 
{
	FlappyBird Game;
	Game.Construct(720,350,2,2);
	Game.Start();

	return 0;
}