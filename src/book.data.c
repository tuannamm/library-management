#include <string.h>

#include "book.data.h"


int tong_so_luong_sach = 0;

char g_sach_isbn[MAX_SO_LUONG_SACH *  LENGTH_ISBN];
char g_sach_tieu_de[MAX_SO_LUONG_SACH * LENGTH_TIEU_DE];
char g_sach_tac_gia[MAX_SO_LUONG_SACH * LENGTH_TAC_GIA];
char g_sach_nxb[MAX_SO_LUONG_SACH * LENGTH_NXB];
char g_sach_the_loai[MAX_SO_LUONG_SACH * LENGTH_THE_LOAI];
int  g_sach_nam_xuat_ban[MAX_SO_LUONG_SACH];
int  g_sach_gia[MAX_SO_LUONG_SACH];
int  g_sach_ban_sao[MAX_SO_LUONG_SACH];
int  g_sach_ban_sao_co_san[MAX_SO_LUONG_SACH];

void khoi_tao_du_lieu_book() {
    tong_so_luong_sach = 10;
    init_sample_data();
};

void init_sample_data() {
    struct {
        const char* isbn;
        const char* tieu_de;
        const char* tac_gia;
        const char* nxb;
        int nam_xuat_ban;
        const char* the_loai;
        int gia;
        int so_luong;
    } sach_mau[] = {
        {"978-0-13-110362-7", "The C Programming Language", "Brian W. Kernighan, Dennis M. Ritchie", "Prentice Hall", 1988, "Programming", 450000, 5},
        {"978-0-201-61622-4", "The Pragmatic Programmer", "David Thomas, Andrew Hunt", "Addison-Wesley", 1999, "Programming", 380000, 3},
        {"978-0-134-49418-4", "Clean Code", "Robert C. Martin", "Prentice Hall", 2008, "Programming", 520000, 4},
        {"978-0-201-63361-0", "Design Patterns", "Gang of Four", "Addison-Wesley", 1994, "Software Design", 650000, 2},
        {"978-0-596-00712-6", "Learning SQL", "Alan Beaulieu", "O'Reilly", 2009, "Database", 420000, 6},
        {"978-1-491-95031-5", "JavaScript: The Good Parts", "Douglas Crockford", "O'Reilly", 2008, "Web Development", 350000, 4},
        {"978-0-201-33456-7", "Refactoring", "Martin Fowler", "Addison-Wesley", 1999, "Programming", 480000, 3},
        {"978-0-596-00373-9", "HTTP: The Definitive Guide", "David Gourley, Brian Totty", "O'Reilly", 2002, "Web", 580000, 2},
        {"978-1-449-35818-8", "Eloquent JavaScript", "Marijn Haverbeke", "No Starch Press", 2014, "Web Development", 390000, 5},
        {"978-0-321-84268-8", "Growing Object-Oriented Software", "Steve Freeman, Nat Pryce", "Addison-Wesley", 2009, "Testing", 520000, 3}
    };
    
    int so_sach_mau = sizeof(sach_mau) / sizeof(sach_mau[0]);
    int i;
    for (i = 0; i < so_sach_mau; i++) {
        strcpy(isbn_sach_at(i), sach_mau[i].isbn);
        strcpy(tieu_de_sach_at(i), sach_mau[i].tieu_de);
        strcpy(tac_gia_sach_at(i), sach_mau[i].tac_gia);
        strcpy(nxb_sach_at(i), sach_mau[i].nxb);
        strcpy(the_loai_sach_at(i), sach_mau[i].the_loai);
        g_sach_nam_xuat_ban[i] = sach_mau[i].nam_xuat_ban;
        g_sach_gia[i] = sach_mau[i].gia;
        g_sach_ban_sao[i] = sach_mau[i].so_luong;
        g_sach_ban_sao_co_san[i] = sach_mau[i].so_luong;
    }
    
    tong_so_luong_sach = so_sach_mau;
};

char* isbn_sach_at(int index) {
    return &g_sach_isbn[index * LENGTH_ISBN];
};

char* tieu_de_sach_at(int index) {
    return &g_sach_tieu_de[index * LENGTH_TIEU_DE];
} 

char* tac_gia_sach_at(int index) {
    return &g_sach_tac_gia[index * LENGTH_TAC_GIA];
}

char* nxb_sach_at(int index) {
    return &g_sach_nxb[index * LENGTH_NXB];
}

char* the_loai_sach_at(int index) {
    return &g_sach_the_loai[index * LENGTH_THE_LOAI];
}