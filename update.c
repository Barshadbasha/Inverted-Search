#include"main.h"
int update(hash_t *arr,list **head2,int *f)
{
    if((*f) == 1)
    {
        printf("INFO: Database is already created\n");
        return 0;
    }
    list *temp_list = *head2;
    char file[10];
    char str[200];
    printf("Enter the file name: ");
    getchar();
    scanf("%[^\n]",file);
    FILE *fptr = fopen(file,"r");
    while(fscanf(fptr,"%s",str) != EOF)
    {
        if(str[0] == '#' && str[strlen(str)-1] == '#')
        {
            char *ptr = strtok(&str[1],";");
            int index = atoi(ptr);
            mnode *new_m = malloc(sizeof(mnode));
                if(new_m == NULL)
                    return 0;
            mnode *temp = arr[index].link;

            if(arr[index].link == NULL)
            {
                arr[index].link = new_m;
            }
            else
            {
                while(temp->mlink != NULL)
                        temp = temp->mlink;
                temp->mlink =  new_m;
            }
            strcpy(new_m->word,strtok(NULL,";"));
            new_m->file_count = atoi((strtok(NULL,";")));
            new_m->mlink = NULL;
            new_m->slink = NULL;
            snode *prev = NULL;
            for(int i=1;i<=new_m->file_count;i++)
            {
                    snode *new_s = malloc(sizeof(snode));
                    strcpy(new_s->file_name,strtok(NULL,";"));
            if(*head2 == NULL)
            {
                list *new_list = malloc(sizeof(list));
                if(new_list == NULL)
                    return 0;
                else
                {
                        *head2 = new_list;
                        strcpy(new_list->file_name,new_s->file_name);
                        temp_list = new_list;
                        new_list->link = NULL;
                }
            }
            else if(strcmp(temp_list->file_name,new_s->file_name))
            {
                list *new_list = malloc(sizeof(list));
                temp_list->link = new_list;
                temp_list = new_list;
                strcpy(new_list->file_name,new_s->file_name);
                new_list->link = NULL;
            }

                    new_s->word_count = atoi((strtok(NULL,";")));
                    new_s->slink = NULL;
                    if(new_m->slink == NULL)
                        new_m->slink = new_s;
                    else
                        prev->slink = new_s;
                    prev = new_s;
            }
        }
        else
        {
            printf("INFO: File lines doesnt bigin or end with #\n");
            return 0;
        }
    }
    return 1;
}
