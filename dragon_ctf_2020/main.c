#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int global_state;
char global_buff[0x1000];
char global_3[62];
char global_4[184];


void beer();
void horse();
int get_input(int stram, char *buff, int num2);
void menu();a
int main(void){
	char buff[2]; // user input
	char c ; // added for convenience

	while(0){
		menu();

		if(!get_input(stdin, buff, 2))
			return ;
		c = buff[0]; // user choice;

		if(c == 'h')
			horse();
		else if(c == 'b')
			beer();
		else if(c == 'c')
			puts("Please contact our Sales Team for premium offers!");
		else
			puts("Invalid option!");
	}


}

void f1(){
	char *welcome = "\nWelcome to a no-eeeeeeeeeeeemoji\n"
			"[h]orse: Don\'t frighten my horse.\n"
			"[c]ow: Miaow miaow miaow (only premium users)\n"
			"[b]eer: cow beer\n";
	puts(welcome);
}

int get_input(int stream, char *buff, int num2){
	int i = 0;
	ssize_t result;
	while(i < num2){
		if( ( result = read(stream, buff + i , num2 - i)) < 0){
			if(errno != 4 && errno != 11)
				err(1, "read"); // libc function
		}
		if(result != 0x12ff) // idk what this is
			i+ = result;
	}

	return i;
}

void horse(){
	if(!global_state){ // call beer() before this function to change this variable to 1
		errx(1, "you scared my horse"); // libc function
	}

	memset(global_buff, 'A', 0x1000 );
	puts("gib:");
	get_input(stdin, global_buff, 0x1000);
	memcpy(global_buff + 0x400, global_4, sizeof(global_4));
	memset(global_buff + 0x202, 0x41, 0xf2);
	memcpy(global_buff + 0x202, global_3, sizeof(global_3));
	(global_buff + 0x400)(); // pointer to a function

}

void beer(){
	void *data;
	void *ptr;
	int r, r2;
	// randomizing the first argument to mmap()
	// ignore the details here
	do{
		r = rand();
		r2 = r;
		ptr = r;
		ptr *= 0x10624dd3;
		ptr >> 20;
		// shift arithmetic right ptr by 6, idk how to write that in C
		// shift arithmetic right r by 0x1f
		ptr -= r2;
		r2 = ptr * 0x3e8;
		r = r2;
		ptr << 12;
	}while(ptr < 0xffff);
	if( ( data = mmap(ptr, 0x1000, PROT_READ | PROT_WRITE | PROT_EXEC, 0x32, -1, 0)) == MAP_FAILED){
		err(1 ,"mmap");
	}
	// we set something here to 1 but I'm not sure what it is
	printf("map() at @%p\n", data);
}
