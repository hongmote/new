//删除区间实验(删除[s,t]之间的元素)
#include "seqlist.h"//引用自己写的头函数
#include<malloc.h>
#include<algorithm>

using namespace std;
//过滤法算法实验(对应无序表删除[s,t]之间的元素)
void deleteElem1(ElemType s,ElemType t,SeqList &L){
     int length=0;
     for(int i=0;i<L.length;i++){
        if(L.Data[i]<s||L.Data[i]>t)
            L.Data[length++]=L.Data[i];
     }
     L.length=length;

}
//偏移法实验(对应删除非递减序列中的[s,t]之间的元素)
void deleteElem2(ElemType s,ElemType t,SeqList &L){
     int left=0,right=L.length-1;
     while(left<L.length && L.Data[left]<s){
          left++;
     }
      while(right>=0 && L.Data[right]>t){
          right--;
     }
     for(int i=left;i<L.length-right+left;i++){
          L.Data[i]=L.Data[i+right-left+1];
     }
     L.length-=(right-left+1);
}
//过滤法非递减数列去重
void deleteElem3(SeqList &L){
     int length=0;
     for(int i=0;i<L.length;i++){
          if(length==0||L.Data[length]!=L.Data[i])
           L.Data[length++]=L.Data[i];      
  }
          L.length=length;
}


int main(){
    SeqList L;
    InitList(L);
    ChuList(L);
     printf("原序列为:\n");
          print(L);
    //
    deleteElem1(3,5,L);
          print(L);
     //排序成为非递减序列
     sort(L.Data,L.Data+L.length);
     printf("非递减序列为\n");
          print(L);
     deleteElem2(7,8,L);
          print(L);
return 0;
}