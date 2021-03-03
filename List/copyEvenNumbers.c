#include "AListLib.c"

void copyEvenNumbers(List L1, List *pL2){
    makeNullList(pL2);
    Position P = firstList(L1);
    while(P != endList(L1)){
        if(Retrieve(P, L1) % 2 == 0){
            insertSet(Retrieve(P, L1), pL2);
        }
        P = Next(P, L1);
    }
}

int main(){
    List L1,L2;
    int i;
    makeNullList(&L1);
    for(i=0;i<=5;i++){
        insertList(i, L1.Last+1, &L1);
    }
    copyEvenNumbers(L1, &L2);
    for(i=0;i<L1.Last;i++){
        printf("%d ",L1.Elements[i]);
    }
    printf("\n");
    for(i=0;i<L2.Last;i++){
        printf("%d ",L2.Elements[i]);
    }
}
