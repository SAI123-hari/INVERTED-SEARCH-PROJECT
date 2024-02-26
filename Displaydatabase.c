#include "hash.h"
int Display_database(Flist *head,m_node *database[])
{
    printf("[Index]	[word]	[Filecount]	[Filename]	[wordcount]\n");
    for(int i=0;i<26;i++)
    {
	if(database[i] != 0)
	{
	    m_node *temp = database[i];
	    while(temp != NULL)
	    {
		printf("[%d]	",i);
		printf("%s	    ",temp->word);
		printf("%d	        ",temp->filecount);
		printf("%s		",temp->slink->filename);
		printf("%d		",temp->slink->wordcount);
		s_node *temp1 = temp ->slink->sublink;
	       	while(temp1 != NULL)
	       	{
		    printf("%s ",temp1->filename);
		    printf("%d ",temp1->wordcount);
		    temp1 =temp1->sublink;
		}
		temp = temp->mlink;
		printf("\n");
	    }
	}
    }
    return 0;
}

