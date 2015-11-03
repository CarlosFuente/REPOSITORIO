#include "Plataforma.h"
#include "GameScene.h"

USING_NS_CC;

Plataforma::Plataforma(cocos2d::Layer *layer)
{


	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	plataforma = Sprite::create("images/provisional/quad.jpg");
	plataforma->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	//FISICAS
	auto pfBody = PhysicsBody::createCircle(plataforma->getContentSize().width / 2);
	plataforma->setPhysicsBody(pfBody);

	layer->addChild(plataforma, 1);

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