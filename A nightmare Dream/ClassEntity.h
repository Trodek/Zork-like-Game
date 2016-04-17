#ifndef _Entity_
#define _Entity_

#include "MyString.h"
#include "dynArray.h"

typedef unsigned int uint;


enum classes
{
	ENTITY, ROOM, PLAYER, ITEM, EXIT
};

class Entity{
private:
	MyString name;
	MyString description;
	classes type;

public:
	dynArray<Entity*> contain;

public:
	//Constructors
	Entity(){}

	Entity(const char* n, const char* des, classes classtype = ENTITY): name(n), description(des), type(classtype){}

	Entity(const Entity& ent){
		name = ent.name;
		description = ent.description;
	}

	//Destructor
	virtual ~Entity(){}

	//Methods
	char* GetName()const{ return name.c_str(); }

	MyString& GetNameString(){ return name; }

	char* GetDescription()const{	return description.c_str();	}

	classes GetType()const { return type; }

	void SetName(const char* new_name){	name = new_name; }

	void SetDescription(const char* new_des){ description = new_des; }

};

class World;
extern World* Game;
#endif