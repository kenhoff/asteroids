#include "asteroid.h"

asteroid::asteroid(float asize, float px_pos, float py_pos, float px_vel, float py_vel, float rspeed)
{
	position.x = px_pos;
	position.y = py_pos;
	velocity.x = px_vel;
	velocity.y = py_vel;
	rot_speed = rspeed;
	size = asize;
	
	life = 1000;
}

void asteroid::loop_world()
{
	if (position.x > zoom || position.x < -zoom)
	{
		position.x = -position.x*loop_accuracy;
	}
	if (position.y > zoom || position.y < -zoom)
	{
		position.y = -position.y*loop_accuracy;
	}
}

void asteroid::calculate_position()
{
	loop_world();
	
	position.x += velocity.x;
	position.y += velocity.y;
	
	heading += rot_speed;
	
	if (heading < 0)
	{
		heading += 360;
	}
	
	heading = fmod(heading, 360);
}

void asteroid::draw()
{
	calculate_position();
	
	glPushMatrix();

	glTranslatef(position.x, position.y, 0);
	glRotatef(heading, 0,0,1);

//	glPointSize(2.0);

	glBegin(GL_LINE_LOOP);
	
	for (int i = 0; i < 359; i += 36)
	{
		glVertex2f(cos(radians(i))*size, sin(radians(i))*size);
	}
	
	glEnd();
	glPopMatrix();
}
