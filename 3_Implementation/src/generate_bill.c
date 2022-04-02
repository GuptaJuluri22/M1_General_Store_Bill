#include<stdio.h>

/* To Generate The Bill Footer */
void generateBillFooter(float total){
  printf("\n");
  float dis=0.1*total;
  float netTotal=total-dis;
  float cgst=0.09*netTotal,grandTotal=netTotal+2*cgst;
  printf("-----------------------------------\n");
  printf("Sub Total\t\t\t%.2f",total);
  /* To do the total of all product buyed by the customer */
  printf("\nDiscount @10%s\t\t%.2f","%",dis);
  /* To give a discount of 10% */
  printf("\n\t\t\t\t-----------");
  printf("\nNet Total\t\t\t%.2f",netTotal);
  /* The amount after removing the discount amount*/
  printf("\nCGST @9%s\t\t\t%.2f","%",cgst);
  /* Tax to be paid to the centeral goverment */
  printf("\nSGST @9%s\t\t\t%.2f","%",cgst);
  /* Tax to be paid to the state goverment */
  printf("\n----------------------------------");
  printf("\nGrand Total\t\t\t%.2f",grandTotal);
  /* The total amount to be paid by the customer */ 
  printf("\n----------------------------------\n");
  //textcolor(4);
  printf("\t Thank you:)\n");
  printf("\t Please Visit Again\n");
  
}