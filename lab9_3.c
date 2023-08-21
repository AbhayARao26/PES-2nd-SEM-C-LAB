/*
    Concatentate 2 ordered Singly Linked Lists

        Write a C program to create two ordered singly linked lists (ascending order) and concatenate list 2 to list 1.
 
        Implement the following functions:
            NODE* orderedSLL(NODE *head,int ele);
            void display(NODE *head);
            NODE* concatentate(NODE *head1,NODE *head2);
            NODE* freeList(NODE *head);

        Note: If the list is empty, display the message "Empty List" in display function.

        You may use the below client code:
            //Concatenate 2 ordered SLL
            #include<stdio.h>
            #include<stdlib.h>

            typedef struct node
            {
                int info;
                struct node *next;
            }NODE;

            NODE* orderedSLL(NODE *head,int ele);
            void display(NODE *head);
            NODE* cocatenate(NODE *head1,NODE *head2);
            NODE* freeList(NODE *head);

            int main()
            {
                NODE *head1=NULL,*head2=NULL;
                int n1,n2,ele;
     
                scanf("%d",&n1);
                for(int i=0;i<n1;i++)
                {
                    scanf("%d",&ele);
                    head1=orderedSLL(head1,ele);
                }
     
                scanf("%d",&n2);
                for(int i=0;i<n2;i++)
                {
                    scanf("%d",&ele);
                    head2=orderedSLL(head2,ele);
                }
     
                display(head1);
                printf("\n");
                display(head2);
                printf("\n");
                head1=cocatenate(head1,head2);
                display(head1);
                printf("\n");
     
                head1=freeList(head1);
            }
 
        Input Format
            First line: n – number of elements in list1 (n>=0)
            Second line: n integers separated by space
            Third line: n – number of elements in list2 (n>=0)
            Fourth line: n integers separated by space

        Output Format
            First line: Numbers in ordered sll1 separated by space
            Second line: Numbers in ordered sll2 separated by space
            Third line: Numbers in concatenated sll separated by space

        Note: If the list is empty, display the message "Empty List"
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} NODE;

NODE* orderedSLL(NODE *head, int ele)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->info = ele;
    temp->next = NULL;
    NODE *prev = NULL, *cur = head;
    while (cur != NULL && cur->info < ele)
    {
        prev = cur;
        cur = cur->next;
    }
    if (prev == NULL)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        prev->next = temp;
        temp->next = cur;
    }
    return head;
}

NODE* concatenate(NODE *head1, NODE *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    NODE *cur = head1;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = head2;
    return head1;
}

void display(NODE *head)
{
    if (head == NULL)
    {
        printf("Empty List");
        return;
    }
    NODE *cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->info);
        cur = cur->next;
    }
}

NODE* freeList(NODE *head)
{
    NODE *cur = head;
    while (cur != NULL)
    {
        NODE *temp = cur;
        cur = cur->next;
        free(temp);
    }
    return NULL;
}

int main()
{
    NODE *head1 = NULL, *head2 = NULL;
    int n1, n2, ele;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &ele);
        head1 = orderedSLL(head1, ele);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &ele);
        head2 = orderedSLL(head2, ele);
    }
    display(head1);
    printf("\n");
    display(head2);
    printf("\n");
    head1 = concatenate(head1, head2);
    display(head1);
    printf("\n");
    head1 = freeList(head1);
}

