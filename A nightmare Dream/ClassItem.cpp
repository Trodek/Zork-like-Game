#include "ClassEntity.h"
#include "ClassItem.h"
#include "ClassWorld.h"

Item* Item::HaveItem(MyString& other){
	Item* temp;
	for (int i = 0; i < Game->contain.size(); i++){
		if (Game->contain[i]->GetType() == ITEM){
			temp = dynamic_cast<Item*> (Game->contain[i]);
			if (temp->GetContainer()== this && temp->GetNameString()==other){
				return temp;
			}
		}
	}
	return nullptr;
}