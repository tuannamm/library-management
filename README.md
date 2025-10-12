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

