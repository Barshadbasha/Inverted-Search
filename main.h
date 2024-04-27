#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct list
{
    char file_name[20];
    struct list *link;
}list;

typedef struct hashtable
{
    int index;
    struct mainnode *link;
}hash_t;

typedef struct mainnode
{
    int file_count;
    char word[20];
    struct mainnode *mlink;
    struct subnode *slink;
}mnode;

typedef struct subnode
{
    int word_count;
    char file_name[20];
    struct subnode *slink;
}snode;

int validation(int argc,char**,list **);
int insert(char* ,list **);
int creation(list **,hash_t *,list *,int *);
void display(hash_t *);
int search(hash_t *);
int store(hash_t *);
int update(hash_t *,list **,int *);
