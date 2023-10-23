
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int list_length =0;

Node* head;

// Node **ptrToList = &head;



// int main(void)
// {
// 	ListInit;
// 	AddNodeLast(5);
// 	AddNodeLast(10);
// 	AddNodeFirst(1);
// 	AddNode(3, 1);
// 	PrintList();
// 	DeleteNodeFirst();
// 	printf("list after deleting first node:\n");
// 	PrintList();
// 	printf("length of list = %d\n", list_length);
// 	DeleteNodeLast();
// 	printf("list after deleting last node\n");
// 	PrintList();
// 	printf("-----------------------\n");
// 	AddNodeLast(100);
// 	AddNodeLast(200);
// 	PrintList();
// 	DeleteNodePosition(3);
// 	printf("list after deleting position 3:\n");
// 	PrintList();
// 	AddNodeFirst(5);
// 	AddNodeLast(5);
// 	AddNodeLast(10);
// 	AddNodeLast(20);
// 	AddNodeLast(5);
// 	printf("-----------------------\n");
// 	PrintList();
// 	DeleteNodeValue(5);
// 	printf("-----------------------\n");
// 	PrintList();
// }

void ListInit(void)
{
	head = NULL;
}


void PrintList(void)
{
	int i=0;
	Node* current = head;
	if(current == NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		while(current != NULL)
		{
		  i++;
          printf("value of node %d = %p\n" ,i, current->data);
		  current = current->next	;
		}
	}
}

void getDataByIndex(int index, void * ptrToData){
	Node* current = head;
	if(current == NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		ptrToData = current + (index*sizeof(current));
	}
	printf("%p",ptrToData);
}

void AddNodeLast(void * value)
{
	Node * new_node = (Node*)malloc(sizeof(Node));
	new_node -> next = NULL;
	new_node -> data = value;

	if (head == NULL)
	{
      head = new_node;
	}
	else
	{
      Node* current = head;
      while(current->next != NULL)
      {
    	  current = current->next;
      }
      current -> next = new_node;
	}
	list_length ++;
}

void AddNodeFirst(void * value)
{
	Node * new_node = (Node*)malloc(sizeof(Node));
	new_node -> next = NULL;
	new_node -> data = value;

	if (head == NULL)
	{
      head = new_node;
	}
	else
	{
      new_node ->next = head;
      head = new_node;
	}
	list_length ++;
}

void AddNode (void * value, int position)
{
	Node * new_node = (Node*)malloc(sizeof(Node));
	new_node -> next = NULL;
	new_node -> data = value;


	if(head == NULL)
	{

	}
	else
	{
		if(position >list_length || position<=0)
		{
			printf("invalid position\n");
		}
		else if(position ==1)
		{
			AddNodeFirst(value);
		}
		else if(position == list_length)
		{
			AddNodeLast(value);
		}
		else
		{
			Node* before = head;
			Node* after;

			for (int i =1 ; i<position-1; i++)
			{
				before = before -> next;
			}
			after = before -> next;
			before -> next = new_node;
			new_node -> next = after;
			list_length ++;
		}
	}
}

void DeleteNodeFirst (void)
{
 if(list_length == 0)
 {
	 printf("list is empty\n");
 }
 else
 {
	 Node* current = head;
	 head = head->next;
	 free(current);
 }
 list_length--;
}

void DeleteNodeLast(void)
{
	 if(list_length == 0)
	 {
		 printf("list is empty\n");
	 }
	 else
	 {
         Node* current = head;
         while(current -> next-> next != NULL)
         {
        	 current = current->next;
         }
         free(current->next);
         current->next = NULL;
	 }
	 list_length--;
}

void DeleteNodePosition(int position)
{
	Node* current = head;
	if(position> list_length || position<=0)
	{
		printf("invalid position\n");
	}
	else if(position == 1)
	{
        DeleteNodeFirst();
	}
	else if(position == list_length)
	{
        DeleteNodeLast();
	}
	else
	{
		for(int i=1 ; i<position-1; i++)
		{
			current = current -> next;
		}
		Node* after = current -> next;

		current->next = after-> next;
		free(after);
		list_length --;
	}
}

void DeleteNodeValue(void * value){
	Node * current = head;
	Node * previous = head;
	do
	{
		if ((current->next == head ->next) && (current->data == value))
		{
			DeleteNodeFirst();
			current = head;
			previous = head;
		}
		else if ((current->next == NULL) && (current->data == value))
		{
			DeleteNodeLast();
			previous->next = NULL;
		}
		else if(current ->data == value)
		{
			previous->next = current->next;
			free(current);
			current= previous->next;
		}
		else{	
		previous = current;
		current = current->next;
		}
	} while (previous->next != NULL);
}