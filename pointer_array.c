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
