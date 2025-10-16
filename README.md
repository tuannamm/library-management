- học được cách sử dụng của fgets và sự khác biệt của nó scanf
| Hàm       | Mục đích                                                                          |
| --------- | --------------------------------------------------------------------------------- |
| `scanf()` | Đọc dữ liệu **theo định dạng (format)** — ví dụ số nguyên, số thực, chuỗi, ký tự… |
| `fgets()` | Đọc **nguyên một dòng ký tự (string)** từ đầu vào, kể cả khoảng trắng             |

| Tiêu chí                      | `scanf()`                                   | `fgets()`                      |
| ----------------------------- | ------------------------------------------- | ------------------------------ |
| **Đọc chuỗi có khoảng trắng** | ❌ Không (dừng ở dấu cách)                   | ✅ Có                           |
| **Đọc cả dòng**               | ❌ Không                                     | ✅ Có                           |
| **Giới hạn độ dài nhập**      | ⚠️ Không (dễ tràn bộ nhớ nếu quên giới hạn) | ✅ Có (rất an toàn)             |
| **Giữ lại `\n`**              | ❌ Không                                     | ✅ Có                           |
| **Dễ dùng cho số**            | ✅ Có                                        | ❌ Cần `sscanf()` để chuyển đổi |
| **Xử lý lỗi nhập (sai kiểu)** | ❌ Khó, dễ crash hoặc kẹt                    | ✅ Dễ kiểm soát                 |
| **Khuyến nghị dùng**          | ❌ Tránh dùng trực tiếp                      | ✅ Ưu tiên (an toàn, linh hoạt) |

- extern
| Từ khóa             | Vai trò                             | Vùng nhớ | Khi nào dùng                                   |
| ------------------- | ----------------------------------- | -------- | ---------------------------------------------- |
| `int x = 0;`        | Định nghĩa biến toàn cục            | ✅ Có     | Chỉ một lần trong toàn chương trình            |
| `extern int x;`     | Khai báo biến đã tồn tại ở nơi khác | ❌ Không  | Dùng trong các file khác muốn truy cập biến đó |
| `static int x = 0;` | Biến toàn cục riêng tư trong file   | ✅ Có     | Không thể truy cập từ file khác                |
          ┌───────────────────┐
          │       RAM         │
          ├───────────────────┤
          │   x = 10          │ ← Được định nghĩa trong data.c
          │(sau cộng 2) x = 12| 
          │(sau trừ 1) x = 11 |
          └───────────────────┘
               ▲      ▲      ▲
               │      │      │
          sum.c   minus.c   result.c
(extern int x) (extern int x) (extern int x)

