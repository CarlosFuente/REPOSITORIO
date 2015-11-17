#include "GameScene.h"
#include "MainMenuScene.h"
#include "Classes/Objetos/Rooney.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL); //para ver los cuadrados rojitos

	// 'layer' is an autorelease object
	auto layer = GameScene::create();
	layer->setPhysicsWorld(scene->getPhysicsWorld()); //Físicas


	// add layer as a child to scene
	scene->addChild(layer);

	//PARA QUE APAREZCA AL PRIMER TICK
	scene->getPhysicsWorld()->setAutoStep(false);// aqui le decimos al motor de fisicas que nosotros nos encargamos de llamar a
	//su actualización
	scene->getPhysicsWorld()->step(1.0f);// aqui le decimos cuando es la siguiente actualización
	scene->getPhysicsWorld()->setAutoStep(true);// Aquí le decimos que se encargue el solito

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	origin = Director::getInstance()->getVisibleOrigin();
	visibleSize = Director::getInstance()->getVisibleSize();

	_gravity = Vec2(0, -1500);

	//Creando a Rooney
	rooney = new Rooney(this);
	rooney->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 20);
	

	//Creando el Mundo

	floor = new Plataforma(this, 0, 0,0);
	floor2 = new Plataforma(this, visibleSize.width -100, 200,1);
	floor3 = new Plataforma(this, 100, 200,1);
	

	//Movimiento
	
	auto listenermove = EventListenerKeyboard::create();

	listenermove->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	listenermove->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenermove, this);
	
	this->scheduleUpdate();

	//Colision
	//auto contactListener = EventListenerPhysicsContact::create();
	//contactListener->onContactBegin = CC_CALLBACK_2(GameScene::onContactBegin, this);
	//this ->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	return true;
}
void GameScene::update(float dt)
{

	rooney->moveRooney();
}


//FISICAS

void GameScene::setPhysicsWorld(PhysicsWorld *world)
{
	mWorld = world;
	mWorld->setGravity(_gravity);
	//mWorld->setGravity(Vec2::ZERO);
}

void GameScene::recolocarObjetos()
{
	rooney->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 +origin.y);
}

void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event){
	switch (keyCode) {
	//MOVIMIENTO NORMAL
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		rooney->left = true;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		rooney->right = true;
		break;

	//SALTO
	case EventKeyboard::KeyCode::KEY_SPACE:
		rooney->Jump();
		break;
	
	///OTROS///
	//REINICIARSALTO inecesario :D
	case EventKeyboard::KeyCode::KEY_Z:
		rooney->setCanJump(true);
		break;
	//IR AL MENU
	case EventKeyboard::KeyCode::KEY_Q:
		goToMainMenuScene(this);
		break;

	//RECOLOCARRONEY inecesario :D
	case EventKeyboard::KeyCode::KEY_P:
		recolocarObjetos();
		break;
	}

}

void GameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event){
	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE){
		rooney->setJumping(false);
	}
	/*
	Error, con el orden correcto al saltar el personaje desliza. Se soluciona con booleanos
	*/
	else if (EventKeyboard::KeyCode::KEY_LEFT_ARROW == keyCode) {
		rooney->left = false;
	}
	else if (EventKeyboard::KeyCode::KEY_RIGHT_ARROW == keyCode) {
		rooney->right = false;
	}
}

void GameScene::goToMainMenuScene(Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}



