#define OLC_PGE_APPLICATION
#include <algorithm>
#include "olcPixelGameEngine.h"
#include "FPlayer.h"



//UpdateGameLogic();
void FPlayer::ClearScreen()
{
	FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::BLACK);
}

void FPlayer::InitializePlayers()
{
	//Inicialise Player position
	Player1.Position.x = ScreenWidth() / 16.0f;
	Player1.Position.y = ScreenHeight() / 1.2f;
	Player1.Velocity.x = 0.0f;
	Player1.Velocity.y = 0.0f;
	Player1.Angle = 0.0f;
	Player1.bIsDead = false;
	Player1.Speed = 50.0f;
	Player1.Score = 0;
	PlayerModel =
	{
		{0.0f,-15.0f},
		{-5.0f , +5.0f},
		{+5.0f,+5.0f}
	};
	Player2.Score = 0;
	
	
}



void FPlayer::MovePlayer1(float ElapsedTime)
{
	if (GetKey(olc::Key::UP).bHeld)
	{
		Player1.Position.x += sin(Player1.Angle) * Player1.Speed * ElapsedTime;
		Player1.Position.y += -cos(Player1.Angle) * Player1.Speed * ElapsedTime;
	}
	if (GetKey(olc::Key::RIGHT).bHeld)
	{
		Player1.Angle += 5.0f * ElapsedTime;
	}

	else if (GetKey(olc::Key::LEFT).bHeld)
	{
		Player1.Angle -= 5.0f * ElapsedTime;
	}
	
}



void FPlayer::ShootBullet(float ElapsedTime)
{
	if (GetKey(olc::Key::SPACE).bReleased)
	{
		VectorBullets.push_back({ {Player1.Position.x,Player1.Position.y},{50.0f * sinf(Player1.Angle),-50.0f * cosf(Player1.Angle)},0,0 });
	}
}

//UpdatePhysics;
void FPlayer::OutCoordinates(const float CoordinatesX, const float CoordinatesY, float& WrappedX, float& WrappedY)
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

bool FPlayer::HasWon()
{
	
	if (Player1.Score == 4)
	{
		PlayerModel.clear();
		VectorBullets.clear();

		DrawString(60, 100, "Player 1 Win", olc::GREEN, 10);
		return true;
	}
	else if(Player2.Score == 4) 
	{
		PlayerModel.clear();
		VectorBullets.clear();

		DrawString(60, 100, "Player 2 Win", olc::GREEN, 10);
		return true;
	}
		return false;
	

}

void FPlayer::DestroyVectorBullets()
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

/*bool FPlayer::Collision(float CenterX, float CenterY, float Radius, float PositionX, float PositionY)
{
	return sqrt(((PositionX - CenterX) * (PositionX - CenterX)) + ((PositionY - CenterY) * (PositionY - CenterY))) < Radius;
}*/



void FPlayer::IsDead()
{
	if (Player1.bIsDead == true)
	{

		VectorBullets.clear();
		Round+=  1;

		InitializePlayers();

	}
}

//Render()

bool FPlayer::Draw(int PositionX, int PositionY, olc::Pixel P = olc::RED)
{
	float TempX, TempY;
	OutCoordinates((float)PositionX, (float)PositionY, TempX, TempY);

	return PixelGameEngine::Draw(TempX, TempY, P);

}





void FPlayer::LoadSprites() 
{

	Ship1 = new olc::Sprite("./Sprites/ShipSprite.png");
	Player1.DecalShip = new olc::Decal(Ship1);
	//DrawDecal(Player1.Position, Player1.DecalShip, {10.0f,10.0f},olc::WHITE);
	DrawRotatedDecal(Player1.Position, Player1.DecalShip, Player1.Angle, { 400.0f,300.0f }, { 0.03f,0.03f }, olc::WHITE);
	OutCoordinates(Player1.Position.x, Player1.Position.y, Player1.Position.x, Player1.Position.y);
}


void FPlayer::DrawBehindLine()
{
	olc::vf2d BackDirection;
	BackDirection.x = -sinf(Player1.Angle);
	BackDirection.y = cosf(Player1.Angle);
	olc::vf2d ShipTail = 6.f * BackDirection + Player1.Position;
	
	DrawLine(Player1.Position, (Player1.Position + BackDirection.perp()*1.70f), olc::MAGENTA);
	std::cout << ShipTail << "  " << Player1.Position << std::endl;
	//DrawRect()
}
void FPlayer::Collision()
{
	olc::vf2d  FrontDirection;
	FrontDirection.x = sinf(Player1.Angle);
	FrontDirection.y = -cosf(Player1.Angle);
	olc::vf2d ShipTip = 6.f * FrontDirection + Player1.Position;
	if (GetDrawTarget()->GetPixel(ShipTip.x, ShipTip.y) == olc::MAGENTA) 
	{
		Player1.Score -= 10;
		InitializePlayers();
	}
}
void FPlayer::HudDisplay()
{
	DrawString(8, 8, "Score Player 1: " + std::to_string(Player1.Score) + "\t" +"Score Player 2: "+std::to_string(Player2.Score)+"\t" + "Round: " + std::to_string(Round), olc::YELLOW);
}



void FPlayer::UpdateAndDrawVectorBullets(float ElapsedTime)
{
	for (auto& Bullet : VectorBullets)
	{
		Bullet.Position.x += Bullet.Velocity.x * ElapsedTime;
		Bullet.Position.y += Bullet.Velocity.y * ElapsedTime;
		OutCoordinates(Bullet.Position.x, Bullet.Position.y, Bullet.Position.x, Bullet.Position.y);
		Draw(Bullet.Position.x, Bullet.Position.y);


	}
}

bool FPlayer::InitialConditions()
{

	InitializePlayers();

	return true;
}

bool FPlayer::UpdatingGame(float ElapsedTime)
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
		
		void Collision();
		MovePlayer1(ElapsedTime);
		//DrawPlayer1();
		ShootBullet(ElapsedTime);
		UpdateAndDrawVectorBullets(ElapsedTime);
		DestroyVectorBullets();
		DrawBehindLine();
		LoadSprites();
		HudDisplay();
		IsDead();


	}
	return true;
}

