#include<stdio.h>
int main(){
    int pin =2415;
    int userpin,attempt=3,wd,rb,amount=10000;
    while(attempt>0){
        printf("Enter the pin:");
        scanf("%d",&userpin);
        if(userpin==pin){
            printf("pin is correct");
             printf("Enter the wd amount\n:");
        scanf("%d",&wd);
        if(wd<=amount){
            printf("Transaction successful\n");
            rb=amount-wd;
            printf("The remaining balance=%d",rb);
        }
        else{
            printf("Transaction failed ");
        }
        }
        else{
            printf("incorrect pin");
            attempt--;
        }
    }
}
