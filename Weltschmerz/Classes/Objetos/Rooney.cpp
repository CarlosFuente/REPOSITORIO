#include "Rooney.h"
#include "GameScene.h"

USING_NS_CC;

Rooney::Rooney(cocos2d::Layer *layer)
{
	_jump = 3;
	_speed = 10;

	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	rooney = Sprite::create("images/provisional/rooney.png");
	rooney->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height/2 + origin.y));
	
	//FISICAS
	/*
	auto rooneyBody = PhysicsBody::createCircle(rooney->getContentSize().width / 2);
	rooney->setPhysicsBody(rooneyBody);
	*/
	layer->addChild(rooney, 1);

}



void Rooney::moveRooney()
{
	if (_isMoving){
		Vec2 newPos = Vec2(rooney->getPosition().x + _podVector.x, rooney->getPosition().y + _podVector.y);
		if (newPos.x >= rooney->getBoundingBox().size.width / 2 && newPos.x <= (visibleSize.width - rooney->getBoundingBox().size.width / 2) && newPos.y >= rooney->getBoundingBox().size.height / 2 && newPos.y <= (visibleSize.height - rooney->getBoundingBox().size.height / 2))
		{
			rooney->setPosition(newPos);
		}
	}

}

void Rooney::updateMove(bool Moving, Vec2 Vector)
{
	_isMoving = Moving;
	_podVector = Vector;
}

void Rooney::setPosition(int X, int Y)
{
	rooney->setPosition(X,Y);
}

//Mover Rooney
/*
void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event)
{
	_pressedKey = keyCode;
	switch (_pressedKey) {
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		_podVector = Vec2(-SPEED, 0);
		_isMoving = true;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		_podVector = Vec2(SPEED, 0);
		_isMoving = true;
		break;

		//SALTO
	case EventKeyboard::KeyCode::KEY_SPACE:
		_podVector = Vec2(0, SPEED);
		_isMoving = true;
		break;
	
	 //Volver donde antes
	case EventKeyboard::KeyCode::KEY_P:
		rooney->setPosition(Point(Director::getInstance()->getVisibleSize().width / 2 + Director::getInstance()->getVisibleOrigin().x, Director::getInstance()->getVisibleSize().height / 2 + Director::getInstance()->getVisibleOrigin().y));

		break;
	}
}


void GameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event)
{
	if (_pressedKey == keyCode) {
		_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
		_isMoving = false;
		_podVector = Vec2::ZERO;
	}
}
*/