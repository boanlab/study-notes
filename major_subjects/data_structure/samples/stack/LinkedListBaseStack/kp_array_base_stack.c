# include <stdio.h>
# define MAX 100

typedef struct Stack {

    int stack[MAX]; //������ value
    int top; //������ index

}Stack;

//���� �ʱ�ȭ
void Init (Stack* p) {

    p -> top = 0;
}

//������ ������� Ȯ��
int IsEmpty (Stack* p) {

    if (p -> top == 0) return 1;
    else return 0;

}

//���� �� ���ִ��� Ȯ��
int IsFull (Stack* p) {

    if (p -> top == MAX-1) return 1;
    else return 0;

}

//value�� ���ÿ� �߰�
void Push (Stack* p, int value) {

    if (IsFull(p)) printf("���ÿ� �� �̻� ������ �����..");

    else {

        p -> top += 1;
        p -> stack[p -> top] = value;

    }
}

//���� ���� �ִ� value ����
void Pop (Stack* p) {

    int e;
    if (IsEmpty(p)) printf("���� ������ ����ֽ��ϴ�.");
        
    else {

        e = p -> stack[p -> top];
        p -> top -= 1;
        printf("��� |%d|�� Pop �Ǿ����ϴ�.\n",e);
    }

}

//���� ���� ���� �ִ� value ��ȯ
int Peek (Stack* p) {

    if (IsEmpty(p)) printf("���� ������ ����ֽ��ϴ�.");
    else return p -> stack[p -> top];

}

void Print (Stack* p) {

    printf("���� Stack ��Ȳ");

    for (int i=1; i <= p -> top; i++) {

        printf("|%d| ", p -> stack[i]);

    }

    printf("\n");
}

int main() {

    Stack stack;
    Init(&stack);

    //���ÿ� 1~10���� �ֱ�
    for(int i=1; i <= 10; i++) {

        Push(&stack, i);

    }
    Print(&stack);

    printf("%d�� top�� �־��.\n",Peek(&stack));
    Pop(&stack);
    Pop(&stack);

    Print(&stack);

    
}




