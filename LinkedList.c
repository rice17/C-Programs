//A program to illustrate the following
//understanding of singly linked lists
//involving reversing the list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int roll;
	char name[30];
	struct node *next;
}node;

node *create_node()
{
	node *head;
	head = (node *)malloc(sizeof(node));
	head->next = NULL;
	printf("Enter Roll no and name respectively\n");
	scanf("%d %s", &(head->roll), &(head->name));
	return head;
}

node* insert_beg(node *head)
{
	node *tmp;
	tmp = create_node();
	tmp->next = head;
	head = tmp;
	return head;
}

void insert_end(node *head)
{
	node *ptr;
	if(head == NULL)
	{
		printf("Create a list first!\n");
		return;
	}
	ptr = head;
	while(ptr->next!=NULL)
		ptr = ptr->next;
	ptr->next = (node*) malloc(sizeof(node));
	ptr = ptr->next;
	scanf("%d", &(ptr->roll));
	scanf("%s", &(ptr->name));
	ptr->next = NULL;
}

node* search_node(node* list)
{
	int roll_no;
	scanf("%d", &roll_no);
	while(list->roll!=roll_no && list->next!=NULL)
	{
		list = list->next;
	}
	if(list->roll != roll_no)
		return NULL;
	return list;
}

void insert_between(node *head)
{
	node *p, *temp;
	printf("Enter roll no after which you want to insert new node\n");
	p = search_node(head);

	temp = p->next;
	p->next = create_node();
	p = p->next;
	p->next = temp;
}

void traverse(node *head)
{
	printf("%-10s %-10s\n\n", "Roll No", "Name");
	while(head != NULL)
	{
		printf("%-10d %-10s\n", head->roll, head->name);
		head = head->next;
	}
}

void search(node *head)
{
	node *temp;
	printf("Enter roll no to search\n");
	temp = search_node(head);
	if(temp != NULL)
		printf("\nRoll No: %d Name: %s\n", temp->roll, temp->name);
	else
		printf("\nRecord ot fount\n");
}

void delete_end(node *list)
{
	while(list->next->next != NULL)
	{
		list = list->next;
	}
	free(list->next);
	list->next = NULL;
}

void delete_between(node *list)
{
	node *temp;
	printf("Enter roll no to delete\n");
	temp = search_node(list);
	if(temp == NULL)
	{
		printf("\nNothing to delete\n");
		return;
	}
	while(list->next != temp)
	{
		list = list->next;
	}
	list->next = temp->next;
	free(temp);
}

node * delete_beg(node* list)
{
	node *tmp;
	tmp = list;
	list=list->next;
	free(tmp);
	return list;
}

void reverse_print(node *list)
{
	node* temp;
	int n, i;
	temp = list;
	n=1;
	while(temp->next!=NULL)
	{
		temp = temp->next;
		n++;
	}
	while(n>=1)
	{
		i=1;
		temp = list;
		while(i<n)
		{
			temp = temp->next;
			i++;
		}
		printf("%10d %10s\n", temp->roll, temp->name);
		n--;
	}
}

node* reverse_list(node *list)
{
	node *temp, *ptr, *tail;
	int n, i;
	temp = list;
	n=1;
	while(temp->next!=NULL)
	{
		temp = temp->next;
		n++;
	}
	tail = NULL;
	while(n>=1)
	{
		i=1;
		temp = list;
		while(i<n)
		{
			temp = temp->next;
			i++;
		}
		if(tail==NULL)
		{
			ptr = (node*) malloc(sizeof(node));
			tail = ptr;
		}
		else
		{
			ptr->next = (node*) malloc(sizeof(node));
			ptr=ptr->next;
		}
		ptr->roll = temp->roll;
		strcpy(ptr->name, temp->name);
		n--;
	}
	return tail;
}

int menu()
{
	int choice;
	printf("\n\nMENU\n----\n");
	printf("1. Create a new list\n");
	printf("2. Add a node at the end\n");
	printf("3. Add a new node at the beginning\n");
	printf("4. Add a new node in between\n");
	printf("5. Search a node\n");
	printf("6. Print the list\n");
	printf("7. Delete last node\n");
	printf("8. Delete first node\n");
	printf("9. Delete a node in between\n");
	printf("10. Reverse print\n");
	printf("11. Reverse list\n");
	printf("12. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	return choice;
}

void main()
{
	node *list;
	list = NULL;
	while(1)
	{
		switch(menu())
		{
			case 1:
				list = create_node();
				continue;
			case 2:
				insert_end(list);
				continue;
			case 3:
				list = insert_beg(list);
				continue;
			case 4:
				insert_between(list);
				continue;
			case 5:
				search(list);
				continue;
			case 6:
				traverse(list);
				continue;
			case 7:
				delete_end(list);
				continue;
			case 8:
				list = delete_beg(list);
				continue;
			case 9:
				delete_between(list);
				continue;
			case 10:
				reverse_print(list);
				break;
			case 11:
				list = reverse_list(list);
				continue;
			case 12:
				break;
			default:
				printf("Enter correct choice\n");
				continue;
		}
		break;
	}
}
