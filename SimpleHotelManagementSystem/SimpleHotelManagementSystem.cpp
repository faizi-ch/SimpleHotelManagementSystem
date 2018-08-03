#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct customer
{
	int room_no;
	char roomType[10];
	int nights;
	char name[50];
	char address[50];
	char nationality[20];
	char phone[20];
}; customer a[50];
int n = 0;

void mainMenu();
void bookRoom();
void customers();
void bookedRooms();
void editRecord();

void main()
{
	mainMenu();

	_getch();
}

void mainMenu()
{
	system("CLS");
	printf("1. Book a room");
	printf("\n2. Customer Record");
	printf("\n3. Rooms allocated");
	printf("\n4. Edit record");
	printf("\n5. Exit");
	printf("\n\nEnter your choice: ");

	switch(_getch())
	{
	case '1':
		bookRoom();
		break;
	case '2':
		customers();
		break;
	case  '3':
		bookedRooms();
		break;
	case '4':
		editRecord();
		break;
	case '5':
		exit(0);
	default:
		printf("\n\aInvalid choice!");
		
	}
}

void bookRoom()
{
	system("CLS");
	int roomPrice = 0;
	
	printf("\n***Room Types***\n\n1. Simple Room\n2. VIP Room");
	char c = _getch();
	if (c=='1')
	{
		roomPrice = 5000;
		strcpy(a[n].roomType, "Simple");
	}
	else if (c=='2')
	{
		roomPrice = 15000;
		strcpy(a[n].roomType, "VIP");
	}


	printf("\n\nEnter room no.: ");
	int r;
	scanf("%d", &r);

	for (int i = 0; i < 50; i++)
	{
		if (a[i].room_no==r)
		{
			printf("\nRoom is already booked!");
			printf("\nPress any key to book any other room");
			if (_getch())
			{
				bookRoom();
			}
		}
	}

	a[n].room_no = r;
	printf("\nEnter no. of nights: ");
	int nn;
	scanf("%d", &nn);
	a[n].nights = nn;
	printf("\nEnter name: ");
	fflush(stdin);
	gets_s(a[n].name);
	printf("\nEnter nationality: ");
	gets_s(a[n].nationality);
	printf("\nEnter address: ");
	gets_s(a[n].address);
	printf("\nEnter Phone No. ");
	gets_s(a[n].phone);

	printf("\n\nRoom No. %d is booked successfully!", r);
	printf("\nYour total fare is %d", roomPrice*nn);

	n++;

	printf("\n\nPress 1 to book another room or 2 to go back to menu");
	if (_getch() == '1')
	{
		bookRoom();
	}
	else
		mainMenu();
}
void customers()
{
	system("CLS");
	printf("***Customers Records***");
	
	printf("\n\nName\tNationality\tAddress\tPhone No.\tRoom No.\tRoom Type\tNo. of Nights");

	for (int i = 0; i <= n; i++)
	{
		printf("\n\n%s\t%s\t%s\t%s\t%d\t%s\t%d", a[i].name, a[i].nationality, a[i].address, a[i].phone, a[i].room_no, a[i].roomType, a[i].nights);
	}

	printf("\n\nPress any key to go back to main menu");
	if (_getch())
	{
		mainMenu();
	}
}
void bookedRooms()
{
	system("CLS");
	printf("***Customers Records***");

	printf("\n\nRoom No.\t\tRoom Type\t\tNo. of Nights");

	for (int i = 0; i < n; i++)
	{
		printf("\n\n%d\t%s\t%d", a[i].room_no, a[i].roomType, a[i].nights);
	}

	printf("\n\nPress any key to go back to main menu");
	if (_getch())
	{
		mainMenu();
	}
}
void editRecord()
{
	int num;
	printf("Enter the room no. ");
	scanf("%d", &num);

	for (int i = 0; i < 50; i++)
	{
		if (a[i].room_no == num)
		{
			printf("\nEnter new record:");
			printf("\\nnEnter name: ");
			fflush(stdin);
			gets_s(a[i].name);
			printf("\nEnter nationality: ");
			gets_s(a[i].nationality);
			printf("\nEnter address: ");
			gets_s(a[i].address);
			printf("\nEnter Phone No. ");
			gets_s(a[i].phone);

			printf("\n\nRecord is modified successfully!");

			printf("\n\nPress 1 to modify another record or 2 to go back to menu");
			if (_getch() == '1')
			{
				editRecord();
			}
			else
				mainMenu();
		}
	}

}