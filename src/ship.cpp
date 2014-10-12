#include "ship.h"
#include "ProjectileManager.h"
#include "projectile.h"
#include "vec2d.h"
#include <iostream>


ship::ship(ProjectileManager* pproj_manage)
{
	position.x = 0;
	position.y = 0;
	velocity.x = 0;
	velocity.y = 0;
	heading = 0;
	speed = .005;
	rot_speed = .05;
	stabilize_speed = .99;
	proj_manage = pproj_manage;
	p_speed = .1;
	ShotRate = .1;
}
	
void ship::thrust()
{
	
	velocity.y += ((speed * sin(radians(heading))));
	velocity.x += ((speed * cos(radians(heading))));
}

void ship::stabilize()
{
	rot_inertia = ((rot_inertia * stabilize_speed));
	velocity.x = ((velocity.x * stabilize_speed));
	velocity.y = ((velocity.y * stabilize_speed));
}

void ship::rotate_right()
{
	rot_inertia -= (rot_speed);
}

void ship::rotate_left()
{
	rot_inertia += (rot_speed);
}


void ship::shoot()
{

	if (ShotTimer.GetElapsedTime() > ShotRate)
	{

		float p_y = ((p_speed * sin(radians(heading))));
		float p_x = ((p_speed * cos(radians(heading))));
		projectile* new_proj = new projectile(position.x, position.y, p_x + velocity.x, p_y + velocity.y);
		proj_manage->add_projectile(new_proj);
	
		ShotTimer.Reset();
	}
}
	

void ship::loop_world()
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

void ship::calculate_position()
{
	loop_world();
	
	heading += rot_inertia;
	
	if (heading < 0)
	{
		heading += 360;
	}
	
	heading = fmod(heading, 360);
	
	position.x += velocity.x;
	position.y += velocity.y;
}

void ship::draw()
{
	calculate_position();
	
	glPushMatrix();


	glTranslatef(position.x, position.y, 0);
	glRotatef(heading, 0,0,1);

	glBegin(GL_LINE_LOOP);
	glVertex2f(1,0);
	glVertex2f(-1,1);
	glVertex2f(0,0);
	glVertex2f(-1,-1);

	glEnd();

	glPopMatrix();
	
	/*glPushMatrix();
	
	glTranslatef(position.x, position.y, 0);
	
	glBegin(GL_LINES);
	
	glVertex2f(0,0);
	glVertex2f(velocity.x*100, velocity.y*100);
	
	glEnd();
	
	glPopMatrix();
	*/
	
}
