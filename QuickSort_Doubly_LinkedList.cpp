// QUICKSORT DOUBLY LINKEDLIST...
// It takes O(n^2) time in worst case and O(nLogn) in average and best cases. The worst case occurs when the linked list is already sorted.
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *createnode(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	
	return temp;
}

void push(struct node **head_ref, int data)
{
	struct node *temp = createnode(data);
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

void printlist(struct node* head)
{
	while(head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}

struct node* lastnode(struct node *head)
{
	while(head->next != NULL)
	{
		head = head->next;
	}
	
	return head;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

struct node *partition(struct node *first, struct node *last)
{
	int pivot = last->data;
	struct node *i = first->prev;
	struct node *j;
	
	for(j=first; j!=last; j=j->next)
	{
		if(j->data <= pivot)
		{
			i = (i == NULL)? first : i->next;  // THIS CONDITION IS IMPORTANT...DON'T JUST DO :- i= i->next;
			swap(&(i->data), &(j->data));
		}
	}
	
	i = (i == NULL)? first : i->next;  // THIS CONDITION IS IMPORTANT...DON'T JUST DO :- i= i->next;
	swap(&(i->data), &(last->data));
	
	return i;
}

void _quicksort(struct node *first, struct node *last)
{
	if(last != NULL && first != last && first != last->next)
	{
		struct node *p = partition(first, last);
		
		_quicksort(first, p->prev);
		_quicksort(p->next, last);
	}
}

void quicksort(struct node *head) // WE'RE NOT PASSING REFERENCE TO HEAD BUT THE HEAD ITSELF AS UNLIKE IN MERGE SORT, WE ARE'NT CHANGING POINTERS...WE'RE JUST SWAPPING VALUES....
{
	struct node *last = lastnode(head);
	
	_quicksort(head, last);
}

int main()
{
	struct node *a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);
    
    printlist(a);
    printf("\n\n");
    quicksort(a);
    
    printlist(a);
	return 0;
}
