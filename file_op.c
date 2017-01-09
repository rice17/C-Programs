//A very simple program to read and write files in C

	
NEW 
.
Folder Path
My Drive
Assignments
FDS Assignment
Folders and views
My Drive
Shared with me
Recent
Google Photos
Starred
Trash
Backups
Get Drive for PC
3 GB of 15 GB used
Upgrade storage
NAME 
Files
.

Unknown File
a.out

C
abcd.c

C
abhishar.c

Binary File
as1.cpp

C
as10.c

C
as11.c

C
as2.c

Binary File
as2.cpp

C
as3.c

Binary File
as3.cpp

C
as4.c

Binary File
as4.cpp

C
as5.c

Binary File
as5.cpp

C
as6.c

Binary File
as6.cpp

Binary File
as7.cpp

Binary File
as8.cpp

C
as9.c

Binary File
asin7.cpp

C
assn10.c

C
bs.c

C
circularList.c

Compressed Archive
drive-download-20161002T081543Z.zip

Binary File
index.cpp

C
LinkedList.c

C
pcpy.c

C
sds.c

Binary File
sort

C
sort.c

C
sparse.c

Binary File
trial

C
tset.c

Binary File
Untitled Document
C
as6.c
Details
Activity
LAST YEAR

You uploaded an item
Oct 3, 2016
C
as6.c
No recorded activity before October 3, 2016
New Team Drive

#include <stdio.h>

typedef struct
{
	int roll;
	char name[30];
}record;

void accept(record r)
{
	printf("\nEnter records ");
	printf("\nEnter roll no : ");
	scanf("%d", &r.roll);
	printf("\nEnter name : ");
	scanf("%s", &r.name);
}

int addRecord(int n)
{
	FILE *fp;
	record r;
	if(!(fp = fopen("filename", "r+")));
		fp = fopen("filename", "w+");
	fseek(fp, 0, n);
	printf("\nEnter records ");
	printf("\nEnter roll no : ");
	scanf("%d", &r.roll);
	printf("\nEnter name : ");
	scanf("%s", &r.name);
	fclose(fp);
}

void main()
{
	FILE *fp;
	int x; char y[10];
	fp = fopen("filename", "r+");
	fclose(fp);
	addRecord(1);
/*	fscanf(fp, "%\", r);
	printf("\nroll no : %d", r.roll);
	printf("\nname : %s", r.name);*/
}
