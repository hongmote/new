#include<seqlist.h>
#include<malloc.h>
//É¾³ý×îÐ¡ÔªËØ
void minz(SeqList &L){
    int temp=L.Data[0];
    for(int i=0;i<L.length;i++){
        if(temp>L.Data[i])
            temp=L.Data[i];
    }

}
int main(){
    SeqList L;
     InitList(L);
    ChuList(L);
    print(L);

}