/**
 * Copyright 2015 Marco Bakels <marcobakels@live.nl>
 *
 * @file spaceship.h
 *
 * @brief description of the SpaceShip behavior.
 */

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "spaceentity.h"

/// @brief The SpaceShip class handels the spaceship movement and keeps a list of passengers.
class SpaceShip : public SpaceEntity{
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
	float rotationSpeed;
	Polar polar;
};

#endif /* SPACESHIP_H */
