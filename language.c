#include<stdio.h>
int main(){
    int choice;
    printf("select the language\n");
    printf(" 1.TAMIL\n 2.ENGLISH\n 3.HINDI\n");
    printf("Choose your language:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("You selected tamil");
        break;
        case 2:
        printf("You selected english");
        break;
        case 3:
        printf("You selected hindi");
        break;
        default:
        printf("Invalid Input");
    }
    return 0;
}
