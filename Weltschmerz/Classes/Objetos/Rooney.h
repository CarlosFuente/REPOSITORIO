#ifndef __ROONEY_H__
#define __ROONEY_H__


#include "cocos2d.h"
USING_NS_CC;

const int   SPEED = 10;
const int JUMP = 0;


class Rooney : public cocos2d::Layer
{

private:

	bool _isMoving;
	Vec2 _podVector;
	int _jump;
	int _speed;
	

	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

	cocos2d::Sprite *rooney;



public:
	Rooney(cocos2d::Layer *layer);


	//My functions
	
	void moveRooney();
	void updateMove(bool Moving, Vec2 Vector);

	void setPosition(int X, int Y);

	//Funciones Movimiento
	//void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	//void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);

};

#endif
