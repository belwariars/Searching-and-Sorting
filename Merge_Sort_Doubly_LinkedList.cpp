// MERGE SORT ON DOUBLY LINKED LIST...

#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* next;
	struct node *prev;	
};

struct node *createnode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	
	return temp;
}

void insert(struct node **head_ref, int data)
{
	struct node* temp = createnode(data);
	
	if(*head_ref == NULL)
	{
		*head_ref = temp;
	}
	else
	{
		temp->next = *head_ref;
		(*head_ref)->prev = temp;
		*head_ref = temp;
	}
}

void partition(struct node *head, struct node** firstref, struct node** secondref)
{
	struct node *slow;
	struct node *fast;
	
	if(head == NULL || head->next == NULL)
	{
		fast = head;
		slow = NULL;
	}
	else
	{
		slow = head;
		fast = head->next;
		while(fast != NULL)
		{
			fast = fast->next;
			if(fast != NULL)
			{
				fast = fast->next;
				slow = slow->next;
			}
		}
		
		*firstref = head;
		*secondref = slow->next;
		slow->next = NULL;
	}
}

struct node *merge(struct node *a, struct node *b)
{
	struct node *finalhead = NULL;
	if(a == NULL)
	{
		return b;
	}
	else if(b == NULL)
	{
		return a;
	}
	
	if(a->data <= b->data)
	{
		finalhead = a;
		finalhead->next = merge(a->next, b);
		finalhead->next->prev = finalhead;
		finalhead->prev = NULL;
	}
	else
	{
		finalhead = b;
		finalhead->next = merge(a, b->next);
		finalhead->next->prev = finalhead;
		finalhead->prev = NULL;
	}
	
	return finalhead;
}

void mergesort(struct node **head_ref)
{
	if(*head_ref == NULL || (*head_ref)->next == NULL)
		return;
	
	struct node *a;
	struct node *b;
	
	partition(*head_ref, &a, &b);

	mergesort(&a);
	mergesort(&b);
	
	*head_ref = merge(a, b);
}

void printlist(struct node *head)
{
	while(head->next != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("%d", head->data);
	
	printf("\t\t\t");
	while(head != NULL)
	{
		printf("%d ", head->data);
		head = head->prev;
	}
}

int main()
{
	struct node *head = NULL;
    insert(&head,5);
    insert(&head,20);
    insert(&head,4);
    insert(&head,3);
    insert(&head,30);
    insert(&head,10);
    
    printlist(head);
    printf("\n\n");
    mergesort(&head);
    printlist(head);
    
	return 0;
}
