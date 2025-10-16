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

// function: Bấm enter to continue, bỏ qua mọi thứ mọi người nhập cho đến khi nhập "enter"
void press_enter_to_continue();

#endif