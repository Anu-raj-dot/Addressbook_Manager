#ifndef CONTACT_H
#define CONTACT_H
#include <stdio.h>

#define MAX_CONTACTS 100 // Maximum number of contacts allowed

typedef struct
{                  // typedef struct for Contact
    char name[50]; // structure elements name,phone,email of type char
    char phone[20];
    char email[50];
} Contact; // gave a nick name Contact to the structure

typedef struct
{                                   // typedef struct for AddressBook
    Contact contacts[MAX_CONTACTS]; // array contacts[maxcontacts] created using Contact structure
    int contactCount;               // contactcount variable to track number of contacts
} AddressBook;

// Function prototypes for AddressBook operations

void createContact(AddressBook *addressBook);
int searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *addressBook);
int validate_phoneno(char *phone, AddressBook *addressbook);
int validate_email(char *email, AddressBook *addressBook);
int compare_contacts_by_name(const void *a, const void *b);

#endif
