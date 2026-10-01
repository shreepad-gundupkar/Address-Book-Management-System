# Address-Book-Management-System
A C-based Address Book Management System to store, search, edit, delete, and manage contact information efficiently using file handling and data structures.
# Address Book Management System

A menu-driven **Address Book Management System developed in C** for creating, searching, editing, deleting, listing, and storing contact information using text file handling.

## Features

- Create new contacts
- List all contacts
- Search contacts by:
  - Name
  - Phone Number
  - Email ID
- Edit contacts by:
  - Name
  - Phone Number
  - Email ID
- Delete contacts by:
  - Name
  - Phone Number
  - Email ID
- Handles multiple contacts with the same name
- Validates names, phone numbers, and email IDs
- Prevents duplicate phone numbers
- Prevents duplicate email IDs
- Automatically sorts contacts alphabetically by name when a new contact is created
- Loads contacts from a file when the program starts
- Saves contacts to a text file when the program exits
- Menu-driven user interface

## Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Data Storage:** Text Files (.txt)

## C Concepts Used

- Structures
- Arrays
- Strings
- Functions
- Pointers
- Searching
- Sorting
- File Handling
- Input Validation
- CRUD Operations
- Modular Programming

## Project Structure

```text
AddressBook/
│
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── contacts.txt
└── README.md
```

## File Description

| File | Description |
|------|-------------|
| `main.c` | Contains the main function and menu of the application |
| `contact.c` | Contains contact creation, search, edit, delete, list, and validation functions |
| `contact.h` | Header file containing declarations related to contact operations |
| `file.c` | Contains functions for loading contacts from and saving contacts to files |
| `file.h` | Header file containing file-handling function declarations |
| `contacts.txt` | Stores contact information in text format |
| `README.md` | Project documentation |

## Application Modules

### 1. Create Contact

The user can create a new contact by entering:

- Name
- Phone Number
- Email ID

Each field is validated before the contact is added.

The application checks for duplicate phone numbers and email IDs.

After creating a contact, the contacts are automatically sorted alphabetically by name.

### 2. List Contacts

Displays all contacts in an organized format.

Example:

```text
+----+----------------+----------------+--------------------------+
| No | Name           | Phone Number   | Email ID                 |
+----+----------------+----------------+--------------------------+
| 1  | Akshay         | 9876543213     | akshay123@gamil.com      |
| 2  | Chetan         | 9886568521     | chetan@gmail.com         |
| 3  | Kishor         | 9876543212     | kishor123@gmail.com      |
| 4  | Shreepad       | 9876543211     | shreepad123@gmail.com    |
| 5  | Vittal         | 9876543214     | vittal123@gamil.com      |
+----+----------------+----------------+--------------------------+
```

### 3. Search Contact

Contacts can be searched using:

- Name
- Phone Number
- Email ID

If multiple contacts have the same name, the matching contacts are displayed and the user can select the required contact.

### 4. Edit Contact

Contacts can be edited using:

- Name
- Phone Number
- Email ID

The corresponding field is updated after validation.

For example:

- Edit by Name → updates the name
- Edit by Phone Number → updates the phone number
- Edit by Email ID → updates the email ID

### 5. Delete Contact

Contacts can be deleted using:

- Name
- Phone Number
- Email ID

When deleting by name, multiple matching contacts are displayed so that the user can select the required contact.

### 6. File Handling

The application uses file handling to maintain contact information.

Contacts are loaded when the application starts and updated contact information is saved when the application exits.

The main text file used by the project is:

```text
contacts.txt
```

Example:

```text
Akshay 9876543213 akshay123@gamil.com      
Chetan 9886568521 chetan@gmail.com         
Kishor 9876543212 kishor123@gmail.com      
Shreepad 9876543211 shreepad123@gmail.com    
Vittal 9876543214 vittal123@gamil.com
```

## Validation

### Name Validation

The name is validated before creating or editing a contact.

### Phone Number Validation

The phone number must:

- Contain exactly 10 digits
- Start with a digit from `6` to `9`
- Be unique in the address book

### Email Validation

The email ID is validated for:

- Presence of `@`
- Presence of `.`
- Only one `@`
- `.` must occur after `@`
- At least one character between `@` and `.`
- No extra characters after `.com`
- Email ID must be unique

## Automatic Sorting

Contacts are automatically sorted alphabetically by **name** whenever a new contact is created.

Example:

```text
Before:

Kishor
Shreepad

New Contact:

Akshay

After:

Akshay
Kishor
Shreepad
```

No separate sorting option is required in the menu.

## Menu

The application provides a menu-driven interface.

```text
========== Address Book ==========

1. Create Contact
2. Search Contact
3. Edit Contact
4. Delete Contact
5. List Contacts
6. Exit

Enter your choice:
```

## How to Compile

Make sure GCC is installed on your system.

Compile the project using:

```bash
gcc *.c -o addressbook
```

## How to Run

### Windows

```bash
addressbook.exe
```

### Linux

```bash
./addressbook
```

## Example Workflow

```text
1. Start the application
        ↓
2. Load existing contacts
        ↓
3. Create / Search / Edit / Delete / List contacts
        ↓
4. New contacts are automatically sorted by name
        ↓
5. Exit the application
        ↓
6. Save updated contacts to contacts.txt
```

## Learning Outcomes

This project helped in practicing:

- C Programming Fundamentals
- Structures
- Functions
- Pointers
- Arrays
- String Handling
- Searching
- Sorting
- File Handling
- Text File Operations
- Input Validation
- CRUD Operations
- Modular Programming
- Problem Solving and Debugging

## Future Improvements

- Case-insensitive searching
- Improved email validation
- Sorting by phone number or email
- Import/export of additional file formats
- Database integration
- Graphical user interface
- Improved user interface and error handling

## Author

**Shreepad Gundupkar**


C Programming | Embedded Systems | Software Development
