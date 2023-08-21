/*
    Merge 2 ordered Singly Linked Lists

        Write a C program to create two ordered singly linked lists (ascending order) and merge them into an ordered singly linked list.
 
        Implement the following functions: (Any number of helper functions may be used)
            NODE* orderedSLL(NODE *head,int ele);
            void display(NODE *head);
            NODE* merge(NODE *head1,NODE *head2,NODE *head3);
            NODE* freeList(NODE *head);

        Note: If the list is empty, display the message "Empty List" in display function.

        You may use the below client code:
            #include<stdio.h>
            #include<stdlib.h>

            typedef struct node
            {
                int info;
                struct node *next;
            }NODE;

            NODE* orderedSLL(NODE *head,int ele);
            void display(NODE *head);
            NODE* merge(NODE *head1,NODE *head2,NODE *head3);
            NODE* freeList(NODE *head);

            int main()
            {
                NODE *head1=NULL,*head2=NULL,*head3=NULL;
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
                head3=merge(head1,head2,head3);
                display(head3);
                printf("\n");
     
                head1=freeList(head1);
                head2=freeList(head2);
                head3=freeList(head3);
            }
 
        Input format:
            First line: n – number of elements in list1 (n>=0)
            Second line: n integers separated by space
            Third line: n – number of elements in list2 (n>=0)
            Fourth line: n integers separated by space
 
        Output Format
            First line: Numbers in ordered sll1 separated by space
            Second line: Numbers in ordered sll2 separated by space
            Third line: Numbers in ordered sll3 separated by space

        Note: If the list is empty, display the message "Empty List"
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
}NODE;

NODE* orderedSLL(NODE *head, int ele);
void display(NODE *head);
NODE* merge(NODE *head1, NODE *head2, NODE *head3);
NODE* freeList(NODE *head);

int main()
{
    NODE *head1=NULL,*head2=NULL,*head3=NULL;
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
    head3=merge(head1,head2,head3);
    display(head3);
    printf("\n");

    head1=freeList(head1);
    head2=freeList(head2);
    head3=freeList(head3);
}

NODE* orderedSLL(NODE *head, int ele)
{
    NODE *temp, *p, *q;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->info=ele;
    temp->next=NULL;
    if(head==NULL || ele<head->info)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        p=head;
        while(p!=NULL && p->info<=ele)
        {
            q=p;
            p=p->next;
        }
        temp->next=p;
        q->next=temp;
    }
    return head;
}

void display(NODE *head)
{
    NODE *p;
    if(head==NULL)
    {
        printf("Empty List");
    }
    else
    {
        p=head;
        while(p!=NULL)
        {
            printf("%d ",p->info);
            p=p->next;
        }
    }
}

NODE* merge(NODE *head1, NODE *head2, NODE *head3)
{
    NODE *p=head1, *q=head2, *r;
    while(p!=NULL && q!=NULL)
    {
        if(p->info<=q->info)
        {
            head3=orderedSLL(head3,p->info);
            p=p->next;
        }
        else
        {
            head3=orderedSLL(head3,q->info);
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        head3=orderedSLL(head3,p->info);
        p=p->next;
    }
    while(q!=NULL)
    {
        head3=orderedSLL(head3,q->info);
        q=q->next;
    }
    return head3;
}

NODE* freeList(NODE *head)
{
    NODE *temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    return NULL;
}
