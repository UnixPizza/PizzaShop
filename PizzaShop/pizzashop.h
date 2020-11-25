#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdio.h>

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

int totalSalesOfDay;

void payFunc(Table* pf);
void readBills(Table* pf);
void writeBills(Table* pf, int index, int cash, int change);

void checkBilsCombination(Table* pf, int index, FILE* fp);
void checkBilsPotato(Table* pf, int index, FILE* fp);
void orderFunc(Table* table);