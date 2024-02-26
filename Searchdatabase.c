#include "hash.h"
int Search_database(m_node *database[])
{
    char word[50];
    scanf("%s",word);
    int index = tolower(word[0]) % 97;
    m_node *temp = database[index];
    if(database[index] == 0)
	return FAILURE;
    while(temp != NULL)
    {
	if(!(strcmp((temp->word),word)))
	    break;
	temp = temp->mlink;
    }
    printf("Word %s is present in %d files\n",word,temp->filecount);
    s_node *temp1 = temp->slink;
    while(temp1 != NULL)
    {
	printf("%s -> %d\n",temp1->filename,temp1->wordcount);
	temp1 = temp1->sublink;
    }
    if(temp == NULL)
	printf("ERROR : Word not present in database");
    return 0;
}

