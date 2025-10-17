#include <stdio.h>
#include <string.h>

#include "reader.h"

void print_doc_gia_theo_hang(int i) {
    printf("👤 DOC GIA #%d\n", i + 1);
    printf("──────────────────────────────────────────────────────────────\n");
    printf("  Ma doc gia       : %s\n", ma_doc_gia_at(i));
    printf("  Ho va ten        : %s\n", ho_va_ten_at(i));
    printf("  CMND             : %s\n", cmnd_at(i));
    printf("  Ngay sinh       : %s-%s-%s\n", ngay_sinh_at(i), thang_sinh_at(i), nam_sinh_at(i));
    printf("  Gioi tinh       : %s\n", gioi_tinh_at(i));
    printf("  Email           : %s\n", email_at(i));
    printf("  Dia chi         : %s\n", dia_chi_at(i));
    printf("  Ngay lap the    : %s-%s-%s\n", ngay_lap_the_at(i), thang_lap_the_at(i), nam_lap_the_at(i));
    printf("  Ngay het han the: %s-%s-%s\n", ngay_het_han_the_at(i), thang_het_han_the_at(i), nam_het_han_the_at(i));
    printf("──────────────────────────────────────────────────────────────\n\n");
}

void get_danh_sach_doc_gia() {
    printf("\n===Danh sach cac doc gia===\n\n");
    printf("Tong so luong doc gia hien co: %d\n\n", tong_so_luong_doc_gia);
    int i;
    for (i = 0; i < tong_so_luong_doc_gia; i++ ) {
        print_doc_gia_theo_hang(i);
    }
    if (tong_so_luong_doc_gia == 0) printf("Hien tai chua co doc gia trong thu vien.\n\n");
}