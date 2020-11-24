#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "pizzashop.h"
#include "printscreen.h"

int main_idx = 0;
int pos_idx = 0;

int main() {
	int status;
	while (1) {
		main_idx = printMainScreen();

		if (main_idx == 1) {
			while (1) {
				pos_idx = printPosScreen();
				if (pos_idx == 1) {
					// call order function
				}
				else if (pos_idx == 2) {
					// call pay function
				}
				else if (pos_idx == 3) {
					break;
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