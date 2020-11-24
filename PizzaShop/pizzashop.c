#define _CRT_SECURE_NO_WARNINGS
#define _CRT_OBSOLETE_NO_WARNINGS
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

void payFunc(Table* pf)
{
	int tableID=0;
	int payNum = 0;
	int cash = 0;
	//구조체에서 TotalSales 가져오기
	char c;

	printf("--결제화면--\n");
	printf("테이블 번호를 입력하세요 : ");
	scanf("%d", &tableID);

	
	int totalSales = (pf+tableID-1)->TotalSales;
	int index = tableID - 1;

	printf("1.현금결제\n2.카드결제\n");
	scanf("%d", &payNum);
	if (payNum == 1) {
		printf("받은 금액 : ");
		scanf("%d", &cash);
		printf("거스름 돈 : %d\n", (cash - totalSales));
		_sleep(1000);
		//sleep(1000)
		writeBills(pf,index, cash, (cash - totalSales));
		printf("영수증을 출력하시겠습니까?(y/n) : ");
		getchar();
		scanf("%c", &c);
		if (c == 'y' || c == 'Y') {
			readBills(pf);
		}
		else if (c == 'N' || c == 'n') {
			system("cls");
			//clear();
			_sleep(1000);
			//sleep(1000)
			//메인함수
		}
	}
	else if(payNum==2) {
		printf("카드결제 중...\n");
		_sleep(1000);
		//sleep(1000)
		//파일 입출력
		writeBills(pf, index, totalSales, 0);
		printf("영수증을 출력하시겠습니까?(y/n) : ");
		getchar();
		scanf("%c", &c);
		if (c == 'y'|| c=='Y') {
			readBills(pf);
		}
		else if (c == 'N' || c == 'n') {
			system("cls");
			//clear();
			_sleep(1000);
			//sleep(1000)
			
		}

	}
	(pf+index)->status = 0;
	//같은 테이블을 사용할 경우 주문 메뉴가 초기화 되지 않아있다.

}

void readBills(Table* pf) {
	char line[255];
	FILE* fp = fopen("C:\\Users\\fishb\\Desktop\\bills.txt", "r");
	while (fgets(line, sizeof(line), fp) != NULL) {
		printf("%s",line);
	}
	fclose(fp);
	_sleep(5000);
}

void writeBills(Table* pf,int index,int cash,int change)
{
	FILE *fp = fopen("C:\\Users\\fishb\\Desktop\\bills.txt", "w");
	fputs("PizzaShop\n", fp);
	fputs("시간 : ",fp);
	fputs("\n", fp);
	fputs("ID : ", fp);
	char buffer[10] = { 0, };
	_itoa((pf + index)->ID, buffer, 10);
	fputs(buffer,fp);
	fputs("\n", fp);
	fputs("품명                                   단가       수량        금액", fp);
	fputs("\n-----------------------------------------------------------\n", fp);

	if ((pf + index)->Combination != 0) {
		fputs("Combination pizza                ", fp);
		fputs("8,000      ", fp);
		char buffer[10] = { 0, };
		_itoa((pf + index)->Combination, buffer, 10);
		fputs(buffer, fp);
		fputs("            ", fp);
		int price = 8000 * ((pf + index)->Combination);
		_itoa(price, buffer, 10);
		fputs(buffer, fp);
		fputs("\n", fp);
	}
	if ((pf + index)->Potato != 0) {
		fputs("Potato pizza                        ", fp);
		fputs("8,000      ", fp);
		char buffer[10] = { 0, };
		_itoa((pf + index)->Potato, buffer, 10);
		fputs(buffer, fp);
		fputs("            ", fp);
		int price = 8000 * ((pf + index)->Potato);
		_itoa(price, buffer, 10);
		fputs(buffer, fp);
		fputs("\n", fp);
	}
	if ((pf + index)->Pepperoni != 0) {
		fputs("Pepperoni pizza                   ", fp);
		fputs("7,000      ", fp);
		char buffer[10] = { 0, };
		_itoa((pf + index)->Pepperoni, buffer, 10);
		fputs(buffer, fp);
		fputs("            ", fp);
		int price = 7000 * ((pf + index)->Pepperoni);
		_itoa(price, buffer, 10);
		fputs(buffer, fp);
		fputs("\n", fp);
	}
	if ((pf + index)->Cheese != 0) {
		fputs("Cheese pizza                       ", fp);
		fputs("6,000      ", fp);
		char buffer[10] = { 0, };
		_itoa((pf + index)->Cheese, buffer, 10);
		fputs(buffer, fp);
		fputs("            ", fp);
		int price = 6000 * ((pf + index)->Cheese);
		_itoa(price, buffer, 10);
		fputs(buffer, fp);
		fputs("\n", fp);
	}
	if ((pf + index)->Tomato != 0) {
		fputs("Tomato pasta                      ", fp);
		fputs("4,000      ", fp);
		char buffer[10] = { 0, };
		_itoa((pf + index)->Tomato, buffer, 10);
		fputs(buffer, fp);
		fputs("            ", fp);
		int price = 4000 * ((pf + index)->Tomato);
		_itoa(price, buffer, 10);
		fputs(buffer, fp);
		fputs("\n", fp);
	}
	if ((pf + index)->Cream != 0) {
		fputs("Cream pasta                        ", fp);
		fputs("5,000      ", fp);
		char buffer[10] = { 0, };
		_itoa((pf + index)->Cream, buffer, 10);
		fputs(buffer, fp);
		fputs("            ", fp);
		int price = 5000 * ((pf + index)->Cream);
		_itoa(price, buffer, 10);
		fputs(buffer, fp);
		fputs("\n", fp);
	}
	if ((pf + index)->Coke != 0) {
		fputs("Coke                                  ", fp);
		fputs("2,000      ", fp);
		char buffer[10] = { 0, };
		_itoa((pf + index)->Coke, buffer, 10);
		fputs(buffer, fp);
		fputs("            ", fp);
		int price = 2000 * ((pf + index)->Coke);
		_itoa(price, buffer, 10);
		fputs(buffer, fp);
		fputs("\n", fp);
	}
	if ((pf + index)->Cider != 0) {
		fputs("Cider                                  ", fp);
		fputs("2,000      ", fp);
		char buffer[10] = { 0, };
		_itoa((pf + index)->Cider, buffer, 10);
		fputs(buffer, fp);
		fputs("            ", fp);
		int price = 2000 * ((pf + index)->Cider);
		_itoa(price, buffer, 10);
		fputs(buffer, fp);
		fputs("\n", fp);
	}
	fputs("\n-----------------------------------------------------------\n", fp);
	fputs("청구금액                                                         ", fp);
	_itoa((pf + index)->TotalSales, buffer, 10);
	fputs(buffer, fp);
	fputs("\n", fp);
	fputs("받은금액                                                         ", fp);
	_itoa(cash, buffer, 10);
	fputs(buffer, fp);
	fputs("\n", fp);
	fputs("거스름돈                                                         ", fp);
	_itoa(change, buffer, 10);
	fputs(buffer, fp);
	fputs("\n", fp);

	/*checkBilsCombination(pf,index, fp);
	checkBilsPotato(pf, index, fp);*/
	fclose(fp);
}

//void checkBilsCombination(Table* pf, int index, FILE *fp) {
//	if ((pf + index)->Combination != 0) {
//		fputs("Combination pizza                ", fp);
//		fputs("8,000      ", fp);
//		char buffer[10] = { 0, };
//		_itoa((pf + index)->Combination, buffer, 10);
//		fputs(buffer, fp);
//		fputs("            ", fp);
//		int price = 8000 * ((pf + index)->Combination);
//		_itoa(price, buffer, 10);
//		fputs(buffer, fp);
//	}
//}
//void checkBilsPotato(Table* pf, int index, FILE* fp) {
//	if ((pf + index)->Potato != 0) {
//		fputs("Potato pizza                        ", fp);
//		fputs("8,000      ", fp);
//		char buffer[10] = { 0, };
//		_itoa((pf + index)->Potato, buffer, 10);
//		fputs(buffer, fp);
//		fputs("            ", fp);
//		int price = 8000 * ((pf + index)->Potato);
//		_itoa(price, buffer, 10);
//		fputs(buffer, fp);
//	}
//}
