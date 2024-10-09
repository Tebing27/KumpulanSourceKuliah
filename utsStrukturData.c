#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa {
    char nim[100];
    char nama[100];
    char matakuliah[100];
    float nilai;
    struct Mahasiswa* next;
} Mahasiswa;

typedef struct {
    Mahasiswa* top;
} Stack;

void initStack(Stack* s) {
    (*s).top = NULL;
}

int isEmpty(Stack s) {
    return s.top == NULL;
}

void push(Stack* s, char* nim, char* nama, char* matakuliah, float nilai) {
    Mahasiswa* newNode = (Mahasiswa*)malloc(sizeof(Mahasiswa));

    strncpy((*newNode).nim, nim, 100 - 1);
    strncpy((*newNode).nama, nama, 100 - 1);
    strncpy((*newNode).matakuliah, matakuliah, 100 - 1);
    (*newNode).nilai = nilai;

    (*newNode).next = (*s).top;
    (*s).top = newNode;
    printf("Data berhasil ditambahkan ke stack.\n");
}

void pop(Stack* s) {
    if (isEmpty(*s)) {
        printf("Stack kosong.\n");
        return;
    }
    Mahasiswa* temp = (*s).top;
    (*s).top = (*(*s).top).next;
    free(temp);
    printf("Data teratas berhasil dihapus dari stack.\n");
}

void display(Stack s) {
    if (isEmpty(s)) {
        printf("Stack kosong.\n");
        return;
    }
    Mahasiswa* tampilan = s.top;
    printf("Melihat stack:\n");
    while (tampilan != NULL) {
        printf("NIM: %s\nNama: %s\nMata Kuliah: %s\nNilai: %.2f\n",
               (*tampilan).nim, (*tampilan).nama, (*tampilan).matakuliah, (*tampilan).nilai);
        tampilan = (*tampilan).next;
    }
}

void clearStack(Stack* s) {
    while (!isEmpty(*s)) {
        pop(s);
    }
}

int main() {
    Stack s;
    initStack(&s);
    int pilihan;
    char nim[100], nama[100], matakuliah[100];
    float nilai;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                printf("Masukkan NIM: ");
                fgets(nim, 100, stdin);
                nim[strcspn(nim, "\n")] = 0;

                printf("Masukkan Nama: ");
                fgets(nama, 100, stdin);
                nama[strcspn(nama, "\n")] = 0;

                printf("Masukkan Nama Matakuliah: ");
                fgets(matakuliah, 100, stdin);
                matakuliah[strcspn(matakuliah, "\n")] = 0;

                printf("Masukkan Nilai: ");
                scanf("%f", &nilai);

                push(&s, nim, nama, matakuliah, nilai);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(s);
                break;
            case 4:
                printf("Terima kasih telah menggunakan program ini.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);
    return 0;
}
