#include"main.h"

int main(int argc,char *argv[])
{
    list *head1 = NULL;
    list *head2 = NULL;
    int f=0;
    int c;
    char opt;
    if(validation(argc,argv,&head1))
        printf("validation succesfull\n");
    else
    {
        printf("INFO: Validation failed \n");
        return 0;
    }
    hash_t arr[28];
    for(int i=0;i<=27;i++)
    {
        arr[i].index = i;
        arr[i].link = NULL;
    }
    do
    {
        printf("Enter your choice:\n1. Creation\n2.Dispay\n3.Search\n4.Store\n5.Update\n");
        scanf("%d",&c);

    switch(c)
    {
        case 1:
            {
                if(creation(&head1,arr,head2,&f))
                {
                        printf("creation succesfull\n");
                }
                else
                {
                        printf("INFO: Creation failed\n");
                        return 0;
                }
                break;
            }
        case 2:
            {
                display(arr);
                break;
            }
        case 3:
             {
                if(search(arr)==0)
                        printf("INFO:Word not found\n");
                break;
             }
        case 4:
             {
                if( store(arr))
                    printf("Stored succesfully\n");
                else
                    printf("INFO: The file extension not in .txt \n");
                 break;
             }
        case 5:
             {
                 if(update(arr,&head2,&f))
                     printf("UPDATE COMPLETED\n");
                 break;
             }
    }
    printf("Do you want to continue: y/n ");
    getchar();
    scanf("%c",&opt);
    }while(opt == 'y');
}

