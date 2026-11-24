#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include <windows.h>
#include <winuser.h>

void gotoxy(int x, int y) {
	COORD p = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

int main(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (1) {
		int op = 1;
		while (op != 0) {
			int pole[25][51];
			int pobed[3][3] = { 0 };
			int pobedo[3][3] = { 0 };
			int step1, step2, step3, step4, step5, step6, step7, step8, step9 = 0;
			step1 = step2 = step3 = step4 = step5 = step6 = step7 = step8 = step9 = 0;
			int pi1, pi2, pi3, pi4, pi5, pi6, pi7, pi8, pi9 = 8;
			int pj1, pj2, pj3, pj4, pj5, pj6, pj7, pj8, pj9 = 15;
			pj9 = pj1 = pj2 = pj3 = pj4 = pj5 = pj6 = pj7 = pj8 = 15;
			pi9 = pi1 = pi2 = pi3 = pi4 = pi5 = pi6 = pi7 = pi8 = 8;
			int menu1 = 0;
			int i, j = 0;
			char name1[20] = { 0 };
			char name2[20] = { 0 };
			char chek[32] = { 0 };
			int ch1, ch2, ch3, ch4, ch5, ch6, ch7, ch8, ch9, chm;
			int ch01, ch02, ch03, ch04, ch05, ch06, ch07, ch08, ch09, ch0m;

			system("cls");
			if (menu1 == 0) {

				for (i = 0; i < 25; i++)
				{
					for (j = 0; j < 51; j++)
					{
						if (i == 0 && j < 49) { printf("|"); }

						if (i == 21 && j < 49) { printf("|"); }
						if ((0 < i && i < 21) && (j == 0 || j == 47)) { printf("|"); }
						if ((0 < i) && (i < 21)) {
							if (j < 47) printf(" ");
						}
						if (i == 3 && j == 30) { printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"); printf("Hello, this is a "); }
						if (i == 5 && j == 29) { printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"); printf("TIC-TAC-TOE GAME"); }
						if (i == 8 && j == 27) { printf("\b\b\b\b\b\b\b\b\b\b\b\b"); printf("1.  New Game"); }
						if (i == 10 && j == 31) { printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"); printf("2.  How to play?"); }
						if (i == 12 && j == 23) { printf("\b\b\b\b\b\b\b\b"); printf("3.  Exit"); }
						if (i == 16 && j == 31) { printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"); printf("enter the number of"); }
						if (i == 17 && j == 29) { printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"); printf("the desired item"); }

						if (j == 50) { printf("\n"); }
					}
				}

			}

			fgets(chek, 31, stdin);
			gotoxy(0, 25);
			while (sscanf_s(chek, "%d", &menu1) != 1) {
				gotoxy(0, 25);
				printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
				gotoxy(0, 23);
				printf("Error, please enter a number from 1 to 3\n");
				gotoxy(0, 25);
				fgets(chek, 31, stdin);
			}
			chm = chek[0];
			ch0m = chek[1];
			gotoxy(0, 25);
			while (chm == 45 || ch0m != 10 || chm == 48 || chm > 51) {
				gotoxy(0, 25);
				printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
				gotoxy(0, 23);
				printf("Error, please enter a number from 1 to 3\n \n");
				gotoxy(0, 25);
				fgets(chek, 31, stdin);
				chm = chek[0];
				ch0m = chek[1];

			}
			if (chm == 49) { menu1 = 1; }if (chm == 50) { menu1 = 2; }if (chm == 51) { menu1 = 3; }

			if (menu1 == 2) {
				system("cls");
				printf("\n Инструкция \n 1. Что бы начать игру введите цифру 1 \n 2. Для того что бы сделать ход вводите цифру которой соответствует нужный квадрат \n 3. Первым в игре ходит крестик(Х) \n 4. В имени игрока можно внести максимум 20 символов \n 5. В случае превышения 20 символов, имя обрежется до 20 \n Пример: (если бы максимум было 10) \n Ввод : Putin_Vladimir \n Ваше имя в игре : Putin_Vlad \n\n\n");
				printf("\n\n enter 0 to return \n\n\n\n\n");



				fgets(chek, 31, stdin);
				while (sscanf_s(chek, "%d", &menu1) != 1) {
					gotoxy(0, 19);
					printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
					gotoxy(0, 14);
					printf("Error, please enter 0 \n");
					gotoxy(0, 19);

					fgets(chek, 31, stdin);
				}
				chm = chek[0];
				ch0m = chek[1];
				while (chm == 45 || ch0m != 10 || chm > 48) {
					gotoxy(0, 19);
					printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
					gotoxy(0, 14);
					printf("Error, please enter 0 \n");
					gotoxy(0, 19);
					fgets(chek, 31, stdin);
					chm = chek[0];
					ch0m = chek[1];
				}system("cls");
				if (chm == 48) { op = op - 1; }
			}


			if (menu1 == 3) {
				system("cls");
				exit(EXIT_SUCCESS);
			}
			if (menu1 == 1) {
				system("cls");
				if (menu1 == 1) {
					printf("Name up to 20 characters");
					printf("\n\n Enter name Player(X): ");
					fgets(name1, 20, stdin);

				}
				{
				}

				menu1 = menu1 + 10;

				if (menu1 == 11) {
					printf("[ Remember, if there are more than 20 characters, they will be cut off \n (press enter if there are less than 20 characters)");
					while (getchar() != '\n'); { }
					fflush(stdout);
					printf("\n\n Enter name Player(0):\n ");
					fflush(stdout);
					fgets(name2, 20, stdin);
					printf("[ Remember, if there are more than 20 characters, they will be cut off \n (press enter if there are less than 20 characters) ");
					while (getchar() != '\n'); { }
					printf("\n");
				}
			}
			menu1 = menu1 + 4;

			if (menu1 == 15) {
				system("cls");
				printf("Player(X): %s \b\b\b\b Player(0): %s ", name1, name2);
				printf("\n");



				for (i = 0; i < 25; i++)
				{
					for (j = 0; j < 51; j++)
					{

						if (i == 7 && j == 15) { printf("\b"); printf("7"); }
						if (i == 7 && j == 30) { printf("\b"); printf("8"); }
						if (i == 7 && j == 45) { printf("\b"); printf("9"); }
						if (i == 15 && j == 15) { printf("\b"); printf("4"); }
						if (i == 15 && j == 30) { printf("\b"); printf("5"); }
						if (i == 15 && j == 45) { printf("\b"); printf("6"); }
						if (i == 10 && j == 50) { printf("     Player(X):  now it's your turn  "); }
						if (i == 12 && j == 50) { printf("     Player(0):                      "); }
						if (i == 23 && j == 15) { printf("\b"); printf("1"); }
						if (i == 23 && j == 30) { printf("\b"); printf("2"); }
						if (i == 23 && j == 45) { printf("\b"); printf("3"); }

						if (i == 0 && j < 49) { printf("|"); }
						if (i == 8 && j < 49) { printf("|"); }
						if (i == 16 && j < 49) { printf("|"); }
						if (i == 24 && j < 49) { printf("|"); }
						if ((0 < i && i < 24 && i != 8 && i != 16) && (j == 0 || j == 47 || j == 15 || j == 30)) { printf("|"); }
						if ((0 < i) && (i < 24) && (i != 8) && (i != 16)) { if (j < 45) printf(" "); }


						if (j == 50) { printf("\n"); }
					}
				}
				gotoxy(0, 28);
				printf("Please enter a number from 1 to 9\n");
				gotoxy(0, 30);
				fgets(chek, 31, stdin);
				while (sscanf_s(chek, "%d", &step1) != 1) {
					gotoxy(0, 30);
					printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
					gotoxy(0, 28);
					printf("Error, Please enter a number from 1 to 9\n");
					gotoxy(0, 30);
					fgets(chek, 31, stdin);
				}
				ch1 = chek[0];
				ch01 = chek[1];
				while (ch1 == 45 || ch01 != 10 || ch1 == 48) {
					gotoxy(0, 30);
					printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
					gotoxy(0, 28);
					printf("Error, Please enter a number from 1 to 9\n");
					gotoxy(0, 30);
					fgets(chek, 31, stdin);
					ch1 = chek[0];
					ch01 = chek[1];

				}
				if (ch1 == 49) { step1 = 1; }if (ch1 == 50) { step1 = 2; }if (ch1 == 51) { step1 = 3; }
				if (ch1 == 52) { step1 = 4; }if (ch1 == 53) { step1 = 5; }if (ch1 == 54) { step1 = 6; }
				if (ch1 == 55) { step1 = 7; }if (ch1 == 56) { step1 = 8; }if (ch1 == 57) { step1 = 9; }

				if (step1 == 7) { pi1 = 0; pj1 = 0; pobed[0][0] = 1; }
				if (step1 == 8) { pi1 = 0; pj1 = pj1; pobed[0][1] = 1; }
				if (step1 == 9) { pi1 = 0; pj1 = pj1 * 2; pobed[0][2] = 1; }

				if (step1 == 4) { pi1 = pi1; pj1 = 0; pobed[1][0] = 1; }
				if (step1 == 5) { pi1 = pi1; pj1 = pj1; pobed[1][1] = 1; }
				if (step1 == 6) { pi1 = pi1; pj1 = pj1 * 2; pobed[1][2] = 1; }

				if (step1 == 1) { pi1 = pi1 * 2; pj1 = 0; pobed[2][0] = 1; }
				if (step1 == 2) { pi1 = pi1 * 2; pj1 = pj1 * 1; pobed[2][1] = 1; }
				if (step1 == 3) { pi1 = pi1 * 2; pj1 = pj1 * 2; pobed[2][2] = 1; }

				system("cls");
				printf("Player(X): %s \b\b\b\b Player(0): %s ", name1, name2);
				printf("\n");
				for (i = 0; i < 25; i++)
				{
					for (j = 0; j < 51; j++)
					{

						if (i == 7 && j == 15) { printf("\b"); printf("7"); }
						if (i == 7 && j == 30) { printf("\b"); printf("8"); }
						if (i == 7 && j == 45) { printf("\b"); printf("9"); }
						if (i == 15 && j == 15) { printf("\b"); printf("4"); }
						if (i == 15 && j == 30) { printf("\b"); printf("5"); }
						if (i == 15 && j == 45) { printf("\b"); printf("6"); }
						if (i == 10 && j == 50) { printf("     Player(X):    "); }
						if (i == 12 && j == 50) { printf("     Player(0):  now it's your turn "); }
						if (i == 23 && j == 15) { printf("\b"); printf("1"); }
						if (i == 23 && j == 30) { printf("\b"); printf("2"); }
						if (i == 23 && j == 45) { printf("\b"); printf("3"); }

						if (i == 0 && j < 49) { printf("|"); }
						if (i == 8 && j < 49) { printf("|"); }
						if (i == 16 && j < 49) { printf("|"); }
						if (i == 24 && j < 49) { printf("|"); }
						if ((0 < i && i < 24 && i != 8 && i != 16) && (j == 0 || j == 47 || j == 15 || j == 30)) { printf("|"); }
						if ((0 < i) && (i < 24) && (i != 8) && (i != 16)) { if (j < 45) printf(" "); }



						if ((i == 7 + (pi1) || i == 1 + (pi1)) && (j == 2 + (pj1) || j == 12 + (pj1))) { printf("\b"); printf("*"); }
						if ((i == 6 + (pi1) || i == 2 + (pi1)) && (j == 4 + (pj1) || j == 10 + (pj1))) { printf("\b"); printf("*"); }
						if ((i == 5 + (pi1) || i == 3 + (pi1)) && (j == 6 + (pj1) || j == 8 + (pj1))) { printf("\b"); printf("*"); }
						if ((i == 4 + (pi1)) && (j == 7 + (pj1))) { printf("\b"); printf("*"); }

						if (j == 50) { printf("\n"); }
					}
				}                                        ////////////////////////////////1 шаг конце






																				///////////////////////// 2 шаг
				chek[0] = 0;
				chek[1] = 0;
				gotoxy(0, 28);
				printf("Please enter a number from 1 to 9\n");
				gotoxy(0, 30);
				fgets(chek, 31, stdin);
				while (sscanf_s(chek, "%d", &step2) != 1) {
					gotoxy(0, 30);
					printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
					gotoxy(0, 28);
					printf("Error, Please enter a number from 1 to 9\n");
					gotoxy(0, 30);
					fgets(chek, 31, stdin);
				}
				ch2 = chek[0];
				ch02 = chek[1];
				while (ch2 == 45 || ch02 != 10 || ch2 == 48 || ch2 == 10) {
					gotoxy(0, 30);
					printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
					gotoxy(0, 28);
					printf("Error, Please enter a number from 1 to 9\n");
					gotoxy(0, 30);
					fgets(chek, 31, stdin);
					ch2 = chek[0];
					ch02 = chek[1];

				}


				while (ch1 == ch2) {
					gotoxy(0, 30);
					printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
					gotoxy(0, 28);
					printf("There has already been such a move! print another number\n");
					gotoxy(0, 30);

					fgets(chek, 31, stdin);
					ch2 = chek[0];
					ch02 = chek[1];
				}
				if (ch2 == 49) { step2 = 1; }if (ch2 == 50) { step2 = 2; }if (ch2 == 51) { step2 = 3; }
				if (ch2 == 52) { step2 = 4; }if (ch2 == 53) { step2 = 5; }if (ch2 == 54) { step2 = 6; }
				if (ch2 == 55) { step2 = 7; }if (ch2 == 56) { step2 = 8; }if (ch2 == 57) { step2 = 9; }



				if (step2 == 7) { pi2 = 0; pj2 = 0; pobedo[0][0] = 1; }
				if (step2 == 8) { pi2 = 0; pj2 = pj2; pobedo[0][1] = 1; }
				if (step2 == 9) { pi2 = 0; pj2 = pj2 * 2; pobedo[0][2] = 1; }

				if (step2 == 4) { pi2 = pi2; pj2 = 0; pobedo[1][0] = 1; }
				if (step2 == 5) { pi2 = pi2; pj2 = pj2; pobedo[1][1] = 1; }
				if (step2 == 6) { pi2 = pi2; pj2 = pj2 * 2; pobedo[1][2] = 1; }

				if (step2 == 1) { pi2 = pi2 * 2; pj2 = 0; pobedo[2][0] = 1; }
				if (step2 == 2) { pi2 = pi2 * 2; pj2 = pj2 * 1; pobedo[2][1] = 1; }
				if (step2 == 3) { pi2 = pi2 * 2; pj2 = pj2 * 2; pobedo[2][2] = 1; }
				system("cls");

				printf("Player(X): %s \b\b\b\b Player(0): %s ", name1, name2);
				printf("\n");
				for (i = 0; i < 25; i++)
				{
					for (j = 0; j < 51; j++)
					{

						if (i == 7 && j == 15) { printf("\b"); printf("7"); }
						if (i == 7 && j == 30) { printf("\b"); printf("8"); }
						if (i == 7 && j == 45) { printf("\b"); printf("9"); }
						if (i == 15 && j == 15) { printf("\b"); printf("4"); }
						if (i == 15 && j == 30) { printf("\b"); printf("5"); }
						if (i == 15 && j == 45) { printf("\b"); printf("6"); }
						if (i == 10 && j == 50) { printf("     Player(X):  now it's your turn  "); }
						if (i == 12 && j == 50) { printf("     Player(0):                      "); }
						if (i == 23 && j == 15) { printf("\b"); printf("1"); }
						if (i == 23 && j == 30) { printf("\b"); printf("2"); }
						if (i == 23 && j == 45) { printf("\b"); printf("3"); }

						if (i == 0 && j < 49) { printf("|"); }
						if (i == 8 && j < 49) { printf("|"); }
						if (i == 16 && j < 49) { printf("|"); }
						if (i == 24 && j < 49) { printf("|"); }
						if ((0 < i && i < 24 && i != 8 && i != 16) && (j == 0 || j == 47 || j == 15 || j == 30)) { printf("|"); }
						if ((0 < i) && (i < 24) && (i != 8) && (i != 16)) { if (j < 45) printf(" "); }


						if ((i == 7 + (pi1) || i == 1 + (pi1)) && (j == 2 + (pj1) || j == 12 + (pj1))) { printf("\b"); printf("*"); }
						if ((i == 6 + (pi1) || i == 2 + (pi1)) && (j == 4 + (pj1) || j == 10 + (pj1))) { printf("\b"); printf("*"); }
						if ((i == 5 + (pi1) || i == 3 + (pi1)) && (j == 6 + (pj1) || j == 8 + (pj1))) { printf("\b"); printf("*"); }
						if ((i == 4 + (pi1)) && (j == 7 + (pj1))) { printf("\b"); printf("*"); }

						if ((i == 4 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
						if ((i == 3 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
						if ((i == 5 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
						if ((i == 2 + (pi2) || i == 6 + (pi2)) && (j == 5 + (pj2) || j == 10 + (pj2))) { printf("\b"); printf("*"); }
						if ((i == 1 + (pi2) || i == 7 + (pi2)) && (j == 7 + (pj2) || j == 8 + (pj2))) { printf("\b"); printf("*"); }



						if (j == 50) { printf("\n"); }
					}
				}                                        ////////////////////////////////2 шаг конце



																		///////////////////////// 3 шаг
				chek[0] = 0;
				chek[1] = 0;
				gotoxy(0, 28);
				printf("Please enter a number from 1 to 9\n");
				gotoxy(0, 30);
				fgets(chek, 31, stdin);
				while (sscanf_s(chek, "%d", &step3) != 1) {
					gotoxy(0, 30);
					printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
					gotoxy(0, 28);
					printf("Error, Please enter a number from 1 to 9\n");
					gotoxy(0, 30);
					fgets(chek, 31, stdin);
				}
				ch3 = chek[0];
				ch03 = chek[1];

				while (ch3 == 45 || ch03 != 10 || ch3 == 48) {
					gotoxy(0, 30);
					printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
					gotoxy(0, 28);
					printf("Error, Please enter a number from 1 to 9\n");
					gotoxy(0, 30);
					fgets(chek, 31, stdin);
					ch3 = chek[0];
					ch03 = chek[1];
				}

				while ((ch2 == ch3) || (ch1 == ch3)) {
					gotoxy(0, 30);
					printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
					gotoxy(0, 28);
					printf("There has already been such a move! print another number\n");
					gotoxy(0, 30);
					fgets(chek, 31, stdin);
					ch3 = chek[0];
					ch03 = chek[1];
				}
				if (ch3 == 49) { step3 = 1; }if (ch3 == 50) { step3 = 2; }if (ch3 == 51) { step3 = 3; }
				if (ch3 == 52) { step3 = 4; }if (ch3 == 53) { step3 = 5; }if (ch3 == 54) { step3 = 6; }
				if (ch3 == 55) { step3 = 7; }if (ch3 == 56) { step3 = 8; }if (ch3 == 57) { step3 = 9; }


				if (step3 == 7) { pi3 = 0; pj3 = 0; pobed[0][0] = 1; }
				if (step3 == 8) { pi3 = 0; pj3 = pj3; pobed[0][1] = 1; }
				if (step3 == 9) { pi3 = 0; pj3 = pj3 * 2; pobed[0][2] = 1; }

				if (step3 == 4) { pi3 = pi3; pj3 = 0; pobed[1][0] = 1; }
				if (step3 == 5) { pi3 = pi3; pj3 = pj3; pobed[1][1] = 1; }
				if (step3 == 6) { pi3 = pi3; pj3 = pj3 * 2; pobed[1][2] = 1; }

				if (step3 == 1) { pi3 = pi3 * 2; pj3 = 0; pobed[2][0] = 1; }
				if (step3 == 2) { pi3 = pi3 * 2; pj3 = pj3 * 1; pobed[2][1] = 1; }
				if (step3 == 3) { pi3 = pi3 * 2; pj3 = pj3 * 2; pobed[2][2] = 1; }
				system("cls");
				printf("Player(X): %s \b\b\b\b Player(0): %s ", name1, name2);
				printf("\n");
				for (i = 0; i < 25; i++)
				{
					for (j = 0; j < 51; j++)
					{

						if (i == 7 && j == 15) { printf("\b"); printf("7"); }
						if (i == 7 && j == 30) { printf("\b"); printf("8"); }
						if (i == 7 && j == 45) { printf("\b"); printf("9"); }
						if (i == 15 && j == 15) { printf("\b"); printf("4"); }
						if (i == 15 && j == 30) { printf("\b"); printf("5"); }
						if (i == 15 && j == 45) { printf("\b"); printf("6"); }
						if (i == 10 && j == 50) { printf("     Player(X):    "); }
						if (i == 12 && j == 50) { printf("     Player(0):  now it's your turn "); }
						if (i == 23 && j == 15) { printf("\b"); printf("1"); }
						if (i == 23 && j == 30) { printf("\b"); printf("2"); }
						if (i == 23 && j == 45) { printf("\b"); printf("3"); }

						if (i == 0 && j < 49) { printf("|"); }
						if (i == 8 && j < 49) { printf("|"); }
						if (i == 16 && j < 49) { printf("|"); }
						if (i == 24 && j < 49) { printf("|"); }
						if ((0 < i && i < 24 && i != 8 && i != 16) && (j == 0 || j == 47 || j == 15 || j == 30)) { printf("|"); }
						if ((0 < i) && (i < 24) && (i != 8) && (i != 16)) { if (j < 45) printf(" "); }


						if ((i == 7 + (pi1) || i == 1 + (pi1)) && (j == 2 + (pj1) || j == 12 + (pj1))) { printf("\b"); printf("*"); }
						if ((i == 6 + (pi1) || i == 2 + (pi1)) && (j == 4 + (pj1) || j == 10 + (pj1))) { printf("\b"); printf("*"); }
						if ((i == 5 + (pi1) || i == 3 + (pi1)) && (j == 6 + (pj1) || j == 8 + (pj1))) { printf("\b"); printf("*"); }
						if ((i == 4 + (pi1)) && (j == 7 + (pj1))) { printf("\b"); printf("*"); }

						if ((i == 4 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
						if ((i == 3 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
						if ((i == 5 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
						if ((i == 2 + (pi2) || i == 6 + (pi2)) && (j == 5 + (pj2) || j == 10 + (pj2))) { printf("\b"); printf("*"); }
						if ((i == 1 + (pi2) || i == 7 + (pi2)) && (j == 7 + (pj2) || j == 8 + (pj2))) { printf("\b"); printf("*"); }


						if ((i == 7 + (pi3) || i == 1 + (pi3)) && (j == 2 + (pj3) || j == 12 + (pj3))) { printf("\b"); printf("*"); }
						if ((i == 6 + (pi3) || i == 2 + (pi3)) && (j == 4 + (pj3) || j == 10 + (pj3))) { printf("\b"); printf("*"); }
						if ((i == 5 + (pi3) || i == 3 + (pi3)) && (j == 6 + (pj3) || j == 8 + (pj3))) { printf("\b"); printf("*"); }
						if ((i == 4 + (pi3)) && (j == 7 + (pj3))) { printf("\b"); printf("*"); }




						if (j == 50) { printf("\n"); }
					}
				}                                        ////////////////////////////////3 шаг конце


																 ///////////////////////// 4 шаг
				chek[0] = 0;
				chek[1] = 0;
				gotoxy(0, 28);
				printf("Please enter a number from 1 to 9\n");
				gotoxy(0, 30);
				fgets(chek, 31, stdin);
				while (sscanf_s(chek, "%d", &step4) != 1) {
					gotoxy(0, 30);
					printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
					gotoxy(0, 28);
					printf("Error, Please enter a number from 1 to 9\n");
					gotoxy(0, 30);
					fgets(chek, 31, stdin);
				}
				ch4 = chek[0];
				ch04 = chek[1];

				while (ch4 == 45 || ch04 != 10 || ch4 == 48) {
					gotoxy(0, 30);
					printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
					gotoxy(0, 28);
					printf("Error, Please enter a number from 1 to 9\n");
					gotoxy(0, 30);
					fgets(chek, 31, stdin);
					ch4 = chek[0];
					ch04 = chek[1];
				}

				while ((ch2 == ch4) || (ch1 == ch4) || (ch3 == ch4)) {
					gotoxy(0, 30);
					printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
					gotoxy(0, 28);
					printf("There has already been such a move! print another number\n");
					gotoxy(0, 30);
					fgets(chek, 31, stdin);
					ch4 = chek[0];
					ch04 = chek[1];
				}
				if (ch4 == 49) { step4 = 1; }if (ch4 == 50) { step4 = 2; }if (ch4 == 51) { step4 = 3; }
				if (ch4 == 52) { step4 = 4; }if (ch4 == 53) { step4 = 5; }if (ch4 == 54) { step4 = 6; }
				if (ch4 == 55) { step4 = 7; }if (ch4 == 56) { step4 = 8; }if (ch4 == 57) { step4 = 9; }

				if (step4 == 7) { pi4 = 0; pj4 = 0; pobedo[0][0] = 1; }
				if (step4 == 8) { pi4 = 0; pj4 = pj4; pobedo[0][1] = 1; }
				if (step4 == 9) { pi4 = 0; pj4 = pj4 * 2; pobedo[0][2] = 1; }

				if (step4 == 4) { pi4 = pi4; pj4 = 0; pobedo[1][0] = 1; }
				if (step4 == 5) { pi4 = pi4; pj4 = pj4; pobedo[1][1] = 1; }
				if (step4 == 6) { pi4 = pi4; pj4 = pj4 * 2; pobedo[1][2] = 1; }

				if (step4 == 1) { pi4 = pi4 * 2; pj4 = 0; pobedo[2][0] = 1; }
				if (step4 == 2) { pi4 = pi4 * 2; pj4 = pj4 * 1; pobedo[2][1] = 1; }
				if (step4 == 3) { pi4 = pi4 * 2; pj4 = pj4 * 2; pobedo[2][2] = 1; }
				system("cls");
				printf("Player(X): %s \b\b\b\b Player(0): %s ", name1, name2);
				printf("\n");
				for (i = 0; i < 25; i++)
				{
					for (j = 0; j < 51; j++)
					{

						if (i == 7 && j == 15) { printf("\b"); printf("7"); }
						if (i == 7 && j == 30) { printf("\b"); printf("8"); }
						if (i == 7 && j == 45) { printf("\b"); printf("9"); }
						if (i == 15 && j == 15) { printf("\b"); printf("4"); }
						if (i == 15 && j == 30) { printf("\b"); printf("5"); }
						if (i == 15 && j == 45) { printf("\b"); printf("6"); }
						if (i == 10 && j == 50) { printf("     Player(X):  now it's your turn  "); }
						if (i == 12 && j == 50) { printf("     Player(0):                      "); }
						if (i == 23 && j == 15) { printf("\b"); printf("1"); }
						if (i == 23 && j == 30) { printf("\b"); printf("2"); }
						if (i == 23 && j == 45) { printf("\b"); printf("3"); }

						if (i == 0 && j < 49) { printf("|"); }
						if (i == 8 && j < 49) { printf("|"); }
						if (i == 16 && j < 49) { printf("|"); }
						if (i == 24 && j < 49) { printf("|"); }
						if ((0 < i && i < 24 && i != 8 && i != 16) && (j == 0 || j == 47 || j == 15 || j == 30)) { printf("|"); }
						if ((0 < i) && (i < 24) && (i != 8) && (i != 16)) { if (j < 45) printf(" "); }


						if ((i == 7 + (pi1) || i == 1 + (pi1)) && (j == 2 + (pj1) || j == 12 + (pj1))) { printf("\b"); printf("*"); }
						if ((i == 6 + (pi1) || i == 2 + (pi1)) && (j == 4 + (pj1) || j == 10 + (pj1))) { printf("\b"); printf("*"); }
						if ((i == 5 + (pi1) || i == 3 + (pi1)) && (j == 6 + (pj1) || j == 8 + (pj1))) { printf("\b"); printf("*"); }
						if ((i == 4 + (pi1)) && (j == 7 + (pj1))) { printf("\b"); printf("*"); }

						if ((i == 4 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
						if ((i == 3 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
						if ((i == 5 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
						if ((i == 2 + (pi2) || i == 6 + (pi2)) && (j == 5 + (pj2) || j == 10 + (pj2))) { printf("\b"); printf("*"); }
						if ((i == 1 + (pi2) || i == 7 + (pi2)) && (j == 7 + (pj2) || j == 8 + (pj2))) { printf("\b"); printf("*"); }


						if ((i == 7 + (pi3) || i == 1 + (pi3)) && (j == 2 + (pj3) || j == 12 + (pj3))) { printf("\b"); printf("*"); }
						if ((i == 6 + (pi3) || i == 2 + (pi3)) && (j == 4 + (pj3) || j == 10 + (pj3))) { printf("\b"); printf("*"); }
						if ((i == 5 + (pi3) || i == 3 + (pi3)) && (j == 6 + (pj3) || j == 8 + (pj3))) { printf("\b"); printf("*"); }
						if ((i == 4 + (pi3)) && (j == 7 + (pj3))) { printf("\b"); printf("*"); }

						if ((i == 4 + (pi4)) && (j == 3 + (pj4) || j == 12 + (pj4))) { printf("\b"); printf("*"); }
						if ((i == 3 + (pi4)) && (j == 3 + (pj4) || j == 12 + (pj4))) { printf("\b"); printf("*"); }
						if ((i == 5 + (pi4)) && (j == 3 + (pj4) || j == 12 + (pj4))) { printf("\b"); printf("*"); }
						if ((i == 2 + (pi4) || i == 6 + (pi4)) && (j == 5 + (pj4) || j == 10 + (pj4))) { printf("\b"); printf("*"); }
						if ((i == 1 + (pi4) || i == 7 + (pi4)) && (j == 7 + (pj4) || j == 8 + (pj4))) { printf("\b"); printf("*"); }



						if (j == 50) { printf("\n"); }
					}
				}                                        ////////////////////////////////4 шаг конце


																	///////////////////////// 5 шаг
				chek[0] = 0;
				chek[1] = 0;
				gotoxy(0, 28);
				printf("Please enter a number from 1 to 9\n");
				gotoxy(0, 30);
				fgets(chek, 31, stdin);
				while (sscanf_s(chek, "%d", &step5) != 1) {
					gotoxy(0, 30);
					printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
					gotoxy(0, 28);
					printf("Error, Please enter a number from 1 to 9\n");
					gotoxy(0, 30);
					fgets(chek, 31, stdin);
				}
				ch5 = chek[0];
				ch05 = chek[1];

				while (ch5 == 45 || ch05 != 10 || ch5 == 48) {
					gotoxy(0, 30);
					printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
					gotoxy(0, 28);
					printf("Error, Please enter a number from 1 to 9\n");
					gotoxy(0, 30);
					fgets(chek, 31, stdin);
					ch5 = chek[0];
					ch05 = chek[1];
				}

				while ((ch2 == ch5) || (ch1 == ch5) || (ch3 == ch5) || (ch4 == ch5)) {
					gotoxy(0, 30);
					printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
					gotoxy(0, 28);
					printf("There has already been such a move! print another number\n");
					gotoxy(0, 30);
					fgets(chek, 31, stdin);
					ch5 = chek[0];
					ch05 = chek[1];
				}
				if (ch5 == 49) { step5 = 1; }if (ch5 == 50) { step5 = 2; }if (ch5 == 51) { step5 = 3; }
				if (ch5 == 52) { step5 = 4; }if (ch5 == 53) { step5 = 5; }if (ch5 == 54) { step5 = 6; }
				if (ch5 == 55) { step5 = 7; }if (ch5 == 56) { step5 = 8; }if (ch5 == 57) { step5 = 9; }


				if (step5 == 7) { pi5 = 0; pj5 = 0; pobed[0][0] = 1; }
				if (step5 == 8) { pi5 = 0; pj5 = pj5; pobed[0][1] = 1; }
				if (step5 == 9) { pi5 = 0; pj5 = pj5 * 2; pobed[0][2] = 1; }

				if (step5 == 4) { pi5 = pi5; pj5 = 0; pobed[1][0] = 1; }
				if (step5 == 5) { pi5 = pi5; pj5 = pj5; pobed[1][1] = 1; }
				if (step5 == 6) { pi5 = pi5; pj5 = pj5 * 2; pobed[1][2] = 1; }

				if (step5 == 1) { pi5 = pi5 * 2; pj5 = 0; pobed[2][0] = 1; }
				if (step5 == 2) { pi5 = pi5 * 2; pj5 = pj5 * 1; pobed[2][1] = 1; }
				if (step5 == 3) { pi5 = pi5 * 2; pj5 = pj5 * 2; pobed[2][2] = 1; }
				system("cls");
				printf("Player(X): %s \b\b\b\b Player(0): %s ", name1, name2);
				printf("\n");
				for (i = 0; i < 25; i++)
				{
					for (j = 0; j < 51; j++)
					{

						if (i == 7 && j == 15) { printf("\b"); printf("7"); }
						if (i == 7 && j == 30) { printf("\b"); printf("8"); }
						if (i == 7 && j == 45) { printf("\b"); printf("9"); }
						if (i == 15 && j == 15) { printf("\b"); printf("4"); }
						if (i == 15 && j == 30) { printf("\b"); printf("5"); }
						if (i == 15 && j == 45) { printf("\b"); printf("6"); }
						if (i == 10 && j == 50) { printf("     Player(X):    "); }
						if (i == 12 && j == 50) { printf("     Player(0):  now it's your turn "); }
						if (i == 23 && j == 15) { printf("\b"); printf("1"); }
						if (i == 23 && j == 30) { printf("\b"); printf("2"); }
						if (i == 23 && j == 45) { printf("\b"); printf("3"); }

						if (i == 0 && j < 49) { printf("|"); }
						if (i == 8 && j < 49) { printf("|"); }
						if (i == 16 && j < 49) { printf("|"); }
						if (i == 24 && j < 49) { printf("|"); }
						if ((0 < i && i < 24 && i != 8 && i != 16) && (j == 0 || j == 47 || j == 15 || j == 30)) { printf("|"); }
						if ((0 < i) && (i < 24) && (i != 8) && (i != 16)) { if (j < 45) printf(" "); }


						if ((i == 7 + (pi1) || i == 1 + (pi1)) && (j == 2 + (pj1) || j == 12 + (pj1))) { printf("\b"); printf("*"); }
						if ((i == 6 + (pi1) || i == 2 + (pi1)) && (j == 4 + (pj1) || j == 10 + (pj1))) { printf("\b"); printf("*"); }
						if ((i == 5 + (pi1) || i == 3 + (pi1)) && (j == 6 + (pj1) || j == 8 + (pj1))) { printf("\b"); printf("*"); }
						if ((i == 4 + (pi1)) && (j == 7 + (pj1))) { printf("\b"); printf("*"); }

						if ((i == 4 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
						if ((i == 3 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
						if ((i == 5 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
						if ((i == 2 + (pi2) || i == 6 + (pi2)) && (j == 5 + (pj2) || j == 10 + (pj2))) { printf("\b"); printf("*"); }
						if ((i == 1 + (pi2) || i == 7 + (pi2)) && (j == 7 + (pj2) || j == 8 + (pj2))) { printf("\b"); printf("*"); }


						if ((i == 7 + (pi3) || i == 1 + (pi3)) && (j == 2 + (pj3) || j == 12 + (pj3))) { printf("\b"); printf("*"); }
						if ((i == 6 + (pi3) || i == 2 + (pi3)) && (j == 4 + (pj3) || j == 10 + (pj3))) { printf("\b"); printf("*"); }
						if ((i == 5 + (pi3) || i == 3 + (pi3)) && (j == 6 + (pj3) || j == 8 + (pj3))) { printf("\b"); printf("*"); }
						if ((i == 4 + (pi3)) && (j == 7 + (pj3))) { printf("\b"); printf("*"); }

						if ((i == 4 + (pi4)) && (j == 3 + (pj4) || j == 12 + (pj4))) { printf("\b"); printf("*"); }
						if ((i == 3 + (pi4)) && (j == 3 + (pj4) || j == 12 + (pj4))) { printf("\b"); printf("*"); }
						if ((i == 5 + (pi4)) && (j == 3 + (pj4) || j == 12 + (pj4))) { printf("\b"); printf("*"); }
						if ((i == 2 + (pi4) || i == 6 + (pi4)) && (j == 5 + (pj4) || j == 10 + (pj4))) { printf("\b"); printf("*"); }
						if ((i == 1 + (pi4) || i == 7 + (pi4)) && (j == 7 + (pj4) || j == 8 + (pj4))) { printf("\b"); printf("*"); }

						if ((i == 7 + (pi5) || i == 1 + (pi5)) && (j == 2 + (pj5) || j == 12 + (pj5))) { printf("\b"); printf("*"); }
						if ((i == 6 + (pi5) || i == 2 + (pi5)) && (j == 4 + (pj5) || j == 10 + (pj5))) { printf("\b"); printf("*"); }
						if ((i == 5 + (pi5) || i == 3 + (pi5)) && (j == 6 + (pj5) || j == 8 + (pj5))) { printf("\b"); printf("*"); }
						if ((i == 4 + (pi5)) && (j == 7 + (pj5))) { printf("\b"); printf("*"); }


						if (j == 50) { printf("\n"); }
					}
				}                                        ////////////////////////////////5 шаг конце
				if (((pobed[0][0] + pobed[0][1] + pobed[0][2]) == 3) || ((pobed[1][0] + pobed[1][1] + pobed[1][2]) == 3) ||
					((pobed[2][0] + pobed[2][1] + pobed[2][2]) == 3) || ((pobed[0][0] + pobed[1][0] + pobed[2][0]) == 3) ||
					((pobed[0][1] + pobed[1][1] + pobed[2][1]) == 3) || ((pobed[0][2] + pobed[1][2] + pobed[2][2]) == 3) ||
					((pobed[0][2] + pobed[1][1] + pobed[2][0]) == 3) || ((pobed[0][0] + pobed[1][1] + pobed[2][2]) == 3)) {

					printf("Player(X): %s WIN!", name1);

					gotoxy(0, 32);
					printf("\n press 0 to return to the main menu \n");
					gotoxy(0, 35);
					fgets(chek, 31, stdin);
					while (sscanf_s(chek, "%d", &menu1) != 1) {
						gotoxy(0, 35);
						printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
						gotoxy(0, 33);
						printf("Error, please enter 0 \n");
						gotoxy(0, 35);
						fgets(chek, 31, stdin);
					}
					chm = chek[0];
					ch0m = chek[1];
					while (chm == 45 || ch0m != 10 || chm > 48) {
						gotoxy(0, 35);
						printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
						gotoxy(0, 33);
						printf("Error, please enter 0 \n");
						gotoxy(0, 35);
						fgets(chek, 31, stdin);
						chm = chek[0];
						ch0m = chek[1];
					}
					if (chm == 48) { op = op - 1; }

				}
				else if (((pobedo[0][0] + pobedo[0][1] + pobedo[0][2]) == 3) || ((pobedo[1][0] + pobedo[1][1] + pobedo[1][2]) == 3) ||
					((pobedo[2][0] + pobedo[2][1] + pobedo[2][2]) == 3) || ((pobedo[0][0] + pobedo[1][0] + pobedo[2][0]) == 3) ||
					((pobedo[0][1] + pobedo[1][1] + pobedo[2][1]) == 3) || ((pobedo[0][2] + pobedo[1][2] + pobedo[2][2]) == 3) ||
					((pobedo[0][2] + pobedo[1][1] + pobedo[2][0]) == 3) || ((pobedo[0][0] + pobedo[1][1] + pobedo[2][2]) == 3)) {

					printf("Player(0): %s WIN!", name2);
					gotoxy(0, 32);
					printf("\n press 0 to return to the main menu \n");
					gotoxy(0, 35);
					fgets(chek, 31, stdin);
					while (sscanf_s(chek, "%d", &menu1) != 1) {
						gotoxy(0, 35);
						printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
						gotoxy(0, 33);
						printf("Error, please enter 0 \n");
						gotoxy(0, 35);
						fgets(chek, 31, stdin);
					}
					chm = chek[0];
					ch0m = chek[1];
					while (chm == 45 || ch0m != 10 || chm > 48) {
						gotoxy(0, 35);
						printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
						gotoxy(0, 33);
						printf("Error, please enter 0 \n");
						gotoxy(0, 35);
						fgets(chek, 31, stdin);
						chm = chek[0];
						ch0m = chek[1];
					}
					if (chm == 48) { op = op - 1; }

				}

				else {
					///////////////////////// 6 шаг
					chek[0] = 0;
					chek[1] = 0;
					gotoxy(0, 28);
					printf("Please enter a number from 1 to 9\n");
					gotoxy(0, 30);
					fgets(chek, 31, stdin);
					while (sscanf_s(chek, "%d", &step6) != 1) {
						gotoxy(0, 30);
						printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
						gotoxy(0, 28);
						printf("Error, Please enter a number from 1 to 9\n");
						gotoxy(0, 30);
						fgets(chek, 31, stdin);
					}
					ch6 = chek[0];
					ch06 = chek[1];

					while (ch6 == 45 || ch06 != 10 || ch6 == 48) {
						gotoxy(0, 30);
						printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
						gotoxy(0, 28);
						printf("Error, Please enter a number from 1 to 9\n");
						gotoxy(0, 30);
						fgets(chek, 31, stdin);
						ch6 = chek[0];
						ch06 = chek[1];
					}

					while ((ch2 == ch6) || (ch1 == ch6) || (ch3 == ch6) || (ch4 == ch6) || (ch5 == ch6)) {
						gotoxy(0, 30);
						printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
						gotoxy(0, 28);
						printf("There has already been such a move! print another number\n");
						gotoxy(0, 30);
						fgets(chek, 31, stdin);
						ch6 = chek[0];
						ch06 = chek[1];
					}
					if (ch6 == 49) { step6 = 1; }if (ch6 == 50) { step6 = 2; }if (ch6 == 51) { step6 = 3; }
					if (ch6 == 52) { step6 = 4; }if (ch6 == 53) { step6 = 5; }if (ch6 == 54) { step6 = 6; }
					if (ch6 == 55) { step6 = 7; }if (ch6 == 56) { step6 = 8; }if (ch6 == 57) { step6 = 9; }


					if (step6 == 7) { pi6 = 0; pj6 = 0; pobedo[0][0] = 1; }
					if (step6 == 8) { pi6 = 0; pj6 = pj6; pobedo[0][1] = 1; }
					if (step6 == 9) { pi6 = 0; pj6 = pj6 * 2; pobedo[0][2] = 1; }

					if (step6 == 4) { pi6 = pi6; pj6 = 0; pobedo[1][0] = 1; }
					if (step6 == 5) { pi6 = pi6; pj6 = pj6; pobedo[1][1] = 1; }
					if (step6 == 6) { pi6 = pi6; pj6 = pj6 * 2; pobedo[1][2] = 1; }

					if (step6 == 1) { pi6 = pi6 * 2; pj6 = 0; pobedo[2][0] = 1; }
					if (step6 == 2) { pi6 = pi6 * 2; pj6 = pj6 * 1; pobedo[2][1] = 1; }
					if (step6 == 3) { pi6 = pi6 * 2; pj6 = pj6 * 2; pobedo[2][2] = 1; }
					system("cls");

					printf("Player(X): %s \b\b\b\b Player(0): %s ", name1, name2);
					printf("\n");
					for (i = 0; i < 25; i++)
					{
						for (j = 0; j < 51; j++)
						{

							if (i == 7 && j == 15) { printf("\b"); printf("7"); }
							if (i == 7 && j == 30) { printf("\b"); printf("8"); }
							if (i == 7 && j == 45) { printf("\b"); printf("9"); }
							if (i == 15 && j == 15) { printf("\b"); printf("4"); }
							if (i == 15 && j == 30) { printf("\b"); printf("5"); }
							if (i == 10 && j == 50) { printf("     Player(X):  now it's your turn  "); }
							if (i == 12 && j == 50) { printf("     Player(0):                      "); }
							if (i == 15 && j == 45) { printf("\b"); printf("6"); }
							if (i == 23 && j == 15) { printf("\b"); printf("1"); }
							if (i == 23 && j == 30) { printf("\b"); printf("2"); }
							if (i == 23 && j == 45) { printf("\b"); printf("3"); }

							if (i == 0 && j < 49) { printf("|"); }
							if (i == 8 && j < 49) { printf("|"); }
							if (i == 16 && j < 49) { printf("|"); }
							if (i == 24 && j < 49) { printf("|"); }
							if ((0 < i && i < 24 && i != 8 && i != 16) && (j == 0 || j == 47 || j == 15 || j == 30)) { printf("|"); }
							if ((0 < i) && (i < 24) && (i != 8) && (i != 16)) { if (j < 45) printf(" "); }


							if ((i == 7 + (pi1) || i == 1 + (pi1)) && (j == 2 + (pj1) || j == 12 + (pj1))) { printf("\b"); printf("*"); }
							if ((i == 6 + (pi1) || i == 2 + (pi1)) && (j == 4 + (pj1) || j == 10 + (pj1))) { printf("\b"); printf("*"); }
							if ((i == 5 + (pi1) || i == 3 + (pi1)) && (j == 6 + (pj1) || j == 8 + (pj1))) { printf("\b"); printf("*"); }
							if ((i == 4 + (pi1)) && (j == 7 + (pj1))) { printf("\b"); printf("*"); }

							if ((i == 4 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
							if ((i == 3 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
							if ((i == 5 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
							if ((i == 2 + (pi2) || i == 6 + (pi2)) && (j == 5 + (pj2) || j == 10 + (pj2))) { printf("\b"); printf("*"); }
							if ((i == 1 + (pi2) || i == 7 + (pi2)) && (j == 7 + (pj2) || j == 8 + (pj2))) { printf("\b"); printf("*"); }


							if ((i == 7 + (pi3) || i == 1 + (pi3)) && (j == 2 + (pj3) || j == 12 + (pj3))) { printf("\b"); printf("*"); }
							if ((i == 6 + (pi3) || i == 2 + (pi3)) && (j == 4 + (pj3) || j == 10 + (pj3))) { printf("\b"); printf("*"); }
							if ((i == 5 + (pi3) || i == 3 + (pi3)) && (j == 6 + (pj3) || j == 8 + (pj3))) { printf("\b"); printf("*"); }
							if ((i == 4 + (pi3)) && (j == 7 + (pj3))) { printf("\b"); printf("*"); }

							if ((i == 4 + (pi4)) && (j == 3 + (pj4) || j == 12 + (pj4))) { printf("\b"); printf("*"); }
							if ((i == 3 + (pi4)) && (j == 3 + (pj4) || j == 12 + (pj4))) { printf("\b"); printf("*"); }
							if ((i == 5 + (pi4)) && (j == 3 + (pj4) || j == 12 + (pj4))) { printf("\b"); printf("*"); }
							if ((i == 2 + (pi4) || i == 6 + (pi4)) && (j == 5 + (pj4) || j == 10 + (pj4))) { printf("\b"); printf("*"); }
							if ((i == 1 + (pi4) || i == 7 + (pi4)) && (j == 7 + (pj4) || j == 8 + (pj4))) { printf("\b"); printf("*"); }

							if ((i == 7 + (pi5) || i == 1 + (pi5)) && (j == 2 + (pj5) || j == 12 + (pj5))) { printf("\b"); printf("*"); }
							if ((i == 6 + (pi5) || i == 2 + (pi5)) && (j == 4 + (pj5) || j == 10 + (pj5))) { printf("\b"); printf("*"); }
							if ((i == 5 + (pi5) || i == 3 + (pi5)) && (j == 6 + (pj5) || j == 8 + (pj5))) { printf("\b"); printf("*"); }
							if ((i == 4 + (pi5)) && (j == 7 + (pj5))) { printf("\b"); printf("*"); }

							if ((i == 4 + (pi6)) && (j == 3 + (pj6) || j == 12 + (pj6))) { printf("\b"); printf("*"); }
							if ((i == 3 + (pi6)) && (j == 3 + (pj6) || j == 12 + (pj6))) { printf("\b"); printf("*"); }
							if ((i == 5 + (pi6)) && (j == 3 + (pj6) || j == 12 + (pj6))) { printf("\b"); printf("*"); }
							if ((i == 2 + (pi6) || i == 6 + (pi6)) && (j == 5 + (pj6) || j == 10 + (pj6))) { printf("\b"); printf("*"); }
							if ((i == 1 + (pi6) || i == 7 + (pi6)) && (j == 7 + (pj6) || j == 8 + (pj6))) { printf("\b"); printf("*"); }


							if (j == 50) { printf("\n"); }
						}
					}

					////////////////////////////////6 шаг конце
					if (((pobed[0][0] + pobed[0][1] + pobed[0][2]) == 3) || ((pobed[1][0] + pobed[1][1] + pobed[1][2]) == 3) ||
						((pobed[2][0] + pobed[2][1] + pobed[2][2]) == 3) || ((pobed[0][0] + pobed[1][0] + pobed[2][0]) == 3) ||
						((pobed[0][1] + pobed[1][1] + pobed[2][1]) == 3) || ((pobed[0][2] + pobed[1][2] + pobed[2][2]) == 3) ||
						((pobed[0][2] + pobed[1][1] + pobed[2][0]) == 3) || ((pobed[0][0] + pobed[1][1] + pobed[2][2]) == 3)) {

						printf("Player(X): %s WIN!", name1);
						gotoxy(0, 32);
						printf("\n press 0 to return to the main menu \n");
						gotoxy(0, 35);
						fgets(chek, 31, stdin);
						while (sscanf_s(chek, "%d", &menu1) != 1) {
							gotoxy(0, 35);
							printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
							gotoxy(0, 33);
							printf("Error, please enter 0 \n");
							gotoxy(0, 35);
							fgets(chek, 31, stdin);
						}
						chm = chek[0];
						ch0m = chek[1];
						while (chm == 45 || ch0m != 10 || chm > 48) {
							gotoxy(0, 35);
							printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
							gotoxy(0, 33);
							printf("Error, please enter 0 \n");
							gotoxy(0, 35);
							fgets(chek, 31, stdin);
							chm = chek[0];
							ch0m = chek[1];
						}
						if (chm == 48) { op = op - 1; }

					}
					else if (((pobedo[0][0] + pobedo[0][1] + pobedo[0][2]) == 3) || ((pobedo[1][0] + pobedo[1][1] + pobedo[1][2]) == 3) ||
						((pobedo[2][0] + pobedo[2][1] + pobedo[2][2]) == 3) || ((pobedo[0][0] + pobedo[1][0] + pobedo[2][0]) == 3) ||
						((pobedo[0][1] + pobedo[1][1] + pobedo[2][1]) == 3) || ((pobedo[0][2] + pobedo[1][2] + pobedo[2][2]) == 3) ||
						((pobedo[0][2] + pobedo[1][1] + pobedo[2][0]) == 3) || ((pobedo[0][0] + pobedo[1][1] + pobedo[2][2]) == 3)) {

						printf("Player(0): %s WIN!", name2);
						gotoxy(0, 32);
						printf("\n press 0 to return to the main menu \n");
						gotoxy(0, 35);
						fgets(chek, 31, stdin);
						while (sscanf_s(chek, "%d", &menu1) != 1) {
							gotoxy(0, 35);
							printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
							gotoxy(0, 33);
							printf("Error, please enter 0 \n");
							gotoxy(0, 35);
							fgets(chek, 31, stdin);
						}
						chm = chek[0];
						ch0m = chek[1];
						while (chm == 45 || ch0m != 10 || chm > 48) {
							gotoxy(0, 35);
							printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
							gotoxy(0, 33);
							printf("Error, please enter 0 \n");
							gotoxy(0, 35);
							fgets(chek, 31, stdin);
							chm = chek[0];
							ch0m = chek[1];
						}
						if (chm == 48) { op = op - 1; }

					}

					else {


						///////////////////////// 7 шаг
						chek[0] = 0;
						chek[1] = 0;
						gotoxy(0, 28);
						printf("Please enter a number from 1 to 9\n");
						gotoxy(0, 30);
						fgets(chek, 31, stdin);
						while (sscanf_s(chek, "%d", &step7) != 1) {
							gotoxy(0, 30);
							printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
							gotoxy(0, 28);
							printf("Error, Please enter a number from 1 to 9\n");
							gotoxy(0, 30);
							fgets(chek, 31, stdin);
						}
						ch7 = chek[0];
						ch07 = chek[1];

						while (ch7 == 45 || ch07 != 10 || ch7 == 48) {
							gotoxy(0, 30);
							printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
							gotoxy(0, 28);
							printf("Error, Please enter a number from 1 to 9\n");
							gotoxy(0, 30);
							fgets(chek, 31, stdin);
							ch7 = chek[0];
							ch07 = chek[1];
						}

						while ((ch2 == ch7) || (ch1 == ch7) || (ch3 == ch7) || (ch4 == ch7) || (ch5 == ch7) || (ch6 == ch7)) {
							gotoxy(0, 30);
							printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
							gotoxy(0, 28);
							printf("There has already been such a move! print another number\n");
							gotoxy(0, 30);
							fgets(chek, 31, stdin);
							ch7 = chek[0];
							ch07 = chek[1];
						}
						if (ch7 == 49) { step7 = 1; }if (ch7 == 50) { step7 = 2; }if (ch7 == 51) { step7 = 3; }
						if (ch7 == 52) { step7 = 4; }if (ch7 == 53) { step7 = 5; }if (ch7 == 54) { step7 = 6; }
						if (ch7 == 55) { step7 = 7; }if (ch7 == 56) { step7 = 8; }if (ch7 == 57) { step7 = 9; }



						if (step7 == 7) { pi7 = 0; pj7 = 0; pobed[0][0] = 1; }
						if (step7 == 8) { pi7 = 0; pj7 = pj7; pobed[0][1] = 1; }
						if (step7 == 9) { pi7 = 0; pj7 = pj7 * 2; pobed[0][2] = 1; }

						if (step7 == 4) { pi7 = pi7; pj7 = 0; pobed[1][0] = 1; }
						if (step7 == 5) { pi7 = pi7; pj7 = pj7; pobed[1][1] = 1; }
						if (step7 == 6) { pi7 = pi7; pj7 = pj7 * 2; pobed[1][2] = 1; }

						if (step7 == 1) { pi7 = pi7 * 2; pj7 = 0; pobed[2][0] = 1; }
						if (step7 == 2) { pi7 = pi7 * 2; pj7 = pj7 * 1; pobed[2][1] = 1; }
						if (step7 == 3) { pi7 = pi7 * 2; pj7 = pj7 * 2; pobed[2][2] = 1; }
						system("cls");
						printf("Player(X): %s \b\b\b\b Player(0): %s ", name1, name2);
						printf("\n");
						for (i = 0; i < 25; i++)
						{
							for (j = 0; j < 51; j++)
							{

								if (i == 7 && j == 15) { printf("\b"); printf("7"); }
								if (i == 7 && j == 30) { printf("\b"); printf("8"); }
								if (i == 7 && j == 45) { printf("\b"); printf("9"); }
								if (i == 15 && j == 15) { printf("\b"); printf("4"); }
								if (i == 15 && j == 30) { printf("\b"); printf("5"); }
								if (i == 15 && j == 45) { printf("\b"); printf("6"); }
								if (i == 10 && j == 50) { printf("     Player(X):    "); }
								if (i == 12 && j == 50) { printf("     Player(0):  now it's your turn "); }
								if (i == 23 && j == 15) { printf("\b"); printf("1"); }
								if (i == 23 && j == 30) { printf("\b"); printf("2"); }
								if (i == 23 && j == 45) { printf("\b"); printf("3"); }

								if (i == 0 && j < 49) { printf("|"); }
								if (i == 8 && j < 49) { printf("|"); }
								if (i == 16 && j < 49) { printf("|"); }
								if (i == 24 && j < 49) { printf("|"); }
								if ((0 < i && i < 24 && i != 8 && i != 16) && (j == 0 || j == 47 || j == 15 || j == 30)) { printf("|"); }
								if ((0 < i) && (i < 24) && (i != 8) && (i != 16)) { if (j < 45) printf(" "); }


								if ((i == 7 + (pi1) || i == 1 + (pi1)) && (j == 2 + (pj1) || j == 12 + (pj1))) { printf("\b"); printf("*"); }
								if ((i == 6 + (pi1) || i == 2 + (pi1)) && (j == 4 + (pj1) || j == 10 + (pj1))) { printf("\b"); printf("*"); }
								if ((i == 5 + (pi1) || i == 3 + (pi1)) && (j == 6 + (pj1) || j == 8 + (pj1))) { printf("\b"); printf("*"); }
								if ((i == 4 + (pi1)) && (j == 7 + (pj1))) { printf("\b"); printf("*"); }

								if ((i == 4 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
								if ((i == 3 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
								if ((i == 5 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
								if ((i == 2 + (pi2) || i == 6 + (pi2)) && (j == 5 + (pj2) || j == 10 + (pj2))) { printf("\b"); printf("*"); }
								if ((i == 1 + (pi2) || i == 7 + (pi2)) && (j == 7 + (pj2) || j == 8 + (pj2))) { printf("\b"); printf("*"); }


								if ((i == 7 + (pi3) || i == 1 + (pi3)) && (j == 2 + (pj3) || j == 12 + (pj3))) { printf("\b"); printf("*"); }
								if ((i == 6 + (pi3) || i == 2 + (pi3)) && (j == 4 + (pj3) || j == 10 + (pj3))) { printf("\b"); printf("*"); }
								if ((i == 5 + (pi3) || i == 3 + (pi3)) && (j == 6 + (pj3) || j == 8 + (pj3))) { printf("\b"); printf("*"); }
								if ((i == 4 + (pi3)) && (j == 7 + (pj3))) { printf("\b"); printf("*"); }

								if ((i == 4 + (pi4)) && (j == 3 + (pj4) || j == 12 + (pj4))) { printf("\b"); printf("*"); }
								if ((i == 3 + (pi4)) && (j == 3 + (pj4) || j == 12 + (pj4))) { printf("\b"); printf("*"); }
								if ((i == 5 + (pi4)) && (j == 3 + (pj4) || j == 12 + (pj4))) { printf("\b"); printf("*"); }
								if ((i == 2 + (pi4) || i == 6 + (pi4)) && (j == 5 + (pj4) || j == 10 + (pj4))) { printf("\b"); printf("*"); }
								if ((i == 1 + (pi4) || i == 7 + (pi4)) && (j == 7 + (pj4) || j == 8 + (pj4))) { printf("\b"); printf("*"); }

								if ((i == 7 + (pi5) || i == 1 + (pi5)) && (j == 2 + (pj5) || j == 12 + (pj5))) { printf("\b"); printf("*"); }
								if ((i == 6 + (pi5) || i == 2 + (pi5)) && (j == 4 + (pj5) || j == 10 + (pj5))) { printf("\b"); printf("*"); }
								if ((i == 5 + (pi5) || i == 3 + (pi5)) && (j == 6 + (pj5) || j == 8 + (pj5))) { printf("\b"); printf("*"); }
								if ((i == 4 + (pi5)) && (j == 7 + (pj5))) { printf("\b"); printf("*"); }

								if ((i == 4 + (pi6)) && (j == 3 + (pj6) || j == 12 + (pj6))) { printf("\b"); printf("*"); }
								if ((i == 3 + (pi6)) && (j == 3 + (pj6) || j == 12 + (pj6))) { printf("\b"); printf("*"); }
								if ((i == 5 + (pi6)) && (j == 3 + (pj6) || j == 12 + (pj6))) { printf("\b"); printf("*"); }
								if ((i == 2 + (pi6) || i == 6 + (pi6)) && (j == 5 + (pj6) || j == 10 + (pj6))) { printf("\b"); printf("*"); }
								if ((i == 1 + (pi6) || i == 7 + (pi6)) && (j == 7 + (pj6) || j == 8 + (pj6))) { printf("\b"); printf("*"); }

								if ((i == 7 + (pi7) || i == 1 + (pi7)) && (j == 2 + (pj7) || j == 12 + (pj7))) { printf("\b"); printf("*"); }
								if ((i == 6 + (pi7) || i == 2 + (pi7)) && (j == 4 + (pj7) || j == 10 + (pj7))) { printf("\b"); printf("*"); }
								if ((i == 5 + (pi7) || i == 3 + (pi7)) && (j == 6 + (pj7) || j == 8 + (pj7))) { printf("\b"); printf("*"); }
								if ((i == 4 + (pi7)) && (j == 7 + (pj7))) { printf("\b"); printf("*"); }

								if (j == 50) { printf("\n"); }
							}
						}                                        ////////////////////////////////7 шаг конце
						if (((pobed[0][0] + pobed[0][1] + pobed[0][2]) == 3) || ((pobed[1][0] + pobed[1][1] + pobed[1][2]) == 3) ||
							((pobed[2][0] + pobed[2][1] + pobed[2][2]) == 3) || ((pobed[0][0] + pobed[1][0] + pobed[2][0]) == 3) ||
							((pobed[0][1] + pobed[1][1] + pobed[2][1]) == 3) || ((pobed[0][2] + pobed[1][2] + pobed[2][2]) == 3) ||
							((pobed[0][2] + pobed[1][1] + pobed[2][0]) == 3) || ((pobed[0][0] + pobed[1][1] + pobed[2][2]) == 3)) {

							printf("Player(X): %s WIN!", name1);

							printf("\n press 0 to return to the main menu \n");
							gotoxy(0, 35);
							fgets(chek, 31, stdin);
							gotoxy(0, 32);
							while (sscanf_s(chek, "%d", &menu1) != 1) {
								gotoxy(0, 35);
								printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
								gotoxy(0, 33);
								printf("Error, please enter 0 \n");
								gotoxy(0, 35);
								fgets(chek, 31, stdin);
							}
							chm = chek[0];
							ch0m = chek[1];
							while (chm == 45 || ch0m != 10 || chm > 48) {
								gotoxy(0, 35);
								printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
								gotoxy(0, 33);
								printf("Error, please enter 0 \n");
								gotoxy(0, 35);
								fgets(chek, 31, stdin);
								chm = chek[0];
								ch0m = chek[1];
							}
							if (chm == 48) { op = op - 1; }

						}
						else if (((pobedo[0][0] + pobedo[0][1] + pobedo[0][2]) == 3) || ((pobedo[1][0] + pobedo[1][1] + pobedo[1][2]) == 3) ||
							((pobedo[2][0] + pobedo[2][1] + pobedo[2][2]) == 3) || ((pobedo[0][0] + pobedo[1][0] + pobedo[2][0]) == 3) ||
							((pobedo[0][1] + pobedo[1][1] + pobedo[2][1]) == 3) || ((pobedo[0][2] + pobedo[1][2] + pobedo[2][2]) == 3) ||
							((pobedo[0][2] + pobedo[1][1] + pobedo[2][0]) == 3) || ((pobedo[0][0] + pobedo[1][1] + pobedo[2][2]) == 3)) {

							printf("Player(0): %s WIN!", name2);
							gotoxy(0, 32);
							printf("\n press 0 to return to the main menu \n");
							gotoxy(0, 35);
							fgets(chek, 31, stdin);
							while (sscanf_s(chek, "%d", &menu1) != 1) {
								gotoxy(0, 35);
								printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
								gotoxy(0, 33);
								printf("Error, please enter 0 \n");
								gotoxy(0, 35);
								fgets(chek, 31, stdin);
							}
							chm = chek[0];
							ch0m = chek[1];
							while (chm == 45 || ch0m != 10 || chm > 48) {
								gotoxy(0, 35);
								printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
								gotoxy(0, 33);
								printf("Error, please enter 0 \n");
								gotoxy(0, 35);
								fgets(chek, 31, stdin);
								chm = chek[0];
								ch0m = chek[1];
							}
							if (chm == 48) { op = op - 1; }

						}

						else {


							///////////////////////// 8 шаг
							chek[0] = 0;
							chek[1] = 0;
							gotoxy(0, 28);
							printf("Please enter a number from 1 to 9\n");
							gotoxy(0, 30);
							fgets(chek, 31, stdin);
							while (sscanf_s(chek, "%d", &step8) != 1) {
								gotoxy(0, 30);
								printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
								gotoxy(0, 28);
								printf("Error, Please enter a number from 1 to 9\n");
								gotoxy(0, 30);
								fgets(chek, 31, stdin);
							}
							ch8 = chek[0];
							ch08 = chek[1];

							while (ch8 == 45 || ch08 != 10 || ch8 == 48) {
								gotoxy(0, 30);
								printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
								gotoxy(0, 28);
								printf("Error, Please enter a number from 1 to 9\n");
								gotoxy(0, 30);
								fgets(chek, 31, stdin);
								ch8 = chek[0];
								ch08 = chek[1];
							}

							while ((ch2 == ch8) || (ch1 == ch8) || (ch3 == ch8) || (ch4 == ch8) || (ch5 == ch8) || (ch6 == ch8)
								|| (ch7 == ch8)) {
								gotoxy(0, 30);
								printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
								gotoxy(0, 28);
								printf("There has already been such a move! print another number\n");
								gotoxy(0, 30);
								fgets(chek, 31, stdin);
								ch8 = chek[0];
								ch08 = chek[1];
							}
							if (ch8 == 49) { step8 = 1; }if (ch8 == 50) { step8 = 2; }if (ch8 == 51) { step8 = 3; }
							if (ch8 == 52) { step8 = 4; }if (ch8 == 53) { step8 = 5; }if (ch8 == 54) { step8 = 6; }
							if (ch8 == 55) { step8 = 7; }if (ch8 == 56) { step8 = 8; }if (ch8 == 57) { step8 = 9; }


							if (step8 == 7) { pi8 = 0; pj8 = 0; pobedo[0][0] = 1; }
							if (step8 == 8) { pi8 = 0; pj8 = pj8; pobedo[0][1] = 1; }
							if (step8 == 9) { pi8 = 0; pj8 = pj8 * 2; pobedo[0][2] = 1; }

							if (step8 == 4) { pi8 = pi8; pj8 = 0; pobedo[1][0] = 1; }
							if (step8 == 5) { pi8 = pi8; pj8 = pj8; pobedo[1][1] = 1; }
							if (step8 == 6) { pi8 = pi8; pj8 = pj8 * 2; pobedo[1][2] = 1; }

							if (step8 == 1) { pi8 = pi8 * 2; pj8 = 0; pobedo[2][0] = 1; }
							if (step8 == 2) { pi8 = pi8 * 2; pj8 = pj8 * 1; pobedo[2][1] = 1; }
							if (step8 == 3) { pi8 = pi8 * 2; pj8 = pj8 * 2; pobedo[2][2] = 1; }
							system("cls");
							printf("Player(X): %s \b\b\b\b Player(0): %s ", name1, name2);
							printf("\n");
							for (i = 0; i < 25; i++)
							{
								for (j = 0; j < 51; j++)
								{

									if (i == 7 && j == 15) { printf("\b"); printf("7"); }
									if (i == 7 && j == 30) { printf("\b"); printf("8"); }
									if (i == 7 && j == 45) { printf("\b"); printf("9"); }
									if (i == 15 && j == 15) { printf("\b"); printf("4"); }
									if (i == 15 && j == 30) { printf("\b"); printf("5"); }
									if (i == 15 && j == 45) { printf("\b"); printf("6"); }
									if (i == 10 && j == 50) { printf("     Player(X):  now it's your turn  "); }
									if (i == 12 && j == 50) { printf("     Player(0):                      "); }
									if (i == 23 && j == 15) { printf("\b"); printf("1"); }
									if (i == 23 && j == 30) { printf("\b"); printf("2"); }
									if (i == 23 && j == 45) { printf("\b"); printf("3"); }

									if (i == 0 && j < 49) { printf("|"); }
									if (i == 8 && j < 49) { printf("|"); }
									if (i == 16 && j < 49) { printf("|"); }
									if (i == 24 && j < 49) { printf("|"); }
									if ((0 < i && i < 24 && i != 8 && i != 16) && (j == 0 || j == 47 || j == 15 || j == 30)) { printf("|"); }
									if ((0 < i) && (i < 24) && (i != 8) && (i != 16)) { if (j < 45) printf(" "); }


									if ((i == 7 + (pi1) || i == 1 + (pi1)) && (j == 2 + (pj1) || j == 12 + (pj1))) { printf("\b"); printf("*"); }
									if ((i == 6 + (pi1) || i == 2 + (pi1)) && (j == 4 + (pj1) || j == 10 + (pj1))) { printf("\b"); printf("*"); }
									if ((i == 5 + (pi1) || i == 3 + (pi1)) && (j == 6 + (pj1) || j == 8 + (pj1))) { printf("\b"); printf("*"); }
									if ((i == 4 + (pi1)) && (j == 7 + (pj1))) { printf("\b"); printf("*"); }

									if ((i == 4 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
									if ((i == 3 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
									if ((i == 5 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
									if ((i == 2 + (pi2) || i == 6 + (pi2)) && (j == 5 + (pj2) || j == 10 + (pj2))) { printf("\b"); printf("*"); }
									if ((i == 1 + (pi2) || i == 7 + (pi2)) && (j == 7 + (pj2) || j == 8 + (pj2))) { printf("\b"); printf("*"); }


									if ((i == 7 + (pi3) || i == 1 + (pi3)) && (j == 2 + (pj3) || j == 12 + (pj3))) { printf("\b"); printf("*"); }
									if ((i == 6 + (pi3) || i == 2 + (pi3)) && (j == 4 + (pj3) || j == 10 + (pj3))) { printf("\b"); printf("*"); }
									if ((i == 5 + (pi3) || i == 3 + (pi3)) && (j == 6 + (pj3) || j == 8 + (pj3))) { printf("\b"); printf("*"); }
									if ((i == 4 + (pi3)) && (j == 7 + (pj3))) { printf("\b"); printf("*"); }

									if ((i == 4 + (pi4)) && (j == 3 + (pj4) || j == 12 + (pj4))) { printf("\b"); printf("*"); }
									if ((i == 3 + (pi4)) && (j == 3 + (pj4) || j == 12 + (pj4))) { printf("\b"); printf("*"); }
									if ((i == 5 + (pi4)) && (j == 3 + (pj4) || j == 12 + (pj4))) { printf("\b"); printf("*"); }
									if ((i == 2 + (pi4) || i == 6 + (pi4)) && (j == 5 + (pj4) || j == 10 + (pj4))) { printf("\b"); printf("*"); }
									if ((i == 1 + (pi4) || i == 7 + (pi4)) && (j == 7 + (pj4) || j == 8 + (pj4))) { printf("\b"); printf("*"); }

									if ((i == 7 + (pi5) || i == 1 + (pi5)) && (j == 2 + (pj5) || j == 12 + (pj5))) { printf("\b"); printf("*"); }
									if ((i == 6 + (pi5) || i == 2 + (pi5)) && (j == 4 + (pj5) || j == 10 + (pj5))) { printf("\b"); printf("*"); }
									if ((i == 5 + (pi5) || i == 3 + (pi5)) && (j == 6 + (pj5) || j == 8 + (pj5))) { printf("\b"); printf("*"); }
									if ((i == 4 + (pi5)) && (j == 7 + (pj5))) { printf("\b"); printf("*"); }

									if ((i == 4 + (pi6)) && (j == 3 + (pj6) || j == 12 + (pj6))) { printf("\b"); printf("*"); }
									if ((i == 3 + (pi6)) && (j == 3 + (pj6) || j == 12 + (pj6))) { printf("\b"); printf("*"); }
									if ((i == 5 + (pi6)) && (j == 3 + (pj6) || j == 12 + (pj6))) { printf("\b"); printf("*"); }
									if ((i == 2 + (pi6) || i == 6 + (pi6)) && (j == 5 + (pj6) || j == 10 + (pj6))) { printf("\b"); printf("*"); }
									if ((i == 1 + (pi6) || i == 7 + (pi6)) && (j == 7 + (pj6) || j == 8 + (pj6))) { printf("\b"); printf("*"); }

									if ((i == 7 + (pi7) || i == 1 + (pi7)) && (j == 2 + (pj7) || j == 12 + (pj7))) { printf("\b"); printf("*"); }
									if ((i == 6 + (pi7) || i == 2 + (pi7)) && (j == 4 + (pj7) || j == 10 + (pj7))) { printf("\b"); printf("*"); }
									if ((i == 5 + (pi7) || i == 3 + (pi7)) && (j == 6 + (pj7) || j == 8 + (pj7))) { printf("\b"); printf("*"); }
									if ((i == 4 + (pi7)) && (j == 7 + (pj7))) { printf("\b"); printf("*"); }

									if ((i == 4 + (pi8)) && (j == 3 + (pj8) || j == 12 + (pj8))) { printf("\b"); printf("*"); }
									if ((i == 3 + (pi8)) && (j == 3 + (pj8) || j == 12 + (pj8))) { printf("\b"); printf("*"); }
									if ((i == 5 + (pi8)) && (j == 3 + (pj8) || j == 12 + (pj8))) { printf("\b"); printf("*"); }
									if ((i == 2 + (pi8) || i == 6 + (pi8)) && (j == 5 + (pj8) || j == 10 + (pj8))) { printf("\b"); printf("*"); }
									if ((i == 1 + (pi8) || i == 7 + (pi8)) && (j == 7 + (pj8) || j == 8 + (pj8))) { printf("\b"); printf("*"); }

									if (j == 50) { printf("\n"); }
								}
							}                                        ////////////////////////////////8 шаг конце
							if (((pobed[0][0] + pobed[0][1] + pobed[0][2]) == 3) || ((pobed[1][0] + pobed[1][1] + pobed[1][2]) == 3) ||
								((pobed[2][0] + pobed[2][1] + pobed[2][2]) == 3) || ((pobed[0][0] + pobed[1][0] + pobed[2][0]) == 3) ||
								((pobed[0][1] + pobed[1][1] + pobed[2][1]) == 3) || ((pobed[0][2] + pobed[1][2] + pobed[2][2]) == 3) ||
								((pobed[0][2] + pobed[1][1] + pobed[2][0]) == 3) || ((pobed[0][0] + pobed[1][1] + pobed[2][2]) == 3)) {

								printf("Player(X): %s WIN!", name1);
								gotoxy(0, 32);
								printf("\n press 0 to return to the main menu \n");
								gotoxy(0, 35);
								fgets(chek, 31, stdin);
								while (sscanf_s(chek, "%d", &menu1) != 1) {
									gotoxy(0, 35);
									printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
									gotoxy(0, 33);
									printf("Error, please enter 0 \n");
									gotoxy(0, 35);
									fgets(chek, 31, stdin);
								}
								chm = chek[0];
								ch0m = chek[1];
								while (chm == 45 || ch0m != 10 || chm > 48) {
									gotoxy(0, 35);
									printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
									gotoxy(0, 33);
									printf("Error, please enter 0 \n");
									gotoxy(0, 35);
									fgets(chek, 31, stdin);
									chm = chek[0];
									ch0m = chek[1];
								}
								if (chm == 48) { op = op - 1; }


							}
							else if (((pobedo[0][0] + pobedo[0][1] + pobedo[0][2]) == 3) || ((pobedo[1][0] + pobedo[1][1] + pobedo[1][2]) == 3) ||
								((pobedo[2][0] + pobedo[2][1] + pobedo[2][2]) == 3) || ((pobedo[0][0] + pobedo[1][0] + pobedo[2][0]) == 3) ||
								((pobedo[0][1] + pobedo[1][1] + pobedo[2][1]) == 3) || ((pobedo[0][2] + pobedo[1][2] + pobedo[2][2]) == 3) ||
								((pobedo[0][2] + pobedo[1][1] + pobedo[2][0]) == 3) || ((pobedo[0][0] + pobedo[1][1] + pobedo[2][2]) == 3)) {

								printf("Player(0): %s WIN!", name2);
								gotoxy(0, 32);
								printf("\n press 0 to return to the main menu \n");
								gotoxy(0, 35);
								fgets(chek, 31, stdin);
								while (sscanf_s(chek, "%d", &menu1) != 1) {
									gotoxy(0, 35);
									printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
									gotoxy(0, 33);
									printf("Error, please enter 0 \n");
									gotoxy(0, 35);
									fgets(chek, 31, stdin);
								}
								chm = chek[0];
								ch0m = chek[1];
								while (chm == 45 || ch0m != 10 || chm > 48) {
									gotoxy(0, 35);
									printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
									gotoxy(0, 33);
									printf("Error, please enter 0 \n");
									gotoxy(0, 35);
									fgets(chek, 31, stdin);
									chm = chek[0];
									ch0m = chek[1];
								}
								if (chm == 48) { op = op - 1; }

							}

							else {


								///////////////////////// 9 шаг
								chek[0] = 0;
								chek[1] = 0;
								gotoxy(0, 28);
								printf("Please enter a number from 1 to 9\n");
								gotoxy(0, 30);
								fgets(chek, 31, stdin);
								while (sscanf_s(chek, "%d", &step9) != 1) {
									gotoxy(0, 30);
									printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
									gotoxy(0, 28);
									printf("Error, Please enter a number from 1 to 9\n");
									gotoxy(0, 30);
									fgets(chek, 31, stdin);
								}
								ch9 = chek[0];
								ch09 = chek[1];

								while (ch9 == 45 || ch09 != 10 || ch9 == 48) {
									gotoxy(0, 30);
									printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
									gotoxy(0, 28);
									printf("Error, Please enter a number from 1 to 9\n");
									gotoxy(0, 30);
									fgets(chek, 31, stdin);
									ch9 = chek[0];
									ch09 = chek[1];
								}

								while ((ch2 == ch9) || (ch1 == ch9) || (ch3 == ch9) || (ch4 == ch9) || (ch5 == ch9) || (ch6 == ch9)
									|| (ch7 == ch9) || (ch8 == ch9)) {
									printf("There has already been such a move!\n");
									fgets(chek, 31, stdin);
									ch9 = chek[0];
									ch09 = chek[1];
								}
								if (ch9 == 49) { step9 = 1; }if (ch9 == 50) { step9 = 2; }if (ch9 == 51) { step9 = 3; }
								if (ch9 == 52) { step9 = 4; }if (ch9 == 53) { step9 = 5; }if (ch9 == 54) { step9 = 6; }
								if (ch9 == 55) { step9 = 7; }if (ch9 == 56) { step9 = 8; }if (ch9 == 57) { step9 = 9; }



								if (step9 == 7) { pi9 = 0; pj9 = 0; pobed[0][0] = 1; }
								if (step9 == 8) { pi9 = 0; pj9 = pj9; pobed[0][1] = 1; }
								if (step9 == 9) { pi9 = 0; pj9 = pj9 * 2; pobed[0][2] = 1; }

								if (step9 == 4) { pi9 = pi9; pj9 = 0; pobed[1][0] = 1; }
								if (step9 == 5) { pi9 = pi9; pj9 = pj9; pobed[1][1] = 1; }
								if (step9 == 6) { pi9 = pi9; pj9 = pj9 * 2; pobed[1][2] = 1; }

								if (step9 == 1) { pi9 = pi9 * 2; pj9 = 0; pobed[2][0] = 1; }
								if (step9 == 2) { pi9 = pi9 * 2; pj9 = pj9 * 1; pobed[2][1] = 1; }
								if (step9 == 3) { pi9 = pi9 * 2; pj9 = pj9 * 2; pobed[2][2] = 1; }

								system("cls");
								printf("Player(X): %s \b\b\b\b Player(0): %s ", name1, name2);
								printf("\n");
								for (i = 0; i < 25; i++)
								{
									for (j = 0; j < 51; j++)
									{

										if (i == 7 && j == 15) { printf("\b"); printf("7"); }
										if (i == 7 && j == 30) { printf("\b"); printf("8"); }
										if (i == 7 && j == 45) { printf("\b"); printf("9"); }
										if (i == 15 && j == 15) { printf("\b"); printf("4"); }
										if (i == 15 && j == 30) { printf("\b"); printf("5"); }
										if (i == 15 && j == 45) { printf("\b"); printf("6"); }
										if (i == 10 && j == 50) { printf("     Player(X):    "); }
										if (i == 12 && j == 50) { printf("     Player(0):  now it's your turn "); }
										if (i == 23 && j == 15) { printf("\b"); printf("1"); }
										if (i == 23 && j == 30) { printf("\b"); printf("2"); }
										if (i == 23 && j == 45) { printf("\b"); printf("3"); }

										if (i == 0 && j < 49) { printf("|"); }
										if (i == 8 && j < 49) { printf("|"); }
										if (i == 16 && j < 49) { printf("|"); }
										if (i == 24 && j < 49) { printf("|"); }
										if ((0 < i && i < 24 && i != 8 && i != 16) && (j == 0 || j == 47 || j == 15 || j == 30)) { printf("|"); }
										if ((0 < i) && (i < 24) && (i != 8) && (i != 16)) { if (j < 45) printf(" "); }


										if ((i == 7 + (pi1) || i == 1 + (pi1)) && (j == 2 + (pj1) || j == 12 + (pj1))) { printf("\b"); printf("*"); }
										if ((i == 6 + (pi1) || i == 2 + (pi1)) && (j == 4 + (pj1) || j == 10 + (pj1))) { printf("\b"); printf("*"); }
										if ((i == 5 + (pi1) || i == 3 + (pi1)) && (j == 6 + (pj1) || j == 8 + (pj1))) { printf("\b"); printf("*"); }
										if ((i == 4 + (pi1)) && (j == 7 + (pj1))) { printf("\b"); printf("*"); }

										if ((i == 4 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
										if ((i == 3 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
										if ((i == 5 + (pi2)) && (j == 3 + (pj2) || j == 12 + (pj2))) { printf("\b"); printf("*"); }
										if ((i == 2 + (pi2) || i == 6 + (pi2)) && (j == 5 + (pj2) || j == 10 + (pj2))) { printf("\b"); printf("*"); }
										if ((i == 1 + (pi2) || i == 7 + (pi2)) && (j == 7 + (pj2) || j == 8 + (pj2))) { printf("\b"); printf("*"); }


										if ((i == 7 + (pi3) || i == 1 + (pi3)) && (j == 2 + (pj3) || j == 12 + (pj3))) { printf("\b"); printf("*"); }
										if ((i == 6 + (pi3) || i == 2 + (pi3)) && (j == 4 + (pj3) || j == 10 + (pj3))) { printf("\b"); printf("*"); }
										if ((i == 5 + (pi3) || i == 3 + (pi3)) && (j == 6 + (pj3) || j == 8 + (pj3))) { printf("\b"); printf("*"); }
										if ((i == 4 + (pi3)) && (j == 7 + (pj3))) { printf("\b"); printf("*"); }

										if ((i == 4 + (pi4)) && (j == 3 + (pj4) || j == 12 + (pj4))) { printf("\b"); printf("*"); }
										if ((i == 3 + (pi4)) && (j == 3 + (pj4) || j == 12 + (pj4))) { printf("\b"); printf("*"); }
										if ((i == 5 + (pi4)) && (j == 3 + (pj4) || j == 12 + (pj4))) { printf("\b"); printf("*"); }
										if ((i == 2 + (pi4) || i == 6 + (pi4)) && (j == 5 + (pj4) || j == 10 + (pj4))) { printf("\b"); printf("*"); }
										if ((i == 1 + (pi4) || i == 7 + (pi4)) && (j == 7 + (pj4) || j == 8 + (pj4))) { printf("\b"); printf("*"); }

										if ((i == 7 + (pi5) || i == 1 + (pi5)) && (j == 2 + (pj5) || j == 12 + (pj5))) { printf("\b"); printf("*"); }
										if ((i == 6 + (pi5) || i == 2 + (pi5)) && (j == 4 + (pj5) || j == 10 + (pj5))) { printf("\b"); printf("*"); }
										if ((i == 5 + (pi5) || i == 3 + (pi5)) && (j == 6 + (pj5) || j == 8 + (pj5))) { printf("\b"); printf("*"); }
										if ((i == 4 + (pi5)) && (j == 7 + (pj5))) { printf("\b"); printf("*"); }

										if ((i == 4 + (pi6)) && (j == 3 + (pj6) || j == 12 + (pj6))) { printf("\b"); printf("*"); }
										if ((i == 3 + (pi6)) && (j == 3 + (pj6) || j == 12 + (pj6))) { printf("\b"); printf("*"); }
										if ((i == 5 + (pi6)) && (j == 3 + (pj6) || j == 12 + (pj6))) { printf("\b"); printf("*"); }
										if ((i == 2 + (pi6) || i == 6 + (pi6)) && (j == 5 + (pj6) || j == 10 + (pj6))) { printf("\b"); printf("*"); }
										if ((i == 1 + (pi6) || i == 7 + (pi6)) && (j == 7 + (pj6) || j == 8 + (pj6))) { printf("\b"); printf("*"); }

										if ((i == 7 + (pi7) || i == 1 + (pi7)) && (j == 2 + (pj7) || j == 12 + (pj7))) { printf("\b"); printf("*"); }
										if ((i == 6 + (pi7) || i == 2 + (pi7)) && (j == 4 + (pj7) || j == 10 + (pj7))) { printf("\b"); printf("*"); }
										if ((i == 5 + (pi7) || i == 3 + (pi7)) && (j == 6 + (pj7) || j == 8 + (pj7))) { printf("\b"); printf("*"); }
										if ((i == 4 + (pi7)) && (j == 7 + (pj7))) { printf("\b"); printf("*"); }

										if ((i == 4 + (pi8)) && (j == 3 + (pj8) || j == 12 + (pj8))) { printf("\b"); printf("*"); }
										if ((i == 3 + (pi8)) && (j == 3 + (pj8) || j == 12 + (pj8))) { printf("\b"); printf("*"); }
										if ((i == 5 + (pi8)) && (j == 3 + (pj8) || j == 12 + (pj8))) { printf("\b"); printf("*"); }
										if ((i == 2 + (pi8) || i == 6 + (pi8)) && (j == 5 + (pj8) || j == 10 + (pj8))) { printf("\b"); printf("*"); }
										if ((i == 1 + (pi8) || i == 7 + (pi8)) && (j == 7 + (pj8) || j == 8 + (pj8))) { printf("\b"); printf("*"); }

										if ((i == 7 + (pi9) || i == 1 + (pi9)) && (j == 2 + (pj9) || j == 12 + (pj9))) { printf("\b"); printf("*"); }
										if ((i == 6 + (pi9) || i == 2 + (pi9)) && (j == 4 + (pj9) || j == 10 + (pj9))) { printf("\b"); printf("*"); }
										if ((i == 5 + (pi9) || i == 3 + (pi9)) && (j == 6 + (pj9) || j == 8 + (pj9))) { printf("\b"); printf("*"); }
										if ((i == 4 + (pi9)) && (j == 7 + (pj9))) { printf("\b"); printf("*"); }

										if (j == 50) { printf("\n"); }



									}
								}                                        ////////////////////////////////9 шаг конце




								if (((pobed[0][0] + pobed[0][1] + pobed[0][2]) == 3) || ((pobed[1][0] + pobed[1][1] + pobed[1][2]) == 3) ||
									((pobed[2][0] + pobed[2][1] + pobed[2][2]) == 3) || ((pobed[0][0] + pobed[1][0] + pobed[2][0]) == 3) ||
									((pobed[0][1] + pobed[1][1] + pobed[2][1]) == 3) || ((pobed[0][2] + pobed[1][2] + pobed[2][2]) == 3) ||
									((pobed[0][2] + pobed[1][1] + pobed[2][0]) == 3) || ((pobed[0][0] + pobed[1][1] + pobed[2][2]) == 3)) {

									printf("Player(X): %s WIN!", name1);
									gotoxy(0, 32);
									printf("\n Enter 0 to return to the main menu \n");
									gotoxy(0, 35);
									fgets(chek, 31, stdin);
									while (sscanf_s(chek, "%d", &menu1) != 1) {
										gotoxy(0, 35);
										printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
										gotoxy(0, 33);
										printf("Error, please enter 0 \n");
										gotoxy(0, 35);
										fgets(chek, 31, stdin);
									}
									chm = chek[0];
									ch0m = chek[1];
									while (chm == 45 || ch0m != 10 || chm > 48) {
										gotoxy(0, 35);
										printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
										gotoxy(0, 33);
										printf("Error, please enter 0 \n");
										gotoxy(0, 35);
										fgets(chek, 31, stdin);
										chm = chek[0];
										ch0m = chek[1];
									}
									if (chm == 48) { op = op - 1; }


								}
								else if (((pobedo[0][0] + pobedo[0][1] + pobedo[0][2]) == 3) || ((pobedo[1][0] + pobedo[1][1] + pobedo[1][2]) == 3) ||
									((pobedo[2][0] + pobedo[2][1] + pobedo[2][2]) == 3) || ((pobedo[0][0] + pobedo[1][0] + pobedo[2][0]) == 3) ||
									((pobedo[0][1] + pobedo[1][1] + pobedo[2][1]) == 3) || ((pobedo[0][2] + pobedo[1][2] + pobedo[2][2]) == 3) ||
									((pobedo[0][2] + pobedo[1][1] + pobedo[2][0]) == 3) || ((pobedo[0][0] + pobedo[1][1] + pobedo[2][2]) == 3)) {

									printf("Player(0): %s WIN!", name2);
									gotoxy(0, 32);
									printf("\n Enter 0 to return to the main menu \n");
									gotoxy(0, 35);
									fgets(chek, 31, stdin);
									while (sscanf_s(chek, "%d", &menu1) != 1) {
										gotoxy(0, 35);
										printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
										gotoxy(0, 33);
										printf("Error, please enter 0 \n");
										gotoxy(0, 35);
										fgets(chek, 31, stdin);
									}
									chm = chek[0];
									ch0m = chek[1];
									while (chm == 45 || ch0m != 10 || chm > 48) {
										gotoxy(0, 35);
										printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
										gotoxy(0, 33);
										printf("Error, please enter 0 \n");
										gotoxy(0, 35);
										fgets(chek, 31, stdin);
										chm = chek[0];
										ch0m = chek[1];
									}
									if (chm == 48) { op = op - 1; }

								}
								else {



									printf("\n Oops draw \n\n");
									gotoxy(0, 32);
									printf("\n Enter 0 to return to the main menu \n");
									gotoxy(0, 35);
									fgets(chek, 31, stdin);
									while (sscanf_s(chek, "%d", &menu1) != 1) {
										gotoxy(0, 35);
										printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
										gotoxy(0, 33);
										printf("Error, please enter 0 \n");
										gotoxy(0, 35);
										fgets(chek, 31, stdin);
									}
									chm = chek[0];
									ch0m = chek[1];
									while (chm == 45 || ch0m != 10 || chm > 48) {
										gotoxy(0, 35);
										printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                 \n");
										gotoxy(0, 33);
										printf("Error, please enter 0 \n");
										gotoxy(0, 35);
										fgets(chek, 31, stdin);
										chm = chek[0];
										ch0m = chek[1];
									}

									if (chm == 48) { op = op - 1; }




								}
							}
						}
					}
				}
			}
		}
	}
}

