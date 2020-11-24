#define _CRT_SECURE_NO_WARNINGS
#define _CRT_OBSOLETE_NO_WARNINGS
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

void payFunc(Table* pf)
{
	int tableID=0;
	int payNum = 0;
	int cash = 0;
	//����ü���� TotalSales ��������
	char c;

	printf("--����ȭ��--\n");
	printf("���̺� ��ȣ�� �Է��ϼ��� : ");
	scanf("%d", &tableID);

	int index = checkIndex(pf,tableID);
	
	int totalSales = (pf+index)->TotalSales;

	printf("1.���ݰ���\n2.ī�����\n");
	scanf("%d", &payNum);
	if (payNum == 1) {
		printf("���� �ݾ� : ");
		scanf("%d", &cash);
		printf("�Ž��� �� : %d\n", (cash - totalSales));
		_sleep(1000);
		//sleep(1000)
		writeBills(pf,index);
		printf("�������� ����Ͻðڽ��ϱ�?(y/n) : ");
		getchar();
		scanf("%c", &c);
		if (c == 'y' || c == 'Y') {

		}
		else if (c == 'N' || c == 'n') {
			system("cls");
			//clear();
			_sleep(1000);
			//sleep(1000)
			//�����Լ�
		}
	}
	else if(payNum==2) {
		printf("ī����� ��...\n");
		_sleep(1000);
		//sleep(1000)
		//���� �����
		writeBills(pf,index);
		printf("�������� ����Ͻðڽ��ϱ�?(y/n) : ");
		getchar();
		scanf("%c", &c);
		if (c == 'y'|| c=='Y') {
			
		}
		else if (c == 'N' || c == 'n') {
			system("cls");
			//clear();
			_sleep(1000);
			//sleep(1000)
			//�����Լ�
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
	fputs("�ð� : ",fp);
	fputs("\n", fp);
	fputs("ID : ", fp);
	char buffer[5] = { 0, };
	_itoa((pf + index)->ID, buffer, 10);
	fputs(buffer,fp);
	fputs("\n", fp);
	fputs("ǰ��                                   �ܰ�       ����        �ݾ�", fp);
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
