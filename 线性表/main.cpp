#include <cstdio>
#include <malloc.h>
#define MaxSize 10

typedef int ElemType;
typedef struct {
    ElemType data[MaxSize + 1];
    int length;
}SqList;

void InitList(SqList *&L){//初始化一个空列表
    L=(SqList*) malloc(sizeof(SqList));
    L->length=0;
}

bool ListInsert(SqList *&L, int i, ElemType e){//插入一个元素
    if(i<1 || i>L->length+1 || L->length==MaxSize)
        return false;
    for(int j=L->length;j>=i;j--)
        L->data[j]=L->data[j-1];
    L->data[i-1]=e;L->length++;
    return true;
}

int ListLength(SqList *L){//线性表长度
    return (L->length);
}

void CreatList(SqList* &L,  int n){//创建一个线性表
    L = (SqList *)malloc(sizeof(SqList));
    for(int i=0;i<n;i++){
        scanf("%d",&L->data[i]);
    }
    L->length=n;
    printf("success!\n");
}

void DisList(SqList*L){//输出线性表
    if(L->length ==0) return;
    for(int i=0;i<L->length;i++){
        printf("%d\n",L->data[i]);
    }
}
bool GetElem(SqList *L, int i, ElemType &e){//获得第i个位置的元素值
    if(i<1 && i>L->length)
        return false;
    e=L->data[i-1];
    return true;
}

bool ListEmpty(SqList*L){//判断线性表是否为空
    if(L->length==0) return true;
    else return false;
}

int LocateElem(SqList*L,ElemType e){//找到和e相等值的位置
    int i =1;
    while(i<=L->length && L->data[i-1]!=e)
        i++;
    if(i>L->length)
        return 0;
    else return i;
}

bool ListDelete(SqList &L,int i){//删除第i个位置的元素
    if(i<1 || i>L.length) return false;
    else{
        for(int j=i;j<L.length;j++){
            L.data[j-1]=L.data[j];
        }
        L.length--;
    }
    return true;
}

int main(){
    SqList *L;
    int a[5]={5,4,8,2,0};
    CreatList(L,5);
    DisList(L);
    ListDelete(*L,3);
    DisList(L);
}
