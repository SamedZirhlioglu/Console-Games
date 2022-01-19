#include <stdio.h>
#include <conio.h>
#include <windows.h>

int player1[2][20];
int player2[2][20];
int p1 = 0;
int p2 = 0;

int turn = 1;
int i, j;
int color, index;


int negativeColor()
{
	if(color == 0) return 1;
	else return 0;
}

void changeColor(char color)
{
	switch(color)
	{
		case 'R':
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			break;
		}
		case 'G':
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			break;
		}
		case 'B':
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			break;
		}
		default:
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			break;
		}
	}
}

void printTables()
{
	system("CLS");
	/*PLAYER1's TABLE*/
	{
		changeColor('G');
		printf("PLAYER 1's TABLE\n");
		for(i = 0; i < 2; i++)
		{
			if(i == 0) changeColor('B');
			else changeColor('R');
			
			for(j = 0; j < 20; j++)
			{
				printf("%d", player1[i][j]);
				if(j < 19) printf(" | ");
			}
			printf("\n");
		}
		printf("\n\n\n");
	}
	
	/*PLAYER2's TABLE*/
	{
		changeColor('G');
		printf("PLAYER 2's TABLE\n");
		for(i = 0; i < 2; i++)
		{
			if(i == 0) changeColor('B');
			else changeColor('R');
			
			for(j = 0; j < 20; j++)
			{
				printf("%d", player2[i][j]);
				if(j < 19) printf(" | ");
			}
			printf("\n");
		}
		printf("\n\n\n");
	}
	changeColor('A');
}

int inputColor()
{
	char input = '0';
	
	changeColor('G');
	printf("Which color would you like to give?\n");
	
	changeColor('B');
	printf("'1' for Blue\n");
	
	changeColor('R');
	printf("'2' for Red\n");
	
	while(input == '0')
	{
		input = getch();
		
		if(input == '1') return 0;
		else if(input == '2') return 1;
		else input = '0';
	}
}

int inputIndex(int maxIndex)
{
	int index = -1;
	
	changeColor('G');
	printf("Which index would you like to give?(0 - %d)\n", maxIndex - 1);
	
	changeColor('A');
	while(index == -1)
	{
		scanf("%d", &index);
		
		if(0 <= index && index < maxIndex) return index;
		else index = -1;
	}
}

void give(int clr, int indx)
{
	if(turn == 1)
	{
		player1[clr][indx]--;
		player2[clr][indx]++;
		
		p1++;
		turn = 2;
	}
	else if(turn == 2)
	{
		player1[clr][indx]++;
		player2[clr][indx]--;
		
		p2++;
		turn = 1;
	}
	
	color = clr;
	index = indx;
}

int possibleMoves()
{
	int mv1, mv2;
	
	int newIndex;
	if(index == 0) newIndex = 1;
	else newIndex = index * 2;
	
		
	if(newIndex >= 20) mv1 = 0;
	else mv1 = 1;
	
	if(index - 4 < 0) mv2 = 0;
	else mv2 = 1;
	
	if(mv1 == 0 && mv2 == 0) return 0;
	else if(mv1 == 0 && mv2 == 1) return 2;
	else if(mv1 == 1 && mv2 == 0) return 1;
	else if(mv1 == 1 && mv2 == 1) return 3;
}

void firstMove()
{
	changeColor('G');
	printf("TURN: PLAYER1\n\n");
	
	color = inputColor();
	index = inputIndex(10);
	
	give(color, index);
	changeColor('A');
}

int nextMove(int possibleMove)
{
	int moves[2] = { 0 };
	char move = '0';
	
	int newIndex;
	if(index == 0) newIndex = 1;
	else newIndex = index * 2;
	
	if(possibleMove == 1 || possibleMove == 3)
	{
		if(turn == 1)
		{
			if(player1[color][newIndex] > 0) moves[0] = 1;
		}
		else if(turn == 2)
		{
			if(player2[color][newIndex] > 0) moves[0] = 1;
		}
	}
	if(possibleMove == 2 || possibleMove == 3)
	{
		if(turn == 1)
		{
			if(player1[negativeColor()][index - 4] > 0) moves[1] = 1;
		}
		else if(turn == 2)
		{
			if(player2[negativeColor()][index - 4] > 0) moves[1] = 1;
		}
	}
	
	changeColor('G');
	
	if(turn == 1)
	{
		if(color == 0) printf("\n\nPLAYER 2's MOVE\nBLUE-%d", index);
		else printf("\n\nPLAYER 2's MOVE\nRED-%d", index);
	}
	else if(turn == 2)
	{
		if(color == 0) printf("\n\nPLAYER 1's MOVE\nBLUE-%d", index);
		else printf("\n\nPLAYER 1's MOVE\nRED-%d", index);
	}
	
	changeColor('A');
	printf("\n\n\nTURN: PLAYER%d\n\n", turn);
	
	if(moves[0] == 1)
	{
		int newIndex;
		if(index == 0) newIndex = 1;
		else newIndex = index * 2;
		
		if(color == 0) printf("'1' for BLUE-%d\n", newIndex);
		else printf("'1' for RED-%d\n", newIndex);
	}
	if(moves[1] == 1)
	{
		if(color == 0) printf("'2' for RED-%d\n", index - 4);
		else printf("'2' for BLUE-%d\n", index - 4);
	}
	
	
	if(moves[0] == 0 && moves[1] == 0) return 0;
	
	if(turn == 2)
	{
		if(moves[0] == 1) return 1;
		else if(moves[1] == 1) return 2;
		else return 0;
	}
	
	printf("These are the move(s) you can make. Choose one: ");
	
	while(move == '0')
	{
		move = getch();
		if(moves[0] == 1 && move == '1') return 1;
		else if(moves[1] == 1 && move == '2') return 2;
		else move = '0';
	}
}

void gameOver()
{
	system("CLS");
	changeColor('A');
	
	printf("P1: %d\nP2: %d", p1, p2);
	printf("\n\nLoser: PLAYER%d", turn);
}

void playGame()
{
	printTables();
	firstMove();
	
	int possibleMove = possibleMoves();
	int move;
	
	while(possibleMove > 0)
	{
		printTables();
		move = nextMove(possibleMove);
		if(move == 0) break;
		if(move == 1)
		{
			int newIndex;
			if(index == 0) newIndex = 1;
			else newIndex = index * 2;
			
			give(color, newIndex);
		}
		else if(move == 2)
		{
			give(negativeColor(), index - 4);
		}
		possibleMove = possibleMoves();
	}
	gameOver();
}

int main()
{
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 20; j++)
		{
			player1[i][j] = 1;
			player2[i][j] = 1;
		}
	}
	playGame();
}
