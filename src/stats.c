 
#include "stats.h" // gọi file header
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Hàm tính tổng doanh thu
void calculate_stats(){
	FILE* file = fopen("data/orders.txt", "r");
	if(!file) {
		printf("\nKhong the mo file orders.txt");
		return;
	}
	int totalRevenue = 0;
	int price = 0;
	while(fscanf(file, "%*s %d", &price) != EOF){  // %*s: bỏ qua 1 chuỗi
		totalRevenue += price;
	}
	fclose(file);
	
	printf("\nTotal Revenue: %d VND",totalRevenue);
}



//Hàm tìm món ăn bán chạy nhất
void find_best_selling(){
	FILE *file = fopen("data/orders.txt", "r");
	if(!file){
		printf("\nKhong the mo file orders.txt");
		return ;
	}
	
	char item[50]; // lưu từng món ăn đọc được
	char bestSelling[100];// lưu món bán chạy nhất
	int count[100] = {0}; // mảng đếm số lần mỗi món xuất hiện
	char items[100][50]; // lưu danh sach món ăn duy nhất
	int index = 0; // Số món đã lưu vào items
	int maxIndex = 0; // Chỉ số của món có số lần xuất hiện nhìu nhất
	//Đọc danh sách món ăn
	while(fscanf(file, "%s", item) != EOF){
		int found = 0;
		for(int i = 0; i <= index - 1; i++){
			if(strcmp(items[i], item) == 0){
				count[i]++;
				found = 1;
				break;
			}
		}
		if(!found){
			strcpy(items[index],item);
			count[index++] = 1;
		}
	}
	fclose(file);
	//Tìm món ăn bán chạy nhất
	for(int i = 0; i <= index - 1; i++){
		if(count[i] > count[maxIndex]){
			maxIndex = i;
		}
	}
	strcpy(bestSelling, items[maxIndex]);
	
	printf("\nBest Selling: %s",bestSelling);
}














