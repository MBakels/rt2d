/**
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*
* @file superscene.h
*
* @brief description of the SuperScene behavior.
*/

#ifndef SUPERSCENE_H
#define SUPERSCENE_H

#include <rt2d/scene.h>

/// @brief The SpaceShip class handels the spaceship movement and keeps a list of passengers.
class SuperScene : public Scene {
public:
	/// @brief Constructor
	SuperScene();
	/// @brief Destructor
	virtual ~SuperScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	int GetStatus();

	void ResetStatus() { status = 5; }

protected:
	int status;
};

#endif /* SUPERSCENE_H */