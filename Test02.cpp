#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;
struct student
{
	int  num;
	struct student  *next;
};
//�Ӽ��̶������ݴ��������½����뵽β��
struct student *createByTail()
{
	struct student *head;
	struct student *p1,*p2;
	int n;
	n=0;
	p1=p2=(struct student*)malloc(sizeof(struct student));
	scanf("%d",&p1->num);
	head=NULL;  //����������Ϊ������
	while(p1->num!=-1)    //numΪ-1����ζ���û��������
	{
		n=n+1;
		if(n==1)            //������һ�����
			head=p1;
		else
			p2->next=p1;
		p2=p1;            //p2ʼ��ָ�����һ����㣨��βָ�룩
		p1=(struct student*)malloc(sizeof(struct student)); //p1ָ���½��
        scanf("%d",&p1->num);
	}
	p2->next=NULL;  //���һ������next��ֵΪNULL
	return head;
}
//��������е���Ϣ��num��
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
//�������е�index������sָ����ָ��Ľ�㡣index��1��ʼ��
//���ڿ��ܲ��ڵ�һ����㣬���Ժ�������ͷָ�����������
struct student *insertNode(struct student *head, struct student *s, int index)
{
    // ���indexΪ1��˵��Ҫ����������ͷ��
    if (index == 1) {
        s->next = head; // ���½���nextָ��ԭͷ���
        return s;       // �����½����Ϊ�µ�ͷ���
    }

    // ����һ��p��㣬���ڴ������λ�ò���ͷ�������
    struct student p;
    p.next = head; // p����nextָ��ԭͷ���

    struct student *current = &p; // current��p��㿪ʼ
    int currentPos = 0; // ��ǰλ�ü���

    // ��������ֱ���ҵ�����λ�û�����β��
    while (current->next != NULL && currentPos < index - 1) {
        current = current->next;
        currentPos++;
    }

    // ���currentPos������index-1��˵��index����������Χ
    if (currentPos != index - 1) {
        // ����λ����Ч������ԭʼ����ͷָ��
        return head;
    }

    // �����½��
    s->next = current->next; // �½���nextָ��current����һ�����
    current->next = s;       // current��nextָ���½��

    return p.next; // ����p������һ����㣬���µ�ͷ���
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

