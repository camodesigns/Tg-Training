#define OLC_PGE_APPLICATION
#include <algorithm>
#include "olcPixelGameEngine.h"
#include "FPlayer.h"


//UpdateGameLogic();
void FTron::ClearScreen()
{
	FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::BLACK);
}

void FTron::InitializePlayers()
{
	//Inicialise Player 1 characteristics
	Player1.Position.x = ScreenWidth();
	Player1.Position.y = ScreenHeight() + 1.f;
	Player1.Velocity.x = 0.0f;
	Player1.Velocity.y = 0.0f;
	Player1.Angle = 70.0f;
	Player1.WinRounds = 0;
	PlayerModel =
	{
		{0.0f,-15.0f},
		{-5.0f , +5.0f},
		{+5.0f,+5.0f}
	};

	Player2.Position.x = ScreenWidth() - 1.0f;
	Player2.Position.y = ScreenHeight() / 200.f;
	Player2.Velocity.x = 0.0f;
	Player2.Velocity.y = 0.0f;
	Player2.Angle = 10.0f;
	Player2.WinRounds = 0;
	PlayerModel =
	{
		{0.0f,-15.0f},
		{-5.0f , +5.0f},
		{+5.0f,+5.0f}
	};

}

void FTron::MovePlayers(float ElapsedTime)
{
	//Constant move of player in front

	//Player1.Velocity.x = 120.0f;
	//Player1.Velocity.y = 120.0f;
	//Player1.Position.x += sin(Player1.Angle) * Player1.Velocity.x * ElapsedTime;
	//Player1.Position.y += -cos(Player1.Angle) * Player1.Velocity.y * ElapsedTime;

	//if (GetKey(olc::Key::D).bHeld)
	//{
	//	Player1.Angle += 5.0f * ElapsedTime;
	//}

	//else if (GetKey(olc::Key::A).bHeld)
	//{
	//	Player1.Angle -= 5.0f * ElapsedTime;
	//}

	Player2.Velocity.x = 120.0f;
	Player2.Velocity.y = 120.0f;
	Player2.Position.x += sin(Player2.Angle) * Player2.Velocity.x * ElapsedTime;
	Player2.Position.y += -cos(Player2.Angle) * Player2.Velocity.y * ElapsedTime;

	if (GetKey(olc::Key::RIGHT).bHeld)
	{
		Player2.Angle += 5.0f * ElapsedTime;
	}

	else if (GetKey(olc::Key::LEFT).bHeld)
	{
		Player2.Angle -= 5.0f * ElapsedTime;
	}
}

/*void FTron::ShootBullet(float ElapsedTime)
{
	if (GetKey(olc::Key::SPACE).bReleased)
	{
		VectorBullets.push_back({ {Player1.Position.x,Player1.Position.y},{50.0f * sinf(Player1.Angle),-50.0f * cosf(Player1.Angle)},0,0 });
	}
}*/

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

	if (Player1.WinRounds == 3)
	{
		PlayerModel.clear();
		//VectorBullets.clear();
		DrawString(60, 100, "Player 1 Win", olc::GREEN, 4);
		return true;
	}
	else if (Player2.WinRounds == 3)
	{
		PlayerModel.clear();
		//VectorBullets.clear();
		DrawString(100, 200, "Player 2 Win", olc::GREEN, 4);
		return true;
	}
	return false;


}

/*void FTron::DestroyVectorBullets()
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
}*/

bool FTron::Collision(const FPlayer& Player)const
{
	olc::vf2d ShipTip = Player.GetShipTip();
	olc::vf2d RightWing = Player.GetRightWing();
	olc::vf2d LeftWing = Player.GetLefttWing();
	return GetDrawTarget()->GetPixel(ShipTip.x, ShipTip.y) == olc::MAGENTA || GetDrawTarget()->GetPixel(ShipTip.x, ShipTip.y) == olc::GREEN || GetDrawTarget()->GetPixel(RightWing.x, RightWing.y) == olc::GREEN || GetDrawTarget()->GetPixel(RightWing.x, RightWing.y) == olc::MAGENTA || GetDrawTarget()->GetPixel(LeftWing.x, LeftWing.y) == olc::GREEN || GetDrawTarget()->GetPixel(LeftWing.x, RightWing.y) == olc::MAGENTA;
}

void FTron::ActivateLine(float ElapsedTime)
{
	if (GetKey(olc::Key::F).bHeld)
	{

	}
	else
	{
		DrawBehindLine(ElapsedTime, Player1, olc::MAGENTA);
	}
	if (GetKey(olc::Key::M).bHeld)
	{

	}
	else
	{
		DrawBehindLine(ElapsedTime, Player2, olc::GREEN);
	}

}

olc::vf2d FTron::FPlayer::GetBackDirection()const
{
	olc::vf2d BackDirection;
	BackDirection.x = -sinf(Angle);
	BackDirection.y = cosf(Angle);
	return BackDirection;
}

olc::vf2d FTron::FPlayer::GetShipTip()const
{
	olc::vf2d  FrontDirection;
	FrontDirection.x = sinf(Angle);
	FrontDirection.y = -cosf(Angle);
	olc::vf2d ShipTip = 6.0f * FrontDirection + Position;
	return ShipTip;
}
olc::vf2d FTron::FPlayer::GetShipTail()const
{
	olc::vf2d BackDirection;
	BackDirection.x = -sinf(Angle);
	BackDirection.y = cosf(Angle);
	olc::vf2d ShipTail = 6.f * BackDirection + Position;
	return ShipTail;
}

olc::vf2d FTron::FPlayer::GetLefttWing()const
{
	olc::vf2d LeftWing = Position - GetBackDirection().perp() * 4.0f;
	
	return LeftWing;

}

olc::vf2d FTron::FPlayer::GetRightWing()const
{
	olc::vf2d RightWing = Position - GetBackDirection().perp() * 4.0f;
	return RightWing;
}

void FTron::ResetPlayers()
{
	Player1.Position.x = ScreenWidth() / 16.0f;
	Player1.Position.y = ScreenHeight() / 1.2f;
	Player1.Velocity.x = 0.0f;
	Player1.Velocity.y = 0.0f;
	Player1.Angle = 0.0f;

	PlayerModel =
	{
		{0.0f,-15.0f},
		{-5.0f , +5.0f},
		{+5.0f,+5.0f}
	};
	ClearScreen();
	Player2.Position.x = ScreenWidth() / 2.0f;
	Player2.Position.y = ScreenHeight() / 1.2f;
	Player2.Velocity.x = 0.0f;
	Player2.Velocity.y = 0.0f;
	Player2.Angle = 0.0f;
	PlayerModel =
	{
		{0.0f,-15.0f},
		{-5.0f , +5.0f},
		{+5.0f,+5.0f}
	};
}

//Render()

bool FTron::Draw(int PositionX, int PositionY, olc::Pixel P = olc::RED)
{
	float TempX, TempY;
	OutCoordinates((float)PositionX, (float)PositionY, TempX, TempY);

	return PixelGameEngine::Draw(TempX, TempY, P);

}

void FTron::LoadSprites()
{
	Ship1 = new olc::Sprite("./Sprites/ShipSprite.png");
	Player1.DecalShip = new olc::Decal(Ship1);

	Ship2 = new olc::Sprite("./Sprites/ShipSprite.png");
	Player2.DecalShip = new olc::Decal(Ship2);

}

void FTron::DrawRotatedDecals(FPlayer Player, olc::Pixel P)
{
	DrawRotatedDecal(Player.Position, Player.DecalShip, Player.Angle, { 350.0f,400.0f }, { 0.02f,0.02f }, P);
}


void FTron::DrawBehindLine(float ElapsedTime, FPlayer Player, olc::Pixel P)
{
	olc::vf2d ShipTail = 6.f * Player.GetBackDirection() + Player.Position;
	olc::vf2d  FrontDirection = -Player.GetBackDirection();
	olc::vf2d ShipTip = 8.0f * FrontDirection + Player.Position;

	olc::vf2d VelocityDirection = 50.f * FrontDirection * ElapsedTime;
	float Magnitude = VelocityDirection.mag();
	std::cout << "  " << Magnitude << std::endl;

	for (int i = 0; i <= (int)Magnitude; i++)
	{
		DrawLine((Player.Position - Player.GetBackDirection().perp() * 1.70f) - (float)i * VelocityDirection.norm(), (Player.Position +Player.GetBackDirection().perp() * 1.70f) - (float)i * VelocityDirection.norm(), P);
	}
}

void FTron::HudDisplay()
{
	DrawString(8, 8, "Win Rounds Player 1: " + std::to_string(Player1.WinRounds) + "\t" + "Win Rounds Player 2: " + std::to_string(Player2.WinRounds) + "\t" + "Round: " + std::to_string(Round), olc::YELLOW, 1);
}

//void FTron::UpdateAndDrawVectorBullets(float ElapsedTime)
//{
//	for (auto& Bullet : VectorBullets)
//	{
//		Bullet.Position.x += Bullet.Velocity.x * ElapsedTime;
//		Bullet.Position.y += Bullet.Velocity.y * ElapsedTime;
//		OutCoordinates(Bullet.Position.x, Bullet.Position.y, Bullet.Position.x, Bullet.Position.y);
//		Draw(Bullet.Position.x, Bullet.Position.y);
//	}
//}

bool FTron::InitialConditions()
{


	InitializePlayers();
	LoadSprites();
	return true;
}

bool FTron::UpdatingGame(float ElapsedTime)
{
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
		MovePlayers(ElapsedTime);
		/*ShootBullet(ElapsedTime);
		UpdateAndDrawVectorBullets(ElapsedTime);
		DestroyVectorBullets();*/
		DrawRotatedDecals(Player1, olc::WHITE);
		DrawRotatedDecals(Player2, olc::YELLOW);
		ActivateLine(ElapsedTime);
		OutCoordinates(Player1.Position.x, Player1.Position.y, Player1.Position.x, Player1.Position.y);
		OutCoordinates(Player2.Position.x, Player2.Position.y, Player2.Position.x, Player2.Position.y);
		if (Collision(Player1))
		{
			Player2.WinRounds += 1;
			ResetPlayers();
			Round += 1;
		}

		else if (Collision(Player2))
		{
			Player1.WinRounds += 1;
			ResetPlayers();
			Round += 1;
		}
		HudDisplay();

	}
	return true;
}

