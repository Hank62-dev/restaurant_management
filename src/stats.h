/*Idea: 
Dữ liệu thống kê bao gồm:
- Doanh thu(Revenue): Tổng tiền bán được theo ngày/tháng
- Món bán chạy nhất(bestSelling): Món có số lượng bán nhiều nhất
Lưu ý: dữ liệu sẽ được tính toán từ orders.txt
 */


#ifndef STATS_H  // Kiểm tra nếu chưa được định nghĩa
#define STATS_H // Định nghĩa để tránh nạp lại file

#include <stdio.h>
#include <stdlib.h>

//Cấu trúc dữ liệu thống kê
typedef struct {
	int totalRevenue; // Tổng doanh thu
	char bestSelling[100]; // Tên món bán chạy nhất
	int bestSellingCount; // Số lượng món bán chạy nhất
} Stats;

//Khai báo hàm cần làm
void calculate_stats();
void find_best_selling();

#endif // kết thúc khai báo chương trình











