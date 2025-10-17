#include <stdio.h>
#include <string.h>

#include "utils.h"

int nhap_so_nguyen(const char* prompt, int min_val, int max_val) {
    char line[128];
    int val;
    while (1) {
        if (prompt && *prompt) {
            printf("%s", prompt);
            fflush(stdout);
        }
        if (!fgets(line, sizeof(line), stdin)) {
            continue;
        }
        // TODO: cần phải viết hàm trim để xóa khoảng trống của line
        if (line[0] == '\0') continue; // skip dòng không nhập gì
        char extra;
        // check xem có ký tự thừa không
        // ép kiểu: biến giá trị string nhập vào thành giá trị integer và gắn vào biến val thông qua địa chỉ &val
        // biến extra dùng để check có giá trị sau đó nữa không
        // vd: 123 -> đúng, nếu 123abc -> vẫn đúng nếu không có biến extra -> bug
        if (sscanf(line, "%d %c", &val, &extra) == 1) { 
            if (val < min_val || val > max_val) {
                printf("Vui long nhap trong khoang [%d %d].\n", min_val, max_val);
            }
            return val;
        } else {
            printf("Vui long nhap mot so nguyen.\n");
        };
    }
}

void nhap_chuoi(const char* prompt, char* buf, int max_len) {
    if (prompt && *prompt) {
        printf("%s", prompt);
    }
    if (fgets(buf, max_len, stdin) == NULL) {
        if (max_len > 0) buf[0] = '\0';
        return;
    }
    // Xóa ký tự xuống dòng (\n hoặc \r\n)
    size_t n = strlen(buf);
    if (n > 0 && buf[n-1] == '\n') buf[n-1] = '\0';
    n = strlen(buf);
    if (n > 0 && buf[n-1] == '\r') buf[n-1] = '\0';
}

void luu_du_lieu_vao_vung_nho(char* dest, const char* source) {
    strcpy(dest, source);
}

void luu_so_nguyen_vao_vung_nho(int* dest, int value) {
    *dest = value;
}

void press_enter_to_continue() {
    printf("Bam Enter de tiep tuc");
    fflush(stdout);
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {} // 
}

int check_nam_nhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int so_ngay_trong_thang(int thang, int nam) {
    const int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (thang == 2 && check_nam_nhuan(nam)) return 29;
    return days[thang];
}

int validate_ngay_thang_nam(int ngay, int thang, int nam) {
    if (nam < 1 || thang < 1|| thang > 12 || ngay < 1 || ngay > 31) return 0;
    int tong_ngay_trong_thang = so_ngay_trong_thang(thang, nam);
    return ngay <= tong_ngay_trong_thang;
}

int nhap_ngay_thang_nam(const char* label, int* ngay , int* thang, int* nam) {
    int day, month, year;
    while (1) {
        char prompt[128];
        snprintf(prompt, sizeof(prompt), "%s dd mm yyyy: ", label);
        printf("%s", prompt);
        fflush(stdout);
        char line[128];
        if (!fgets(line, sizeof(line), stdin)) continue;
        if (sscanf(line, "%d %d %d", &day, &month, &year) == 3) {
            if (validate_ngay_thang_nam(day, month, year)) {
                *ngay = day;
                *thang = month;
                *nam = year;
                return 1;
            } else {
                printf("Ngay thang nam khong hop le. Vui long thu lai.\n");
            }
        } else {
            printf("Vui long nhap dinh dang dd mm yyyy.\n");
        }
    }
}
