/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <rt2d/entity.h>

/// @brief The SpaceShip class handels the spaceship movement and keeps a list of passengers.
class SpaceShip : public Entity{
public:
	/// @brief Constructor
	SpaceShip();
	/// @brief Destructor
	virtual ~SpaceShip();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	float rotationSpeed = 3.14f;
};

#endif /* SPACESHIP_H */
