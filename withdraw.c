#include <stdio.h>
int main() {
    int Bankamount=1000;
    int num1;
    printf("Enter the num1:");
    scanf("%d",&num1);
    if(num1<=1000){
        printf("Withdraw successful\nThe new balance=%d",Bankamount - num1);
    }
    else{
        printf("Withdraw unsuccessful");
    }
    return 0;
}
