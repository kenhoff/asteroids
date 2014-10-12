#include "AsteroidManager.h"
#include <vector>
#include "asteroid.h"
#include <iostream>

void AsteroidManager::add_asteroid(asteroid* new_asteroid)
{
	AsteroidVec.push_back(new_asteroid);
}
void AsteroidManager::delete_asteroid()
{
	//return AsteroidVec.erase(deleted_asteroid);

}


void AsteroidManager::cull_asteroids()
{

	std::vector<asteroid*>::iterator it;
	for (it = AsteroidVec.begin(); it != AsteroidVec.end(); it++)
	{
		a = *it;
		if ((a->life <= 0) || (a->size < 1))
		{

			if (*it == *AsteroidVec.end())
			{
				AsteroidVec.pop_back();

				break;
			}
			else
			{
				it = AsteroidVec.erase(it);

				break;
			}
		}
	}
}


void AsteroidManager::draw_asteroids()
{

	std::vector<asteroid*>::iterator it;
	for (it = AsteroidVec.begin(); it != AsteroidVec.end(); it++)
	{
		a = *it;
		a->draw();
	}
	
	//std::cout << AsteroidVec.size() << std::endl;

}
