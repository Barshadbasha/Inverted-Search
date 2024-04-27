#include"main.h"
int creation(list **head1,hash_t *arr,list *head2,int *f)
{
    if(head2 != NULL && *head1 != NULL)
    {
        list *temp1 = *head1;
        list *prev1 = NULL;
        list *temp2 = head2;
        while(temp2)
        {
            while(temp1)
            {
                if(strcmp(temp1->file_name,temp2->file_name)== 0 && temp1 == *head1)
                {
                    *head1 = (*head1)->link;
                    free(temp1);
                    temp1 = *head1;
                }
                else if(strcmp(temp1->file_name,temp2->file_name)==0)
                {
                    prev1->link  = temp1->link;
                    free(temp1);
                    temp1 = prev1->link;
                }
                else
                {
                    prev1 = temp1;
                    temp1 = temp1->link;
                }
            }
            temp2 = temp2->link;
            temp1 = *head1;
        }
    }
    char word[20];

     list *temp = *head1;
    while(temp)
    {
        FILE *ptr = fopen(temp->file_name,"r");
        while(fscanf(ptr,"%s",word) != EOF)
        {
                int index = toupper(word[0])%65;
                if(index>=48 && index<=57)
                    index = 27;
                else if(index>=33 && index<=64)
                    index = 26;
                if(arr[index].link == NULL)
                {
                    snode *new_s = malloc(sizeof(snode));
                    new_s->slink = NULL;
                    new_s->word_count = 1;
                    strcpy(new_s->file_name,temp->file_name);

                        mnode *new_m = malloc(sizeof(mnode));
                        arr[index].link  = new_m;
                        new_m->file_count = 1;
                        strcpy(new_m->word,word);
                        new_m->mlink = NULL;
                        new_m->slink = new_s;
                }
                else
                {
                    mnode *temp_m = arr[index].link;
                    while(temp_m)
                    {
                            int otp_word = strcmp(word,temp_m->word);

                            if(!otp_word)
                            {
                                snode *temp_s = temp_m->slink;
                                while(temp_s)
                                {
                                    int otp_file_name = strcmp(temp->file_name,temp_s->file_name);
                                    if(otp_file_name !=0 && temp_s->slink == NULL)
                                    {
                                        snode *new_s = malloc(sizeof(snode));
                                        temp_s->slink = new_s;
                                        new_s->slink = NULL;
                                        new_s->word_count = 1;
                                        strcpy(new_s->file_name,temp->file_name);
                                        (temp_m->file_count)++;
                                        break;
                                    }
                                    if(!otp_file_name)
                                    {
                                        (temp_s->word_count)++;
                                        break;
                                    }
                                    else if(otp_file_name)
                                        temp_s = temp_s->slink;
                                }
                                break;
                            }
                            else if(otp_word != 0 && temp_m->mlink == NULL)
                            {
                                snode *new_s = malloc(sizeof(snode));
                                new_s->slink = NULL;
                                new_s->word_count = 1;
                                strcpy(new_s->file_name,temp->file_name);

                                mnode *new_m = malloc(sizeof(mnode));
                                temp_m->mlink  = new_m;
                                new_m->file_count = 1;
                                strcpy(new_m->word,word);
                                new_m->mlink = NULL;
                                new_m->slink = new_s;
                                break;
                            }
                            else if(otp_word)
                                temp_m = temp_m->mlink;
                    }
                }
        }
        printf("Database created successfully for %s\n",temp->file_name);
        temp = temp->link;
    }
    *f = 1;
    return 1;
}
