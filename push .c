#include<stdio.h>
#define size 5
int array[size];
int top=-1;
void push(int value){
    if(top==size-1){
        printf("no space left\n");
    }
    else{
        top++;
        array[top]=value;
        printf("%d value pushed to array\n",value);
    }
}
void pop(){
    if(top==-1){
        printf("No value at stack");
    }
    else{
        printf("The peak value is :%d\n",array[top]);
    }
}
void peak(){
    if (top==-1){
        printf("No value is stack");
        
    }
    else{
        printf("The peak Value is :%d\n",array[top]);
    }
}
void isEmpty(){
    if (top==-1){
        printf("No value is stack\n");
        
    }
    else{
        printf("stack has items\n");
    }
}
void Size(){
    printf("My stack is %d\n",top+1);
}
int main(){
    push(10);
    push(20);
    isEmpty();
    Size();
    return 0;
}