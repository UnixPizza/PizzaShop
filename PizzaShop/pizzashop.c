#define _CRT_SECURE_NO_WARNINGS
#define _CRT_OBSOLETE_NO_WARNINGS
#include "pizzashop.h"


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
