#include <stdio.h>
#include <string.h>

#include "stats.h"
#include "book.data.h"
#include "reader.data.h"

void thong_ke_sach() {
    long long total = 0;
    int i;
    for (i = 0; i < tong_so_luong_sach; i++) {
        total += g_sach_ban_sao[i];
    }
    printf("Tong so luong sach hien co: %lld\n", total);
}

void thong_ke_doc_gia() {
    printf("Tong so luong doc gia hien co: %d\n", tong_so_luong_doc_gia);
}

void thong_ke_doc_gia_theo_gioi_tinh() {
    int tong_nam = 0;
    int tong_nu =0;
    for (int i = 0; i < tong_so_luong_doc_gia; i++) {
        if (strcmp(g_doc_gia_gioi_tinh[i], "nam") == 0) {
            tong_nam++;
        } else if (strcmp(g_doc_gia_gioi_tinh[i], "nu") == 0) {
            tong_nu++;
        }
    }
    printf("Tong so luong doc gia nam: %d\n", tong_nam);
    printf("Tong so luong doc gia nu: %d\n", tong_nu);
}

void thong_ke_sach_theo_the_loai() {
    printf("\n=== THONG KE SACH THEO THE LOAI ===\n\n");
    
    if (tong_so_luong_sach == 0) {
        printf("Hien tai chua co sach trong thu vien.\n");
        return;
    }
    
    const char* the_loai_list[] = {
        "Programming",
        "Database",
        "Web Development",
        "Software Design",
        "Testing",
        "Networking",
        "Security",
        "AI/Machine Learning",
        "Mobile Development"
    };
    int so_the_loai = 9;
    
    printf("%-30s | %-15s | %-15s\n", "THE LOAI", "SO DAU SACH", "TONG SO SACH");
    printf("------------------------------------------------------------------\n");
    
    int tong_the_loai_co_sach = 0;
    
    for (int i = 0; i < so_the_loai; i++) {
        int so_dau_sach = 0;
        int tong_so_sach_loai = 0;
        
        for (int j = 0; j < tong_so_luong_sach; j++) {
            if (strcmp(the_loai_sach_at(j), the_loai_list[i]) == 0) {
                so_dau_sach++;
                tong_so_sach_loai += g_sach_ban_sao[j];
            }
        }
        
        if (so_dau_sach > 0) {
            printf("%-30s | %-15d | %-15d\n", the_loai_list[i], so_dau_sach, tong_so_sach_loai);
            tong_the_loai_co_sach++;
        }
    }
    
    printf("------------------------------------------------------------------\n");
    printf("Tong so the loai co sach: %d\n", tong_the_loai_co_sach);
}