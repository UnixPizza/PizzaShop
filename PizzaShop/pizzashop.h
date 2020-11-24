#pragma once

typedef struct _Table {
	int ID;
	int status;
	
	int Combination;
	int Potato;
	int Pepperoni;
	int Cheese;
	int Tomato;
	int Cream;
	int Coke;
	int Cider;

	int TotalSales;
}Table;

void orderFunc(Table* table);