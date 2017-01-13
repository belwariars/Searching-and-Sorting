// MERGE SORT ON LINKEDLIST...
// TIME COMPLEXITY: (N LOGN)
//Why is merge sort preferred over quick sort for sorting linked lists?
  
//As Singly Linked list can be accessed in only one direction and cannot be accessed randomly, Quick sort will not be well suitable here.
//Quick sort requires access to elements in both direction for swapping and doing such operation in Linked list is not as easy as working with Arrays. 
//Starting from the end and moving backward is usually expensive operation in Singly linked list.
//So Quick sort is well suited for arrays and not linked list.

#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

struct node* createnode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	
	return temp;
}

void push(struct node **head_ref, int data)
{
	struct node *temp = createnode(data);
	temp->next = *head_ref;
	(*head_ref) = temp;
}

void partition(struct node *head, struct node** frontref, struct node** backref)
{
	struct node *slow;
	struct node *fast;
	
	if(head == NULL || head->next == NULL)
	{
		*frontref = head;
		*backref = NULL;
	}
	else
	{
		slow = head;
		fast = head->next;
		
		while(fast != NULL)
		{
			fast = fast->next;
			
			if(fast!= NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		
		*frontref = head;
		*backref = slow->next;
		slow->next = NULL;
	}
}

struct node* merge(struct node *a, struct node *b)
{
	struct node *finalhead = NULL;
	
	if(a == NULL)
	{
		return b;
	}
	else if(b==NULL)
	{
		return a;
	}
	
	if(a->data <= b->data)
	{
		finalhead = a;
		finalhead->next = merge(a->next, b);
	}
	else
	{
		finalhead = b;
		finalhead->next = merge(a, b->next);
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

void printlist(struct node *root)
{
	while(root!=NULL)
	{
		printf("%d ", root->data);
		root = root->next;
	}
}

int main()
{
	struct node* a = NULL;
  
  	push(&a, 15);
  	push(&a, 10);
  	push(&a, 5); 
  	push(&a, 20);
  	push(&a, 3);
  	push(&a, 2);
  	
  	printlist(a);
  	printf("\n\n");
  	mergesort(&a);
  	printlist(a);
	return 0;
}
