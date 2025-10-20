#include <stdio.h>
#include <string.h>

#include "stats.h"
#include "book.data.h"

void thong_ke_sach() {
    long long total = 0;
    int i;
    for (i = 0; i < tong_so_luong_sach; i++) {
        total += g_sach_ban_sao[i];
    }
    printf("Tong so luong sach hien co: %lld\n", total);
}