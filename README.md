# Address Book Manager (C Project)

## Overview

This project is a **console-based Address Book Manager** written in C. It allows users to create, search, edit, delete, list, and save contacts with details such as name, phone number, and email. The application uses file handling for persistent storage and supports sorting contacts in a case-insensitive manner.

---

## Features

- **Add Contact:** Create new contacts with name, phone, and email.
- **Search Contact:** Search by name, phone, or email (case-insensitive).
- **Edit Contact:** Update name, phone, or email of existing contacts.
- **Delete Contact:** Remove contacts from the address book.
- **List Contacts:** Display all contacts, sorted alphabetically (case-insensitive).
- **Save & Load:** Persistent storage using a text file (`contacts.txt`).
- **Input Validation:** Checks for valid phone numbers and email formats, and prevents duplicates.
- **Dummy Data:** Optionally populate with sample contacts for testing.

---

## File Structure

- `main.c` - Main menu and program flow.
- `contact.h` - Structure definitions and function prototypes.
- `contact.c` - Core logic for contact operations.
- `file.h`, `file.c` - File save/load functions.
- `populate.h`, `populate.c` - Dummy data population.
- `contacts.txt` - Persistent storage for contacts.


## Relevance

- **Practical C Programming:** Demonstrates modular programming, use of structures, and file I/O.
- **Data Management:** Teaches how to manage and validate user data in a real-world scenario.
- **Sorting & Searching:** Implements case-insensitive sorting and searching, relevant for user-friendly applications.
- **Resume-Ready:** A great project to showcase C skills, problem-solving, and understanding of data structures and file handling.

---

## Sample Menu

```
Select the below options
 1. Create contact
 2. Search contact
 3. Edit contact
 4. Delete contact
 5. List contact
 6. Save & Exit
Enter option :
```

---

## License

This project is open-source and available under the MIT License.
