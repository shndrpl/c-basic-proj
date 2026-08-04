#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[50];
    char phone[20];
    char email[50];
    char address[100];
} Contact;

Contact contacts[] = {
    {1, "Juan Dela Cruz", "09171234567", "juan.delacruz@email.com", "Cagayan de Oro City"},
    {2, "Maria Santos", "09981234567", "maria.santos@email.com", "Manila City"},
    {3, "John Reyes", "09261234567", "john.reyes@email.com", "Davao City"},
    {4, "Angela Cruz", "09192345678", "angela.cruz@email.com", "Cebu City"},
    {5, "Michael Tan", "09351234567", "michael.tan@email.com", "Quezon City"},
    {6, "Sophia Garcia", "09481234567", "sophia.garcia@email.com", "Iloilo City"},
    {7, "Daniel Lim", "09671234567", "daniel.lim@email.com", "Bacolod City"},
    {8, "Camille Flores", "09781234567", "camille.flores@email.com", "Baguio City"},
    {9, "Ethan Mendoza", "09561234567", "ethan.mendoza@email.com", "Zamboanga City"},
    {10, "Chloe Ramos", "09081234567", "chloe.ramos@email.com", "General Santos City"}
};

int contactCount = sizeof(contacts) / sizeof(contacts[0]);

// prototypes
int menu_choice(void);
void add_contact(void);
void helper_add_contact(char *str1, char *str2);

int main(void) {
	
	while(1) {
		int menu = menu_choice();
		
		switch (menu) {
			case 1:
				// Add Contact
				add_contact();
				break;
			case 2:
				// View Contacts
				break;
			case 3:
				// Search Contact
				break;
			case 4:
				// Update Contact
				break;
			case 5:
				// Delete Contact
				break;
			case 6:
				// exit
				return 0;
		}
		
		flag = false;
		
		
	}
	
	//int lastDigit = contactCount - 1;
	
	//printf("Name: %s", contacts[lastDigit].name);
	//printf("Name: %s", contacts[lastDigit].phone);
	//printf("Name: %s", contacts[lastDigit]);
	//printf("Name: %s", contacts[lastDigit]);
	
	
	return 0;
}

// menu function
int menu_choice(void) {
	int choice;
	while (1) {
		printf("[1] Add Contact\n");
		printf("[2] View Contacts\n");
		printf("[3] Search Contact\n");
		printf("[4] Update Contact\n");
		printf("[5] Delete Contact\n");
		printf("[6] Exit\n");
		printf("::: ");
		
		if (scanf("%i", &choice) != 1) {
			printf("Choose a valid input.\n");
			
			while(getchar() != '\n');
			continue;
		}
		
		switch (choice) {
			case 1:
				printf("----- Add Contact -----\n");
				return choice;
			case 2:
				printf("----- View Contacts -----\n");
				return choice;
			case 3:
				printf("----- Search Contact -----\n");
				return choice;
			case 4:
				printf("----- Update Contact -----\n");
				return choice;
			case 5:
				printf("----- Delete Contact -----\n");
				return choice;
			case 6:
				printf("----- Babye! -----\n");
				return choice;
		}
	}
}


// Add Contact function
void add_contact(void) {
	// name
	helper_add_contact("Name", "Please a valid name");
	
	// phone number
	helper_add_contact("Phone Number", "Please a valid phone number");
	
	// email
	helper_add_contact("Email", "Please a valid email");
	
	// address
	helper_add_contact("Address", "Please a valid address");
	
	return;
}

// helper for add contact function
void helper_add_contact(char *str1, char *str2) {
	int lastIndex = contactCount - 1;
	
	while (1) {
		printf("%s: ", str1);
		printf("::: ");
		
		if(scanf("%s", contacts[lastIndex].name) != 1) {
			printf("%s\n", str2);
			
			while(getchar() != '\n');
			continue;
		}
		return;
	}
}


// View Contacts


// Search Contact


// Update Contact


// Delete Contact





// selection sort