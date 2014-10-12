#include "vec2d.h"
#include "CollisionDetection.h"
#include <math.h>

CollisionDetection::CollisionDetection(ship* pship, ProjectileManager* pproj_manager, AsteroidManager* past_manager)
{
	player = pship;
	proj_manager = pproj_manager;
	ast_manager = past_manager;
	
}

void CollisionDetection::check_projectile_asteroid()
{
	std::vector<asteroid*>::iterator a_it;
	std::vector<projectile*>::iterator p_it;
	std::vector<asteroid*> new_asteroids;
	float destroyed_size;
	float new_size;
	float angle;
	vec2d vel;
	vec2d destroyed_location;
	vec2d dist;

	for (a_it = ast_manager->AsteroidVec.begin(); a_it != ast_manager->AsteroidVec.end(); a_it++)
	{
		ast_manager->a = *a_it;

		for (p_it = proj_manager->ProjectileVec.begin(); p_it != proj_manager->ProjectileVec.end(); p_it++)
		{
			proj_manager->p = *p_it;
			
			dist = ast_manager->a->position - proj_manager->p->position;
			
			if (dist.length() < ast_manager->a->size)
			{

				proj_manager->p->life = -1;
				ast_manager->a->life = -1;
				destroyed_size = ast_manager->a->size;
				new_size = destroyed_size/2;
				destroyed_location = ast_manager->a->position;
				angle = rand() % 359;
				vel.x = cos(angle) * ast_manager->a->velocity.x;
				vel.y = sin(angle) * ast_manager->a->velocity.y;				
				//vel.y = ((rand() % 100) - 50) / 1000.0;

				asteroid* new_ast1 = new asteroid(	new_size, // size
									destroyed_location.x + new_size, // x pos
									destroyed_location.y + new_size, // y pos
									vel.x, // x vel
									vel.y, // y vel
									((rand() % 50) - 25) / 10.0); // rotational speed
				asteroid* new_ast2 = new asteroid(	new_size, // size
									destroyed_location.x - new_size, // x pos
									destroyed_location.y - new_size, // y pos
									-vel.x, // x vel
									-vel.y, // y vel
									((rand() % 50) - 25) / 10.0); // rotational speed
				
				new_asteroids.push_back(new_ast1);
				new_asteroids.push_back(new_ast2);
				
				new_ast1 = NULL;
				new_ast2 = NULL;


			}


		}

	
	}
	
	for (a_it = new_asteroids.begin(); a_it != new_asteroids.end(); a_it++)
	{
		ast_manager->add_asteroid(*a_it);
	}

}

void CollisionDetection::check_asteroid_asteroid()
{
	std::vector<asteroid*>::iterator a1_it;
	std::vector<asteroid*>::iterator a2_it;
	std::vector<asteroid*> new_asteroids;
	asteroid * a1;
	asteroid * a2;
	float destroyed_size;
	float new_size;
	float angle;
	vec2d vel;
	vec2d destroyed_location;
	vec2d dist;

	for (a1_it = ast_manager->AsteroidVec.begin(); a1_it != ast_manager->AsteroidVec.end(); a1_it++)
	{
		//ast_manager->a = *a_it;

		//for (p_it = proj_manager->ProjectileVec.begin(); p_it != proj_manager->ProjectileVec.end(); p_it++)
		//{
			//proj_manager->p = *p_it;
			
			a1
			
			/*if (dist.length() < ast_manager->a->size)
			{

				proj_manager->p->life = -1;
				ast_manager->a->life = -1;
				destroyed_size = ast_manager->a->size;
				new_size = destroyed_size/2;
				destroyed_location = ast_manager->a->position;
				angle = rand() % 359;
				vel.x = cos(angle) * ast_manager->a->velocity.x;
				vel.y = sin(angle) * ast_manager->a->velocity.y;				
				//vel.y = ((rand() % 100) - 50) / 1000.0;

				asteroid* new_ast1 = new asteroid(	new_size, // size
									destroyed_location.x + new_size, // x pos
									destroyed_location.y + new_size, // y pos
									vel.x, // x vel
									vel.y, // y vel
									((rand() % 50) - 25) / 10.0); // rotational speed
				asteroid* new_ast2 = new asteroid(	new_size, // size
									destroyed_location.x - new_size, // x pos
									destroyed_location.y - new_size, // y pos
									-vel.x, // x vel
									-vel.y, // y vel
									((rand() % 50) - 25) / 10.0); // rotational speed
				
				new_asteroids.push_back(new_ast1);
				new_asteroids.push_back(new_ast2);
				
				new_ast1 = NULL;
				new_ast2 = NULL;


			}*/


		//}

	
	}
	
	for (a1_it = new_asteroids.begin(); a1_it != new_asteroids.end(); a1_it++)
	{
		ast_manager->add_asteroid(*a1_it);
	}

}
