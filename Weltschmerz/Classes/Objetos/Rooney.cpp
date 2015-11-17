#include "Rooney.h"
#include "GameScene.h"

USING_NS_CC;


Rooney::Rooney(cocos2d::Layer *layer)
{

	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	//Inicializando variables propias
	_jump = Vec2(0.0, 200.0);
	__jump = JUMP;
	_speed = 10;
	_canJump = true;
	_isJumping = false;
	right = false;
	left = false;


	// Apartado Visual
	rooney = Sprite::create("images/provisional/rooneyp.png");


	//Físcias
	auto physicsBody = PhysicsBody::createBox(Size(rooney->getBoundingBox().size.width, rooney->getBoundingBox().size.height), 
		PhysicsMaterial(0.1f,0.0f,0.0f));
	physicsBody->setDynamic(true);
	physicsBody->setRotationEnable(false);
	physicsBody->setContactTestBitmask(true);
	physicsBody->setCategoryBitmask(0x03);
	physicsBody->setCollisionBitmask(0x03);
	physicsBody->setTag(_rooneytag); //Para el futuro
	rooney->setPhysicsBody(physicsBody);

	layer->addChild(rooney, 1);

}


void Rooney::moveRooney()
{
	if (right)
	{
		Vec2 newPos = Vec2(rooney->getPosition().x + _speed, rooney->getPosition().y);
		rooney->setPosition(newPos);
	}
	else if (left)
	{
		Vec2 newPos = Vec2(rooney->getPosition().x - _speed, rooney->getPosition().y);
		rooney->setPosition(newPos);
	}
	if (_isJumping){
		_canJump = false;
		Vec2 newPos = Vec2(rooney->getPosition().x, rooney->getPosition().y + __jump);
		rooney->setPosition(newPos);
		_contJump++;
		if (__jump - _contJump >=0) __jump-=_contJump;
		if (_contJump >= 8){
			_isJumping = false;
		}
	}
	if (rooney->getPhysicsBody()->getVelocity().y == 0) _canJump = true; //cuando no baja (ha tocado solido) puede saltar
}

void Rooney::setPosition(int X, int Y)
{
	rooney->setPosition(X,Y);
}

bool Rooney::getCanJump()
{
	return _canJump;
}

void Rooney::setCanJump(bool p)
{
	_canJump = p;
}

void Rooney::setJumping(bool p)
{
	_canJump = p;
}

void Rooney::Jump()
{
	if (_canJump){
		_isJumping = true;
		_contJump = 0;
		__jump = JUMP;
	}
}
