#include <vector>
#include "asteroid.h"
/* AsteroidManager

add asteroid
delete asteroid
cull dead asteroids
update/draw asteroids

*/

#ifndef ASTEROID_MANAGER
#define ASTEROID_MANAGER

class AsteroidManager{

	public:
		std::vector<asteroid*> AsteroidVec;
		asteroid* a;
		void add_asteroid(asteroid* new_asteroid);
		void delete_asteroid();
		void cull_asteroids();
		void draw_asteroids();

};

#endif
