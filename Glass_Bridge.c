#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*
" " - Normal Cam
"K" - Kýrýlabilir Cam
"X" - Kýrýk Cam
"A" - A Karakteri
"B" - B Karakteri
"C" - C Karakteri
"a" - Ölen A Karakteri
"b" - Ölen B Karakteri
"c" - Ölen C Karakteri
*/
/*
00 = Black
01 = Dark Blue
02 = Dark Green
03 = Dark Aqua / Cyan
04 = Dark Red
05 = Dark Purple / Pink / Magenta
06 = Dark Yellow
07 = Dark White
08 = Gray
09 = Blue
10 = Green
11 = Aqua / Cyan
12 = Red
13 = Purple / Pink / Magenta
14 = Yellow
15 = White
*/

// Kalan Can
int A = 3;
int B = 3;
int C = 3;

char winner = ' ';
int iteration = 0;
int find_i, find_j;

void set_color(char color)
{
	int color_code = 15;
	
	if(color == 'A') color_code = 4;
	else if(color == 'a') color_code = 12;
	else if(color == 'B') color_code = 2;
	else if(color == 'b') color_code = 10;
	else if(color == 'C') color_code = 1;
	else if(color == 'c') color_code = 9;
	else if(color == 'K') color_code = 6;
	else if(color == 'X') color_code = 8;
	else if(color == 'i') color_code = 14;
	else if(color == ' ') color_code = 15;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_code);
}

void print(char line[], char color)
{
	set_color(color);
	printf(line);
	set_color(' ');
}

void printc(char line[], char ch, char color)
{
	set_color(color);
	printf(line, ch);
	set_color(' ');
}

void printd(char line[], int num, char color)
{
	set_color(color);
	printf(line, num);
	set_color(' ');
}

// Harita
char map[4][10] =
{
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
};

// Rastgele integer üreten fonksiyon
int random_integer(int min, int max)
{
	int diff = max - min;
	int generated = rand() % diff;
	return generated + min;
}

// Haritadaki kýrýlabilir camlarý rastgele olarak belirleyen fonksiyon
void fill_random_map()
{
	int i;
	for(i = 0; i < 10; i++)
	{
		int r = random_integer(0, 4);
		map[r][i] = 'K';
	}
}

void print_map()
{
	int i, j;
	printd("\nIteration: %d", iteration, 'i');
	printf("\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
	for(i = 0; i < 4; i++)
	{
		printf("¯¯ ");
		for(j = 0; j < 10; j++)
		{
			printc("|%c| ", map[i][j], map[i][j]);
		}
		printf("¯¯\n");
	}
	printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\nHealth A: %d\nHealth B: %d\nHealth C: %d\n", A, B, C);
	
}

void find_character(char character)
{
	int finded = 0, i, j;
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 10; j++)
		{
			if(map[i][j] == character)
			{
				find_i = i;
				find_j = j;
				finded = 1;
				break;
			}
		}
		if(finded == 1) break;
	}
	if(finded == 0)
	{
		find_i = -1;
		find_j = -1;
	}
}

int control_continues()
{
	int i;
	
	if(A == 0 && B == 0) winner = 'C';
	else if(A == 0 && C == 0) winner = 'B';
	else if(B == 0 && C == 0) winner = 'A';
	else
	{
		for(i = 0; i < 4; i++)
		{
			if(map[i][9] == 'A')
			{
				winner = 'A';
				break;
			}
			else if(map[i][9] == 'B')
			{
				winner = 'B';
				break;
			}
			else if(map[i][9] == 'C')
			{
				winner = 'C';
				break;
			}
		}
	}
	
	if(winner == ' ') return 1;
	else return 0;
}

void move_character(char character, char small_character)
{
	switch(character)
	{
		case 'A': {
			if(A == 0) return;
			break;
		}
		case 'B': {
			if(B == 0) return;
			break;
		}
		case 'C': {
			if(C == 0) return;
			break;
		}
		default: {
			break;
		}
	}
	find_character(character);
	int next_i = random_integer(0, 4);
	int next_j = find_j + 1;
	
	while(map[next_i][next_j] != ' ' && map[next_i][next_j] != 'K')
	{
		next_i = random_integer(0, 4);
	}
	
	if(map[next_i][next_j] == ' ') map[next_i][next_j] = character;
	else if(map[next_i][next_j] == 'K') map[next_i][next_j] = small_character;
	
	if(find_i == -1 && find_j == -1);
	else
	{
		map[find_i][find_j] = ' ';
	}
}

void fall_manager_health()
{
	find_character('a');
	if(find_i != -1 && find_j != -1) A--;
	
	find_character('b');
	if(find_i != -1 && find_j != -1) B--;
	
	find_character('c');
	if(find_i != -1 && find_j != -1) C--;
}

void fall_manager()
{
	find_character('a');
	map[find_i][find_j] = 'X';
	
	find_character('b');
	map[find_i][find_j] = 'X';
	
	find_character('c');
	map[find_i][find_j] = 'X';
}

void game_over()
{
	printf("\n\n\n\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");
	printc("\nGAME OVER! Winner: %c", winner, 'i');
	iteration--;
	print_map();
	printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
	system("pause");
}

void game_manager()
{
	int game_continues = 1;
	system("cls");
	print_map();
	
	while(game_continues == 1)
	{
		move_character('A', 'a');
		if(iteration == 0);
		else if(iteration == 1) move_character('B', 'b');
		else
		{
			move_character('B', 'b');
			move_character('C', 'c');
		}
		fall_manager_health();
		print_map();
		printf("\n");
		system("pause");
		printf("\n\n\n");
		fall_manager();
		game_continues = control_continues();
		iteration++;
	}
	
	game_over();
}

int main()
{    
	srand(time(NULL));
	fill_random_map();
	print("Welcome to the game!\n", 'i');
	print("A ", 'A');
	print("B ", 'B');
	print("C ", 'C');
	print("characters will be play automaticly.\n", 'i');
	system("pause");
	
	game_manager();
}
