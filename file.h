#ifndef FILE_H
#define FILE_H

#include "contact.h"

// function prototype for saving and loading contacts

void saveContactsToFile(AddressBook *addressBook);
void loadContactsFromFile(AddressBook *addressBook);

#endif
