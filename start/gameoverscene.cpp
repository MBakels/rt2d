/**
* This class describes the BasicEntity behavior.
*
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*/

#include "gameoverscene.h"

GameOverScene::GameOverScene() : SuperScene() {

}

GameOverScene::~GameOverScene() {

}

void GameOverScene::update(float deltaTime) {
	if (input()->getKeyUp(KeyCode::RightBracket)) {
		status = 0;
	}
}