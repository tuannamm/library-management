
#ifndef BOOK_H
#define BOOK_H

#include "data.h"

// function lấy show list sách và số lượng sách có trong thư viện
void get_list_sach();

// function in sách theo hàng
void print_sach_theo_hang(int i);

// function thêm sách vào thư viện
int them_sach();

// function xóa sách khỏi thư viện
void xoa_sach();

// function tìm sách được thêm thư viện bằng ISBN
// params: char* isbn
// return: 0 nếu chưa tồn tại, 1 nếu đã tồn tại
int tim_sach_bang_ISBN(const char* isbn); 

// function validate sách bằng ISBN
// params: char* isbn
// return 0 nếu chưa tồn tại, 1 nếu đã tồn tại
int validate_sach_by_isbn(const char* isbn);

#endif