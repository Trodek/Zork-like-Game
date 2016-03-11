#include "ConnectionClass_Header.h"
#include "RoomClass_Header.h"
#include <iostream>

Room::Room(){
	name = "some room";
	basic_description = "info about some room";
};

Room::Room( const std::string& type, const std::string& info) : name(type), basic_description(info){}

std::string Room::get_name() const {
	return name;
}

std::string Room::get_description() const{
	return basic_description;
}
