/**
* This class describes the PauseScene behavior.
*
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*/

#include "pausescene.h"

PauseScene::PauseScene() : SuperScene() {
	background = new BasicEntity();
	background->position = Point(SWIDTH / 2, SHEIGHT / 2);
	background->addSprite("assets/star_background.tga");
	background->sprite()->size = Point2(SWIDTH, SWIDTH);
	addChild(background);

	resumeButton = new BasicEntity();
	Sprite* startButtonSpr = new Sprite();
	resumeButton->addSprite(startButtonSpr);
	delete startButtonSpr;
	resumeButton->position = Point(SWIDTH / 2, SHEIGHT / 2 - 200);
	resumeButton->sprite()->color = RGBAColor(0, 0, 0, 220);
	resumeButton->sprite()->size = Point2(300, 100);
	resumeButtonText = new Text();
	resumeButtonText->message("Resume");
	resumeButtonText->position.x -= 75;
	resumeButton->addChild(resumeButtonText);
	addChild(resumeButton);

	toMenuButton = new BasicEntity();
	Sprite* quitButtonSpr = new Sprite();
	toMenuButton->addSprite(quitButtonSpr);
	delete quitButtonSpr;
	toMenuButton->position = Point(SWIDTH / 2, SHEIGHT / 2 + 200);
	toMenuButton->sprite()->color = RGBAColor(0, 0, 0, 220);
	toMenuButton->sprite()->size = Point2(300, 100);
	toMenuButtonText = new Text();
	toMenuButtonText->message("To menu");
	toMenuButtonText->position.x -= 95;
	toMenuButton->addChild(toMenuButtonText);
	addChild(toMenuButton);
}

PauseScene::~PauseScene() {
	removeChild(background);
	delete background;

	removeChild(resumeButton);
	delete resumeButton;
	removeChild(resumeButtonText);
	delete resumeButtonText;

	removeChild(toMenuButton);
	delete toMenuButton;
	removeChild(toMenuButtonText);
	delete toMenuButtonText;
}

void PauseScene::update(float deltaTime) {
	int mouseX = input()->getMouseX();
	int mouseY = input()->getMouseY();
	if (input()->getMouseDown(0)) {
		if (mouseX > resumeButton->position.x - resumeButton->sprite()->size.x / 2 &&
			mouseX < resumeButton->position.x + resumeButton->sprite()->size.x / 2 &&
			mouseY > resumeButton->position.y - resumeButton->sprite()->size.y / 2 &&
			mouseY < resumeButton->position.y + resumeButton->sprite()->size.y / 2) {
			status = 2;
		}
		if (mouseX > toMenuButton->position.x - toMenuButton->sprite()->size.x / 2 &&
			mouseX < toMenuButton->position.x + toMenuButton->sprite()->size.x / 2 &&
			mouseY > toMenuButton->position.y - toMenuButton->sprite()->size.y / 2 &&
			mouseY < toMenuButton->position.y + toMenuButton->sprite()->size.y / 2) {
			status = 0;
		}
	}
	if (input()->getKeyUp(KeyCode::Escape)) {
		status = 2;
	}
}