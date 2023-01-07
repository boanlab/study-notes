# include <stdio.h>
# include <stdlib.h>

//노드 정의
typedef struct DLL_Node {

    int data;
    struct DLL_Node* llink;
    struct DLL_Node* rlink;

}Node;

//이중 연결리스트 초기화
void Init (Node* phead, Node* ptail) {


    phead -> llink = phead;
    phead -> rlink = ptail;

    ptail -> llink = phead;
    ptail -> rlink = ptail;

}

//이중 연결리스트 출력
void PrintList (Node* phead, Node* ptail) {

    Node* p;

    for (p = phead-> rlink; p == ptail; p = p -> rlink ) {

        printf(" |%d| ", p -> data);

    }
    printf("\n");

}

//이중 연결리스트 삽입
void Insert (Node* before, int data) {

    Node* newnode = (Node*)malloc(sizeof(Node));

    newnode -> data = data;

    newnode -> llink = before;
    before -> rlink = newnode;

    newnode -> rlink = before -> rlink;
    before -> rlink -> llink = newnode;

}

//이중 연결리스트 삭제
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
    
    //0부터 10까지의 데이터를 가진 노드 삽입
    for (int i=0; i<10; i++) {
        
        Insert(phead,i);

    }
    PrintList(phead,ptail);

    printf("노드 추가 : 1번 클릭\n");
    printf("노드 삭제 : 2번 클릭\n");
    scanf("%d",&select);

    if (select == 1) {

        printf("추가할 노드의 데이터를 입력하세요 : ");
        scanf("%d",&data);
        printf("어떤 노드의 뒤에 추가할 것인가요? ");
        scanf("%d",&before_data);
        Node* before_node = SearchNode(phead,ptail,before_data);
        Insert(before_node, data);

    }else if (select == 2) {

        printf("삭제할 노드의 데이터를 입력하세요 : ");
        scanf("%d",&data);
        Node* delete_node = SearchNode(phead, ptail, data);
        Delete(delete_node);

    }

    PrintList(phead,ptail);

    
}








