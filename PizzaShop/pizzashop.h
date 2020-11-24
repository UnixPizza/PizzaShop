#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdio.h>

typedef struct {
	int ID;

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

void payFunc(Table* pf);
void writeBills(Table* pf);
void checkBilsCombination(Table* pf,FILE* fp);
void checkBilsPotato(Table* pf, FILE* fp);