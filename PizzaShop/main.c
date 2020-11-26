#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "pizzashop.h"
#include "printscreen.h"

int main_idx = 0;
int pos_idx = 0;
int table_idx = 0;
Table table[10] = { {1,0,},{2,0,},{3,0,},{4,0,},{5,0,},{6,0,},{7,0,},{8,0},{9,0},{10,0} };

int main() {

	while (1) {
		main_idx = printMainScreen();			// ���� ������ Start, Sales Check ���� ȭ�� ���
		if (main_idx == 1) {					// Start(index: 1) ��ư �Է� ��
			totalSalesOfDay = 0;
			while (1) {
				pos_idx = printPosScreen();				// ������ ��� ���� ȭ�� ���
				if (pos_idx == 1) {							// order ����
					while (1) {
						table_idx = printOrderScreen();			// order ȭ�� ���
						if (table_idx < 1 || table_idx > 10) {					// table ��ȣ ���� ó��
							printf("���̺� ��ȣ�� 1������ 10������ �Դϴ�.\n");
							Sleep(1000);
						}
						else if (table[table_idx - 1].status == 0) break;
						else {
							printf("�ش� ���̺��� �̹� ������Դϴ�.\n");
							Sleep(1000);
						}
					}
					printTableOrderScreen(table_idx);
					orderFunc(&table[table_idx - 1]);
				}
				else if (pos_idx == 2) {
					// call pay function
					payFunc(table);
				}
				else if (pos_idx == 3) {
					break;
				}
				else {
					printf("�߸� �Է��ϼ̽��ϴ�.\n");
				}
				Sleep(1000);
			}
		}
		else if (main_idx == 2) {
			printf("�� ������� %d�� �Դϴ�.\n", totalSalesOfDay);
			Sleep(1000);

		}
		else if (main_idx == 3) {
			return;
		}
		else {
			printf("�߸� �����̽��ϴ�.\n");
		}
		Sleep(1000);
	}
}