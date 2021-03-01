#include <stdio.h>
#include <conio.h>
#include <string>
#define MaxLength 100 
typedef int ElementType;
typedef int Position; 
typedef struct {
		ElementType Elements[MaxLength];
	   Position Last; 
  }List;
// khoi tao danh sach rong
void MakeNull_List(List *L)
{
	L->Last=0;
}
//kiem tra danh sach rong
int Empty_List(List L){
	return L.Last==0;
}
//vi tri phan tu dau tien
Position First(List L){
	return 1;
}
//truy xuat vi tri phan tu
ElementType Retrieve(Position P,List L)
{
	return L.Elements[P-1];
}
// vi tri ket thuc
Position EndList(List L){
 return L.Last+1;
}
//vi tri sau phan tu P, trong danh sach L
Position Next(Position P, List L)
{
	return P+1;
}

// xoa vi tri P trong danh sach L
void Delete_List(Position P,List *L)
{
    if ((P<1) || (P>L->Last))
	    printf("Vi tri khong hop le");
  else if(Empty_List(*L))
	    printf("Danh sach rong!");
  else
  {
        Position Q;
		for(Q=P-1;Q<L->Last-1;Q++)
		   L->Elements[Q]=L->Elements[Q+1];
		L->Last--;
  }
}
// xoa cac phan tu trung lap
void Delete_duplication(List *L){
	Position P,Q;
	P = First(*L);
	while(P!=EndList(*L)){
		Q = Next (P,*L);
		while(Q !=EndList(*L)){
			if(Retrieve (P,*L) == Retrieve(Q,*L))
			{
				Delete_List(Q, L);
			}
			else
			Q = Next(Q, *L);
		}
		P = Next(P, *L);
	}
}
// void ReadList(List *L)
// {	int i,N,a;
// 	ElementType X;
// 	MakeNull_List(L);
// 	printf("So phan tu danh sach N= ");
// 	scanf("%d",&N);
// 	for(i=1;i<=N;i++)
// 	 {
//         printf("Phan tu thu %d: ",i);
//         scanf("%d",&X);
// 	  }
//   }
//in danh sach
void PrintList(List L)
{	
	Position P;
	P = First(L);
	while (P != EndList(L))
	{     printf("%d ",Retrieve(P,L));
		P = Next(P, L);
	}
	printf("\n");
}

void insertList(ElementType X, Position P, List *L){
    int i = 0;
    if(L->Last == MaxLength)
        printf("\nDanh sach day !!!");	
    else if((P < 1) || (P > L->Last+1))
        printf("\nVi tri khong hop le !!!");
    else{
        for(i = L->Last; i >= P; i--)
            L->Elements[i] = L->Elements[i-1];
        L->Last++;
        L->Elements[P-1] = X;
    }
}

void ReadList(List *L){
    int i, N;
    ElementType X;
    MakeNull_List(L);
    printf("\nNhap vao so phan tu trong danh sach ");
    scanf("%d", &N); fflush(stdin);
    for(i = 1; i <= N; i++){
        printf("\nPhan tu thu %d la ", i);
        scanf("%d", &X); fflush(stdin);
        insertList(X, EndList(*L), L);
    }
}


int main()
{
	List L;
	Position P;
	MakeNull_List(&L);
	ReadList(&L);
	printf("danh sach vua  nhap: ");
	PrintList(L);
	Delete_duplication(&L);
	printf("\ndanh sach cac phan tu sau khi xoa: ");
	PrintList(L);
	return 0;
}

