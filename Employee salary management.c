#include<stdio.h>

struct structure{
    int ID;
    float salary;

    
};
int main(){
    struct structure emp[3];
    emp[1].ID=23 ;
    emp[1].salary=5000 ;
    emp[2].ID=22 ;
    
    emp[2].salary=2000;
    emp[3].salary=4000;
    emp[3].ID=24;
    
    
    printf("the ID is %d and the salary is %.1f\n",emp[1].ID,emp[1].salary);  
    printf("the ID is %d and the salary is %.1f\n",emp[2].ID,emp[2].salary);    
    printf("the ID is %d and the salary is %.1f\n",emp[3].ID,emp[3].salary);    
    
    return 0;
}
