#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
char e;
/*�����û��Ƿ�ȷ���Լ��Ĳ���*/
#define OK do{\
printf("�Ƿ��˲���?(c/q):");\
getchar();\
scanf("%c",&e);\
}while(0);
 
/*ͼ��֤ѧ����Ϣ�ṹ*/
typedef struct node
{
    char name[20];//����
    int number;//ѧ��
    struct node* next;
}Node, * LinkList;
 
/*��ʼ������*/
LinkList InitList()
{
    LinkList head;
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}
 
/*�ж��ظ���Ϣ*/
int judge(LinkList head,int number1,char name1[])
{
    Node*p=head;
    while(p)
    {
        if(strcmp(p->name,name1)==0&&p->number==number1)
        {
            printf("ȫ���ظ�");
            return 0;
        }
        else if(p->number==number1)
        {
            printf("id");
            return 0;
        }
        else if(strcmp(p->name,name1)==0)
        {
            printf("����");
            return 0;
        }
        p=p->next;
    }
    return 1;
}
 
/*�ж��ظ�id*/
int judge_id(LinkList head,int number1)
{
    Node*p=head;
    while(p)
    {
        if(p->number==number1)
        {
            printf("id�ظ���\n");
            return 0;
        }
        p=p->next;
    }
    return 1;
}
 
/*�ж�����*/
int judge_name(LinkList head,char name1[])
{
    Node*p=head;
    while(p)
    {
        if(strcmp(p->name,name1)==0)
        {
            printf("�����ظ� !\n");
            return 0;
        }
        p=p->next;
    }
    return 1;
}
 
/*/β������*/
void CreatByRear(LinkList head)
{
    Node*r, *s;
    char name[20];
    int number;
    r = head;
    OK;
    if(e=='c'||e=='C')
    {
        printf("����������ӵ���Ϣ:\n");
        scanf("%s", name);
        scanf("%d", &number);
        if (number == 0)//������ѧ��Ϊ0ʱ�˳�����
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
            else printf(" �ظ�! ���ٴ�����!\n");//ѧ�ź������������ظ�
        }
        r->next = NULL;
    }
    getchar();
}
 
 
/*����ѧ����Ϣ*/
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
            printf("���������ѧ����Ϣλ��:");//�������λ��
            scanf("%d", &i);
            while (j < i - 1 && p)
            {
                p = p->next;
                j++;
            }
            if (p)
            {
                printf("\n������ѧ����Ϣ:\n");
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
                    printf("�Ѳ���!\n");
                }
                else
                    printf(" �ظ�!\n");
            }
            else
                printf("�޷����ҵ���Ϣ!\n");
            printf("�Ƿ����?(yes/no):");
            getchar();
            scanf("%c",&ok);
        }while(ok=='yes');
    }
    getchar();
}
 
/*���ѧ����Ϣ*/
void Add(LinkList head)
{
    char name[20];
    int number;
    char ok;
    Node* p=head, * s;
    OK;
    if(e=='c'||e=='C')
    {
        while (p && p->next)//ÿ�ζ���ӵ���ǰѧ����Ϣ��ĩβ
            p = p->next;
        if (p)
        {   
            do
            {
                printf("������ѧ����Ϣ:\n");
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
                    printf("��ӳɹ�!\n");
                    p=p->next;
                }
                else
                    printf(" �ظ�d!\n");
                printf("�Ƿ�������?(yes/no):");
                getchar();
                scanf("%c",&ok);
            }while(ok=='yes');
        }
        else printf("��ӽ���!\n");
    }
    getchar();
}
 
/*ɾ��ѧ����Ϣ*/
void Delete(LinkList head)
{
    Node* p=head, * q;
    int j,pos;
    char ok;
    if(p==NULL||p->next==NULL)
    {
        printf("û��Ҫɾ��������!\n");
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
            printf("������Ҫɾ����λ��:");//Ҫɾ����ѧ��λ��
            scanf("%d", &pos);
            while (j < pos - 1 && p)                         
            {
                p = p->next;
                j++;
            }
            if (p == NULL || p->next == NULL)
                printf("\nλ�ô���!\n\n");
            else
            {
                q = p->next;
                p->next = q->next;
                free(q);
                printf("\n********��ɾ��********\n\n");
            }
            printf("�Ƿ����ɾ��?(y/n):");
            getchar();
            scanf("%c",&ok);
        }while(ok=='yes');
    }
    getchar();
}
 
/*���ѧ����Ϣ*/
void OutPut(LinkList head)
{
    Node* p;
    p = head->next; 
    if(!p)
        printf("û��!\n\n");
    else
    {
        printf("\n********��Ϣ��********\n");
        while (p)
        {
            printf("����: %s\n", p->name);
            printf("id: %d\n\n", p->number);
            p = p->next;
        }
    }
    getchar();
}
 
/*����ѧ����Ϣ*/
void save(LinkList head)
{
    Node*p=head;
    FILE*fp;
    char filename[40];
    if(p==NULL||p->next==NULL)
    {
        printf("û��Ҫ���������!\n");
        getchar();
        return;
    }
    OK;
}
 
/*����ѧ����Ϣ*/
void Search(LinkList head)
{
    char name[20];
    char ok;
    Node*p=head;
    if(p==NULL||p->next==NULL)
    {
        printf("û�в��ҵ�����!\n");
        getchar();
        return;
    }
    OK;
    if(e=='c'||e=='C')
    {
        do
        {
            printf("����������:");
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
                printf("�޷��ҵ���\n\n");
            else
            {
                printf("--------��Ϣ��--------\n");
                printf("����: %s\n", p->name);
                printf("id: %d\n", p->number);
            }
            printf("�Ƿ��������?(y/n):");
            getchar();
            scanf("%c",&ok);
        }while(ok=='yes');
    }
    getchar();
}
 
/*ѧ��������*/
void ListLength(LinkList head)
{
    int count = 0;
    Node* p = head->next;
    while (p)
    {
        count++;
        p = p->next;
    }
    printf("\n����=%d\n\n", count);
    getchar();
}
 
/*��������*/
void swapname(char *a,char*b)
{
    char c[20];
    strcpy(c,a);
    strcpy(a,b);
    strcpy(b,c);
}
 
/*�������*/
void swapid(int *a,int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
 
/*��ѧ������*/
void Sort(LinkList head)
{
    Node*p=head->next,*t;
    int choice;
    if(p==NULL||p->next==NULL)
    {
        printf("û�ж���Ҫ����!\n");
        getchar();
        return;
    }
    OK;
    if(e=='c'||e=='C')
    {
        printf("ѡ��:\n");
        printf("1.low->high. 2.high->low.\n");//�ɴ�С����Ҳ���ԴӴ�С��
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
                        printf("�ɹ�!\n");
                    }
                    else printf("����!\n");
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
                        printf("�ɹ�!\n");
                    }
                    else printf("����!\n");
                    break;
            default:printf("��������ȷ��ѡ��!\n");break;
        }
    }
    getchar();
}
 
/*�޸�ѧ����Ϣ*/
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
                printf("������id:");
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
                    printf("������!\n");
                    continue;
                }
                printf("\n1.�޸�id.\n");//�޸�ѧ��
                printf("2.�޸�����.\n");//�޸�����
                printf("3.ȫ���޸�.\n");//���޸�
                printf("����ѡ��:");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:printf("�������µ�id:");
                        scanf("%d",&number1);
                        if(judge_id(head,number1))
                        {
                            for(p=head->next;p;p=p->next)
                            {
                                if(id==p->number)
                                {
                                    p->number=number1;
                                    printf("id �ı�!\n");
                                    break;
                                }
                            }
                        }
                        break;
                    case 2:printf("�������µ�����:");
                        scanf("%s",&name1);
                        if(judge_name(head,name1))
                        {                   
                            for(p=head->next;p;p=p->next)
                            {
                                if(id==p->number)
                                {
                                    strcpy(p->name,name1);
                                    printf("�����ı�!\n");
                                    break;
                                }
                            }
                        }
                        break;
                    case 3:printf("�������µ�������ѧ��:");
                        scanf("%s %d",name1,&number1);
                        if(judge(head,number1,name1))
                        {
                            for(p=head->next;p;p=p->next)
                            {
                                if(id==p->number)
                                {
                                    p->number=number1;
                                    strcpy(p->name,name1);
                                    printf("ȫ���ı�!\n");
                                    break;
                                }
                            }
                        }
                        else printf(" �ظ�!\n");
                        break;
                    default:printf("��������ȷ��ѡ��!\n");break;
                }
                printf("�Ƿ�����޸�?(yes/no):");
                getchar();
                scanf("%c",&ok);
            }while(ok=='yes');
        }
    }
    else
    {
        printf("û���κ����ݸı�!\n");
        getchar();
        return;
    }
    getchar();
}
 
/*ɾ����ǰ����ѧ����Ϣ*/
void Clear(LinkList head)
{
    Node* p=head,*q;
    if(p==NULL||p->next==NULL)
    {
        printf("û������Ҫɾ��!\n");
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
        printf("��ɾ��!\n");
    }
    getchar();
}
 
/*������*/
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
        printf("\n�������û�����:");//�����û�����(�Ĵλ���)
        gets(pass);
        if(!strcmp(pass,"4444"))//��ʼ����4444 
        {
            printf("\n\n ****��ӭ����ͼ��֤ѧ������ϵͳ****\n\n");
            printf("         �밴 \"enter\" ����\n\n");
            while (1)
            {
                getchar();
                printf("------------------------------------------------\n");
                printf("1.��    ��.    \t");
                printf("2.����ѧ����Ϣ.\t");
                printf("3.���ѧ����Ϣ.\n");
                printf("4.ɾ��ѧ����Ϣ.\t");
                printf("5.����ѧ����Ϣ.\t");
                printf("6.��ѧ������.  \t\n");
                printf("7.ѧ��������.  \t");
                printf("8.���ѧ����Ϣ.\t");
                printf("9.�޸�ѧ����Ϣ.\n");
                printf("c.ɾ����ǰ����ѧ����Ϣ.\t");
                printf("s.����ѧ����Ϣ.\t\n");
                printf("------------------------------------------------\n");
                printf("\n������ѡ��:");
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
                        else printf("��������ȷ��ѡ��!\n");
                        break;
                    case 's':save(ha);
                        break;
                    default:printf("��������ȷ��ѡ��!\n");
                        getchar();
                        break;
                }
                if(jk) break;
            }
            if(jk) break;
        }
        if(cnt<3)
        {
            printf("�������! ��ʣ %d �λ���!\n",(3-cnt));
            cnt++;
        }
        else
        {
            printf("û�л���!\n");
            break;
        }
    }
}

