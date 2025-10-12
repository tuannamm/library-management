#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>


// function đọc một số nguyên trong khoảng từ min_val đến max_val từ stdin với prompt và validation
// params: prompt; min_val, max_val
// return: số nguyên đọc được
int read_int(const char* prompt, int min_val, int max_val);

// function: Bấm enter to continue, bỏ qua mọi thứ mọi người nhập cho đến khi nhập "enter"
void press_enter_to_continue();


#endif