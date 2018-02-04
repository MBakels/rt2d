/**
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*
* @file menuscene.h
*
* @brief description of the MenuScene behavior.
*/

#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <rt2d/text.h>

#include "superscene.h"
#include "basicentity.h"

/// @brief The SpaceShip class handels the spaceship movement and keeps a list of passengers.
class MenuScene : public SuperScene {
public:
	/// @brief Constructor
	MenuScene();
	/// @brief Destructor
	virtual ~MenuScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	BasicEntity* background;
	BasicEntity* startButton;
	Text* startButtonText;
	BasicEntity* quitButton;
	Text* quitButtonText;
};

#endif /* MENUSCENE_H */