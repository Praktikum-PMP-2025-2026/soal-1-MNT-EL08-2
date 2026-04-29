/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 3
 *   Hari dan Tanggal    : Rabu, 29 April 2026
 *   Nama (NIM)          : Salman Santika Abdullah (13224084)
 *   Nama File           : soal1.c
 *   Deskripsi           : Membuat1 sistem arsip yang dapat menghasilkan urutan akhir yang sesuai dengan prioritas pengelompokan yang 
telah disepakati. 
 * 
 */


#include <stdio.h>
#include <string.h>
#include<stdlib.h>

 //definisi structure
typedef struct {
    char nama [100];
    char kategori [100];
    int tahun;
    int nilai;
 } artefak;


 //Fungsi komparator untuk qsort
int compare (const void *a, const void *b) {
    artefak *p1 = (artefak *)a;
    artefak *p2 = (artefak *)b;

    //prioritas pertama, kategori alfabetis naik
    if(strcmp(p1->kategori, p2->kategori) < 0){
        return p2->kategori - p1->kategori;
    }
    //priotitas kedua, tahun naik
    if (p1->tahun > p2->tahun) {
        return p1->tahun - p2->tahun; 
    }
    //prioritas ketiga, nilai turun
    if (p1->nilai > p2->nilai) {
        return p2->nilai - p1->nilai; 
    }
    //prioritas keempat, nama alfabetis naik
    return strcmp(p1->kategori, p2->kategori);
}


 int main() {
    int n;

    //membaca jumlah artefak
    if (scanf("%d", &n) != 1 || n <= 0) {
        // Jika tidak ada data, cetak - untuk semua shift
        printf("tidak ada artefak");
        return 0;
    }

    //alokasi memori dinamis array of struct

    artefak *data = (artefak *)malloc(n * sizeof(artefak));
    if (data == NULL){
        printf("Gagal mengalokasi memori.\n");
        return 1;
    }

    //membaca data artefak
    for(int i = 0; i < n; i++){
        scanf ("%s %s %d %d", data[i].nama, data[i].kategori, &data[i].tahun, &data[i].nilai);
    }

    //mengurutkan artefak terbaik
    qsort(data, n, sizeof(artefak), compare);


    //mencetak nilai hasil pengurutan
    for(int i = 0; i < n; i++){
        printf("%s %s %d %d\n", data[i].nama, data[i].kategori, data[i].tahun, data[i].nilai);
    }

    free(data);
    return 0;
  
 }
