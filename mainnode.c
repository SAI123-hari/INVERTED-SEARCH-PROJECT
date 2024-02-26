/*
Name:SAI HARI HARA CHANDRA TALAGADADEEVI
Date:
Description:
Sample I/P:
Sample O/P:
*/
#include "hash.h"
int main_code(Flist *head)
{
    m_node *database[26];
    for(int i=0;i<26;i++)
	database[i] = NULL;
    while(1)
    {
	printf("Select your choice among following options:\n");
	printf("1. Create Database\n2. Display Database\n3. Search Database\n4. Save Database\n5. Update Database\n6. Exit\n");
	int option;
	printf("Enter the choice:");
        scanf("%d",&option);
	switch(option)
	{
	    case 1:
		if(Create_database(head,database) == SUCCESS)
		{
		    printf("INFO : Create database is Done\n");
		}
		else
	       	{
		    printf("INFO : Creation is failure\n");
		}
		break;
	    case 2:
		if(Display_database(head,database) == SUCCESS)
		{
		    printf("INFO : Display database is Done\n");
		}
		else
		{
		    printf("INFO : Display database is faliure\n");
		}
		break;
	    case 3:
		if(Search_database(database) == SUCCESS)
		{
		    printf("INFO : Search database is Done\n");
		}
		else
		{
		    printf("INFO : Search database is failure\n");
		}
		break;
	    case 4:
		if(Save_database(head,database) == SUCCESS)
		{
		    printf("INFO : Save database is Done\n");
		}
		else
		{
		    printf("INFO : Save database is failure\n");
		}
		break;
	    case 5:
		if(Update_database(head,database) == SUCCESS)
		{
		    printf("INFO : update database is Done\n");
		}
		else
		{
		    printf("INFO : update database is failure\n");
		}
		break;
	    case 6:
		return SUCCESS;
		break;
	    default:
		break;
	}
    }
    return 0;
}

