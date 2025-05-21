#include<stdio.h>
#include<stdlib.h>
#define MAX 100
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
        printf("Stack Underflow\n");
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

int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;  
    }
    return stack_arr[top];
}

int main(){
int a;
printf("Enter the no of elements to add ");
scanf("%d",&a);
for(int i=0;i<a;i++){
    int a;
    printf("Enter the element no %d ",i+1);
    scanf("%d",&a);
    push(a);
}

int choice=0,data;
while(1){
    printf("\n1. Push\n2. Pop\n3. Print the top element\n4. print all the elements of the stack\n5. Quit\nPlease enter your choice ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter the element to be pushed ");
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            printf("The popped out element is %d",pop());
            break;
        case 3:
            printf("Top element is: %d\n", peek());
            break;
        case 4:
            show();
            break;
        case 5:
            exit(1);
            break;
        default:
        printf("Wrong Choice\n");
        
    }
    
}

return 0;
}

