#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<time.h>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    char data;
    struct node *next;
};
struct node* create(char text[])
{
    int i;
    struct node *current;//当前插入位置指针
    struct node *tail;//尾指针
    struct node *head;//头指针
    head = (struct node*)malloc(sizeof(struct node));//头结点
    head->next = NULL;
    current = head;//当前位置指针指向头结点
    tail = head;//尾指针也指向头结点
    for(i=0; i<strlen(text); i++)
    {
        if(text[i] == '[')
        {//当前位置指针回到最前面
            current = head;
        }
        else if (text[i] == ']')
        {//当前位置指针移到最后面
            current = tail;
        }
        else
        {//在当前位置指针后面插入结点
            struct node *p;
            p = (struct node*)malloc(sizeof(struct node));
            p->data = text[i];
            p->next = current->next;
            current->next = p;
            current = p;
            if(current->next == NULL) tail = current; //当前位置在最后面，则需要修改tail指针
        }
    }
    return head;
}
int count(struct node *head) {
    struct node *current = head->next; // 从头结点的下一个节点开始遍历
    int wordCount = 0; // 单词计数器
    int inWord = 0; // 标记是否在单词中

    // 跳过头结点，从第一个数据节点开始遍历
    while (current != NULL) {
        // 忽略非字母数字字符
        if (isalpha(current->data)) {
            if (!inWord) {
                // 如果之前不在单词中，现在遇到了单词的开始
                wordCount++; // 增加单词计数
                inWord = 1; // 更新标记，表示现在在单词中
            }
        } else {
            // 遇到非字母数字字符，单词结束
            inWord = 0;
        }
        current = current->next; // 移动到下一个节点
    }

    return wordCount;
}
int main()
{
    //freopen("input2.txt","r",stdin);
    //freopen("output2.txt", "w", stdout);
    char text[100005];
    struct node *head,*p;
    int num;
    while(gets(text)!=NULL)
    {
        head=create(text);
        //for(p=head->next; p!=NULL; p=p->next)
        //    printf("%c",p->data);
        //printf("\n");
        num=count(head);
        printf("%d\n",num);
    }

    //printf("%.2f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}

