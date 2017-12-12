/**
 * Copyright 2015 Marco Bakels <marcobakels@live.nl>
 *
 * @file spaceship.h
 *
 * @brief description of the SpaceShip behavior.
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

	float GetMass();

private:
	float rotationSpeed;
	Vector2 velocity;
	Polar polar;
	float mass;
};

#endif /* SPACESHIP_H */
