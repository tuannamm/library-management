#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

// function đọc một số nguyên trong khoảng từ min_val đến max_val từ stdin với prompt và validation
// params: prompt; min_val, max_val
// return: số nguyên đọc được
int nhap_so_nguyen(const char* prompt, int min_val, int max_val);

// function nhập chuỗi từ stdin vào buffer
// params: propmt, buf - output buffer; max_len - buffer size
// return: none
void nhap_chuoi(const char* promp, char* buf, int max_len);

// function lưu dữ liệu vào vùng nhớ
// params: dest - địa chỉ vùng nhớ, source: dữ liệu
// return: none
void luu_du_lieu_vao_vung_nho(char* dest, const char* source);

// function lưu dữ liệu int vào vùng nhớ
// params: dest - địa chỉ vùng nhớ, value - giá trị int
// return: none
void luu_so_nguyen_vao_vung_nho(int* dest, int value);

// function Bấm enter to continue, bỏ qua mọi thứ mọi người nhập cho đến khi nhập "enter"
void press_enter_to_continue();

// function trả về số ngày trong một tháng của một năm
// params: month, year
// return: số ngày trong tháng
int so_ngay_trong_thang(int thang, int nam);

// function random mã đọc giả
int random_ma_doc_gia();

int validate_ngay_thang_nam(int ngay, int thang, int nam);

// function nhập ngày tháng năm
// params: prompt, ngày, tháng, năm
// return: 
int nhap_ngay_thang_nam(const char* label, int* ngay, int* thang, int* nam);

// function kiểm tra tháng có phải là năm nhuận không
// params: int thang
// return 1 nếu là năm nhuận, return 0 nếu không phải
int check_nam_nhuan(int nam);


// function tính ngày trả sách
// params: int ngay_muon, int thang_muon, int nam_muon,
// return: none
void tinh_ngay_han_tra_sach(int ngay_muon, int thang_muon, int nam_muon, int *ngay_tra, int *thang_tra, int *nam_tra); 

#endif