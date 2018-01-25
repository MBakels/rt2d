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
	Body(std::string name, float mass, float diameter, int scoreValue, std::string filePath);
	/// @brief Destructor
	virtual ~Body();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	Vector2 GravitationalForce(SpaceEntity* entity);

	float GetDiameter();

	void SetOrbit(Point3 orbitingPlanetPosition, float orbitingPlanetMass, float distance);

	std::string GetName() { return name; };

	void SetStationOrbit(float height);

	float GetDistance(Point3 otherPos);

	bool CheckStableOrbit(Point3 shipPosition, float deltaTime);

	float GetPassengersWaiting() { return passengersWaiting; };

	void SetPassengersWaiting(int newValue) { passengersWaiting = newValue; };

	int GetScoreValue() { return scoreValue; };

	bool CheckCollision(Point3 otherPosition, float otherRadius);

private:
	float gravityConstant;
	std::string name;
	float diameter;
	Body* orbitingPlanet;
	BasicEntity* stationOrbit;
	float stationOrbitHeight;
	float stableOrbitTimer;
	int passengersWaiting;
	int scoreValue;
};

#endif /* BODY_H */