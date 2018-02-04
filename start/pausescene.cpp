/**
* This class describes the PauseScene behavior.
*
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*/

#include "pausescene.h"

PauseScene::PauseScene() : SuperScene() {

}

PauseScene::~PauseScene() {

}

void PauseScene::update(float deltaTime) {
	if (input()->getKeyUp(KeyCode::Escape)) {
		status = 1;
	}
	if (input()->getKeyUp(KeyCode::RightBracket)) {
		status = 0;
	}
}