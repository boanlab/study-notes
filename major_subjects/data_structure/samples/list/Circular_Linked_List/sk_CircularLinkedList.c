#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode * insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	
	if (head == NULL) {
		head = node;
		node->link = head; // ������ ��尡 �����ٸ� ���Ե� ù ��° ����� ��ũ�� �ڱ� �ڽ��� ����Ű�� �Ѵ�. 
	}
	
	else {
		node->link = head->link;
		head->link = node;
	}
	
	return head; // ����� head ������ ��ȯ 
}

ListNode * insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	
	if (head == NULL) {
		head = node;
		node->link = head; // ������ ��尡 �����ٸ� ���Ե� ù ��° ����� ��ũ�� �ڱ� �ڽ��� ����Ű�� �Ѵ�. 
	}
	
	else {
		node->link = head->link;
		head->link = node;
		head = node; // head�� ��ġ�� ���ο� ���� �ٲپ� ���ο� ��尡 ������ ��尡 �ǰ� �Ѵ�. 
	}
	
	return head; // ����� head ������ ��ȯ 
}

void print(ListNode* head) {
	ListNode* n = head->link;
	
	if (head == NULL) return;
	
	do {
		printf("%d -> ", n->data);
		n = n->link;
	}while(n != head);
	
	printf("%d\n", n->data);
	printf("\n");
}

int main() {
	ListNode* head = NULL;
	
	head = insert_last(head, 13);
	head = insert_last(head, 15);
	head = insert_first(head, 12);
	print(head);
	
}
