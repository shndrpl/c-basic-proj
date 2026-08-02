#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {

// generate a random number between 1 - 100
srand(time(NULL));
int randomNum = rand() % 100 + 1;

int user_guess;
int attempt = 0;

while (1) {
	
	if (attempt > 10) {
		printf("Game Over! You've reach the 10 attemps limit.\n");
		return 0;
	}
	
	attempt++;
	printf("Guess a Number between 1 - 100: ");
	if (scanf("%i", &user_guess) != 1) {
		printf("\n");
		printf("Please enter a valid Number.\n");
		printf("\n");
		
		while (getchar() != '\n');
		
		continue;
	}
	
	if (user_guess == randomNum) {
		printf("Correct! It's %i. It took you %i attempts.\n", randomNum, attempt);
		return 0;
	}
	else if (user_guess < randomNum) {
		printf("Too Low.\n");
	}
	else if (user_guess > randomNum) {
		printf("Too High.\n");
	}
	
}
}
