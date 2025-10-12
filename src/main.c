#include "utils.h"
#include <stdio.h>

int main() {
    // TODO: init data
    while(1) {
        printf("\n===== QUAN LI THU VIEN =====\n");
        printf("1. Quan li doc gia\n");
        printf("2. Quan li sach\n");
        printf("3. Lap phieu muon sach\n");
        printf("4. Lap phieu tra sach\n");
        printf("5. Cac thong ke co ban\n");
        printf("0. Thoat\n");
        int c = read_int("Chon : ", 0, 5);
        if (c == 0) return 0;
        if (c == 1) {
            printf("Chon option 1\n");
        }
        if (c == 2) {
            printf("Chon option 2\n");
        }
        if (c == 3) {
            printf("Chon option 3\n");
        }
        if (c == 4) {
            printf("Chon option 4\n");
        }
        if (c == 5) {
            printf("Chon option 5\n");
        }
        press_enter_to_continue();
    }
    return 0;
}