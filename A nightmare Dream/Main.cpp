#include "ClassEntity.h"
#include "ClassWorld.h"

World* Game = nullptr;

int main(){

	printf("\n			Welcome to A Nightmare Dream.\n");
	printf("			   A text based adventure.\n\n");

	printf("This is so boring... Every day the same. Go to class, take the same subway line,and listen to these stupid teachers.");
	printf(" Once the clock reaches 2 o'clock, the \nsame journey back home.Take the subway, go to my home building and take the \nleaver...");
	printf(" The half of the day is wasted without anything exciting and once I'm \nhome, the routine of every day... Warm the meal, wash the dishes,");
	printf(" and do the \nhomework. And finally, some distraction playing some of the few games I got on \nthe PC. Just to argue with my mum when she arrive ");
	printf("home because she says I'm \nalways playing games.\nTHIS SUCKS!\nAfter that just go dinner and sleep, just to wake up early and start again the \nsame shit.");
	printf("\nI wish I was alone and don't have to do the same every day...");
	printf("\nWhat time is it? It's so shiny to be early morning.What happen with the alarm \nclock?\n'Click', 'click'.What's happening here why the light isn't working? ");
	printf("\nWait... My phone is turned off too. Mum? Dad? They aren't here... Am I alone?\n");
	printf("'Bip''Bip'. What's that ? Seams there's something in my room... A message?\n");

	Game = new World;
	bool end = false;
	
	while (!end){
		end = Game->Play();
	}

	delete Game;

	printf("\nPress enter to exit...");
	getchar();
	return 0;
}

//This is so boring… Every day the same.Go to class, take the same subway line, and listen to these stupid’s teachers.Once the clock reaches 2 o’clock, the same journey back home.Take the subway, go to my home building and take the leaver… The half of every day is wasted without anything exciting and once I’m home, the routine of every day… warm the meal, wash the dishes, and do the homework.And finally, some distraction playing the some of the few games I got on the PC.Just to argue with my mum when they arrive home because she says I’m always playing games.THIS SUCKS.After that just go dinner and sleep, just to wake up early and start again the same shit.I wish I was alone and don’t have to do the same every day…
//What time is it ? It’s so shiny to be early morning.What happen with the alarm clock ? ‘Click’ ‘click’.What’s happening here why the light isn’t working ? Wait… My phone is turned off too.Mum ? Dad ? They aren’t here… I’m alone ?
//‘Bip’’Bip’.What’s that ? Seams there’s something in my PC screen… A message ?