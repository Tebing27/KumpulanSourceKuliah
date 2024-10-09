#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//definisi ukuran
#define MAX 100
#define Garis 60

//bikin garis panjang
void panjangGaris(int panjang) {
    int i = 0;
    while(i < panjang) {
        printf("=");
        i++;
    }
    printf("\n");
    return 0;
}
//menyimpan data
typedef struct {
    char nim[5];
    char nama[50];
    char noTelp[15];
    int uangSaku;
} Data;
//bikin stack array
typedef struct {
    Data data[MAX];
    int top;
} Stack;
//menginisialisasi stack
void initStack(Stack *s) {
    (*s).top = -1;
}
//periksa stack penuh
int isFullStack(Stack *s) {
    return (*s).top == MAX - 1;
}
//periksa stack kosong
int isEmptyStack(Stack *s) {
    return (*s).top == -1;
}
//periksa stack kosong atau tidak
void push(Stack *s, Data value) {
    if (isFullStack(s)) {
        printf("Stack penuh\n");
    } else {
        (*s).top++;
        (*s).data[(*s).top] = value;
    }
}
//mengeluarkan elemen dari stack
Data pop(Stack *s) {
    Data data = {"", "", "", 0};
    if (isEmptyStack(s)) {
        printf("Stack kosong\n");
    } else {
        data = (*s).data[(*s).top];
        (*s).top--;
    }
    return data;
}
//menampilkan elemen dalam stack
void displayStack(Stack *s) {
    printf("Isi Stack:\n");
    for (int i = (*s).top; i >= 0; i--) {
        printf("%s %s %s %d\n", (*s).data[i].nim, (*s).data[i].nama, (*s).data[i].noTelp, (*s).data[i].uangSaku);
    }
}
//bikin queue menggunakan linked list
typedef struct Node {
    Data data;
    struct Node* next;
} Node;
//queue pointer
typedef struct {
    Node* depan;
    Node* belakang;
} Queue;
//menginisialisasi queue
void initQueue(Queue* q) {
    (*q).depan = (*q).belakang = NULL;
}
//periksa kosong atau tidak
int isEmptyQueue(Queue* q) {
    return ((*q).depan == NULL);
}
//menambahkan elemen ke dalam
void enqueue(Queue* q, Data value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmptyQueue(q)) {
        (*q).depan = (*q).belakang = newNode;
    } else {
        (*q).belakang->next = newNode;
        (*q).belakang = newNode;
    }
}
//mengeluarkan elemen
Data dequeue(Queue* q) {
    Data data = {"", "", "", 0};
    if (isEmptyQueue(q)) {
        printf("Queue kosong\n");
    } else {
        Node* temp = (*q).depan;
        data = temp->data;
        (*q).depan = (*q).depan->next;
        free(temp);

        if ((*q).depan == NULL) {
            (*q).belakang = NULL;
        }
    }
    return data;
}
//tampilkan elemen
void displayQueue(Queue* q) {
    printf("Isi Queue:\n");
    Node* current = (*q).depan;
    while (current != NULL) {
        printf("%s %s %s %d\n", (*current).data.nim, (*current).data.nama, (*current).data.noTelp, (*current).data.uangSaku);
        current = (*current).next;
    }
}
//program utama
int main() {
    Stack s;
    initStack(&s);
    //isi data
    Data d1 = {"0001", "Sandi", "0895555666", 50000};
    Data d2 = {"0002", "Iwan", "0879222727", 51000};
    Data d3 = {"0003", "Ari", "0891232323", 46000};

    push(&s, d1);
    push(&s, d2);
    push(&s, d3);

    printf("Program Stack menggunakan Array\n");
    printf("Data awal:\n");
    displayStack(&s);
    //menambahkan data
    Data d4 = {"0004", "Budi", "0879797979", 45000};
    Data d5 = {"0005", "Riswan", "0879787879", 50000};
    push(&s, d4);
    push(&s, d5);
    panjangGaris(Garis);
    printf("Perintah 1:\n");
    panjangGaris(Garis);
    displayStack(&s);
    //menghapus stack
    pop(&s);
    pop(&s);
    Data poppedd1 = pop(&s);
    pop(&s);
    Data poppedd4 = pop(&s);

    panjangGaris(Garis);
    printf("Data dikeluarkan:\n");
    printf("%s dan %s\n", poppedd4.nama, poppedd1.nama);
    panjangGaris(Garis);
    printf("Perintah 3:\n");
    panjangGaris(Garis);
    if(displayStack != 0){
        printf("Stack Kosong\n");
    }
    panjangGaris(Garis);
    //menambahkan data ke dalam queue
    Queue q;
    initQueue(&q);

    enqueue(&q, d1);
    enqueue(&q, d2);
    enqueue(&q, d3);

    printf("Program Queue menggunakan Linked List\n");
    printf("Data awal:\n");
    displayQueue(&q);

    enqueue(&q, d4);
    enqueue(&q, d5);
    panjangGaris(Garis);

    printf("Perintah 1:\n");
    displayQueue(&q);

    Data dequeued1 = dequeue(&q);
    dequeue(&q);
    Data dequeued2 = dequeue(&q);

    panjangGaris(Garis);
    printf("Data yang dikeluarkan\n");
    printf("%s dan %s\n", dequeued1.nama, dequeued2.nama);
    panjangGaris(Garis);
    printf("Perintah 3:\n");
    displayQueue(&q);
    panjangGaris(Garis);
    return 0;
}
