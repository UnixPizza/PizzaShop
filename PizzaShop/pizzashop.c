#define _CRT_SECURE_NO_WARNINGS
#define _CRT_OBSOLETE_NO_WARNINGS
#include "pizzashop.h"


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

	int index = checkIndex(pf,tableID);
	
	int totalSales = (pf+index)->TotalSales;

	printf("1.현금결제\n2.카드결제\n");
	scanf("%d", &payNum);
	if (payNum == 1) {
		printf("받은 금액 : ");
		scanf("%d", &cash);
		printf("거스름 돈 : %d\n", (cash - totalSales));
		_sleep(1000);
		//sleep(1000)
		writeBills(pf,index);
		printf("영수증을 출력하시겠습니까?(y/n) : ");
		getchar();
		scanf("%c", &c);
		if (c == 'y' || c == 'Y') {

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
		writeBills(pf,index);
		printf("영수증을 출력하시겠습니까?(y/n) : ");
		getchar();
		scanf("%c", &c);
		if (c == 'y'|| c=='Y') {
			
		}
		else if (c == 'N' || c == 'n') {
			system("cls");
			//clear();
			_sleep(1000);
			//sleep(1000)
			//메인함수
		}
	}
}
int checkIndex(Table* pf, int tableID) {
	int index;
	for (int i = 0; i < 10; i++) {
		if ((pf + i)->ID == tableID) {
			index = i;
		}
	}
	return index;
}

void writeBills(Table* pf,int index)
{
	FILE *fp = fopen("C:\\Users\\fishb\\Desktop\\bills.txt", "w");
	fputs("PizzaShop\n", fp);
	fputs("시간 : ",fp);
	fputs("\n", fp);
	fputs("ID : ", fp);
	char buffer[5] = { 0, };
	_itoa((pf + index)->ID, buffer, 10);
	fputs(buffer,fp);
	fputs("\n", fp);
	fputs("품명                                   단가       수량        금액", fp);
	fputs("\n-----------------------------------------------------------\n", fp);
	if ((pf + index)->Combination != 0) {
		fputs("Combination pizza                ", fp);
		fputs("8,000      ", fp);
		char buffer[5] = { 0, };
		_itoa((pf + index)->Combination, buffer, 10);
		fputs(buffer, fp);
		fputs("            ", fp);
		int price = 8000 * ((pf + index)->Combination);
		_itoa(price, buffer, 10);
		fputs(buffer, fp);
	}
	/*checkBilsCombination(pf,index, &fp);*/
	//checkBilsPotato(pf, index, &fp);
	fclose(fp);
}

void checkBilsCombination(Table* pf, int index, FILE *fp) {
	if ((pf + index)->Combination != 0) {
		fputs("Combination pizza                ", fp);
		fputs("8,000      ", fp);
		char buffer[5] = { 0, };
		_itoa((pf + index)->Combination, buffer, 10);
		fputs(buffer, fp);
		fputs("            ", fp);
		int price = 8000 * ((pf + index)->Combination);
		_itoa(price, buffer, 10);
		fputs(buffer, fp);
	}
}
void checkBilsPotato(Table* pf, int index, FILE* fp) {
	if ((pf + index)->Potato != 0) {
		fputs("Potato pizza                        ", fp);
		fputs("8,000      ", fp);
		char buffer[5] = { 0, };
		_itoa((pf + index)->Potato, buffer, 10);
		fputs(buffer, fp);
		fputs("            ", fp);
		int price = 8000 * ((pf + index)->Potato);
		_itoa(price, buffer, 10);
		fputs(buffer, fp);
	}
}
