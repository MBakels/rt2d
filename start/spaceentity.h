/**
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*
* @file spaceentity.h
*
* @brief description of the SpaceEntity behavior.
*/

#ifndef SPACEENTITY_H
#define SPACEENTITY_H

#include <rt2d/entity.h>

/// @brief The SpaceShip class handels the spaceship movement and keeps a list of passengers.
class SpaceEntity : public Entity {
public:
	/// @brief Constructor
	SpaceEntity();
	/// @brief Destructor
	virtual ~SpaceEntity();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	float GetMass();

	void AddForce(Vector2 force);

	void SetVelocity(Vector2 velocity);

protected:
	float mass;
	Vector2 velocity;
};

#endif /* SPACEENTITY_H */