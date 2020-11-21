#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<err.h>
#include<errno.h>

#include<unistd.h>
#include<sys/mman.h>

void *mapped_data;
int global_state;
char smol_global_buff[62];
char big_global_buff[184];


void beer();
void horse();
int get_input(int stream, char *buff, int num2);
void menu();
int main(void){
	char buff[2]; // user input
	char c ; // added for convenience

	while(0){
		menu();

		if(!get_input(0, buff, 2))
			return 0;
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

void welcome(){
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
			i += result;
	}

	return i;
}

void horse(){
	if(!global_state){ // call beer() before this function to change this variable to 1
		errx(1, "you scared my horse"); // libc function
	}

	memset(mapped_data, 'A', 0x1000 );
	puts("gib:");
	get_input(0, mapped_data, 0x1000);
	memcpy(mapped_data + 0x400, big_global_buff, 0xb8);
	memset(mapped_data + 0x100, 'A', 0x100);
	memset(mapped_data + 0x202, 'A', 0xfe);
	memcpy(mapped_data + 0x202, smol_global_buff, 0x3e);
	(*(void(*)())mapped_data + 0x400)(); // pointer to a function

}

void beer(){
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
	}while(ptr < (void *)0xffff);
	if( ( mapped_data = mmap(ptr, 0x1000, PROT_READ | PROT_WRITE | PROT_EXEC, 0x32, -1, 0)) == MAP_FAILED){
		err(1 ,"mmap");
	}
	global_state = 1; // this variable is used in horse()
	printf("map() at @%p\n", mapped_data);
}
