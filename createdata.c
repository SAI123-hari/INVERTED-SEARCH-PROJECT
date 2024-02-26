#include "hash.h"

int Create_database(Flist *head,m_node *database[])
{
    Flist *temp = head;
    if(head == NULL)
    {
	printf("INFO : List is Empty\n");
	return FAILURE;
    }
    else
    {
	while(head)
	{
	    printf("%s -> ",head -> filename);
	    head = head -> link;
	}
	printf("NULL\n");
    }
    while(temp != NULL)
    {
	FILE *fp = fopen(temp ->filename,"r");
	char word[50];
	while(fscanf(fp,"%s",word) > 0)
	{
	    //printf("%s\n",word);
	    int index = toupper(word[0]) % 65;
	    //printf("%d\n",index);
	    if(database[index] == NULL)
	    {
		m_node *mainnode = malloc(sizeof(m_node));
		if(mainnode == NULL)
		    return FAILURE;
		s_node *subnode = malloc(sizeof(s_node));
		if(subnode == NULL)
		    return FAILURE;
		strcpy(mainnode->word,word);
		mainnode->filecount = 1;
		mainnode->mlink=NULL;
		mainnode->slink = subnode;
		strcpy((subnode->filename),(temp->filename));
		subnode->wordcount = 1;
		subnode->sublink= NULL;
		database[index] = mainnode;
	    }
	    else
	    {
		m_node *prev = NULL;
		m_node *temp1 = database[index];
		while(temp1 != NULL)
		{
		    if(!(strcmp((temp1->word), word)))
		    {
			break;
		    }
		    prev=temp1;
		    temp1=temp1->mlink;
		}
		if(temp1 == NULL)
		{
		    m_node *mainnode = malloc(sizeof(m_node));
		    if(mainnode == NULL)
			return FAILURE;

		    s_node *subnode = malloc(sizeof(s_node));
		    if(subnode == NULL)
			return FAILURE;

		    strcpy(mainnode->word, word);
		    mainnode->filecount = 1;
		    mainnode->mlink = NULL;
		    mainnode->slink = subnode;

		    strcpy((subnode->filename), (temp->filename));
		    subnode->wordcount = 1;
		    subnode->sublink =NULL;

		    prev->mlink = mainnode;
		}
		if(temp1 != NULL)
		{
		    if(!(strcmp((temp1->slink->filename), (temp->filename))))
		    {
			temp1->slink->wordcount = ((temp1->slink->wordcount)+1);
		    }
		    else
		    {
			int flag =0;
			s_node *prev1=NULL;
			s_node *temp2 = temp1->slink;	
			while(temp2 != NULL)
			{
			    if(!(strcmp((temp2->filename), (temp->filename))))
			    {
				temp2->wordcount= ((temp2->wordcount) +1);
			        flag = 1;
				break;
			    }
			    prev1 = temp2;
			    temp2 = temp2->sublink;
			}
			if(flag == 0)
			{
			s_node *subnode = malloc(sizeof(s_node));
			if(subnode == NULL)
			    return FAILURE;
			subnode->wordcount = 1;
			subnode->sublink =NULL;
		        strcpy((subnode->filename),(temp->filename));
			prev1->sublink = subnode;
			temp1->filecount = ((temp1->filecount) + 1);
			}
		    }
		}
	    }
	}
	temp = temp->link;
    }
}

