#define OLC_PGE_APPLICATION
#include <algorithm>
#include "olcPixelGameEngine.h"


class FAsteroidGame : public olc::PixelGameEngine
{
public:
	FAsteroidGame()
	{
		sAppName = "Asteroids";
	}
private:

	struct FSpaceObject
	{
		float PositionX;
		float PositionY;
		float DeltaX;
		float DeltaY;
		int Size;
		float Angle;
		bool bDead;
	};
	std::vector <FSpaceObject> VecAsteroid;

	

	FSpaceObject VectorPlayer;

	std::vector<std::pair<float, float>> ShipModel;
	std::vector<std::pair<float, float>> AsteroidModel;
	int Level = 1;
	int Score = 0;

protected:

	void WrapCoordinates(float CoordinatesX, float CoordinatesY, float& WrapedX, float& WrapedY)
	{
		WrapedX = CoordinatesX;
		WrapedY = CoordinatesY;
		if (CoordinatesX < 0.0f)
		{
			WrapedX = CoordinatesX + (float)ScreenWidth();
		}
		if (CoordinatesX > ScreenWidth())
		{
			WrapedX = CoordinatesX - (float)ScreenWidth();
		}

		if (CoordinatesY < 0.0f)
		{
			WrapedY = CoordinatesY + (float)ScreenHeight();
		}
		if (CoordinatesY > ScreenHeight())
		{
			WrapedY = CoordinatesY - (float)ScreenHeight();
		}
	}

	void GiveColorToTheBackGround()
	{
		FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::BLACK);
	}

	virtual void InitializeCharacteristicsVectorPlayer()
	{
		//Inicialise VectorPlayer position
		VectorPlayer.PositionX = ScreenWidth() / 2.0f;
		VectorPlayer.PositionY = ScreenHeight() / 2.0f;
		VectorPlayer.DeltaX = 0.0f;
		VectorPlayer.DeltaY = 0.0f;
		VectorPlayer.Angle = 0.0f;
		VectorPlayer.bDead = false;
		ShipModel =
		{
			{0.0f,-15.0f},
			{-5.0f , +5.0f},
			{+5.0f,+5.0f}
		};
	}
	void InitializeCharacteristicsVectorAsteroid()
	{
		int Verts = 20;
		for (int i = 0; i < Verts; i++)
		{
			float RandomValue = ((float)rand() / (float)RAND_MAX) * 0.3f;
			float AsteroidRadius = 1.0f + RandomValue;
			float Angle = ((float)i / float(Verts) * 6.28318f);
			AsteroidModel.push_back(std::make_pair(AsteroidRadius * sinf(Angle), AsteroidRadius * cosf(Angle)));
		}
	}


	virtual bool Draw(int PositionX, int PositionY, olc::Pixel P = olc::RED)override
	{
		float TempX, TempY;
		WrapCoordinates((float)PositionX, (float)PositionY, TempX, TempY);

		return PixelGameEngine::Draw(TempX, TempY, P);

	}

	void AccelerateShip(float ElapsedTime)
	{
		if (GetKey(olc::Key::UP).bHeld)
		{
			VectorPlayer.DeltaX += sin(VectorPlayer.Angle) * 50.0f * ElapsedTime;
			VectorPlayer.DeltaY += -cos(VectorPlayer.Angle) * 50.0f * ElapsedTime;
		}
	}
	void ReverseShip(float ElapsedTime)
	{
		if (GetKey(olc::Key::DOWN).bHeld)
		{
			VectorPlayer.DeltaX += sin(VectorPlayer.Angle) * -50.0f * ElapsedTime;
			VectorPlayer.DeltaY += -cos(VectorPlayer.Angle) * -50.0f * ElapsedTime;
		}
	}

	void ChangeVelocity(float ElapsedTime)
	{
		VectorPlayer.PositionX += VectorPlayer.DeltaX * ElapsedTime;
		VectorPlayer.PositionY += VectorPlayer.DeltaY * ElapsedTime;
	}

	void TurningShip(float ElapsedTime)
	{
		if (GetKey(olc::Key::RIGHT).bHeld)
		{
			VectorPlayer.Angle += 5.0f * ElapsedTime;
		}

		else if (GetKey(olc::Key::LEFT).bHeld)
		{
			VectorPlayer.Angle -= 5.0f * ElapsedTime;
		}
	}



	void DrawShip()
	{
		WrapCoordinates(VectorPlayer.PositionX, VectorPlayer.PositionY, VectorPlayer.PositionX, VectorPlayer.PositionY);
		DrawWireFrameModel(ShipModel, VectorPlayer.PositionX, VectorPlayer.PositionY, VectorPlayer.Angle);
	}

	void DrawWireFrameModel(const std::vector<std::pair<float, float>>& vecModelCoordinates, float PositionX, float PositionY, float TurningRadius = 0.0f, float Scale = 1.0f, olc::Pixel P = olc::WHITE)
	{

		std::vector<std::pair<float, float>> TransformedCoordinates;
		int Verts = vecModelCoordinates.size();
		TransformedCoordinates.resize(Verts);

		// Rotate
		for (int i = 0; i < Verts; i++)
		{
			TransformedCoordinates[i].first = vecModelCoordinates[i].first * cosf(TurningRadius) - vecModelCoordinates[i].second * sinf(TurningRadius);
			TransformedCoordinates[i].second = vecModelCoordinates[i].first * sinf(TurningRadius) + vecModelCoordinates[i].second * cosf(TurningRadius);
		}

		// Scale
		for (int i = 0; i < Verts; i++)
		{
			TransformedCoordinates[i].first = TransformedCoordinates[i].first * Scale;
			TransformedCoordinates[i].second = TransformedCoordinates[i].second * Scale;
		}

		// Translate
		for (int i = 0; i < Verts; i++)
		{
			TransformedCoordinates[i].first = TransformedCoordinates[i].first + PositionX;
			TransformedCoordinates[i].second = TransformedCoordinates[i].second + PositionY;
		}

		// Draw Closed Polygon
		for (int i = 0; i < Verts + 1; i++)
		{
			int j = (i + 1);
			DrawLine(TransformedCoordinates[i % Verts].first, TransformedCoordinates[i % Verts].second,
				TransformedCoordinates[j % Verts].first, TransformedCoordinates[j % Verts].second, P);
		}
	}
	
	
	void HudDisplay()
	{
		DrawString(8, 8, "Score: " + std::to_string(Score) + "\t" + "Level: " + std::to_string(Level), olc::YELLOW);
	}

	bool WinGame()
	{
		int MaxLevel = 4;
		if (Level >= MaxLevel)
		{
			ShipModel.clear();
			AsteroidModel.clear();
			VectorBullets.clear();

			DrawString(60, 100, "You Win", olc::GREEN, 10);
			return true;
		}
		else
		{
			return false;
		}

	}
	void LevelUp()
	{
		if (VecAsteroid.empty())
		{
			Level += 1;
			// Level Clear
			Score += 1000; // Large score for level progression
			VecAsteroid.clear();
			VectorBullets.clear();
			if (Level == 2)
			{
				VecAsteroid.push_back({ 30.0f * sinf(VectorPlayer.Angle - 3.14159f / 2.0f) + VectorPlayer.PositionX,
												  30.0f * cosf(VectorPlayer.Angle - 3.14159f / 2.0f) + VectorPlayer.PositionY,
												  10.0f * sinf(VectorPlayer.Angle), 10.0f * cosf(VectorPlayer.Angle),(int)15, 0.0f,false });


				VecAsteroid.push_back({ 30.0f * sinf(VectorPlayer.Angle - 3.14159f / 2.0f) + VectorPlayer.PositionX,
												  40.0f * cosf(VectorPlayer.Angle - 3.14159f / 2.0f) + VectorPlayer.PositionY,
												  40.0f * sinf(VectorPlayer.Angle), 10.0f * cosf(VectorPlayer.Angle),(int)15, 0.0f,false });
			}
			else if (Level == 3)
			{
				VecAsteroid.push_back({ 30.0f * sinf(VectorPlayer.Angle - 3.14159f / 2.0f) + VectorPlayer.PositionX,
												  40.0f * cosf(VectorPlayer.Angle - 3.14159f / 2.0f) + VectorPlayer.PositionY,
												  10.0f * sinf(VectorPlayer.Angle), 10.0f * cosf(VectorPlayer.Angle),(int)15, 0.0f,false });


				VecAsteroid.push_back({ 30.0f * sinf(VectorPlayer.Angle - 3.14159f / 2.0f) + VectorPlayer.PositionX,
												  40.0f * cosf(VectorPlayer.Angle - 3.14159f / 2.0f) + VectorPlayer.PositionY,
												  10.0f * sinf(VectorPlayer.Angle), 10.0f * cosf(VectorPlayer.Angle),(int)15, 0.0f,false });
				VecAsteroid.push_back({ 100.0f * sinf(VectorPlayer.Angle - 3.14159f / 2.0f) + VectorPlayer.PositionX,
												  40.0f * cosf(VectorPlayer.Angle - 3.14159f / 2.0f) + VectorPlayer.PositionY,
												  10.0f * sinf(VectorPlayer.Angle), 10.0f * cosf(VectorPlayer.Angle),(int)15, 0.0f,false });

			}
			else if (Level == 4)
			{
				VecAsteroid.push_back({ 30.0f * sinf(VectorPlayer.Angle - 3.14159f / 2.0f) + VectorPlayer.PositionX,
												  30.0f * cosf(VectorPlayer.Angle - 3.14159f / 2.0f) + VectorPlayer.PositionY,
												  10.0f * sinf(VectorPlayer.Angle), 10.0f * cosf(VectorPlayer.Angle),(int)15, 0.0f,false });


				VecAsteroid.push_back({ 30.0f * sinf(VectorPlayer.Angle - 3.14159f / 2.0f) + VectorPlayer.PositionX,
												  30.0f * cosf(VectorPlayer.Angle - 3.14159f / 2.0f) + VectorPlayer.PositionY,
												  10.0f * sinf(VectorPlayer.Angle), 10.0f * cosf(VectorPlayer.Angle),(int)15, 0.0f,false });

				VecAsteroid.push_back({ 100.0f * sinf(VectorPlayer.Angle - 3.14159f / 2.0f) + VectorPlayer.PositionX,
												  40.0f * cosf(VectorPlayer.Angle - 3.14159f / 2.0f) + VectorPlayer.PositionY,
												  10.0f * sinf(VectorPlayer.Angle), 10.0f * cosf(VectorPlayer.Angle),(int)15, 0.0f,false });

				VecAsteroid.push_back({ 70.0f * sinf(VectorPlayer.Angle - 3.14159f / 2.0f) + VectorPlayer.PositionX,
												  40.0f * cosf(VectorPlayer.Angle - 3.14159f / 2.0f) + VectorPlayer.PositionY,
												  10.0f * sinf(VectorPlayer.Angle), 10.0f * cosf(VectorPlayer.Angle),(int)15, 0.0f,false });


			}

		}
	}

	void AppendVectorNewAsteroids()
	{
		for (const auto& NewAsteroid : VectorNewAsteroids)
		{
			VecAsteroid.push_back(NewAsteroid);
		}
		VectorNewAsteroids.clear();
	}

	void UpdateAndDrawAsteroids(float ElapsedTime)
	{
		for (auto& AsteroidObject : VecAsteroid)
		{
			AsteroidObject.PositionX += AsteroidObject.DeltaX * ElapsedTime;
			AsteroidObject.PositionY += AsteroidObject.DeltaY * ElapsedTime;
			WrapCoordinates(AsteroidObject.PositionX, AsteroidObject.PositionY, AsteroidObject.PositionX, AsteroidObject.PositionY);
			DrawWireFrameModel(AsteroidModel, AsteroidObject.PositionX, AsteroidObject.PositionY, AsteroidObject.Angle, AsteroidObject.Size);

		}
	}

	std::vector<FSpaceObject> VectorBullets;

	//VectorBullets
	void ShotBullet(float ElapsedTime)
	{
		if (GetKey(olc::Key::SPACE).bReleased)
		{
			VectorBullets.push_back({ VectorPlayer.PositionX,VectorPlayer.PositionY,50.0f * sinf(VectorPlayer.Angle),-50.0f * cosf(VectorPlayer.Angle),0,0 });
		}
	}
	std::vector<FSpaceObject> VectorNewAsteroids;

	void UpdateAndDrawVectorBullets(float ElapsedTime)
	{
		for (auto& Bullet : VectorBullets)
		{
			Bullet.PositionX += Bullet.DeltaX * ElapsedTime;
			Bullet.PositionY += Bullet.DeltaY * ElapsedTime;
			WrapCoordinates(Bullet.PositionX, Bullet.PositionY, Bullet.PositionX, Bullet.PositionY);
			Draw(Bullet.PositionX, Bullet.PositionY);


			for (auto& Asteroid : VecAsteroid)
			{
				if (Collision(Asteroid.PositionX, Asteroid.PositionY, Asteroid.Size, Bullet.PositionX, Bullet.PositionY))
				{
					//Asteroid hit
					Bullet.PositionX = -200;
					if (Asteroid.Size > 4)
					{
						float Angle1 = ((float)rand() / (float)RAND_MAX) * 6.283185f;
						float Angle2 = ((float)rand() / (float)RAND_MAX) * 6.283185f;
						VectorNewAsteroids.push_back({ Asteroid.PositionX, Asteroid.PositionY,10.0f * sinf(Angle1),10.0f * cosf(Angle1),(int)Asteroid.Size >> 1, 0.0f });
						VectorNewAsteroids.push_back({ Asteroid.PositionX, Asteroid.PositionY,10.0f * sinf(Angle2),10.0f * cosf(Angle2),(int)Asteroid.Size >> 1, 0.0f });
					}
					Asteroid.PositionX = -100;
					Score += 100;
				}
			}
		}
	}



	void DestroyVectorBullets()
	{
		if (VectorBullets.size() > 0)
		{
			auto Destroy =
				remove_if(VectorBullets.begin(), VectorBullets.end(), [&](FSpaceObject BulletDestroy)
					{
						return (BulletDestroy.PositionX < 1 || BulletDestroy.PositionY < 1 || BulletDestroy.PositionX >= ScreenWidth() || BulletDestroy.PositionY >= ScreenHeight());
					});
			if (Destroy != VectorBullets.end())
			{
				VectorBullets.erase(Destroy);
			}
		}
	}

	void DestroyAsteroids()
	{
		if (VecAsteroid.size() > 0)
		{
			auto Destroy =
				remove_if(VecAsteroid.begin(), VecAsteroid.end(), [&](FSpaceObject AsteroidDestroy)
					{
						return (AsteroidDestroy.PositionX < 0);
					});
			if (Destroy != VecAsteroid.end())
			{
				VecAsteroid.erase(Destroy);
			}
		}
	}

	bool Collision(float AsteroidCenterX, float AsteroidCenterY, float Radius, float PositionX, float PositionY)
	{
		return sqrt(((PositionX - AsteroidCenterX) * (PositionX - AsteroidCenterX)) + ((PositionY - AsteroidCenterY) * (PositionY - AsteroidCenterY))) < Radius;
	}

	void DetectShipCollisionWithAsteroid()
	{
		for (auto& Asteroid : VecAsteroid)
		{
			if (Collision(Asteroid.PositionX, Asteroid.PositionY, Asteroid.Size, VectorPlayer.PositionX, VectorPlayer.PositionY))
			{
				VectorPlayer.bDead = true;
			}
		}
	}

	void bDead()
	{
		if (VectorPlayer.bDead == true)
		{
			VecAsteroid.clear();
			VectorBullets.clear();
			Level = 1;

			VectorPlayer.PositionX = ScreenWidth() / 2.0f;
			VectorPlayer.PositionY = ScreenHeight() / 2.0f;
			VectorPlayer.DeltaX = 0.0f;
			VectorPlayer.DeltaY = 0.0f;
			VectorPlayer.Angle = 0.0f;
			VectorPlayer.bDead = false;
			ShipModel =
			{
				{0.0f,-15.0f},
				{-5.0f , +5.0f},
				{+5.0f,+5.0f}
			};

		}
	}


	virtual bool InitialConditions()
	{
		VecAsteroid.push_back({ 50.0f,50.0f,10.0f,-15.0f,(int)20,0.0f,false });
		InitializeCharacteristicsVectorPlayer();
		InitializeCharacteristicsVectorAsteroid();
		return true;
	}

	virtual bool UpdatingGame(float ElapsedTime)
	{
		GiveColorToTheBackGround();
		if (WinGame())
		{
			std::cout<<"Press Enter for End the Game"<<std::endl;
			if (GetKey(olc::Key::ENTER).bReleased)
			{
				return false;
			}

		}
		else
		{
			UpdateAndDrawAsteroids(ElapsedTime);
			TurningShip(ElapsedTime);

			AccelerateShip(ElapsedTime);
			ReverseShip(ElapsedTime);
			ChangeVelocity(ElapsedTime);
			DrawShip();
			ShotBullet(ElapsedTime);
			UpdateAndDrawVectorBullets(ElapsedTime);
			DestroyVectorBullets();
			DestroyAsteroids();
			HudDisplay();
			DetectShipCollisionWithAsteroid();
			bDead();
			AppendVectorNewAsteroids();
			LevelUp();
		}
		return true;
	}




};
int main()
{
	FAsteroidGame Game;
	Game.Construct(420, 320, 2, 2);
	Game.Start();

	return 0;
}