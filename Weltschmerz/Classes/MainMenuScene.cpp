#include "MainMenuScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


	// Creating menu
	auto playItem = MenuItemImage::create("images/provisional/quad.jpg", "images/provisional/quad.jpg", CC_CALLBACK_1(MainMenu::goToGameScene, this));
	playItem->setScale(0.5f);
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
	addChild(menu, 1);

    return true;
}

void MainMenu::goToGameScene(Ref *pSender) 
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene));
}
