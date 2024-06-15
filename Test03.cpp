#include <stdio.h>
#include<stdlib.h>
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
         p2->next=NULL;  //切记：最后一个结点的next赋值为NULL
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
//删除链表中第index个结点。index从1开始。
//由于可能删除第一个结点，所以函数返回头指针给主调函数
struct student *deleteNode(struct student *head,int index)
{
    if(head == NULL) return NULL;
    if(index == 1)//只有一个元素
    {
        struct student *toDelete = head;
        head = head->next;
        free(toDelete);
        return head;
    }
    else if (index==0)return head;

    struct student *current = head;
    struct student *pre = NULL;
    int cnt=1;//计数
    //遍历 找到要删除节点的前一个节点
    while(cnt <index &&current !=NULL)
    {
        pre=current;
        current=current->next;
        cnt++;
    }
    //找到了要删除的
    if(current != NULL)
    {
        pre->next = current->next;//删除
        free(current);//释放内存
    }
    else
    {
        return head;//超出了链表范围
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

