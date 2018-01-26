#include <stdio.h>	
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <unistd.h>

#define BUFFER_SIZE 25 
// #define ULL unsigned long long

void printUsage(void);
/*bool isPrime(ULL num);
ULL getInput(void);
char* getInput(void);
ULL parseInput(char* numstr);
*/

// is_prime(num) checks if num is a prime number
bool is_prime(int num);

int main(int argc, char* argv[]){

	if(argc == 1){
		//use unsigned long long
	}else{
		int c;
		char* snum;
		while((c = getopt(argc, argv, "Bb:hn:")) != -1){
			switch(c){
				case 'B':
					//entering big-number mode
					printf("big number mode\n");
					break;
				case 'b':
					printf("single big number mode\n");
					//check the number in big-number mode
					break;
				case 'h':
					printUsage();
					exit(0);
				case 'n':
					printf("single regular mode\n");
				/*{
					ULL num = parseInput(optarg);
					if(num >= 2){
						printf("%llu is %sa prime number\n", num, (isPrime(num))?"":"not ");
						exit(0);
					}else
						exit(1);
				}*/	
			}	
		}	
	}

/*	printf("------------------------------------------------------------\n");
	printf("This program is a prime checker; it takes a positive integer\n");
	printf("that is greater than 1 and less than 18446744073709551615 or\n");
	printf("2^64 - 1 and then returns whether it is a prime number.\n");
	printf("------------------------------------------------------------\n");

	ULL num;

	while(true){
		num = getInput();
		if(num == 1)
			continue;
		else
			printf("%llu is %sa prime number.\n", num, (isPrime(num))? "" : "NOT ");
	}*/	
	return 0;
}

bool is_prime(int num){
	for (int i = 2; i * i <= num; ++i){
		if (num % i == 0){
			return false;
		}
	}
	return true;
}


/*
bool isPrime(ULL num){
	for(ULL i = 2; i * i <= num; i++)
		if(num % i == 0)
			return false;
	return true;
}

ULL getInput(void){
	char buffer[BUFFER_SIZE];

	printf("Please enter a number: ");

	//read input error, exit the program
	if(!fgets(buffer, BUFFER_SIZE, stdin)){
		fprintf(stderr, "EOF encountered. Now exiting the program.\n");
		exit(1);
	}

	//too many digits error, return 1
	{
		char* c = strchr(buffer, '\n');
		if(c)
			*c = '\0';
		else{
			printf("ERROR: input has too many digits.\n");
			while(getchar() != '\n')
				continue;
			return 1;
		}
	}
	
	//non-digit error, return 1
	{
		char* c = buffer;
		while(*c != '\0'){
			if(!isdigit(*c)){
				printf("ERROR: input contains non-digit characters.\n");
				return 1;
			}
			c++;
		}
	}

	ULL result = strtoull(buffer, NULL, 10);
	if(result == 0)
		exit(0);
	//invalid input error, return 1
	else if(result < 2){
		printf("ERROR: invalid input.\n");
		return 1;
	//out of range error, return 1
	}else if(result == ULLONG_MAX){
		printf("ERROR: input is out of range.\n");	
		return 1;
	}

	return result;
}*/

void printUsage(void){
	puts("USAGE: PrimeChecker [-B] [-b <number>] [-h] [-n <number>]");
/*	puts("COMMAND LINE OPTIONS");
	puts("		-B, big-number mode");
	puts("			Entering big-number mode that accepts numbers beyond 2^64 - 1");
	puts("");
	puts("		-b <number>, check <number> in big-number mode");
	puts("");
	puts("		-h, help");
	puts("");
	puts("		-n <number>, check <number> in regular mode");*/
}
