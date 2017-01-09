//A program to illustrate the concept of circular linked list in C

#include <stdio.h>
#include <string.h>

typedef struct
{
	int roll_no;
	char name[31];
	float marks;
} student;

int menu();
int accept(student *s);
void display(student s);
void displayRecords(student *s, int n);
int Search(student *s, int key, int n);
int BSearch(student *s, int key, int left, int right);
int addNewRecord(student *s, int *n);
void editRecord(student *s, int *n);
void deleteRecord(student *s, int *n);

void main()
{
	student s[60];
	int n, query;
	char con[5];
	do{
		switch(menu())
		{
			case 1:
				n = accept(s);
				break;
			case 2:
				displayRecords(s, n);
				break;
			case 3:
				printf("\nEnter roll number to search : ");
				scanf("%d", &query);
				query=BSearch(s, query, 0, n-1);
				if(query != -1)
					printf("\nFound at position %d  ", query+1);
				else
					printf("\nRecord not found");
				break;
			case 4:
				addNewRecord(s, &n);
				break;
			case 5:
				editRecord(s, &n);
				break;
			case 6:
				deleteRecord(s, &n);
				break;
			default:
				printf("\nEnter 1-6 from menu : ");
		}
		printf("\n Want to exit? \'yes/no\' ... ");
		scanf("%s", &con);
	} while ( strcmp(con, "yes") != 0 );
}

int menu()
{
	int ch;
	printf("\n\nStudent Record Menu");
	printf("\n1. Create new database");
	printf("\n2. Display whole Database");
	printf("\n3. Search for a Student");
	printf("\n4. Add new student data");
	printf("\n5. Edit student data");
	printf("\n6. Delete student data");
	printf("\nEnter your choice : ");
	scanf("%d", &ch);
	return ch;
}

int accept(student *s)
{
	int i,n;
	printf(" Enter total no of students : ");
	scanf("%d",&n);
	for ( i=0; i<n; i++)
	{
		printf("\n Enter Record of Student #%d",i+1);
		printf("\n Roll No.: ");
		scanf("%d", &s[i].roll_no);
		printf(" Name: ");
		scanf("%s", &s[i].name);
		printf(" Marks: ");
		scanf("%f", &s[i].marks);
	}
	return n;
}

	void display(student s)
	{	
		printf("\n %d", s.roll_no);
		printf("\t\t %s", s.name);
		printf("\t %f", s.marks);	
	}

	void displayRecords(student *s, int n)
	{
		int i;
		printf("\n Student Records");
		printf("\n Roll No.\t Name \t Marks");
		for(i=0;i<n;i++)
		{
			display(s[i]);
		}	
	}

int Search(student *s, int key, int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		if( s[i].roll_no == key )
		{
			printf(" Record found at position %d ", i+1);
			display(s[i]);
			return i;
		}
	}
	printf(" Record not found\n");
	return -1;
}

int BSearch(student *s, int key, int left, int right)
{
	int mid;
	mid = (left + right)/2;
	if(s[mid].roll_no == key)
		return mid;
	if(left == right)
		return -1;
	if (s[mid].roll_no < key)
		BSearch(s, key, mid+1, right);
	else
		BSearch(s, key, left, mid);
}

int addNewRecord(student *s, int *n)
{
	printf("\n Enter Record of Student #%d : ",*n+1);
	printf("\n Roll No.: ");
	scanf("%d", &s[*n].roll_no);
	printf(" Name: ");
	scanf("%s", &s[*n].name);
	printf(" Marks: ");
	scanf("%f", &s[*n].marks);
	++(*n);
	return *n;
}

void editRecord(student *s, int *n)
{
	int q, i;
	printf("\nEnter roll no of student to edit");
	scanf("%d", &q);
	i=Search(s, q, *n);
	if(i != -1)
	{
		printf("\n Enter Record of Student #%d : ",i+1);
		printf(" Marks: ");
		scanf("%f", &s[i].marks);
	}
	else
		*n = addNewRecord(s, n);
}

void deleteRecord(student *s, int *n)
{
	int i,j;
	printf("\nEnter roll no of student to delete : ");
	scanf("%d", &i);
	i = Search (s, i, *n);
	if( i >= 0 )		
	{
		printf("\nRecord Deleted");
		for (j=i; j<*n; j++)
		{
			s[i] = s[i+1];
		}
		--(*n);
	}
}
