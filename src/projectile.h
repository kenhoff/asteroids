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
#include "vec2d.h"

#ifndef PROJECTILE
#define PROJECTILE

class projectile
{	
	public:
		vec2d position;
		vec2d velocity;
		int life;
		
		projectile(float x_pos, float y_pos, float x_vel, float y_vel);
	
		void loop_world();
		void calculate_position();
		void draw();
};

#endif 
