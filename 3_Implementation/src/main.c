#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"generate_bill.h"
#include "function.h"

struct items{
  char item[30];
  float price;
  float qty;
};

struct orders{
  char customer[50];
  char date[50];
  int numofItems;
  struct items itm[50];
};





int main(){
  float total;
  
  int opt,n;
  struct orders ord;
  struct orders order;
  char saveBill='y',contFlag='y';
  
  char name[50];
  FILE *fp;
  /* To store data of bill */
  while(contFlag =='y'){
  system("clear");
  float total=0;
  int invoiceFound=0;
  printf("\t===========General Store===========");
    /* To display the name of the store on the bill */
  printf("\n\nPlease select your prefered opertion ");
  printf("\n1.Generate Invoice");
  printf("\n2.Show all Invoices");
  printf("\n3.Search Invoice");
  printf("\n4.Exit");
  printf("\n5.Clear");
    /* To select the opertion to be done by the owner */

  printf("\n\nYour choice:\t");
  scanf("%d",&opt);
  fgetc(stdin);
  switch(opt){
    case 1:
      /* To generate the new bill*/
      system("clear");
     /* To clear the options after selection of choice */
    printf("\nPlese enter the name of the customer:\t");
    fgets(ord.customer,50,stdin);
      /* To read the customer name*/
    ord.customer[strlen(ord.customer)-1]=0;
    strcpy(ord.date,__DATE__);
      /* To generate the date on the bill*/
    printf("\nPlease enter the number of items:\t");
    scanf("%d",&n);
      /* To read the number of items purchased by the customer */
    ord.numofItems=n;
    for(int i=0;i<n;i++){
      /* The for loop is to collect the data of n number of items purchased by the customer in the single formate*/ 
      fgetc(stdin);
      printf("\n\n");
      printf("Please enter the item %d:\t",i+1);
      fgets(ord.itm[i].item,20,stdin);
        /* To read the name of the item */
      ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
      printf("[Note: the grams values should be written as 250gm=0.25\t]");
      printf("\nPlease enter the quantity(KG):\t");
      
      scanf("%f",&ord.itm[i].qty);
      /* To read the Quantity of the item */
      printf("Please enter the unit price:\t");
      scanf("%f",&ord.itm[i].price);
      /* To read the price of the item */
      total +=ord.itm[i].qty*ord.itm[i].price;
      /*To do the total of quantity * price of the item*/
    }

    generateBillHeader(ord.customer,ord.date);
    for(int i=0;i<ord.numofItems;i++){
      generateBillBody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);
    }
    generateBillFooter(total);

    printf("\nDo you want to save the bill[y/n]:\t");
    scanf("%s",&saveBill);
      /* The commond used to ask the own to save the bill or not */

    if(saveBill =='y'){
      /* To save the bill in the fill */
      fp=fopen("GeneralStoreBill.dat","a+");
      fwrite(&ord,sizeof(struct orders),1,fp);
      if(*fwrite!=0)
        printf("\nSuccessfully saved");
      else
        printf("\nError saving");
      /* if having any issue in saveing the bill the above meassage is printed*/
      fclose(fp);
      /* To close the fill after saving the bill */
    }
    break;

    case 2:
      /* To display the all bill stored in the fill */
    system("clear");
    fp=fopen("GeneralStoreBill.dat","r");
      /* To open the fill */
    printf("\n *****Your Previous Invoices*****\n");
    while(fread(&order,sizeof(struct orders),1,fp)){
      float tot=0;
      generateBillHeader(order.customer,order.date);
      for(int i=0;i<order.numofItems;i++){
        generateBillBody(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
        tot+=order.itm[i].qty*order.itm[i].price;
        } 
      generateBillFooter(tot);
    }
    fclose(fp);
      /* To close the fill*/
    break;
    case 3:
      /* To generate the bills aviable on the customer we want */
    printf("\nEnter the name of the customer:\t");
      
    
    fgets(name,50,stdin);
    name[strlen(name)-1]=0;
    system("clear");
    fp=fopen("GeneralStoreBill.dat","r");
      /* To open the file */
    printf("\t ***** Invoice of %s *****",name);
      /* To display the bills present with the purticuler name*/
    while(fread(&order,sizeof(struct orders),1,fp)){
      /* To check the name to display bills*/
      float tot=0;
      if(!strcmp(order.customer,name)){
      generateBillHeader(order.customer,order.date);
      for(int i=0;i<order.numofItems;i++){
        generateBillBody(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
        tot+=order.itm[i].qty*order.itm[i].price;
      }
      generateBillFooter(tot);
      invoiceFound=1;
      }
       
    }
    if(!invoiceFound){
      printf("sorry the invoice for %s doesnot exists",name);
      /* To display msg if the name does'n exists in the fill*/
    }
    fclose(fp);
    break;
    case 4:
      /* To exit the bill */
    printf("\n\t\t Bye Bye:)\n\n");
    exit(0);
    break;

    

    case 5:
    system("clear");
      /* To clear the display*/
      break;

    default:
    printf("Sorry invalied option");
    break;
  }
    
      
    printf("\nDo you want to perform another operation?[y/n]:\t");
    scanf("%s",&contFlag);
    /* To do any operation after the one bill is generated */
    printf("\n\t\t Bye Bye:)\n\n");
  }
  return 0;  
}
