#ifndef _Connection_
#define _Connection_

#include "ClassEntity.h"

class Room;

class Connection: public Entity{
private:
	bool closed;
	bool can_be_closed;
	Entity* key;
	MyString direction;
	Room* from;
	Room* next_room;
	uint food_consumed;

public:
	//Constructors
	Connection(bool close_door, bool can_closed, Room* coming, Room* following_room, MyString& dir ,int hungry_decrementor,Entity* the_key) :
		Entity("Connection", "", EXIT),	closed(close_door), can_be_closed(can_closed), from(coming),
		next_room(following_room), food_consumed(hungry_decrementor), key(the_key), direction(dir) {}

	~Connection(){}

	//Methods
	bool GetClosed() const{	return closed;	}

	bool GetCanClose() const{ return can_be_closed;	}

	Entity* GetNeedKey() const{ return key; }

	MyString& GetDirection() { return direction; }

	Room* GetFrom() const{ return from;	}

	Room* GetNextRoom() const{ return next_room; }

	uint GetFoodConsumed() const{ return food_consumed; }

	void OpenDoor(){ closed = false; }

	void CloseDoor(){ closed = true; }
};

#endif