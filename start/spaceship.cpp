/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "spaceship.h"

SpaceShip::SpaceShip() : Entity(){
	this->addSprite("assets/ship.tga");
	rotationSpeed = 3.14f;
	velocity = Vector2(0, 0);
	polar = Polar((rand() % 360) * DEG_TO_RAD, 200.0f);
}

SpaceShip::~SpaceShip(){

}

void SpaceShip::update(float deltaTime){
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
