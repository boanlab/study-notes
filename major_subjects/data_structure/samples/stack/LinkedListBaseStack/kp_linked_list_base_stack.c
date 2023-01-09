# include <stdio.h>
# include <stdlib.h>

typedef struct Stack_Node{

    int data;
    struct Stack_Node* link;

}Stack_Node;


int IsEmpty (Stack_Node* top) {

    if (top == NULL) return 1;
    else return 0;
}

void Push (Stack_Node* top, int value) {

    //���Ḯ��Ʈ�� FULL�� ���� �� ����

    Stack_Node* temp = (Stack_Node*)malloc(sizeof(Stack_Node));
    temp -> data = value;
    temp -> link = top;
    top = temp;

}

void Pop (Stack_Node* top) {

    int data = top -> data;

    if (IsEmpty(top)) printf("������ ����ֽ��ϴ�");
    else {

        Stack_Node* temp = top;
        top = top -> link;
        free(temp);
        printf("%d�� Pop �Ǿ����ϴ�.", data);

    }
}

/*
void Print (Stack_Node* top) {

    while (top != NULL) {

        printf("%d -> ", top -> data);
        top = top -> link;

    }
    printf("\n");
}
*/

int main() {

    Stack_Node* stack;
    stack -> link = NULL;

    Push(stack,1);
    Push(stack,2);
    Pop(stack);

   // Print(stack);


}
