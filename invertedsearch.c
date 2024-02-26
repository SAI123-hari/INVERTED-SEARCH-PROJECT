/*
Name:sai hari hara chandra talagadadeevi
Date:
Description:
Sample I/P:
Sample O/P:
*/
#include "hash.h"
int main(int argc,char *argv[])
{
    Flist *head = NULL;
    if(argc > 1)
    {
	int i=1;
	while(i < argc)
	{
	    if(duplicate(argv[i],&head) == SUCCESS)
	    {
		if(open_file(argv[i]) == SUCCESS)
		{
		    if(file_not_empty(argv[i]) == SUCCESS)
		    {
			if(insert_at_last(&head,argv[i]) == SUCCESS)
			{
			    printf("INFO : Validation is Done\n");
			}
		    }
		    else
		    {
			printf("%s ,INFO : File is empty\n",argv[i]);
		    }
		}
	    }
	    else
	    {
		printf("%s INFO : Duplicate file\n",argv[i]);
	    }
	    i++;
	}
	printf("INFO : Validation is Done\n");
    }
    else
    {
	printf("INFO : Given sufficient file names\n");
    }
    if(main_code(head) == SUCCESS)
    {
	//printf("INFO : Done\n");
    }
    //else
    //{
///	printf("INFO : Error in maincode");
    //}
    return 0;
}
int duplicate(char *str,Flist **head)
{
    if(*head == NULL)
	return SUCCESS;
    Flist *temp = *head;
    while(temp != NULL)
    {
	if(!(strcmp(str,temp->filename)))
	    return FAILURE;
	temp = temp -> link;
    }
    return SUCCESS;
}
int open_file(char *str)
{
    FILE *fptr = fopen(str,"r");
    if(fptr == NULL)
    {
	perror("fopen");
	fprintf(stderr,"ERROR : Unable to open %s\n",str);
	return FAILURE;
    }
    return SUCCESS;
}
int file_not_empty(char *str)
{
    FILE *fptr = fopen(str,"r");
    fseek(fptr,0,SEEK_END);
    int size = ftell(fptr);
    if(size == 0)
	return FAILURE;
    return SUCCESS;
}
int insert_at_last(Flist **head, char *str)
{
    Flist *new = malloc(sizeof(Flist));
    if(new == NULL)
	return FAILURE;
    strcpy(new->filename,str);
    new->link = NULL;
    if(*head == NULL)
    {
	*head = new;
	return SUCCESS;
    }
    Flist *temp = *head;
    while(temp -> link != NULL)
    {
	temp = temp->link;
    }
    temp->link = new;
    return SUCCESS;
}


