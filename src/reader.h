
#ifndef READER_H
#define READER_H

#include "reader.data.h"

// function in đọc giả theo hàng
// params: int i - index của đọc giả
// return: none
void print_doc_gia_theo_hang(int i);

// function lấy danh sách đọc giả
void get_danh_sach_doc_gia();

// function thêm đọc giả
int them_doc_gia();

// function validate mã đọc giả
int validate_ma_doc_gia();

// function tìm đọc giả được thêm thư viện bằng mã đọc giả
// params: char* ma_doc_gia
// return: 0 nếu chưa tồn tại, 1 nếu đã tồn tại
int tim_doc_gia_bang_ma(const char* ma_doc_gia);

#endif