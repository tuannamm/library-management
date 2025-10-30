
#ifndef READER_H
#define READER_H

#include "reader.data.h"

// function in đọc giả theo hàng
// params: int i - index của đọc giả
// return: none
void print_doc_gia_theo_hang(int i);

// function lấy danh sách đọc giả
void get_danh_sach_doc_gia();

// function in độc giả bằng cmnd
void tim_doc_gia_bang_cmnd();

// function thêm đọc giả
int them_doc_gia();

// function validate mã đọc giả
int validate_ma_doc_gia(const char* ma_doc_gia);

// function tìm đọc giả được thêm thư viện bằng mã đọc giả
void tim_doc_gia_bang_ma();

// function tìm index độc giả bằng CMND
int tim_doc_gia_by_cmnd(const char* cmnd);

// function tim index đọc giả bằng mã đọc giả
int tim_doc_gia_by_ma(const char* ma_doc_gia);

// function xóa độc giả bằng mã độc giả
void xoa_doc_gia_bang_cmnd();

// function tìm độc giả bằng CMND
void tim_doc_gia_bang_cmnd();

// function tìm index độc giả bằng họ và tên
int tim_doc_gia_by_ho_va_ten(const char* ho_va_ten);

// function tìm độc giả bằng họ và tên
void tim_doc_gia_bang_ho_va_ten();

// function cập nhật độc giả 
void cap_nhat_doc_gia();

#endif