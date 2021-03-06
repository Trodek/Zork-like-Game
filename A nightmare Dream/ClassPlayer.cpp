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
			if (!temp->GetClosed())	{
				actual_room = temp->GetNextRoom();
				current_food -= temp->GetFoodConsumed();
				printf("I'm in the %s.\n", temp->GetNextRoom()->GetName());
				printf("Food left: %d.\n", current_food);
			}
			else printf("Door is closed\n");
		}
		else printf("There is no room in direction %s.\n", words[1].c_str());
	}
	else {
		Connection* temp = actual_room->GetConnection(words[0]);
		if (temp != nullptr&& temp->GetDirection() == words[0]){
			actual_room = temp->GetNextRoom();
			current_food -= temp->GetFoodConsumed();
			printf("I'm in the %s.\n", temp->GetNextRoom()->GetName());
			printf("Food left: %d.\n", current_food);
		}
		else printf("There is no room in direction %s.\n", words[0].c_str());
	}
}

void Player::Pick(dynArray<MyString>& words){
	Item* temp;
	bool picked = false;
	switch (words.size()){
	case 2:{
			   for (int i = 0; i < Game->contain.size(); i++){
				   if (Game->contain[i]->GetType() == ITEM){
					   temp = dynamic_cast<Item*> (Game->contain[i]);
					   if (temp->GetContainer() == actual_room && temp->GetNameString() == words[1]){
						   if (temp->GetPickable()){
							   temp->SetContainer(inventory);
							   picked = true;
							   break;
						   }
						   else{
							   printf("The %s can not be picked.\n", temp->GetName());
							   return;
						   }
					   }
				   }
			   }
	}
		break;
	case 4:{
			   Item* container;
			   for (int i = 0; i < Game->contain.size(); i++){
				   if (Game->contain[i]->GetNameString() == words[3] && Game->contain[i]->GetType() == ITEM) {
					   container = dynamic_cast<Item*>(Game->contain[i]);
					   if (container->GetContainer() != actual_room && container->GetContainer() != inventory) 
						   printf("The %s is not in this room.", container->GetName());
					   else{
						   temp = container->HaveItem(words[1]);
						   if (temp != nullptr){
							   temp->SetContainer(inventory);
							   picked = true;
							   break;
						   }
						   else {
							   printf("The %s doesn't contain %s.\n", container->GetName(), words[1].c_str());
							   return;
						   }
					   }
				   }
			   }
	}
		break;
	default:{
				printf("I don't understand that.\n");
				return;
	}
		break;
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
	Item* lantern=nullptr;
	switch (words.size()){
	case 1:{
			   printf("I'm in the %s.\n%s", actual_room->GetName(),actual_room->GetDescription());
			   if (actual_room->GetNameString() == "Sants"){
				   for (int i = 0; i < Game->contain.size(); i++){
					   if (Game->contain[i]->GetNameString() == "lantern"){
						   lantern = dynamic_cast<Item*>(Game->contain[i]);
						   break;
					   }
				   }
				   if (wearing == lantern){
					   if (lantern->HaveItem(MyString("batteries"))!=nullptr){
						   printf("\nWith the lantern light I can see: ");
						   for (int i = 0; i < Game->contain.size(); i++){
							   if (Game->contain[i]->GetType() == ITEM){
								   temp = dynamic_cast<Item*> (Game->contain[i]);
								   if (temp->GetContainer() == actual_room){
									   printf("%s ", temp->GetName());
								   }
							   }
						   }
					   }
					   else printf("\nLantern don't have batteries.");
				   }
			   }
			   else if (actual_room->GetNameString()=="Parc de la Ciutadella"){
				   for (int i = 0; i < Game->contain.size(); i++){
					   if (Game->contain[i]->GetNameString() == "lantern"){
						   lantern = dynamic_cast<Item*>(Game->contain[i]);
						   break;
					   }
				   }
				   if (wearing == lantern){
					   if (lantern->HaveItem(MyString("batteries")) != nullptr){
						   printf("\nWith the lantern light I can see: ");
						   for (int i = 0; i < Game->contain.size(); i++){
							   if (Game->contain[i]->GetType() == ITEM){
								   temp = dynamic_cast<Item*> (Game->contain[i]);
								   if (temp->GetContainer() == actual_room){
									   printf("%s ", temp->GetName());
								   }
							   }
						   }
					   }
					   else printf("\nLantern don't have batteries.");
				   }
			   }
			   else{
				   
				   printf("\nI can see: ");
				   for (int i = 0; i < Game->contain.size(); i++){
					   if (Game->contain[i]->GetType() == ITEM){
						   temp = dynamic_cast<Item*> (Game->contain[i]);
						   if (temp->GetContainer() == actual_room){
							   printf("%s ", temp->GetName());
						   }
					   }
				   }
			   }
			   printf("\nFrom here, I can go to: ");
			   Connection* north = actual_room->GetConnection(MyString("north"));
			   Connection* south = actual_room->GetConnection(MyString("south"));
			   Connection* east = actual_room->GetConnection(MyString("east"));
			   Connection* west = actual_room->GetConnection(MyString("west"));
			   if (north != nullptr)printf("%s(north) ", north->GetNextRoom()->GetName());
			   if (south != nullptr)printf("%s(south) ", south->GetNextRoom()->GetName());
			   if (east != nullptr)printf("%s(east) ", east->GetNextRoom()->GetName());
			   if (west != nullptr)printf("%s(west)", west->GetNextRoom()->GetName());
	}
		break;
	case 2:{
			   for (int i = 0; i < Game->contain.size(); i++){
				   if (Game->contain[i]->GetType() == ITEM && Game->contain[i]->GetNameString() == words[1]){
					   temp = dynamic_cast<Item*> (Game->contain[i]);
					   if (temp->GetContainer() == actual_room|| temp->GetContainer()==inventory|| temp == inventory){
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

void Player::Drop(dynArray<MyString>& words){
	Item* temp;
	switch (words.size())
	{
	case 2:{
			   temp = inventory->HaveItem(words[1]);
			   if (temp!=nullptr){
				   temp->SetContainer(actual_room);
				   printf("I droped %s to the room.", temp->GetName());
			   }
			   else printf("I don't have %s in the inventory.", words[1].c_str());
		}
		break;
	case 4:{
				temp = inventory->HaveItem(words[1]);
				if (temp!=nullptr){
					Item* new_container;
					for (int i = 0; i < Game->contain.size(); i++){
					if (Game->contain[i]->GetNameString() == words[3] && Game->contain[i]->GetType() == ITEM){
						new_container = dynamic_cast<Item*> (Game->contain[i]);
						if (new_container->GetContainer() == actual_room || new_container->GetContainer()==inventory) {
							if (new_container->GetCanContain()){
								temp->SetContainer(new_container);
								printf("I put %s into %s.", temp->GetName(), new_container->GetName());
							}
							else printf("The %s can not contain other items.", new_container->GetName());
							}
						else printf("The %s is neither in the room nor my inventory.", new_container->GetName());
						}
					}
				}
				else printf("I don't have %s in the inventory.", words[1].c_str());
			}
		break;
	}
	printf("\n");
}

void Player::Equip(dynArray<MyString>& words){
	Item* temp;
	if ((temp=inventory->HaveItem(words[1]))!=nullptr){
		if (wearing == nullptr)printf("I equiped the %s.\n", temp->GetName());
		else printf("I change %s for %s.\n", wearing->GetName(),temp->GetName());
		wearing = temp;
	}
	else printf("I dont have %s.", words[1].c_str());
}

void Player::Unquip(){
	if (wearing != nullptr){
		printf("I unequip %s.\n", wearing->GetName());
		wearing = nullptr;
	}
	else printf("I don't have something equiped.\n");
}

void Player::Eat(dynArray<MyString>& words){
	Item* temp;
	temp = inventory->HaveItem(words[1]);
	if (temp != nullptr){
		if (temp->GetFoodRegen() > 0){
			current_food += temp->GetFoodRegen();
			temp->SetContainer(nullptr);
			printf("Eating %s, I regen %d food.\nCurrentFood: %d.\n", temp->GetName(), temp->GetFoodRegen(), current_food);
		}
		else printf("I can't eat %s.\n", temp->GetName());
	}
	else printf("I dont have %s.", words[1].c_str());
	
}

void Player::Cook(dynArray<MyString>& words){
	Item* stove;
	if (actual_room->GetNameString() == "Kitchen"){
		for (int i = 0; i < Game->contain.size(); i++){
			if (Game->contain[i]->GetType() == ITEM && Game->contain[i]->GetNameString() == "stove"){
				stove = dynamic_cast<Item*> (Game->contain[i]);
				Item* food;
				Item* cookfood;
				if ((food=stove->HaveItem(words[1]))!=nullptr){
					if (words[1] == "meat"){
						food->SetContainer(nullptr);
						for (int i = 0; i < Game->contain.size(); i++){
							if (Game->contain[i]->GetType() == ITEM&& Game->contain[i]->GetNameString() == "steak"){
								cookfood = dynamic_cast<Item*> (Game->contain[i]);
								cookfood->SetContainer(stove);
								printf("Cook finished.\n");
							}
						}
					}
					else if (words[1] == "fish"){
						food->SetContainer(nullptr);
						for (int i = 0; i < Game->contain.size(); i++){
							if (Game->contain[i]->GetType() == ITEM&& Game->contain[i]->GetNameString() == "fried-fish"){
								cookfood = dynamic_cast<Item*> (Game->contain[i]);
								cookfood->SetContainer(stove);
								printf("Cook finished.\n");
							}
						}
					}
					else if (words[1] == "eggs"){
						food->SetContainer(nullptr);
						for (int i = 0; i < Game->contain.size(); i++){
							if (Game->contain[i]->GetType() == ITEM&& Game->contain[i]->GetNameString() == "omelet"){
								cookfood = dynamic_cast<Item*> (Game->contain[i]);
								cookfood->SetContainer(stove);
								printf("Cook finished.\n");
							}
						}
					}
					else printf("I can't cook that.\n");
				}
				else printf("The %s is not in the stove.\n", words[1].c_str());
			}
		}
	}
	else printf("I can't cook this room.\n");
}

void Player::Create(dynArray<MyString>& words){
	Item* paw1 = nullptr;
	Item* paw2 = nullptr;
	Item* paw3 = nullptr;
	Item* paw4 = nullptr;
	Item* head = nullptr;
	Item* body = nullptr;
	Item* tail = nullptr;
	Item* cement = nullptr;
	Item* drake = nullptr;
	if (words[1] == "drake"){
		paw1 = inventory->HaveItem(MyString("frontleftpaw"));
		paw2 = inventory->HaveItem(MyString("frontrightpaw"));
		paw3 = inventory->HaveItem(MyString("backleftpaw"));
		paw4 = inventory->HaveItem(MyString("backrightpaw"));
		head = inventory->HaveItem(MyString("head"));
		tail = inventory->HaveItem(MyString("tail"));
		body = inventory->HaveItem(MyString("body"));
		cement = inventory->HaveItem(MyString("cement"));
		if (paw1 && paw2 && paw3 && paw4 && head && tail && body && cement){
			for (int i = 0; i < Game->contain.size(); i++){
				if (Game->contain[i]->GetNameString() == "drake"){
					drake = dynamic_cast<Item*> (Game->contain[i]);
					drake->SetContainer(inventory);
					paw1->SetContainer(drake);
					paw2->SetContainer(drake);
					paw3->SetContainer(drake);
					paw4->SetContainer(drake);
					body->SetContainer(drake);
					head->SetContainer(drake);
					tail->SetContainer(drake);
					cement->SetContainer(drake);
					printf("I create the Drake!!!\n");
					break;
				}
			}
		}
	}
	else printf("I can't create that.\n");
}