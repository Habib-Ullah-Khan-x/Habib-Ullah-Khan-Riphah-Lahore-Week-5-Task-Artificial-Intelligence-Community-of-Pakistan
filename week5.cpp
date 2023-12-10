#include<iostream>
using namespace std;
char board[3][3]= {{'1','2','3'}, {'4','5','6'},{'7','8','9'}};
void displayBoard() {
	for(int i=0; i<3; i++) {
		cout<<"  | "<<board[i][0] << " | "<< board[i][1] << " | "<<board[i][2] << " | "<<endl;
	}
	cout<<endl;
}
bool checkWin(char symbol) {
	for(int i=0; i<3; i++) {
		if(board[i][0]==symbol && board[i][1] == symbol && board[i][2] ==symbol ||
		        (board[0][i] == symbol && board[1][i]==symbol && board[2][i]==symbol)) {

			return true;
		}
	}
	if(board[0][0]==symbol && board[1][1] == symbol && board[2][2] ==symbol ||
	        (board[0][2] == symbol && board[1][1]==symbol && board[2][0]==symbol)) {

		return true;
	}
	return false;
}
void updateBoard(int choice,char symbol) {
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(board[i][j]==choice+'0') {
				board[i][j]=symbol;
				return;
			}
		}

	}
}
int main() {
	int turn=0;
	char currentPlayer='x';
	while(true) {
		displayBoard();
		int choice;
		cout<<"Player "<<(turn%2+1)<<": Enter a number (1-9): ";
		cin>>choice;
		if(choice<1 || choice >9 || board[(choice-1)/3][(choice-1)%3] =='x' || board[(choice-1)/3][(choice-1)%3] =='o' ) {
			cout<<"Invalid input.Please Enter a valid number. "<<endl;
			continue;
		}
		updateBoard(choice,currentPlayer);
		if(checkWin(currentPlayer)) {
			displayBoard();
			cout<<"Player "<<(turn%2+1)<<" wins"<<endl;
			break;
		}
		turn++;
		currentPlayer=(turn%2==0)? 'x' : 'o';
		if(turn==9) {
			displayBoard();
			cout<<"It a draw!"<<endl;
			break;
		}
	}
	return 0;
}
