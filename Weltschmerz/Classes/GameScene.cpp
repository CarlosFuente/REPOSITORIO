#include "GameScene.h"
#include "Classes/Objetos/Rooney.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	//auto scene = Scene::createWithPhysics();
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();


	//layer->setPhysicsWorld(scene->getPhysicsWorld()); //Físicas


	// add layer as a child to scene
	scene->addChild(layer);

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

	Size visibleSize = Director::getInstance()->getVisibleSize();
	
	//Creando a Rooney
	rooney = new Rooney(this);
	//addChild(rooney, 1);
	

	//Creando el Suelo
	/*
	floor = Sprite::create("images/provisional/quad.jpg");
	floor->setPosition(Point(visibleSize.width / 2, visibleSize.height / 13));
	addChild(floor, 0);
	*/

	floor = new Plataforma(this, visibleSize.width / 2, visibleSize.height / 13);

	//Movimiento
	
	auto listenermove = EventListenerKeyboard::create();

	listenermove->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	listenermove->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenermove, this);
	
	this->scheduleUpdate();

	return true;
}
void GameScene::update(float dt)
{
	rooney->moveRooney();
}

//FISICAS
/*
void GameScene::setPhysicsWorld(PhysicsWorld *world)
{
	mWorld = world;
	mWorld->setGravity(Vec2::ZERO);
}
*/
//Mover Rooney (por si no funciona el update en rooney y hay que hacerlo en el nivel)

void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event){
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
		rooney->setPosition(Director::getInstance()->getVisibleSize().width / 2 + Director::getInstance()->getVisibleOrigin().x,
			Director::getInstance()->getVisibleSize().height / 2 + Director::getInstance()->getVisibleOrigin().y);

		break;
	}

	rooney->updateMove(_isMoving, _podVector);
}

void GameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event){
	if (_pressedKey == keyCode) {
		_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
		_isMoving = false;
		_podVector = Vec2::ZERO;
	}
	rooney->updateMove(_isMoving, _podVector);
}



