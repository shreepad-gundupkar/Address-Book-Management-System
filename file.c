#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook)
{ 
    //printf("Contact Count = %d\n", addressBook->contactCount);

    FILE *fptr = fopen("contacts.txt", "w");

    if(fptr == NULL)
    {
        printf("Unable to open file\n");
        return;
    }

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fptr, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }

    fclose(fptr);
}
  


void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fptr = fopen("contacts.txt", "r");

    if(fptr == NULL)
    {
        return;
    }

    addressBook->contactCount = 0;

    while(fscanf(fptr,
                 "%49[^,],%10[^,],%49[^\n]\n",
                 addressBook->contacts[addressBook->contactCount].name,
                 addressBook->contacts[addressBook->contactCount].phone,
                 addressBook->contacts[addressBook->contactCount].email) == 3)
    {
        addressBook->contactCount++;
    }
 
    fclose(fptr);
}
    

