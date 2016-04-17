#ifndef _Items_
#define _Items_

#include "ClassEntity.h"


class Item :public Entity{
private:
	Entity* container;
	bool can_contain;
	bool pickable;
	int food_regen;

public:

	//Constructor
	Item(const char* name, const char* des, bool contain = true, bool use = false, Entity* the_container = nullptr, int regen = NULL) : Entity(name, des, ITEM),
		can_contain(contain), pickable(use), container(the_container), food_regen(regen){}

	~Item(){}

	//Methods
	void SetContainer(Entity* new_container){ container = new_container; }

	Entity* GetContainer(){ return container; }

	bool GetPickable()const{ return pickable; }

	bool GetCanContain()const{ return can_contain; }

	int GetFoodRegen()const{ return food_regen; };

	Item* HaveItem(MyString& other);


};

#endif _Items_