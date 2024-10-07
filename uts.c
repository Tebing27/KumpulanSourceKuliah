#include <stdio.h>

int main() {
    int input, i, nl;
    char kategoriCount[5] = {0};
    char kategori;
    int total = 0;
    int nilai_tertinggi = 0;
    int nilai_terendah = 100;
    printf("Masukkan jumlah nilai yang ingin diinput: ");
    scanf("%d", &input);

    for (i = 0; i < input; i++) {
        printf("Masukkan nilai mahasiswa ke-%i (0 - 100) : ", i + 1);
        scanf("%d", &nl);
        while (nl < 0 || nl > 100) {
            printf("Nilai tidak ditemukan, mohon untuk input (0-100) : ");
            scanf("%d", &nl);
        }

        if (nl >= 85 && nl <= 100) {
            kategori = 'A';
            kategoriCount[0]++;
        } else if (nl >= 70 && nl <= 84) {
            kategori = 'B';
            kategoriCount[1]++;
        } else if (nl >= 41 && nl <= 69) {
            kategori = 'C';
            kategoriCount[2]++;
        } else if (nl >= 30 && nl <= 40) {
            kategori = 'D';
            kategoriCount[3]++;
        } else if (nl >= 0 && nl <= 29) {
            kategori = 'E';
            kategoriCount[4]++;
        } else {
            kategori = 'X';
        }

        printf("Nilai : %d - Kategori : %c\n", nl, kategori);
        total += nl;
        if (nl > nilai_tertinggi) {
            nilai_tertinggi = nl;
        }
        if (nl < nilai_terendah) {
            nilai_terendah = nl;
        }
    }

    float rata_rata = (float)total / input;
    printf("Total nilai: %d\n", total);
    printf("Rata-rata nilai: %.2f\n", rata_rata);
    printf("Nilai tertinggi: %d\n", nilai_tertinggi);
    printf("Nilai terendah: %d\n", nilai_terendah);
    printf("Jumlah mahasiswa dalam setiap kategori:\n");
    printf("Kategori A: %d mahasiswa\n", kategoriCount[0]);
    printf("Kategori B: %d mahasiswa\n", kategoriCount[1]);
    printf("Kategori C: %d mahasiswa\n", kategoriCount[2]);
    printf("Kategori D: %d mahasiswa\n", kategoriCount[3]);
    printf("Kategori E: %d mahasiswa\n", kategoriCount[4]);

    return 0;
}
