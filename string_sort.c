//A program ito sort strings
//Can be used to arrange names in alphabetical order

#include <stdio.h>
#include <string.h>
#define MAX 15

int bsearch(char sa[][MAX], char key[], int left, int right);
void bubblesort(char A[][MAX], int n);
void display(char A[][MAX], int n);
void selectionsort(char A[][MAX], int n);
void insertionSort(char A[][MAX], int n);
int accept(char A[][MAX]);
int menu();

void main()
{
	char A[MAX][MAX];
	char key[MAX];
	int n, pos, ch;
	n = accept(A);
	do
	{		
	ch = menu();
	switch(ch)
	{
		case 1:
			bubblesort(A, n);
			display(A, n);
			break;
		case 2:
			selectionsort(A, n);
			display(A, n);
			break;
		case 3:
			insertionSort(A, n);
			display(A, n);
			break;
		case 4:
			printf("\n Enter key to search : ");
			scanf("%s", &key);
			pos = bsearch(A, key, 0, n-1);
			if(pos != -1)
				printf(" Foud at position %d", pos+1);
			else
				printf(" Element not found");
			break;
		case 5:
			display(A, n);
			break;
		case 6:
			printf("\n Exiting...");
			break;
		default:
			printf("\n Enter correct choice!");
	}
	}while(ch!=6);
}

int menu()
{
	int choice;
	printf("\nMENU:\n1. Bubble Sort\n2. Selection Sort");
	printf("\n3. Insertion Sort\n4. Binary Search");
	printf("\n5. Display array\n6. Exit");
	printf("\nEnter your choice : ");
	scanf("%d", &choice);
	return choice;
}

int accept(char A[][MAX])
{
	int n, i;
	printf("\nEnter no of strings: ");
	scanf("%d", &n);
	printf("\nEnter strings");
	for(i=0; i<n; i++)
		scanf("%s", &A[i]);
	return n;
}

void display(char A[][MAX], int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%s\n", A[i]);
}

void bubblesort(char A[][MAX], int n)
{
	int i,j;
	char temp[MAX];
	for(i=0; i<n; i++)
	{
		for(j=0;j<(n-i-1);j++)
		{
			if ( strcmp(A[j+1], A[j]) <1 )
			{
				strcpy(temp, A[j+1]);
				strcpy(A[j+1], A[j]);
				strcpy(A[j], temp);
			}
		}
	}
}

void selectionsort(char A[][MAX], int n)
{
	int i,j;
	char temp[MAX];
	for(i=0;i<n;i++)
	{
		for(j=i+1; j<n; j++)
		{
			if( strcmp(A[j], A[i]) <1 )
			{
				strcpy(temp, A[i]);
				strcpy(A[i], A[j]);
				strcpy(A[j], temp);
			}
		}
	}
}

void insertionSort(char A[][MAX], int n)
{
	int i,j;
	char temp[MAX];
	for(i=1;i<n;i++)
	{
		strcpy(temp, A[i]);
		for(j=i-1;j>=0 && strcmp(temp, A[j])<0;j--)
		{
			strcpy(A[j+1], A[j]);
		}
			strcpy(A[j+1],temp);
	}
}

int bsearch(char sa[][MAX], char key[], int left, int right)
{
	int mid;
	mid = (left + right) / 2;
	if (strcmp( sa[mid], key) == 0)
		return mid;
	if (left == right)
		return -1;
	if (strcmp( sa[mid], key) < 0)
		bsearch(sa, key, mid+1, right);
	else
		bsearch(sa, key, left, mid);
}
