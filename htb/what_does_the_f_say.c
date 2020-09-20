#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

double srocks = 69.69;

void food_menu(void);
void warning(void);
void enjoy(char *ptr);
void drinks_menu(void);
void menu(void);
void goodbye(void);
void srock_check(void);
void fox_bar(void);
void welcome(void);
void setup(void);
int main(void){ // checked
	setup();

	welcome();

	fox_bar(); // checking ptr
	
	return 0;
}

void setup(void){ // checked

	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);

}

void welcome(void){ // checked

	puts("");
	puts("Welcome to Fox space bar!");

}

void fox_bar(void){ // checked but not the sub functions // ptr
	int menu_choice;

	while(1){
		puts("");
		printf("Current space rocks: %.2f\n", srocks); 
	
		srock_check();
	
		menu();
	
		scanf("%d", &menu_choice);
	
		if(menu_choice == 1)
			drinks_menu(); // ptr
		else if(menu_choice == 2)
			food_menu();
		else{
			puts("Invalid option!");
			goodbye();
		}

	}
}

void srock_check(void){ // checked

	if(srocks < 0){
		puts("");
		puts("Not enough space rocks!");
		goodbye();
	}

}

void goodbye(void){

	puts("");
	puts("Exiting..");
	exit(0x69);

}

void menu(void){ // checked

	char *ptr =	"1. Space drinks\n"
			"2. Space food";
	puts("");
	puts(ptr);

}

void drinks_menu(void){
	char buf[30];
	int drink_choice;

	memset(buf, 0, sizeof(buf));

	puts("");
	puts("1. Milky way (4.90 s.rocks)");
	puts("2. Kryptonite vodka (6.90 s.rocks)");
	puts("3. Deathstar(70.00 s.rocks)");

	scanf("%d", &drink_choice);

	if(drink_choice == 1){

		srocks -= 4.9; // good
		srock_check();

		if(srocks < 20.00){  // can't fingure out how to print this value in gdb
			puts("");
			puts("You have less than 20 space rocks!");
		}

		enjoy("Milky way");

	}
	else if(drink_choice == 2){

		srock_check();
		puts("");
		puts("Red or Green Kryptonite?");

		read(0, buf, 29);
		printf(buf); // found the bug!!!

		warning(); // ptr
	}
	else if(drink_choice == 3){
		srocks -= 6.9;
		srock_check();

		if(srocks < 20.00)  // guessed!!
			puts("You have less than 20 space rocks!");

		enjoy("Deathstar");
	}
	else{
		puts("Invalid option!");
		goodbye();
	}

	// might see this part as a return 0

}

void enjoy(char *ptr){

	puts("");
	printf("Enjoy your %s!\n");

}

void warning(void){
	char affirmation[idk_size];

	if(srocks > 20){ // 6.9 was guessed here cause that's the Kryptonite's price!!
		enjoy("Kryptonite vodka");
		srocks -= 6.9;
		srock_check();
		return;
	}

	puts("");
	puts("You have less than 20 space rocks! Are you sure you want to buy it?");

	scanf("%s", &affirmation);
	if(!strcmp(affirmation, "yes")){
		srocks =- 6.9;
		srock_check();
		enjoy("Kryptonite vodka");
		
	}
	else if(strcmp(affirmation, "no")){
		puts("");
		puts("A Milky way is nice too if you want..");

	}
	else
		return;// 0;
}

void food_menu(void){
	int food_choice;

	char *ptr = 	"1. E.Tarts (6.90 s.rocks)\n"
			"2. Space Brownies (5.90 s.rocks)\n"
			"3. Spacecream (7.90 s.rocks)";
	puts("");
	puts(ptr);

	scanf("%d", &food_choice);

	if(food_choice == 3){
		srocks -= 7.9;
		srock_check();
		if(srocks < 20) 
			puts("You have less than 20 space rocks!");
		enjoy("Spacecream");
	}
	else if(food_choice == 1){
		srocks -= 6.9;
		srock_check();
		if(srocks < 20) // check
			puts("You have less than 20 space rocks!");
		enjoy("E.Tarts");
	}
	else if(food_choice == 2){
		srocks -= 5.9;
		srock_check();
		if(srocks < 20)
			puts("You have less than 20 space rocks!");
		enjoy("Space Brownies");		
	}
	else{
		puts("Invalid option!");
		goodbye();
	}

}
