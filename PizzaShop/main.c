#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "pizzashop.h"
#include "printscreen.h"

int main_idx = 0;
int pos_idx = 0;
int table_idx = 0;
Table table[10];

int main() {
	while (1) {
		main_idx = printMainScreen();			// 메인 페이지 Start, Sales Check 선택 화면 출력

		if (main_idx == 1) {					// Start(index: 1) 버튼 입력 시
			while (1) {
				pos_idx = printPosScreen();				// 포스기 기능 선택 화면 출력
				if (pos_idx == 1) {							// order 선택
					while (1) {
						table_idx = printOrderScreen();			// order 화면 출력
						if (table_idx < 1 || table_idx > 10){					// table 번호 예외 처리
							printf("테이블 번호는 1번부터 10번까지 입니다.\n");
							Sleep(1000);
						}
						else if (table[table_idx - 1].status == 0) break;
						else {
							printf("해당 테이블은 이미 사용중입니다.\n");
							Sleep(1000);
						}
					}
					printTableOrderScreen(table_idx);
					orderFunc(&table[table_idx - 1]);
				}
				else if (pos_idx == 2) {
					// call pay function
				}
				else if (pos_idx == 3) {
					break;
				}
				else {
					printf("잘못 입력하셨습니다.\n");
				}
				Sleep(1000);
			}
		}
		else if (main_idx == 2) {
			printf("Sales Check Clicked\n");
		}
		else {
			printf("잘못 누르셨습니다.\n");
		}
		Sleep(1000);
	}
}