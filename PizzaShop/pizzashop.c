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
	/*printf(totalSales);
	printf((pf + index)->Combination);*/

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
	/*fputs((pf+index)->ID,fp);
	fputs("\n", fp);
	fputs("ǰ��                                   �ܰ�       ����        �ݾ�", fp);
	fputs("\n-----------------------------------------------------------\n", fp);
	checkBilsCombination(pf,index, &fp);
	checkBilsPotato(pf, index, &fp);*/
	fclose(fp);
}

void checkBilsCombination(Table* pf, int index, FILE *fp) {
	if ((pf + index)->Combination != 0) {
		fputs("Combination pizza                ", fp);
		fputs("8,000      ", fp);
		fputs((pf + index)->Combination, fp);
		fputs("            ", fp);
		int price = 8000 * ((pf + index)->Combination);
		fputs(price, fp);
	}
}
void checkBilsPotato(Table* pf, int index, FILE* fp) {
	if ((pf + index)->Potato != 0) {
		fputs("Potato pizza                        ", fp);
		fputs("8,000      ", fp);
		fputs((pf + index)->Potato, fp);
		fputs("            ", fp);
		int price = 8000 * ((pf + index)->Potato);
		fputs(price, fp);
	}
}
