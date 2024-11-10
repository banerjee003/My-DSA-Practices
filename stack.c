#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int stack_arr[MAX];
int top=-1;

int isFull(){
    if(top==MAX-1) return 1;
    else return 0;
}

int isEmpty(){
    if (top==-1) return 1;
    else return 0;
}

void push(int data){
    if (top==MAX-1){
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack_arr[top]=data;
}

int pop(){
    if(top==-1){
        printf("Stack Overflow\n");
        exit(1);
    }
    int value=stack_arr[top];
    top--;
    return value;
}

void show(){
    for(int i=0;i<=top;i++){
        printf("%d ",stack_arr[i]);
    }
    printf("\n");
}

int main(){

for(int i=0;i<MAX;i++){
    int a;
    printf("Enter the element no %d ",i+1);
    scanf("%d",&a);
    push(a);
}

show();

pop();

show();

return 0;
}

