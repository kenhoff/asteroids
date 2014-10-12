#include "ProjectileManager.h"
#include <vector>
#include "projectile.h"
#include <iostream>

void ProjectileManager::add_projectile(projectile* new_projectile)
{
	ProjectileVec.push_back(new_projectile);
}
void ProjectileManager::delete_projectile()
{
	
}


void ProjectileManager::cull_projectiles()
{
	std::vector<projectile*>::iterator it;
	for (it = ProjectileVec.begin(); it != ProjectileVec.end(); it++)
	{
		p = *it;
		if ((p->life <= 0))
		{
			if (*it == *ProjectileVec.end())
			{
				ProjectileVec.pop_back();
				break;
			}
			else
			{
				ProjectileVec.erase(it);
				break;
			}
		}
	}
}


void ProjectileManager::draw_projectiles()
{
	std::vector<projectile*>::iterator it;
	for (it = ProjectileVec.begin(); it != ProjectileVec.end(); it++)
	{
		p = *it;
		p->draw();
	}

}
