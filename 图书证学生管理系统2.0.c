#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
char e;
/*提醒用户是否确认自己的操作*/
#define OK do{\
printf("是否本人操作?(c/q):");\
getchar();\
scanf("%c",&e);\
}while(0);
 
/*图书证学生信息结构*/
typedef struct node
{
    char name[20];//姓名
    int number;//学号
    struct node* next;
}Node, * LinkList;
 
/*初始化链表*/
LinkList InitList()
{
    LinkList head;
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}
 
/*判断重复信息*/
int judge(LinkList head,int number1,char name1[])
{
    Node*p=head;
    while(p)
    {
        if(strcmp(p->name,name1)==0&&p->number==number1)
        {
            printf("全部重复");
            return 0;
        }
        else if(p->number==number1)
        {
            printf("id");
            return 0;
        }
        else if(strcmp(p->name,name1)==0)
        {
            printf("姓名");
            return 0;
        }
        p=p->next;
    }
    return 1;
}
 
/*判断重复id*/
int judge_id(LinkList head,int number1)
{
    Node*p=head;
    while(p)
    {
        if(p->number==number1)
        {
            printf("id重复！\n");
            return 0;
        }
        p=p->next;
    }
    return 1;
}
 
/*判断重名*/
int judge_name(LinkList head,char name1[])
{
    Node*p=head;
    while(p)
    {
        if(strcmp(p->name,name1)==0)
        {
            printf("姓名重复 !\n");
            return 0;
        }
        p=p->next;
    }
    return 1;
}
 
/*/尾创链表*/
void CreatByRear(LinkList head)
{
    Node*r, *s;
    char name[20];
    int number;
    r = head;
    OK;
    if(e=='c'||e=='C')
    {
        printf("请输入所添加的信息:\n");
        scanf("%s", name);
        scanf("%d", &number);
        if (number == 0)//当输入学号为0时退出输入
            return;
        s = (Node*)malloc(sizeof(Node));
        strcpy(s->name, name);
        s->number = number;
        r->next = s;
        r = s;
        while (1)
        {
            scanf("%s", name);
            scanf("%d", &number);
            if (number == 0)
                return;
            if(judge(head,number,name))
            {
                s = (Node*)malloc(sizeof(Node));
                strcpy(s->name, name);
                s->number = number;
                r->next = s;
                r = s;
            }
            else printf(" 重复! 请再次输入!\n");//学号和姓名均不可重复
        }
        r->next = NULL;
    }
    getchar();
}
 
 
/*插入学生信息*/
void Insert(LinkList head)
{
    char ok;
    int i,j,number;
    char name[20];
    Node* p=head, * s;
    OK;
    if(e=='c'||e=='C')
    {
        do
        {
            p=head;
            j=0;
            printf("请输入插入学生信息位置:");//输入插入位置
            scanf("%d", &i);
            while (j < i - 1 && p)
            {
                p = p->next;
                j++;
            }
            if (p)
            {
                printf("\n请输入学生信息:\n");
                scanf("%s", name);
                scanf("%d", &number);
                if (number == 0)
                    break;
                if(judge(head,number,name))
                {
                       s = (Node*)malloc(sizeof(Node));
                    strcpy(s->name, name);
                    s->number = number;
                    s->next = p->next;
                    p->next = s;
                    printf("已插入!\n");
                }
                else
                    printf(" 重复!\n");
            }
            else
                printf("无法查找到信息!\n");
            printf("是否继续?(yes/no):");
            getchar();
            scanf("%c",&ok);
        }while(ok=='yes');
    }
    getchar();
}
 
/*添加学生信息*/
void Add(LinkList head)
{
    char name[20];
    int number;
    char ok;
    Node* p=head, * s;
    OK;
    if(e=='c'||e=='C')
    {
        while (p && p->next)//每次都添加到当前学生信息到末尾
            p = p->next;
        if (p)
        {   
            do
            {
                printf("请输入学生信息:\n");
                scanf("%s", name);
                scanf("%d", &number);
                if (number == 0)
                    break;
                if(judge(head,number,name))
                {
                    s = (Node*)malloc(sizeof(Node));
                    strcpy(s->name, name);
                    s->number = number;
                    p->next = s;
                    s->next = NULL;
                    printf("添加成功!\n");
                    p=p->next;
                }
                else
                    printf(" 重复d!\n");
                printf("是否继续添加?(yes/no):");
                getchar();
                scanf("%c",&ok);
            }while(ok=='yes');
        }
        else printf("添加结束!\n");
    }
    getchar();
}
 
/*删除学生信息*/
void Delete(LinkList head)
{
    Node* p=head, * q;
    int j,pos;
    char ok;
    if(p==NULL||p->next==NULL)
    {
        printf("没有要删除的内容!\n");
        getchar();
        return;
    }
    OK;
    if(e=='c'||e=='C')
    {
        do
        {
            p=head;
            j=0;
            printf("请输入要删除的位置:");//要删除的学生位置
            scanf("%d", &pos);
            while (j < pos - 1 && p)                         
            {
                p = p->next;
                j++;
            }
            if (p == NULL || p->next == NULL)
                printf("\n位置错误!\n\n");
            else
            {
                q = p->next;
                p->next = q->next;
                free(q);
                printf("\n********已删除********\n\n");
            }
            printf("是否继续删除?(y/n):");
            getchar();
            scanf("%c",&ok);
        }while(ok=='yes');
    }
    getchar();
}
 
/*输出学生信息*/
void OutPut(LinkList head)
{
    Node* p;
    p = head->next; 
    if(!p)
        printf("没有!\n\n");
    else
    {
        printf("\n********信息是********\n");
        while (p)
        {
            printf("姓名: %s\n", p->name);
            printf("id: %d\n\n", p->number);
            p = p->next;
        }
    }
    getchar();
}
 
/*保存学生信息*/
void save(LinkList head)
{
    Node*p=head;
    FILE*fp;
    char filename[40];
    if(p==NULL||p->next==NULL)
    {
        printf("没有要保存的内容!\n");
        getchar();
        return;
    }
    OK;
}
 
/*查找学生信息*/
void Search(LinkList head)
{
    char name[20];
    char ok;
    Node*p=head;
    if(p==NULL||p->next==NULL)
    {
        printf("没有查找到内容!\n");
        getchar();
        return;
    }
    OK;
    if(e=='c'||e=='C')
    {
        do
        {
            printf("请输入姓名:");
            scanf("%s", name);
            p = head->next;
            while (p)
            {
                if (strcmp(p->name, name) != 0)
                    p = p->next;
                else
                    break;
            }
            if (p == NULL)
                printf("无法找到！\n\n");
            else
            {
                printf("--------信息是--------\n");
                printf("姓名: %s\n", p->name);
                printf("id: %d\n", p->number);
            }
            printf("是否继续查找?(y/n):");
            getchar();
            scanf("%c",&ok);
        }while(ok=='yes');
    }
    getchar();
}
 
/*学生总人数*/
void ListLength(LinkList head)
{
    int count = 0;
    Node* p = head->next;
    while (p)
    {
        count++;
        p = p->next;
    }
    printf("\n总数=%d\n\n", count);
    getchar();
}
 
/*交换姓名*/
void swapname(char *a,char*b)
{
    char c[20];
    strcpy(c,a);
    strcpy(a,b);
    strcpy(b,c);
}
 
/*交换序号*/
void swapid(int *a,int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
 
/*以学号排序*/
void Sort(LinkList head)
{
    Node*p=head->next,*t;
    int choice;
    if(p==NULL||p->next==NULL)
    {
        printf("没有东西要排序!\n");
        getchar();
        return;
    }
    OK;
    if(e=='c'||e=='C')
    {
        printf("选择:\n");
        printf("1.low->high. 2.high->low.\n");//可从小到大也可以从大到小排
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:if(p!=NULL&&p->next!=NULL)
                    {
                        for(p=head->next;p->next;p=p->next)
                        {
                            for(t=p->next;t;t=t->next)
                            {
                                if(p->number>t->number)
                                {
                                    swapname(p->name,t->name);
                                    swapid(&p->number,&t->number);
                                }
                            }
                        }
                        printf("成功!\n");
                    }
                    else printf("错误!\n");
                    break;
            case 2:if(p!=NULL&&p->next!=NULL)
                    {
                        for(p=head->next;p->next;p=p->next)
                        {
                            for(t=p->next;t;t=t->next)
                            {
                                if(p->number<t->number)
                                {
                                    swapname(p->name,t->name);
                                    swapid(&p->number,&t->number);
                                }
                            }
                        }
                        printf("成功!\n");
                    }
                    else printf("错误!\n");
                    break;
            default:printf("请做出正确的选择!\n");break;
        }
    }
    getchar();
}
 
/*修改学生信息*/
void Modify(LinkList head)
{
    int choice,id,number1;
    char name1[20];
    char ok;
    Node*p=head;
    if(p!=NULL&&p->next!=NULL)
    {
        OK;
        if(e=='c'||e=='C')
        {
            do
            {
                p=head;
                OutPut(head);
                printf("请输入id:");
                scanf("%d",&id);
                while (p)
                {
                    if (p->number != id)
                        p = p->next;
                    else
                        break;
                }
                if(p==NULL)
                {
                    printf("不存在!\n");
                    continue;
                }
                printf("\n1.修改id.\n");//修改学号
                printf("2.修改姓名.\n");//修改姓名
                printf("3.全部修改.\n");//都修改
                printf("做出选择:");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:printf("请输入新的id:");
                        scanf("%d",&number1);
                        if(judge_id(head,number1))
                        {
                            for(p=head->next;p;p=p->next)
                            {
                                if(id==p->number)
                                {
                                    p->number=number1;
                                    printf("id 改变!\n");
                                    break;
                                }
                            }
                        }
                        break;
                    case 2:printf("请输入新的姓名:");
                        scanf("%s",&name1);
                        if(judge_name(head,name1))
                        {                   
                            for(p=head->next;p;p=p->next)
                            {
                                if(id==p->number)
                                {
                                    strcpy(p->name,name1);
                                    printf("姓名改变!\n");
                                    break;
                                }
                            }
                        }
                        break;
                    case 3:printf("请输入新的姓名和学号:");
                        scanf("%s %d",name1,&number1);
                        if(judge(head,number1,name1))
                        {
                            for(p=head->next;p;p=p->next)
                            {
                                if(id==p->number)
                                {
                                    p->number=number1;
                                    strcpy(p->name,name1);
                                    printf("全部改变!\n");
                                    break;
                                }
                            }
                        }
                        else printf(" 重复!\n");
                        break;
                    default:printf("请做出正确的选择!\n");break;
                }
                printf("是否继续修改?(yes/no):");
                getchar();
                scanf("%c",&ok);
            }while(ok=='yes');
        }
    }
    else
    {
        printf("没有任何内容改变!\n");
        getchar();
        return;
    }
    getchar();
}
 
/*删除当前所有学生信息*/
void Clear(LinkList head)
{
    Node* p=head,*q;
    if(p==NULL||p->next==NULL)
    {
        printf("没有内容要删除!\n");
        getchar();
        return;
    }
    OK;
    if(e=='c'||e=='C')
    {
        p=head->next;
        while(p)  
        {
            q = p->next;
            free(p);
            p = q;
        }
        head->next = NULL;
        printf("已删除!\n");
    }
    getchar();
}
 
/*主函数*/
void main()
{
    Node* p;
    char op,flag;
    int cnt=0,jk=0;
    char name[20],pass[20];
    LinkList ha;
    ha = InitList();
    while(cnt<4)
    {
        printf("\n请输入用户密码:");//输入用户密码(四次机会)
        gets(pass);
        if(!strcmp(pass,"4444"))//初始密码4444 
        {
            printf("\n\n ****欢迎来到图书证学生管理系统****\n\n");
            printf("         请按 \"enter\" 继续\n\n");
            while (1)
            {
                getchar();
                printf("------------------------------------------------\n");
                printf("1.创    建.    \t");
                printf("2.插入学生信息.\t");
                printf("3.添加学生信息.\n");
                printf("4.删除学生信息.\t");
                printf("5.查找学生信息.\t");
                printf("6.以学号排序.  \t\n");
                printf("7.学生总人数.  \t");
                printf("8.输出学生信息.\t");
                printf("9.修改学生信息.\n");
                printf("c.删除当前所有学生信息.\t");
                printf("s.保存学生信息.\t\n");
                printf("------------------------------------------------\n");
                printf("\n请做出选择:");
                scanf("%c", &flag);
                switch (flag)
                {
                    case '1':CreatByRear(ha);
                        break;
                    case '2':Insert(ha);
                        break;
                    case '3':Add(ha);
                        break;
                    case '4':Delete(ha);
                        break;
                    case '5':Search(ha);
                        break;
                    case '6':Sort(ha);
                        break;
                    case '7':ListLength(ha);
                        break;
                    case '8':OutPut(ha);
                        break;
                    case '9':Modify(ha);
                        break;
                    case 'c':Clear(ha);
                        break;
                        getchar();
                        scanf("%c",&op);
                        if(op=='yes')
                        {
                            jk=1;
                            printf("\next!\n\n");
                        }
                        else if(op=='n');
                        else printf("请做出正确的选择!\n");
                        break;
                    case 's':save(ha);
                        break;
                    default:printf("请做出正确的选择!\n");
                        getchar();
                        break;
                }
                if(jk) break;
            }
            if(jk) break;
        }
        if(cnt<3)
        {
            printf("密码错误! 还剩 %d 次机会!\n",(3-cnt));
            cnt++;
        }
        else
        {
            printf("没有机会!\n");
            break;
        }
    }
}

