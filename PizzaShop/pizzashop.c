#include "pizzashop.h"
#include <stdio.h>
#include <Windows.h>
void orderFunc(Table* table) {
	static int food_idx;

	table->status = 1;				// ���̺� ��� ��

	while (1) {
		printf("�ֹ��Ͻ� ������ ��ȣ�� �����ϼ���(����: 0): ");
		scanf("%d", &food_idx);

		if (food_idx == 0)
			break;

		switch (food_idx)
		{
			break;
		case 1:
			printf("�ֹ��Ͻ� Combination Pizza�� ������ �Է����ּ���: ");
			scanf("%d", &table->Combination);
			break;
		case 2:
			printf("�ֹ��Ͻ� Potato Pizza�� ������ �Է����ּ���: ");
			scanf("%d", &table->Potato);
			break;
		case 3:
			printf("�ֹ��Ͻ� Pepperoni Pizza�� ������ �Է����ּ���: ");
			scanf("%d", &table->Pepperoni);
			break;
		case 4:
			printf("�ֹ��Ͻ� Cheese Pizza�� ������ �Է����ּ���: ");
			scanf("%d", &table->Cheese);
			break;
		case 5:
			printf("�ֹ��Ͻ� Tomato Pasta�� ������ �Է����ּ���: ");
			scanf("%d", &table->Tomato);
			break;
		case 6:
			printf("�ֹ��Ͻ� Cream Pasta�� ������ �Է����ּ���: ");
			scanf("%d", &table->Cream);
			break;
		case 7:
			printf("�ֹ��Ͻ� Coke�� ������ �Է����ּ���: ");
			scanf("%d", &table->Coke);
			break;
		case 8:
			printf("�ֹ��Ͻ� Cider �� ������ �Է����ּ���: ");
			scanf("%d", &table->Cider);
			break;

		default:
			printf("�߸� �Էµ� ��ȣ�Դϴ�.\n");
			break;
		}
	}
	table->TotalSales = table->Combination * 8000 + table->Potato * 8000 + table->Pepperoni * 7000 + table->Cheese * 6000 + table->Tomato * 4000 + table->Cream * 5000 + table->Coke * 2000 + table->Cider * 2000;
	printf("���̺� %d�� �� ������ : %d�Դϴ�.\n", table->ID, table->TotalSales);
	printf("------------------------------\n");
	Sleep(1000);
}