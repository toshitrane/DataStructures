 #include <stdio.h>
 #include <conio.h>
 #include <stdlib.h>

 struct node
 {
     int value;
     struct node* next;
     struct node* previous;
 };


 struct node* CreateNewNode(int data)
 {
     struct node* new_node = (struct node*)malloc(sizeof(struct node));
     new_node -> next = NULL;
     new_node -> previous = NULL;
     new_node -> value = data;
     return new_node;
 }

/*
 void reverse_doubly(struct node** head)
 {
     struct node* temp = NULL;
     struct node* current = NULL;
     if (*head == NULL)
     {
         printf("\nEmpty === Reverse");
         return;
     }
     while ( (*head) != NULL)
     {
         temp = (*head) -> previous;
         (*head) -> previous = (*head) -> next;
         (*head) -> next = temp;
         current  = (*head);
         (*head) = (*head) -> previous;
     }
     *head = current;
 }
*/

void reverse_doubly(struct node** head)
 {
     struct node* temp = NULL;
     struct node* current = *head;
     if (*head == NULL)
     {
         printf("\nEmpty === Reverse");
         return;
     }
     while ( current!= NULL)
     {
         current -> previous = current ->next;
         current -> next = temp;
         temp=current;
         current= current -> previous;
     }
     *head = temp;
 }

void doubly_create(int data, struct node** head)
 {
     struct node* temp;
     if ( (*head) == NULL)
     {
         temp = CreateNewNode(data);
         temp -> next = NULL;
         temp -> previous = NULL;
         (*head) = temp;
     }
     else
     {
         temp = CreateNewNode(data);
         temp -> previous = NULL;
         temp -> next = (*head);
         (*head) -> previous = temp;
         (*head) = temp;
    }

 }

 void print_doubly(struct node* head)
 {
     struct node* current = head;
     if (current == NULL)
     {
         printf("Empty!!");
     }
     printf("\nThe double linked list is: ");
     while (current != NULL)
     {
         printf("%d\t",current->value);
         current = current -> next;
     }

 }


 int main()
 {
     struct node* head = NULL;
     doubly_create(2,&head);
     doubly_create(3,&head);
     doubly_create(4,&head);
     doubly_create(5,&head);
     doubly_create(6,&head);
     print_doubly(head);
     reverse_doubly(&head);
     printf("\nReverse is : \n");
     print_doubly(head);
 }
