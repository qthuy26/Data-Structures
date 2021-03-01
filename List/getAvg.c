#include "AListLib.c"

float getAvg(List L){
    float S = 0, avg, dem = 0;
    Position P = firstList(L);
    if(emptyList(L))
        return -10000.0000;
    else{
        while(P != endList(L)){
            S += Retrieve(P, L);
            dem++;
            P = Next(P, L);
        }
    avg = S / dem;
    return avg;
    }
}

int main(){
    List L;
int i;
L.Last=0;
for(i=0;i<5;i++)
    L.Elements[i] = i+1;
L.Last=5;
printf("AVG = %.4f\n", getAvg(L));
}
