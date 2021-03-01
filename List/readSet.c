#include "AListLib.c"

void readSet(List *pL){
    int n;
    makeNullList(pL);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        if(member(x, *pL)){
            ;
        }
        else
            insertSet(x, pL);
    }
}

int main(){
    List L;
    int i;
    readSet(&L);
    for(i=0;i<L.Last;i++){
        printf("%d ",L.Elements[i]);
    }
}
