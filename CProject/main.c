#include <stdio.h>
#include <stdlib.h>


//brief : return where it can move
//parameter : board(for return), chessBoard, choosed piece's x and y, player
//return : none
void whereCanGo(int board[10][10], char chessBoard[10][10], int x, int y, int player);

//brief : print chess board by text graphic
//parameter : board list
//return : none
void printBoard(char board[10][10]){
	printf("____________________________________\n");
	int i, j;
	for (i=0; i<10; i++){
		for (j=0; j<10; j++){
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

//brief : move piece event
//parameter : board list, player int (1 or 2)
//return : none
void movePiece(char board[10][10], int player){
	int x1, y1, x2, y2;
	while(1){
		printf("choose piece (ex x, y) : ");
		
		scanf("%d, %d", &x1, &y1);
		if (player == 1){
			if (board[y1][x1]<='z' && 'a'<=board[y1][x1]){//������ ���� �ڽ��� ���� �� 
				break;
			}else{//�ڽ��� ���� ������ ���� �ƴҶ� 
				printf("try again\n"); 
			}
		} else if (player == 2){
			if (board[y1][x1]<='Z' && 'A'<=board[y1][x1]){
				break;
			}else{
				printf("try again\n"); 
			}
		}	
	}
	
	int boardAboutMove[10][10] = {0,};
	whereCanGo(boardAboutMove, board, x1, y1, player);
	
	while(1){
		printf("choose where to move (ex x, y) : ");
		
		scanf("%d, %d", &x2, &y2);
		if (boardAboutMove[y2][x2]==1){
			break;
		}
		
	} 
}

//brief : test this piece is enemy piece
//parameter : board, choosed block's x and y, player(int 1 or 2)
//return : boolean enemy -> 1, not enemy -> 0
int isEnemy(char board[10][10], int x, int y, int player){
	if ((player == 1?'A':'a')<=board[y][x]&&(player == 1?'Z':'z')>=board[y][x]){
		return 1;
	}
	return 0;
}

//brief : return where it can move
//parameter : board(for return), chessBoard, choosed piece's x and y, player
//return : none
void whereCanGo(int board[10][10], char chessBoard[10][10], int x, int y, int player){
	
	switch(chessBoard[y][x] + (player==1?0:'A'-'a')){
		case 'k':
			if (chessBoard[y-1][x-1]=='.'||isEnemy(chessBoard, x-1, y-1, player)){
				board[y-1][x-1] = 1;
			}
			if (chessBoard[y][x-1]=='.'||isEnemy(chessBoard, x-1, y, player)){
				board[y][x-1] = 1;
			}
			if (chessBoard[y-1][x]=='.'||isEnemy(chessBoard, x, y-1, player)){
				board[y-1][x] = 1;
			}
			if (chessBoard[y+1][x-1]=='.'||isEnemy(chessBoard, x-1, y+1, player)){
				board[y+1][x-1] = 1;
			}
			if (chessBoard[y-1][x+1]=='.'||isEnemy(chessBoard, x+1, y-1, player)){
				board[y-1][x+1] = 1;
			}
			if (chessBoard[y+1][x]=='.'||isEnemy(chessBoard, x, y+1, player)){
				board[y+1][x] = 1;
			}
			if (chessBoard[y][x+1]=='.'||isEnemy(chessBoard, x+1, y, player)){
				board[y][x+1] = 1;
			}
			if (chessBoard[y+1][x+1]=='.'||isEnemy(chessBoard, x+1, y+1, player)){
				board[y+1][x+1] = 1;
			}
			break;
		case 'q'://������� �ϸ� �� 
		case 'p':
		case 'n':
		case 'b':
		case 'l':
			break;
	}
}

int main(void){
	char chessBoard[10][10] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', 'L', 'N', 'B', 'Q', 'K', 'B', 'N', 'L', ' '},
		{' ', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', ' '},
		{' ', '.', '.', '.', '.', '.', '.', '.', '.', ' '},
		{' ', '.', '.', '.', '.', '.', '.', '.', '.', ' '},
		{' ', '.', '.', '.', '.', '.', '.', '.', '.', ' '},
		{' ', '.', '.', '.', '.', '.', '.', '.', '.', ' '},
		{' ', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p', ' '},
		{' ', 'l', 'n', 'b', 'q', 'k', 'b', 'n', 'l', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
	};
	printBoard(chessBoard);
	movePiece(chessBoard, 1);
}
