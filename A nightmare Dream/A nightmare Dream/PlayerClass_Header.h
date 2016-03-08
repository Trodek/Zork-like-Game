#ifndef _PlayerClass_
#define _PlayerClass_

#include "RoomClass_Header.h"

class Player {
public:
	Room* actual;
	Player(Room*);
	void change_room(Room* next_room);


};

#endif