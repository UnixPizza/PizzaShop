#include "pizzashop.h"

int printMainScreen() {
	static int index;
	system("cls");
	printf("------------------------------\n");
	printf("\tPOS기 메인 화면\t\n");
	printf("------------------------------\n");

	printf("1. Start\n");
	printf("2. Sales Check\n");
	printf("3. Off\n");
	printf("------------------------------\n");
	printf("번호를 입력해주세요: ");
	scanf("%d", &index);
	return index;
}

int printPosScreen() {
	static int index;
	system("cls");
	printf("------------------------------\n");
	printf("\tPOS기 기능 선택\t\n");
	printf("------------------------------\n");
	printf("1. Order\n");
	printf("2. Pay\n");
	printf("3. Finish\n");
	printf("------------------------------\n");
	printf("번호를 입력해주세요: ");
	scanf("%d", &index);
	return index;
}

int printOrderScreen() {
	static int index;
	system("cls");
	printf("------------------------------\n");
	printf("\t메뉴 주문 화면\t\n");
	printf("------------------------------\n");
	printf("테이블 번호를 입력해주세요: ");
	scanf("%d", &index);
	return index;

}


void printTableOrderScreen(int table_num) {
	system("cls");
	printf("------------------------------\n");
	printf("\t테이블 %d번 주문\t\n", table_num);
	printf("------------------------------\n");
	printf("1. Combination Pizza(8,000)\n");
	printf("2. Potato Pizza(8,000)\n");
	printf("3. Pepperoni Pizza(7,000)\n");
	printf("4. Cheese Pizza(6,000)\n");
	printf("5. Tomato Pasta(4,000)\n");
	printf("6. Cream Pasta(5,000)\n");
	printf("7. Coke(2,000)\n");
	printf("8. Cider(2,000)\n");
	printf("------------------------------\n");
}