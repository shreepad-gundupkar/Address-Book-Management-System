#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <ctype.h>



void listContacts(AddressBook *addressBook)
{
    if(addressBook->contactCount == 0)
    {
        printf("No contacts found.\n");
        return;
    }

    printf("\n+------------------------------------------------------------------------+\n");
    printf("| %-5s %-20s %-15s %-27s |\n",
       "No", "Name", "Phone Number", "Email ID");
    printf("+------------------------------------------------------------------------+\n");

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        printf("| %-5d %-20s %-15s %-27s |\n",
           i + 1,
           addressBook->contacts[i].name,
           addressBook->contacts[i].phone,
           addressBook->contacts[i].email);
    }

    printf("+------------------------------------------------------------------------+\n");
}

void initialize(AddressBook *addressBook) 
{
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
     
    loadContactsFromFile(addressBook);
    // Load contacts from file during initialization (After files)
    
}


void saveAndExit(AddressBook *addressBook) 
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{

    char name[50];
    char phone[11];
    char email_id[50];

                      /* Name Function */

    while(1)
    {
        printf("\nEnter the name        : ");
        //getchar();
        scanf(" %[^\n]", name);
        if(is_valid_name(name,addressBook))
        {
            strcpy(addressBook->contacts[addressBook->contactCount].name,name);
            break;
        }
    }

                     /* Phone Number Function */

    while(1)
    {
        printf("Enter the phoneNumber : ");
        //getchar();
        scanf(" %[^\n]", phone);
        if(is_valid_phone(phone,addressBook))
        {
            strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
            break;
        }
    }
                     /* Gmail Function */

    while(1)
    {
        printf("Enter the Gmail ID    : ");
        //getchar();
        scanf(" %[^\n]", email_id);
        if(is_valid_email(email_id,addressBook))
        {
            strcpy(addressBook->contacts[addressBook->contactCount].email,email_id);
            break;
        }

    }

    addressBook->contactCount++;   

    for(int i = 0; i < addressBook->contactCount - 1; i++)
    {
        for(int j = i + 1; j < addressBook->contactCount; j++)
        {
            if(strcmp(addressBook->contacts[i].name,addressBook->contacts[j].name) > 0)
            {
                Contact temp;
                temp = addressBook->contacts[i];
                addressBook->contacts[i] = addressBook->contacts[j];
                addressBook->contacts[j] = temp;
            }
        }
    }

    printf("\nContact Create Successfully\n");
}	


                                                                /* Validation Name */


int is_valid_name(char name[], AddressBook *addressBook)
{
    int len = strlen(name);

    if(len < 3)
    {
        printf("\nError: Name must contain at least 3 characters\n");
        return 0;
    }
   
    if(name[0] == '.')
    {
        printf("\nError: Name should not start with dot.\n");
        return 0;
    }

    if(name[len - 1] == '.')
    {
        printf("\nError: Name should not end with dot.\n");
        return 0;
    }

    for(int i=0; i<len; i++)
    {
        if(name[i] >= '0' && name[i] <= '9')
        {
            printf("\nError: Numbers are not allowed in the name.\n");
            return 0;
        }
    }
    
    for(int i=0; i<len; i++)
    {
        if(!(name[i] >= 'A' && name[i] <= 'Z' || name[i] >= 'a' && name[i] <= 'z' || name[i] == ' ' || name[i] =='.'))
        {
            printf("\nError: Name must contain alphabets single space and single dot.\n");
            return 0;
        }  
    }
     
    int count_dot=0;
    int count_space=0;

    for(int i=0; i<len; i++)
    {
        if(name[i] == ' ')
        count_space++;

        if(name[i] == '.')
        count_dot++;
    }

    if(count_space > 1)
    {
        printf("\nError: Name contain only one space.\n");
        return 0;
    }

    if(count_dot > 1)
    {
        printf("\nError: Name contain only one dot.\n");
        return 0;
    }
    return 1;

}


                                                           /* PHONE NUMBER VALIDATION */


int is_valid_phone(char phone[], AddressBook *addressBook)
{
    int len = strlen(phone);
    
    if(len != 10)
    {
        printf("\nError : Phone number must contain exactly 10 digits\n");
        return 0;
    }
   
    for(int i=0; i<len; i++)
    {
        if(!isdigit(phone[i]))
        {
            printf("\nError : Phone number must contain only digits\n");
            return 0;
        }        
    }

    if(!(phone[0] >= '6' && phone[0] <= '9'))
    {
        printf("\nError : First digit must be between 6 and 9\n");
        return 0;
    }

    for(int i = 0; i< addressBook->contactCount; i++)
    {
        if(strcmp(addressBook->contacts[i].phone, phone )== 0)
        {
            printf("\nError: Phone number already exists.\n");
            return 0;
        }

    }
    
    return 1;
}


                                                         /* Gmail validation Function */


int is_valid_email(char email_id[], AddressBook *addressBook)
{
    int at_count  =  0;
    int dot_count =  0;
    int at_pos    = -1;
    int dot_pos   = -1;

    int len = strlen(email_id);

    for(int i=0; i<len; i++)
    {
        if(email_id[i] == '@')
        {
            at_count++;
            at_pos = i;
        }
        else if(email_id[i] == '.')
        {
            dot_count++;
            dot_pos = i;
        }
        else if(!(isalpha(email_id[i]) || isdigit(email_id[i])))
        {
            printf("Error: Invalid symbol.\n");
            return 0;
        }
    }

    if(at_count == 0)
    {
        printf("Error: Missing @ symbol.\n");
        return 0;
    }

    if(at_pos == 0)
    {
        printf("Error: @ cannot be the first character.\n");
        return 0;
    }

    if(at_count > 1)
    {
       printf("Error: Only one @ symbol is allowed.\n");
        return 0;
    }


    if(dot_count == 0)
    {
        printf("Error: Missing . symbol.\n");
        return 0;
    }

    if(dot_pos == len - 1)
    {
        printf("Error: . cannot be the last character.\n");
        return 0;
    }
    if(dot_pos - at_pos <= 1)
    {
        printf("Error: There must be at least one character between @ and .\n");
        return 0;
    }


    if(len < 4 || strcmp(email_id + len - 4, ".com") != 0)
    {
        printf("Error: Email must end with .com or domain\n");
        return 0;
    }

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(addressBook->contacts[i].email, email_id) == 0)
        {
            printf("Email ID already exists\n");
            return 0;
        }
    }
    return 1;


}


                                                      /* Search contact */


void searchContact(AddressBook *addressBook)
{
    int choice;

    do
    {
        printf("\n+--------------------------------------+\n");
        printf("|          SEARCH CONTACT MENU         |\n");
        printf("+--------------------------------------+\n");
        printf("| 1. Search By Name                    |\n");
        printf("| 2. Search By Phone Number            |\n");
        printf("| 3. Search By Email ID                |\n");
        printf("| 4. Exit Search                       |\n");
        printf("+--------------------------------------+\n");
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                search_by_name(addressBook);
                break;

            case 2:
                search_by_phone(addressBook);
                break;

            case 3:
                search_by_email(addressBook);
                break;

            case 4:
                printf("Exiting Search Menu...\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 4);
}
void search_by_name(AddressBook *addressBook)
{
    char name[20];

    printf("\nEnter the searching name : ");
    getchar();
    scanf("%[^\n]", name);

    int flag = 0;

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strstr(addressBook->contacts[i].name, name) != NULL)
        {
            printf("\n--------------------------Contact Found--------------------------\n");
            printf("\n%-25s %-20s %-25s\n","NAME", "PHONE NUMBER", "EMAIL");
            printf("%-25s %-20s %-25s\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("Name not found\n");
    }

}


                                                         /* SRARCH BY PHONE */


void search_by_phone(AddressBook *addressBook)
{
    char phone[11];
    int flag = 0;

    printf("\nEnter the phone number: ");
    scanf("%s", phone);

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(addressBook->contacts[i].phone, phone) == 0)
        {
            printf("\n-----------------Contact Found-------------------\n");
            printf("\n%-25s %-20s %-25s\n","NAME", "PHONE NUMBER", "EMAIL");
            printf("%-25s %-20s %-25s\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);

            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        printf("Phone number not found\n");
    }
}


                                                             /* SEARCH BY GMAIL */


void search_by_email(AddressBook *addressBook)
{
    char email[50];
    int flag = 0;

    printf("\nEnter the email ID: ");
    scanf("%s", email);

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(addressBook->contacts[i].email, email) == 0)
        {
            printf("\n----------------------Contact Found------------------------\n");
            printf("\n%-25s %-20s %-25s\n","NAME", "PHONE NUMBER", "EMAIL");
            printf("%-25s %-20s %-25s\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);

            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        printf("Email ID not found\n");
    }
}


                                                             /* EditContact  */


void editContact(AddressBook *addressBook)
{
	int choice;
    
    do
    {
        printf("\n+--------------------------------------+\n");
        printf("|           EDIT CONTACT MENU          |\n");
        printf("+--------------------------------------+\n");
        printf("| 1. Edit By Name                      |\n");
        printf("| 2. Edit By Phone Number              |\n");
        printf("| 3. Edit By Email ID                  |\n");
        printf("| 4. Exit                              |\n");
        printf("+--------------------------------------+\n");
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                is_edit_name(addressBook);
                break;

            case 2:
                is_edit_phone_num(addressBook);
                break;

            case 3:
                is_edit_email(addressBook);
                break;

            case 4:
                printf("Exiting Edit menu\n");
                break;

            default:
                printf("Invalid option !\n");
                break;           
        }
    } while (choice != 4);
    
}


                                                                     /* Edit By Name */


void is_edit_name(AddressBook *addressBook)
{
    char old_name[50];
    int match_count = 0;
    int index = -1;

    printf("\nEnter existing name: ");
    scanf(" %[^\n]", old_name);

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(old_name, addressBook->contacts[i].name) == 0)
        {
            match_count++;
            index = i;
        }
    }

    if(match_count == 0)
    {
        printf("Contact not found\n");
        return;
    }

    if(match_count > 1)
    {
        printf("\nFound %d contacts with the name %s\n",
               match_count, old_name);

        printf("Multiple contacts found.\n");
        printf("Please edit using Phone Number or Email ID.\n");

        return;
    }

    if(match_count == 1)
    {
        char new_name[50];
        while(1)
        {
            printf("Enter new name     : ");
            scanf(" %[^\n]", new_name);

            if(is_valid_name(new_name, addressBook))
            {
                strcpy(addressBook->contacts[index].name, new_name);

                printf("Name updated successfully\n");
                break;
            }
        }
    }
}
   

                                                          /* Edite By PhoneNumber */                


void is_edit_phone_num(AddressBook *addressBook)
{
 
    char old_phone[11];
    char new_phone[11];

    int index = -1;

    printf("Enter existing phone number: ");
    scanf("%s", old_phone);

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(old_phone, addressBook->contacts[i].phone) == 0)
        {
            index = i;
            break;
        }
    }

    if(index == -1)
    {
        printf("Phone number not found\n");
        return;
    }

    while(1)
    {
        printf("Enter new phone number: ");
        scanf("%s", new_phone);

        if(is_valid_phone(new_phone, addressBook))
        {
            strcpy(addressBook->contacts[index].phone, new_phone);

            printf("Phone number updated successfully\n");
            break;
        }
    }
}

 
                                                     /* Edit By Gmail */


void is_edit_email(AddressBook *addressBook)
{
    char old_email[50];
    char new_email[50];

    int index = -1;

    printf("Enter existing Email ID: ");
    scanf("%s", old_email);

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(old_email, addressBook->contacts[i].email) == 0)
        {
            index = i;
            break;
        }
    }

    if(index == -1)
    {
        printf("Email ID not found\n");
        return;
    }

    while(1)
    {
        printf("Enter new Email ID: ");
        scanf("%s", new_email);

        if(is_valid_email(new_email, addressBook))
        {
            strcpy(addressBook->contacts[index].email, new_email);

            printf("Email ID updated successfully\n");
            break;
        }
    }
}
     
          
                                      /* DELETE CONTACT MENU */


void deleteContact(AddressBook *addressBook)
{

    int choice;

    do
    {
        printf("\n+--------------------------------------+\n");
        printf("|          DELETE CONTACT MENU         |\n");
        printf("+--------------------------------------+\n");
        printf("| 1. Delete By Name                    |\n");
        printf("| 2. Delete By Phone Number            |\n");
        printf("| 3. Delete By Email ID                |\n");
        printf("| 4. Exit                              |\n");
        printf("+--------------------------------------+\n");
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                delete_by_name(addressBook);
                break;

            case 2:
                delete_by_phone(addressBook);
                break;

            case 3:
                delete_by_email(addressBook);
                break;

            case 4:
                printf("Exiting Delete Menu\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 4);
}


                                   /* delete_by_name function */


void delete_by_name(AddressBook *addressBook)
{
    char name[50];
    int match_count = 0;
    int index = -1;

    printf("\nEnter name to delete: ");
    scanf(" %[^\n]", name);

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(name, addressBook->contacts[i].name) == 0)
        {
            match_count++;
            index = i;
        }
    }

    if(match_count == 0)
    {
        printf("Contact not found\n");
        return;
    }

    if(match_count > 1)
    {
        printf("Found %d contacts with same name\n", match_count);
        printf("Please delete using Phone Number or Email ID\n");
        return;
    }

    for(int i = index; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] =
        addressBook->contacts[i + 1];
    }

    addressBook->contactCount--;

    printf("\nContact deleted successfully\n");
}


                                        /* delete_by_phone function */


void delete_by_phone(AddressBook *addressBook)
{
    char phone[11];
    int index = -1;

    printf("\nEnter phone number to delete: ");
    scanf("%s", phone);

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(phone, addressBook->contacts[i].phone) == 0)
        {
            index = i;
            break;
        }
    }

    if(index == -1)
    {
        printf("Phone number not found\n");
        return;
    }

    for(int i = index; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    addressBook->contactCount--;

    printf("\nContact deleted successfully\n");
}


                                /* delete_by_email function */


void delete_by_email(AddressBook *addressBook)
{
    char email[50];
    int index = -1;

    printf("\nEnter Email ID to delete: ");
    scanf("%s", email);

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(email, addressBook->contacts[i].email) == 0)
        {
            index = i;
            break;
        }
    }

    if(index == -1)
    {
        printf("Email ID not found\n");
        return;
    }

    for(int i = index; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    addressBook->contactCount--;

    printf("\nContact deleted successfully\n");
}