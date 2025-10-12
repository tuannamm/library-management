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
        switch(c) {
            case 1: 
                printf("Chon option 1\n");
                return 0;
            case 2: 
                printf("Chon option 2\n");
                return 0;
            case 3: 
                printf("Chon option 3\n");
                return 0;
            case 4: 
                printf("Chon option 4\n");
                return 0;
            case 5: 
                printf("Chon option 5\n");
                return 0;
        }
    }
}