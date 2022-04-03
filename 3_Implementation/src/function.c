#include<stdio.h>


/* To Generate the bill Header*/
void generateBillHeader(char name[50],char date[30]){
  printf("\n\n");
    printf("\t\t\t General Store");
    printf("\n\t  -------------------------");
    printf("\nDATE:%s",date);
    printf("\nInvoice To:%s",name);
    printf("\n");
    printf("----------------------------------\n");
    printf("Items\t\t");
    printf("Qty\t\t");
    printf("Total\t\t");
    printf("\n----------------------------------");
    printf("\n\n");
}



/* To Generate the Bill Body*/
void generateBillBody(char item[30],float qty,float price){
  printf("%s\t\t",item);
    printf("%.2f\t\t",qty);
    printf("%.2f\t\t",qty*price);
    printf("\n");
}


int count(int num){


int count_ = num+num;

return count_;
}
