/**
* This class describes the MenuScene behavior.
*
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*/

#include "menuscene.h"

MenuScene::MenuScene() : SuperScene() {
	background = new BasicEntity();
	background->position = Point(SWIDTH / 2, SHEIGHT / 2);
	background->addSprite("assets/star_background.tga");
	background->sprite()->size = Point2(SWIDTH, SWIDTH);
	addChild(background);

	startButton = new BasicEntity();
	Sprite* startButtonSpr = new Sprite();
	startButton->addSprite(startButtonSpr);
	delete startButtonSpr;
	startButton->position = Point(SWIDTH / 2, SHEIGHT / 2 - 200);
	startButton->sprite()->color = RGBAColor(0,0,0,220);
	startButton->sprite()->size = Point2(300, 100);
	startButtonText = new Text();
	startButtonText->message("Start");
	startButtonText->position.x -= 60;
	startButton->addChild(startButtonText);
	addChild(startButton);

	quitButton = new BasicEntity();
	Sprite* quitButtonSpr = new Sprite();
	quitButton->addSprite(quitButtonSpr);
	delete quitButtonSpr;
	quitButton->position = Point(SWIDTH / 2, SHEIGHT / 2 + 200);
	quitButton->sprite()->color = RGBAColor(0, 0, 0, 220);
	quitButton->sprite()->size = Point2(300, 100);
	quitButtonText = new Text();
	quitButtonText->message("Quit");
	quitButtonText->position.x -= 50;
	quitButton->addChild(quitButtonText);
	addChild(quitButton);
}

MenuScene::~MenuScene() {
	removeChild(background);
	delete background;

	removeChild(startButton);
	delete startButton;
	removeChild(startButtonText);
	delete startButtonText;

	removeChild(quitButton);
	delete quitButton;
	removeChild(quitButtonText);
	delete quitButtonText;
}

void MenuScene::update(float deltaTime) {
	int mouseX = input()->getMouseX();
	int mouseY = input()->getMouseY();
	if (input()->getMouseDown(0)) {
		if (mouseX > startButton->position.x - startButton->sprite()->size.x / 2 && 
			mouseX < startButton->position.x + startButton->sprite()->size.x / 2 && 
			mouseY > startButton->position.y - startButton->sprite()->size.y / 2 && 
			mouseY < startButton->position.y + startButton->sprite()->size.y / 2) {
			status = 4;
		}
		if (mouseX > quitButton->position.x - quitButton->sprite()->size.x / 2 &&
			mouseX < quitButton->position.x + quitButton->sprite()->size.x / 2 &&
			mouseY > quitButton->position.y - quitButton->sprite()->size.y / 2 &&
			mouseY < quitButton->position.y + quitButton->sprite()->size.y / 2) {
			status = 5;
		}
	}
}