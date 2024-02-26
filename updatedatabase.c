#include "hash.h"

int valid_file(char *str);
int Update_database(Flist *head,m_node *database[])
{
    int count =0;
    for(int i=0;i<26;i++)
    {
	if(database[i] == 0)
	    count ++;
    }
    if(count != 26)
    {
	printf("INFO : Database is Not Empty\n");
	return FAILURE;
    }
    char str[20];
    char word[45];
    char *tok;
    printf("Enter the saved filename : ");
    scanf("%s",str);
    if(open_file(str) == SUCCESS)
    {
	printf("INFO : File exits\n");
	if(valid_file(str) == SUCCESS)
	{
	    FILE *fptr = fopen(str,"r");
	    printf("INFO : Enter file is valid file\n");
	    while(fscanf(fptr,"%s",word) > 0)
	    {
		int i=0;
		while(word[i] != '\0')
		{
		    word[i] = word[i+1];
		    i++;
		}
		word[i] = '\0';
		tok = strtok(word,"#;");
		if(database[atoi(tok)] == 0)
		{
		    m_node *mainnode = malloc(sizeof(m_node));
		    if(mainnode == NULL)
			return FAILURE;
		    database[atoi(tok)] = mainnode;
		    tok  = strtok(NULL,"#;");
		    strcpy((mainnode->word),tok);
		    tok = strtok(NULL,"#;");
		    int filecount = atoi(tok);
		    mainnode->filecount = filecount;
		    mainnode->mlink = NULL;
		    s_node *subnode = malloc(sizeof(s_node));
		    if(subnode == NULL)
			return FAILURE;
		    mainnode->slink = subnode;
		    tok = strtok(NULL,"#;");
		    strcpy((mainnode->slink->filename),tok);
		    tok = strtok(NULL,"#;");
		    int wordcount = atoi(tok);
		    mainnode->slink->wordcount = wordcount;
		    tok = strtok(NULL,"#;");
		    subnode->sublink = NULL;
		    s_node *temp = mainnode->slink;
		    for(int i=1;i<(mainnode->filecount);i++)
		    {
			s_node *subnode = malloc(sizeof(s_node));
			if(subnode == NULL)
			    return FAILURE;
			strcpy((subnode->filename),tok);
			tok = strtok(NULL,"#;");
			wordcount = atoi(tok);
			subnode->wordcount = wordcount;
			subnode->sublink = NULL;
			temp->sublink = subnode;
			temp = subnode;
		    }
		}
		else
		{
		    m_node *temp = database[atoi(tok)];
		    while(temp->mlink != NULL)
		    {
			temp = temp->mlink;
		    }
		    m_node *mainnode = malloc(sizeof(m_node));
		    if(mainnode ==  NULL)
			return FAILURE;
		    temp->mlink = mainnode;
		    tok = strtok(NULL,"#;");
		    strcpy((mainnode->word),tok);
		    tok = strtok(NULL,"#;");
		    int filecount = atoi(tok);
		    mainnode->filecount = filecount;
		    mainnode->mlink = NULL;
		    s_node *subnode = malloc(sizeof(s_node));
		    if(subnode == NULL)
			return FAILURE;
		    mainnode->slink = subnode;
		    tok = strtok(NULL,"#;");
		    strcpy((mainnode->slink->filename),tok);
		    tok = strtok(NULL,"#;");
		    int wordcount = atoi(tok);
		    mainnode->slink->wordcount = wordcount;
		    subnode->sublink = NULL;
		    tok = strtok(NULL,"#;");
		    s_node *temp1 = mainnode->slink;
		    for(int i=1;i<(mainnode->filecount);i++)
		    {
			s_node *subnode = malloc(sizeof(s_node));
			if(subnode == NULL)
			    return FAILURE;
			strcpy((subnode->filename),tok);
			tok = strtok(NULL,"#;");
			wordcount = atoi(tok);
			subnode->wordcount = wordcount;
			subnode->sublink = NULL;
			temp1->sublink = subnode;
			temp1 = subnode;
		    }
		}

	    }
	}
	else
	{
	    printf("ERROR : Enter file is not valid file\n");
	}
    }
    return SUCCESS;
}
int valid_file(char *str)
{
    char ch,ch1;
    FILE *fptr = fopen(str,"r");
    ch = fgetc(fptr);
    fseek(fptr,0,SEEK_END);
    int l = ftell(fptr);
    fseek(fptr,(l-2),SEEK_SET);
    ch1 = fgetc(fptr);
    rewind(fptr);
    if(ch1 == ch)
    {
	fclose(fptr);
	return SUCCESS;
    }
    else
    {
	fclose(fptr);
	return FAILURE;
    }
}
