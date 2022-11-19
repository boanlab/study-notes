
# Detail, Usage Example


## Function Example

### 1. Recursive Function ( fibonacci sequence )

```

#include <stdio.h>

int Fibo(int n);

int main(void){

    int i,num;

    printf("num : ");
    scanf("%d",&num);

    for(i=1; i<=num; i++){           // iterator

        printf("%3d", Fibo(i));

        if(i%5 == 0){                // to improve the readability
            printf("\n");
        }
    }

    return 0;
}

int Fibo(int n){                    // recursive function

    if (n<=0){                      // condition
        return 0;
    }

    if ((n==1) || (n==2)){          // relational operator & logic operator
        return 1;
    }
   
   return Fibo(n-2) + Fibo(n-1);    // recursive
}

```





## Pointer Exmaple

### 1. Struct Pointer
```
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

```
