#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Classes/Objetos/Rooney.h"
#include "Classes/Objetos/Plataforma.h"


USING_NS_CC;

class GameScene : public cocos2d::Layer
{
private:
	EventKeyboard::KeyCode _pressedKey;
	Vec2 _podVector;
	bool _isMoving;


	//Fisicas
	PhysicsWorld *mWorld;


public:
	static cocos2d::Scene* createScene();
	virtual bool init();


	//ACTORES
	Rooney * rooney;
	//Sprite *floor;

	Plataforma *floor;

	//FUNCIONES

	//Movimiento Rooney
	void update(float dt);
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);

	//Fisicas
	/*
	void setPhysicsWorld(PhysicsWorld *world);
	bool onContactBegin(PhysicsContact &contact);
	*/

	

	

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);
};

#endif // __GAME_SCENE_H__
