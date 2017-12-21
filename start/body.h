/**
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*
* @file planet.h
*
* @brief description of the Planet behavior.
*/

#ifndef BODY_H
#define BODY_H

#include "spaceentity.h"

/// @brief The SpaceShip class handels the spaceship movement and keeps a list of passengers.
class Body : public SpaceEntity {
public:
	/// @brief Constructor
	Body(std::string name, float mass, float diameter);
	/// @brief Destructor
	virtual ~Body();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	Vector2 GravitationalForce(SpaceEntity* entity);

	float GetRadius() { return radius; };

	void SetOrbid(Body* orbitingPlanet, float orbitingHeight, float orbitingSpeed, float angle);

	void OrbidBody(float deltaTime);

	std::string GetName() { return name; };

	float GetDistance(Point3 otherPos);

	void SetSlowDown(float amount) { this->slowDown = amount; };

private:
	float slowDown;
	std::string name;
	float radius;
	bool orbidSet;
	Body* orbitingPlanet;
	float orbitingPlanetX;
	float orbitingPlanetY;
	float orbitingHeight;
	float orbitingSpeed;
	float angle;
};

#endif /* BODY_H */