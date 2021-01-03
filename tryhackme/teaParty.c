#include<stdio.h>
#include<stdlib.h>

#include<unistd.h>

int main(void){
	setuid(1003);
	setgid(1003);

	puts("Welcome to the tea party!\nThe Mad Hatter will be here soon.");

	system("/bin/echo -n \'Probably by \' && date --date=\'next hour\' -R");

	puts("Ask very nicely, and I will give you some tea while you wait for him");

	getchar();

	puts("Segmentation fault (core dumped)");
}
