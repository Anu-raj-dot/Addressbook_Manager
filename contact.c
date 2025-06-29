#include <stdio.h> //Add necessary header files
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook)
{
  // Sort contacts by name before listing
  qsort(addressBook->contacts, addressBook->contactCount, sizeof(Contact), compare_contacts_by_name);

  // Sort contacts based on the chosen criteria
  printf("---------------------------------------------------------------------------------------\n");
  printf("  Name\t\t   Phone\t\tEmail\n");
  printf("---------------------------------------------------------------------------------------\n");
  for (size_t i = 0; i < addressBook->contactCount; i++) // Loop through each contact in the address book
  {                                                      // It is used to represent the size of objects in bytes and for array indexing/looping.
    if (strlen(addressBook->contacts[i].name) > 6)
    {
      printf("%s\t%s\t%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    else
    {
      printf("%s\t\t%s\t%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
  }
  printf("---------------------------------------------------------------------------------------\n");
}

void initialize(AddressBook *addressBook)
{
  addressBook->contactCount = 0;
  // populateAddressBook(addressBook); // load contact from dummy array
  loadContactsFromFile(addressBook); // Load contacts from file
}

void saveAndExit(AddressBook *addressBook)
{
  saveContactsToFile(addressBook); // Save contacts to file
  exit(EXIT_SUCCESS);              // Exit the program
}

void createContact(AddressBook *addressBook)
{
  /* Define the logic to create a Contacts */
  char str[50], str1[20], str2[50];           // Declare string variables
  int ret, value = addressBook->contactCount; // Get the current contact count to assign a new contact

  printf("--------------------------------------------------------------------------------------\n");
  printf("Name : ");
  scanf("%[^\n]", str);                           // Selective scanf to read string with spaces
  strcpy(addressBook->contacts[value].name, str); // Copy the string to the contact's name field

  do // Loop until a valid phone number is entered
  {
    printf("Phone : ");
    scanf(" %[^\n]", str1);
    ret = validate_phoneno(str1, addressBook); // call function to validate phone number

    if (ret == -2) // If phone number is not valid
    {
      printf("Error : Enter 10 digit number\n");
    }
    else if (ret != -2 && ret != -1) // If phone number is valid but already exists
    {
      printf("Error : Phone number already existed\n");
    }
    else // if phone number is valid and does not exist
    {
      strcpy(addressBook->contacts[value].phone, str1); // Copy the phone number to the contact's phone field
    }
  } while (ret != -1);

  do // Loop until a valid email is entered
  {
    printf("Email : ");
    scanf(" %[^\n]", str2);
    ret = validate_email(str2, addressBook); // call function to validate email
    if (ret == -2)
    {
      printf("Error : Invalid Format\n");
    }
    else if (ret != -2 && ret != -1)
    {
      printf("Error : Email already existed\n");
    }
    else
    {
      strcpy(addressBook->contacts[value].email, str2); // Copy the email to the contact's email field
    }
  } while (ret != -1);

  printf("--------------------------------------------------------------------------------------\n");
  printf("\n");
  printf("\t\t\t\tContact created successfully\n");
  printf("--------------------------------------------------------------------------------------\n");
  printf("Name : %s\nphone : %s\nEmail : %s\n", addressBook->contacts[value].name, addressBook->contacts[value].phone, addressBook->contacts[value].email);
  printf("--------------------------------------------------------------------------------------\n");
  addressBook->contactCount++; // increment the contact count
}

int searchContact(AddressBook *addressBook)
{
  /* Define the logic for search */
  int option = 0, value, ret;
  printf("Search\n 1.Name\n 2.Phone\n 3.Email\n"); // Display search options
  printf("Enter option : ");
  scanf("%d", &option); // Read the user's choice
  while (getchar() != '\n')
    ;
  char str[50]; // declare a string for search

  switch (option) // Check the user's choice
  {
  case 1:
    printf("Name : ");
    scanf(" %[^\n]", str);

    for (int i = 0; i < addressBook->contactCount; i++) // Loop through each contact in the address book
    {
      value = strcasecmp(addressBook->contacts[i].name, str); // Compare the string with each contact's name
      if (!value)
      {
        printf("--------------------------------------------------------------------------------------\n");
        printf("\t\t\t\tContact Found\n");
        printf("--------------------------------------------------------------------------------------\n");
        printf("Name : %s\nphone : %s\nEmail : %s", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        printf("\n");
        return i;
      }
    }
    break;

  case 2:
    do
    {
      printf("Phone : ");
      scanf(" %[^\n]", str);
      ret = validate_phoneno(str, addressBook); // Validate the phone number entered by the user
      if (ret == -2)
      {
        printf("Error : Enter 10 digit number\n");
      }
      if (ret != -2 && ret != -1) // if the phone number is valid and exists in the address book
      {
        printf("\n");
        printf("--------------------------------------------------------------------------------------\n");
        printf("\t\t\t\tContact Found\n");
        printf("--------------------------------------------------------------------------------------\n");
        printf("Name : %s\nphone : %s\nEmail : %s", addressBook->contacts[ret].name, addressBook->contacts[ret].phone, addressBook->contacts[ret].email);
        printf("\n");

        return ret;
      }
    } while (ret != -1); // Loop until a valid phone number is entered
    break;

  case 3:
    do
    {
      printf("Email : ");
      scanf(" %[^\n]", str);
      ret = validate_email(str, addressBook); // validate the email entered by the user

      if (ret == -2)
      {
        printf("Error : Invalid format\n");
      }
      if (ret != -2 && ret != -1) // if the email is valid and exists in the address book
      {
        printf("\n");
        printf("--------------------------------------------------------------------------------------\n");
        printf("\t\t\t\tContact Found\n");
        printf("--------------------------------------------------------------------------------------\n");
        printf("Name : %s\nphone : %s\nEmail : %s", addressBook->contacts[ret].name, addressBook->contacts[ret].phone, addressBook->contacts[ret].email);
        printf("\n");

        return ret;
      }
    } while (ret != -1);
    break;

  default:
    printf("Invalid option\n");
    break;
  }
  if (option > 0 && option < 4)
  {
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t\t\t\tContact not Found\n"); // if no contact is found
    printf("---------------------------------------------------------------------------------------\n");
  }
  return -1;
}

void editContact(AddressBook *addressBook)
{
  /* Define the logic for Editcontact */
  int ret, value = searchContact(addressBook); // Search for the contact to edit
  char str[50];

  if (value == -1) // if the contact is not found
    return;

  printf("\n");
  printf("--------------------------------------------------------------------------------------\n");
  printf("\t\t\t\tEdit Details\n");
  printf("--------------------------------------------------------------------------------------\n");

  int option = 0;
  printf("Select the below options\n 1. Name\n 2. Phone\n 3. Email\n"); // Display options for editing
  printf("Enter option : ");
  scanf("%d", &option);
  while (getchar() != '\n')
    ;

  switch (option) // Check the user's choice for editing
  {
  case 1:
    printf("Enter Name : ");
    scanf(" %[^\n]", addressBook->contacts[value].name); // Read the new name for the contact
    break;

  case 2:
    do
    {
      printf("Enter Phone : ");
      scanf(" %[^\n]", str);
      ret = validate_phoneno(str, addressBook); // Validate the phone number entered by the user
      if (ret == -2)
      {
        printf("Error : Enter 10 digit number\n");
      }
      else if (ret != -2 && ret != -1)
      {
        printf("Error : Phone number already existed\n");
      }
      else
      {
        strcpy(addressBook->contacts[value].phone, str); // add the new phone number to the contact
      }
    } while (ret != -1); // Loop until a valid phone number is entered
    break;

  case 3:
    do
    {
      printf("Enter Email : ");
      scanf(" %[^\n]", str);
      ret = validate_email(str, addressBook); // Validate the email entered by the user
      if (ret == -2)
      {
        printf("Error : Invalid format\n");
      }
      else if (ret != -2 && ret != -1)
      {
        printf("Error : Email already existed\n");
      }
      else
      {
        strcpy(addressBook->contacts[value].email, str); // add the new email to the contact
      }
    } while (ret != -1);
    break;
  default:
    printf("Invalid option\n");
    break;
  }

  if (option > 0 && option < 4)
  {
    printf("\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("\t\t\tContact updated sucessfully\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("Name : %s\nphone : %s\nEmail : %s\n", addressBook->contacts[value].name, addressBook->contacts[value].phone, addressBook->contacts[value].email);
    printf("--------------------------------------------------------------------------------------\n");
  }
}

void deleteContact(AddressBook *addressBook)
{
  /* Define the logic for deletecontact */
  int value = searchContact(addressBook); // search for the contact to delete

  if (value == -1) // if the contact is not found
    return;

  printf("\n");
  printf("\t\tDelete Details\n");
  printf("--------------------------------------------------------------------------------------\n");
  printf("Name : %s\nphone : %s\nEmail : %s\n", addressBook->contacts[value].name, addressBook->contacts[value].phone, addressBook->contacts[value].email);
  printf("--------------------------------------------------------------------------------------\n");

  printf("Delete contact (y/n) : "); // Ask the user for confirmation to delete the contact
  char ch;
  while (getchar() != '\n')
    ;
  scanf("%c", &ch);

  if (ch == 'y' || ch == 'Y') // If the user confirms deletion
  {
    for (int i = value; i < addressBook->contactCount - 1; i++)
    {
      addressBook->contacts[i] = addressBook->contacts[i + 1]; // Shift the contacts to the left to remove the deleted contact
    }
    printf("\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("\t\tContact deleted successfully\n");
    printf("--------------------------------------------------------------------------------------\n");
    addressBook->contactCount--; // Decrement the contact count
  }

  else if (ch == 'n' || ch == 'N')
  {
    printf("\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("\t\tContact not deleted\n");
    printf("--------------------------------------------------------------------------------------\n");
    return;
  }

  else
  {
    printf("Invalid option\n");
    return;
  }
}

int validate_phoneno(char *phone, AddressBook *addressBook) // validate phone number function
{
  int i, count = 0, val = 0;
  if (strlen(phone) == 10) // check string length is 10
  {
    for (i = 0; i < 10; i++)
    {
      if (phone[i] >= '0' && phone[i] <= '9') // check if each character is a digit
        count++;
    }
    if (count == 10) // if all characters are digits
    {
      for (i = 0; i < addressBook->contactCount; i++) // Loop through each contact in the address book
      {
        int val = strcmp(addressBook->contacts[i].phone, phone); // Compare the phone number with each contact's phone number
        if (!val)                                                // if a duplicate is found
        {
          return i; // return the index of the duplicate contact
        }
      }
      return -1;
    }
    return -2;
  }
  return -2;
}

int validate_email(char *email, AddressBook *addressBook) // validate email function
{
  int i = 0, count = 0;

  while (email[i] != '\0') // Loop through each character in the email string
  {
    if (email[i] == ' ')
      return -2; // Invalid email if it contains spaces

    if ((email[i] >= 'a' && email[i] <= 'z') || (email[i] >= '0' && email[i] <= '9') || email[i] == '@' || email[i] == '.') // check if a  character is a valid email character
    {
      if (email[i] == '@' || email[i] == '.') // check if a character is @ or .
      {
        count++; // Increment count if @ or . is found
      }
    }
    else
      return -2;
    i++;
  }

  if (count == 2) // make sure there is exactly one @ and one .
  {
    char *ptr = strchr(email, '@');  // Find the position of @ in the email string
    char *ptr1 = strchr(email, '.'); // Find the position of . in the email string

    if (ptr == NULL || ptr1 == NULL) // not found, then return
    {
      return -2;
    }

    if ((*(ptr + 1) != '.') && (*(ptr1 + 1)) != '\0') // check character after @ is not '.' or null
    {

      for (i = 0; i < addressBook->contactCount; i++) // Loop through each contact in the address book
      {
        int val = strcmp(addressBook->contacts[i].email, email); // Compare the email string with each contact's email
        if (!val)
        {
          return i; // If a duplicate email is found, return the index of the contact
        }
      }
      return -1;
    }
    return -2;
  }
  return -2;
}

int compare_contacts_by_name(const void *a, const void *b)
{
  const Contact *c1 = (const Contact *)a;
  const Contact *c2 = (const Contact *)b;
  return strcasecmp(c1->name, c2->name);
}
