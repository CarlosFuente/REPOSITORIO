#ifndef __ROONEY_H__
#define __ROONEY_H__


#include "cocos2d.h"
USING_NS_CC;

const int   SPEED = 10;
const int JUMP = 40;
const int _rooneytag = 0;


class Rooney : public cocos2d::Layer
{

private:
	//Movimiento
	int _speed;

	//Salto
	cocos2d::Vec2 _jump;
	Vec2 _podVectorJ;
	int __jump;
	bool _canJump;
	bool _isJumping;
	int _contJump;
	

	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

	cocos2d::Sprite *rooney;



public:
	Rooney(cocos2d::Layer *layer);

	bool left;
	bool right;


	//My functions
	
	void moveRooney();

	void setPosition(int X, int Y);

	//Salto
	bool Rooney::getCanJump();
	void Rooney::setCanJump(bool p);
	void Rooney::Jump();
	void Rooney::setJumping(bool p);

	void Rooney::Move(bool derecha);

	//Funciones Movimiento
	//void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	//void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);

};

#endif
