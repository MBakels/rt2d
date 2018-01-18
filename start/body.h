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
	Body(std::string name, float mass, float diameter, int scoreValue);
	/// @brief Destructor
	virtual ~Body();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	Vector2 GravitationalForce(SpaceEntity* entity);

	float GetDiameter();

	void SetOrbid(Point3 orbitingPlanetPosition, float orbitingPlanetMass, float distance);

	std::string GetName() { return name; };

	void SetStationOrbid(float height);

	float GetDistance(Point3 otherPos);

	bool CheckStableOrbid(Point3 shipPosition, float deltaTime);

	float GetPassengersWaiting() { return passengersWaiting; };

	void SetPassengersWaiting(int newValue) { passengersWaiting = newValue; };

	int GetScoreValue() { return scoreValue; };

private:
	float gravityConstant;
	std::string name;
	float diameter;
	Body* orbitingPlanet;
	BasicEntity* stationOrbid;
	float stationOrbidHeight;
	float stableOrbidTimer;
	int passengersWaiting;
	int scoreValue;
};

#endif /* BODY_H */