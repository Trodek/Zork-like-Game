#ifndef _RoomClass_
#define _RoomClass_

#include "ClassEntity.h"
#include "ClassConnection.h"


class Room : public Entity{
private:
	Roomtype tag;

public:
	//Constructor
	Room(const char* type, const char* info, Roomtype roomtag) : Entity(type, info, ROOM), tag(roomtag){}

	~Room(){}

	//Methods
	Roomtype GetTag()const{	return tag;	}
	Connection* GetConnection(MyString& direction);
};

#endif