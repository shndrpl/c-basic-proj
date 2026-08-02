#include <stdio.h>
#include <stdbool.h>

double memory = 0;
double total = 0;

// prototypes
void arithemetic(void);
double double_validation(char *str);
char char_validation(char *str);

int main(void) {
	int mode = 0;
	
	// ask user what mode
	bool flag = true;
	while (flag) {
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
				arithemetic();
				flag = false;
				break;
			case 2:
				// call remainder func
				printf("Remainder\n");
				flag = false;
				break;
			case 3:
				// call power func
				printf("Power\n");
				flag = false;
				break;
			case 4:
				// call average func
				printf("Average\n");
				flag = false;
				break;
			case 5:
				// quit
				printf("Bye!\n");
				return 0;
		}
		
	}
	return 0;
}

void arithemetic(void) {
	double first_num = double_validation("First Number");
	char ope = char_validation("Choose operator: ");
	double second_num = double_validation("Second Number");
	
	printf("\n");
	printf("\n");
	printf("First Number: %.2lf\n", first_num);
	printf("Operator: %c\n", ope);
	printf("First Number: %.2lf\n", second_num);
	
}

// helper function
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
		return ope;
	}
}