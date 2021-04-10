#include "mazee.h"

void TextColorChange(int);
void GotoXY(int, int);
void DrawMap(int, int);
void RunGame(int, int);
int Checker(int, int);

int main(int argc, char* argv[]) {

	int circlePosX = 4, circlePosY = 3;

	DrawMap(circlePosX, circlePosY);

	RunGame(circlePosX, circlePosY);

	//system("cls");
	GotoXY(15, 21);
	printf("Clear!");
	return 0;
}

void TextColorChange(int colorNumber) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNumber);


}

void GotoXY(int x, int y) {
	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void DrawMap(int circlePosX, int circlePosY) {
	
	system("mode con cols=37 lines=27");

	int idx = 0, idy = 0;

	GotoXY(0, 2);
	for (idx = 0; idx < HEIGHT; idx++) {
		for (idy = 0; idy < WIDTH; idy++) {

			switch (map[idx][idy]) {
			case 0:
				printf("  "); //공백 두개
				break;
			case 1:
				TextColorChange(8);
				printf("■");
				break;
			case 2:
				TextColorChange(12);
				printf("★");
				break;
			}
		}
		printf("\n");
	}

	GotoXY(circlePosX, circlePosY + 2);
	TextColorChange(14);
	printf("●");
}

int Checker(int x, int y) {
	switch (map[y][x]) {

	case 0:
		return 1;
		break;
	case 2:
		return 2;
		break;
	default:
		return 0;
		break;
	}
}

void RunGame(int circlePosX, int circlePosY) {
	int cmd = 0;
	int ext = true;

	while (1) {

		TextColorChange(14);

		cmd = _getch();
		int chk;

		switch (cmd) {
		case UP:
			GotoXY(circlePosX, circlePosY + 2);
			printf("  ");
			if (ext == false) {
				return;
			}
			circlePosY = circlePosY - 1;
			chk = Checker(circlePosX, circlePosY);
			if (0 == chk) {
				circlePosY = circlePosY + 1;
			}
			else if (2 == chk) { //star
				ext = false;
			}
			break;
		case DOWN:
			GotoXY(circlePosX, circlePosY + 2);
			printf("  ");
			if (ext == false) {
				return;
			}
			circlePosY = circlePosY + 1;
			chk = Checker(circlePosX, circlePosY);
			if (0 == chk) {
				circlePosY = circlePosY - 1;
			}
			else if (2 == chk) {
				ext = false;
			}
			break;
		case LEFT:
			GotoXY(circlePosX, circlePosY + 2);
			printf("  ");
			if (ext == false) {
				return;
			}
			circlePosX = circlePosX - 2;
			chk = Checker(circlePosX, circlePosY);
			if (0 == chk) {
				circlePosX = circlePosX + 2;
			}
			else if (2 == chk) {
				ext = false;
			}
			break;
		case RIGHT:
			GotoXY(circlePosX, circlePosY + 2);
			printf("  ");
			if (ext == false) {
				return;
			}
			circlePosX = circlePosX + 2;
			chk = Checker(circlePosX, circlePosY);
			if (0 == chk) {
				circlePosX = circlePosX - 2;
			}
			else if (2 == chk) {
				ext = false;
			}
			break;
		case EXIT:
			return;
		}

		GotoXY(circlePosX, circlePosY + 2);
		printf("●");
	}
}