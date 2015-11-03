#ifndef __PLATAFORMA_H__
#define __PLATAFORMA_H__


#include "cocos2d.h"
USING_NS_CC;


class Plataforma : public cocos2d::Layer
{

private:

	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

	cocos2d::Sprite *plataforma;

	//Plataformas que desaparecen
	bool desaparece; //Si tiene algun condicionante para desaparecer
	bool existe; //Si exite en este momento
	int tiempoReap; //Tiempo que no existe
	int tiempoDesp; //Tiempo antes de desaparecer



public:
	Plataforma(cocos2d::Layer *layer, int X, int Y);

	void setPosition(int X, int Y);


};

#endif //__PLATAFORMA_H__