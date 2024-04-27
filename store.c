#include"main.h"
int store(hash_t *arr)
{
    char new_file[10];
    printf("Enter the file name: ");
    getchar();
    scanf("%[^\n]",new_file);
    if(strstr(new_file,".txt"))
    {
        FILE *ptr = fopen(new_file,"w");
        for(int i=0;i<28;i++)
        {
            if(arr[i].link != NULL)
            {
                mnode *temp_m = arr[i].link;
                while(temp_m)
                {
                    fprintf(ptr,"#%d;%s;%d;",i,temp_m->word,temp_m->file_count);
                    snode *temp_s = temp_m->slink;
                    while(temp_s)
                    {
                        fprintf(ptr,"%s;%d;",temp_s->file_name,temp_s->word_count);
                        temp_s = temp_s->slink;
                    }
                    fprintf(ptr,"#\n");
                    temp_m = temp_m->mlink;
                }
            }
        }
        return 1;
    }
    else
        return 0;

}
