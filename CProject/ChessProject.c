#include <stdio.h>
#include <stdlib.h>
#define mapx 8
#define mapy 8

//brief : return where it can move
//parameter : board(for return), chessBoard, choosed piece's x and y, player
//return : none
void whereCanGo(int board[mapy][mapx], char chessBoard[mapy][mapx], int x, int y, int player);

//bried : Returns whether (x, y) is included in the map.
//parameter : x, y
//return : is inluded in the map -> 1 
// not -> 0 
int isInMap(x, y) {
	if (0<=x && x<mapx && 0<=y && y<mapy)
		return 1;
	else 
		return 0;
}

//brief : print chess board by text graphic
//parameter : board list
//return : none
void printBoard(char board[mapy][mapx], int player){
	printf("____________________________________\n");
	int i, j;
	if (player)
		printf("lower turn\n");
	else 
		printf("upper turn\n");
	printf("   0 1 2 3 4 5 6 7\n\n");
	for (i=0; i<mapx; i++){
		printf("%d  ", i);
		for (j=0; j<mapy; j++){
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

//brief : move piece event
//parameter : board list, player int (1 or 0)
//return : none
void movePiece(char board[mapy][mapx], int player){
	int x1, y1, x2, y2;
	while(1){
		printf("choose piece (ex x, y) : ");
		
		scanf("%d, %d", &x1, &y1);
		if (player){
			if (board[y1][x1]<='z' && 'a'<=board[y1][x1]){//선택한 말이 자신의 말일 때 
				break;
			}else{//자신의 말을 선택한 것이 아닐때 
				printf("try again\n"); 
			}
		} else {
			if (board[y1][x1]<='Z' && 'A'<=board[y1][x1]){
				break;
			}else{
				printf("try again\n"); 
			}
		}	
	}
	
	int boardAboutMove[mapy][mapx] = {0,};
	whereCanGo(boardAboutMove, board, x1, y1, player);
	
	while(1){
		printf("choose where to move (ex x, y) : ");
		
		scanf("%d, %d", &x2, &y2);
		if (boardAboutMove[y2][x2]==1){
			board[y2][x2] = board[y1][x1];
			board[y1][x1] = '.';
			break;
		}
		printf("try again\n");
		
	} 
}

//brief : test this piece is enemy piece
//parameter : board, choosed block's x and y, player(int 1 or 2)
//return : boolean enemy -> 1, not enemy -> 0
int isEnemy(char board[mapy][mapx], int x, int y, int player){
	if ((player == 1?'A':'a')<=board[y][x]&&(player == 1?'Z':'z')>=board[y][x]){
		return 1;
	}
	return 0;
}

//brief : return where it can move
//parameter : board(for return), chessBoard, choosed piece's x and y, player
//return : none
void whereCanGo(int board[mapy][mapx], char chessBoard[mapy][mapx], int x, int y, int player){
	int i;
	int direction;
	switch(chessBoard[y][x] + (player==1?0:'a'-'A')){
		case 'k':
			if (chessBoard[y-1][x-1]=='.'){
				board[y-1][x-1] = 1;
			} else if (isEnemy(chessBoard, x-1, y-1, player))
				board[y-1][x-1] = 2;
				
			if (chessBoard[y][x-1]=='.'){
				board[y][x-1] = 1;
			} else if (isEnemy(chessBoard, x-1, y, player))
				board[y][x-1] = 2;
				
			if (chessBoard[y-1][x]=='.'){
				board[y-1][x] = 1;
			} else if (isEnemy(chessBoard, x, y-1, player))
				board[y-1][x] = 2;
				
			if (chessBoard[y+1][x-1]=='.'){
				board[y+1][x-1] = 1;
			} else if (isEnemy(chessBoard, x-1, y+1, player))
				board[y+1][x-1] = 2;
				
			if (chessBoard[y-1][x+1]=='.'){
				board[y-1][x+1] = 1;
			} else if (isEnemy(chessBoard, x+1, y-1, player))
				board[y-1][x+1]=2;
				
			if (chessBoard[y+1][x]=='.'){
				board[y+1][x] = 1;
			} else if (isEnemy(chessBoard, x, y+1, player))
				board[y+1][x] = 2;
				
			if (chessBoard[y][x+1]=='.'){
				board[y][x+1] = 1;
			} else if (isEnemy(chessBoard, x+1, y, player))
				board[y][x+1] = 2;
				
			if (chessBoard[y+1][x+1]=='.'){
				board[y+1][x+1] = 1;
			} else if (isEnemy(chessBoard, x+1, y+1, player))
				board[y+1][x+1];
			break;
			
		case 'q':
			for (i=1; x+i<8; i++) {
				if (chessBoard[y][x+i]=='.'||isEnemy(chessBoard, x+i, y, player)){
					board[y][x+i]=1;
					break;
				}
			}
			for (i=1; x+i<8 && y+i<8; i++) {
				if (chessBoard[y+i][x+i]=='.'||isEnemy(chessBoard, x+i, y+i, player)){
					board[y+i][x+i]=1;
					break;
				}
			}
			for (i=1; y+i<8; i++) {
				if (chessBoard[y+i][x]=='.'||isEnemy(chessBoard, x, y+i, player)){
					board[y+i][x]=1;
					break;
				}
			}
			for (i=1; y+i<8 && x-i>=0; i++) {
				if (chessBoard[y+i][x-i]=='.'||isEnemy(chessBoard, x-i, y+i, player)){
					board[y+i][x-i]=1;
					break;
				}
			}
			for (i=1; x-i>=0; i++) {
				if (chessBoard[y][x-i]=='.'||isEnemy(chessBoard, x-i, y, player)){
					board[y][x-i]=1;
					break;
				}
			}
			for (i=1; x-i>=0 && y-i>=0; i++) {
				if (chessBoard[y-i][x-i]=='.'||isEnemy(chessBoard, x-i, y-i, player)){
					board[y-i][x-i]=1;
					break;
				}
			}
			for (i=1; y-i>=0; i++) {
				if (chessBoard[y-i][x]=='.'||isEnemy(chessBoard, x, y-i, player)){
					board[y-i][x]=1;
					break;
				}
			}
			for (i=1; y-i>=0 && x+i<8; i++) {
				if (chessBoard[y-i][x+i]=='.'||isEnemy(chessBoard, x+i, y-i, player)){
					board[y-i][x+i]=1;
					break;
				}
			}
			break;
		case 'p':
			if (player)
				direction = -1;
			else 
				direction = 1;
			if (chessBoard[y+direction][x] == '.')
				board[y+direction][x] = 1;
			if (isEnemy(chessBoard, x+1, y+direction, player))
				board[y+direction][x+1] = 1;
			if (isEnemy(chessBoard, x-1, y+direction, player))
			break;
		case 'n':
			if (chessBoard[y+2][x+1] == '.' ||isEnemy(chessBoard, x+1, y+2, player))
				board[y+2][x+1]=1;
			if (chessBoard[y+1][x+2] == '.' || isEnemy(chessBoard,x+2, y+1, player))
				board[y+1][x+2]=1;
			if (chessBoard[y-2][x+1] == '.' ||isEnemy(chessBoard, x+1, y-2, player))
				board[y-2][x+1]=1;
			if (chessBoard[y-1][x+2] == '.' || isEnemy(chessBoard,x+2, y-1, player))
				board[y-1][x+2]=1;
			if (chessBoard[y+2][x-1] == '.' ||isEnemy(chessBoard, x-1, y+2, player))
				board[y+2][x+1]=1;
			if (chessBoard[y+1][x-2] == '.' || isEnemy(chessBoard,x-2, y+1, player))
				board[y+1][x-2]=1;
			if (chessBoard[y-2][x-1] == '.' ||isEnemy(chessBoard, x-1, y-2, player))
				board[y-2][x-1]=1;
			if (chessBoard[y-1][x-2] == '.' || isEnemy(chessBoard,x-2, y-1, player))
				board[y-1][x-2]=1;
			break;
		case 'b':
			for (i=1; x+i<8 && y+i<8; i++) {
				if (chessBoard[y+i][x+i]=='.'||isEnemy(chessBoard, x+i, y+i, player)){
					board[y+i][x+i]=1;
					break;
				}
			}
			for (i=1; y+i<8 && x-i>=0; i++) {
				if (chessBoard[y+i][x-i]=='.'||isEnemy(chessBoard, x-i, y+i, player)){
					board[y+i][x-i]=1;
					break;
				}
			}
			for (i=1; x-i>=0 && y-i>=0; i++) {
				if (chessBoard[y-i][x-i]=='.'||isEnemy(chessBoard, x-i, y-i, player)){
					board[y-i][x-i]=1;
					break;
				}
			}
			for (i=1; y-i>=0 && x+i<8; i++) {
				if (chessBoard[y-i][x+i]=='.'||isEnemy(chessBoard, x+i, y-i, player)){
					board[y-i][x+i]=1;
					break;
				}
			}
			break;
		case 'l':
			for (i=1; x+i<8; i++) {
				if (chessBoard[y][x+i]=='.'||isEnemy(chessBoard, x+i, y, player)){
					board[y][x+i]=1;
					break;
				}
			}
			for (i=1; y+i<8; i++) {
				if (chessBoard[y+i][x]=='.'||isEnemy(chessBoard, x, y+i, player)){
					board[y+i][x]=1;
					break;
				}
			}
			for (i=1; x-i>=0; i++) {
				if (chessBoard[y][x-i]=='.'||isEnemy(chessBoard, x-i, y, player)){
					board[y][x-i]=1;
					break;
				}
			}
			for (i=1; y-i>=0; i++) {
				if (chessBoard[y-i][x]=='.'||isEnemy(chessBoard, x, y-i, player)){
					board[y-i][x]=1;
					break;
				}
			}
			break;
	}
}

// Brief : check winner
// parameter : chess board, winner (output parameter)
// return : is winner -> 1, no winner -> 0 
int checkWinner(char Board[mapy][mapx], int * winner){
	int UC=0, LC=0, i, j;
	for (i=0; i<mapx; i++) {
		for (j=0; j<mapx; j++) {
			if (Board[j][i] == 'k')
				LC = 1;
			else if (Board[j][i] == 'K')
				UC = 1;
		}
	}
	if (LC && UC) 
		return 0;
	else if (LC) 
		*winner = 1;
	else if (UC)
		*winner = 0; 
	
	return 1;
}

void test

void makeDecision(char chessBoard[mapy][mapx], int player) {
	player = 0;
	
	
}

int main(void){
	char chessBoard[mapy][mapx] = {
		{'L', 'N', 'B', 'Q', 'K', 'B', 'N', 'L'}, // player = 0
		{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'}, // player = 1
		{'l', 'n', 'b', 'q', 'k', 'b', 'n', 'l'},
	};
	int player=0;
	int winner;
	while (1){
		player++;	
		printBoard(chessBoard, player%2);
		if (checkWinner(chessBoard, &winner))
			break;
		movePiece(chessBoard, player%2);	
	}
	printf("%s win\n", (winner?"lower":"upper"));
}
