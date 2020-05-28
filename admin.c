#include "ass3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>   

/*****************************************************************************************
 * Author: Palvi
 * Input: none
 * Output: 0 if successful
*****************************************************************************************/
 

void adminMain()
{
	int choice;
	int k = 0; /* keeps track of customer count */
	FILE *pFile; /*for case 7*/
	customer_t customer[MAX_CUSTOMER_SIZE];
	do
	{
		choice = adminMenu(); /*int input is taken from adminMenu*/
		switch(choice)
		{
			case 1: customer[k] = createCustomer(); k++; break; /*customer counter "k" increments after function*/
			case 2: if(k)displayCustomerInfo(customer,k); /* checks k if more than 0 */
					else if(!k) {printf("No customers\n");pressEnter();}  /*if k is 0*/
					break;
			case 3: search(); break;
			case 4: editCustomer(); break;
			case 5: deleteCustomer(); break;
			case 6: saveCustomers(customer,k); break;
			case 7: /*load customers() from database it will overwrite your current customer list*/
					k = 0; /*k resets*/
                	pFile = fopen(DB_NAME,"r");
                	if (pFile==0){
                    	printf("No database found\n");
                    	break;
                	}
					/* loops over and reads each customer */
                	while(fread(&customer[k],1,sizeof(customer_t),pFile))
                    	k++; /*k increments to total number of customers in database */
					printf("loaded!\n"); 
					pressEnter();
					break;
			case 8: printf("Successfully logged off\n\n"); break;
			default: printf("Invalid option\n"); break;
		}
	} while(choice != 8); /*clears buffer*/
	fclose(pFile); /*for case 7*/
}

/*****************************************************************************************
 * printAdminMenu: prints 5 options which the admin can do in this ATM system.
 * Author: Palvi
 * Input: optionp
 * Output: none
*****************************************************************************************/
int adminMenu()
{
	int choice;

	printf("=================================\n"
		   "1. Add a customer\n"
		   "2. Display all customers\n"
		   "3. Search for a customer\n"
		   "4. Edit customer\n"
		   "5. Delete customer\n"
		   "6. Save the customers to the database file\n"
		   "7. Load the customers from the database file\n"
		   "8. Log out\n"
		   "=================================\n"
		   "Enter option (number between 1-6)> \n");
		   
	
	scanf("%d", &choice);
	return choice;
}
/*****************************************************************************************
 * Create account: requires personal details 
 * Author: 
 * Input:
 * Output: 
*****************************************************************************************/
customer_t createCustomer()
{
	customer_t temp_customer;
	char input;

	printf("Creating new customer...\n\n");
	
	temp_customer.ID = rand(); /*generates 32767 up to 2^31 -1*/
	printf("The new customer's ID is %d\n", temp_customer.ID);
	pressEnter();

	printf("Enter password of customer>\n");
	scanf("%s",temp_customer.password);

	printf("Enter customer's firstname and lastname separated by spaces>\n");
	scanf("%s %s", temp_customer.firstname,temp_customer.lastname);



	while (getchar() != '\n');
	printf("Press any key to continue or enter * to skip customer details...");
	scanf("%c",&input);
	
	if (input!='*')
	{
		printf("Enter email of customer>\n");
		scanf("%s",temp_customer.email);
		while (getchar() != '\n');
		printf("Enter address of customer>\n");
		scanf("%[^\n]",temp_customer.address);

		printf("Enter phone number of customer>\n");
		scanf("%d",&temp_customer.phone_number);

		printf("Enter initial balance of customer>\n");
		scanf("%lf",&temp_customer.balance);

	} else if(input=='*')
	{
		printf("Customer details skipped.\n");
	}

	printf("Successfully created a new customer!\n");
	pressEnter();
	

	printf("\n");

	return temp_customer;
}

/*****************************************************************************************
 * [insert function name + description]
 * Author: 
 * Input:
 * Output: 
*****************************************************************************************/
void encryptPassword()
{
	/*int index;
	for(index=0; (index < 100 && str[index] != '\0'); index++){
		str[index]= str[index] + 3;
	}*/

}
/*****************************************************************************************
 * [insert function name + description]
 * Author: 
 * Input:
 * Output: 
*****************************************************************************************/
void decryptPassword()
{
	/*int index;
	for(i = 0; (i < 100 && str[i] != '\0'); i++){
		str[index] = str[index] - 3;
	}*/

}

/*****************************************************************************************
 * [insert function name + description]
 * Author: 
 * Input:
 * Output: 
*****************************************************************************************/
void displayCustomerInfo(customer_t *customer,int num_added_customers)
{
	int i;

	printf("This is the display account Info function\n\n");
	printf("ID         Password        Name\n"
           "---------- --------------- ------------------\n");
	for(i=0; i<num_added_customers;i++){
		printf("%-10d %-15s %s %s",customer[i].ID 
							   ,customer[i].password
							   ,customer[i].firstname
							   ,customer[i].lastname);

	printf("\n");
	}
	pressEnter();
}

/*****************************************************************************************
 * Searches for the customer ID
 * Author: 
 * Input:
 * Output: 
*****************************************************************************************/
void search()
{
	printf("This is the search account Info function\n\n");
	pressEnter();
}

/*****************************************************************************************
 * [insert function name + description]
 * Author: 
 * Input:
 * Output: 
*****************************************************************************************/
void editCustomer()
{
	printf("This is the edit customer function\n\n");
	pressEnter();
}


/*****************************************************************************************
 * [insert function name + description]
 * Author: 
 * Input:
 * Output: 
*****************************************************************************************/
void saveCustomers(customer_t * customer, int num_added_customers)
{
	FILE *pFile;
    int i;
    
    pFile = fopen(DB_NAME,"w");
    
    if(pFile == 0)
        return;
    
    for (i=0; i<num_added_customers;i++)
        fwrite(&customer[i],1,sizeof(customer[i]),pFile);
    
    fclose(pFile);
    
	printf("saved!\n");
	pressEnter();
}

/*****************************************************************************************
 * [insert function name + description]
 * Author: 
 * Input:
 * Output: 
*****************************************************************************************/
void loadCustomers()
{
	printf("This is the load customer function\n\n");
	pressEnter();
}

/*****************************************************************************************
 * [insert function name + description]
 * Author: 
 * Input:
 * Output: 
*****************************************************************************************/
void deleteCustomer()
{
	printf("This is the delete customer function\n\n");
	pressEnter();
}





