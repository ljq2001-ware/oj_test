#include <bits/stdc++.h>
using namespace std;
typedef int Elemtype;
typedef struct node
{
    Elemtype data;
    struct node *next;
}LNode,*LinkList;
void Initlist(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
}
void InputList(LinkList &L,int n)
{
    LNode *p;//�����µĽ��
    LNode *r;//βָ��
    r=L;
    for(int i=1;i<=n;i++)
    {
        p= new LNode;
        cin>>p->data;
        //���½������β
        r->next=p;
        r=p;
    }
    r->next=NULL;//β����Ϊ��
}
void ShowList(LinkList L)
{
    LNode *p;//����ָ��
    p=L->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
void FindStu(LinkList L,int num)
{
    LNode *p;
    p=L->next;
    int i=1;
    while(p!=NULL)
    {
        if(p->data == num)
        {
            cout<<i<<endl;
            return;
        }
        else
        {
            p=p->next;
            i++;
        }
    }
    if(p==NULL) cout<<"no"<<endl;
}
int main()
{
    int n;
    cin>>n;
    LNode *head;
    Initlist(head);
    InputList(head,n);
    int num;
    while(cin>>num)
    {
        FindStu(head,num);
    }
    //ShowList(head);
    return 0;
}

