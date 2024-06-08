#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map <int,bool> RowCheck;
unordered_map <int,bool> UldCheck;
unordered_map <int,bool> BldCheck;

bool isPossible(vector<vector<char> > &board, int row , int col){
    if(RowCheck[row] == true || UldCheck[row+col] == true || BldCheck[board.size()-1+col-row] == true){
        return false;
    }
    return true;
}

void printBoard(vector<vector<char> > &board){
    for (const auto& Row : board) {
        for (const auto& element : Row) {
            cout << element << " ";
        }
        cout << endl;  
    }
    cout << endl;
}

void solve(vector<vector<char> > &board , int col ){
    if(col == board.size()){
        printBoard(board);
        return ;
    }

    for(int row=0 ; row<board.size() ; ++row){
        bool p = isPossible(board,row,col);
        if(p){
            board[row][col]='Q';
            RowCheck[row] = true;
            UldCheck[row+col] = true;
            BldCheck[board.size()-1+col-row] = true;
            solve(board , col+1);
            RowCheck[row] = false;
            UldCheck[row+col] = false;
            BldCheck[board.size()-1+col-row] = false;
            board[row][col]='-';
        }
    }
}

int main(){
    int n = 4;
    
    cout << "input the size of the board : " << endl;

    int col = 0;
    vector<vector<char> > board(n,vector<char> (n,'-'));
    solve(board ,col);
    
    return 0;
}