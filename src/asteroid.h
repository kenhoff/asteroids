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

#ifndef ASTEROID
#define ASTEROID

class asteroid
{	
public:
	vec2d position;
	vec2d velocity;
	float heading;
	float rot_speed;
	//float speed;
	int life;
	float size;
	
	asteroid(float asize, float x_pos, float y_pos, float x_vel, float y_vel, float rspeed);
	
	void loop_world();
	void calculate_position();
	void draw();
};

#endif 
