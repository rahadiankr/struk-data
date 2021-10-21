#include <iostream>
#include "simpleList.h"

using namespace std;

int main()
{
    List L;
    address P;
	int i, x, s, c, mn;

	CreateList(&L);
	printf("List Kosong : %s",ListEmpty(L) ? "true" : "false");
    printf("\n");
    PrintInfo(L);
    do {
        mn = menu();
        switch(mn) {
            case 1 :printf("Input banyak element :" );
                    scanf("%d", &s);
                        for(i=1; i<= s; i++) {
                            printf("Elemen %d : ", i); scanf("%d", &x);
                            P = Alokasi(x);
                            InsertFirst(&L, P);
                        }
                        printf("L="); PrintInfo(L);
                     break;
            case 2 :printf("Input banyak element :" );
                    scanf("%d", &s);
                        for(i=1; i<= s; i++) {
                            printf("Elemen %d : ", i); scanf("%d", &x);
                            InsertLast(&L, x);
                        }
                        printf("L="); PrintInfo(L);
                    break;

            case 3 :deleteBegin(&L);
                    printf("L="); PrintInfo(L);
                    break;

            case 4 :printf("Urutan ke: " );
                    scanf("%d", &c);
                    printf("Input Elemennya: " );
                    scanf("%d", &x);
                    insertNth(&L, x, c);
                    printf("L="); PrintInfo(L);
                    break;

            case 5 :break;
        }
    } while(mn != 5);
}
