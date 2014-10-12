#include "projectile.h"


projectile::projectile(float px_pos, float py_pos, float px_vel, float py_vel)
{
	position.x = px_pos;
	position.y = py_pos;
	velocity.x = px_vel;
	velocity.y = py_vel;

	
	life = 250;
}
	

void projectile::loop_world()
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

void projectile::calculate_position()
{
	loop_world();
	
	position.x += velocity.x;
	position.y += velocity.y;
	life--;
}

void projectile::draw()
{
	calculate_position();
	
	glPushMatrix();


	glTranslatef(position.x, position.y, 0);



	glPointSize(2.0);

	glBegin(GL_POINTS);
	glVertex2f(0,0);

	glEnd();

	glPopMatrix();
	

	
	
}
