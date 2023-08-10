#define _CRT_SECURE_NO_WARNINGS
//����ͷ�ļ� 
#include<stdio.h>   
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>


//����Ա�˺�(�����������޸�)
const char user[10]="admin";
//����Ա����(�����������޸�) 
const char password[18]="123456";


//����film�ṹ�壬����typedef��struct film���͸ı��film���� 
typedef struct film { 
	char filmName[30]; //��Ӱ����
	char filmTime[40]; //����ʱ��
	int roomNumber; //��ӳ����
}film;
///����ticket�ṹ��,���� typedef��struct ticket���͸ı��ticket���� 
typedef struct ticket {
	char filmName[30]; //��Ӱ����
	char filmTime[40]; //����ʱ��
	int roomNumber; //��ӳ����
	int seatNumber;  //��λ��
}ticket;
//��ticket���͸ı��DataType���� ��ԭ�������ͻ��Ǵ��ڵģ� 
typedef ticket DataType;
//��film���͸ı��DataType1���� 
typedef film DataType1;
//����ticket����ڵ� 
//����Node�ṹ�壬����typedef��struct Node���͸ı��SLNode
typedef struct Node {
	DataType data;       //������ 
	struct Node *next;   //ָ���� 
}SLNode;
//����film����ڵ� 
//����Node1�ṹ�壬����typedef��struct Node���͸ı��SLNode1 
typedef struct Node1 {
	DataType1 data;      //������ 
	struct Node1 *next;  //ָ���� 
}SLNode1;

void ListInitiate(SLNode **head);
void ListInitiate1(SLNode1 **head);
int ListLength(SLNode *head);
int ListLength1(SLNode1 *head);
int ListInsert(SLNode *head, int i, DataType x);
int ListInsert1(SLNode1 *head, int i, DataType1 x);
int ListDelete(SLNode *head, int i, DataType *x);
int ListDelete1(SLNode1 *head, int i, DataType1 *x);
int ListGet(SLNode *head, int i, DataType *x);
int ListGet1(SLNode1 *head, int i, DataType1 *x);
void Destroy(SLNode **head);
void Destroy1(SLNode1 **head);
void login(SLNode *head, SLNode1 *head1);
void ticketMenu(SLNode *head, SLNode1 *head1);
void filmMenu(SLNode *head, SLNode1 *head1);
void searchTicket(SLNode *head, SLNode1 *head1);
void searchFilm(SLNode *head, SLNode1 *head1);
void buy(SLNode *head, SLNode1 *head1);
void returnTicket(SLNode *head, SLNode1 *head1);
void changeTicket(SLNode *head, SLNode1 *head1);
void insertFilm(SLNode *head, SLNode1 *head1);
void deleteFilm(SLNode *head, SLNode1 *head1);
void changeFilm(SLNode *head, SLNode1 *head1);
int write_to_ticketCsv(int count, ticket *data);
int write_to_filmCsv(int count, film *data);
void get_from_ticketCsv(SLNode *head);
void get_from_filmCsv(SLNode1 *head1);
void ifTicket();
void ifFilm();
void change(SLNode *head, SLNode1 *head1);

void ListInitiate(SLNode **head) {    //����ticket�����ʼ������ 
	*head = (SLNode*)malloc(sizeof(SLNode));  //��̬����һ���ڵ� 
	(*head)->next = NULL;                     //���ɵ��½ڵ�ָ��NULL 
}

void ListInitiate1(SLNode1 **head) {  //����film�����ʼ������ 
	*head = (SLNode1*)malloc(sizeof(SLNode1));  //��̬����һ���ڵ� 
	(*head)->next = NULL;                       //���ɵ��½ڵ�ָ��NULL 
}

int ListLength(SLNode *head) {       //��ticket����ĳ��� 
	SLNode *p = head;
	int size = 0;
	while (p->next != NULL) {        //��������Ԫ�� 
		p = p->next;
		size++;                       //������һ 
	}
	return size;
}

int ListLength1(SLNode1 *head) {    //��film����ĳ��� 
	SLNode1 *p = head;
	int size = 0;
	while (p->next != NULL) {         //��������Ԫ�� 
		p = p->next;
		size++;                      //������һ 
	}
	return size;
}

int ListInsert(SLNode *head, int i, DataType x) {    //�������ticket����ڵ㺯�� 
	SLNode *p, *q;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && j < i - 1) {//��������Ԫ�� 
		p = p->next;
		j++;
	}
	if (j != i - 1) {
		printf("��ӵ�ӰƱλ�ô�\n");
		return 0;
	}
	q = (SLNode *)malloc(sizeof(SLNode));              //��̬����һ���½ڵ� 
	q->data = x;
	q->next = p->next;
	p->next = q;
	return 1;
}

int ListInsert1(SLNode1 *head, int i, DataType1 x) {  //�������film����ڵ㺯�� 
	SLNode1 *p, *q;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && j < i - 1) {//��������Ԫ�� 
		p = p->next;
		j++;
	}
	if (j != i - 1) {
		printf("��ӵ�Ӱ������\n");
		return 0;
	}
	q = (SLNode1 *)malloc(sizeof(SLNode1));             //��̬����һ���½ڵ� 
	q->data = x;
	q->next = p->next;
	p->next = q;
	return 1;
}

int ListDelete(SLNode *head, int i, DataType *x) {     //����ɾ��ticket����ڵ㺯�� 
	SLNode *p, *s;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && p->next != NULL && j < i - 1) {//��������Ԫ�� 
		p = p->next;
		j++;
	}
	if (j != i - 1) {
		printf("ɾ����ӰƱλ�ò�����\n");
		return 0;
	}
	s = p->next;
	*x = s->data;
	p->next = p->next->next;
	free(s);                                           //�ͷ��ڴ�ռ� 
	return 1;
}

int ListDelete1(SLNode1 *head, int i, DataType1 *x) { //����ɾ��film����ڵ㺯�� 
	SLNode1 *p, *s;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && p->next != NULL && j < i - 1) {//��������Ԫ�� 
		p = p->next;
		j++;
	}
	if (j != i - 1) {
		printf("ɾ����Ӱλ�ò�����\n");
		return 0;
	}
	s = p->next;
	*x = s->data;
	p->next = p->next->next;
	free(s);                       //�ͷ��ڴ�ռ� 
	return 1;
}

int ListGet(SLNode *head, int i, DataType *x) {    //�����ȡticket����ڵ�����ݺ��� 
	SLNode *p;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && j < i) {//��������Ԫ�� 
		p = p->next;
		j++;
	}
	if (j != i) {
		printf("��ȡ��ӰƱλ�ò�����\n");
		return 0;
	}
	*x = p->data;
	return 1;
}

int ListGet1(SLNode1 *head, int i, DataType1 *x) {    //�����ȡfilm����ڵ�����ݺ��� 
	SLNode1 *p;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && j < i) {//��������Ԫ�� 
		p = p->next;
		j++;
	}
	if (j != i) {
		printf("��ȡ��Ӱλ�ò�����\n");
		return 0;
	}
	*x = p->data;
	return 1;
}

void Destroy(SLNode **head) {  //����ticket���� 
	SLNode *p, *p1;
	p = *head;
	while (p != NULL) {
		p1 = p;
		p = p->next;
		free(p1); //�ͷ��ڴ�ռ� 
	}
	*head = NULL;
}

void Destroy1(SLNode1 **head1) {//����film���� 
	SLNode1 *p, *p1;
	p = *head1;
	while (p != NULL) {
		p1 = p;
		p = p->next;
		free(p1);//�ͷ��ڴ�ռ� 
	}
	*head1 = NULL;
}

void login(SLNode *head, SLNode1 *head1) {   //�����¼���� 
	char User[10], Password[18];
	int m = 3;
	while (1) {
		printf("========================================================================\n");
		printf("                             ����Ա�˺ŵ�¼\n");
		printf("========================================================================\n\n");
		printf("                              �˺ţ�");
	    gets(User);
		printf("                              ���룺");	
		gets(Password);
		if (strcmp(user, User) == 0 && strcmp(password, Password) == 0) {
			system("cls");   //���� 
			filmMenu(head, head1);
			break;
		}
		else {
			m--;
		    printf("                 �����˺Ż�������󣡻�ʣ��%d���������", m);
			Sleep(1000);
			system("cls");
		}
		if (m == 0) {
			system("cls");
		printf("                      3���������ϵͳǿ���˳���");
			exit(0);//������ֹ 
			break;
		}
	}
}

void ticketMenu(SLNode *head, SLNode1 *head1) {//������ҳ�溯�� 
	int n;
	char c;
	while (1) {
		printf("========================================================================\n");
		printf("                                �����б�\n\n");
		printf("                             [0]��ѯ��ӰƱ\n");
		printf("                             [1]������ӰƱ\n");
		printf("                             [2]�����ӰƱ\n");
		printf("                             [3]�˵���ӰƱ\n");          
		printf("                             [4]����������\n");                         
		printf("\n========================================================================\n");
		printf("��ѡ��");
		scanf(" %c",&c);
		n = c - '0';
		getchar();
		system("cls");
		switch (n) //ѡ��ѡ�� 
		{
		case 0:searchTicket(head, head1); break;
		case 1:changeTicket(head, head1); break;
		case 2:buy(head, head1); break;
		case 3:returnTicket(head, head1); break;
		case 4:change(head, head1); break;
		default: {
			printf("����ѡ������\n");
			Sleep(1000);
			system("cls"); };
		}
	}
}
void filmMenu(SLNode *head, SLNode1 *head1) {//������ҳ�溯�� 
	int n;
	char c;
	while (1) {
		printf("========================================================================\n");
		printf("                                �����б�\n\n");
		printf("                             [0]��ѯ��Ӱ\n");
		printf("                             [1]��ӵ�Ӱ\n");
		printf("                             [2]ɾ����Ӱ\n");
		printf("                             [3]���ĵ�Ӱ\n");
		printf("                             [4]����������\n");          
		printf("\n========================================================================\n");
		printf("��ѡ��");
		scanf(" %c",&c);
		n = c - '0';
		getchar();
		system("cls");
		switch (n) //ѡ��ѡ�� 
		{
		case 0:searchFilm(head, head1); break;
		case 1:insertFilm(head, head1); break;
		case 2:deleteFilm(head, head1); break;
		case 3:changeFilm(head, head1); break;
		case 4:change(head,head1);break;
		default: {
			printf("����ѡ������\n");
			Sleep(1000);
			system("cls"); };
		}
	}
}
void searchTicket(SLNode *head, SLNode1 *head1) {//���ҵ�ӰƱ���� 
	int i,k;
	char c;
	ticket x;
	while (1)
	{
		printf("========================================================================\n");
		printf("                            ���۳��ĵ�ӰƱ\n\n");
		if (ListLength(head) == 0) 
			printf("                            ���۳��ĵ�ӰƱ��\n");
		for (i = 0; i < ListLength(head); i++)
		{
			ListGet(head, i, &x);
			printf("    ��Ӱ����%s ��ӳʱ�䣺%s ��ӳ���ţ�%d ��λ�ţ�%d\n", x.filmName, x.filmTime, x.roomNumber, x.seatNumber);
		}
		printf("\n                              [0]������ҳ\n");
		printf("========================================================================\n");
		printf("��ѡ��");
		scanf(" %c", &c);
		k = c - '0';
		getchar();
		if (k == 0) {
			system("cls");
			ticketMenu(head, head1);
			break;
		}
		else {
			printf("����ѡ������\n");
			Sleep(1000);
			system("cls");
		}
	}
}

void searchFilm(SLNode *head, SLNode1 *head1) {//���ҵ�Ӱ���� 
	int i,k;
	char c;
	film x;
	while (1)
	{
		printf("========================================================================\n");
		printf("                            ������ӳ�ĵ�Ӱ\n\n");
		if (ListLength1(head1) == 0) 
			printf("                            û����ӳ�ĵ�Ӱ��\n");
		for (i = 0; i < ListLength1(head1); i++)
		{
			ListGet1(head1, i, &x);
			printf("    ��Ӱ����%s ��ӳʱ�䣺%s ��ӳ�Һţ�%d\n", x.filmName, x.filmTime, x.roomNumber);
		}
		printf("\n                              [0]������ҳ\n");
		printf("\n========================================================================\n");
		printf("��ѡ��");
		scanf(" %c", &c);
		k = c - '0';
		getchar();
		if (k == 0) {
			system("cls");
			filmMenu(head, head1);
			break;
		}
		else {
			printf("����ѡ������\n");
			Sleep(1000);
			system("cls");
		}
	}
}

void buy(SLNode *head, SLNode1 *head1) {//�����ӰƱ���� 
	int i,k;
	char c;
	film film, x;
	ticket ticket, y,t[100];
	while (1) {
		printf("========================================================================\n");
		printf("                            ������ӳ�ĵ�Ӱ\n\n");
		if (ListLength1(head1) == 0) {
			printf("                         �޵�Ӱ������������ҳ");
			Sleep(1000);
			system("cls");
			break;
		}
		for (i = 0; i < ListLength1(head1); i++) {
			ListGet1(head1, i, &film);
			printf("    ��Ӱ����%s ��ӳʱ�䣺%s ��ӳ�Һţ�%d ��ţ�[%d]\n", film.filmName, film.filmTime, film.roomNumber, i + 1);
		}
		printf("\n========================================================================\n");
		printf("��ѡ���Ӱ������");
		scanf("%d", &i);
		getchar();
		if (ListGet1(head1, i - 1, &x)) {
			strcpy(y.filmName, x.filmName);
			strcpy(y.filmTime, x.filmTime);
			y.roomNumber = x.roomNumber;
			printf("��ѡ����λ�ţ�");
			scanf("%d", &y.seatNumber);
			getchar();
			printf("[1]�����ӰƱ [0]�˳���Ʊ\n");
			printf("��ѡ��");
			scanf(" %c", &c);
			k = c - '0';
			getchar();
			for (i = 0; i < ListLength(head); i++) {
				ListGet(head, i, &ticket);
				//�жϹ���ĵ�ӰƱ�Ƿ��ظ� 
				if (strcmp(ticket.filmName, y.filmName) == 0 && strcmp(ticket.filmTime, y.filmTime) == 0 && ticket.seatNumber == y.seatNumber&&ticket.roomNumber == y.roomNumber) {
					k = -1;
					printf("��ѡ��ӰƱ�ظ��������¹���\n");
					Sleep(1000);
				}
			}
			if (k == 1) {
				printf("����ɹ��������������棡\n");
				Sleep(1000);
				system("cls");
				ListInsert(head, ListLength(head), y);
				for (i = 0; i < ListLength(head); i++) {
					ListGet(head, i, &t[i]);
				}
				write_to_ticketCsv(ListLength(head),t);
				ticketMenu(head, head1);
				break;
			}
			else if (k == 0) {
				system("cls");
				ticketMenu(head, head1);
				break;
			}
			else {
				printf("����ѡ������\n");
				Sleep(1000);
				system("cls");
			}
		}
		else {
			Sleep(1000);
			system("cls");
		}
	}
}

void returnTicket(SLNode *head, SLNode1 *head1) {//�˵�ӰƱ 
	int i,m,k;
	char c;
	ticket x,t[100];
	while (1)
	{
		printf("========================================================================\n");
		printf("                            ���۳��ĵ�ӰƱ\n\n");
		if (ListLength(head) == 0) {
			printf("                         ����Ʊ������������ҳ");
			Sleep(1000);
			system("cls");
			break;
		}
		for (i = 0; i < ListLength(head); i++)
		{
			ListGet(head, i, &x);
			printf("    ��Ӱ����%s ��ӳʱ�䣺%s ��ӳ�Һţ�%d ��λ�ţ�%d ��ţ�[%d]\n", x.filmName, x.filmTime, x.roomNumber, x.seatNumber, i + 1);
		}
		printf("\n========================================================================\n");
		printf("��ѡ���ӰƱ��ţ�");
		scanf("%d", &m);
		getchar();
		if (ListGet(head, m - 1, &x)) {
			printf("[1]�˵���ӰƱ [0]������ҳ\n");
			printf("��ѡ��");
			scanf(" %c", &c);
			k = c - '0';
			getchar();
			if (k == 1) {
				printf("��Ʊ�ɹ��������������棡\n");
				Sleep(1000);
				system("cls");
				ListDelete(head, m - 1, &x);
				for (i = 0; i < ListLength(head); i++) {
					ListGet(head, i, &t[i]);
				}
				write_to_ticketCsv(ListLength(head), t);
				ticketMenu(head, head1);
				break;
			}
			else if (k == 0) {
				system("cls");
				ticketMenu(head, head1);
				break;
			}
			else {
				printf("����ѡ������\n");
				Sleep(1000);
				system("cls");
			}
		}
		else {
			Sleep(1000);
			system("cls");
		}
	}
}

void changeTicket(SLNode *head, SLNode1 *head1) {   //������ӰƱ 
	int i,m, n,j = -1, k = -1,seatNumber;
	char c;
	ticket ticket, x,t[100];
	film film, y;
	while (1)
	{
		printf("========================================================================\n\n");
		printf("                            ���۳��ĵ�ӰƱ\n\n");
		if (ListLength(head) == 0) {
			printf("                         ����Ʊ������������ҳ");
			Sleep(1000);
			system("cls");
			break;
		}
		for (i = 0; i < ListLength(head); i++)
		{
			ListGet(head, i, &x);
			printf("    ��Ӱ����%s ��ӳʱ�䣺%s ��ӳ�Һţ�%d ��λ�ţ�%d ��ţ�[%d]\n", x.filmName, x.filmTime, x.roomNumber, x.seatNumber, i + 1);
		}
		printf("\n========================================================================\n");
		printf("��ѡ���ӰƱ��ţ�");
		scanf("%d", &m);
		getchar();
		if (ListGet(head, m - 1, &x)) {
			printf("[1]������ӰƱ [0]������ҳ\n");
			printf("��ѡ��");
			scanf(" %c", &c);
			k = c - '0';
			getchar();
			if (k == 1) {
				system("cls");
				printf("========================================================================\n\n");
				printf("                            ������ӳ�ĵ�Ӱ\n\n");
				for (i = 0; i < ListLength1(head1); i++) {
					ListGet1(head1, i, &film);
					printf("    ��Ӱ����%s ��ӳʱ�䣺%s ��ӳ�Һţ�%d ��ţ�[%d]\n", film.filmName, film.filmTime, film.roomNumber, i + 1);
				}
				printf("\n========================================================================\n");
				printf("��ѡ���Ӱ��ţ�");
				scanf("%d", &n);
				getchar();
				if (ListGet1(head1, n - 1, &y)) {
					printf("��������λ�ţ�");
					scanf("%d", &seatNumber);
					getchar();
					//�жϸ����ĵ�ӰƱ�Ƿ��ظ� 
					if (strcmp(x.filmName, y.filmName) == 0 && strcmp(x.filmTime, y.filmTime) == 0 && x.seatNumber == seatNumber && x.roomNumber == y.roomNumber)
					{
						k = -1;
						printf("��ѡ��ӰƱ�ظ���������ѡ��\n");
						Sleep(1000);
					}
					strcpy(ticket.filmName, x.filmName);
					strcpy(ticket.filmTime, x.filmTime);
					ticket.roomNumber = x.roomNumber;
					ticket.seatNumber = seatNumber;
				}
				else {
					k = -1;
				}
			}
			if (k == 1) {
				printf("���ĳɹ�������������ҳ��\n");
				Sleep(1000);
				system("cls");
				ListDelete(head, m - 1, &x);
				ListInsert(head, m - 1, ticket);
				for (i = 0; i < ListLength(head); i++) {
					ListGet(head, i, &t[i]);
				}
				write_to_ticketCsv(ListLength(head), t);
				ticketMenu(head, head1);
				break;
			}
			else if (k == 0) {
				system("cls");
				ticketMenu(head, head1);
				break;
			}
			else {
				printf("����ѡ������\n");
				Sleep(1000);
				system("cls");
			}
		}
		else {
			Sleep(1000);
			system("cls");
		}
	}
}

void insertFilm(SLNode *head, SLNode1 *head1) { //��ӵ�Ӱ 
	film film, x,f[100];
	int k, i;
	char c;
	while (1) {
		printf("========================================================================\n\n");
		printf("                            ������ӳ�ĵ�Ӱ\n\n");
		if (ListLength(head) == 0) {
		printf("                                ����Ʊ��");
		}
		for (i = 0; i < ListLength1(head1); i++) {
			ListGet1(head1, i, &x);
			printf("    ��Ӱ����%s ��ӳʱ�䣺%s ��ӳ�Һţ�%d ��ţ�[%d]\n", x.filmName, x.filmTime, x.roomNumber, i + 1);
		}
		printf("\n========================================================================\n");
		printf("�������Ӱ����");
		gets(film.filmName);
		printf("�������ӳʱ�䣺");
		gets(film.filmTime);
		printf("�������ӳ�Һţ�");
		scanf("%d", &film.roomNumber);
		getchar();
		printf("[1]��ӵ�Ӱ [0]������ҳ\n");
		printf("��ѡ��");
		scanf(" %c", &c);
		k = c - '0';
		getchar();
		for (i = 0; i < ListLength1(head1); i++) {
			ListGet1(head1, i, &x);
			//�ж���ӵĵ�Ӱ�ĵ����Ƿ��Ѿ��������Ӱ������ 
			if (strcmp(x.filmName, film.filmName) == 0 && strcmp(x.filmTime, film.filmTime) == 0 && x.roomNumber == film.roomNumber) {
				k = -1;
				printf("����ӵĵ�Ӱ�ظ�����������ӣ�\n");
				Sleep(1000);
			}
		}
		if (k == 1)
		{
			ListInsert1(head1, ListLength1(head1), film);
			for (i = 0; i < ListLength1(head1); i++) {
				ListGet1(head1, i, &f[i]);
			}
			write_to_filmCsv(ListLength1(head1), f);
			printf("��Ӱ��ӳɹ�������������ҳ");
			Sleep(1000);
			system("cls");
			filmMenu(head, head1);
			break;
		}
		else if (k == 0) {
			system("cls");
			filmMenu(head, head1);
			break;
		}
		else {
			printf("����ѡ������\n");
			Sleep(1000);
			system("cls");
		}
	}
}

void deleteFilm(SLNode *head, SLNode1 *head1) {   //ɾ����Ӱ 
	int i,m,k;
	char c;
	film x,f[100];
	while (1) {
		printf("========================================================================\n\n");
		printf("                            ������ӳ�ĵ�Ӱ\n\n");
		if (ListLength1(head1) == 0) {
			printf("                         �޵�Ӱ������������ҳ");
			Sleep(1000);
			system("cls");
			break;
		}
		for (i = 0; i < ListLength1(head1); i++) {
			ListGet1(head1, i, &x);
			printf("    ��Ӱ����%s ��ӳʱ�䣺%s ��ӳ�Һţ�%d ��ţ�[%d]\n", x.filmName, x.filmTime, x.roomNumber, i + 1);
		}
		printf("\n========================================================================\n");
		printf("��ѡ���Ӱ��ţ�");
		scanf("%d", &m);
		getchar();
		if (ListGet1(head1, m - 1, &x)) {
			printf("[1]ɾ����Ӱ [0]������ҳ\n");
			printf("��ѡ��");
			scanf(" %c", &c);
			k = c - '0';
			getchar();
			if (k == 1) {
				printf("ɾ���ɹ��������������棡\n");
				Sleep(1000);
				system("cls");
				ListDelete1(head1, m - 1, &x);
				for (i = 0; i < ListLength1(head1); i++) {
					ListGet1(head1, i, &f[i]);
				}
				write_to_filmCsv(ListLength1(head1), f);
			filmMenu(head, head1);
				break;
			}
			else if (k == 0) {
				system("cls");
			filmMenu(head, head1);
				break;
			}
			else {
				printf("����ѡ������\n");
				Sleep(1000);
				system("cls");
			}
		}
		else {
			Sleep(1000);
			system("cls");
		}
	}
}

void changeFilm(SLNode *head, SLNode1 *head1) {
	int i,m,k = -1;
	film x, film,f[100];
	char c;
	while (1) {
		printf("========================================================================\n\n");
		printf("                            ������ӳ�ĵ�Ӱ\n\n");
		if (ListLength1(head1) == 0) {
			printf("                         �޵�Ӱ������������ҳ");
			Sleep(1000);
			system("cls");
			break;
		}
		for (i = 0; i < ListLength1(head1); i++) {
			ListGet1(head1, i, &x);
			printf("    ��Ӱ����%s ��ӳʱ�䣺%s ��ӳ�Һţ�%d ��ţ�[%d]\n", x.filmName, x.filmTime, x.roomNumber, i + 1);
		}
		printf("\n========================================================================\n");
		printf("��ѡ���Ӱ��ţ�");
		scanf("%d", &m);
		getchar();
		if (ListGet1(head1, m - 1, &x)) {
			printf("[1]�޸ĵ�Ӱ [0]������ҳ\n");
			printf("��ѡ��");
			scanf(" %c", &c);
			k = c - '0';
			getchar();
			if (k == 1) {
				printf("�������Ӱ����");
				gets(film.filmName);
				printf("�������ӳʱ�䣺");
				gets(film.filmTime);
				printf("�������ӳ�Һţ�");
				scanf("%d", &film.roomNumber);
				getchar();
				for (i = 0; i < ListLength1(head1); i++) {
					//�ж��Ƿ�����ظ� 
					if (strcmp(x.filmName, film.filmName) == 0 && strcmp(x.filmTime, film.filmTime) == 0 && x.roomNumber == film.roomNumber) {
						k = -1;
						printf("��ѡ��Ӱ�ظ���������ѡ��\n");
						Sleep(1000);
					}
				}
			}
			if (k == 1) {
				printf("�޸ĳɹ��������������棡\n");
				Sleep(1000);
				system("cls");
				ListDelete1(head1, m - 1, &x);
				ListInsert1(head1, m - 1, film);
				for (i = 0; i < ListLength1(head1); i++)
					ListGet1(head1, i, &f[i]);
				write_to_filmCsv(ListLength1(head1), f);
				filmMenu(head, head1);
				break;
			}
			else if (k == 0) {
				system("cls");
				filmMenu(head, head1);
				break;
			}
			else {
				printf("����ѡ������\n");
				Sleep(1000);
				system("cls");
			}
		}
		else {
			Sleep(1000);
			system("cls");
		}
	}
}

//д��ticket.csv�ļ� 
int write_to_ticketCsv(int count, ticket *data)     //д���ݵ��ļ����ļ����̶� ���Ϊ�ṹ�������
{
	int i = 0;
	FILE *f = fopen("./ticket.csv", "w");
	if (f == NULL) return -1;
	for (i = 0; i < count; i++)
		fprintf(f, "%s,%s,%d,%d\n", data[i].filmName, data[i].filmTime, data[i].roomNumber, data[i].seatNumber);
	fclose(f);
	return 0;
}

//д��film.csv�ļ�
int write_to_filmCsv(int count, film *data)     //д���ݵ��ļ����ļ����̶� ���Ϊ�ṹ�������
{
	int i = 0;
	FILE *f = fopen("./film.csv", "w");
	if (f == NULL) return -1;
	for (i = 0; i < count; i++)
		fprintf(f, "%s,%s,%d\n", data[i].filmName, data[i].filmTime, data[i].roomNumber);
	fclose(f);
	return 0;
}

//��ȡticket.csv�ļ����� 
void get_from_ticketCsv(SLNode *head)     //���ļ��л�ȡ���ݣ��򵥵�ֱ��д��
{
	ticket ticket;
	char tmp_buf[1024] = { 0 };
	FILE *fp = fopen("./ticket.csv", "r");
	while (fgets(tmp_buf, sizeof(tmp_buf), fp) > 0)
	{
		tmp_buf[1023] = 0;
		char * filmName = strtok(tmp_buf, ",");
		strcpy(ticket.filmName, filmName);
		char * filmTime = strtok(NULL, ",");
		strcpy(ticket.filmTime, filmTime);
		char *roomNumber = strtok(NULL, ",");
		int roomNumber1 = atoi(roomNumber);
		ticket.roomNumber = roomNumber1;
		char *seatNumber = strtok(NULL, ",");
		int seatNumber1 = atoi(seatNumber);
		ticket.seatNumber = seatNumber1;
		memset(tmp_buf, 0, sizeof(tmp_buf));
		ListInsert(head, ListLength(head), ticket);
	}
	fclose(fp);
	return;
}


//��ȡfilm.csv�ļ����� 
void get_from_filmCsv(SLNode1 *head1)     //���ļ��л�ȡ���ݣ��򵥵�ֱ��д��
{
	film film;
	char tmp_buf[1024] = { 0 };
	FILE *fp = fopen("./film.csv", "r");
	while (fgets(tmp_buf, sizeof(tmp_buf), fp) > 0)
	{
		tmp_buf[1023] = 0;
		char * filmName = strtok(tmp_buf, ",");
		strcpy(film.filmName, filmName);
		char * filmTime = strtok(NULL, ",");
		strcpy(film.filmTime, filmTime);
		char *roomNumber = strtok(NULL, ",");
		int roomNumber1 = atoi(roomNumber);
		film.roomNumber = roomNumber1;
		memset(tmp_buf, 0, sizeof(tmp_buf));
		ListInsert1(head1, ListLength1(head1), film);
	}
	fclose(fp);
	return;
}

//�ж��Ƿ����ticket.csv 
void ifTicket(){
	FILE *fp = fopen("./ticket.csv", "r");//��ȡticket.csv,��������ָ��ΪNULL 
	if (NULL == fp){
		FILE *f = fopen("./ticket.csv", "w"); //������ticket.csv,���Զ�����ticket.csv�ļ� 
	}
}

//�ж��Ƿ����film.csv 
void ifFilm(){
	FILE *fp = fopen("./film.csv", "r");//��ȡfilm.csv,��������ָ��ΪNULL
	if (NULL == fp) {
		FILE *f = fopen("./film.csv", "w");//������film.csv,���Զ�����film.csv�ļ� 
	}
}
void change(SLNode *head, SLNode1 *head1){
	char c;
	int a;
	while (1) {
		printf("========================================================================\n\n");
		printf("                        *��ӭʹ�õ�ӰƱ����ϵͳ*\n\n");
		printf("                        [0]����Ա [1]��ƱԱ\n\n");
		printf("========================================================================\n\n");
		printf("��ѡ��");
		scanf(" %c", &c);  //��ֹ���������ַ� 
		a = c - '0'; //���Ϊһ������ 
		getchar();
		if (a == 0) {
			system("cls");
			login(head, head1);
			break;
		}
		else if (a == 1) {
			system("cls");
			ticketMenu(head,head1);
			break;
		}
		else {
			printf("����ѡ������\n");
			Sleep(1000); //1���ʱ�� 
			system("cls");
		}
	}
}
int main() {
	int a;
	char c;
	SLNode *head;//��ӰƱ����ͷ�ڵ�
	SLNode1 *head1;//��Ӱ����ͷ�ڵ�
	ticket t[1];
	film f[1];
	ListInitiate(&head);//��ticket�����ʼ�� 
	ListInitiate1(&head1);//��film�����ʼ�� 
	ifTicket();
	ifFilm();
	get_from_ticketCsv(head); //��ȡticket.csv 
	get_from_filmCsv(head1);   //��ȡfilm.csv 
	while (1) {
		printf("========================================================================\n\n");
		printf("                        *��ӭʹ�õ�ӰƱ����ϵͳ*\n\n");
		printf("                        [1]����ϵͳ [0]�˳�ϵͳ\n\n");
		printf("========================================================================\n\n");
		printf("��ѡ��");
		scanf(" %c", &c);  //��ֹ���������ַ� 
		a = c - '0'; //���Ϊһ������ 
		getchar();
		if (a == 1) {
			system("cls");
			change(head,head1);
			break;
		}
		else if (a == 0) {
			system("cls");
			printf("ϵͳ���˳���");
			exit(0);
			break;
		}
		else {
			printf("����ѡ������\n");
			Sleep(1000); //1���ʱ�� 
			system("cls");
		}
	}
	Destroy(&head);  //����ticket���� 
	Destroy1(&head1);  //����film���� 
	return 0;
}
