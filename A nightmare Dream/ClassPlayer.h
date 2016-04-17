#ifndef _Player_
#define _Player_

#include "ClassEntity.h"

class Room;
class Item;

class Player :public Entity{
private:
	Item* wearing;
	Room* actual_room;
	Item* inventory;
	int current_food = 20;
	
public:

	//Constructor
	Player(const char* name, const char* desc, Item* inv, Room* room, Item* wear) : Entity(name, desc, PLAYER), wearing(wear),
		inventory(inv), actual_room(room){}

	~Player(){}

	//Methods

	Room* GetActualRoom()const { return actual_room; }

	Item* GetWearing()const { return wearing; }

	Item* GetInventory()const { return inventory; }

	int GetCurrentFood()const{ return current_food; }

	void SetRoom(Room* new_room){ actual_room = new_room; }

	void Go(dynArray<MyString>& words);

	void Pick(dynArray<MyString>& words);

	void ChangeDoor(dynArray<MyString>& words);

	void Look(dynArray<MyString>& words);
	
	void Drop(dynArray<MyString>& words);

	void Equip(dynArray<MyString>& words);

	void Unquip();

	void Eat(dynArray<MyString>& words);

	void Cook(dynArray<MyString>& words);

	void Create(dynArray<MyString>& words);
};

#endif