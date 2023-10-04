#include<stdio.h>
#include <iostream>
#include<malloc.h>
typedef  int ElemType;
#define N 10
typedef struct{
    ElemType *Data;
    int length;
    int lengthSize;
}SeqList;
//³õÊ¼»¯Ë³Ðò±í
void InitList(SeqList &L){
    L.Data=(ElemType *)malloc(sizeof(ElemType) * N);
    L.length=0;
    L.lengthSize=N;
}
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
int main(){


}