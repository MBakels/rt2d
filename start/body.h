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
	Body(std::string name, double mass, double diameter);
	/// @brief Destructor
	virtual ~Body();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	Vector2 GravitationalForce(SpaceEntity* entity);

	float GetRadius();

	void SetOrbid(Body* orbitingPlanet, double distance);

	std::string GetName();

	float GetDistance(Point3 otherPos);

private:
	float scale;
	double gravityConstant;
	std::string name;
	float radius;
	bool orbidSet;
	Body* orbitingPlanet;
	float orbitingPlanetX;
	float orbitingPlanetY;
	float radiusOrbitingPlanetX;
	float radiusOrbitingPlanetY;
	float orbitingSpeed;
	float angle;
};

#endif /* BODY_H */