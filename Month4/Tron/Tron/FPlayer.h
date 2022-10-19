#include "olcPixelGameEngine.h"
#pragma once
class FPlayer : public olc::PixelGameEngine
{
public:
	FPlayer()
	{
		sAppName = "Tron";
	}
private:

	

	struct FSpaceObject
	{
		olc::vf2d Position;
		olc::vf2d Velocity;
		int Size;
		float Angle;
		bool bIsDead;
		float Speed;
		int Score;
		olc::Decal* DecalShip = nullptr;
	};

	
	FSpaceObject Player1;
	FSpaceObject Player2;
	FSpaceObject Line;
	std::vector<std::pair<float, float>> PlayerModel;
	int Round = 1;
	int ScorePlayer1 = 0;
	int ScorePlayer2 = 0;
protected:
	//Update Logic
	virtual void InitializePlayers();
	void MovePlayer1(float ElapsedTime);

	//UpdatePhysics
	void OutCoordinates(const float CoordinatesX, const float CoordinatesY, float& WrappedX, float& WrappedY);
	bool HasWon();
	void DestroyVectorBullets();
	void ShootBullet(float ElapsedTime);
	bool Collision(float AsteroidCenterX, float AsteroidCenterY, float Radius, float PositionX, float PositionY);
	void IsDead();
	virtual bool InitialConditions() override;
	virtual bool UpdatingGame(float ElapsedTime) override;

	//Render+
	void LoadSprites();
	
	void ClearScreen();
	virtual bool Draw(int PositionX, int PositionY, olc::Pixel P )override;
	void DrawPlayer1();
	void DrawWireFrameModel(const std::vector<std::pair<float, float>>& vecModelCoordinates, float PositionX, float PositionY, float TurningRadius , float Scale , olc::Pixel P );
	void HudDisplay();
	std::vector<FSpaceObject> VectorBullets;
	void UpdateAndDrawVectorBullets(float ElapsedTime);
	void DrawBehindLine();

public:
	olc::Sprite* Ship1 = nullptr;
	olc::Sprite* Ship2 = nullptr;
	
	
};