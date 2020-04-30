#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <queue>
#include <time.h>
#include <vector>

std::queue<int> queue;
std::queue<int> queueSetNum;
std::queue<int> luckNum;
int queueCount = 0;
int queueCountcpy = 0;
int queueX = 61;
int queueY = 21;
int insertNumber = 0;
int queueXcpy = 61;
int clearNumber = 97;

struct dataset {
	int setNum;
	int lucky;
};

void gotoxy(int x,int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void CursorView(char show)
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
}

int result() {
	system("cls");
	int countNum = 0;
	int specialNum = 0;
	int key;
	dataset datas;
	std::vector<dataset> data;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	gotoxy(83,9);
	printf("Winning Numbers\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	gotoxy(65,11);
	printf("���������������������������\n");
	gotoxy(65,12);
	printf("��                                                ��\n");
	gotoxy(65,13);
	printf("��                                                ��\n");
	gotoxy(65,14);
	printf("��                                                ��\n");
	gotoxy(65,15);
	printf("��                                                ��\n");
	gotoxy(65,16);
	printf("��                                                ��\n");
	gotoxy(65,17);
	printf("��                                                ��\n");
	gotoxy(65,18); 
	printf("��                                                ��\n");
	gotoxy(65,19);
	printf("��                                                ��\n");
	gotoxy(65,20);
	printf("��                                                ��\n");
	gotoxy(65,21);
	printf("���������������������������\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
	gotoxy(65,24);
	printf("First place : luckyNumber : 6");
	gotoxy(65,25);
	printf("Second place : luckyNumber : 5 & bonusNumber : 1");
	gotoxy(65,26);
	printf("Third place : luckyNumber : 5");
	gotoxy(65,27);
	printf("Fourth place : luckyNumber : 4");
	gotoxy(65,28);
	printf("Fifth place : luckyNumber : 3");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);

	gotoxy(11,7);
	printf("������������������������������������������������������������������������������������  \n");
	gotoxy(11,8);
	printf("��    ����    ����    ����    ����    ����    ����    ��    \n");
	gotoxy(11,9);
	printf("������������������������������������������������������������������������������������  \n");

	gotoxy(11,15);
	printf("������������������������������������������������������������������������������������  \n");
	gotoxy(11,16);
	printf("��    ����    ����    ����    ����    ����    ����    ��    \n");
	gotoxy(11,17);
	printf("������������������������������������������������������������������������������������  \n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	gotoxy(11,25);
	printf("input A key : ESC");

	for(int i =0; i<7; i++) {
		gotoxy(14+(i*6),8);
		printf("%d",queueSetNum.front());
		gotoxy(14+(i*6),16);
		printf("%d",luckNum.front());
		datas.setNum = queueSetNum.front();
		datas.lucky = luckNum.front();
		
		queueSetNum.pop();
		luckNum.pop();
		data.push_back(datas);
	}
	
	for(int i =0; i<7; i++) {
		for(int j =0; j<7; j++) {
			if((data[i].setNum == data[j].lucky) && i<=5){
				countNum++;
				data[j].lucky = 0;
			}
			else if((data[i].setNum == data[j].lucky) && i==6) {
				specialNum++;
				data[j].lucky = 0;
			}
		}
	}
	while(1) {
		if(countNum == 6) {
			gotoxy(65,11);
			printf("���������������������������\n");
			gotoxy(65,12);
			printf("��                                 �������   ��\n");
			gotoxy(65,13);
			printf("��          ��                     ��             ��\n");
			gotoxy(65,14);
			printf("��          ��                     �������   ��\n");
			gotoxy(65,15);
			printf("��          ��                                    ��\n");
			gotoxy(65,16);
			printf("��          ��                   ��������� ��\n");
			gotoxy(65,17);
			printf("��          ��                                    ��\n");
			gotoxy(65,18); 
			printf("��          ��                         ���       ��\n");
			gotoxy(65,19);
			printf("��          ��                       ��    ��     ��\n");
			gotoxy(65,20);
			printf("��                                     ���       ��\n");
			gotoxy(65,21);
			printf("���������������������������\n");
		}
		else if(countNum == 5 && specialNum == 1) {
			gotoxy(65,11);
			printf("���������������������������\n");
			gotoxy(65,12);
			printf("��     ������                  �������   ��\n");
			gotoxy(65,13);
			printf("��             ��                  ��             ��\n");
			gotoxy(65,14);
			printf("��             ��                  �������   ��\n");
			gotoxy(65,15);
			printf("��     ������                                 ��\n");
			gotoxy(65,16);
			printf("��     ��                        ��������� ��\n");
			gotoxy(65,17);
			printf("��     ��                                         ��\n");
			gotoxy(65,18); 
			printf("��     ������                      ���       ��\n");
			gotoxy(65,19);
			printf("��                                   ��    ��     ��\n");
			gotoxy(65,20);
			printf("��                                     ���       ��\n");
			gotoxy(65,21);
			printf("���������������������������\n");
		}
		else if(countNum == 5 &&specialNum == 0) {
			gotoxy(65,11);
			printf("���������������������������\n");
			gotoxy(65,12);
			printf("��     ������                  �������   ��\n");
			gotoxy(65,13);
			printf("��             ��                  ��             ��\n");
			gotoxy(65,14);
			printf("��             ��                  �������   ��\n");
			gotoxy(65,15);
			printf("��             ��                                 ��\n");
			gotoxy(65,16);
			printf("��     ������                ��������� ��\n");
			gotoxy(65,17);
			printf("��             ��                                 ��\n");
			gotoxy(65,18); 
			printf("��             ��                      ���       ��\n");
			gotoxy(65,19);
			printf("��     ������                    ��    ��     ��\n");
			gotoxy(65,20);
			printf("��                                     ���       ��\n");
			gotoxy(65,21);
			printf("���������������������������\n");			
		}
		else if(countNum == 4 & specialNum == 0) {
			gotoxy(65,11);
			printf("���������������������������\n");
			gotoxy(65,12);
			printf("��             ��                  �������   ��\n");
			gotoxy(65,13);
			printf("��           ���                  ��             ��\n");
			gotoxy(65,14);
			printf("��          �� ��                  �������   ��\n");
			gotoxy(65,15);
			printf("��         ��  ��                                 ��\n");
			gotoxy(65,16);
			printf("��        ��   ��                ��������� ��\n");
			gotoxy(65,17);
			printf("��       ��    ��                                 ��\n");
			gotoxy(65,18); 
			printf("��     ��������                  ���       ��\n");
			gotoxy(65,19);
			printf("��             ��                    ��    ��     ��\n");
			gotoxy(65,20);
			printf("��             ��                      ���       ��\n");
			gotoxy(65,21);
			printf("���������������������������\n");			
		}
		else if(countNum == 3 && specialNum == 0) {
			gotoxy(65,11);
			printf("���������������������������\n");
			gotoxy(65,12);
			printf("��         ��������          �������   ��\n");
			gotoxy(65,13);
			printf("��         ��                      ��             ��\n");
			gotoxy(65,14);
			printf("��         ��                      �������   ��\n");
			gotoxy(65,15);
			printf("��         ������                             ��\n");
			gotoxy(65,16);
			printf("��                  ��           ��������� ��\n");
			gotoxy(65,17);
			printf("��                    ��                          ��\n");
			gotoxy(65,18); 
			printf("��                    ��               ���       ��\n");
			gotoxy(65,19);
			printf("��         ��         ��             ��    ��     ��\n");
			gotoxy(65,20);
			printf("��          ������                 ���       ��\n");
			gotoxy(65,21);
			printf("���������������������������\n");			
		}
		else{
			gotoxy(65,11);
			printf("���������������������������\n");
			gotoxy(65,12);
			printf("��                                                ��\n");
			gotoxy(65,13);
			printf("��       �� �� �� �� �� �� ��         ��          ��\n");
			gotoxy(65,14);
			printf("��             ��          ��         ��          ��\n");
			gotoxy(65,15);
			printf("��             ��    ��    ��         ��          ��\n");
			gotoxy(65,16);
			printf("��                   ��               �����    ��\n");
			gotoxy(65,17);
			printf("��      �������������      ��          ��\n");
			gotoxy(65,18); 
			printf("��                                  ����        ��\n");
			gotoxy(65,19);
			printf("��                                 ��    ��       ��\n");
			gotoxy(65,20);
			printf("��                                  ����        ��\n");
			gotoxy(65,21);
			printf("���������������������������\n");			
		}
		
		if(kbhit()) {
			key = getch();
			
			switch(key) {
				case 97:
					exit(0);
			}
		}
	}
}

int Done() {
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	gotoxy(22,5);
	printf("your select number\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	gotoxy(11,7);
	printf("������������������������������������������������������������������������������������  \n");
	gotoxy(11,8);
	printf("��    ����    ����    ����    ����    ����    ����    ��    \n");
	gotoxy(11,9);
	printf("������������������������������������������������������������������������������������  \n");
	for(int i =0; i<7; i++) {
		gotoxy(14+(i*6),8);
		printf("%d",queue.front());
		queueSetNum.push(queue.front());
		queue.pop();
	}
	gotoxy(22,13);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	printf("Lucky Number");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	gotoxy(11,15);
	printf("������������������������������������������������������������������������������������  \n");
	gotoxy(11,16);
	printf("��    ����    ����    ����    ����    ����    ����    ��    \n");
	gotoxy(11,17);
	printf("������������������������������������������������������������������������������������  \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	gotoxy(11,25);
	printf("��start");
	gotoxy(11,26);
	printf("��exit");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	gotoxy(21,25);
	printf("��");
	
	int key;
	int selectY = 25;
	int selectX = 21;
	int selectYcpy = 25; 
	int startX = 14;
	
	while(1){
		if(kbhit()) {
			key = getch();			
			switch(key) {
				case 72:
					if(selectY <= 25) {
						break;
					}
					gotoxy(selectX,selectY);
					printf(" ");
					selectY = 25;
					gotoxy(selectX,selectY);
					printf("��\n");
					selectYcpy = selectY;
					break;
				case 80:
					if(selectY >=26) {
						break;
					}
					gotoxy(selectX,selectY);
					printf(" ");
					selectY = 26;
					gotoxy(selectX,selectY);
					printf("��\n");
					selectYcpy = selectY;				
					break;
				case 13:
					if(selectYcpy <= 25) {
						for(int i =0; i<7; i++) {
							srand(time(NULL));
							int random = rand()%45;	
							if(random == 0) random = 1;					
							gotoxy(startX+(i*6),16);
							printf("%d",random);	
							luckNum.push(random);
							sleep(3);							
						}
						result();
					}
					else if(selectYcpy >=26){
						exit(0);
					}
					gotoxy(10,25);
					break;
				default:
					break;
			}
		}
	}
}

int start() {
	
	int selectX = 13;
	int selectY = 8;
	int selectXcpy, selectYcpy,key;
	system("cls");
	gotoxy(11,2);
	printf("select lotto number\n");
	gotoxy(30,5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	printf("Lotto\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	gotoxy(11,7);
	printf("������������������������������������������������������������������������������������\n");
	gotoxy(11,8);
	printf("��  1 ����  2 ����  3 ����  4 ����  5 ����  6 ����  7 ��\n");
	gotoxy(11,9);
	printf("������������������������������������������������������������������������������������\n");
	
	gotoxy(11,10);
	printf("������������������������������������������������������������������������������������\n");
	gotoxy(11,11);
	printf("��  8 ����  9 ����  10����  11����  12����  13����  14��\n");
	gotoxy(11,12);
	printf("������������������������������������������������������������������������������������\n");
	
	gotoxy(11,13);
	printf("������������������������������������������������������������������������������������\n");
	gotoxy(11,14);
	printf("��  15����  16����  17����  18����  19����  20����  21��\n");
	gotoxy(11,15);
	printf("������������������������������������������������������������������������������������\n");
	
	gotoxy(11,16);
	printf("������������������������������������������������������������������������������������\n");
	gotoxy(11,17);
	printf("��  22����  23����  24����  25����  26����  27����  28��\n");
	gotoxy(11,18);
	printf("������������������������������������������������������������������������������������\n");
	
	gotoxy(11,19);
	printf("������������������������������������������������������������������������������������\n");
	gotoxy(11,20);
	printf("��  29����  30����  31����  32����  33����  34����  35��\n");
	gotoxy(11,21);
	printf("������������������������������������������������������������������������������������\n");
	
	gotoxy(11,22);
	printf("������������������������������������������������������������������������������������\n");
	gotoxy(11,23);
	printf("��  36����  37����  38����  39����  40����  41����  42��\n");
	gotoxy(11,24);
	printf("������������������������������������������������������������������������������������\n");
	
	gotoxy(11,25);
	printf("������������������������������������������������������������������������������������\n");
	gotoxy(11,26);
	printf("��  43����  44����  45����  DN����  DL����  CR����  EX��\n");
	gotoxy(11,27);
	printf("������������������������������������������������������������������������������������\n");
	
	gotoxy(11,28);
	printf(" DN : Done , DL : Delete , CR : Clear , EX : Exit\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	gotoxy(58,7);
	printf("1. cursor move\n");
	gotoxy(58,8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	printf("                      ����������\n");
	gotoxy(58,9);
	printf("                      �� �覢\n");
	gotoxy(58,10);
	printf("                  ��������������������������\n");
	gotoxy(58,11);
	printf("                  �� �禢 �馢 �榢\n");
	gotoxy(58,12);
	printf("                  ��������������������������\n");
	gotoxy(65,13);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("up : �� down : �� right :�� left: ��enter : select\n");
	gotoxy(58,15);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	printf("2. * : input enter, insert current position\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);	
		
	gotoxy(58,19);
	printf("your lotto number\n");
	gotoxy(58,20);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	
	printf("������������������������������������������������������������������������������������\n");
	gotoxy(58,21);
	printf("��    ����    ����    ����    ����    ����    ����    ��\n");
	gotoxy(58,22);
	printf("������������������������������������������������������������������������������������\n");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	gotoxy(selectX,selectY);
	printf("*");
	selectXcpy = selectX;
	selectYcpy = selectY;

	while(1) {
		gotoxy(selectXcpy,selectYcpy);
		printf("*");
		
		if(kbhit()) {
			key = getch();		
			switch(key) {
				case 72:  //up
					if(selectY >=11 && selectY <=26) {
						selectY = selectY - 3;
						gotoxy(selectXcpy,selectYcpy);
						printf(" ");
						gotoxy(selectX,selectY);
						printf("*");
						selectYcpy = selectY;
					}
					break;
				case 80:  //down
					if(selectY >=8 && selectY <=23) {
						selectY = selectY + 3;
						gotoxy(selectXcpy,selectYcpy);
						printf(" ");
						gotoxy(selectX,selectY);
						printf("*");
						selectYcpy = selectY;
					}
					break;
				case 75:  // left
				if(selectX >=19 && selectX <=49) {
						selectX = selectX - 6;
						gotoxy(selectXcpy,selectYcpy);
						printf(" ");
						gotoxy(selectX,selectY);
						printf("*");
						selectXcpy = selectX;
					}
					break;
				case 77:  // right
					if(selectX >=13 && selectX <=43) {
						selectX = selectX + 6;
						gotoxy(selectXcpy,selectYcpy);
						printf(" ");
						gotoxy(selectX,selectY);
						printf("*");
						selectXcpy = selectX;
					}
					break;
				case 13: // enter
					if((selectX >=8 && selectX <=49) && (selectY >=8 && selectY <=26)) {
						if((selectX >=31 && selectX <=49) && selectY ==26) {
							if(selectX == 31) { //done
								queueCountcpy = queueCount;
								if(queueCountcpy == 7) {
									Done();
								}
							}
							
							if(selectX == 37 && queueX >=61) { //delete
								gotoxy(queueXcpy-1,queueY);
								printf("   ");	
								if(queueX >=67) {
									queueX = queueX - 6;							
								}
								if(queueX <=61) {
									queueX = 61;
									queueXcpy = queueX;
								}
								queueXcpy = queueX;
								queue.pop();
								queueCount--;
								if(queueCount <0) {
									queueCount = 0;
								}
							}
							
							if(selectX == 43) { //clear
								for(int i =0; i<7; i++) {
									gotoxy(clearNumber-1,queueY);
									printf("   ");
									clearNumber = clearNumber - 6;
									queue.pop();
								}
							}
							
							if(selectX == 49) { //exit
								system("cls");
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
								printf("good bye");
								exit(0);
							}
						}
						else { //input
							gotoxy(queueX-1,queueY);
							printf("   ");						
							gotoxy(queueX,queueY);						
							printf("%d",((selectX/6)-1)+((selectY/3)-2)*7);
							insertNumber = ((selectX/6)-1)+(((selectY/3)-2)*7);
						
							if(queueCount < 7){
								queue.push(insertNumber);
								queueCount++;
							}
							else {
								queue.pop();
								queue.push(insertNumber);
							}
							if(queueX<=91) {
								queueX = queueX + 6;
								queueXcpy = queueX;
							}
							else {
								queueX = queueX;
							}
						}
						break;
					}
				default:
					break;
			}
		}
	}
}

int loading() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	system("cls");
	gotoxy(5,5);
	printf("��       ���       ��          ��      ��      �����    ����\n");
	gotoxy(5,6);
	printf("��      ��  ��     ���         ��              ��    ��    ��  ��\n");
	gotoxy(5,7);
	printf("��      ��  ��    ��  ��    ����      ��      ��    ��    ����\n");
	gotoxy(5,8);
	printf("��      ��  ��   �����   ��  ��      ��      ��    ��        ��\n");
	gotoxy(5,9);
	printf("����   ���   ��      ��  ����      ��      ��    ��    ����\n");
	
	gotoxy(5,13);
	printf("please wait 5 seconds\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	sleep(5);
	start();
}


int main() {
	CursorView(0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	printf("Seoil university computer application electronic apartment 202024510 LEESANGHOON\n");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	gotoxy(10,3);
	printf("�����������������������");
	gotoxy(10,4);
	printf("��                                        ��");
	gotoxy(15,4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("      select key : �� or  ��");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	gotoxy(10,5);
	printf("��                                        ��"); 
	gotoxy(10,6);
	printf("��     ��   ���  ����  ����  ���    ��\n");
	gotoxy(10,7);
	printf("��     ��  ��  ��   ��      ��   ��  ��   ��\n");
	gotoxy(10,8);
	printf("��     ��  ��  ��   ��      ��   ��  ��   ��\n");
	gotoxy(10,9);
	printf("��     ��  ��  ��   ��      ��   ��  ��   ��\n");
	gotoxy(10,10);
	printf("��     ��   ���    ��      ��    ���    ��\n");
	gotoxy(10,11);
	printf("��                                        ��");
	gotoxy(10,12);
	printf("�����������������������");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	gotoxy(10,15); 
	printf("��start\n");
	gotoxy(10,16);
	printf("��exit\n");
	
	gotoxy(20,15);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	printf("��\n");
	
	int selectX = 20;
	int selectY = 15;
	int selectYcpy;
	int key;
	
	while(1) {
		gotoxy(selectX,selectY);
		if(kbhit()) {
			key = getch();
		}
		
		switch(key) {	
			case 72:
				if(selectY <= 15) {
					break;
				}
				gotoxy(selectX,selectY);
				printf(" ");
				selectY = 15;
				gotoxy(selectX,selectY);
				printf("��\n");
				selectYcpy = selectY;
				break;
			case 80:
				if(selectY >=16) {
					break;
				}
				gotoxy(selectX,selectY);
				printf(" ");
				selectY = 16;
				gotoxy(selectX,selectY);
				printf("��\n");
				selectYcpy = selectY;				
				break;
			case 13:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				if(selectYcpy <= 15) {
					loading();
				}
				else if(selectYcpy >=16){
					return 0;
				}
				gotoxy(10,25);
				break;
			default :
				break;
		}
	}
}
