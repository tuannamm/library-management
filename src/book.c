#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "book.h"

void print_sach_theo_hang(int i) {
    printf("📘 SÁCH #%d\n", i + 1);
    printf("──────────────────────────────────────────────────────────────\n");
    printf("  ISBN          : %s\n", isbn_sach_at(i));
    printf("  Tiêu đề       : %s\n", tieu_de_sach_at(i));
    printf("  Tác giả       : %s\n", tac_gia_sach_at(i));
    printf("  Nhà xuất bản  : %s\n", nxb_sach_at(i));
    printf("  Năm xuất bản  : %d\n", g_sach_nam_xuat_ban[i]);
    printf("  Thể loại      : %s\n", the_loai_sach_at(i));
    printf("  Giá bán       : %d VND\n", g_sach_gia[i]);
    printf("  Tổng số lượng : %d\n", g_sach_ban_sao[i]);
    printf("  Còn lại       : %d\n", g_sach_ban_sao_co_san[i]);
    printf("──────────────────────────────────────────────────────────────\n\n");
}

void get_list_sach() {
    printf("\n===Danh sach cac dau sach===\n\n");
    printf("Tong so luong sach hien co: %d\n\n", tong_so_luong_sach);

    int i;
    for (i = 0; i < tong_so_luong_sach; i++) {
        print_sach_theo_hang(i);
    }

    if (tong_so_luong_sach == 0) printf("Hien tai chua co sach trong thu vien.\n\n");

}

int them_sach() {
    printf("\n===Them sach vao thu vien===\n\n");
    if (tong_so_luong_sach >= MAX_SO_LUONG_SACH) {
        printf("Khong the them sach vao thu vien, so luong sach da toi gioi han.");
        return 0;
    }
    // nhập ISBN với kiểm tra trùng lặp
    char isbn[LENGTH_ISBN];
    int isbn_valid = 0;
    while (!isbn_valid) {
        nhap_chuoi("ISBN: ", isbn, LENGTH_ISBN);
        isbn_valid = validate_sach_by_isbn(isbn);
    }
    char tieu_de[LENGTH_TIEU_DE];
    nhap_chuoi("Tieu de: ", tieu_de, LENGTH_TIEU_DE);
    char tac_gia[LENGTH_TAC_GIA];
    nhap_chuoi("Tac gia: ", tac_gia, LENGTH_TAC_GIA);
    char nha_xuat_ban[LENGTH_NXB];
    nhap_chuoi("Nha xuat ban: ", nha_xuat_ban, LENGTH_NXB);
    int year = nhap_so_nguyen("Nam xuat ban: ", 1, 9999);
    char the_loai[LENGTH_THE_LOAI];
    nhap_chuoi("The loai: ", the_loai, LENGTH_THE_LOAI);
    int gia = nhap_so_nguyen("Gia: ", 0, 999999999);
    int so_luong = nhap_so_nguyen("So luong: ", 0, 99999999);

    // lưu từng mục thông tin của sách vào array chứa dữ liệu của từng loại
    int i = tong_so_luong_sach;
    luu_du_lieu_vao_vung_nho(isbn_sach_at(i), isbn);
    luu_du_lieu_vao_vung_nho(tieu_de_sach_at(i), tieu_de);
    luu_du_lieu_vao_vung_nho(tac_gia_sach_at(i), tac_gia);
    luu_du_lieu_vao_vung_nho(nxb_sach_at(i), nha_xuat_ban);
    luu_du_lieu_vao_vung_nho(the_loai_sach_at(i), the_loai);
    g_sach_nam_xuat_ban[i] = year;
    g_sach_gia[i] = gia;
    g_sach_ban_sao[i] = so_luong;
    g_sach_ban_sao_co_san[i] = so_luong;

    tong_so_luong_sach++;
    printf("Them sach vao thu vien thanh cong!\n\n");
    return 1;

}

void xoa_sach() {
    char isbn[LENGTH_ISBN];
    nhap_chuoi("Nhap ISBN can xoa: ", isbn, LENGTH_ISBN);
    int index_cua_sach = tim_sach_bang_ISBN(isbn);
    if (index_cua_sach == -1) {
        printf("Khong tim thay sach voi ISBN.\n");
        return;
    }
    int i;
    for (i = index_cua_sach + 1; i < tong_so_luong_sach; i++) {
        int index_moi = i - 1;
        luu_du_lieu_vao_vung_nho(isbn_sach_at(index_moi), isbn_sach_at(i));
        luu_du_lieu_vao_vung_nho(tieu_de_sach_at(index_moi), tieu_de_sach_at(i));
        luu_du_lieu_vao_vung_nho(tac_gia_sach_at(index_moi), tac_gia_sach_at(i));
        luu_du_lieu_vao_vung_nho(nxb_sach_at(index_moi), nxb_sach_at(i));
        luu_du_lieu_vao_vung_nho(the_loai_sach_at(index_moi), the_loai_sach_at(i));
        g_sach_nam_xuat_ban[index_moi] = g_sach_nam_xuat_ban[i];
        g_sach_gia[index_moi] = g_sach_gia[i];
        g_sach_ban_sao[index_moi] = g_sach_ban_sao[i];
        g_sach_ban_sao_co_san[index_moi] = g_sach_ban_sao_co_san[i];
    }
    tong_so_luong_sach--;
    printf("\nDa xoa sach isbn %s thanh cong\n\n", isbn);

} 

int tim_sach_bang_ISBN(const char* isbn) {
    int i;
    for (i = 0; i < tong_so_luong_sach; i++) {
        if (strcmp(isbn_sach_at(i), isbn) == 0) {
            return i;
        }
    }
    return -1;
}

int validate_sach_by_isbn(const char* isbn) {
    int result = tim_sach_bang_ISBN(isbn);

    if (result != -1) {
        printf("------------------------------\n");
        printf("Loi: ISBN cua sach da ton tai.\n");
        printf("Vui long nhap ISBN khac.\n");
        printf("------------------------------\n");
        return 0;
    }
    return 1;
}