#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*link;
} *top=NULL;

void push(int a){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL){
        printf("Stack Overflow\n");
        exit(1);
    }
    new->data=a;
    new->link=top;
    top=new;
}

void pop(){
    struct node*temp=top;
    if(temp==NULL) {
        printf("Stack underflow\n");
    }
    printf("The popped out element is %d\n",top->data);
    top=temp->link;
    free(temp);
}

void display(struct node*ptr){
    printf("Elements in the stack are ");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}

void peek(){
    printf("%d\n",top->data);
}

int main(){

while(1){
    int choice;
    printf("Choices:\n1 to push\n2 to pop\n3 to peek\n4 to display\n5 to quit\nEnter your choice: ");
    scanf("%d",&choice);
    int n,a;

    switch (choice)
    {
    case 1:
        printf("Enter the number of elements to enter ");
        scanf("%d",&n);
        for(int i=0;i<n;i++){
        printf("Enter the element no %d ",i+1);
        scanf("%d",&a);
        push(a);
    }
        display(top);
        break;
    case 2:
        pop();
        display(top);
        break;
    
    case 3:
        peek();
        break;
    
    case 4:
        display(top);
        break;
    
    case 5:
        printf("Thank You!!");
        exit(0);
    
    default:
        printf("Wrong Input\n");
        break;
    }
}
return 0;
}

