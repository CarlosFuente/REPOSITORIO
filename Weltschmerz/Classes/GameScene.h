#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Classes/Objetos/Rooney.h"
#include "Classes/Objetos/Plataforma.h"


USING_NS_CC;

class GameScene : public cocos2d::Layer
{
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

	Vec2 _gravity;


	//Fisicas
	PhysicsWorld *mWorld;

public:
	static cocos2d::Scene* createScene();
	virtual bool init();


	//ACTORES
	Rooney * rooney;
	Plataforma *floor;
	Plataforma *floor2;
	Plataforma *floor3;

	Vec3 world;

	//FUNCIONES
	//Utiles
	void GameScene::goToMainMenuScene(Ref *pSender);

	//Movimiento Rooney
	void update(float dt);
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);

	/////EN PRUEBAS

	//Fisicas
	
	void setPhysicsWorld(PhysicsWorld *world);
	void recolocarObjetos();



	

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);
};

#endif // __GAME_SCENE_H__
