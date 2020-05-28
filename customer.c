#include "ass3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>      

/*****************************************************************************************
 * [insert function name + description]
 * Author: 
 * Input:
 * Output: 
*****************************************************************************************/
void customerMain()
{
	int choice;
	do
	{
		choice = customerMenu();
		switch(choice)
		{
			case 1: deposit(); break;
			case 2: withdraw(); break;
			case 3: viewBalance(); break;
			case 4: convertCurrency(); break;
			case 5:  transfer(); break;
			case 6: printf("Successfully logged off\n\n"); break;
			default: printf("Invalid option\n"); break;
		}
	}while(choice != 6);
	
}
/*****************************************************************************************
 * [insert function name + description]
 * Author: 
 * Input:
 * Output: 
*****************************************************************************************/
int customerMenu()
{
	int choice;
	
	printf("=================================\n"
		   "1.Make a deposit\n"
		   "2.Make a withdrawal\n"
		   "3.View balance\n"
		   "4.Convert currency\n"
		   "5.Transfer an amount\n"
		   "6.Log out\n"
		   "=================================\n"
		   "Enter choice (number between 1-6)> \n");

	scanf("%d", &choice);
	return choice;
}

/*****************************************************************************************
 * [insert function name + description]
 * Author: 
 * Input:
 * Output: 
*****************************************************************************************/
void deposit() 
{
	printf("This is the deposit function\n\n");
	pressEnter();
	/*int temp = 1;
	
	while(temp){
		
		printf("You currently have $%d\n", amount);
		printf("Enter amount to deposit: ");
	
	int d;
	scanf("%d",&d);
	if (d < 0)
	{
		printf("Invalid amount\n");
	}
	
	else
	{
		amount += d;
		printf("Would you like a receipt ( y or n ): ");
		
		char ch[5];
	    scanf("%s",ch);
		
		if (ch[0] == 'y' || ch[0] == 'Y'){
			
			printf("You current balance is $%d\n",amount);
		    printf("Have a great day!\n");
			
			temp = 0;
			
			}

		else if(ch[0] == 'n' || ch[0] == 'N')
		{
			printf("Have a great day!\n");
			temp = 0;
		}
			
			else
			{
				printf("Invalid entry\n");
			}
			}
			}
	*/		
}

/* can only deposit a positive amount */

/*****************************************************************************************
 * [insert function name + description]
 * Author: 
 * Input:
 * Output: 
*****************************************************************************************/
void withdraw() 
{
	printf("This is the withdraw function\n\n");
	pressEnter();

}

/*****************************************************************************************
 * [insert function name + description]
 * Author: 
 * Input:
 * Output: 
*****************************************************************************************/
void viewBalance() 
{
	printf("This is the viewBalance function\n\n");
	pressEnter();
}

/*****************************************************************************************
 * transfers money to either domestic or international accounts via calling convertCurrency
 * Author: 
 * Input:
 * Output: 
*****************************************************************************************/
void transfer() 
{
	printf("This is the transfer function\n\n");
	pressEnter();
}

/*****************************************************************************************
 * [insert function name + description]
 * Author: 
 * Input:
 * Output: 
*****************************************************************************************/
void convertCurrency() 
{
	printf("This is the converCurrency function\n\n");
	pressEnter();
}


