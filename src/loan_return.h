#ifndef LOAN_RETURN_H
#define LOAN_RETURN_H

// Constants theo đề bài
#define PHAT_TRE_HAN_MOI_NGAY 5000      // 5,000 đồng/ngày
#define PHAT_MAT_SACH_PERCENT 200       // 200% giá sách

// function tính số ngày chênh lệch giữa 2 ngày
// params: ngay1, thang1, nam1, ngay2, thang2, nam2
// return: số ngày chênh lệch
int tinh_so_ngay_chenh_lech(int ngay1, int thang1, int nam1,
                             int ngay2, int thang2, int nam2);

// function tính tiền phạt trả trễ
// params: ngày trả dự kiến, ngày trả thực tế
// return: số tiền phạt (đồng)
int tinh_tien_phat_tre_han(int ngay_tra_du_kien, int thang_tra_du_kien, int nam_tra_du_kien,
                            int ngay_tra_thuc_te, int thang_tra_thuc_te, int nam_tra_thuc_te);

// function tính tiền phạt mất sách
// params: giá sách
// return: số tiền phạt (200% giá sách)
int tinh_tien_phat_mat_sach(int gia_sach);

// function lập phiếu trả sách
// return: none
void lap_phieu_tra_sach();

#endif
