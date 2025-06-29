
#include <stdio.h>    //standrd i/p & o/p library
#include "contact.h"  //header file of structure and functions
#include "populate.h" //header file of dummy data

int main()
{

        AddressBook info;  // declare info variable of structure AddressBook
        initialize(&info); // initialize the AddressBook structure

        int option = 0; // declare option variable

        while (1) // infinite loop to display menu options
        {
                printf("Select the below options\n 1. Create contact\n 2. Search contact\n 3. Edit contact\n 4. Delete contact\n 5. List contact\n 6. Save & Exit\n");
                printf("Enter option : "); // prompt user to enter an option
                scanf("%d", &option);
                while (getchar() != '\n')
                        ;       // clear the input buffer
                switch (option) // switch cases for different options
                {
                case 1:
                        printf("\t\t\t\tCreate contact\n");
                        createContact(&info); // call function to create a contact by sending the address of info
                        printf("\n");
                        break;
                case 2:
                        printf("\t\tSearch contact\n");
                        searchContact(&info); // call function to search a contact by sending the address of info
                        printf("\n");
                        option = 0;
                        break;
                case 3:
                        printf("\t\tEdit contact\n");
                        editContact(&info); // call function to edit a contact by sending the address of info
                        printf("\n");
                        break;
                case 4:
                        printf("\t\tDelete contact\n");
                        deleteContact(&info); // call function to delete a contact by sending the address of info
                        printf("\n");
                        break;
                case 5:
                        printf("\t\tList contact\n");
                        listContacts(&info); // call function to list all contacts by sending the address of info
                        printf("\n");
                        break;
                case 6:
                        printf("\t\t\t\tSave & Exit\n");
                        saveContactsToFile(&info); // call function to save contacts to file
                        printf("\n");
                        printf("Exiting the program...\n");
                        return 0; // exit the program
                default:
                        printf("Invalid option\n"); // handle invalid option
                        break;
                }
        }
}
