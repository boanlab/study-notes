#include <stdio.h>
#include <string.h>  // to use strcpy function


struct myDevice // Struct
{
    char phone[20];
    char labtop[20];
    char tablet[20];
    char earphone[10];

}; // ; be careful

int main(void){

    struct myDevice younghwan;

    struct myDevice *ptr;       // Struct Pointer declare == Struct myDevice's address

    ptr= &younghwan;

//  *ptr.phone; error
//  (*ptr).phone = "Z Filp 3"; error 

    strcpy((*ptr).phone, "Z Filp 3"); // (*ptr).phone == younghwan.phone
    strcpy((*ptr).labtop, "MacBook Air");
    strcpy((*ptr).tablet, "iPad Pro");
    strcpy((*ptr).earphone, "Sony XM5" );
    
    printf("phone : %s\n", ptr->phone);
    printf("labtop: %s\n", ptr->labtop);
    printf("tablet : %s\n", ptr->tablet);
    printf("earphone : %s\n", ptr->earphone);


    return 0;

}
