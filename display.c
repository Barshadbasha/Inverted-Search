#include"main.h"
void display(hash_t *arr)
{
    printf("Index\tWord\tFilecount\tFilename\tWordcount\n");
    for(int i=0;i<28;i++)
    {
        if(arr[i].link!= NULL)
        {
            mnode *temp_m = arr[i].link;
            while(temp_m)
            {
                printf("[%d]\t%s\t%d\t",i,temp_m->word,temp_m->file_count);
                snode *temp_s = temp_m->slink;
                while(temp_s)
                {
                    printf("\t%s\t\t%d\t",temp_s->file_name,temp_s->word_count);
                    temp_s = temp_s->slink;
                }
                printf("\n");
                temp_m = temp_m->mlink;
            }
        }
    }
}
