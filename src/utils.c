#include <stdio.h>
#include <string.h>

#include "utils.h"

// function đọc một số nguyên trong khoảng từ min_val đến max_val từ stdin với prompt và validation
// params: prompt, min_val, max_val
// return: số nguyên đọc được
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

// function: Bấm enter to continue, bỏ qua mọi thứ mọi người nhập cho đến khi nhập "enter"
void press_enter_to_continue() {
    printf("Bam Enter de tiep tuc");
    fflush(stdout);
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {} // 
}