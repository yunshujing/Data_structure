#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node *next;
} LNode, *LinkList;
void print(LinkList head);
LinkList createTail();
LinkList createHead();
int length(LinkList head);
int insertAfter(LinkList head, int i, ElemType item);
int del(LinkList head, int i);
int insertBefore(LinkList head, int i, ElemType item);
char find(LinkList head, int i);
int main()
{
	printf("��ӭ�������������ϵͳ!\n");
	printf("1.��������-β�巨\n");
	printf("2.��������-ͷ�巨\n");
	printf("------------------------------------\n");
	printf("3.�������\n");
	printf("4.���������\n");
	printf("5.������ĵ�i���ڵ�����һ��������Ϊitem���½ڵ�\n");
	printf("6.ɾ������ĵ�i���ڵ�\n");
	printf("7.������ĵ�i���ڵ�ǰ����һ��������Ϊitem���½ڵ�\n");
	printf("8.��������ĵ�i�����\n");
	printf("9.Ԥ������3\n");
	printf("10.�˳�ϵͳ\n");
	int choice;
	LinkList head = NULL;
	while (~scanf("%d", &choice)){
		switch (choice){
		case 1:
			printf("1.��������-β�巨\n");
			head = createTail();
			break;
		case 2:
			printf("2.��������-ͷ�巨\n");
			head = createHead();
			break;
		case 3:
			printf("3.�������\n");
			print(head);
			break;
		case 4:
			printf("4.���������\n");
			printf("%d\n", length(head));
			break;
		case 5:
			printf("5.������ĵ�i���ڵ�����һ��������Ϊitem���½ڵ�\n");
			int i;
			ElemType item;
			scanf("%d %c", &i, &item);
			if (insertAfter(head, i, item) == 0){
				printf("����ʧ��\n");
			}
			else{
				printf("����ɹ�\n");
			}
			print(head);
			break;
		case 6:
			printf("6.ɾ������ĵ�i���ڵ�\n");
			scanf("%d", &i);
			if (del(head, i) == 0){
				printf("ɾ��ʧ��\n");
			}
			else{
				printf("ɾ���ɹ�\n");
			}
			print(head);
			break;
		case 7:
			printf("7.������ĵ�i���ڵ�ǰ����һ��������Ϊitem���½ڵ�\n");
			scanf("%d %c", &i, &item);
			if (insertBefore(head, i, item) == 0){
				printf("����ʧ��\n");
			}
			else{
				printf("����ɹ�\n");
			}
			print(head);
			break;
		case 8:
			printf("8.��������ĵ�i�����\n");
			scanf("%d", &i);
			if (i <= 0 || i > length(head)){
				printf("����ʧ��\n");
			}
			else{
				printf("%c\n", find(head, i));
			}
			break;
		case 10:
			printf("ϵͳ�����˳�����ӭ�ٴ�ʹ�ã�\n");
			break;
		}
		if (choice == 10){
			break;
		}
	}
	return 0;
}
void print(LinkList head)
{
	if (head == NULL){
		printf("����Ϊ�ձ�\n");
		return;
	}
	LinkList p = head;
	while (p->next != NULL){
		printf("%c->", p->data);
		p = p->next;
	}
	printf("%c\n", p->data);
}
LinkList createTail()
{
	LinkList head = NULL, tail, p;
	char ch;
	while (~scanf("%c", &ch)){
		if (ch == '#'){
			break;
		}
		if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n'){
			continue;
		}
		p = (LinkList)malloc(sizeof(LNode));
		p->data = ch;
		p->next = NULL;
		if (head == NULL){
			head = p;
		}
		else{
			tail->next = p;
		}
		tail = p;
	}
	return head;
}
LinkList createHead()
{
	LinkList head = NULL, tail, p;
	char ch;
	while (~scanf("%c", &ch)){
		if (ch == '#'){
			break;
		}
		if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n'){
			continue;
		}
		p = (LinkList)malloc(sizeof(LNode));
		p->data = ch;
		p->next = NULL;
		if (head == NULL){
			head = p;
		}
		else{
			p->next = head;
			head = p;
		}
	}
	return head;
}

int length(LinkList head)
{
	int len = 0;
	LinkList p = head;
	if (p == NULL)
		return 0;
	while (p->next != NULL){
		p = p->next;
		len++;
	}
	return len + 1;
}
int insertAfter(LinkList head, int i, ElemType item)
{
	if (i <= 0 || i > length(head))
		return 0;
	LinkList p = head, q;
	q = (LinkList)malloc(sizeof(LNode));
	int j = 1;
	while (j < i && p != NULL){
		p = p->next;
		j++;
	}
	q->data = item;
	q->next = p->next;
	p->next = q;
	return 1;
}
int del(LinkList head, int i)
{
	if (i <= 0 || i > length(head))
		return 0;
	LinkList p = head, q;
	q = (LinkList)malloc(sizeof(LNode));
	int j = 0;
	if (i == 1 && p != NULL){
		q = p->next;
		p->data = q->data;
		p->next = q->next;
		return 1;
	}
	while (j < i - 2 && p->next != NULL){
		p = p->next;
		j++;
	}
	q = p->next;
	p->next = q->next;
	return 1;
}
int insertBefore(LinkList head, int i, ElemType item)
{
	if (i <= 0 || i > length(head))
		return 0;
	LinkList p = head, q;
	q = (LinkList)malloc(sizeof(LNode));
	if (i == 1){
		q->data = p->data;
		q->next = p->next;
		p->data = item;
		p->next = q;
		return 1;
	}
	int j = 2;
	while (j < i && p != NULL){
		p = p->next;
		j++;
	}
	q->data = item;
	q->next = p->next;
	p->next = q;
	return 1;
}
char find(LinkList head, int i)
{
	LinkList p = head, q;
	i--;
	while (i--){
		p = p->next;
	}
	return p->data;
}
