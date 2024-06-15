#include <stdio.h>
#include<stdlib.h>
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
         p2->next=NULL;  //�мǣ����һ������next��ֵΪNULL
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
//ɾ�������е�index����㡣index��1��ʼ��
//���ڿ���ɾ����һ����㣬���Ժ�������ͷָ�����������
struct student *deleteNode(struct student *head,int index)
{
    if(head == NULL) return NULL;
    if(index == 1)//ֻ��һ��Ԫ��
    {
        struct student *toDelete = head;
        head = head->next;
        free(toDelete);
        return head;
    }
    else if (index==0)return head;

    struct student *current = head;
    struct student *pre = NULL;
    int cnt=1;//����
    //���� �ҵ�Ҫɾ���ڵ��ǰһ���ڵ�
    while(cnt <index &&current !=NULL)
    {
        pre=current;
        current=current->next;
        cnt++;
    }
    //�ҵ���Ҫɾ����
    if(current != NULL)
    {
        pre->next = current->next;//ɾ��
        free(current);//�ͷ��ڴ�
    }
    else
    {
        return head;//����������Χ
    }
    return head;
}
int main()
{
    struct student *head;
    int index;
         head=createByTail();
         while(scanf("%d", &index) != -1)
    {
        head=deleteNode(head, index);
        displayLink(head);
    }
}

