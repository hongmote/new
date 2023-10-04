#ifndef SEQLIST_H
#define SEQLIST_H


typedef  int ElemType;
#define N 10
typedef struct{
    ElemType *Data;
    int length;
    int lengthSize;
}SeqList;
//??????
void InitList(SeqList &L){
    L.Data=(ElemType *)malloc(sizeof(ElemType) * N);
    L.length=0;
    L.lengthSize=N;
}
//?????
void ChuList(SeqList &L){
    
    for(int i=0;i<L.lengthSize;i++){
        if(i==3)
        {
            L.Data[i]=L.lengthSize-3;
        }else if(i==6)
        {
            L.Data[i]=L.lengthSize-2;
        }else
        {
            L.Data[i]=i;
        }
        L.length=L.lengthSize;
    }
}
//??
int insert(ElemType e,int index,SeqList &L){
    if(index<1||index>L.length)
    {
        return 0;
    }
    if(L.length>=L.lengthSize)//?????
    {
       ElemType *pNew=(ElemType *)malloc(sizeof(ElemType)*2*L.lengthSize);
       for(int i=0;i<L.length;i++){
            pNew[i]=L.Data[i];
       }
       free(L.Data);
       L.Data=pNew; 
       L.lengthSize=2*L.length;
    }
    for(int i=L.length-1;i>=index-1;i--){
        L.Data[i+1]=L.Data[i];
    }
    L.Data[index-1]=e;
    L.length+=1;
    return 1;
}
//????
int Delete(int index,SeqList &L,ElemType e){
    if(index<1||index>L.length)
    return 0;
    for(int i=index;i<L.length;i++){
            L.Data[i-1]=L.Data[i];
    }
    --L.length;
    return 1;
}
//????
void print(SeqList L){
    printf("????: %d,????: %d??: ",L.length,L.lengthSize);
    for(int i=0;i<L.length;i++){
        printf("%d ",L.Data[i]);
    }
    printf("\n");
}
#endif