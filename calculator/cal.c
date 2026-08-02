#include <stdio.h>
#include <stdbool.h>

double memory = 0;
double total = 0;

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
		if (scanf("%i", &mode) != 1) {
			printf("Choose a valid mode.\n");
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
				printf("Arithmetic\n");
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

//void arithemetic(void) {
//	
//}
