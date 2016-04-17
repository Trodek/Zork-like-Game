#ifndef _RoomClass_
#define _RoomClass_

#include "ClassEntity.h"
#include "ClassConnection.h"


class Room : public Entity{
public:
	//Constructor
	Room(const char* type, const char* info) : Entity(type, info, ROOM){}

	~Room(){}

	//Methods
	Connection* GetConnection(MyString& direction);
};

#endif