/**
* This class describes the SuperScene behavior.
*
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*/

#include "superscene.h"

SuperScene::SuperScene() : Scene() {
	status = 5;
}

SuperScene::~SuperScene() {

}

void SuperScene::update(float deltaTime) {

}

int SuperScene::GetStatus() {
	return status;
}