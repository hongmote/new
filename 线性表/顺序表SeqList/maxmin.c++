//顺序表 A 和 B 的元素个数分别为 m 和 n ，表 A 升序排序，表 B 降序排序，两个表中都不存在相同的元素；★★★★
//(1）将两表合并，两表中的元素都存储到非递减表 C 中。
//(2）表 A 有 m + n 个存储空间，将 A 、 B 两表合并，所有元素都存储到A中；
//(3）表 A 前 r 个元素递增有序，而表 A 中后 n - r 个元素递减有序，将表 A 进行升序排序。

//(1）最小（最大）值法推断过程如下：有序的输入一处理过程中访问到有序序列一有序（非递减 or 非递增）的结果
//两个表中元素都有序，获得的结果也要求有序，那么在处理的过程中必然要求处理的序列有序，这样才能降低算法设计的难度。
#include "seqlist.h"//引用自己写的头函数
#include<malloc.h>
#include<algorithm>
using namespace std;

bool cmp(int x,int y){
    return x>y;
}
void andElem1(SeqList &A,SeqList &B,SeqList &C){
    C.Data=(ElemType *)malloc(sizeof(ElemType)*(A.lengthSize+B.lengthSize));
    C.length=(A.length+B.length);
    C.lengthSize=2*C.length;
    int i=0,left=0,right=B.length-1;
    while(left<A.length&&right>=0){
        if(A.Data[left]<B.Data[right])
            C.Data[i++]=A.Data[left++];
        else 
            C.Data[i++]=B.Data[right--];
    }
    while(left<A.length){
        C.Data[i++]=A.Data[left++];
    }
     while(right>=0){
        C.Data[i++]=B.Data[right--];
    }
}
void andElem2(SeqList &A,SeqList &B){
   //A空间为m+n
    ElemType *pNew=(ElemType *)malloc(sizeof(ElemType)*(A.lengthSize+B.lengthSize));
       int L=A.length-1,R=0,newi=A.length+B.length-1;
       for(int i=0;i<A.length;i++){
            pNew[i]=A.Data[i];
       }
       free(A.Data);
       A.Data=pNew; 
       A.length=A.length+B.length;
       A.lengthSize=A.lengthSize+B.lengthSize;
       while(L>=0&&R<B.length&&newi>=0){
            if(A.Data[L]>B.Data[R])
                A.Data[newi--]=A.Data[L--];
            else 
                A.Data[newi--]=B.Data[R++];
       }
        while(L>=0&&newi>=0){
            A.Data[newi--]=A.Data[L--];;
        }
        while(R<B.length&&newi>=0){
            A.Data[newi--]=B.Data[R++];
        }
}
void andElem3(SeqList &A,int r){
    int left=r-1,right=r,temp=0;
    while(right<A.length){
        temp=A.Data[right];
        if(left>=0&&A.Data[left]>A.Data[right])
            left--;
        else{
                for(int i=right;i>left+1;i--){
                   A.Data[i]=A.Data[i-1];
                }  
            A.Data[left+1]=temp;
            right++;
        } 
    }
}
int main(){
    SeqList A,B,C;
    InitList(A,9);
    ChuList(A);
    InitList(B,10);
    ChuList(B);
    sort(A.Data,A.Data+A.length);
    sort(B.Data,B.Data+B.length,cmp);
     printf("原序列A为:\n");
          print(A);
     printf("原序列B为:\n");
          print(B);
    /*andElem1(A,B,C);
     printf("序列C为:\n");
          print(C);
    */
    /*andElem2(A,B);
    printf("序列A为:\n");
     print(A);
    */
   ElemType ces[9]={2,4,7,8,9,10,4,3,1};
     free(A.Data);
   A.Data=ces;
   printf("序列A为:\n");
          print(A);
   andElem3(A,6);
      printf("排序后序列A为:\n");
          print(A);
    return 0;
}