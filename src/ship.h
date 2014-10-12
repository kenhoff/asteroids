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
#include "vec2d.h"

#ifndef SHIP
#define SHIP

class ship
{	
	public:
		vec2d position;
		vec2d velocity;
		float heading;
		float rot_inertia;
		float speed;
		float rot_speed;
		float stabilize_speed;
		float p_speed;
		float ShotRate;
		
		ProjectileManager * proj_manage;
		
		ship(ProjectileManager * pproj_manage);
		
		sf::Clock ShotTimer;
		
		// ship movement 
		void thrust();
		void stabilize();
		void rotate_right();
		void rotate_left();
		
		void shoot();	
		
		void loop_world();
		
		void calculate_position();
		
		void draw();
};

#endif 
