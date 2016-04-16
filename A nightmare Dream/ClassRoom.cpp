#include "ClassRoom.h"
#include "ClassWorld.h"

Connection* Room::GetConnection(MyString& direction){
	
	for (int i = 0; i < Game->contain.size(); i++){
		if (Game->contain[i]->GetType() == EXIT){
			Connection* temp;
			temp = dynamic_cast<Connection*> (Game->contain[i]);
			if (temp->GetFrom()==this && temp->GetDirection() == direction){
				return temp;
			}
		}
	}
	return nullptr;
}