#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"


class FlappyBird : public olc::PixelGameEngine
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

	int AttempCount = 0;
	int FlapCount = 0;
	int MaxFlapCount = 0;

	bool HasCollided = false;
	bool ResetGame = true;

protected:

	//Displays
	void DisplayBird(int BirdX)
	{
		if (BirdVelocity > 0)
		{
			DrawString(BirdX, BirdPosition - 8, "  /", olc::YELLOW);
			DrawString(BirdX, BirdPosition + 0, "  //", olc::BLUE);
			DrawString(BirdX, BirdPosition + 8, "<///=Q>", olc::RED);
		}
		else
		{
			DrawString(BirdX, BirdPosition + 0, "<///=Q>", olc::RED);
			DrawString(BirdX, BirdPosition + 8, "  //", olc::BLUE);
			DrawString(BirdX, BirdPosition + 12, "  /", olc::YELLOW);
		}
	}

	void HudDisplay()
	{
		DrawString(1, 1, "Attemp: " + std::to_string(AttempCount) + " Score: " + std::to_string(FlapCount) + " High Score: " + std::to_string(MaxFlapCount));
	}

	//Speed
	float LevelSpeed(const float FElapsedTime) 
	{
		LevelPosition += 100.0f * FElapsedTime;
		return LevelPosition;
	}
	

	//Checks
	void CheckColition(int BirdX)
	{
		HasCollided = BirdPosition < 2 || BirdPosition > ScreenHeight() - 2 ||
			GetDrawTarget()->GetPixel(BirdX, BirdPosition) == olc::GREEN ||
			GetDrawTarget()->GetPixel(BirdX, BirdPosition + 24) == olc::GREEN ||
			GetDrawTarget()->GetPixel(BirdX + 56, BirdPosition) == olc::GREEN ||
			GetDrawTarget()->GetPixel(BirdX + 56, BirdPosition + 24) == olc::GREEN;
	}


	//Reset Game
	void Reset()
	{
		HasCollided = false;
		ResetGame = false;
		ListSection = { 0,0,0,0 };
		BirdAceleration = 0.0f;
		BirdVelocity = 0.0f;
		BirdPosition = ScreenHeight() / 2.0f;
		FlapCount = 0;
		AttempCount++;
	}

	//OnUser

	virtual bool OnUserCreate()
	{

		ListSection = { 0,0,0,0 };
		SectionWidth = (float)ScreenWidth() / (float)(ListSection.size() - 1);
		ResetGame = true;
		return true;
	}


	virtual bool OnUserUpdate(float FElapsedTime)
	{

		if (ResetGame)
		{
			Reset();
		}

		if (HasCollided)
		{
			if (GetKey(olc::Key::SPACE).bReleased)
			{
				ResetGame = true;
			}
		}
		else {

			if (GetKey(olc::Key::SPACE).bPressed)
			{
				BirdAceleration = 0.0f;
				BirdVelocity = -Gravity / 4.0f;
				FlapCount++;
				if (FlapCount > MaxFlapCount)
				{
					MaxFlapCount = FlapCount;
				}
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

			LevelSpeed(FElapsedTime);

			if (LevelPosition > SectionWidth)
			{
				LevelPosition -= SectionWidth;
				ListSection.pop_front();
				int i = rand() % (int)(ScreenHeight() * 0.75);
				if (i <= 10) i = 0;
				ListSection.push_back(i);
			}

			FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::DARK_CYAN);

			int Section = 0;
			for (auto S : ListSection)
			{
				if (S != 0)
				{
					FillRect(Section * SectionWidth + 10 - LevelPosition,
						ScreenHeight() - S,
						SectionWidth / 4,
						ScreenHeight(),
						olc::GREEN);
					FillRect(Section * SectionWidth + 10 - LevelPosition,
						0,
						SectionWidth / 4,
						ScreenHeight() - S - (ScreenHeight() / 3), olc::GREEN);
				}
				Section++;
			}
			int BirdX = (int)(ScreenWidth() / 6.0);

			CheckColition(BirdX);

			DisplayBird(BirdX);

			HudDisplay();

		}
		return true;
	}
};


int main()
{
	FlappyBird Game;
	Game.Construct(720, 350, 2, 2);
	Game.Start();

	return 0;
}