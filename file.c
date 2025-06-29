#include <stdio.h> // standard ip/op library
#include "file.h"  //header file for save & load functions
#include <stdlib.h> // standard library for qsort


void saveContactsToFile(AddressBook *addressBook) // void function to save contacts to a file
{

    FILE *fp1; // decalare file pointer

    if ((fp1 = fopen("contacts.txt", "w")) == NULL) // open file in write mode
    {
        printf("ERROR : File not found");
        return;
    }

    fprintf(fp1, "%d\n", addressBook->contactCount); // write the number of contacts to the file

    // Sort contacts by name before saving
    qsort(addressBook->contacts, addressBook->contactCount, sizeof(Contact), compare_contacts_by_name);

    for (int i = 0; i < addressBook->contactCount; i++) // add contacts from addressBook to file in format "name,phone,email"
    {
        fprintf(fp1, "%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }

    fclose(fp1); // close the file
    printf("---------------------------------------------------------------------------------------\n");
    printf("Contacts saved successfully to contacts.txt\n");
    printf("Total contacts : %d\n", addressBook->contactCount);
    printf("---------------------------------------------------------------------------------------\n");
}

void loadContactsFromFile(AddressBook *addressBook) // void function to load contacts from a file
{
    FILE *fp; // declare file pointer

    if ((fp = fopen("contacts.txt", "r")) == NULL) // open file in read mode
    {
        printf("ERROR : File not found");
        return;
    }

    fscanf(fp, "%d\n", &addressBook->contactCount); // read the number of contacts from the file

    for (int i = 0; i < addressBook->contactCount; i++) // read each contact from the file
    {

        fscanf(fp, "%[^,],%[^,],%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        fseek(fp, 0, SEEK_CUR);
    }

    fclose(fp); // close the file
    printf("---------------------------------------------------------------------------------------\n");
    printf("Contacts loaded successfully from contacts.txt\n");
    printf("Total contacts : %d\n", addressBook->contactCount);
    printf("---------------------------------------------------------------------------------------\n");
}
