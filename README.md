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

Application Interface & Outputs
1. Main Menu
Plaintext
+-----------------------------------+
|         ADDRESS BOOK MENU         |
+-----------------------------------+
| 1. Create Contact                 |
| 2. Search Contact                 |
| 3. Edit Contact                   |
| 4. Delete Contact                 |
| 5. List All Contacts              |
| 6. Save & Exit                    |
+-----------------------------------+

Enter Your Choice : 
2. Create Contact
Creates a new contact record with input prompts and auto-sorting.

Plaintext
Enter Your Choice : 1

Enter the name        : Chetan
Enter the phoneNumber : 9886568521
Enter the Gmail ID    : chetan@gmail.com

Contact Create Successfully
3. List All Contacts
Displays all records formatted in an ASCII tabular structure.

Plaintext
Enter Your Choice : 5

+----+----------------+----------------+--------------------------+
| No | Name           | Phone Number   | Email ID                 |
+----+----------------+----------------+--------------------------+
| 1  | Akshay         | 9876543213     | akshay123@gamil.com      |
| 2  | Chetan         | 9886568521     | chetan@gmail.com         |
| 3  | Kishor         | 9876543212     | kishor123@gmail.com      |
| 4  | Shreepad       | 9876543211     | shreepad123@gmail.com    |
| 5  | Vittal         | 9876543214     | vittal123@gamil.com      |
+----+----------------+----------------+--------------------------+
4. Search Contact
Provides sub-menu choices to search by specific fields.

Plaintext
+-----------------------------------+
|        SEARCH CONTACT MENU        |
+-----------------------------------+
| 1. Search By Name                 |
| 2. Search By Phone Number         |
| 3. Search By Email ID             |
| 4. Exit Search                    |
+-----------------------------------+

Enter Your Choice : 1

Enter the searching name : Chetan

--------------------Contact Found--------------------

NAME                PHONE NUMBER         EMAIL
Chetan              9886568521           chetan@gmail.com
5. Edit Contact
Modifies specific fields of an existing contact.

Plaintext
+-----------------------------------+
|         EDIT CONTACT MENU         |
+-----------------------------------+
| 1. Edit By Name                   |
| 2. Edit By Phone Number           |
| 3. Edit By Email ID               |
| 4. Exit                           |
+-----------------------------------+

Enter Your Choice : 1

Enter existing name: Chetan
Enter new name     : ChetanKumar

Name updated successfully
6. Delete Contact
Deletes contacts by selected criteria and confirms removal.

Plaintext
+-----------------------------------+
|        DELETE CONTACT MENU        |
+-----------------------------------+
| 1. Delete By Name                 |
| 2. Delete By Phone Number         |
| 3. Delete By Email ID             |
| 4. Exit                           |
+-----------------------------------+

Enter Your Choice : 1

Enter name to delete: ChetanKumar

Contact deleted successfully
Exiting the delete menu:

Plaintext
Enter Your Choice : 4
Exiting Delete Menu
7. Save & Exit
Saves all data to file and terminates program execution.

Plaintext
Enter Your Choice : 6

Saving and Exiting...
How to Compile and Run
Compilation
Bash
gcc *.c -o a.out
Execution
Linux / WSL
Bash
./a.out
Windows (CMD / PowerShell)
Bash
a.exe
Author
Shreepad Gundupkar

C Programming | Embedded Systems | Software Development
