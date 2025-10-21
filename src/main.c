#include <stdio.h>

#include "utils.h"

#include "book.h"
#include "book.data.h"
#include "reader.h"
#include "reader.data.h"
#include "stats.h"

static void menu_quan_ly_doc_gia() {
    while(1) {
        printf("\n=== QUAN LY DOC GIA ===\n");
        printf("1. Xem danh sach doc gia\n");
        printf("2. Them doc gia\n");
        printf("3. Chinh sua doc gia\n");
        printf("4. Xoa doc gia\n");
        printf("5. Tim theo CMND\n");
        printf("6. Tim theo Ho ten\n");
        printf("0. Quay lai\n");

        int c = nhap_so_nguyen("Chon: ", 0, 6);
        if (c == 1) get_danh_sach_doc_gia();
        if (c == 2) them_doc_gia();
        if (c == 3) cap_nhat_doc_gia();
        if (c == 4) xoa_doc_gia_bang_cmnd();
        if (c == 5) tim_doc_gia_bang_cmnd();
        if (c == 6) tim_doc_gia_bang_ho_va_ten();
        if (c == 0) return;
    }
}

static void menu_quan_ly_sach() {
        printf("\n=== QUAN LY SACH ===\n");
        printf("1. Xem danh sach sach\n");
        printf("2. Them sach\n");
        printf("3. Chinh sua sach\n");
        printf("4. Xoa sach\n");
        printf("5. Tim theo ISBN\n");
        printf("6. Tim theo ten sach\n");
        printf("0. Quay lai\n");

        int c = nhap_so_nguyen("Chon: ", 0, 6);
        if (c == 1) get_list_sach();
        if (c == 2) them_sach();
        if (c == 3) cap_nhat_sach();
        if (c == 4) xoa_sach();
        if (c == 5) tim_sach_theo_ISBN();
        if (c == 6) tim_sach_theo_tieu_de();
        if (c == 0) return;

}

static void menu_stats() {
        printf("\n=== THONG KE ===\n");
        printf("1. Tong so luong sach\n");
        printf("2. Thong ke so luong sach theo the loai\n");
        printf("3. Tong so luong doc gia\n");
        printf("4. Thong ke doc gia theo gioi tinh\n");
        printf("5. Thong ke so sach dang duoc muon\n");
        printf("6. Danh sach doc gia bi tre han\n");
        printf("0. Quay lai\n");

        int c = nhap_so_nguyen("Chon: ", 0, 6);
        if (c == 1) thong_ke_sach();
        if (c == 2) printf("STATS: option 2");
        if (c == 3) thong_ke_doc_gia();
        if (c == 4) thong_ke_doc_gia_theo_gioi_tinh();
        if (c == 5) printf("STATS: option 5");
        if (c == 6) printf("STATS: option 6");
        if (c == 0) return;
}



int main() {
    khoi_tao_du_lieu_book();
    khoi_tao_du_lieu_reader();

    while(1) {
        printf("\n===== QUAN LI THU VIEN =====\n");
        printf("1. Quan li doc gia\n");
        printf("2. Quan li sach\n");
        printf("3. Lap phieu muon sach\n");
        printf("4. Lap phieu tra sach\n");
        printf("5. Cac thong ke co ban\n");
        printf("0. Thoat\n");

        int c = nhap_so_nguyen("Chon : ", 0, 5);
        if (c == 1) menu_quan_ly_doc_gia();
        if (c == 2) menu_quan_ly_sach();
        if (c == 3) printf("Chon option 3\n");        
        if (c == 4) printf("Chon option 4\n");
        if (c == 5) menu_stats();
        if (c == 0) return 0;

        press_enter_to_continue();
    }
    return 0;
}