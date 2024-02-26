
#include "hash.h"
int Save_database(Flist *head,m_node *database[])
{
    int count = 0;
    for(int i=0;i<26;i++)
    {
	if(database[i] == 0)
	    count++;
    }
    if(count == 26)
    {
	printf("INFO : Database is empty");
    }
    else
    {
	char str[20];
	printf("Enter the filename with extention .txt : ");
	scanf("%s",str);
	FILE *fptr = fopen(str,"w");
	if(fptr == NULL)
	{
	    printf("INFO : File does not exist!");
	    return FAILURE;
	}
	char name[20] = "#";
	for(int i=0;i<26;i++)
	{
	    if(database[i] != NULL)
	    {
		m_node *temp = database[i];
		while(temp != NULL)
		{
		    fprintf(fptr,"%s;",name);
                    fprintf(fptr,"%d;",i);
                    fprintf(fptr,"%s;",temp->word);
                    fprintf(fptr,"%d;",temp->filecount);
                    fprintf(fptr,"%s;",(temp->slink->filename));
                    fprintf(fptr,"%d",temp->slink->wordcount);
                    s_node *temp1 = temp->slink->sublink;
		    while(temp1 != NULL)
		    {
			fprintf(fptr,";%s",temp1->filename);
                        fprintf(fptr,";%d",temp1->wordcount);
			temp1 = temp1->sublink;
		    }
		    if(temp1 == NULL)
		    {
			fprintf(fptr,"%s\n",name);
		    }
		    temp = temp->mlink;
		}
	    }
       	}
	fclose(fptr);
    }
}

