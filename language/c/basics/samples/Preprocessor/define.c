

#include <stdio.h>

#define MAX(a,b)     a>b? a:b
#define MIN(a,b)     a<b? a:b

#define PRINT_INT(n) printf("%d",n)


int main(){

    int i,j;

    i = 5;

    j = 7;

    printf("최댓값은 %d 입니다.\n", MAX(i,j));
    printf("최솟값은 %d 입니다.\n", MIN(i,j));


    PRINT_INT(MAX(i,j));

    return 0;
}