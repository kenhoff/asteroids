#include <vector>
#include "projectile.h"
/* ProjectileManager

add projectile
delete projectile
cull dead projectiles
update/draw projectiles

*/

#ifndef PROJECTILE_MANAGER
#define PROJECTILE_MANAGER

class ProjectileManager{

	public:
		std::vector<projectile*> ProjectileVec;
		projectile* p;
		void add_projectile(projectile* new_projectile);
		void delete_projectile();
		void cull_projectiles();
		void draw_projectiles();

};

#endif
