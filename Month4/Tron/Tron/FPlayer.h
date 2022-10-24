#include "olcPixelGameEngine.h"
#pragma once
class FTron : public olc::PixelGameEngine
{
public:
	FTron()
	{
		sAppName = "Tron";
	}
private:

	class FPlayer
	{
	public:
		olc::vf2d Position;
		olc::vf2d Velocity;
		int Size;
		float Angle;
		int WinRounds;
		olc::Decal* DecalShip = nullptr;
		olc::vf2d GetShipTip()const;
		olc::vf2d GetShipTail()const;
		olc::vf2d GetRightWing()const;
		olc::vf2d GetLefttWing()const;
		olc::vf2d GetBackDirection()const;
	};
	
	FPlayer Player1;
	FPlayer Player2;
	
	std::vector<std::pair<float, float>> PlayerModel;
	int Round = 1;
protected:
	//Update Logic
	virtual void InitializePlayers();
	void MovePlayers(float ElapsedTime);

	//UpdatePhysics
	void OutCoordinates(const float CoordinatesX, const float CoordinatesY, float& WrappedX, float& WrappedY);
	bool HasWon();
	//void DestroyVectorBullets();
	//void ShootBullet(float ElapsedTime);
	void ActivateLine(float ElapsedTime);
	bool Collision(const FPlayer& Player)const;
	void ResetPlayers();
	virtual bool InitialConditions() override;
	virtual bool UpdatingGame(float ElapsedTime) override;
	
	//Render+
	void LoadSprites();
	void ClearScreen();
	virtual bool Draw(int PositionX, int PositionY, olc::Pixel P )override;
	void HudDisplay();
	//std::vector<FPlayer> VectorBullets;
	//void UpdateAndDrawVectorBullets(float ElapsedTime);
	void DrawBehindLine(float ElapsedTime,FPlayer Player, olc::Pixel P);
	void DrawRotatedDecals(FPlayer Player, olc::Pixel P);

public:
	olc::Sprite* Ship1 = nullptr;
	olc::Sprite* Ship2 = nullptr;
	
	
};