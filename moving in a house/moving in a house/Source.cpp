#include <stdio.h>

enum rooms {empty, bedroom, dinning, kitchen, bathroom, pantry};

struct position {
	int x;
	int y;
	rooms room;
};

int main(){
	
	rooms map[5][4] = {
		{empty, empty,empty,empty},
		{empty,kitchen,pantry,empty},
		{empty,dinning, bathroom,empty},
		{empty,bedroom,empty,empty},
		{empty,empty,empty,empty}
	};
	position player = { 2, 1 };
	int end = 1;
	char n;
	while (end){
		player.room = map[player.x][player.y];
		switch (player.room)
		{
		case bedroom: printf("You are in the bedroom.\n"); break;
		case kitchen: printf("You are in the kitchen.\n"); break;
		case dinning: printf("You are in the dinning room.\n"); break;
		case bathroom: printf("You are in the bathroom.\n"); break;
		case pantry: printf("You are in the pantry.\n"); break;
		}

		printf("Where do you want to go?(n/s/e/w/q).");
		scanf_s("%c", &n, 1);
		getchar();
		switch (n){
			case 'n': if (map[player.x - 1][player.y] != empty) player.x -= 1;
					  else printf("You can't move there.\n"); break;
			case 's': if (map[player.x + 1][player.y] != empty) player.x += 1;
					  else printf("You can't move there.\n"); break;
			case 'w': if (map[player.x][player.y - 1] != empty) player.y -= 1;
					  else printf("You can't move there.\n"); break;
			case 'e': if (map[player.x][player.y + 1] != empty) player.y += 1;
					  else printf("You can't move there.\n"); break;
			case 'q': printf("See you next time.");
					  end = 0;
					  break;
		}

	}

	getchar();
	return 0;
}