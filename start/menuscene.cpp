/**
* This class describes the MenuScene behavior.
*
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*/

#include "menuscene.h"

MenuScene::MenuScene() : SuperScene() {
	
}

MenuScene::~MenuScene() {

}

void MenuScene::update(float deltaTime) {
	if (input()->getKeyUp(KeyCode::Escape)) {
		status = 4;
	}
	if (input()->getKeyUp(KeyCode::RightBracket)) {
		status = 1;
	}
}