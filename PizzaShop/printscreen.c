#include <stdio.h>
#include <Windows.h>
int printMainScreen() {
	static int index;
	system("cls");
	printf("------------------------------\n");
	printf("1. Start\n");
	printf("2. Sales Check\n");
	printf("------------------------------\n");
	printf("번호를 입력해주세요: ");
	scanf("%d", &index);
	return index;
}

int printPosScreen() {
	static int index;
	system("cls");
	printf("------------------------------\n");
	printf("1. Order\n");
	printf("2. Pay\n");
	printf("3. Finish\n");
	printf("------------------------------\n");
	printf("번호를 입력해주세요: ");
	scanf("%d", &index);
	return index;
}