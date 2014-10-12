#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <math.h>

#ifdef __APPLE__

// OpenGL mac stuff
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

#else

// OpenGL linux stuff
#include <GL/gl.h>
#include <GL/glu.h>

#endif

// SFML stuff
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "globals.h"
#include "ProjectileManager.h"
#include "AsteroidManager.h"
#include "ship.h"

#ifndef COLLISION_DETECTION
#define COLLISION_DETECTION


class CollisionDetection {
	public:
		ProjectileManager* proj_manager;
		AsteroidManager* ast_manager;
		ship* player;
		
		CollisionDetection(ship* pship, ProjectileManager* pproj_manager, AsteroidManager* past_manager);

		void check_projectile_asteroid();
		void check_asteroid_asteroid();

};

#endif
