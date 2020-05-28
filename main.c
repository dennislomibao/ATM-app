#include "ass3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**************************************************************************************************
  ***PLEASE READ***PLEASE READ***PLEASE READ***PLEASE READ***PLEASE READ***PLEASE READ**************
  **************************************************************************************************
  * if you want to compile ->  "gcc -Wall -Werror -ansi -o test main.c admin.c customer.c -lm"
  *
  *       #Note:  line above will compile those 3 files at the same time including .h file.
  *
  * if you want to test output  ->   "./test"  
  *      
  *  pre-made Admin account -----> userID is "123"   password is "abc"
  *
  *  pre-made Customer account --> userID is "321"   password is "cba"
***************************************************************************************************
  * I renamed the Workspace to "a3-Master" 
  * This workspace will be the master branch and we always have to make sure that all the files
  * are able to compile without any errors. 
  * If you want to add/change/experiment code you have to make your own branch which means that
  * you have to copy this workspace and make a new one of your own - you can do this by clicking
  * the "fork" button on the top right and remember to rename your workspace. eg. a3-Dennis 
  * Once you are sure that your code works without any errors in your workspace branch then you can 
  * add that code here in the Master branch and make sure it compiles. 
  * If you add code here that causes errors i will comment it out
  * Unless you are not coding at the same time with others then its fine to code directly here
  * but make sure the code is able to compile before leaving.
 **************************************************************************************************
***************************************************************************************************
 *****UPDATES/DONE/CURRENT FEATURES***Version-29-May-20******
 *> app uses the structs now
 *> app is able to print out the menus(login, customer, admin)
 *> you can login with admin and customer (details of pre-made accounts provided above)
 *> you can register a new customer
 *> you can view all customers and their details - name, password, firstname and lastname
 *> you can save the created customers in database
 *> you can load the customers from the database
 *> you can login using created customers as long as they were saved in the database
 *> you can log out and exit your account
 *> you can access all the functions and it prints out a msg (eg. "This is the deposit function")
 *> you can access these files in github. https://github.com/dennislomibao/ATM-app
 ***************************************************************************************************
 *****MINOR BUGS******
 *> sometimes "segmentation fault" error will appear after you logout if you had saved/loaded database
****************************************************************************************************
**************************************************************************************************
  *****NOT-DONE*****
  ***********************************************************
  *****FOR ADMIN*****
  *> edit customer details   *> generate unique ID (that doesnt exist already) //sorting algo should be good for large data set
  *> delete customer         *> displayCustomerInfo()- address, number, email, intial balance
  *> search function         *> create another admin?
  ***********************************************************
  *****FOR CUSTOMER*****
  *> deposit()               *> withdraw()
  *> viewBalance()           *> convertCurrency()//can be static?      
  *> transfer() //double check about ID
  ***********************************************************
  *****GENERAL*****
  *> encryptPassword         *> decryptPassword
  *> file encryption         *> file compression
  *> invalid input messages  *> function block comments
  *> Linkedlist? //simple array wont give high mark
****************************************************************************************************/


int main ()  
{
    /*creates one admin -> id:123 pass:abc */
    admin_t admin[MAX_ADMIN_SIZE];
    admin[0].id=123;
    strcpy(admin[0].password,"abc");

    /*welcome message*/
    printf("Welcome to Group 2's App\n");

    while(1){ /*this while loop will only end when user choose 2*/
        
        printf("=================================\n"
		       "1. Log in\n"
		       "2. Exit\n"
		       "=================================\n"
		       "Enter option (number between 1-2)> \n");
        char a = getchar(); 
        if (a=='1') login(&admin);
        if (a=='2') exit(0);
        
        while (getchar() != '\n'); /*cleans buffer*/
    }

   return 0;
}
/*****************************************************************************************
*****************************************************************************************/
void login(admin_t *admin)
{
    /*loads database file*/
    FILE *pFile;
   int id,x,k; 
   char password[20];
   customer_t customer[MAX_CUSTOMER_SIZE];
   k = 0;
   pFile = fopen(DB_NAME,"r");
   if (pFile==0){
     printf("Error no database found\n");
     return;
   }
   while(fread(&customer[k],1,sizeof(customer_t),pFile)){
       k++;
   }

    while(1){
    printf("Enter User ID>  ");
    scanf("%d",&id);

    printf("Enter password> ");
    scanf("%s", password);

    x = isAdmin(id, password, admin); 
    if(x){ /* x will return 1 if they are admin[0] */
        printf("\nHello Admin!!!!!!!!!!!!!!!!\n");
        adminMain();
        break;
    }else if ((id==321 && !strcmp(password,"cba"))||isValidCustomer(id,password,customer)){
        printf("\nHello Customer!!!!!!!!!!!!!!!!\n");
        customerMain();
        break;
        /*else if (id==321 && !strcmp(password,"cba")){
        printf("\nHello Customer!!!!!!!!!!!!!!!!\n");
        customerMain();
        break;*/
    } 

    printf("\nIncorrect user ID or password, please try again.\n\n");
    while (getchar() != '\n');
    }

    fclose(pFile);  
}

/*****************************************************************************************
 * Boolean validation whether the admin is valid or not
 * Author: 
 * Input:
 * Output: 
*****************************************************************************************/
int isAdmin(int ID, char *password, admin_t *admin)
{
    if(admin[0].id==ID && !strcmp(admin[0].password,password)){
        return 1;
    }
        
	return 0;
}
/*****************************************************************************************/
int isValidCustomer(int id, char *password,customer_t * customer)
{
	int i;
    
    for (i=0; i<MAX_CUSTOMER_SIZE;i++){
        if(id==customer[i].ID&&!strcmp(customer[i].password,password))
            return 1;
    }
	
    return 0;
}
/*****************************************************************************************/
void pressEnter()
{
	printf("Press enter to continue...");
	int enter = 0;
	while (getchar() != '\n');
	while (enter != '\r' && enter != '\n') { enter = getchar(); }
}

