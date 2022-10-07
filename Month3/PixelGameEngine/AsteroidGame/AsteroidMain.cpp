#define OLC_PGE_APPLICATION
#include <algorithm>
#include "olcPixelGameEngine.h"


class AsteroidGame : public olc::PixelGameEngine
{
public:
	AsteroidGame()
	{
		sAppName = "Asteroids";
	}
private:

	struct SpaceObject
	{
		float PosX;
		float PosY;
		float DisplacementX;
		float DisplacementY;
		int Size;
		float Angle;

	};
	std::vector <SpaceObject> VecAsteroid;
	std::vector<SpaceObject> Bullets;
	std::vector<SpaceObject> NewAsteroids;

	SpaceObject Player;

	std::vector<std::pair<float, float>> ModelShip;
	std::vector<std::pair<float, float>> ModelAsteroids;
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
		if (CoordinatesY > ScreenWidth())
		{
			WrapedY = CoordinatesY - (float)ScreenHeight();
		}
	}

	void BackgroundColor()
	{
		FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::BLACK);
	}
	virtual void InitialCharacteristicsPlayer()
	{
		//Inicialise player position
		Player.PosX = ScreenWidth() / 2.0f;
		Player.PosY = ScreenHeight() / 2.0f;
		Player.DisplacementX = 0.0f;
		Player.DisplacementY = 0.0f;
		Player.Angle = 0.0f;

		ModelShip =
		{
			{0.0f,-15.0f},
			{-5.0f , +5.0f},
			{+5.0f,+5.0f}
		};
	}
	void InitialCharateriticsAsteroid()
	{
		int Verts = 20;
		for (int i = 0; i < Verts; i++)
		{
			float RandomValue = ((float)rand() / (float)RAND_MAX) * 0.3f;
			float AsteroidRadius = 1.0f+RandomValue;
			float Angle = ((float)i / float(Verts) * 6.28318f);
			ModelAsteroids.push_back(std::make_pair(AsteroidRadius * sinf(Angle), AsteroidRadius * cosf(Angle)));
		}
	}


	virtual bool Draw(int PosX, int PosY, olc::Pixel P = olc::WHITE)override
	{
		float TempX, TempY;
		WrapCoordinates((float)PosX, (float)PosY, TempX, TempY);

		return PixelGameEngine::Draw(TempX, TempY, P);

	}

	void Aceleration(float ElapsedTime)
	{
		if (GetKey(olc::Key::UP).bHeld)
		{
			Player.DisplacementX += sin(Player.Angle) * 50.0f * ElapsedTime;
			Player.DisplacementY += -cos(Player.Angle) * 50.0f * ElapsedTime;
		}
	}
	void Velocity(float ElapsedTime)
	{
		Player.PosX += Player.DisplacementX * ElapsedTime;
		Player.PosY += Player.DisplacementY * ElapsedTime;
	}

	void TurnRight(float ElapsedTime)
	{
		if (GetKey(olc::Key::RIGHT).bHeld)
		{
			Player.Angle += 5.0f * ElapsedTime;
		}
	}

	void TurnLeft(float ElapsedTime)
	{
		if (GetKey(olc::Key::LEFT).bHeld)
		{
			Player.Angle -= 5.0f * ElapsedTime;
		}
	}


	void DrawShip()
	{
		WrapCoordinates(Player.PosX, Player.PosY, Player.PosX, Player.PosY);
		DrawWireFrameModel(ModelShip, Player.PosX, Player.PosY, Player.Angle);
	}

	void DrawWireFrameModel(const std::vector<std::pair<float, float>>& vecModelCoordinates, float PosX, float PosY, float TurningRadius = 0.0f, float Scale = 1.0f, olc::Pixel P = olc::WHITE)
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
			TransformedCoordinates[i].first = TransformedCoordinates[i].first + PosX;
			TransformedCoordinates[i].second = TransformedCoordinates[i].second + PosY;
		}

		// Draw Closed Polygon
		for (int i = 0; i < Verts + 1; i++)
		{
			int j = (i + 1);
			DrawLine(TransformedCoordinates[i % Verts].first, TransformedCoordinates[i % Verts].second,
				TransformedCoordinates[j % Verts].first, TransformedCoordinates[j % Verts].second, P);
		}
	}

	/*void DrawAsteroids(float ElapsedTime)
	{
		for (auto& Asteroid : VecAsteroid)
		{
			Asteroid.PosX += Asteroid.DisplacementX * ElapsedTime;
			Asteroid.PosY += Asteroid.DisplacementY * ElapsedTime;
			WrapCoordinates(Asteroid.PosX, Asteroid.PosY, Asteroid.PosX, Asteroid.PosY);
			for (int CurrentX = 0; CurrentX < Asteroid.Size; CurrentX++)
			{
				for (int CurrentY = 0; CurrentY < Asteroid.Size; CurrentY++)
				{
					Draw(Asteroid.PosX + CurrentX, Asteroid.PosY + CurrentY, olc::BLUE);
				}
			}
		}
	}*/

	void AppendNewAsteroids() 
	{
		for (const auto &NewAsteroid : NewAsteroids) 
		{
			VecAsteroid.push_back(NewAsteroid);
		}
		NewAsteroids.clear();
	}

	void UpdateAndDrawAsteroids(float ElapsedTime)
	{
		for (auto& AsteroidObject : VecAsteroid)
		{
			AsteroidObject.PosX += AsteroidObject.DisplacementX * ElapsedTime;
			AsteroidObject.PosY += AsteroidObject.DisplacementY * ElapsedTime;
			WrapCoordinates(AsteroidObject.PosX, AsteroidObject.PosY, AsteroidObject.PosX, AsteroidObject.PosY);
			DrawWireFrameModel(ModelAsteroids, AsteroidObject.PosX, AsteroidObject.PosY, AsteroidObject.Angle,AsteroidObject.Size);

		}
	}

	//Bullets
	void ShotBullet(float ElapsedTime)
	{
		if (GetKey(olc::Key::SPACE).bReleased)
		{
			Bullets.push_back({ Player.PosX,Player.PosY,50.0f * sinf(Player.Angle),-50.0f * cosf(Player.Angle),0,0 });
		}
	}

	void UpdateAndDrawBullets(float ElapsedTime)
	{
		for (auto& Bullet : Bullets)
		{
			Bullet.PosX += Bullet.DisplacementX * ElapsedTime;
			Bullet.PosY += Bullet.DisplacementY * ElapsedTime;
			WrapCoordinates(Bullet.PosX, Bullet.PosY, Bullet.PosX, Bullet.PosY);
			Draw(Bullet.PosX, Bullet.PosY);


			for (auto& Asteroid : VecAsteroid)
			{
				if (Collition(Asteroid.PosX, Asteroid.PosY, Asteroid.Size, Bullet.PosX, Bullet.PosY)) 
				{
					//Asteroid hit
					Bullet.PosX = -200;
					if (Asteroid.Size > 4) 
					{
						float Angle1 = ((float)rand() / (float)RAND_MAX) * 6.283185f;
						float Angle2 = ((float)rand() / (float)RAND_MAX) * 6.283185f;
						NewAsteroids.push_back({ Asteroid.PosX, Asteroid.PosY,10.0f * sinf(Angle1),10.0f * cosf(Angle1),(int)Asteroid.Size >> 1, 0.0f });
						NewAsteroids.push_back({ Asteroid.PosX, Asteroid.PosY,10.0f * sinf(Angle2),10.0f * cosf(Angle2),(int)Asteroid.Size >> 1, 0.0f });
					}
					Asteroid.PosX = -100;
				}
			}
		}
	}
	
	

	void DestroyBullets()
	{
		if (Bullets.size() > 0)
		{
			auto Destroy =
				remove_if(Bullets.begin(), Bullets.end(), [&](SpaceObject BulletDestroy)
					{
						return (BulletDestroy.PosX < 1 || BulletDestroy.PosY < 1 || BulletDestroy.PosX >= ScreenWidth() || BulletDestroy.PosY >= ScreenHeight());
					});
			if (Destroy != Bullets.end()) 
			{
				Bullets.erase(Destroy);
			}
		}
	}

	void DestroyAsteroids()
	{
		if (VecAsteroid.size() > 0)
		{
			auto Destroy =
				remove_if(VecAsteroid.begin(), VecAsteroid.end(), [&](SpaceObject AsteroidDestroy)
					{
						return (AsteroidDestroy.PosX < 0);
					});
			if (Destroy != VecAsteroid.end())
			{
				VecAsteroid.erase(Destroy);
			}
		}
	}

	bool Collition(float AsteroidCenterX, float AsteroidCenterY, float Radius, float PosX, float PosY) 
	{
		return sqrt(((PosX - AsteroidCenterX) * (PosX - AsteroidCenterX)) + ((PosY - AsteroidCenterY)* (PosY - AsteroidCenterY))) < Radius;
	}

	virtual bool OnUserCreate()
	{
		VecAsteroid.push_back({ 50.0f,50.0f,10.0f,-15.0f,(int)40,0.0f });
		InitialCharacteristicsPlayer();
		InitialCharateriticsAsteroid();
		return true;
	}

	virtual bool OnUserUpdate(float ElapsedTime)
	{

		BackgroundColor();
		UpdateAndDrawAsteroids(ElapsedTime);
		//DrawAsteroids(ElapsedTime);

		TurnLeft(ElapsedTime);
		TurnRight(ElapsedTime);
		Aceleration(ElapsedTime);
		Velocity(ElapsedTime);
		DrawShip();
		ShotBullet(ElapsedTime);
		UpdateAndDrawBullets(ElapsedTime);
		DestroyBullets();
		DestroyAsteroids();

		
		AppendNewAsteroids();
		return true;
	}




};
int main()
{
	AsteroidGame Game;
	Game.Construct(720, 350, 2, 2);
	Game.Start();

	return 0;
}