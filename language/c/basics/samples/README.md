# 샘플

Basics에서 사용되는 샘플 코드



---

# Detail, Usage Example


## Iterator Example

### nested loop

```
#include <stdio.h>

int main(){

    int i,j,k;

    for(i = 1; i<=5; i++){
    
        for(j = 1; j<=(5-i); j++){
            printf(" ");
        }
        
        for(k=1; k<=i; k++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}


// result

    *
   **
  ***
 ****
*****
```


## Preprocessor Example

```
#include <stdio.h>

#define MAX(a,b)         a>b? a:b
#define MIN(a,b)         a<b? a:b

#define PRINT_INT(n)     printf("%d",n)


int main(){

    int i,j;

    i = 5;

    j = 7;

    printf("최댓값은 %d 입니다.\n", MAX(i,j));
    printf("최솟값은 %d 입니다.\n", MIN(i,j));


    PRINT_INT(MAX(i,j));

    return 0;
}

```


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

### 2. Pointer Array ( &Function)

```
#include <stdio.h>

void print_pxy(int* pxy[2]); // function (parameter : pointer array)


int main(void) {

    int x = 0, y = 0;
    int *pxy[2];        // pointer array

    pxy[0] = &x;
    pxy[1] = &y;

    *pxy[0] = 256;
    *pxy[1] = 512;

    print_pxy(pxy);
    return 0;
}

void print_pxy(int*pxy[2]){
    printf("pxy[0] = %d\n", *pxy[0]);   // 256
    printf("pxy[1] = %d\n", *pxy[1]);   // 512 
}

```
