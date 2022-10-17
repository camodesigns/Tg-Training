#define OLC_PGE_APPLICATION
#include <algorithm>
#include "olcPixelGameEngine.h"
#include "Player.h"



//UpdateGameLogic();
void FTron::ClearScreen()
{
	FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::BLACK);
}

void FTron::InitializePlayer()
{
	//Inicialise Player position
	Player.Position.x = ScreenWidth() / 2.0f;
	Player.Position.y = ScreenHeight() / 2.0f;
	Player.Velocity.x = 0.0f;
	Player.Velocity.y = 0.0f;
	Player.Angle = 0.0f;
	Player.bIsDead = false;
	Player.Speed = 50.0f;
	PlayerModel =
	{
		{0.0f,-15.0f},
		{-5.0f , +5.0f},
		{+5.0f,+5.0f}
	};
}



void FTron::MovePlayer(float ElapsedTime)
{
	if (GetKey(olc::Key::UP).bHeld)
	{
		Player.Position.x += sin(Player.Angle) * Player.Speed * ElapsedTime;
		Player.Position.y += -cos(Player.Angle) * Player.Speed * ElapsedTime;
	}
	if (GetKey(olc::Key::RIGHT).bHeld)
	{
		Player.Angle += 5.0f * ElapsedTime;
	}

	else if (GetKey(olc::Key::LEFT).bHeld)
	{
		Player.Angle -= 5.0f * ElapsedTime;
	}
	
}



void FTron::ShootBullet(float ElapsedTime)
{
	if (GetKey(olc::Key::SPACE).bReleased)
	{
		VectorBullets.push_back({ {Player.Position.x,Player.Position.y},{50.0f * sinf(Player.Angle),-50.0f * cosf(Player.Angle)},0,0 });
	}
}

//UpdatePhysics;
void FTron::OutCoordinates(const float CoordinatesX, const float CoordinatesY, float& WrappedX, float& WrappedY)
{
	WrappedX = CoordinatesX;
	WrappedY = CoordinatesY;
	if (CoordinatesX < 0.0f)
	{
		WrappedX = CoordinatesX + (float)ScreenWidth();
	}
	if (CoordinatesX > ScreenWidth())
	{
		WrappedX = CoordinatesX - (float)ScreenWidth();
	}

	if (CoordinatesY < 0.0f)
	{
		WrappedY = CoordinatesY + (float)ScreenHeight();
	}
	if (CoordinatesY > ScreenHeight())
	{
		WrappedY = CoordinatesY - (float)ScreenHeight();
	}
}

bool FTron::HasWon()
{
	int MaxLevel = 4;
	if (Level >= MaxLevel)
	{
		PlayerModel.clear();
		VectorBullets.clear();

		DrawString(60, 100, "You Win", olc::GREEN, 10);
		return true;
	}
		return false;
	

}

void FTron::DestroyVectorBullets()
{
	if (VectorBullets.size() > 0)
	{
		auto Destroy =
			remove_if(VectorBullets.begin(), VectorBullets.end(), [&](FSpaceObject BulletDestroy)
				{
					return (BulletDestroy.Position.x < 1 || BulletDestroy.Position.y < 1 || BulletDestroy.Position.x >= ScreenWidth() || BulletDestroy.Position.y >= ScreenHeight());
				});
		if (Destroy != VectorBullets.end())
		{
			VectorBullets.erase(Destroy);
		}
	}
}

bool FTron::Collision(float CenterX, float CenterY, float Radius, float PositionX, float PositionY)
{
	return sqrt(((PositionX - CenterX) * (PositionX - CenterX)) + ((PositionY - CenterY) * (PositionY - CenterY))) < Radius;
}

void FTron::bIsDead()
{
	if (Player.bIsDead == true)
	{

		VectorBullets.clear();
		Level = 1;

		Player.Position.x = ScreenWidth() / 2.0f;
		Player.Position.y = ScreenHeight() / 2.0f;
		Player.Velocity.x = 0.0f;
		Player.Velocity.y = 0.0f;
		Player.Angle = 0.0f;
		Player.bIsDead = false;
		PlayerModel =
		{
			{0.0f,-15.0f},
			{-5.0f , +5.0f},
			{+5.0f,+5.0f}
		};

	}
}

//Render()

bool FTron::Draw(int PositionX, int PositionY, olc::Pixel P = olc::RED)
{
	float TempX, TempY;
	OutCoordinates((float)PositionX, (float)PositionY, TempX, TempY);

	return PixelGameEngine::Draw(TempX, TempY, P);

}


void FTron::DrawPlayer()
{
	OutCoordinates(Player.Position.x, Player.Position.y, Player.Position.x, Player.Position.y);
	DrawWireFrameModel(PlayerModel, Player.Position.x, Player.Position.y, Player.Angle, 1.0,olc::WHITE);
}

void FTron::DrawWireFrameModel(const std::vector<std::pair<float, float>>& vecModelCoordinates, float PositionX, float PositionY, float TurningRadius = 0.0f, float Scale = 1.0f, olc::Pixel P = olc::WHITE)
{

	std::vector<std::pair<float, float>> TransformedCoordinates;
	int Vertices = vecModelCoordinates.size();
	TransformedCoordinates.resize(Vertices);

	// Rotate
	for (int i = 0; i < Vertices; i++)
	{
		TransformedCoordinates[i].first = vecModelCoordinates[i].first * cosf(TurningRadius) - vecModelCoordinates[i].second * sinf(TurningRadius);
		TransformedCoordinates[i].second = vecModelCoordinates[i].first * sinf(TurningRadius) + vecModelCoordinates[i].second * cosf(TurningRadius);
	}

	// Scale
	for (int i = 0; i < Vertices; i++)
	{
		TransformedCoordinates[i].first = TransformedCoordinates[i].first * Scale;
		TransformedCoordinates[i].second = TransformedCoordinates[i].second * Scale;
	}

	// Translate
	for (int i = 0; i < Vertices; i++)
	{
		TransformedCoordinates[i].first = TransformedCoordinates[i].first + PositionX;
		TransformedCoordinates[i].second = TransformedCoordinates[i].second + PositionY;
	}

	// Draw Closed Polygon
	for (int i = 0; i < Vertices + 1; i++)
	{
		int NextPos = (i + 1);
		DrawLine(TransformedCoordinates[i % Vertices].first, TransformedCoordinates[i % Vertices].second,
			TransformedCoordinates[NextPos % Vertices].first, TransformedCoordinates[NextPos % Vertices].second, P);
	}
}

void FTron::DrawBehindLine()
{
	olc::vf2d BackDirection;
	BackDirection.x = -sinf(Player.Angle);
	BackDirection.y = cosf(Player.Angle);
	olc::vf2d ShipTail = 6.f * BackDirection + Player.Position;
	
	DrawLine(ShipTail, (ShipTail + BackDirection.perp()*2.0f), olc::MAGENTA);
	std::cout << ShipTail << "  " << Player.Position << std::endl;
	//DrawRect()
}

void FTron::HudDisplay()
{
	DrawString(8, 8, "Score: " + std::to_string(Score) + "\t" + "Level: " + std::to_string(Level), olc::YELLOW);
}



void FTron::UpdateAndDrawVectorBullets(float ElapsedTime)
{
	for (auto& Bullet : VectorBullets)
	{
		Bullet.Position.x += Bullet.Velocity.x * ElapsedTime;
		Bullet.Position.y += Bullet.Velocity.y * ElapsedTime;
		OutCoordinates(Bullet.Position.x, Bullet.Position.y, Bullet.Position.x, Bullet.Position.y);
		Draw(Bullet.Position.x, Bullet.Position.y);


	}
}



bool FTron::InitialConditions()
{

	InitializePlayer();

	return true;
}

bool FTron::UpdatingGame(float ElapsedTime)
{
	//TODO: ERASE THAT SHITE
	//ClearScreen();
	if (HasWon())
	{
		std::cout << "Press Enter for End the Game" << std::endl;
		if (GetKey(olc::Key::ENTER).bReleased)
		{
			return false;
		}

	}
	else
	{
		
		
		MovePlayer(ElapsedTime);
		DrawPlayer();
		ShootBullet(ElapsedTime);
		UpdateAndDrawVectorBullets(ElapsedTime);
		DestroyVectorBullets();
		DrawBehindLine();
		HudDisplay();

		bIsDead();


	}
	return true;
}





int main()
{
	FTron Game;
	Game.Construct(420, 320, 2, 2);
	Game.Start();

	return 0;
}