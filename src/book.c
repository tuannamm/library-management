#include <stdio.h>
#include <string.h>

#include "book.h"

void print_sach_theo_hang(int i) {
    printf("%s", i);
}


void get_list_sach() {
    printf("\n===Danh sach cac dau sach===\n\n");
    printf("Tong so luong sach hien co: %d\n\n", tong_so_luong_sach);

    int i;
    for (i = 0; i <= tong_so_luong_sach; i++) {
        print_sach_theo_hang(i);
    }

    if (tong_so_luong_sach == 0) printf("Hien tai chua co sach trong thu vien.\n\n");

}