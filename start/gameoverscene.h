/**
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*
* @file gameoverscene.h
*
* @brief description of the GameOverScene behavior.
*/

#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H

#include <rt2d/text.h>

#include "superscene.h"
#include "basicentity.h"

/// @brief The SpaceShip class handels the spaceship movement and keeps a list of passengers.
class GameOverScene : public SuperScene {
public:
	/// @brief Constructor
	GameOverScene();
	/// @brief Destructor
	virtual ~GameOverScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	void SetScore(int score);

private:
	BasicEntity* background;
	BasicEntity* toMenuButton;
	Text* toMenuButtonText;
	Text* gameOverText;
	Text* scoreText;
};

#endif /* GAMEOVERSCENE_H */