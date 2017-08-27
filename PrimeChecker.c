#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <unistd.h>

#define BUFFER_SIZE 25 
#define ULL unsigned long long

bool isPrime(ULL num);
ULL getInput(void);

int main(void){
	printf("------------------------------------------------------------\n");
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
	}	
	return 0;
}

bool isPrime(ULL num){
	for(ULL i = 2; i * i <= num; i++)
		if(num % i == 0)
			return false;
	return true;
}

ULL getInput(void){
	char buffer[BUFFER_SIZE];

	printf("Please enter a number (enter '0' to quit) : ");

	//read input error, exit the program
	if(!fgets(buffer, BUFFER_SIZE, stdin)){
		fprintf(stderr, "Input error! Now exiting the program.");
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
}
