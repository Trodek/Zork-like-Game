#include "ClassPlayer.h"
#include "ClassEntity.h"
#include "ClassRoom.h"
#include "ClassConnection.h"
#include "ClassWorld.h"
#include "ClassItem.h"

void Player::Go(dynArray<MyString>& words){
	if (words.size() > (uint) 1){
		Connection* temp = actual_room->GetConnection(words[1]);
		if (temp != nullptr && temp->GetDirection()==words[1]){
			if (!temp->GetClosed())	actual_room = temp->GetNextRoom();
			else printf("Door is closed\n");
		}
		else printf("There is no room in direction %s.\n", words[1].c_str());
	}
	else {
		Connection* temp = actual_room->GetConnection(words[0]);
		if (temp != nullptr&& temp->GetDirection() == words[0]){
			actual_room = temp->GetNextRoom();
		}
		else printf("There is no room in direction %s.\n", words[0].c_str());
	}
}

void Player::Pick(dynArray<MyString>& words){
	Item* temp;
	bool picked = false;
	if (words.size() == (uint)2){
		for (int i = 0; i < Game->contain.size(); i++){
			if (Game->contain[i]->GetType() == ITEM){
				temp = dynamic_cast<Item*> (Game->contain[i]);
				if (temp->GetContainer() == actual_room && temp->GetNameString() == words[1]&&temp->GetPickable()){	
					temp->SetContainer(inventory);	
					picked = true;
					break;
				}
			}
		}
	}
	else if (words.size() == (uint)4){
		Item* container;
		for (int i = 0; i < Game->contain.size(); i++){
			if (Game->contain[i]->GetNameString() == words[3] && Game->contain[i]->GetType() == ITEM) {
				container = dynamic_cast<Item*>(Game->contain[i]);
				if (container->GetContainer() != actual_room) continue;
				else{
					for (int i = 0; i < Game->contain.size(); i++){
						if (Game->contain[i]->GetType() == ITEM){
							temp = dynamic_cast<Item*> (Game->contain[i]);
							if (temp->GetContainer() == container && temp->GetNameString() == words[1] && temp->GetPickable()){
								temp->SetContainer(inventory);
								picked = true;
								break;
							}
						}
					}
				}
			}
		}
	}

	if(picked) printf("The %s is now in your %s.\n", words[1].c_str(), inventory->GetName());
	else printf("The item %s is not there or can not be picked.\n", words[1].c_str());
}

void Player::ChangeDoor(dynArray<MyString>& words){
	Connection* departure;
	Connection* ret = nullptr;

	departure = actual_room->GetConnection(words[1]);
	if (departure != nullptr){
		for (int i = 0; i < Game->contain.size(); i++){
			if (Game->contain[i]->GetType() == EXIT){
				ret = dynamic_cast<Connection*>(Game->contain[i]);
				if (ret->GetFrom() == departure->GetNextRoom() && ret->GetNextRoom() == departure->GetFrom()) break;
				else ret = nullptr;
			}
		}
		if (ret != nullptr){
			if (departure->GetNeedKey() != nullptr){
				Item* key = dynamic_cast<Item*>(departure->GetNeedKey());
				if (key->GetContainer() == inventory){
					if (words[0] == "close"){
						if (departure->GetCanClose()){
							departure->CloseDoor();
							ret->CloseDoor();
							printf("The door is closed now.\n");
						}
					}
					else if (words[0] == "open"){
						departure->OpenDoor();
						ret->OpenDoor();
						printf("The door is open now.\n");
					}
				}
				else printf("I need a key to open this door.\n");
			}
			else if (words[0] == "close"){
				if (departure->GetCanClose()){
					departure->CloseDoor();
					ret->CloseDoor();
					printf("The door is closed now.\n");
				}
			}
			else if (words[0] == "open"){
				departure->OpenDoor();
				ret->OpenDoor();
				printf("The door is open now.\n");
			}
		}
	}
	else printf("I cant find a door in %s direction.\n", words[1]);

}

void Player::Look(dynArray<MyString>& words){
	Item* temp;
	Item* temp2;
	switch (words.size()){
	case 1:{
			   printf("I'm it the %s.\n", actual_room->GetName());
			   printf("%s.\nI can see: ", actual_room->GetDescription());
			   for (int i = 0; i < Game->contain.size(); i++){
				   if (Game->contain[i]->GetType() == ITEM){
					   temp = dynamic_cast<Item*> (Game->contain[i]);
					   if (temp->GetContainer() == actual_room){
						   printf("%s ", temp->GetName());
					   }
				   }
			   }
			   printf("\nFrom here, I can go to: ");
			   Connection* north = actual_room->GetConnection(MyString("north"));
			   Connection* south = actual_room->GetConnection(MyString("south"));
			   Connection* east = actual_room->GetConnection(MyString("east"));
			   Connection* west = actual_room->GetConnection(MyString("west"));
			   if (north != nullptr)printf("%s(north)", north->GetNextRoom()->GetName());
			   if (south != nullptr)printf("%s(south)", south->GetNextRoom()->GetName());
			   if (east != nullptr)printf("%s(east)", east->GetNextRoom()->GetName());
			   if (west != nullptr)printf("%s(west)", west->GetNextRoom()->GetName());
	}
		break;
	case 2:{
			   for (int i = 0; i < Game->contain.size(); i++){
				   if (Game->contain[i]->GetType() == ITEM && Game->contain[i]->GetNameString() == words[1]){
					   temp = dynamic_cast<Item*> (Game->contain[i]);
					   if (temp->GetContainer() == actual_room|| temp->GetContainer()==inventory){
						   printf("%s\n", temp->GetDescription());
						   if (temp->GetCanContain()){
							   printf("The %s contains: ", temp->GetName());
							   for (int i = 0; i < Game->contain.size(); i++){
								   if (Game->contain[i]->GetType() == ITEM){
									   temp2 = dynamic_cast<Item*> (Game->contain[i]);
									   if (temp2->GetContainer() == temp)printf("%s ", temp2->GetName());
								   }
							   }
						   }
					   }
				   }
			   }
	}
		break;
	}
	printf("\n");
}