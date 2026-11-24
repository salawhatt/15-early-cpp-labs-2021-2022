#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <windows.h>
#include <winuser.h>
#include <conio.h>
char way[128] = "Price.txt";
int AMD = 0;
int INTEL = 0;
char clean[50] = { 0 };
//char ch.identy_output_sockets = 0;
char nubm_punkt;//1-14
char object[80] = { 0 };
char way_to_save[150] = { 0 };
char way_to_import[150] = { 0 };
/* Нумерация Сокетов
LGA 1151 - 1
LGA 2066 - 2
LGA 1200 - 3
LGA 1700 - 4
AM1      - 5
AM4      - 6
TR4      - 7
*/
//инструкция перед началом работы
void clean_stdin(void)
{
	int c;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}
void instruction_control() {
	printf("                           Управление\n\n"
		"\n        /----\\                          /-----\\"
		"\n       |  / \\ |                         |     |"
		"\n       |   |  |   -- Вверх              |     |"
		"\n        \\____/                          |     | - перейти в пункт/вернуться назад"
		"\n                              __________|     |"
		"\n /----\\ /----\\ /----\\        |                |"
		"\n|      |   |  |      |       |                |"
		"\n|      |   |  |      |       |     Enter      |"
		"\n|      |  \\ / |      |       |                |"
		"\n \\____/ \\____/ \\____/        |________________|"
		"\n          |\n          |\n        Вниз\n"
		"\n");
	system("pause");
	system("cls");
}
//функция для перемещения курсора
void gotoxy(SHORT x, SHORT y) {
	COORD p = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
//функция для отрисовки полей
void drawing_box(int x, int y)
{
	for (int Y_axis = 0; Y_axis < y; Y_axis++)
	{

		gotoxy(0, Y_axis);
		printf("|");
		gotoxy(70, Y_axis);
		printf("|");
	}
	for (int X_axis = 0; X_axis < x; X_axis++)
	{

		gotoxy(X_axis, 0);
		printf("|");
		gotoxy(X_axis, 35);
		printf("|");
	}
}
//структура с ценами и названиям компонентов
struct computer
{
	char CPU_make[50];      //-1 *
	int CPU_ch;

	char CPU_socket[50];    //0 *
	int CPU_socket_ch;

	char CPU[50];           //1
	int CPU_cost;
	int CPU_yes;

	char motherboard[50];   //2
	int motherboard_cost;

	char GPU[50];           //3
	int GPU_cost;

	char RAM[50];           //4
	int RAM_cost;

	char SSD[50];           //5
	int SSD_cost;

	char HDD[50];           //6
	int HDD_cost;

	char Power_Supply[50];  //7
	int Power_Supply_cost;

	char coolers[50];       //8
	int coolers_cost;

	char Frame[50];         //9
	int Frame_cost;

	char Sound_Сard[50];    //10
	int Sound_Сard_cost;

	char Optical_Drive[50]; //11
	int Optical_Drive_cost;

	char Net[50];           //12
	int Net_cost;

	char Card_Reader[50];   //13
	int Card_Reader_cost;

	char OS[50];           //14
	int OS_cost;

	int summ;

} PC;
//отрисовка главного меню
union socet
{
	char identy_output_sockets;
	int number;
} ch;
union discount
{
	char percent;
	int without;
} discount;

void drawing_main_menu() {
	drawing_box(71, 35);
	gotoxy(25, 5); printf("Конфигуратор ПК");
	gotoxy(6, 9); printf("1. Cоздать необходимую конфигурацию товара");
	gotoxy(6, 12); printf("2. Cохранить созданную конфигурацию товара в файл");
	gotoxy(6, 15);  printf("3. Импортировать существующую конфигурацию товара из файла");
	gotoxy(6, 18); printf("4. Очистить конфигурацию");
	gotoxy(6, 21); printf("5. Инструкция");
	gotoxy(6, 24);  printf("6. Выход");
}
//управление в главном меню
int main_menu_control()
{

	drawing_main_menu();
	int control = 1;
	int pointer_location = 9;
	while (control == 1)
	{
		int button = 0;

		gotoxy(6, 9);
		printf("\b");
		printf(">");
		gotoxy(0, 0);
		button = 0;

		while (button != 13)
		{

			button = getch();

			if (button == 80)
			{

				gotoxy(5, pointer_location);
				printf(" ");

				pointer_location = pointer_location + 3;
				if (pointer_location == 27)
				{
					pointer_location = 9;
				}

				gotoxy(6, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
			if (button == 72)
			{

				gotoxy(5, pointer_location);
				printf(" ");
				pointer_location = pointer_location - 3;
				if (pointer_location == 6)
				{
					pointer_location = 24;
				}
				gotoxy(6, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
		}
		control--;
	}
	system("cls");
	return pointer_location;
}
//отрисовка первого пункта
void drawing_first_item() {
	double with_discount = 0;
	system("cls");
	drawing_box(75, 35);

	gotoxy(16, 3);
	printf("Cоздать необходимую конфигурацию");
	gotoxy(5, 5); printf(" 1. Процессор");
	gotoxy(5, 7); printf(" 2. Материнская плата");
	gotoxy(5, 9); printf(" 3. Видеокарта");
	gotoxy(5, 11); printf(" 4. ОЗУ");
	gotoxy(5, 13); printf(" 5. SSD");
	gotoxy(5, 15); printf(" 6. HDD");
	gotoxy(5, 17); printf(" 7. Блок Питания");
	gotoxy(5, 19); printf(" 8. Кулеры");
	gotoxy(5, 21); printf(" 9. Корпус");
	gotoxy(5, 23); printf(" 10. Звуковая карта");
	gotoxy(5, 25); printf(" 11. Оптический привод");
	gotoxy(5, 27); printf(" 12. Сетевая карта");
	gotoxy(5, 29); printf(" 13. Кард-риддер");
	gotoxy(5, 31); printf(" 14. OS");
	gotoxy(5, 33); printf(" 15. Назад");

	gotoxy(72, 5);  printf(" 1.\t%s", PC.CPU);
	gotoxy(72, 7);  printf(" 2.\t%s", PC.motherboard);
	gotoxy(72, 9);  printf(" 3.\t%s", PC.GPU);
	gotoxy(72, 11); printf(" 4.\t%s", PC.RAM);
	gotoxy(72, 13); printf(" 5.\t%s", PC.SSD);
	gotoxy(72, 15); printf(" 6.\t%s", PC.HDD);
	gotoxy(72, 17); printf(" 7.\t%s", PC.Power_Supply);
	gotoxy(72, 19); printf(" 8.%s", PC.coolers);
	gotoxy(72, 21); printf(" 9.%s", PC.Frame);
	gotoxy(72, 23); printf("10.%s", PC.Sound_Сard);
	gotoxy(72, 25); printf("11.%s", PC.Optical_Drive);
	gotoxy(72, 27); printf("12.%s", PC.Net);
	gotoxy(72, 29); printf("13.%s", PC.Card_Reader);
	gotoxy(72, 31); printf("14.%s", PC.OS);
	PC.summ = (PC.CPU_cost + PC.motherboard_cost + PC.GPU_cost + PC.RAM_cost + PC.SSD_cost + PC.HDD_cost + PC.Power_Supply_cost + PC.coolers_cost + PC.Frame_cost + PC.Sound_Сard_cost + PC.Optical_Drive_cost + PC.Net_cost + PC.Card_Reader_cost + PC.OS_cost);
	if (discount.without != 0)
	{
		if (discount.percent == 25)
		{
			with_discount = PC.summ - (PC.summ / 4);
		}
		if (discount.percent == 5)
		{
			with_discount = PC.summ - (PC.summ / 20);
		}
	}
	else
	{
		with_discount = PC.summ;
	}
	gotoxy(1, 40); printf("При выборе процессора Intel Core i9-12900 скидка на всю сборку 25%%");
	gotoxy(1, 42); printf("При выборе процессора AMD Ryzen 9 5950X скидка на всю сборку 5%%");

	gotoxy(71, 32); printf("\t Общая цена: %d руб.", PC.summ);
	gotoxy(71, 33); printf("\t Cкидка: %d%%.", discount.without);
	gotoxy(71, 34); printf("\t Цена с учётом скидки: %f руб.", with_discount);


}
//управление в первом пункте
int first_item_control()
{

	drawing_first_item();
	int pointer_location = 5;
	int control = 1;
	while (control == 1)
	{
		int button = 0;

		gotoxy(6, 5);
		printf("\b");
		printf(">");
		gotoxy(0, 0);
		button = 0;

		while (button != 13)
		{

			button = getch();

			if (button == 80)
			{

				gotoxy(5, pointer_location);
				printf(" ");

				pointer_location = pointer_location + 2;
				if (pointer_location == 35)
				{
					pointer_location = 5;
				}

				gotoxy(6, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
			if (button == 72)
			{

				gotoxy(5, pointer_location);
				printf(" ");
				pointer_location = pointer_location - 2;
				if (pointer_location == 3)
				{
					pointer_location = 33;
				}
				gotoxy(6, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
		}
		control--;

	}
	system("cls");
	return pointer_location;
}
//вывод производителей процессоров и управление
int drawing_get_processor_manufacturer_to_files()
{
	drawing_box(71, 35);
	gotoxy(20, 5);
	printf("Производители процессоров");
	gotoxy(15, 10);
	printf("1. AMD");
	gotoxy(15, 15);
	printf("2. INTEL");
	gotoxy(15, 20);
	printf("3. Назад");
	gotoxy(0, 35);



	int pointer_location = 10;
	int control = 1;
	while (control == 1)
	{
		int button = 0;

		gotoxy(15, 10);
		printf("\b");
		printf(">");
		gotoxy(0, 0);
		button = 0;

		while (button != 13)
		{

			button = getch();

			if (button == 80)
			{

				gotoxy(14, pointer_location);
				printf(" ");

				pointer_location = pointer_location + 5;
				if (pointer_location == 25)
				{
					pointer_location = 10;
				}

				gotoxy(15, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
			if (button == 72)
			{

				gotoxy(14, pointer_location);
				printf(" ");
				pointer_location = pointer_location - 5;
				if (pointer_location == 5)
				{
					pointer_location = 20;
				}
				gotoxy(15, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
		}
		control--;

	}
	system("cls");
	return pointer_location;


}
//парсинг назвний процессоров из файла
int output_sockets()
{
	int end_of_the_list = 25;
	drawing_box(71, 35);

	gotoxy(32, 5);
	printf("Сокет");
	if (AMD == 1)
	{
		gotoxy(15, 10);
		printf("1. Socket AM1 (2015г)");
		gotoxy(15, 15);
		printf("2. Socket AM4 (2016г)");
		gotoxy(15, 20);
		printf("3. Socket TR4 (2019г)");
		gotoxy(15, 25);
		printf("4. Назад");
		gotoxy(0, 35);
	}
	if (INTEL == 1)
	{
		end_of_the_list = 30;
		gotoxy(15, 10);
		printf("1. LGA 1151 (2015г)");
		gotoxy(15, 15);
		printf("2. LGA 2066 (2017г)");
		gotoxy(15, 20);
		printf("3. LGA 1200 (2020г)");
		gotoxy(15, 25);
		printf("4. LGA 1700 (2021г)");
		gotoxy(15, 30);
		printf("4. Назад");
		gotoxy(0, 35);
	}



	int pointer_location = 10;
	int control = 1;
	while (control == 1)
	{
		int button = 0;

		gotoxy(15, 10);
		printf("\b");
		printf(">");
		gotoxy(0, 0);
		button = 0;

		while (button != 13)
		{

			button = getch();

			if (button == 80)
			{

				gotoxy(14, pointer_location);
				printf(" ");

				pointer_location = pointer_location + 5;
				if (pointer_location == end_of_the_list + 5)
				{
					pointer_location = 10;
				}

				gotoxy(15, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
			if (button == 72)
			{

				gotoxy(14, pointer_location);
				printf(" ");
				pointer_location = pointer_location - 5;
				if (pointer_location == 5)
				{
					pointer_location = end_of_the_list;
				}
				gotoxy(15, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
		}
		control--;

	}
	system("cls");
	if (AMD == 1)
	{
		return pointer_location + 5;
	}
	return pointer_location;

}
//вывод процессоров под опреденённый сокет и выбор процессора
int Intel_Proc(int soct)
{

	int end_of_the_list = 22;  //конце списка, переменная для отрисованного меню (что б курсор не уходил вне поля)
	drawing_box(71, 35);
	//ch.identy_output_sockets = 0;//номер сокета в файла, по которому будут парситься названия

	int selected_socket = soct;
	if (selected_socket == 10) //1151 //7
	{
		ch.number = 49; //определяется номер по которому будут процессоры
		end_of_the_list = 22;
		gotoxy(19, 5);
		printf("Процессоры на сокете LGA 1151");

	}
	if (selected_socket == 15) //2066 //
	{
		ch.number = 50;
		end_of_the_list = 18;
		gotoxy(19, 5);
		printf("Процессоры на сокете LGA 2066");
	}
	if (selected_socket == 20) //1200
	{
		ch.number = 51;
		end_of_the_list = 18;
		gotoxy(19, 5);
		printf("Процессоры на сокете LGA 1200");
	}
	if (selected_socket == 25) //1700
	{
		ch.number = 52;
		end_of_the_list = 20;
		gotoxy(19, 5);
		printf("Процессоры на сокете LGA 1700");
	}
	///////получение наименований процессорв из файла 
	FILE* file;
	file = fopen(way, "r");
	int output_string = 8;
	if (file != NULL)
	{
		while (!feof(file)) //цикл до конца файла
		{

			char str[200] = { 0 };
			fgets(str, 150, file);

			if (str[0] == '\t' && str[1] == '\t' && str[2] == nubm_punkt && str[3] == '.' && str[5] == '.' && str[4] == ch.identy_output_sockets) //условия для парсинга названий
			{

				/*if (str[23] == '1' && str[24] == '2' && str[25] == '9' && str[26] == '0' && str[27] == '0')
				{
					discount.rubles = (str[23] + str[24] + str[25] + str[26]) * 10;
				}*/
				gotoxy(10, output_string);

				for (int i = 0; i < 150; i++) //вывод названий процессоров
				{
					if (i > 5)
					{
						printf("%c", str[i]);
					}
				}
				output_string = output_string + 2;;
			}

		}
		gotoxy(10, output_string);
		fclose(file);
	}printf("Назад к выбору сокета");

	int pointer_location = 8;
	int control = 1;
	while (control == 1)
	{
		int button = 0;

		gotoxy(10, 8);
		printf("\b");
		printf(">");
		gotoxy(0, 0);
		button = 0;

		while (button != 13)
		{

			button = getch();

			if (button == 80)
			{

				gotoxy(9, pointer_location);
				printf(" ");

				pointer_location = pointer_location + 2;
				if (pointer_location == end_of_the_list + 2)
				{
					pointer_location = 8;
				}

				gotoxy(10, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
			if (button == 72)
			{

				gotoxy(9, pointer_location);
				printf(" ");
				pointer_location = pointer_location - 2;
				if (pointer_location == 6)
				{
					pointer_location = end_of_the_list;
				}
				gotoxy(10, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
		}
		control--;

	}
	if (pointer_location == (end_of_the_list)) //возврат из пункта выбора процессорв
	{
		return 50;
	}
	return pointer_location;
}
int AMD_Proc(int soct)
{
	//тот же принцип что у Intel_Proc()
	int end_of_the_list = 24;
	drawing_box(71, 35);
	gotoxy(32, 5);
	printf("Процессоры");
	


	int selected_socket = soct;
	if (selected_socket == 15) //AM1
	{
		gotoxy(19, 5);
		printf("Процессоры на сокете AM1");
		end_of_the_list = 14;
		ch.number = 53;
	}
	if (selected_socket == 20) //AM4
	{
		gotoxy(19, 5);
		printf("Процессоры на сокете AM4");
		ch.number = 54;
		end_of_the_list = 24;
	}
	if (selected_socket == 25) //TR4
	{
		gotoxy(19, 5);
		printf("Процессоры на сокете TR4");
		ch.number = 55;
		end_of_the_list = 16;
	}

	FILE* file;
	file = fopen(way, "r");
	int p = 8;
	if (file != NULL)
	{
		while (!feof(file)) //цикл до конца файла
		{
			char str[200] = { 0 };
			fgets(str, 150, file);

			if (str[0] == '\t' && str[1] == '\t' && str[2] == nubm_punkt && str[3] == '.' && str[5] == '.' && str[4] == ch.identy_output_sockets)
			{
				/*if (str[21] == '3' && str[22] == '9' && str[23] == '5' && str[24] == '0')
				{
					discount.rubles = (str[21] + str[22] + str[23] + str[24]) * 10;
				}*/

				gotoxy(10, p);

				for (int i = 0; i < 150; i++)
				{
					if (i > 5)
					{
						printf("%c", str[i]);
					}
				}
				p = p + 2;;
			}

		}
		gotoxy(10, p);
		fclose(file);
	}printf("Назад к выбору сокета");

	int pointer_location = 8;
	int control = 1;
	while (control == 1)
	{
		int button = 0;

		gotoxy(10, 8);
		printf("\b");
		printf(">");
		gotoxy(0, 0);
		button = 0;

		while (button != 13)
		{

			button = getch();

			if (button == 80)
			{

				gotoxy(9, pointer_location);
				printf(" ");

				pointer_location = pointer_location + 2;
				if (pointer_location == end_of_the_list + 2)
				{
					pointer_location = 8;
				}

				gotoxy(10, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
			if (button == 72)
			{

				gotoxy(9, pointer_location);
				printf(" ");
				pointer_location = pointer_location - 2;
				if (pointer_location == 6)
				{
					pointer_location = end_of_the_list;
				}
				gotoxy(10, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
		}
		control--;

	}
	if (pointer_location == (end_of_the_list))
	{
		return 50;
	}
	return pointer_location;
}
//функция которая используется для записи названия процессора в структуру
char* cpu_name_to_array(int serch)
{
	//массив для записи названия
	char serch_num;  //перевод из нумерации в меню процессорв, в обычную цифру типа char
	serch_num = ((serch - 6) / 2) + '0';
	//например при выборе в меню процеесора под номером "2" мы получим serch=10, номер давнного процессора в файле "2" поэтому из 10 мы делаем 2
	system("cls");
	drawing_box(71, 35);

	//запись выбранного процессора в массив
	FILE* file;
	file = fopen(way, "r");
	char str[200] = { 0 };
	if (file != NULL)
	{
		while (!feof(file)) //цикл до конца файла
		{

			memset(str, NULL, 150);
			fgets(str, 150, file);
			int i = 9;
			if (str[0] == '\t' && str[1] == '\t' && str[2] == nubm_punkt && str[3] == '.' && str[5] == '.' && str[4] == ch.identy_output_sockets && str[6] == serch_num && str[7] == '.')
			{
				for (int j = 0; j < 55; j++) //запись в массив без нумерации процессора
				{

					object[j] = str[i];
					i++;

				}
				//break;
			}

		}

	}


	return object;

}
//проверка является ли символ цифрой
int checking_numb(char sym)
{

	char numbs[11] = { "0123456789" };
	for (int i = 0; i < 10; i++)
	{
		if (sym == numbs[i] && sym != '\n' && sym != '\t')
		{
			return 1;
		}
	}
	return 0;
}
//получение из массива названия ценны и перевод в int
int price(char price[])
{
	int price_int = 0;
	char number[6] = { 0 };
	for (int i = 100;i >= 0; i--)
	{
		if (price[i] == '.' && price[i - 1] == 'б' && price[i - 2] == 'у' && price[i - 3] == 'р')
		{
			number[0] = price[i - 11];
			number[1] = price[i - 10];
			number[2] = price[i - 9];
			number[3] = price[i - 7];
			number[4] = price[i - 6];
			number[5] = price[i - 5];
		}
	}
	if (checking_numb(number[0]) == 1)
	{
		price_int = price_int + ((number[0] - '0') * 100000);
	}
	if (checking_numb(number[1]) == 1)
	{
		price_int = price_int + ((number[1] - '0') * 10000);
	}
	if (checking_numb(number[2]) == 1)
	{
		price_int = price_int + ((number[2] - '0') * 1000);
	}
	if (checking_numb(number[3]) == 1)
	{
		price_int = price_int + ((number[3] - '0') * 100);
	}
	if (checking_numb(number[4]) == 1)
	{
		price_int = price_int + ((number[4] - '0') * 10);
	}
	if (checking_numb(number[5]) == 1)
	{
		price_int = price_int + ((number[5] - '0'));
	}
	return price_int;
}
void your_ch(char name[])
{
	int button = 0;
	drawing_box(71, 35);
	gotoxy(25, 10);
	printf("Вы выбрали:");
	gotoxy(15, 15);
	printf("%s", name);
	gotoxy(10, 25);
	printf("Нажмте Enter, что бы вернуться к выбору компонентов");

	while (button != 13)
	{
		button = getch();
	}
}
int motherboard()
{
	nubm_punkt = '4'; //сразу определяем какой номер у мат.плат в прайс листе
	int end_of_the_list = 22;
	drawing_box(71, 35);
	if (ch.number == 49) //1151 //7
	{
		end_of_the_list = 16;
		gotoxy(19, 5);
		printf("Материнская плата под LGA 1151");

	}
	if (ch.number == 50) //2066 //
	{
		end_of_the_list = 16;
		gotoxy(19, 5);
		printf("Материнская плата под LGA 2066");
	}
	if (ch.number == 51) //1200
	{
		end_of_the_list = 24;
		gotoxy(19, 5);
		printf("Материнская плата под LGA 1200");
	}
	if (ch.number == 52) //1700
	{
		end_of_the_list = 24;
		gotoxy(19, 5);
		printf("Материнская плата под LGA 1700");
	}
	if (ch.number == 53) //AM1
	{
		gotoxy(19, 5);
		printf("Материнская плата под AM1");
		end_of_the_list = 14;
	}
	if (ch.number == 54) //AM4
	{
		gotoxy(19, 5);
		printf("Материнская плата под AM4");
		end_of_the_list = 22;
	}
	if (ch.number == 55) //TR4
	{
		gotoxy(19, 5);
		printf("Материнская плата под TR4");
		end_of_the_list = 14;
	}
	//получаем процессоры 
	FILE* file;
	file = fopen(way, "r");
	int p = 8;
	if (file != NULL)
	{
		while (!feof(file)) //цикл до конца файла
		{

			char str[200] = { 0 };
			fgets(str, 150, file);

			if (str[0] == '\t' && str[1] == '\t' && str[2] == nubm_punkt && str[3] == '.' && str[5] == '.' && str[4] == ch.identy_output_sockets && str[7] == '.')
			{


				gotoxy(10, p);

				for (int i = 0; i < 150; i++)
				{
					if (i > 5)
					{
						printf("%c", str[i]);
					}
				}
				p = p + 2;;
			}

		}
		gotoxy(10, p);
		fclose(file);
	} printf("Назад к выбору компонентов");

	int pointer_location = 8;
	int control = 1;
	while (control == 1)
	{
		int button = 0;

		gotoxy(10, 8);
		printf("\b");
		printf(">");
		gotoxy(0, 0);
		button = 0;

		while (button != 13)
		{

			button = getch();

			if (button == 80)
			{

				gotoxy(9, pointer_location);
				printf(" ");

				pointer_location = pointer_location + 2;
				if (pointer_location == end_of_the_list + 2)
				{
					pointer_location = 8;
				}

				gotoxy(10, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
			if (button == 72)
			{

				gotoxy(9, pointer_location);
				printf(" ");
				pointer_location = pointer_location - 2;
				if (pointer_location == 6)
				{
					pointer_location = end_of_the_list;
				}
				gotoxy(10, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
		}
		control--;

	}
	if (pointer_location == end_of_the_list)
	{
		return 50;
	}
	return pointer_location;

}
//пункты с 6 по 9
int punkt6_9(int pk)
{
	int end_of_the_list = 0;
	drawing_box(71, 35);

	if (pk == 11) //2066 //
	{
		end_of_the_list = 18;
		gotoxy(34, 5);
		printf("ОЗУ");
		nubm_punkt = '6';
	}
	if (pk == 13) //1200
	{
		end_of_the_list = 20;
		gotoxy(34, 5);
		printf("SSD");
		nubm_punkt = '7';
	}
	if (pk == 15) //1700
	{
		end_of_the_list = 16;
		gotoxy(34, 5);
		printf("HDD");
		nubm_punkt = '8';
	}
	if (pk == 17) //AM1
	{
		gotoxy(25, 5);
		printf("Блок Питания");
		end_of_the_list = 22;
		nubm_punkt = '9';
	}

	FILE* file;
	file = fopen(way, "r");
	int p = 8;
	if (file != NULL)
	{
		while (!feof(file)) //цикл до конца файла
		{

			char str[200] = { 0 };
			fgets(str, 150, file);
			fseek(stdin, 0, SEEK_END);
			if (str[0] == '\t' && str[1] == nubm_punkt && str[2] == '.' && str[4] == '.')
			{


				gotoxy(10, p);

				for (int i = 0; i < 150; i++)
				{
					if (i > 5)
					{
						printf("%c", str[i]);
					}
				}
				p = p + 2;;
			}

		}
		gotoxy(10, p);
		fclose(file);
	} printf("Назад к выбору компонентов");
	int pointer_location = 8;
	int control = 1;
	while (control == 1)
	{
		int button = 0;

		gotoxy(10, 8);
		printf("\b");
		printf(">");
		gotoxy(0, 0);
		button = 0;

		while (button != 13)
		{

			button = getch();

			if (button == 80)
			{

				gotoxy(9, pointer_location);
				printf(" ");

				pointer_location = pointer_location + 2;
				if (pointer_location == end_of_the_list + 2)
				{
					pointer_location = 8;
				}

				gotoxy(10, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
			if (button == 72)
			{

				gotoxy(9, pointer_location);
				printf(" ");
				pointer_location = pointer_location - 2;
				if (pointer_location == 6)
				{
					pointer_location = end_of_the_list;
				}
				gotoxy(10, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
		}
		control--;

	}
	if (pointer_location == end_of_the_list)
	{
		return 50;
	}
	return pointer_location;

}
//пункты с 10 по 16
int punkt10_16(int pk)
{
	int end_of_the_list = 0;
	drawing_box(71, 35);
	if (pk == 19) //AM4
	{
		gotoxy(19, 5);
		printf("Кулеры");
		end_of_the_list = 26;
		nubm_punkt = '0';
	}
	if (pk == 21) //TR4
	{
		gotoxy(25, 5);
		printf("Корпус");
		end_of_the_list = 22;
		nubm_punkt = '1';
	}
	if (pk == 23) //TR4
	{
		gotoxy(19, 5);
		printf("Звуковая карта");
		end_of_the_list = 22;
		nubm_punkt = '2';
	}
	if (pk == 25) //TR4
	{
		gotoxy(19, 5);
		printf("Оптический привод");
		end_of_the_list = 16;
		nubm_punkt = '3';
	}
	if (pk == 27) //TR4
	{
		gotoxy(19, 5);
		printf("Сетевая карта");
		end_of_the_list = 20;
		nubm_punkt = '4';
	}
	if (pk == 29) //TR4
	{
		gotoxy(19, 5);
		printf("Кард-Риддер");
		end_of_the_list = 16;
		nubm_punkt = '5';
	}
	if (pk == 31) //TR4
	{
		gotoxy(35, 5);
		printf("OS");
		end_of_the_list = 16;
		nubm_punkt = '6';
	}

	FILE* file;
	file = fopen(way, "r");
	int p = 8;
	if (file != NULL)
	{
		while (!feof(file)) //цикл до конца файла
		{

			char str[200] = { 0 };
			fgets(str, 150, file);

			if (str[0] == '\t' && str[1] == '1' && str[2] == nubm_punkt && str[3] == '.' && str[5] == '.')
			{


				gotoxy(10, p);

				for (int i = 0; i < 150; i++)
				{
					if (i > 3)
					{
						printf("%c", str[i]);
					}
				}
				p = p + 2;;
			}

		}
		gotoxy(10, p);
		fclose(file);
	} printf("          Назад к выбору компонентов");
	int pointer_location = 8;
	int control = 1;
	while (control == 1)
	{
		int button = 0;

		gotoxy(10, 8);
		printf("\b");
		printf(">");
		gotoxy(0, 0);
		button = 0;

		while (button != 13)
		{

			button = getch();

			if (button == 80)
			{

				gotoxy(9, pointer_location);
				printf(" ");

				pointer_location = pointer_location + 2;
				if (pointer_location == end_of_the_list + 2)
				{
					pointer_location = 8;
				}

				gotoxy(10, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
			if (button == 72)
			{

				gotoxy(9, pointer_location);
				printf(" ");
				pointer_location = pointer_location - 2;
				if (pointer_location == 6)
				{
					pointer_location = end_of_the_list;
				}
				gotoxy(10, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
		}
		control--;

	}
	if (pointer_location == end_of_the_list)
	{
		return 50;
	}
	return pointer_location;

}
// вывод всех видеокарт
int GPU_menu()
{
	for (int i = 0; i < 60; i++)
	{

		gotoxy(0, i);
		printf("|");
		gotoxy(70, i);
		printf("|");
	}
	for (int i = 0; i < 71; i++)
	{

		gotoxy(i, 0);
		printf("|");
		gotoxy(i, 60);
		printf("|");
	}
	nubm_punkt = '5';
	int end_of_the_list = 56;
	gotoxy(25, 5);
	printf("Видеокарты");
	FILE* file;
	file = fopen(way, "r");
	int p = 8;
	if (file != NULL)
	{
		while (!feof(file)) //цикл до конца файла
		{

			char str[200] = { 0 };
			fgets(str, 150, file);

			if (str[0] == '\t' && str[1] == nubm_punkt && str[2] == '.' && str[3] != '\t' && str[3] != ' ' && str[4] == '.' && checking_numb(str[5]) == 0)
			{

				gotoxy(10, p);

				for (int i = 0; i < 150; i++)
				{
					if (i > 5)
					{
						printf("%c", str[i]);
					}
				}
				p = p + 2;;
			}
			if (str[0] == '\t' && str[1] == nubm_punkt && str[2] == '.' && str[3] != '\t' && str[3] != ' ' && str[5] == '.' && checking_numb(str[6]) == 0)
			{
				gotoxy(9, p);

				for (int i = 0; i < 150; i++)
				{
					if (i > 5)
					{
						printf("%c", str[i]);
					}
				}
				p = p + 2;;
			}

		}

		gotoxy(10, p);

		fclose(file);
	} printf("Назад к выбору компонентов");

	int pointer_location = 8;
	int control = 1;
	while (control == 1)
	{
		int button = 0;

		gotoxy(10, 8);
		printf("\b");
		printf(">");
		gotoxy(0, 0);
		button = 0;

		while (button != 13)
		{

			button = getch();

			if (button == 80)
			{

				gotoxy(9, pointer_location);
				printf(" ");

				pointer_location = pointer_location + 2;
				if (pointer_location == end_of_the_list + 2)
				{
					pointer_location = 8;
				}

				gotoxy(10, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
			if (button == 72)
			{

				gotoxy(9, pointer_location);
				printf(" ");
				pointer_location = pointer_location - 2;
				if (pointer_location == 6)
				{
					pointer_location = end_of_the_list;
				}
				gotoxy(10, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
		}
		control--;

	}
	if (pointer_location == end_of_the_list)
	{
		return 50;
	}
	return pointer_location;

}
//запись названия видеокарарты в структуру
char* name_to_str_GPU(int serch)
{
	drawing_box(71, 35);
	char object[50] = { 0 };
	FILE* file;
	file = fopen(way, "r");
	int p = 8;

	if (serch < 26) //выбрана видеокарта до 10 ( 26 в переводе будет 10 )
	{
		char serch_num = ((serch - 6) / 2) + '0';
		if (file != NULL)
		{
			while (!feof(file)) //цикл до конца файла
			{

				char str[200] = { 0 };
				fgets(str, 150, file);
				int j = 0;
				if (str[0] == '\t' && str[1] == '5' && str[2] == '.' && str[3] == serch_num && str[4] == '.')
				{
					for (int i = 6; i < 49; i++)
					{
						object[j] = str[i];
						j++;
					}
				}

			}
			fclose(file);
		}
	}
	else //если у выбранной видеокарты в номере больше двух цифр
	{
		char serch_num1 = (((serch - 6) / 2)) / 10 + '0';
		char serch_num2 = (((serch - 6) / 2)) % 10 + '0';
		if (file != NULL)
		{
			while (!feof(file)) //цикл до конца файла
			{

				char str[200] = { 0 };
				fgets(str, 150, file);
				int j = 0;
				if (str[0] == '\t' && str[1] == '5' && str[2] == '.' && str[3] == serch_num1 && str[4] == serch_num2 && str[5] == '.')
				{
					for (int i = 6; i < 49; i++)
					{
						object[j] = str[i];
						j++;
					}
				}

			}
			fclose(file);
		}
	}
	system("cls");



	return object;

}
//запись в структуру из пунктов 6-16
char* name_to_str_6_9(int serch)
{
	drawing_box(71, 35);

	char object[50] = { 0 };
	FILE* file;
	file = fopen(way, "r");
	int p = 8;


	char serch_num = ((serch - 6) / 2) + '0';
	if (file != NULL)
	{
		while (!feof(file)) //цикл до конца файла
		{

			char str[200] = { 0 };
			fgets(str, 150, file);
			int j = 0;
			if (str[0] == '\t' && str[1] == nubm_punkt && str[2] == '.' && str[4] == '.' && str[3] == serch_num)
			{
				for (int i = 6; i < 49; i++)
				{
					object[j] = str[i];
					j++;
				}
			}

		}
		fclose(file);
	}
	nubm_punkt = NULL;

	system("cls");



	return object;

}
char* name_to_str_10_16(int serch)
{
	drawing_box(71, 35);

	char object[50] = { 0 };
	FILE* file;
	file = fopen(way, "r");
	int p = 8;


	char serch_num = ((serch - 6) / 2) + '0';
	if (file != NULL)
	{
		while (!feof(file)) //цикл до конца файла
		{

			char str[200] = { 0 };
			fgets(str, 150, file);
			int j = 0;
			if (str[0] == '\t' && str[1] == '1' && str[2] == nubm_punkt && str[3] == '.' && str[5] == '.' && str[4] == serch_num)
			{
				for (int i = 6; i < 49; i++)
				{
					object[j] = str[i];
					j++;
				}
			}

		}
		fclose(file);
	}
	nubm_punkt = NULL;

	system("cls");



	return object;

}
//подсчтёт суммы за все компоненты
int chek_cost_all()
{
	int all_cost[15] = { PC.CPU_ch,PC.CPU_cost,PC.motherboard_cost ,PC.GPU_cost,PC.RAM_cost, PC.SSD_cost , PC.HDD_cost, PC.Power_Supply_cost, PC.coolers_cost,
	PC.Frame_cost,PC.Sound_Сard_cost,PC.Optical_Drive_cost, PC.Net_cost,PC.Card_Reader_cost, PC.OS_cost };

	for (int i = 0; i <= 14; i++)
	{
		if (all_cost[i] == 0)
		{
			return 0;
		}
	}
	return 1;

}
//вопрос "Вы уверены?"
int shure(int var)
{
	//var определяет какой вопрос будет задан
	for (int i = 0; i < 20; i++)
	{

		gotoxy(0, i);
		printf("|");
		gotoxy(70, i);
		printf("|");
	}
	for (int i = 0; i < 71; i++)
	{

		gotoxy(i, 0);
		printf("|");
		gotoxy(i, 20);
		printf("|");
	}
	int pointer_location = 8;
	int control = 1;
	if (var == 1)

	{
		gotoxy(12, 3);
		printf("Вы уверены что хотите записать ");
		gotoxy(8, 4);
		printf("данную конфигурацю вместо других данных в файле ?");
		gotoxy(10, 6);
		printf("%s", way_to_save);
	}
	if (var == 2)
	{
		gotoxy(12, 3);
		printf("Вы уверены что хотите импортировать");
		gotoxy(8, 4);
		printf("данную конфигурацю вместо имеющейся?");
		gotoxy(10, 6);
		printf("%s", way_to_import);
	}
	gotoxy(12, 8);
	printf("Да");
	gotoxy(12, 10);
	printf("Нет");
	while (control == 1)
	{
		int button = 0;
		int end_of_the_list = 10;
		gotoxy(10, 8);
		printf("\b");
		printf(">");
		gotoxy(0, 0);
		button = 0;

		while (button != 13)
		{

			button = getch();

			if (button == 80)
			{

				gotoxy(9, pointer_location);
				printf(" ");

				pointer_location = pointer_location + 2;
				if (pointer_location == end_of_the_list + 2)
				{
					pointer_location = 8;
				}

				gotoxy(10, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
			if (button == 72)
			{

				gotoxy(9, pointer_location);
				printf(" ");
				pointer_location = pointer_location - 2;
				if (pointer_location == 6)
				{
					pointer_location = end_of_the_list;
				}
				gotoxy(10, pointer_location);
				printf("\b");
				printf(">");
				gotoxy(0, 0);

			}
		}
		control--;
	}
	return pointer_location;
}
//полная очистка концфигурации
void dell_all() {
	PC.CPU_ch = 0;
	strcpy(PC.CPU_socket, clean);
	PC.CPU_socket_ch = 0;

	strcpy(PC.CPU, clean);
	PC.CPU_cost = 0;
	PC.CPU_yes = 0;

	strcpy(PC.motherboard, clean);
	PC.motherboard_cost = 0;

	strcpy(PC.GPU, clean);
	PC.GPU_cost = 0;

	strcpy(PC.RAM, clean);
	PC.RAM_cost = 0;

	strcpy(PC.SSD, clean);
	PC.SSD_cost = 0;

	strcpy(PC.HDD, clean);
	PC.HDD_cost = 0;

	strcpy(PC.Power_Supply, clean);
	PC.Power_Supply_cost = 0;

	strcpy(PC.coolers, clean);
	PC.coolers_cost = 0;

	strcpy(PC.Frame, clean);
	PC.Frame_cost = 0;

	strcpy(PC.Sound_Сard, clean);
	PC.Sound_Сard_cost = 0;

	strcpy(PC.Optical_Drive, clean);
	PC.Optical_Drive_cost;

	strcpy(PC.Net, clean);
	PC.Net_cost = 0;

	strcpy(PC.Card_Reader, clean);
	PC.Card_Reader_cost;

	strcpy(PC.OS, clean);
	PC.OS_cost = 0;



}
int existence_proc(char product_name[], char numb_soc)
{
	FILE* file;
	file = fopen(way, "r");
	int str_count = 0;
	if (file != NULL)
	{
		while (!feof(file)) //цикл до конца файла
		{
			char str[200] = { 0 };
			fgets(str, 150, file);

			if (str_count == 0)
			{
				if (str[0] == '\t' && str[1] == '\t' && str[2] == 'К' && str[3] == 'о' && str[4] == 'н' && str[5] == 'ф' && str[6] == 'и' && str[7] == 'г' && str[8] == 'у' && str[9] == 'р' && str[10] == 'а' && str[11] == 'т' && str[12] == 'о' && str[13] == 'р')
				{}
				else { return 0; }
			}
			if (str_count == 1)
			{
				if (str[0] == '\n' )
				{}else{return 0;}
			}
			if (str_count == 2)
			{
				if (str[0] == '\n')
				{}
				else { return 0; }
			}
			if (str_count == 3)
			{
				if (str[0] == ' ' && str[1] == '1' && str[2] == '.' && str[3] == ' ' && str[4] == ' ' && str[5] == 'П' && str[6] == 'р' && str[7] == 'о' && str[8] == 'и' && str[9] == 'з' && str[10] == 'в' && str[11] == 'о' && str[12] == 'д' && str[13] == 'и' && str[14] == 'н')
				{
				}
				else { return 0; }
			}
			str_count++;
		}
		fclose(file);
	}
}
int main()
{


	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	instruction_control();
	int proc = 0;
	int punkt_1 = 0;
	int proiz = 0;
	int soct = 0;
	int one_proc = 0;
	while (1)
	{
		int stop = 0; //для возврата из любого пункта в главное меню
		while (stop == 0)
		{
			int menu = main_menu_control();                                    //отрисовывем главное менню
			if (menu == 9)                //выбран пункт меню 1
			{



				while (stop == 0) //аналог бесконечного цикла для данной функции, т.к его нельзя завершить из данного пункта(выбор компонента)
				{
					int stop_2 = 0; //для возврата к выбору компоненетов
					while (stop_2 == 0)
					{
						punkt_1 = first_item_control();           //отрисовка пунтка 1

						if (punkt_1 == 5)                                  // если выбрали пункт  1. Процессоры
						{
							nubm_punkt = '3';      //нумерация для процессорв цифра 3
							int stop_3 = 0;         //для возврата к выбору компонентов
							while (stop_3 == 0)
							{


								proiz = drawing_get_processor_manufacturer_to_files();            //отрисовка выбора производителся

								if (proiz == 20)        // назад в выбор комопнентов
								{
									system("cls");
									stop_3 = 1;
								}

								if (proiz == 10 || proiz == 15)// был выбран один из прозводителей
								{

									int stop_4 = 0; //для возврата к выбору производителей и очистка выбора
									while (stop_4 == 0)
									{
										int stop_5 = 0;
										AMD = 0;
										INTEL = 0;
										while (stop_5 == 0) //для возврата к выбору прозводителей
										{
											//-------------------------------------
											strcpy(PC.CPU_make, clean);  //очистка
											strcpy(PC.motherboard, clean);
											PC.CPU_ch = 0;
											PC.CPU_yes = 0;
											//--------------------------------------
											if (proiz == 10)// AMD
											{
												//++++++++++++++++++++++++++++++++++
												INTEL = 0;
												AMD = 1;
												PC.CPU_ch = 1;
												strcpy(PC.CPU_make, " AMD");//заносим в структуру
												//++++++++++++++++++++++++++++++++++

												soct = output_sockets(); //выбор сокета
												if (soct != 30) //если не выбран выход
												{
													//---------------------------------
													strcpy(PC.CPU_socket, clean);
													PC.CPU_socket_ch = 0;
													PC.CPU_yes = 0;
													//---------------------------------

													//++++++++++++++++++++++++++++++++++
													if (soct == 15)                     // AM1
													{
														strcpy(PC.CPU_socket, " AM1"); //заносим сокет
														PC.CPU_socket_ch = 1;
													}
													if (soct == 20)                     //  AM4
													{
														strcpy(PC.CPU_socket, " AM4");
														PC.CPU_socket_ch = 1;
													}
													if (soct == 25)                     // TR4
													{
														strcpy(PC.CPU_socket, " TR4");
														PC.CPU_socket_ch = 1;
													}
													//++++++++++++++++++++++++++++++++++
													one_proc = AMD_Proc(soct); //выводим процессоры с полученым сокетом (50 выход )

													if (one_proc == 50)     //назад в сокеты
													{
														system("cls");
														stop_5 = 1;
													}
													else
													{
														char* name_CPU_AMD = cpu_name_to_array(one_proc);
														strcpy(PC.CPU, name_CPU_AMD);
														discount.without = 0;
														if (PC.CPU[12] == '5' && PC.CPU[13] == '9' && PC.CPU[14] == '5' && PC.CPU[15] == '0' && PC.CPU[16] == 'X')
														{
															discount.percent = (PC.CPU[12] + PC.CPU[13] + PC.CPU[14] + PC.CPU[15] + PC.CPU[16]) / 50;
														}
														your_ch(PC.CPU);
														PC.CPU_cost = price(PC.CPU);
														PC.CPU_yes = 1;
														stop_3 = 1;
														stop_4 = 1;
														stop_5 = 1;


													}
												}


											}
											if (proiz == 15)// INTEL так же как у AMD
											{
												//++++++++++++++++++++++++++++++++++
												INTEL = 1;
												AMD = 0;
												strcpy(PC.CPU_make, " INTEL"); //заносим в структуру
												PC.CPU_ch = 1;
												//++++++++++++++++++++++++++++++++++

												soct = output_sockets();
												if (soct != 30)
												{
													//---------------------------------
													strcpy(PC.CPU_socket, clean);
													PC.CPU_socket_ch = 0;
													PC.CPU_yes = 0;
													//---------------------------------

													//++++++++++++++++++++++++++++++++++
													if (soct == 10)                     // LGA 1151
													{
														strcpy(PC.CPU_socket, " LGA 1151");
														PC.CPU_socket_ch = 1;
													}
													if (soct == 15)                     //  LGA 2066
													{
														strcpy(PC.CPU_socket, " LGA 2066");
														PC.CPU_socket_ch = 1;
													}
													if (soct == 20)                     // LGA 1200
													{
														strcpy(PC.CPU_socket, " LGA 1200");
														PC.CPU_socket_ch = 1;
													}
													if (soct == 25)                     // LGA 1700
													{
														strcpy(PC.CPU_socket, " LGA 1700");
														PC.CPU_socket_ch = 1;
													}
													//++++++++++++++++++++++++++++++++++

													one_proc = Intel_Proc(soct); //50 выход

													if (one_proc == 50)     //назад в сокеты
													{
														system("cls");
														stop_5 = 1;
													}

													else //возврат к выбору компонентов
													{
														char* name_CPU_Intel = cpu_name_to_array(one_proc);
														strcpy(PC.CPU, name_CPU_Intel);
														discount.without = 0;
														if (PC.CPU[14] == '1' && PC.CPU[15] == '2' && PC.CPU[16] == '9' && PC.CPU[17] == '0' && PC.CPU[18] == '0')
														{
															discount.percent = (PC.CPU[14] + PC.CPU[15] + PC.CPU[16] + PC.CPU[17] + PC.CPU[18])/10 ;
														}
														your_ch(PC.CPU);
														PC.CPU_cost = price(PC.CPU);
														PC.CPU_yes = 1;
														stop_3 = 1;
														stop_4 = 1;
														stop_5 = 1;


													}



												}

											}
											if (soct == 30)  //возварт к выбору сокетов
											{
												system("cls");
												stop_4 = 1;
												stop_5 = 1;

											}
										}
									}
								}

								/////////////////////////////////////////////////////////////////////////////////








							}
						}
						if (punkt_1 == 7)                                  // выбор материнской платы
						{

							if (PC.CPU_yes != 1)  //ещё не выбран процессор
							{
								for (int i = 0; i < 31; i++)
								{

									gotoxy(0, i);
									printf("|");
									gotoxy(70, i);
									printf("|");
								}
								for (int i = 0; i < 71; i++)
								{

									gotoxy(i, 0);
									printf("|");
									gotoxy(i, 31);
									printf("|");
								}
								gotoxy(17, 5);
								printf("!!Вы ещё не выбрали процессор!!");
								gotoxy(0, 37);
								system("pause");
								stop_2 = 1;
							}
							else
							{
								int chois_MB = motherboard();
								if (chois_MB == 50)
								{
									stop_2 = 1;
								}
								else
								{
									strcpy(PC.motherboard, clean);
									char* name_MB = cpu_name_to_array(chois_MB);
									strcpy(PC.motherboard, name_MB);
									your_ch(PC.motherboard);
									PC.motherboard_cost = price(PC.motherboard);
									stop_2 = 1;
								}


							}

						}
						if (punkt_1 == 9)  //выбор видеокарты
						{
							int chois_GPU = GPU_menu();
							if (chois_GPU == 50)
							{
								stop_2 = 1;
							}
							else
							{
								strcpy(PC.GPU, clean);
								char* name_GPU = name_to_str_GPU(chois_GPU);
								strcpy(PC.GPU, name_GPU);
								your_ch(PC.GPU);
								PC.GPU_cost = price(PC.GPU);
								stop_2 = 1;
							}
						}



						//выбор пунктов 1-16
						if (punkt_1 == 11 || punkt_1 == 13 || punkt_1 == 15 || punkt_1 == 17)
						{
							int chois_p69 = punkt6_9(punkt_1);
							if (chois_p69 == 50)
							{
								stop_2 = 1;

							}

							else {
								char* name_6_9 = name_to_str_6_9(chois_p69);
								if (punkt_1 == 11)
								{
									strcpy(PC.RAM, name_6_9);
									PC.RAM_cost = price(PC.RAM);
									your_ch(PC.RAM);
								}
								if (punkt_1 == 13)
								{
									strcpy(PC.SSD, name_6_9);
									PC.SSD_cost = price(PC.SSD);
									your_ch(PC.SSD);
								}
								if (punkt_1 == 15)
								{
									strcpy(PC.HDD, name_6_9);
									PC.HDD_cost = price(PC.HDD);
									your_ch(PC.HDD);
								}
								if (punkt_1 == 17)
								{
									strcpy(PC.Power_Supply, name_6_9);
									PC.Power_Supply_cost = price(PC.Power_Supply);
									your_ch(PC.Power_Supply);

								}
								//your_ch(name_6_9);
								stop_2 = 1;
							}
						}
						if (punkt_1 == 19 || punkt_1 == 21 || punkt_1 == 22 || punkt_1 == 23 || punkt_1 == 25 || punkt_1 == 27 || punkt_1 == 29 || punkt_1 == 31)
						{
							int chois_p1016 = punkt10_16(punkt_1);
							if (chois_p1016 == 50)
							{

								stop_2 = 1;
							}
							else
							{

								char* name_10_11 = name_to_str_10_16(chois_p1016);

								if (punkt_1 == 19)
								{
									strcpy(PC.coolers, name_10_11);
									PC.coolers_cost = price(PC.coolers);
									your_ch(PC.coolers);
								}
								if (punkt_1 == 21)
								{
									strcpy(PC.Frame, name_10_11);
									PC.Frame_cost = price(PC.Frame);
									your_ch(PC.Frame);
								}
								if (punkt_1 == 23)
								{
									strcpy(PC.Sound_Сard, name_10_11);
									PC.Sound_Сard_cost = price(PC.Sound_Сard);
									your_ch(PC.Sound_Сard);
								}
								if (punkt_1 == 25)
								{
									strcpy(PC.Optical_Drive, name_10_11);
									PC.Optical_Drive_cost = price(PC.Optical_Drive);
									your_ch(PC.Optical_Drive);
								}
								if (punkt_1 == 27)
								{
									strcpy(PC.Net, name_10_11);
									PC.Net_cost = price(PC.Net);
									your_ch(PC.Net);
								}
								if (punkt_1 == 29)
								{
									strcpy(PC.Card_Reader, name_10_11);
									PC.Card_Reader_cost = price(PC.Card_Reader);
									your_ch(PC.Card_Reader);
								}
								if (punkt_1 == 31)
								{
									strcpy(PC.OS, name_10_11);
									PC.OS_cost = price(PC.OS);
									your_ch(PC.OS);
								}

								stop_2 = 1;
							}
						}
						//punkt10_16
					  ////////////////////////////////
						if (punkt_1 == 33)        //назад из меню
						{
							system("cls");
							stop = 1;
							stop_2 = 1;

						}

					}
				}



			}
			//удаление конфингурации
			if (menu == 18)
			{

				dell_all();
				gotoxy(0, 38);
				printf("Конфигурация удалена");
				stop = 1;
			}
			//сохранить в файл
			if (menu == 12)
			{
				if (chek_cost_all() == 0)
				{
					//return chek_cost_all();
					gotoxy(75, 12);
					printf("Вы ещё не выбрали все компоненты\n");
					stop = 1;
				}
				else {
					int return_menu = 0;
					int chek_file = 1;
					while (chek_file == 1)
					{
						printf("\n  Введиет путь к файлу "
							"\n  В формете: Config.txt \n\n !!при длине пути более 100 символов, оставшаяся часть будует стёрта!!"
							"\n  !Введите 0 что бы вернуться в меню!");
						for (int i = 0; i < 6; i++)
						{

							gotoxy(0, i);
							printf("|");
							gotoxy(70, i);
							printf("|");
						}
						for (int i = 0; i < 71; i++)
						{

							gotoxy(i, 0);
							printf("_");
							gotoxy(i, 6);
							printf("-");
						}
						printf("\n\n  Введите здесь:");
						fgets(way_to_save, 100, stdin);
						if (way_to_save[0] == '0' && way_to_save[1] == '\n')
						{
							chek_file = 0;
							return_menu = 1;
							system("cls");
							stop = 1;
							break;


						}
						printf("\n Нажите Enter, что бы продолжить");
						while (getchar() != '\n'); { }
						for (int i = 0; i < 100; i++)
						{
							if (way_to_save[i] == '\n')
							{
								way_to_save[i] = NULL;
							}

						}
						FILE* file;
						file = fopen(way_to_save, "r");
						if (file != NULL)
						{

							chek_file = 0;
							system("cls");

						}
						else
						{
							printf("\n\nФайл не найден, либо неверно введёт путь к файлу. Повторите попытку \n");
							system("pause");
							system("cls");
						}
					}
					if (return_menu == 0)
					{
						int vibor = shure(1);
						if (vibor == 8)
						{
							FILE* file;
							file = fopen(way_to_save, "w");
							if (file != NULL)
							{
								//fprintf(file, %s, "                                Конфигурация компьютера", file);
								fprintf(file, "\t\tКонфигурация\n\n\n");
								fprintf(file, " 1.  Производитель процессора:  %s \n\n", PC.CPU_make);
								fprintf(file, " 2.  Сокет процессора        :  %s \n\n", PC.CPU_socket);
								fprintf(file, " 3.  Процессор               :   %s \n\n", PC.CPU);
								fprintf(file, " 4.  Материнская плата       :   %s \n\n", PC.motherboard);
								fprintf(file, " 5.  Видеокарта              :   %s \n\n", PC.GPU);
								fprintf(file, " 6.  Опертивная память       :   %s \n\n", PC.RAM);
								fprintf(file, " 7.  SSD                     :   %s \n\n", PC.SSD);
								fprintf(file, " 8.  HDD                     :   %s \n\n", PC.HDD);
								fprintf(file, " 9.  Блок Питания            :   %s \n\n", PC.Power_Supply);
								fprintf(file, "10.  Кулеры                  : %s \n\n", PC.coolers);
								fprintf(file, "11.  Корпус                  : %s \n\n", PC.Frame);
								fprintf(file, "12.  Звуковая карта          : %s \n\n", PC.Sound_Сard);
								fprintf(file, "13.  Оптический привод       : %s \n\n", PC.Optical_Drive);
								fprintf(file, "14.  Сетевая карта           : %s \n\n", PC.Net);
								fprintf(file, "15.  Кард-риддер             : %s \n\n", PC.Card_Reader);
								fprintf(file, "16.  OS                      : %s \n\n", PC.OS);
								fprintf(file, "СУММА: %d рублей \n\n", PC.summ);

								fclose(file);
							}
							system("cls");
							stop = 1;
						}
						if (vibor == 10)
						{
							system("cls");
							stop = 1;

						}
					}
				}

			}
			if (menu == 15) //получить конфигурацию из файла
			{
				int return_menu = 0;
				int chek_file = 1;
				while (chek_file == 1)
				{
					printf("\n  Введите путь к файлу "
						"\n  В формете: Import.txt \n\n !!при длине пути более 100 символов, оставшаяся часть будует стёрта!!"
						"\n  !Введите 0 что бы вернуться в меню!");
					for (int i = 0; i < 6; i++)
					{

						gotoxy(0, i);
						printf("|");
						gotoxy(70, i);
						printf("|");
					}
					for (int i = 0; i < 71; i++)
					{

						gotoxy(i, 0);
						printf("_");
						gotoxy(i, 6);
						printf("-");
					}
					printf("\n\n  Введите здесь:");

					fgets(way_to_import, 100, stdin);
					if (way_to_import[0] == '0' && way_to_import[1] == '\n')
					{
						chek_file = 0;
						return_menu = 1;
						system("cls");
						stop = 1;
						break;


					}
					printf("\n Нажите Enter, что бы продолжить");
					while (getchar() != '\n'); { }
					for (int i = 0; i < 100; i++)
					{
						if (way_to_import[i] == '\n')
						{
							way_to_import[i] = NULL;
						}

					}
					FILE* file;
					file = fopen(way_to_import, "r");
					if (file != NULL)
					{

						chek_file = 0;
						system("cls");

					}
					else
					{
						printf("\n\nФайл не найден, либо неверно введёт путь к файлу. Повторите попытку \n");
						system("pause");
						system("cls");
					}
				}

				int vibor = 10;
				if (return_menu == 1)
				{
					system("cls");
					stop = 1;
				}
				else
				{
					vibor = shure(2);
				}
				if (vibor == 10)
				{
					system("cls");
					stop = 1;
				}
				if (vibor == 8)
				{

					dell_all();
					FILE* file;
					file = fopen("Import.txt", "r");

					if (file != NULL)
					{
						char send_of_the_list[50] = { 0 };
						while (!feof(file)) //цикл до конца файла
						{

							char str[200] = { 0 };
							fgets(str, 150, file);
							int j = 0;
							if (str[1] == '1' && str[2] == '.' && str[0] == ' ')
							{
								j = 0;
								for (int i = 32; i < 81; i++)
								{
									send_of_the_list[j] = str[i];
									j++;
								}
								if (send_of_the_list[1] == 'I')
								{
									INTEL = 1;
								}
								if (send_of_the_list[1] == 'A')
								{
									AMD = 1;
								}
								if (AMD != 1 && INTEL != 1)
								{
									stop = 1;
									system("cls");
									printf("Некорректный ввод производителя процессора, импорт не выполнен \n");
									system("pause");
									break;

								}
								strcpy(PC.CPU_make, send_of_the_list);
								strcpy(send_of_the_list, clean);
							}
							if (str[1] == '2' && str[2] == '.' && str[0] == ' ')
							{
								j = 0;
								for (int i = 32; i < 81; i++) // i 32
								{
									send_of_the_list[j] = str[i];
									j++;
								}
								if (INTEL == 1)
								{
									if (send_of_the_list[6] == '1')
									{
										ch.number = 49;
									}
									if (send_of_the_list[6] == '0')
									{
										ch.number = 50;
									}
									if (send_of_the_list[6] == '2')
									{
										ch.number = 51;
									}
									if (send_of_the_list[6] == '7')
									{
										ch.number = 52;
									}
									if (send_of_the_list[1] == 'A' || send_of_the_list[1] == 'T')
									{
										stop = 1;
										system("cls");
										printf("Некорректный ввод сокета, убедитесь что сокет от INTEL, импорт не выполнен \n");
										system("pause");
										break;
									}
								}
								if (AMD == 1)
								{
									if (send_of_the_list[1] == 'A' && str[3] == '1')
									{
										ch.number = 53;
									}
									if (send_of_the_list[1] == 'A' && str[3] == '4')
									{
										ch.number = 54;
									}
									if (send_of_the_list[1] == 'T' && str[3] == '4')
									{
										ch.number = 55;
									}
									if (send_of_the_list[6] == '7')
									{
										ch.number = 52;
									}
									else
									{
										stop = 1;
										system("cls");
										printf("Некорректный ввод сокета, убедитесь что сокет от AMD, импорт не выполнен \n");
										system("pause");
										break;
									}
								}
								strcpy(PC.CPU_socket, send_of_the_list);
								strcpy(send_of_the_list, clean);
							}
							if (str[1] == '3' && str[2] == '.' && str[0] == ' ')
							{
								j = 0;
								for (int i = 33; i < 82; i++)
								{
									send_of_the_list[j] = str[i];
									j++;
								}
								if (send_of_the_list[0] == 'I' && AMD == 1)
								{
									stop = 1;
									system("cls");
									printf("Некорректный ввод процессора, импорт не выполнен \n");
									system("pause");
									break;
								}
								if (send_of_the_list[0] == 'A' && INTEL == 1)
								{
									stop = 1;
									system("cls");
									printf("Некорректный ввод процессора, импорт не выполнен \n");
									system("pause");
									break;
								}
								PC.CPU_ch = 1;
								PC.CPU_yes = 1;

								strcpy(PC.CPU, send_of_the_list);
								strcpy(send_of_the_list, clean);
							}
							if (str[1] == '4' && str[2] == '.' && str[0] == ' ')
							{
								j = 0;
								for (int i = 33; i < 82; i++)
								{
									send_of_the_list[j] = str[i];
									j++;
								}

								strcpy(PC.motherboard, send_of_the_list);
								strcpy(send_of_the_list, clean);

							}
							if (str[1] == '5' && str[2] == '.' && str[0] == ' ')
							{
								j = 0;
								for (int i = 33; i < 82; i++)
								{
									send_of_the_list[j] = str[i];
									j++;
								}
								strcpy(PC.GPU, send_of_the_list);
								strcpy(send_of_the_list, clean);
							}
							if (str[1] == '6' && str[2] == '.' && str[0] == ' ')
							{
								j = 0;
								for (int i = 33; i < 82; i++)
								{
									send_of_the_list[j] = str[i];
									j++;
								}
								strcpy(PC.RAM, send_of_the_list);
								strcpy(send_of_the_list, clean);
							}
							if (str[1] == '7' && str[2] == '.' && str[0] == ' ')
							{

								j = 0;
								for (int i = 33; i < 82; i++)
								{
									send_of_the_list[j] = str[i];
									j++;
								}
								strcpy(PC.SSD, send_of_the_list);
								strcpy(send_of_the_list, clean);
							}
							if (str[1] == '8' && str[2] == '.' && str[0] == ' ')
							{
								j = 0;
								for (int i = 33; i < 82; i++)
								{
									send_of_the_list[j] = str[i];
									j++;
								}
								strcpy(PC.HDD, send_of_the_list);
								strcpy(send_of_the_list, clean);
							}
							if (str[1] == '9' && str[2] == '.' && str[0] == ' ')
							{
								j = 0;
								for (int i = 33; i < 82; i++)
								{
									send_of_the_list[j] = str[i];
									j++;
								}
								strcpy(PC.Power_Supply, send_of_the_list);
								strcpy(send_of_the_list, clean);
							}
							if (str[0] == '1' && str[1] == '0' && str[2] == '.')
							{
								j = 0;
								for (int i = 31; i < 80; i++)
								{

									send_of_the_list[j] = str[i];
									j++;
								}
								strcpy(PC.coolers, send_of_the_list);
								strcpy(send_of_the_list, clean);
							}
							if (str[0] == '1' && str[1] == '1' && str[2] == '.')
							{
								j = 0;
								for (int i = 30; i < 79; i++)
								{
									send_of_the_list[j] = str[i];
									j++;
								}
								strcpy(PC.Frame, send_of_the_list);
								strcpy(send_of_the_list, clean);
							}
							if (str[0] == '1' && str[1] == '2' && str[2] == '.')
							{
								j = 0;
								for (int i = 30; i < 79; i++)
								{
									send_of_the_list[j] = str[i];
									j++;
								}
								strcpy(PC.Sound_Сard, send_of_the_list);
								strcpy(send_of_the_list, clean);
							}

							if (str[0] == '1' && str[1] == '3' && str[2] == '.')
							{
								j = 0;
								for (int i = 30; i < 79; i++)
								{
									send_of_the_list[j] = str[i];
									j++;
								}
								strcpy(PC.Optical_Drive, send_of_the_list);
								strcpy(send_of_the_list, clean);
							}
							if (str[0] == '1' && str[1] == '4' && str[2] == '.')
							{
								j = 0;
								for (int i = 30; i < 79; i++)
								{
									send_of_the_list[j] = str[i];
									j++;
								}
								strcpy(PC.Net, send_of_the_list);
								strcpy(send_of_the_list, clean);
							}
							if (str[0] == '1' && str[1] == '5' && str[2] == '.')
							{
								j = 0;
								for (int i = 30; i < 79; i++)
								{
									send_of_the_list[j] = str[i];
									j++;
								}
								strcpy(PC.Card_Reader, send_of_the_list);
								strcpy(send_of_the_list, clean);

							}
							if (str[0] == '1' && str[1] == '6' && str[2] == '.')
							{
								j = 0;
								for (int i = 30; i < 79; i++)
								{
									send_of_the_list[j] = str[i];
									j++;
								}
								strcpy(PC.OS, send_of_the_list);
								strcpy(send_of_the_list, clean);
							}

							PC.CPU_cost = price(PC.CPU);
							PC.motherboard_cost = price(PC.motherboard);
							PC.GPU_cost = price(PC.GPU);
							PC.RAM_cost = price(PC.RAM);
							PC.SSD_cost = price(PC.SSD);
							PC.HDD_cost = price(PC.HDD);
							PC.Power_Supply_cost = price(PC.Power_Supply);
							PC.coolers_cost = price(PC.coolers);
							PC.Frame_cost = price(PC.Frame);
							PC.Sound_Сard_cost = price(PC.Sound_Сard);
							PC.Optical_Drive_cost = price(PC.Optical_Drive);
							PC.Net_cost = price(PC.Net);
							PC.Card_Reader_cost = price(PC.Card_Reader);
							PC.OS_cost = price(PC.OS);
							PC.summ = (PC.CPU_cost + PC.motherboard_cost + PC.GPU_cost + PC.RAM_cost + PC.SSD_cost + PC.HDD_cost + PC.Power_Supply_cost + PC.coolers_cost + PC.Frame_cost + PC.Sound_Сard_cost + PC.Optical_Drive_cost + PC.Net_cost + PC.Card_Reader_cost + PC.OS_cost);
							//fclose(file);
						}
					}
					stop = 1;
					system("cls");

				}
			}

			if (menu == 21) //инструкиця
			{
				int button = 0;
				drawing_box(71, 35);
				gotoxy(25, 3);
				printf("Инструкция\n");
				gotoxy(3, 6);
				printf("1. Если Вы не выбрали процеcсор, Вы не сможете выбрать ");
				gotoxy(3, 7);
				printf("  материнскую плату, т.к не выбран сокет");
				gotoxy(3, 9);
				printf("2. Сумма считаеся автоматически");
				gotoxy(3, 11);
				printf("3. Место сохранения конфигурации предопределено");
				gotoxy(3, 13);
				printf("4. При смене процессора и сокета, выбранная ");
				gotoxy(3, 14);
				printf("  материнскую плата пропадает");
				gotoxy(3, 16);
				printf("5. Вы не можете сохранить конфигурацию, если ");
				gotoxy(3, 17);
				printf("  не выбраны все компоненты");
				gotoxy(3, 20);
				printf("Нажмте Enter, что бы вернуться к выбору компонентов");

				while (button != 13)
				{
					button = getch();
				}
				system("cls");
				stop = 1;

			}

			if (menu == 24) //пункт 5 в меню (выход)
			{
				system("cls");
				exit(EXIT_SUCCESS);
			}

		}
	}


}







