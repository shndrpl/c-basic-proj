#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX 20

typedef struct
{
    int id;
    char name[50];
    char phone[20];
    char email[50];
    char address[100];
} Contact;

Contact contacts[MAX] = {
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
void validate_name(char *fieldName, char *errorText, int slot);
void validate_phone(char *fieldName, char *errorText, int slot);

int main(void) {
	
	bool flag = true;
	while(flag) {
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
	
//	for (int i = 0; i < contactCount; i++) {
//		printf("Name: %s\n", contacts[i].name);
//		printf("Phone: %s\n", contacts[i].phone);
//		printf("Email: %s\n", contacts[i].email);
//		printf("Address: %s\n", contacts[i].address);
//		printf("-------------------------------------\n");
//	}
	
	
	
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
	// get the first slot of struct
	int slot = -1;
	for (int i = 0; i < MAX; i++) {
		if (contacts[i].name[0] == '\0') {
			slot = i;
			break;
		}
	}
	
	if (slot == -1) {
		printf("Contact is full\n");
		return;
	}
	
	
	// name
	validate_name("Name: ", "Please enter a valid name", slot);
	
	// phone number
	validate_phone("Phone Number: ", "Please enter a valid number", slot);
	
	
	// email
	
	
	// address
	
	
	return;
}


void validate_name(char *fieldName, char *errorText, int slot) {
	char tempName[50];
	
	while(1) {
		bool flag = true;
		while(getchar() != '\n');
		printf("%s", fieldName);
		scanf("%s", tempName);
		
		for (int i = 0; tempName[i] != '\0'; i++) {
			if (!isalpha((unsigned char) tempName[i])) {
				printf("%s\n", errorText);
				flag = false;
				break;
			}
		}
		
		if (flag) {
			strcpy(contacts[slot].name, tempName);
			printf("TempName: %s\n", contacts[slot].name);
			printf("\n");
			return;
		}
	}
}

void validate_phone(char *fieldName, char *errorText, int slot) {
	char tempPhone[50];
	
	while(1) {
		bool flag = true;
		while(getchar() != '\n');
		printf("%s", fieldName);
		scanf("%s", tempPhone);
		
		for (int i = 0; tempPhone[i] != '\0'; i++) {
			if (!isdigit((unsigned char) tempPhone[i])) {
				printf("%s\n", errorText);
				flag = false;
				break;
			}
		}
		
		if (flag) {
			strcpy(contacts[slot].phone, tempPhone);
			printf("TempPhone: %s\n", contacts[slot].phone);
			printf("\n");
			return;	
		}
	}
}


// View Contacts


// Search Contact


// Update Contact


// Delete Contact





// selection sort