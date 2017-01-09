//binary search in strings

#include <stdio.h>
#include <string.h>
#define MAX 15

int bsearch(char sa[][MAX], char key[], int left, int right);

void main()
{
	int in;
	int n;
	int i;
	char list[15][MAX];
	char key[MAX];
	printf("\n Enter size of the list :");
	scanf("%d", &n);
	printf("\n Enter strings \n");
	for (i=0; i<n; i++)
	{
		scanf("%s", &list[i]);
	}
	printf("\n Enter key to search : ");
	scanf("%s", &key);
	in = bsearch(list, key, 0, n-1);
	if(in != -1)
		printf("Foud at position %d", in+1);
	else
		printf("Element not found");
}

Search()
{
	printf("\n Enter key to search : ");
	scanf("%s", &key);
	in = bsearch(list, key, 0, n-1);
	if(in != -1)
		printf("Foud at position %d", in+1);
	else
		printf("Element not found");
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
