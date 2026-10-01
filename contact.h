#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);

int is_valid_name(char name[], AddressBook *addressBook);
int is_valid_phone(char phone[], AddressBook *addressBook);
int is_valid_email(char email_id[], AddressBook *addressBook);

void searchContact(AddressBook *addressBook);

void search_by_name(AddressBook *addressBook);
void search_by_phone(AddressBook *addressBook);
void search_by_email(AddressBook *addressBook);

void editContact(AddressBook *addressBook);

void is_edit_name(AddressBook *addressBook);
void is_edit_phone_num(AddressBook *addressBook);
void is_edit_email(AddressBook *addressBook);

void deleteContact(AddressBook *addressBook);

void delete_by_name(AddressBook *addressBook);
void delete_by_phone(AddressBook *addressBook);
void delete_by_email(AddressBook *addressBook);

void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);

#endif
