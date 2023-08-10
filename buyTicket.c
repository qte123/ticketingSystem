#define _CRT_SECURE_NO_WARNINGS
//引入头文件 
#include<stdio.h>   
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>


//管理员账号(常量，不能修改)
const char user[10]="admin";
//管理员密码(常量，不能修改) 
const char password[18]="123456";


//定义film结构体，并用typedef将struct film类型改变成film类型 
typedef struct film { 
	char filmName[30]; //电影名字
	char filmTime[40]; //开演时间
	int roomNumber; //放映厅号
}film;
///定义ticket结构体,并用 typedef将struct ticket类型改变成ticket类型 
typedef struct ticket {
	char filmName[30]; //电影名字
	char filmTime[40]; //开演时间
	int roomNumber; //放映厅号
	int seatNumber;  //座位号
}ticket;
//将ticket类型改变成DataType类型 （原来的类型还是存在的） 
typedef ticket DataType;
//将film类型改变成DataType1类型 
typedef film DataType1;
//这是ticket链表节点 
//定义Node结构体，并用typedef将struct Node类型改变成SLNode
typedef struct Node {
	DataType data;       //数据域 
	struct Node *next;   //指针域 
}SLNode;
//这是film链表节点 
//定义Node1结构体，并用typedef将struct Node类型改变成SLNode1 
typedef struct Node1 {
	DataType1 data;      //数据域 
	struct Node1 *next;  //指针域 
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

void ListInitiate(SLNode **head) {    //定义ticket链表初始化函数 
	*head = (SLNode*)malloc(sizeof(SLNode));  //动态生成一个节点 
	(*head)->next = NULL;                     //生成的新节点指向NULL 
}

void ListInitiate1(SLNode1 **head) {  //定义film链表初始化函数 
	*head = (SLNode1*)malloc(sizeof(SLNode1));  //动态生成一个节点 
	(*head)->next = NULL;                       //生成的新节点指向NULL 
}

int ListLength(SLNode *head) {       //求ticket链表的长度 
	SLNode *p = head;
	int size = 0;
	while (p->next != NULL) {        //遍历链表元素 
		p = p->next;
		size++;                       //个数加一 
	}
	return size;
}

int ListLength1(SLNode1 *head) {    //求film链表的长度 
	SLNode1 *p = head;
	int size = 0;
	while (p->next != NULL) {         //遍历链表元素 
		p = p->next;
		size++;                      //个数加一 
	}
	return size;
}

int ListInsert(SLNode *head, int i, DataType x) {    //定义添加ticket链表节点函数 
	SLNode *p, *q;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && j < i - 1) {//遍历链表元素 
		p = p->next;
		j++;
	}
	if (j != i - 1) {
		printf("添加电影票位置错！\n");
		return 0;
	}
	q = (SLNode *)malloc(sizeof(SLNode));              //动态生成一个新节点 
	q->data = x;
	q->next = p->next;
	p->next = q;
	return 1;
}

int ListInsert1(SLNode1 *head, int i, DataType1 x) {  //定义添加film链表节点函数 
	SLNode1 *p, *q;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && j < i - 1) {//遍历链表元素 
		p = p->next;
		j++;
	}
	if (j != i - 1) {
		printf("添加电影参数错！\n");
		return 0;
	}
	q = (SLNode1 *)malloc(sizeof(SLNode1));             //动态生成一个新节点 
	q->data = x;
	q->next = p->next;
	p->next = q;
	return 1;
}

int ListDelete(SLNode *head, int i, DataType *x) {     //定义删除ticket链表节点函数 
	SLNode *p, *s;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && p->next != NULL && j < i - 1) {//遍历链表元素 
		p = p->next;
		j++;
	}
	if (j != i - 1) {
		printf("删除电影票位置参数错！\n");
		return 0;
	}
	s = p->next;
	*x = s->data;
	p->next = p->next->next;
	free(s);                                           //释放内存空间 
	return 1;
}

int ListDelete1(SLNode1 *head, int i, DataType1 *x) { //定义删除film链表节点函数 
	SLNode1 *p, *s;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && p->next != NULL && j < i - 1) {//遍历链表元素 
		p = p->next;
		j++;
	}
	if (j != i - 1) {
		printf("删除电影位置参数错！\n");
		return 0;
	}
	s = p->next;
	*x = s->data;
	p->next = p->next->next;
	free(s);                       //释放内存空间 
	return 1;
}

int ListGet(SLNode *head, int i, DataType *x) {    //定义获取ticket链表节点的数据函数 
	SLNode *p;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && j < i) {//遍历链表元素 
		p = p->next;
		j++;
	}
	if (j != i) {
		printf("获取电影票位置参数错！\n");
		return 0;
	}
	*x = p->data;
	return 1;
}

int ListGet1(SLNode1 *head, int i, DataType1 *x) {    //定义获取film链表节点的数据函数 
	SLNode1 *p;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && j < i) {//遍历链表元素 
		p = p->next;
		j++;
	}
	if (j != i) {
		printf("获取电影位置参数错！\n");
		return 0;
	}
	*x = p->data;
	return 1;
}

void Destroy(SLNode **head) {  //销毁ticket链表 
	SLNode *p, *p1;
	p = *head;
	while (p != NULL) {
		p1 = p;
		p = p->next;
		free(p1); //释放内存空间 
	}
	*head = NULL;
}

void Destroy1(SLNode1 **head1) {//销毁film链表 
	SLNode1 *p, *p1;
	p = *head1;
	while (p != NULL) {
		p1 = p;
		p = p->next;
		free(p1);//释放内存空间 
	}
	*head1 = NULL;
}

void login(SLNode *head, SLNode1 *head1) {   //定义登录函数 
	char User[10], Password[18];
	int m = 3;
	while (1) {
		printf("========================================================================\n");
		printf("                             管理员账号登录\n");
		printf("========================================================================\n\n");
		printf("                              账号：");
	    gets(User);
		printf("                              密码：");	
		gets(Password);
		if (strcmp(user, User) == 0 && strcmp(password, Password) == 0) {
			system("cls");   //清屏 
			filmMenu(head, head1);
			break;
		}
		else {
			m--;
		    printf("                 输入账号或密码错误！还剩下%d次输入机会", m);
			Sleep(1000);
			system("cls");
		}
		if (m == 0) {
			system("cls");
		printf("                      3次输入错误！系统强制退出！");
			exit(0);//程序终止 
			break;
		}
	}
}

void ticketMenu(SLNode *head, SLNode1 *head1) {//定义主页面函数 
	int n;
	char c;
	while (1) {
		printf("========================================================================\n");
		printf("                                功能列表\n\n");
		printf("                             [0]查询电影票\n");
		printf("                             [1]更换电影票\n");
		printf("                             [2]购买电影票\n");
		printf("                             [3]退掉电影票\n");          
		printf("                             [4]返回主界面\n");                         
		printf("\n========================================================================\n");
		printf("请选择：");
		scanf(" %c",&c);
		n = c - '0';
		getchar();
		system("cls");
		switch (n) //选项选择 
		{
		case 0:searchTicket(head, head1); break;
		case 1:changeTicket(head, head1); break;
		case 2:buy(head, head1); break;
		case 3:returnTicket(head, head1); break;
		case 4:change(head, head1); break;
		default: {
			printf("输入选项有误！\n");
			Sleep(1000);
			system("cls"); };
		}
	}
}
void filmMenu(SLNode *head, SLNode1 *head1) {//定义主页面函数 
	int n;
	char c;
	while (1) {
		printf("========================================================================\n");
		printf("                                功能列表\n\n");
		printf("                             [0]查询电影\n");
		printf("                             [1]添加电影\n");
		printf("                             [2]删除电影\n");
		printf("                             [3]更改电影\n");
		printf("                             [4]返回主界面\n");          
		printf("\n========================================================================\n");
		printf("请选择：");
		scanf(" %c",&c);
		n = c - '0';
		getchar();
		system("cls");
		switch (n) //选项选择 
		{
		case 0:searchFilm(head, head1); break;
		case 1:insertFilm(head, head1); break;
		case 2:deleteFilm(head, head1); break;
		case 3:changeFilm(head, head1); break;
		case 4:change(head,head1);break;
		default: {
			printf("输入选项有误！\n");
			Sleep(1000);
			system("cls"); };
		}
	}
}
void searchTicket(SLNode *head, SLNode1 *head1) {//查找电影票函数 
	int i,k;
	char c;
	ticket x;
	while (1)
	{
		printf("========================================================================\n");
		printf("                            已售出的电影票\n\n");
		if (ListLength(head) == 0) 
			printf("                            无售出的电影票！\n");
		for (i = 0; i < ListLength(head); i++)
		{
			ListGet(head, i, &x);
			printf("    电影名：%s 放映时间：%s 放映厅号：%d 座位号：%d\n", x.filmName, x.filmTime, x.roomNumber, x.seatNumber);
		}
		printf("\n                              [0]返回主页\n");
		printf("========================================================================\n");
		printf("请选择：");
		scanf(" %c", &c);
		k = c - '0';
		getchar();
		if (k == 0) {
			system("cls");
			ticketMenu(head, head1);
			break;
		}
		else {
			printf("输入选项有误！\n");
			Sleep(1000);
			system("cls");
		}
	}
}

void searchFilm(SLNode *head, SLNode1 *head1) {//查找电影函数 
	int i,k;
	char c;
	film x;
	while (1)
	{
		printf("========================================================================\n");
		printf("                            正在上映的电影\n\n");
		if (ListLength1(head1) == 0) 
			printf("                            没有上映的电影！\n");
		for (i = 0; i < ListLength1(head1); i++)
		{
			ListGet1(head1, i, &x);
			printf("    电影名：%s 放映时间：%s 放映室号：%d\n", x.filmName, x.filmTime, x.roomNumber);
		}
		printf("\n                              [0]返回主页\n");
		printf("\n========================================================================\n");
		printf("请选择：");
		scanf(" %c", &c);
		k = c - '0';
		getchar();
		if (k == 0) {
			system("cls");
			filmMenu(head, head1);
			break;
		}
		else {
			printf("输入选项有误！\n");
			Sleep(1000);
			system("cls");
		}
	}
}

void buy(SLNode *head, SLNode1 *head1) {//购买电影票函数 
	int i,k;
	char c;
	film film, x;
	ticket ticket, y,t[100];
	while (1) {
		printf("========================================================================\n");
		printf("                            正在上映的电影\n\n");
		if (ListLength1(head1) == 0) {
			printf("                         无电影！即将返回主页");
			Sleep(1000);
			system("cls");
			break;
		}
		for (i = 0; i < ListLength1(head1); i++) {
			ListGet1(head1, i, &film);
			printf("    电影名：%s 放映时间：%s 放映室号：%d 编号：[%d]\n", film.filmName, film.filmTime, film.roomNumber, i + 1);
		}
		printf("\n========================================================================\n");
		printf("请选择电影场数：");
		scanf("%d", &i);
		getchar();
		if (ListGet1(head1, i - 1, &x)) {
			strcpy(y.filmName, x.filmName);
			strcpy(y.filmTime, x.filmTime);
			y.roomNumber = x.roomNumber;
			printf("请选择座位号：");
			scanf("%d", &y.seatNumber);
			getchar();
			printf("[1]购买电影票 [0]退出购票\n");
			printf("请选择：");
			scanf(" %c", &c);
			k = c - '0';
			getchar();
			for (i = 0; i < ListLength(head); i++) {
				ListGet(head, i, &ticket);
				//判断购买的电影票是否重复 
				if (strcmp(ticket.filmName, y.filmName) == 0 && strcmp(ticket.filmTime, y.filmTime) == 0 && ticket.seatNumber == y.seatNumber&&ticket.roomNumber == y.roomNumber) {
					k = -1;
					printf("所选电影票重复，请重新购买！\n");
					Sleep(1000);
				}
			}
			if (k == 1) {
				printf("购买成功！即将返回主面！\n");
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
				printf("输入选项有误！\n");
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

void returnTicket(SLNode *head, SLNode1 *head1) {//退电影票 
	int i,m,k;
	char c;
	ticket x,t[100];
	while (1)
	{
		printf("========================================================================\n");
		printf("                            已售出的电影票\n\n");
		if (ListLength(head) == 0) {
			printf("                         无售票！即将返回主页");
			Sleep(1000);
			system("cls");
			break;
		}
		for (i = 0; i < ListLength(head); i++)
		{
			ListGet(head, i, &x);
			printf("    电影名：%s 放映时间：%s 放映室号：%d 座位号：%d 编号：[%d]\n", x.filmName, x.filmTime, x.roomNumber, x.seatNumber, i + 1);
		}
		printf("\n========================================================================\n");
		printf("请选择电影票编号：");
		scanf("%d", &m);
		getchar();
		if (ListGet(head, m - 1, &x)) {
			printf("[1]退掉电影票 [0]返回主页\n");
			printf("请选择：");
			scanf(" %c", &c);
			k = c - '0';
			getchar();
			if (k == 1) {
				printf("退票成功！即将返回主面！\n");
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
				printf("输入选项有误！\n");
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

void changeTicket(SLNode *head, SLNode1 *head1) {   //更换电影票 
	int i,m, n,j = -1, k = -1,seatNumber;
	char c;
	ticket ticket, x,t[100];
	film film, y;
	while (1)
	{
		printf("========================================================================\n\n");
		printf("                            已售出的电影票\n\n");
		if (ListLength(head) == 0) {
			printf("                         无售票！即将返回主页");
			Sleep(1000);
			system("cls");
			break;
		}
		for (i = 0; i < ListLength(head); i++)
		{
			ListGet(head, i, &x);
			printf("    电影名：%s 放映时间：%s 放映室号：%d 座位号：%d 编号：[%d]\n", x.filmName, x.filmTime, x.roomNumber, x.seatNumber, i + 1);
		}
		printf("\n========================================================================\n");
		printf("请选择电影票编号：");
		scanf("%d", &m);
		getchar();
		if (ListGet(head, m - 1, &x)) {
			printf("[1]更换电影票 [0]返回主页\n");
			printf("请选择：");
			scanf(" %c", &c);
			k = c - '0';
			getchar();
			if (k == 1) {
				system("cls");
				printf("========================================================================\n\n");
				printf("                            正在上映的电影\n\n");
				for (i = 0; i < ListLength1(head1); i++) {
					ListGet1(head1, i, &film);
					printf("    电影名：%s 放映时间：%s 放映室号：%d 编号：[%d]\n", film.filmName, film.filmTime, film.roomNumber, i + 1);
				}
				printf("\n========================================================================\n");
				printf("请选择电影编号：");
				scanf("%d", &n);
				getchar();
				if (ListGet1(head1, n - 1, &y)) {
					printf("请输入座位号：");
					scanf("%d", &seatNumber);
					getchar();
					//判断更换的电影票是否重复 
					if (strcmp(x.filmName, y.filmName) == 0 && strcmp(x.filmTime, y.filmTime) == 0 && x.seatNumber == seatNumber && x.roomNumber == y.roomNumber)
					{
						k = -1;
						printf("所选电影票重复，请重新选择！\n");
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
				printf("更改成功！即将返回主页！\n");
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
				printf("输入选项有误！\n");
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

void insertFilm(SLNode *head, SLNode1 *head1) { //添加电影 
	film film, x,f[100];
	int k, i;
	char c;
	while (1) {
		printf("========================================================================\n\n");
		printf("                            正在上映的电影\n\n");
		if (ListLength(head) == 0) {
		printf("                                无售票！");
		}
		for (i = 0; i < ListLength1(head1); i++) {
			ListGet1(head1, i, &x);
			printf("    电影名：%s 放映时间：%s 放映室号：%d 编号：[%d]\n", x.filmName, x.filmTime, x.roomNumber, i + 1);
		}
		printf("\n========================================================================\n");
		printf("请输入电影名：");
		gets(film.filmName);
		printf("请输入放映时间：");
		gets(film.filmTime);
		printf("请输入放映室号：");
		scanf("%d", &film.roomNumber);
		getchar();
		printf("[1]添加电影 [0]返回主页\n");
		printf("请选择：");
		scanf(" %c", &c);
		k = c - '0';
		getchar();
		for (i = 0; i < ListLength1(head1); i++) {
			ListGet1(head1, i, &x);
			//判断添加的电影的档期是否已经存在与电影链表中 
			if (strcmp(x.filmName, film.filmName) == 0 && strcmp(x.filmTime, film.filmTime) == 0 && x.roomNumber == film.roomNumber) {
				k = -1;
				printf("所添加的电影重复，请重新添加！\n");
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
			printf("电影添加成功！即将返回主页");
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
			printf("输入选项有误！\n");
			Sleep(1000);
			system("cls");
		}
	}
}

void deleteFilm(SLNode *head, SLNode1 *head1) {   //删除电影 
	int i,m,k;
	char c;
	film x,f[100];
	while (1) {
		printf("========================================================================\n\n");
		printf("                            正在上映的电影\n\n");
		if (ListLength1(head1) == 0) {
			printf("                         无电影！即将返回主页");
			Sleep(1000);
			system("cls");
			break;
		}
		for (i = 0; i < ListLength1(head1); i++) {
			ListGet1(head1, i, &x);
			printf("    电影名：%s 放映时间：%s 放映室号：%d 编号：[%d]\n", x.filmName, x.filmTime, x.roomNumber, i + 1);
		}
		printf("\n========================================================================\n");
		printf("请选择电影编号：");
		scanf("%d", &m);
		getchar();
		if (ListGet1(head1, m - 1, &x)) {
			printf("[1]删除电影 [0]返回主页\n");
			printf("请选择：");
			scanf(" %c", &c);
			k = c - '0';
			getchar();
			if (k == 1) {
				printf("删除成功！即将返回主面！\n");
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
				printf("输入选项有误！\n");
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
		printf("                            正在上映的电影\n\n");
		if (ListLength1(head1) == 0) {
			printf("                         无电影！即将返回主页");
			Sleep(1000);
			system("cls");
			break;
		}
		for (i = 0; i < ListLength1(head1); i++) {
			ListGet1(head1, i, &x);
			printf("    电影名：%s 放映时间：%s 放映室号：%d 编号：[%d]\n", x.filmName, x.filmTime, x.roomNumber, i + 1);
		}
		printf("\n========================================================================\n");
		printf("请选择电影编号：");
		scanf("%d", &m);
		getchar();
		if (ListGet1(head1, m - 1, &x)) {
			printf("[1]修改电影 [0]返回主页\n");
			printf("请选择：");
			scanf(" %c", &c);
			k = c - '0';
			getchar();
			if (k == 1) {
				printf("请输入电影名：");
				gets(film.filmName);
				printf("请输入放映时间：");
				gets(film.filmTime);
				printf("请输入放映室号：");
				scanf("%d", &film.roomNumber);
				getchar();
				for (i = 0; i < ListLength1(head1); i++) {
					//判断是否存在重复 
					if (strcmp(x.filmName, film.filmName) == 0 && strcmp(x.filmTime, film.filmTime) == 0 && x.roomNumber == film.roomNumber) {
						k = -1;
						printf("所选电影重复，请重新选择！\n");
						Sleep(1000);
					}
				}
			}
			if (k == 1) {
				printf("修改成功！即将返回主面！\n");
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
				printf("输入选项有误！\n");
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

//写入ticket.csv文件 
int write_to_ticketCsv(int count, ticket *data)     //写数据到文件，文件名固定 入参为结构体和数量
{
	int i = 0;
	FILE *f = fopen("./ticket.csv", "w");
	if (f == NULL) return -1;
	for (i = 0; i < count; i++)
		fprintf(f, "%s,%s,%d,%d\n", data[i].filmName, data[i].filmTime, data[i].roomNumber, data[i].seatNumber);
	fclose(f);
	return 0;
}

//写入film.csv文件
int write_to_filmCsv(int count, film *data)     //写数据到文件，文件名固定 入参为结构体和数量
{
	int i = 0;
	FILE *f = fopen("./film.csv", "w");
	if (f == NULL) return -1;
	for (i = 0; i < count; i++)
		fprintf(f, "%s,%s,%d\n", data[i].filmName, data[i].filmTime, data[i].roomNumber);
	fclose(f);
	return 0;
}

//读取ticket.csv文件内容 
void get_from_ticketCsv(SLNode *head)     //从文件中获取数据，简单点直接写死
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


//读取film.csv文件内容 
void get_from_filmCsv(SLNode1 *head1)     //从文件中获取数据，简单点直接写死
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

//判断是否存在ticket.csv 
void ifTicket(){
	FILE *fp = fopen("./ticket.csv", "r");//读取ticket.csv,若不存在指针为NULL 
	if (NULL == fp){
		FILE *f = fopen("./ticket.csv", "w"); //不存在ticket.csv,则自动生成ticket.csv文件 
	}
}

//判断是否存在film.csv 
void ifFilm(){
	FILE *fp = fopen("./film.csv", "r");//读取film.csv,若不存在指针为NULL
	if (NULL == fp) {
		FILE *f = fopen("./film.csv", "w");//不存在film.csv,则自动生成film.csv文件 
	}
}
void change(SLNode *head, SLNode1 *head1){
	char c;
	int a;
	while (1) {
		printf("========================================================================\n\n");
		printf("                        *欢迎使用电影票管理系统*\n\n");
		printf("                        [0]管理员 [1]购票员\n\n");
		printf("========================================================================\n\n");
		printf("请选择：");
		scanf(" %c", &c);  //防止恶意输入字符 
		a = c - '0'; //结果为一个数字 
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
			printf("输入选项有误！\n");
			Sleep(1000); //1秒的时间 
			system("cls");
		}
	}
}
int main() {
	int a;
	char c;
	SLNode *head;//电影票链表头节点
	SLNode1 *head1;//电影链表头节点
	ticket t[1];
	film f[1];
	ListInitiate(&head);//对ticket链表初始化 
	ListInitiate1(&head1);//对film链表初始化 
	ifTicket();
	ifFilm();
	get_from_ticketCsv(head); //读取ticket.csv 
	get_from_filmCsv(head1);   //读取film.csv 
	while (1) {
		printf("========================================================================\n\n");
		printf("                        *欢迎使用电影票管理系统*\n\n");
		printf("                        [1]进入系统 [0]退出系统\n\n");
		printf("========================================================================\n\n");
		printf("请选择：");
		scanf(" %c", &c);  //防止恶意输入字符 
		a = c - '0'; //结果为一个数字 
		getchar();
		if (a == 1) {
			system("cls");
			change(head,head1);
			break;
		}
		else if (a == 0) {
			system("cls");
			printf("系统已退出！");
			exit(0);
			break;
		}
		else {
			printf("输入选项有误！\n");
			Sleep(1000); //1秒的时间 
			system("cls");
		}
	}
	Destroy(&head);  //销毁ticket链表 
	Destroy1(&head1);  //销毁film链表 
	return 0;
}
