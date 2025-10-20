#include <stdio.h>
#include <string.h>

#include "stats.h"
#include "book.data.h"
#include "reader.data.h"

void thong_ke_sach() {
    long long total = 0;
    int i;
    for (i = 0; i < tong_so_luong_sach; i++) {
        total += g_sach_ban_sao[i];
    }
    printf("Tong so luong sach hien co: %lld\n", total);
}

void thong_ke_doc_gia() {
    printf("Tong so luong doc gia hien co: %d\n", tong_so_luong_doc_gia);
}

void thong_ke_doc_gia_theo_gioi_tinh() {
    int tong_nam = 0;
    int tong_nu =0;
    for (int i = 0; i < tong_so_luong_doc_gia; i++) {
        if (strcmp(g_doc_gia_gioi_tinh[i], "nam") == 0) {
            tong_nam++;
        } else if (strcmp(g_doc_gia_gioi_tinh[i], "nu") == 0) {
            tong_nu++;
        }
    }
    printf("Tong so luong doc gia nam: %d\n", tong_nam);
    printf("Tong so luong doc gia nu: %d\n", tong_nu);
}