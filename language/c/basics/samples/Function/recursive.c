
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
