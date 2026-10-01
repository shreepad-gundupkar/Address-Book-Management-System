# Address-Book-Management-System

A C-based Address Book Management System to store, search, edit, delete, and manage contact information efficiently using file handling and modular design.

## Features

- Create new contacts with real-time validation
- List all contacts in a formatted ascii table
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
- Handles sub-menus for operations (Search, Edit, Delete)
- Validates names, phone numbers, and email IDs
- Prevents duplicate phone numbers and email IDs
- Automatically sorts contacts alphabetically by name upon creation
- Loads contacts from a file when the program starts
- Saves contacts to a text file when exiting

## Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Data Storage:** Text Files (`.txt`)

## Project Structure

```text
AddressBook/
│
├── main.c          # Application entry point & main menu loop
├── contact.c       # Core CRUD functions & validation logic
├── contact.h       # Structure & function prototypes for contact operations
├── file.c          # Load & save functions for text file handling
├── file.h          # Function declarations for file handling
├── contacts.txt    # Text file used for data persistence
└── README.md       # Project documentation
