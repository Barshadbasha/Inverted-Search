int validation(int argc, char *argv[],list **head1)
{
    if(argc>1)
    {
        for(int i=1;i<argc;i++)
        {
            if(strstr(argv[i],".txt"))
            {
                FILE *ptr = fopen(argv[i],"r");
                if(ptr)
                {
                    fseek(ptr,0,SEEK_END);
                   if(ftell(ptr)>0)
                   {
                        if(insert(argv[i],head1))
                            printf("File %d inserted succesfully\n",i);
                        else
                            printf("File %d is duplicate\n",i);
                   }
                   else
                       printf("INFO: File %d is empty\n",i);
                }
                else
                    printf("INFO: File %d does not exist\n",i);
            }
            else
                printf("INFO: Extention of file %d is not .txt\n",i);
        }
    }
    else
    {
        printf("INFO: pass CLA \n");
        return 0;
    }
    if((*head1)==NULL)
        printf("List empty\n");
    else
    {
        list *temp = *head1;
        while(temp)
        {
            printf("%s -> ",temp->file_name);
            temp = temp->link;
        }
        printf("NULL\n");
    }
    return 1;
}

int insert(char *file_name,list **head1)
{
    list *new = malloc(sizeof(list));
    strcpy(new->file_name,file_name);
    new->link = NULL;

    if(*head1 == NULL)
    {
        *head1 = new;
        return 1;
    }

    list *temp = *head1;
    while(temp)
    {
        if(strcmp(temp->file_name,file_name) == 0)
            return 0;
        if(temp->link == NULL)
        {
            temp->link = new;
            return 1;
        }
        temp = temp->link;
    }

}
