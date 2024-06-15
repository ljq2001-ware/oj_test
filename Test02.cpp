#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;
struct student
{
	int  num;
	struct student  *next;
};
//从键盘读入数据创建链表，新结点插入到尾部
struct student *createByTail()
{
	struct student *head;
	struct student *p1,*p2;
	int n;
	n=0;
	p1=p2=(struct student*)malloc(sizeof(struct student));
	scanf("%d",&p1->num);
	head=NULL;  //首先置链表为空链表
	while(p1->num!=-1)    //num为-1，意味着用户输入结束
	{
		n=n+1;
		if(n==1)            //创建第一个结点
			head=p1;
		else
			p2->next=p1;
		p2=p1;            //p2始终指向最后一个结点（即尾指针）
		p1=(struct student*)malloc(sizeof(struct student)); //p1指向新结点
        scanf("%d",&p1->num);
	}
	p2->next=NULL;  //最后一个结点的next赋值为NULL
	return head;
}
//输出链表中的信息（num）
void  displayLink(struct student *head)
{
	struct student *p;
    p=head;
	printf("head-->");
	while(p!= NULL)
	{
		printf("%d-->",p->num);
		p=p->next;
	}
	printf("tail\n");
}
//在链表中第index处插入s指针所指向的结点。index从1开始。
//由于可能插在第一个结点，所以函数返回头指针给主调函数
struct student *insertNode(struct student *head, struct student *s, int index)
{
    // 如果index为1，说明要插入在链表头部
    if (index == 1) {
        s->next = head; // 将新结点的next指向原头结点
        return s;       // 返回新结点作为新的头结点
    }

    // 定义一个p结点，用于处理插入位置不在头部的情况
    struct student p;
    p.next = head; // p结点的next指向原头结点

    struct student *current = &p; // current从p结点开始
    int currentPos = 0; // 当前位置计数

    // 遍历链表直到找到插入位置或链表尾部
    while (current->next != NULL && currentPos < index - 1) {
        current = current->next;
        currentPos++;
    }

    // 如果currentPos不等于index-1，说明index超出了链表范围
    if (currentPos != index - 1) {
        // 插入位置无效，返回原始链表头指针
        return head;
    }

    // 插入新结点
    s->next = current->next; // 新结点的next指向current的下一个结点
    current->next = s;       // current的next指向新结点

    return p.next; // 返回p结点的下一个结点，即新的头结点
}
int main()
{
    struct student *head;
    int index,data;
	head=createByTail();
	while(scanf("%d%d", &index,&data) != -1)
    {
        struct student * s = (struct student *) malloc(sizeof(struct student));
        s->num = data;
        head=insertNode(head, s, index);
        displayLink(head);
    }
    return 0;
}

