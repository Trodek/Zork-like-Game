#include <iostream>
#include "ConnectionClass_Header.h"
#include "PlayerClass_Header.h"
#include "RoomClass_Header.h"

Player::Player(Room* initial_room) : actual(initial_room){}

void Player::change_room(Room* next_room){
	actual = next_room;
}
