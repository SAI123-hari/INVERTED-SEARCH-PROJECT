#ifndef hash_H
#define hash_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define SUCCESS 0
#define FAILURE 1
 
typedef struct subnode
{
    char filename[30];
    int wordcount;
    struct subnode *sublink;
}s_node;

typedef struct mainnode
{
    char word[30];
    int filecount;
    struct mainnode *mlink;
    struct subnode *slink;
}m_node;

typedef struct node
{
    char filename[30];
    struct node *link;
}Flist;

int duplicate(char *str,Flist **head);
int open_file(char *str);
int file_not_empty(char *str);
int insert_at_last(Flist **head,char *str);
int main_code(Flist *head);
int Create_database(Flist *head,m_node *database[]);
int Display_database(Flist *head,m_node *database[]);
int Search_database(m_node *database[]);
int Save_database(Flist *head,m_node *database[]);
int Update_database(Flist *head,m_node *database[]);
#endif

