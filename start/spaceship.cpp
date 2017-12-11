/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "spaceship.h"

SpaceShip::SpaceShip() : Entity(){
	this->addSprite("assets/ship.tga");
	//this->sprite()->color = RED;
}

SpaceShip::~SpaceShip(){

}

void SpaceShip::update(float deltaTime){

	static Vector2 velocity = Vector2(0, 0);
	static Polar polar = Polar((rand() % 360) * DEG_TO_RAD, 400.0f);

	// ###############################################################
	// Key input for spaceship
	// ###############################################################
	if (input()->getKey(KeyCode::W)) {
		velocity += polar.cartesian() * deltaTime;
	}
	if (input()->getKey(KeyCode::A)) {
		polar.angle -= rotationSpeed * deltaTime;
	}
	if (input()->getKey(KeyCode::D)) {
		polar.angle += rotationSpeed * deltaTime;
	}

	rotation.z = polar.angle;
	position += velocity * deltaTime;
}
