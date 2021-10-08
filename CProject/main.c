#include <stdio.h>
#include <stdlib.h>

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

void movePiece(char board[10][10], int player){
	int x1, y1, x2, y2;
	while(1){
		printf("choose piece (ex x, y) : ");
		
		scanf("%d, %d", &x1, &y1);
		if (player == 1){
			if (board[y1][x1]<='z' && 'a'<=board[y1][x1]){//선택한 말이 자신의 말일 때 
				break;
			}else{//자신의 말을 선택한 것이 아닐때 
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

int isEnemy(char board[10][10], int x, int y, player){ //좌표에 있는 말이 적의 말인지 판단 
	if ((player == 1?'A':'a')<=board[y][x]&&(player == 1?'Z':'z')>=board[y][x]){
		return 1;
	}
	return 0;
}

void whereCanGo(int board[10][10], char chessBoard[10][10], int x, int y, int player){
	
	switch(chessBoard[y][x] + (player==1?0:'A'-'a')){
		case 'k':
			if (chessBoard[y-1][x-1]=='.'||isEnemy(chessBoard[10][10], x-1, y-1, player)){
				board[y-1][x-1] = 1;
			}
			if (chessBoard[y][x-1]=='.'||isEnemy(chessBoard[10][10], x-1, y, player)){
				board[y][x-1] = 1;
			}
			if (chessBoard[y-1][x]=='.'||isEnemy(chessBoard[10][10], x, y-1, player)){
				board[y-1][x] = 1;
			}
			if (chessBoard[y+1][x-1]=='.'||isEnemy(chessBoard[10][10], x-1, y+1, player)){
				board[y+1][x-1] = 1;
			}
			if (chessBoard[y-1][x+1]=='.'||isEnemy(chessBoard[10][10], x+1, y-1, player)){
				board[y-1][x+1] = 1;
			}
			if (chessBoard[y+1][x]=='.'||isEnemy(chessBoard[10][10], x, y+1, player)){
				board[y+1][x] = 1;
			}
			if (chessBoard[y][x+1]=='.'||isEnemy(chessBoard[10][10], x+1, y, player)){
				board[y][x+1] = 1;
			}
			if (chessBoard[y+1][x+1]=='.'||isEnemy(chessBoard[10][10], x+1, y+1, player)){
				board[y+1][x+1] = 1;
			}
			break;
		case 'q'://여기부터 하면 됨 
		case 'p':
		case 'n':
		case 'b':
		case 'l':
	}
}

int main(void){
	char chessBoard[8][8] = { //board setting 
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
