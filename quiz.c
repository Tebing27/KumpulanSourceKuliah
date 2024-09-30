#include <stdio.h>
#define Garis 60
void panjangGaris(int panjang) {
    int i = 0;
    while(i < panjang) {
        printf("=");
        i++;
    }
    printf("\n");
    return 0;
}

int main() {
    char menu_pilihan[500];
    char pesanLagi, nama[50];
    int meja, menu, jumlah, totalBelanja = 0, pajak, totalAkhir, potongan, hasil_potongan, totalPembayaran, subTotal = 0;
    panjangGaris(Garis);
    printf("Kantin Mahasiswa\"SEDAP RASA\"\n");
    printf("UPN VETERAN JAKARTA\n");
    panjangGaris(Garis);

    printf("Meja : ");
    scanf("%d", &meja);

    while(meja < 1 || meja > 10){
        printf("Pilih meja 1 - 10 : ");
        scanf("%d", &meja);
    }

    printf("Nama : ");
    scanf("%s", &nama);

    do {
        float harga_menu = 0;
        printf("Menu Pesanan: \n");
        printf("Makanan\n");
        printf("1. Pecel Lele\t\t\tRp. 20.000,-\n");
        printf("2. Pecel Ayam\t\t\tRp. 25.000,-\n");
        printf("3. Soto Ayam\t\t\tRp. 30.000,-\n");
        printf("Minuman\n");
        printf("4. Es Teh/Panas\t\t\tRp. 5.000,-\n");
        printf("5. Es Alpukat\t\t\tRp. 8.000,-\n");
        printf("6. Es Jeruk/Panas\t\tRp. 7.000,-\n");
        printf("7. Air Putih (Panas/Dingin)\tRp. 1.000,-\n\n");
        printf("Pilihan angka untuk memesan >>>> ");
        scanf("%d", &menu);
        printf("\n");
        printf("Ketik [0] untuk Tidak memasan\n");
        panjangGaris(Garis);

        printf("Pilihan anda : %d\n", menu);
        if(menu == 0){
            printf("Anda tidak memesan\n");
            break;
        }
        switch(menu) {
            case 1:
             printf("Anda memilih: Pecel Lele @ Rp. 20.000,-\n");
             harga_menu = 20000;
             break;
            case 2:
                printf("Anda memilih: Pecel Ayam @ Rp. 25.000,-\n");
                harga_menu = 25000;
                break;
            case 3:
                printf("Anda memilih: Soto Ayam @ Rp. 30.000,-\n");
                harga_menu = 30000;
                break;
            case 4:
                printf("Anda memilih: Es Teh/Panas @ Rp. 5.000,-\n");
                harga_menu = 5000;
                break;
            case 5:
                printf("Anda memilih: Es Alpukat @ Rp. 8.000,-\n");
                harga_menu = 8000;
                break;
            case 6:
                printf("Anda memilih: Es Jeruk/Panas @ Rp. 7.000,-\n");
                harga_menu = 7000;
                break;
            case 7:
                printf("Anda memilih: Air Putih @ Rp. 1.000,-\n");
                harga_menu = 1000;
                break;
            default:
                printf("Pilihan tidak valid.\n");
                continue;
        }

        printf("Masukkan Jumlah : ");
        scanf("%d", &jumlah);

        subTotal = harga_menu * jumlah;
        totalBelanja += subTotal;
        printf("Harga\t: Rp. %d,-\n", subTotal);

        printf("Ingin memilih menu lain (y/t)? : ");
        scanf(" %c", &pesanLagi);
    }while (pesanLagi == 'y' || pesanLagi == 'Y');

    pajak = totalBelanja * 0.1;
    totalAkhir = totalBelanja + pajak;
    potongan = totalAkhir * 0.05;

    totalPembayaran = totalAkhir - potongan;

    char putus[] = "-----------";
    char putus1[] = "---------- -";
    panjangGaris(Garis);
    printf("Kantin Mahasiswa \"SEDAP RASA\"\n");
    panjangGaris(Garis);
    printf("\033[1mTerimakasih Bpk/Ibu\033[0m %s \033[1mdi Meja %d\033[0m\n", nama, meja);
    printf("Pemesanan di kantin Mahasiswa\"SEDAP RASA\"\n");
    printf("1. Soto Ayam\t@ Rp. 30.000\t2\t\tRp. 60.000,-\n");
    printf("2. Es Teh\t@ Rp. 10.000\t2\t\tRp. 10.000,-\n");
    printf("%59s\n", putus);
    printf("Total\t\t\t\t\t\tRp. %d,-\n", totalBelanja);
    printf("Pajak (10%%)\t\t\t\t\tRp. %d,-\n", pajak);
    printf("Total Akhir\t\t\t\t\tRp. %d,-\n", totalAkhir);
    printf("Potongan \t\t\t\t\tRp. %d,-\n", potongan);
    printf("%60s\n", putus1);
    printf("Total Pembayaran \t\t\t\tRp. %d,-\n", totalPembayaran);
    panjangGaris(Garis);
    printf("*Potongan 5%% untuk pembelian diatas Rp. 50.000,-");
    return 0;
}
