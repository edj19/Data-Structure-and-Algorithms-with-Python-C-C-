#include <stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INIT_SIZE 10  //��ʼ����
#define INCREMENT_SIZE 5  //��������

typedef int Status;
typedef int Elemtype;

/*
�洢�ṹ
*/
typedef struct
{
    Elemtype *elem;
    int length;
    int size;
}Sqlist;

/*
��ʼ��һ���յ����Ա�
*/
Status InitList(Sqlist *L)
{
    L->elem = (Elemtype *)malloc(INIT_SIZE*sizeof(Elemtype));
    if(!L->elem)
    {
        return ERROR;
    }
    L->length = 0;
    L->size = INIT_SIZE;
    return OK;
}
/*
�������Ա�
*/
Status DestroyList(Sqlist *L)
{
    free(L->elem);
    L->length = 0;
    L->size = 0;
    return OK;
}
/*
�ж����Ա��Ƿ�Ϊ��
*/
Status isEmpty(const Sqlist L)
{
    if(0==L.length)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*
��ȡ����
*/
Status getLength(const Sqlist L)
{
    return L.length;
}
/*
����λ�û�ȡԪ��
*/
Status GetElem(const Sqlist L,int i,Elemtype *e)
{
    if(i<1 || i>L.length)
    {
        return ERROR;
    }
    *e = L.elem[i-1];
    return OK;
}
/*
�Ƚ�����Ԫ���Ƿ����
*/
Status compare(Elemtype e1,Elemtype e2)
{
    if(e1==e2)
    {
        return 0;
    }
    else if(e1<e2)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
/*
����Ԫ��
*/
Status FindElem(const Sqlist L,Elemtype e,Status (*compare)(Elemtype,Elemtype))
{
    int i;
    for(i=0;i<L.length;i++)
    {
        if(!(*compare)(L.elem[i],e))
        {
            return i+1;
        }
    }
    if(i>=L.length)
    {
        return ERROR;
    }
}
/*
����ǰ��Ԫ��
*/
Status PreElem(const Sqlist L,Elemtype cur_e,Elemtype *pre_e)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        if(cur_e == L.elem[i])
        {
            if(i != 0)
            {
                *pre_e = L.elem[i-1];
            }
            else
            {
                return ERROR;
            }
        }
    }
    if(i>=L.length)
    {
        return ERROR;
    }
}
/*
���Һ��Ԫ��
*/
Status NextElem(const Sqlist L,Elemtype cur_e,Elemtype *next_e)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        if(cur_e == L.elem[i])
        {
            if(i<L.length-1)
            {
                *next_e = L.elem[i+1];
                return OK;
            }
            else
            {
                return ERROR;
            }
        }
    }
    if(i>=L.length)
    {
        return ERROR;
    }
}
/*
����Ԫ��
*/
Status InsertElem(Sqlist *L,int i,Elemtype e)
{
    Elemtype *new1;
    if(i<1 || i>L->length+1)
    {
        return ERROR;
    }
    if(L->length >=L->size)
    {
        new1 = (Elemtype*)realloc(L->elem,(L->size+INCREMENT_SIZE)*sizeof(Elemtype));
        if(!new1)
        {
            return ERROR;
        }
        L->elem = new1;
        L->size += INCREMENT_SIZE;
    }
    Elemtype *p = &L->elem[i-1];
    Elemtype *q = &L->elem[L->length-1];
    for(;q>=p;q--)
    {
        *(q+1) = *q;
    }
    *p = e;
    ++L->length;
    return OK;
}

/*
ɾ��Ԫ�ز�������ֵ
*/
Status DeleteElem(Sqlist *L,int i,Elemtype *e)
{
    if(i<1 || i>L->length)
    {
        return ERROR;
    }
    Elemtype *p = &L->elem[i-1];
    *e = *p;
    for(;p<&L->elem[L->length];p++)
    {
        *(p) = *(p+1);
    }
    --L->length;
    return OK;
}

/*
����Ԫ��
*/
void visit(Elemtype e)
{
    printf("%d",e);
}

/*
�������Ա�
*/
Status TraverseList(const Sqlist L,void(*visit)(Elemtype))
{
    int i;
    for(i=0;i<L.length;i++)
    {
        visit(L.elem[i]);
    }
    return OK;
}

/*
����������
*/
int main()
{
    Sqlist L;
    if(InitList(&L))
    {
        Elemtype e;
        printf("init_success\n");
        int i;
        for(i=0;i<10;i++)
        {
            InsertElem(&L,i+1,i);
        }
        printf("length is %d\n",getLength(L));
        if(GetElem(L,1,&e))
        {
            printf("The first element is %d\n",e);
        }
        else{
            printf("element is not exist\n");
        }
        if(isEmpty(L))
        {
            printf("list is empty\n");
        }
        else{
            printf("List is not empty\n");
        }
        printf("The 5 is at %d\n",FindElem(L,5,*compare));
        PreElem(L,6,&e);
        printf("The 6's previous element is %d\n",e);
        NextElem(L,6,&e);
        printf("The 6's next element is %d\n",e);
        DeleteElem(&L,1,&e);
        printf("delete first element is %d\n",e);
        printf("list:");
        TraverseList(L,visit);
        if(DestroyList(&L))
        {
            printf("\ndestory_success\n");
        }
    }
    return 0;
}
