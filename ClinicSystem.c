// Clinic management system (C final project)
// Made by Maged Magdy

//Header files
#include<stdio.h> // Used for standard I/O operations
#include<windows.h> // Used for system(cls) to clear the window
#include <stdlib.h> // Used for malloc() to book a place in the heap
#include<conio.h> // Used for getch() to hold the screen 
#include "stdtypes.h" // Used for setting standard data types

//********************************************************************************************

// Enamurations to avoid magic numbers
enum modes {
	admin,
	user
}mode;

enum slots {
	slot1 = 1,
	slot2 = 2,
	slot3 = 3,
	slot4 = 4,
	slot5 = 5
};

enum choices {
	back,
	exits
}choice;

//********************************************************************************************

//Functions declaration
void welcomeScreen(void); // Used for welcoming the user or admin
void exitScreen(void); // Used for delivering a thanking message
void backToMain(void); // Used for going back to user or admin menu and make another task
void makeChoice(void); // Used for choosing between going back or exiting the system
void adminMode (void); // Used for desplaying the admin mode features and choosing among them
void userMode (void); // Used for desplaying the user mode features and choosing between them
void addNew(void); // Used for adding new patient record
void showOrEditRec(void); // Used for showing or editing patient record depend on the mode 
void reserveSlot(void); // Used for reserving a slot with the doctor
void cancelRes(void); // Used for canceling a reservation
void viewRes(void); // Used for printing the reservations

//********************************************************************************************

//list of global variable 
typedef struct {
	u8 firstName[20], lastName[20], gender[20];
	u32 age, id; 
	struct patient *nxt; // pointer to the next patient data
} patient; // for patient information

patient *first = NULL;

struct reserve {
	u32 id[5]; // The ID of the patient
	u8 slotNum[5]; // The desired slot
}slot; // for reservation information

//********************************************************************************************

// Main function 
void main (void){
	welcomeScreen(); // calling welcomeScreen() function
	if(mode == admin){  // check if the mode is admin (0)
		u32 pass; // declaring a variable which holds the password
		printf("----------------------------------------------\n"); // A dividing line
		for (u8 i=0; i<3; i++){ // Loop for taking 3 trials 
			printf("Enter the password: "); // printing the request to enter the password
			scanf("%d", &pass); // scaning the password from the admin
			if(pass == 1234){ // checking if the password is correct
				system("cls"); // Use to clear screen
				adminMode(); // calling adminMode() function
				break; // Used for exiting the loop when the condition is correct
			}
			printf("\n"); // Used to make a new line 
		}
	} else if(mode == user){ // check if the mode is user (1)
		userMode(); // calling userMode() function
	}
}

//********************************************************************************************

//Welcome screen 
void welcomeScreen(void){ //function definition
	system("cls");//Use to clear screen
	printf("\n****** IMT clinic ******\n"); 
	printf("Welcome to our system!\n");
	printf("=================================================\n");
	printf("\n\nPress any key to continue......\n");
	getch();//holds screen 
	system("cls");//Use to clear screen
	printf("Enter your mode (Admin=0, User=1): "); // printing the request to choose the mode
	scanf("%d", &mode); //scaning the mode value (0 or 1)
	
}

//********************************************************************************************

//Admin monitor
void adminMode(void){ // function definition
	u8 ftr; // declaring a variable which holds the number of the feature
	printf("Choose from 1 to 4: \n"); // printing the request to choose a feature
	printf("1. Add new patient record. \n"); 
	printf("2. Edit patient record. \n"); 
	printf("3. Reserve a slot with the doctor. \n");
	printf("4. Cancel reservation. \n"); 
	printf("=================================================\n"); // a dividing line
	printf("Your chosen operation: ");
	scanf("%d", &ftr); // scaning the feature number from admin
	switch (ftr){ //switch to different case
	case 1: 
		addNew(); // calling addNew() function
		break;
	case 2:
		showOrEditRec(); // calling showOrEditRec() function
		break;
	case 3:
		reserveSlot(); // calling reserveSlot() function
		break;
	case 4:
		cancelRes(); // calling cancelRes() function
		break;
	default:
		system("cls"); //Used to clear screen
		printf("Invalid entry. Please enter right option\n\n"); // error message
		adminMode(); // calling again to repeat the operation
	}
}

//********************************************************************************************

//User monitor
void userMode(void){ //function definition
	u8 ftr; // declaring a variable which holds the number of the feature
	printf("Choose from coming two options: \n"); // printing the request to choose a feature
	printf("1. View patient record. \n");
	printf("2. View today's reservations. \n");
	printf("=================================================\n"); // dividing line
	printf("Your chosen operation: "); 
	scanf("%d", &ftr); // scaning the feature number from admin
	switch (ftr){ //switch to different case
	case 1:
		showOrEditRec(); // calling showOrEditRec() function
		break;
	case 2:
		viewRes(); // calling viewRes() function
		break;
	default:
		system("cls"); //Used to clear screen
		printf("Invalid entry. Please enter right option\n\n"); // error message
		userMode(); // calling again to repeat the operation
	}
}

//********************************************************************************************

//Add new patient record
void addNew(void){ //function definition
	system("cls"); //Use to clear screen
	u32 idCheck; // declaring a variable which holds the ID 
	patient *temp = (patient*) malloc(sizeof(patient)); // declaring pointer reserves size in heap
	patient* current = first; // declaring a pointer
	temp->nxt = first;
	first = temp;
	printf("Enter the new patient information......\n"); // request to enter the patient info
	printf("First name: ");
	scanf("%s", &(temp->firstName)); 
	printf("Last name: ");
	scanf("%s", &(temp->lastName));
	printf("Age: ");
	scanf("%d", &(temp->age));
	printf("Gender: ");
	scanf("%s", temp->gender);
	printf("ID: ");
	scanf("%d", &idCheck);
	while (current!= NULL){ //loop for scaning all the list patient by patient
		if (current->id == idCheck){ // check if the ID exists before
			printf("This ID already exists!"); //error message
			addNew(); // calling again to repeat the operation
			break; //use to exit the loop
		}
		current = current->nxt; // moving to the next patient
	}
	if (current == NULL){ // check if true then the ID is original
		temp->id = idCheck; // signing the ID in the system list
		temp->nxt = first;
		first = temp;
	}
	
	makeChoice(); // Redirecting the admin to choose the next move
}

//********************************************************************************************

//Viewing or editing patient record
void showOrEditRec(void){ //function definition
	system("cls");//Use to clear screen
	patient* current = first; // declaring a pointer
	u32 idSearch; // declaring a variable which holds the ID 
	printf("Enter the patient ID: "); // request to enter the ID
	scanf("%d", &idSearch); //scaning the ID 
	
	while (current!= NULL){ //loop for scaning all the list patient by patient
		if (current->id == idSearch){ // check if the ID exists before
			if (mode == admin){ // check if the mode is admin to re-enter patient info
				printf("Enter the new edited patient information......\n"); // request to re-enter the patient info
				printf("First name: ");
				scanf("%s", &(current->firstName));
				printf("Last name: ");
				scanf("%s", &(current->lastName));
				printf("Age: ");
				scanf("%d", &(current->age));
				printf("Gender: ");
				scanf("%s", &(current->gender));
				printf("ID: ");
				scanf("%d", &(current->id));
				break; //use to exit the loop
			} else { // if not, it is user mode. so, print the patient info 
				printf("Name: %s", current->firstName);
				printf(" %s\n", current->lastName);
				printf("Age: %d\n", current->age);
				printf("Gender: %s\n", current->gender);
				printf("ID: %d\n", current->id);
				break; //use to exit the loop
			}
		}
		current = current->nxt; // moving to the next patient
	}
	if (current == NULL) // check if true then the ID doesn't exist
		printf("Incorrect ID!\n");
	
	makeChoice(); // Redirecting the admin or user to choose the next move
}

//********************************************************************************************

//Reserve a slot with the doctor
void reserveSlot(void){ //function definition
	system("cls");//Use to clear screen
	u8 i; // looping factor 
	printf("The available slots:\n");
	if (slot.slotNum[0]==0) //to control the apearing & disapearing of this slot
	printf("1) 2pm to 2:30pm\n");
	if (slot.slotNum[1]==0) //to control the apearing & disapearing of this slot
	printf("2) 2:30pm to 3pm\n");
	if (slot.slotNum[2]==0) //to control the apearing & disapearing of this slot
	printf("3) 3pm to 3:30pm\n");
	if (slot.slotNum[3]==0)	//to control the apearing & disapearing of this slot
	printf("4) 4pm to 4:30pm\n");
	if (slot.slotNum[4]==0) //to control the apearing & disapearing of this slot
	printf("5) 4:30pm to 5pm\n");
	printf("=================================================\n"); // dividing line
	printf("The desired slot: "); //request to enter the desired slot
	scanf("%d", &i); // scaning the desired slot number
	printf("Patient ID: "); // request to enter the patient ID
	scanf("%d", &(slot.id[i])); // scanning the patient ID
	slot.slotNum[i-1] = i; // saving the chosen slot number in the system
	
	makeChoice(); // Redirecting the admin to choose the next move
}

//********************************************************************************************

//Cancel reservation
void cancelRes(void){ //function definition
	system("cls");//Use to clear screen
	u32 idSearch; // declaring a variable which holds the ID 
	printf("Enter the patient ID: "); // request to enter the ID
	scanf("%d", &idSearch); //scaning the ID 
	for (u32 i=0; i<5; i++){ // loop for scaning all the array 
		if (slot.id[i] == idSearch){ //check to find the required ID 
			slot.id[i] = 0; //removing ID
			slot.slotNum[i] = 0; //Canceling slot reservation
			break; // use to exit the loop
		}
	}
	
	makeChoice(); // Redirecting the admin to choose the next move
}

//********************************************************************************************

//View today's reservations
void viewRes(void){ //function definition
	system("cls");//Use to clear screen
	for (u8 i=0; i<5; i++){ // loop for scaning all the array 
		if(slot.slotNum[i] != 0){ // check if the slots are reserved
			printf("The Patient %d has reserved from", slot.id[i]); //printing the reserved slots
			if(slot.slotNum[i] == slot1) 
				printf(" 2pm to 2:30pm\n");
			else if(slot.slotNum[i] == slot2)
				printf(" 2:30pm to 3pm\n");
			else if(slot.slotNum[i] == slot3)
				printf(" 3pm to 3:30pm\n");
			else if(slot.slotNum[i] == slot4)
				printf(" 4pm to 4:30pm\n");
			else if(slot.slotNum[i] == slot5)
				printf(" 4:30pm to 5pm\n");
		}
	}
	
	makeChoice(); // Redirecting the user to choose the next move
}

//********************************************************************************************

//Choose from exiting the system or go back 
void makeChoice(void){ //function definition
	system("cls"); // use to clear screen
	printf("The operation was successful.\n"); //done message
	printf("Back (0) or Exit (1)?\n"); // choosing message
	printf("=================================================\n"); // dividing line
	scanf("%d", &choice); //scaning the choice
	if(choice == exits) //check if the choice is exit (0)
		exitScreen(); //calling exitScreen() function
	else if (choice == back) //check if the choice is back (1)
		backToMain(); //calling backToMain() function
	else
		makeChoice(); // calling again to repeat the operation
}

//********************************************************************************************

// Redirecting to admin monitor or user monitor depend on the early chosen mode
void backToMain(void){ //function definition
	system("cls"); //use to clear screen
	if(mode == admin){ //check if the mode is admin
		adminMode(); // calling adminMode() function "redirecting to it"
	}else if (mode == user){ //check if the mode is user
		userMode(); // calling userMode() function "redirecting to it"
	}else{
		backToMain(); // calling again to repeat the operation
	}
}

//********************************************************************************************

//Exit screen
void exitScreen(void){ //function definition
	system("cls"); //use to clear screen
	printf("\nTHANK YOU FOR USING!"); //greeting message
}