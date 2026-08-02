#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double memory = 0;
double result = 0;
long long_result = 0;

// prototypes
int choose_mode(void);
void arithmetic(void);
double double_validation(char *str);
char char_validation(char *str);
void remain(void);
void to_power(void);
int int_validation(char *str);

int main(void) {
	
	bool flag = true;
	while (flag) {
		int mode = choose_mode();
		
		// check if user choose quit
		if (mode == 5) {
			return 0;
		}
		
		switch (mode) {
			case 1:
				arithmetic();
				break;
			case 2:
				remain();
				break;
			case 3:
				to_power();
				break;
			case 4:
				// average
				break;
		}
		
		printf("Result: %li\n", long_result);
		
		flag = false;
	}
	
	
	return 0;
}


int choose_mode(void) {
	int mode;
	while (1) {
		printf("[1 -> Normal Arithmetic] --- ");
		printf("[2 -> Remainder] --- ");
		printf("[3 -> Power] --- ");
		printf("[4 -> Calculate Average] --- ");
		printf("[5 -> Exit]");
		printf("\n");
		printf("::: ");
		if (scanf("%i", &mode) != 1) {
			printf("Choose a valid mode.\n");
			printf("::: ");
			while(getchar() != '\n');
			continue;
		}
		
		if (mode < 1 || mode > 5) {
			printf("1 - 5 Only.\n");
			while(getchar() != '\n');
			continue;
		}
		
		printf("\n");
		
		switch (mode) {
			case 1:
				// call arithmetic func
				printf("----------Arithmetic----------\n");
				return 1;
			case 2:
				// call remainder func
				printf("----------Remainder----------\n");
				return 2;
			case 3:
				// call power func
				printf("----------Power----------\n");
				return 3;
			case 4:
				// call average func
				printf("----------Average----------\n");
				return 4;
			case 5:
				// quit
				printf("----------Babye!----------\n");
				return 5;
		}
	}	
}



void arithmetic(void) {
	double first_num = double_validation("First Number");
	char ope = char_validation("Choose operator: ");
	double second_num = double_validation("Second Number");
	
	// calculate and save to variable result
	switch (ope) {
		case '+':
			result = first_num + second_num;
			return;
		case '-':
			result = first_num - second_num;
			return;
		case 'x':
		case 'X':
			result = first_num * second_num;
			return;
		case '/':
			if (second_num < 1) {
				printf("Error: Second number is less than 1\n");
			}
			else {
				result = first_num / second_num;
			}
			return;
	}
	
	printf("\n");
	printf("\n");
}

// Helper function
double double_validation(char *str) {
	double num;
	
	while (1) {
		printf("%s\n", str);
		printf("::: ");
		if (scanf("%lf", &num) != 1) {
			printf("Enter a valid number.\n");
			
			while(getchar() != '\n');
			continue;
		}
		printf("\n");
		return num;
	}
}

char char_validation(char *str) {
	char ope;
	
	while (1) {
		printf("CHOOSE AN OPERATOR\n");
		printf("['+' Addition]   ['-' Subtraction]\n");
		printf("['x' Multiplication]   ['/' Division]\n");
		printf("::: ");
		if (scanf(" %c", &ope) != 1) {
			printf("Choose a valid operator. \n");
			
			while(getchar() != '\n');
			continue;
		}
		printf("\n");
		
		if (ope == '+' || ope == '-' || (ope == 'x' || ope == 'X') || ope == '/') {
			return ope;
		}
	}
}

// Remainder func
void remain(void) {
	double first_num = double_validation("First Number: ");
	double second_num = double_validation("second Number: ");
	result = fmod(first_num, second_num);
	return;
}

// power function
void to_power(void) {
	int base_num = int_validation("Base number: ");
	int expo_num = int_validation("Exponent number: ");
	
	long_result = pow(base_num, expo_num);
}

// Helper function for int_validation
int int_validation(char *str) {
	int num;
	while (1) {
		printf("%s\n", str);
		printf("::: ");
		
		if (scanf("%i", &num) != 1) {
			printf("Enter a valid integer number\n");
			
			while(getchar() != '\n');
			continue;
		}
		return num;
	}
}