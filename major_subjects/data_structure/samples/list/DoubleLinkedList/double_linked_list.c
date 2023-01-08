# include <stdio.h>
# include <stdlib.h>

//��� ����
typedef struct DLL_Node {

    int data;
    struct DLL_Node* llink;
    struct DLL_Node* rlink;

}Node;

Node* phead;
Node* ptail;
int size;

//���� ���Ḯ��Ʈ �ʱ�ȭ
void Init () {

    phead = (Node*)malloc(sizeof(Node));
    ptail = (Node*)malloc(sizeof(Node));

    phead -> llink = phead;
    phead -> rlink = ptail;

    
    ptail -> llink = phead;
    ptail -> rlink = ptail;

    size = 0;

}

//���� ���Ḯ��Ʈ ����
int InsertAfter (int value, Node* before) {

    if (before == ptail) {
        
        printf("���� �ڿ��� ����X");
        return 0;

    }

    Node* newnode = (Node*)malloc(sizeof(Node));

    newnode -> data = value;

    before -> rlink -> llink = newnode;
    newnode -> rlink = before -> rlink;
    newnode -> llink = before;
    before -> rlink = newnode;

    size++;

}

int InsertBefore (int value, Node* after) {

    if (after == phead) {

        printf("�Ӹ� �տ��� ����X");
        return 0;

    }

    Node* newnode = (Node*)malloc(sizeof(Node));

    newnode -> data = value;
    after -> llink -> rlink = newnode;
    newnode -> llink = after -> llink;
    newnode -> rlink = after;
    after -> llink = newnode;

    size++;

}

//���� ���Ḯ��Ʈ ����
int DeleteNode (Node* removed) {

    if (removed == phead || removed == ptail) {

        printf("�Ӹ��� ������ ���� �� �����ϴ�.");
        return 0;
    }

    removed -> llink -> rlink = removed -> rlink;
    removed -> rlink -> llink = removed -> llink;
    free(removed);
    size--;

}

void DeleteAll () {

    Node* temp = phead -> rlink;
    Node* delete_node;

    while (temp != ptail) {

        delete_node = temp;
        temp = temp -> rlink;
        free(delete_node);

    }
    size = 0;
    phead -> rlink = ptail;
    ptail -> llink = phead;

    printf("Finish Delete All");
}

//value ���� Node ã��
Node* SearchNode (int value) {

    Node* p = phead -> rlink;
    
    while (p != ptail) {

        if (p -> data == value) {

            
            return p;
        }
        p = p -> rlink;
    }

    printf("ã�� ��尡 �����ϴ�.");
    return p;
}

//���� ���Ḯ��Ʈ ���
void PrintList () {

    Node* p = phead -> rlink;
    if (p == ptail) printf("�� ����Ʈ\n");

    while (p != ptail) {

        printf(" |%d| ", p -> data);
        p = p -> rlink;

    }
    printf("\n\n");

}



int main() {

    

    Init();

    InsertAfter(10,phead);
    InsertAfter(20,SearchNode(10));
    InsertAfter(30,SearchNode(20));
    InsertAfter(40,SearchNode(30));
    PrintList();
    //10, 20, 30, 40

    DeleteNode(SearchNode(30));
    DeleteNode(SearchNode(10));
    PrintList();
    //20, 40

    InsertBefore(11,SearchNode(20));
    InsertBefore(31,SearchNode(40));
    PrintList();
    //21,20,31,40
    
   
    DeleteAll();
    
}








