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

	struct FSpaceObject
	{
		olc::vf2d Position;
		olc::vf2d Velocity;
		int Size;
		float Angle;
		bool bIsDead;
		float Speed;
	};
	FSpaceObject Player;
	FSpaceObject Line;
	std::vector<std::pair<float, float>> PlayerModel;

	int Level = 1;
	int Score = 0;
protected:
	//Update Logic
	virtual void InitializePlayer();
	void MovePlayer(float ElapsedTime);
	//UpdatePhysics
	void OutCoordinates(const float CoordinatesX, const float CoordinatesY, float& WrappedX, float& WrappedY);
	bool HasWon();
	void DestroyVectorBullets();
	void ShootBullet(float ElapsedTime);
	bool Collision(float AsteroidCenterX, float AsteroidCenterY, float Radius, float PositionX, float PositionY);
	void bIsDead();
	virtual bool InitialConditions();
	virtual bool UpdatingGame(float ElapsedTime);

	//Render
	void ClearScreen();
	virtual bool Draw(int PositionX, int PositionY, olc::Pixel P )override;
	void DrawPlayer();
	void DrawWireFrameModel(const std::vector<std::pair<float, float>>& vecModelCoordinates, float PositionX, float PositionY, float TurningRadius , float Scale , olc::Pixel P );
	void HudDisplay();
	std::vector<FSpaceObject> VectorBullets;
	void UpdateAndDrawVectorBullets(float ElapsedTime);
	void DrawBehindLine();
	
	
};