/**********************************
* generally what goes before main
* goes here, except for #include
* any other library.
**********************************/

#ifndef _ASS3_H_
#define _ASS3_H_
#define DEBUG                  /* comment this DEBUG line out at the end when everything has been debugged */
#define MAX_NAME_LEN 20
#define MAX_PASS_LEN 20
#define MAX_ADMIN_SIZE 5
#define MAX_CUSTOMER_SIZE 5
#define DB_NAME "database"             /* for the encrytion functions */

typedef struct customer
{
	int ID;
   char firstname[MAX_NAME_LEN], lastname[MAX_NAME_LEN];
   char email[20], address[20], password[MAX_PASS_LEN];
   int phone_number;
   double balance;
} customer_t;     /* If finished, add account type function */

typedef struct admin{
   int id;
   char password[MAX_PASS_LEN];
} admin_t;

typedef struct node
{
  int value;
  struct node* next;
} node_t;


void adminMain();                /* Palvi: inputs- none, outputs- 0 if successful */
int isAdmin(int, char *, admin_t *);                      /* boolean: validates if person is admin or not */ 
int adminMenu();               /* Palvi: input is pointer of choice/option and output is none */
customer_t createCustomer();               /* Nuvin 
                                     inputs: customer information first name, last name, address, phone number,
                                                                     password, email, intial balance*/
void encryptPassword();             /* Nuvin input: password
                                             returns: encrypted password*/
void decryptPassword();             /* Nuvin input: encrypted password
                                            returns: password*/
void displayCustomerInfo(customer_t *,int);          /*  input: customer
                                        ouput: prints account information */
void search();                      /* Dennis input: string customerid/customername
                                              post: display accounts with that customer name*/
void editCustomer();                /* Dennis input: customer 
                                              post: edit customer information eg. name address*/
void saveCustomers(customer_t *,int);                /* Dennis post: saves customer information in database*/
void loadCustomers();                /* Dennis returns: loads customer information from database*/
void deleteCustomer();              /* Dennis input: customer
                                              post: deletes customer*/
void login();                       /* Nuvin */

  

void customerMain();                /* Palvi: input: none, output: 0 if successful */
int customerMenu();  /* Palvi: input: pointer of choice/option and output = none */
void deposit();                        /* Sahar: deposit - INPUT: amount adding to balance
                                                         - POST: depositing money*/
void withdraw();                       /*Sahar: withdraw - INPUT: subtracting money from balance
                                                         - POST:  withdrawing money */
void viewBalance();                    /*Sahar: balance - INPUT:  total amount
                                                         - OUTPUT:  display customer's balance before and after withdrawing and depositing*/
void convertCurrency();                /* end of the function, there can be an option to transfer the converted money so it will take it to the transfer function */
void transfer();                       /* Saloni:
                                           - Convert: 
                                           INPUT: input the amount that needs to be converted
                                           OUTPUT: the converted currency
                                           - Transfer:  
                                           INPUT: the amount that needs to be transffered and to what account (account number, customer id)
                                           OUTPUT: the desired amount is transferred to the new account 
                                           convertcurrency is just a function that wil be called in transfer (domestic/international)
                                        */
void pressEnter();                              /*Dennis*/
int isValidCustomer(int, char*,customer_t *);   /* Dennis*/

#endif            
