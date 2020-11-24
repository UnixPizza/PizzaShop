#define _CRT_SECURE_NO_WARNINGS
#include "pizzashop.h"
int main() {
	Table table[10];
	table[0].ID = 2;
	table[0].Combination = 1;
	table[0].Coke = 2;
	table[0].TotalSales = 12000;
	
	payFunc(table);

	return 0;
}