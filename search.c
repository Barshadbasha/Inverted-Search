#include"main.h"
int search(hash_t *arr)
{
    char word[20];
    printf("Enter the word: ");
    getchar();
    scanf("%19[^\n]",word);
    int i=  toupper(word[0])%65;
    if(i>=48 && i<=57)
        i = 27;
    else if(i>= 33 && i<=64)
        i = 26;
    if(!arr[i].link)
        return 0;
    mnode *temp_m = arr[i].link;
    while(temp_m)
    {
        if(!strcmp(word,temp_m->word))
        {
            printf("The word %s is in %d files\n",word,temp_m->file_count);
            snode *temp_s = temp_m->slink;
            while(temp_s)
            {
                printf("In %s for %d times\n",temp_s->file_name,temp_s->word_count);
                temp_s = temp_s->slink;
            }
            return 1;
        }
        else
            temp_m = temp_m->mlink;
    }
    return 0;
}
