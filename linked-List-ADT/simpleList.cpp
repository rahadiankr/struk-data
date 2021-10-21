#include "simpleList.h"

boolean ListEmpty(List L) {
	return First(L) == Nil;
}

void CreateList(List *L) {
	First(*L) = Nil;
}

address Alokasi(infotype X) {
	address P;

	P = (address)malloc(sizeof(ElmtList));
	if(P != Nil) {//alokasi berhasil
		Info(P) = X;
		Next(P) = Nil;
	}
	return P;
}

void Dealokasi(address *P) {
	free(*P);
}

void PrintInfo(List L) {
	address P;

	if(ListEmpty(L)) {
		printf("* List Kosong\n");
	} else {//ada isinya
		P = First(L);//P adalah temporary
		do {//sudah pasti tidak kosong, maka pengecekan dibelakang
			printf("|%d| ",Info(P));
			P = Next(P);
		} while (P != Nil);
	}
}

void InsertFirst(List *L, address P) { //berdasar alamat
	Next(P) = First(*L);
	First(*L) = P;
}

void InsVFirst(List *L, infotype X){//berdasar nilai
	address P;
	P = Alokasi(X);
	if(P != Nil){
		InsertFirst(&(*L),P);
	}
}

void InsertLast(List *L, infotype X){ //berdasar alamat
    address P;
    P=Alokasi(X);
	ElmtList *temp = First(*L);
	if(ListEmpty(*L)==0){
        Next(P) = Nil;
        while(temp->Next != Nil){
            temp=temp->Next;
        }
        temp->Next=P;
	}
	else{
        Next(P)=Nil;
        First(*L)=P;
	}
}

void deleteBegin(List *L){
    address P;
    ElmtList *temp = First(*L);
    if(ListEmpty(*L)==0){
        First(*L)=temp -> Next;
        free(temp);
    }
    else{
        printf("sudah kosong");
    }
}

void insertNth(List *L,infotype X, int nth){
//    address *new, *temp;
    address p;
    ElmtList *temp;
    int i;
    p = Alokasi(X);
    Next(p)=Nil;
    if(nth==1){
        Next(p)=First(*L);
        First(*L)=p;
    }
    else if(ListEmpty(*L)==0){
        temp=First(*L);
        for(i=0;i<nth-2;i++){
            temp=temp->Next;
        }
        Next(p)=temp->Next;
        temp->Next=p;
    }
    else{
        printf("Must place Node at first elemen if list is empty\n");
    }
}

int menu() {
        int pilih;
        printf("\nMenu \n");
        printf("1. Insert First \n");
        printf("2. Insert Last\n");
        printf("3. Delete Begin \n");
        printf("4. Insert NTH \n");
        printf("5. Exit \n");
        printf("Pilih menu: ");
        scanf("%d", &pilih);
        return pilih;
}


