#include <stdio.h>
#include <string.h>

#include "reader.h"
#include "utils.h"

void print_doc_gia_theo_hang(int i) {
    printf("👤 DOC GIA #%d\n", i + 1);
    printf("──────────────────────────────────────────────────────────────\n");
    printf("  Ma doc gia      : %s\n", ma_doc_gia_at(i));
    printf("  Ho va ten       : %s\n", ho_va_ten_at(i));
    printf("  CMND            : %s\n", cmnd_at(i));
    printf("  Ngay sinh       : %d-%d-%d\n", g_doc_gia_ngay_sinh[i], g_doc_gia_thang_sinh[i], g_doc_gia_nam_sinh[i]);
    printf("  Gioi tinh       : %s\n", gioi_tinh_at(i));
    printf("  Email           : %s\n", email_at(i));
    printf("  Dia chi         : %s\n", dia_chi_at(i));
    printf("  Ngay lap the    : %d-%d-%d\n", g_doc_gia_ngay_lap_the[i], g_doc_gia_thang_lap_the[i], g_doc_gia_nam_lap_the[i]);
    printf("  Ngay het han the: %d-%d-%d\n", g_doc_gia_ngay_het_han_the[i], g_doc_gia_thang_het_han_the[i], g_doc_gia_nam_het_han_the[i]);
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

void tim_doc_gia_bang_ma() {
    char ma_doc_gia[LENGTH_MA_DOC_GIA];
    nhap_chuoi("Nhap ma doc gia can tim: ", ma_doc_gia, LENGTH_MA_DOC_GIA);
    int index_cua_doc_gia = tim_doc_gia_by_ma(ma_doc_gia);
    if (index_cua_doc_gia == -1) {
        printf("Khong tim thay doc gia voi ma doc gia.\n");
        return;
    }
    print_doc_gia_theo_hang(index_cua_doc_gia);
}

int them_doc_gia() {
    printf("\n===Them doc gia vao thu vien===\n\n");
    if (tong_so_luong_doc_gia >= MAX_SO_LUONG_DOC_GIA) {
        printf("Khong the them doc gia vao thu vien, so luong doc gia da toi gioi han.");
        return 0;
    }
    char ma_doc_gia[LENGTH_MA_DOC_GIA];
    int ma_doc_gia_valid = 0;
    while (!ma_doc_gia_valid) {
        nhap_chuoi("Ma doc gia: ", ma_doc_gia,  LENGTH_MA_DOC_GIA);
        ma_doc_gia_valid = validate_ma_doc_gia(ma_doc_gia);
    }
    char ho_va_ten[LENGTH_HO_VA_TEN];
    nhap_chuoi("Ho va ten: ", ho_va_ten, LENGTH_HO_VA_TEN);
    char cmnd[LENGTH_CMND];
    nhap_chuoi("CMND: ", cmnd, LENGTH_CMND);
    int ngay_sinh, thang_sinh, nam_sinh;
    nhap_ngay_thang_nam("Ngay thang nam sinh ", &ngay_sinh, &thang_sinh, &nam_sinh);
    char gioi_tinh[LENGTH_GIOI_TINH];
    nhap_chuoi("Gioi tinh: ", gioi_tinh, LENGTH_GIOI_TINH);
    char email[LENGTH_EMAIL];
    nhap_chuoi("Email: ", email, LENGTH_EMAIL);
    char dia_chi[LENGTH_DIA_CHI];
    nhap_chuoi("Dia chi: ", dia_chi, LENGTH_DIA_CHI);
    int ngay_lap_the, thang_lap_the, nam_lap_the;
    nhap_ngay_thang_nam("Ngay thang nam lap the: ", &ngay_lap_the, &thang_lap_the, &nam_lap_the);
    // TODO: update ngay het han the tự động dựa trên ngày lập thẻ
    int ngay_het_han_the, thang_het_han_the, nam_het_han_the;
    nhap_ngay_thang_nam("Ngay thang nam het han the: ", &ngay_het_han_the, &thang_het_han_the, &nam_het_han_the);

    int i = tong_so_luong_doc_gia;
    luu_du_lieu_vao_vung_nho(ma_doc_gia_at(i), ma_doc_gia);
    luu_du_lieu_vao_vung_nho(ho_va_ten_at(i), ho_va_ten);
    luu_du_lieu_vao_vung_nho(cmnd_at(i), cmnd);
    g_doc_gia_ngay_sinh[i] = ngay_sinh;
    g_doc_gia_thang_sinh[i] = thang_sinh;
    g_doc_gia_nam_sinh[i] = nam_sinh;
    luu_du_lieu_vao_vung_nho(gioi_tinh_at(i), gioi_tinh);
    luu_du_lieu_vao_vung_nho(email_at(i), email);
    luu_du_lieu_vao_vung_nho(dia_chi_at(i), dia_chi);
    g_doc_gia_ngay_lap_the[i] = ngay_lap_the;
    g_doc_gia_thang_lap_the[i] = thang_lap_the;
    g_doc_gia_nam_lap_the[i] = nam_lap_the;
    g_doc_gia_ngay_het_han_the[i] = ngay_het_han_the;
    g_doc_gia_thang_het_han_the[i] = thang_het_han_the;
    g_doc_gia_nam_het_han_the[i] = nam_het_han_the;

    tong_so_luong_doc_gia++;
    printf("\n\nThem doc gia vao thu vien thanh cong!\n\n");
    return 1;
}

int tim_doc_gia_by_ma(const char* ma_doc_gia) {
    int i;
    for (i = 0; i < tong_so_luong_doc_gia; i++) {
        if(strcmp(ma_doc_gia_at(i), ma_doc_gia) == 0) {
            return i;
        }
    }
    return -1;
}

int tim_doc_gia_by_cmnd(const char* cmnd) {
    int i;
    for (i = 0; i < tong_so_luong_doc_gia; i++) {
        if(strcmp(cmnd_at(i), cmnd) == 0) {
            return i;
        }
    }
    return -1;
}

int validate_ma_doc_gia(const char* ma_doc_gia) {
    int result = tim_doc_gia_by_ma(ma_doc_gia);

    if (result != -1) {
        printf("------------------------------\n");
        printf("Loi: Ma doc gia da ton tai.\n");
        printf("Vui long nhap ma doc gia khac.\n");
        printf("------------------------------\n");
        return 0;
    } 
    return 1;
}

void xoa_doc_gia_bang_cmnd() {
    char cmnd[LENGTH_CMND];
    nhap_chuoi("Nhap CMND can xoa: ", cmnd, LENGTH_CMND);
    int index_cua_doc_gia = tim_doc_gia_by_cmnd(cmnd);
    if (index_cua_doc_gia == -1) {
        printf("Khong tim thay doc gia voi CMND.\n");
        return;
    }
    int i;
    for (i = index_cua_doc_gia + 1; i < tong_so_luong_doc_gia; i++) {
        int index_moi = i - 1;
        luu_du_lieu_vao_vung_nho(ma_doc_gia_at(index_moi), ma_doc_gia_at(i));
        luu_du_lieu_vao_vung_nho(ho_va_ten_at(index_moi), ho_va_ten_at(i));
        luu_du_lieu_vao_vung_nho(cmnd_at(index_moi), cmnd_at(i));
        g_doc_gia_ngay_sinh[index_moi] = g_doc_gia_ngay_sinh[i];
        g_doc_gia_thang_sinh[index_moi] = g_doc_gia_thang_sinh[i];
        g_doc_gia_nam_sinh[index_moi] = g_doc_gia_nam_sinh[i];
        luu_du_lieu_vao_vung_nho(gioi_tinh_at(index_moi), gioi_tinh_at(i));
        luu_du_lieu_vao_vung_nho(email_at(index_moi), email_at(i));
        luu_du_lieu_vao_vung_nho(dia_chi_at(index_moi), dia_chi_at(i));
        g_doc_gia_ngay_lap_the[index_moi] = g_doc_gia_ngay_lap_the[i];
        g_doc_gia_thang_lap_the[index_moi] = g_doc_gia_thang_lap_the[i];
        g_doc_gia_nam_lap_the[index_moi] = g_doc_gia_nam_lap_the[i];
        g_doc_gia_ngay_het_han_the[index_moi] = g_doc_gia_ngay_het_han_the[i];
        g_doc_gia_thang_het_han_the[index_moi] = g_doc_gia_thang_het_han_the[i];
        g_doc_gia_nam_het_han_the[index_moi] = g_doc_gia_nam_het_han_the[i];
    }
    tong_so_luong_doc_gia--;
    printf("\nDa xoa doc gia CMND %s thanh cong\n\n", cmnd);
}

int tim_doc_gia_by_ho_va_ten(const char* ho_va_ten) {
    int i;
    for (i = 0; i < tong_so_luong_doc_gia; i++) {
        if (strcmp(ho_va_ten_at(i), ho_va_ten) == 0) {
            return i;
        }
    }
    return -1;
}

void tim_doc_gia_bang_cmnd() {
    char cmnd[LENGTH_CMND];
    nhap_chuoi("Nhap CMND can tim: ", cmnd, LENGTH_CMND);
    int index_cua_doc_gia = tim_doc_gia_by_cmnd(cmnd);
    if (index_cua_doc_gia == -1) {
        printf("Khong tim thay doc gia voi CMND.\n");
        return;
    }    
    print_doc_gia_theo_hang(index_cua_doc_gia);
}

void tim_doc_gia_bang_ho_va_ten() {
    char ho_va_ten[LENGTH_HO_VA_TEN];
    nhap_chuoi("Nhap ho va ten can tim: ", ho_va_ten, LENGTH_HO_VA_TEN);
    int index_cua_doc_gia = tim_doc_gia_by_ho_va_ten(ho_va_ten);
    if (index_cua_doc_gia == -1) {
        printf("Khong tim thay doc gia voi ho va ten.\n");
        return;
    }
    print_doc_gia_theo_hang(index_cua_doc_gia);
}

void cap_nhat_doc_gia() {
    char cmnd[LENGTH_CMND];
    nhap_chuoi("Nhap CMND cua doc gia can cap nhat: ", cmnd, LENGTH_CMND);
    int index_cua_doc_gia = tim_doc_gia_by_cmnd(cmnd);
    if (index_cua_doc_gia == -1) {
        printf("Khong tim thay doc gia voi CMND.\n");
        return;
    }
    print_doc_gia_theo_hang(index_cua_doc_gia);
    printf("Chon muc can cap nhat:\n1. Ho va ten\n2. CMND\n3. Ngay sinh\n4. Gioi tinh\n5. Email\n6. Dia chi\n7. Ngay lap the\n8. Ngay het han the\n");
    int option = nhap_so_nguyen("Lua chon cua ban: ", 1, 8);
    if (option == 1) {
        char ho_va_ten[LENGTH_HO_VA_TEN];
        nhap_chuoi("Ho va ten moi: ", ho_va_ten, LENGTH_HO_VA_TEN);
        luu_du_lieu_vao_vung_nho(ho_va_ten_at(index_cua_doc_gia), ho_va_ten);
    }
    if (option == 2) {
        char cmnd_moi[LENGTH_CMND];
        nhap_chuoi("CMND moi: ", cmnd_moi, LENGTH_CMND);
        luu_du_lieu_vao_vung_nho(cmnd_at(index_cua_doc_gia), cmnd_moi);
    }
    if (option == 3) {
        int ngay_sinh, thang_sinh, nam_sinh;
        nhap_ngay_thang_nam("Ngay thang nam sinh moi ", &ngay_sinh, &thang_sinh, &nam_sinh);
        g_doc_gia_ngay_sinh[index_cua_doc_gia] = ngay_sinh;
        g_doc_gia_thang_sinh[index_cua_doc_gia] = thang_sinh;
        g_doc_gia_nam_sinh[index_cua_doc_gia] = nam_sinh;
    }
    if (option == 4) {
        char gioi_tinh[LENGTH_GIOI_TINH];
        nhap_chuoi("Gioi tinh moi: ", gioi_tinh, LENGTH_GIOI_TINH);
        luu_du_lieu_vao_vung_nho(gioi_tinh_at(index_cua_doc_gia), gioi_tinh);
    }
    if (option == 5) {
        char email[LENGTH_EMAIL];
        nhap_chuoi("Email moi: ", email, LENGTH_EMAIL);
        luu_du_lieu_vao_vung_nho(email_at(index_cua_doc_gia), email);
    }
    if (option == 6) {
        char dia_chi[LENGTH_DIA_CHI];
        nhap_chuoi("Dia chi moi: ", dia_chi, LENGTH_DIA_CHI);
        luu_du_lieu_vao_vung_nho(dia_chi_at(index_cua_doc_gia), dia_chi);
    }
    if (option == 7) {
        int ngay_lap_the, thang_lap_the, nam_lap_the;
        nhap_ngay_thang_nam("Ngay thang nam lap the moi: ", &ngay_lap_the, &thang_lap_the, &nam_lap_the);
        g_doc_gia_ngay_lap_the[index_cua_doc_gia] = ngay_lap_the;
        g_doc_gia_thang_lap_the[index_cua_doc_gia] = thang_lap_the;
        g_doc_gia_nam_lap_the[index_cua_doc_gia] = nam_lap_the;
    }
    if (option == 8) {
        int ngay_het_han_the, thang_het_han_the, nam_het_han_the;
        nhap_ngay_thang_nam("Ngay thang nam het han the moi: ", &ngay_het_han_the, &thang_het_han_the, &nam_het_han_the);
        g_doc_gia_ngay_het_han_the[index_cua_doc_gia] = ngay_het_han_the;
        g_doc_gia_thang_het_han_the[index_cua_doc_gia] = thang_het_han_the;
        g_doc_gia_nam_het_han_the[index_cua_doc_gia] = nam_het_han_the;
    }
    printf("\nDa cap nhat thong tin doc gia CMND %s thanh cong\n\n", cmnd);
}