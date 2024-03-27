#include <stdlib.h>
#include <stdio.h>

#define COL_KING 4
#define COL_QUEEN 3
#define COL_ROOK 0
#define COL_KNIGHT 1
#define COL_BISHOP 2
#define ALL_CHESSPIECES 32
#define COLS_CB 8
#define ROWS_CB 8

int cb[8][8];
int p;

void put_piece(int chessboard[][8], int piece, int side)
{
	if(chessboard[side][piece] == 0)
		chessboard[side][piece] = 1;
	else
		chessboard[side][7-piece] = 1;

}

void checkpiece(int chessboard[][8], char litera_piesa, int side)
{
	if (litera_piesa == 'k')
				chessboard[side][COL_KING] = 1;
			else if (litera_piesa == 'q')
				chessboard[side][COL_QUEEN] = 1;
			else if (litera_piesa == 'r')
				put_piece(cb, COL_ROOK, side);
			else if (litera_piesa == 'n')
				put_piece(cb, COL_KNIGHT, side);
			else if (litera_piesa == 'b')
				put_piece(cb, COL_BISHOP, side);

			else
			{	
				//setam linia de pion in functie de culoare
				if(side == 0) //daca e white
					side = 1;
				else if(side == 7) //daca e black
					side = 6;
				p = 0; 
				while (chessboard[side][p] != 0)
					p++;
				chessboard[side][p] = 1;
			}

}

int main()
{
	//initializam tabla de sah
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cb[i][j] = 0;
		}
	}

	char piece[3];
	for (int i = 0; i < ALL_CHESSPIECES; i++)
	{
		scanf("%s", piece);

		if (piece[1] == 'w')
		{
			checkpiece(cb, piece[0], 0);
		}
		else if (piece[1] == 'b')
		{
			checkpiece(cb, piece[0], 7);
		}
	}

	//afisam tabla de sah
	for (int i = ROWS_CB-1; i >= 0; i--)
	{
		for (int j = 0; j < COLS_CB; j++)
		{
			printf("%d", cb[i][j]);
		}
		printf("\n");
	}
	return 0;
}
