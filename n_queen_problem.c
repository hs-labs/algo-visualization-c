#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
typedef struct chess{
	int chess_board_size;
	int chess_board[20][20];
	int queens_locations[20];
	int total;
	int recurstion;
	int backTrack;
} Chess;

void initializeArray(Chess *);
void initializeQueenArray(Chess *chess);
int checkChessBoard(Chess *,int,int);
void printChessBoardAns(Chess *chess,int);
void placeQueens(Chess *,int);
void waitShort();
void waitLong();
void placeQueens(Chess *chess,int current_column);
void waitShortShort();

void initializeArray(Chess *chess){
	for (int i = 0;i< chess->chess_board_size;i++){
		for(int j = 0;j<chess->chess_board_size;j++){
			chess->chess_board[i][j] = 0;
		}
	}
}
void initializeQueenArray(Chess *chess){
	for(int i = 0;i<chess->chess_board_size;i++){
		chess->queens_locations[i] = -1;
	}
}

int checkChessBoard(Chess *chess,int current_column,int flag){
	int tempi = chess->queens_locations[current_column];
	int tempj = current_column;
	for(int i = tempj - 1;i>=0;i--){
		if(chess->queens_locations[i] == tempi){
			if(flag)printf("\n\n\n\n\n WOKED 1\n\n\n\n\n");
			return 0;
		}
	}
	while(1){
		if(--tempi < 0 || --tempj < 0){
			break;
		}
		if(chess->queens_locations[tempj] == tempi){
			if(flag)printf("\n\n\n\n\n WOKED 2\n\n\n\n\n");
			return 0;
		}		
	}

	tempi = chess->queens_locations[current_column];
	tempj = current_column;
	while(1){
		if(++tempi >= chess->chess_board_size || --tempj < 0){
			break;
		}
		if(chess->queens_locations[tempj] == tempi){
			if(flag)printf("\n\n\n\n\n WOKED 3\n\n\n\n\n");
			return 0;
		}		
	}

	return 1;
}
void waitShort(){
	long long int timer = 30000000;
	while(timer--);
}
void waitLong(){
	sleep(2);
}
void waitShortShort(){
	long long int timer = 90000000;
	while(timer--);
}

void printChessBoardAns(Chess *chess,int solution){
	for (int i = 0;i<chess->chess_board_size;i++){
		printf("\t\t ");
		for(int j = 0;j<chess->chess_board_size;j++){
			if(chess->queens_locations[j] == i){
				if(solution == 1){
					printf("\x1b[32mQ\x1b[0m   ");
				}else if (solution == 2){\
					printf("\x1b[33mQ\x1b[0m   ");
				}
				else if (solution == 3){
					printf("\x1b[34mQ\x1b[0m   ");
				}
				else if (solution == 4){
					printf("\x1b[31mQ\x1b[0m   ");
				}
			} else {
				printf("_   ");
			}		
		}
	printf("\n\n\n");
	}
	printf("\n\tTotal Solution Found : \x1b[32m%d\x1b[0m\n\n",chess->total);
	printf("\tRecursion count (For next solution) : \x1b[32m%d\x1b[0m\n\n",chess->recurstion);
	printf("\tBacktrack count (For next solution) : \x1b[32m%d\x1b[0m\n\n",chess->backTrack);
	
}



void printAlgoInfo(int type){
	printf("\n\t\x1b[42m8 Queen Puzzle Algorithm Visualization !!\x1b[0m\n\n\t");
	switch (type){
		case 1:
			printf("Loop  ");
			printf("\x1b[43m  \x1b[0m       ");
			printf("Recursion Call  ");
			printf("         ");
			printf("BackTrack  ");
			printf("         ");
			printf("Solution  ");
			printf("         ");
			break;
		case 2:
			printf("Loop  ");
			printf("         ");
			printf("Recursion Call  ");
			printf("\x1b[44m  \x1b[0m       ");
			printf("BackTrack  ");
			printf("         ");
			printf("Solution  ");
			printf("         ");
			break;
		case 3:
			printf("Loop  ");
			printf("         ");
			printf("Recursion Call  ");
			printf("         ");
			printf("BackTrack  ");
			printf("\x1b[41m  \x1b[0m       ");
			printf("Solution  ");
			printf("         ");
			break;
		case 4:
			printf("Loop  ");
			printf("         ");
			printf("Recursion Call  ");
			printf("         ");
			printf("BackTrack  ");
			printf("         ");
			printf("Solution  ");
			printf("\x1b[42m  \x1b[0m       ");
			break;

		default:
			break;
	}
	printf("\n\n");
	printf("\n\n");
}


void placeQueens(Chess *chess,int current_column){
	for(int i = 0;i<chess->chess_board_size;i++){
		chess->queens_locations[current_column] = i;
		system("clear");
		if(i == 0){
			printAlgoInfo(2);
			printChessBoardAns(chess,3);
			waitShortShort();
		}else{
			printAlgoInfo(1);
			printChessBoardAns(chess,2);
		}
		waitShort();
		if(checkChessBoard(chess,current_column,0)){
			if((current_column + 1) >= chess->chess_board_size){
				system("clear");
				printAlgoInfo(4);
				printChessBoardAns(chess,1);
				waitLong();
				chess->total++;
				chess->recurstion = 0;
				chess->backTrack = 0;
				chess->queens_locations[current_column] = -1;
				return;
			}else{
				chess->recurstion++;
				placeQueens(chess,current_column + 1);
			}
		}
		system("clear");
		if(i == chess->chess_board_size - 1){
			printAlgoInfo(3);
			printChessBoardAns(chess,4);
			waitShortShort();
			
		}else{
			printAlgoInfo(1);
			printChessBoardAns(chess,2);
		}
		waitShort();
		chess->queens_locations[current_column] = -1;
	}
	chess->backTrack++;
}

int main(){
	Chess chess;
	chess.chess_board_size = 8;
	chess.total = 0;
	chess.recurstion = 0;
	chess.backTrack = 0;
	initializeArray(&chess);
	initializeQueenArray(&chess);
	placeQueens(&chess,0);
	printChessBoardAns(&chess,3);
	return 0;
	}