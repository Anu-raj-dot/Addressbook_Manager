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

# Address Book Manager
![Menu Screenshot](https://github.com/user-attachments/assets/b98a8e12-9c69-4663-bc61-041ea5092d05)
![Create contact](https://github.com/user-attachments/assets/7e6f013f-9269-42bc-a80f-e96863049ed9)
![Search contact](https://github.com/user-attachments/assets/74887da3-ca6d-4870-a9b8-a783e79c45b2)
![Edit contact](https://github.com/user-attachments/assets/e82b6ea7-4c05-4c5e-8fcd-3a612177f36a)
![Delete contact](https://github.com/user-attachments/assets/8d2230af-c234-426f-89a6-3eea141babeb)
![List contact](https://github.com/user-attachments/assets/8cca363d-b037-49e5-a50d-d23335fbe286)
![Save & exit](https://github.com/user-attachments/assets/cdb079d0-9463-434e-9288-3c019272b549)


## License

This project is open-source and available under the MIT License.
