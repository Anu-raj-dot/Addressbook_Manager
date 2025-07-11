#include "contact.h" // header file for contact structure and functions
// Dummy contact data
static Contact dummyContacts[] = {
    {"John Doe", "1234567890", "john@example.com"},
    {"Alice Smith", "0987654321", "alice@example.com"},
    {"Bob Johnson", "1112223333", "bob@company.com"},
    {"Carol White", "4445556666", "carol@company.com"},
    {"David Brown", "7778889999", "david@example.com"},
    {"Eve Davis", "6665554444", "eve@example.com"},
    {"Frank Miller", "3334445555", "frank@example.com"},
    {"Grace Wilson", "2223334444", "grace@example.com"},
    {"Hannah Clark", "5556667777", "hannah@example.com"},
    {"Ian Lewis", "8889990000", "ian@example.com"}}; // Dummy contacts array

void populateAddressBook(AddressBook *addressBook) // function to add  dummy contacts to address book
{
    int size = sizeof(dummyContacts) / sizeof(dummyContacts[0]); // find size of dummyContacts array
    // printf("%d\n",size);

    addressBook->contactCount = size; // add size to contactCount of addressBook

    for (int i = 0; i < size; i++) // add each contact from dummyContacts to addressBook
    {
        addressBook->contacts[i] = dummyContacts[i];
    }
}