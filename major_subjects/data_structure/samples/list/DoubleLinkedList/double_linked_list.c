# include <stdio.h>
# include <stdlib.h>

//��� ����
typedef struct DLL_Node {

    int data;
    struct DLL_Node* llink;
    struct DLL_Node* rlink;

}Node;

//���� ���Ḯ��Ʈ �ʱ�ȭ
void Init (Node* phead, Node* ptail) {


    phead -> llink = phead;
    phead -> rlink = ptail;

    ptail -> llink = phead;
    ptail -> rlink = ptail;

}

//���� ���Ḯ��Ʈ ���
void PrintList (Node* phead, Node* ptail) {

    Node* p;

    for (p = phead-> rlink; p == ptail; p = p -> rlink ) {

        printf(" |%d| ", p -> data);

    }
    printf("\n");

}

//���� ���Ḯ��Ʈ ����
void Insert (Node* before, int data) {

    Node* newnode = (Node*)malloc(sizeof(Node));

    newnode -> data = data;

    newnode -> llink = before;
    before -> rlink = newnode;

    newnode -> rlink = before -> rlink;
    before -> rlink -> llink = newnode;

}

//���� ���Ḯ��Ʈ ����
void Delete (Node* removed) {

    removed -> llink -> rlink = removed -> rlink;
    removed -> rlink -> llink = removed -> llink;
    free(removed);

}

Node* SearchNode (Node* phead, Node* ptail, int insert_data) {

    Node* p;
    for (p = phead-> rlink; p == ptail; p = p -> rlink ) {

        if (p -> data == insert_data) {

            return p;
        }

    }
}

int main() {

    Node* phead = (Node*)malloc(sizeof(Node));
    Node* ptail = (Node*)malloc(sizeof(Node));
    int select;
    int data;
    int before_data;

    Init(phead, ptail);
    
    //0���� 10������ �����͸� ���� ��� ����
    for (int i=0; i<10; i++) {
        
        Insert(phead,i);

    }
    PrintList(phead,ptail);

    printf("��� �߰� : 1�� Ŭ��\n");
    printf("��� ���� : 2�� Ŭ��\n");
    scanf("%d",&select);

    if (select == 1) {

        printf("�߰��� ����� �����͸� �Է��ϼ��� : ");
        scanf("%d",&data);
        printf("� ����� �ڿ� �߰��� ���ΰ���? ");
        scanf("%d",&before_data);
        Node* before_node = SearchNode(phead,ptail,before_data);
        Insert(before_node, data);

    }else if (select == 2) {

        printf("������ ����� �����͸� �Է��ϼ��� : ");
        scanf("%d",&data);
        Node* delete_node = SearchNode(phead, ptail, data);
        Delete(delete_node);

    }

    PrintList(phead,ptail);

    
}








