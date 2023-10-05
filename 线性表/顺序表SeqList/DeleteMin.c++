#include "seqlist.h"
#include<malloc.h>
//删除最小元素并且将最后一个元素放置与删除位置。
void DeteleMin(SeqList &L){
    int temp=0;
    for(int i=1;i<L.length;i++){
        if(L.Data[temp]>L.Data[i])
        {
            temp=i;
        }    
    }
    if(temp!=L.length)
        L.Data[temp]=L.Data[L.length-1];
    --L.length;
}
int main(){
    SeqList L;
    InitList(L);
    ChuList(L);
    print(L);
    //测试当最小值为最后一个元素时
    //int o=L.Data[0];
    //L.Data[0]=L.Data[9];
    //L.Data[9]=o;
    DeteleMin(L);
    print(L);

}