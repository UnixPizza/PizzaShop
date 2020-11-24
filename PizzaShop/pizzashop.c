#include "pizzashop.h"
#include <stdio.h>
#include <Windows.h>
void orderFunc(Table* table) {
	static int food_idx;

	table->status = 1;				// 테이블 사용 중

	while (1) {
		printf("주문하실 음식의 번호를 선택하세요(종료: 0): ");
		scanf("%d", &food_idx);

		if (food_idx == 0)
			break;

		switch (food_idx)
		{
			break;
		case 1:
			printf("주문하실 Combination Pizza의 수량을 입력해주세요: ");
			scanf("%d", &table->Combination);
			break;
		case 2:
			printf("주문하실 Potato Pizza의 수량을 입력해주세요: ");
			scanf("%d", &table->Potato);
			break;
		case 3:
			printf("주문하실 Pepperoni Pizza의 수량을 입력해주세요: ");
			scanf("%d", &table->Pepperoni);
			break;
		case 4:
			printf("주문하실 Cheese Pizza의 수량을 입력해주세요: ");
			scanf("%d", &table->Cheese);
			break;
		case 5:
			printf("주문하실 Tomato Pasta의 수량을 입력해주세요: ");
			scanf("%d", &table->Tomato);
			break;
		case 6:
			printf("주문하실 Cream Pasta의 수량을 입력해주세요: ");
			scanf("%d", &table->Cream);
			break;
		case 7:
			printf("주문하실 Coke의 수량을 입력해주세요: ");
			scanf("%d", &table->Coke);
			break;
		case 8:
			printf("주문하실 Cider 의 수량을 입력해주세요: ");
			scanf("%d", &table->Cider);
			break;

		default:
			printf("잘못 입력된 번호입니다.\n");
			break;
		}
	}
	table->TotalSales = table->Combination * 8000 + table->Potato * 8000 + table->Pepperoni * 7000 + table->Cheese * 6000 + table->Tomato * 4000 + table->Cream * 5000 + table->Coke * 2000 + table->Cider * 2000;
	printf("테이블 %d의 총 가격은 : %d입니다.\n", table->ID, table->TotalSales);
	printf("------------------------------\n");
	Sleep(1000);
}