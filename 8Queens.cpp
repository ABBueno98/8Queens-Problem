#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
    int board[8][8] = {}, r=0, c=0;
    int numSolutions = 0;
    board[r][c] = 1;
Nc: c++;
    if(c == 8) goto print;
    r = -1;
Nr: r++;
    if(r == 8) goto Bt;
    // Row Test
    for(int i =0; i < c; i++){
        if(board[r][i] ==1) goto Nr;
    }
    // Up Diagonal Test
    for(int i =1; ((r-i) >= 0 && (c-i) >=0); i++){
        if(board[r-i][c-i]==1) goto Nr;
    }
    // Down Diagonal Test
    for(int i = 1; (r+i <8) && (c-i)>=0; i++){
        if (board[r+i][c-i] ==1) goto Nr;
    }
        board[r][c]=1;
        goto Nc;
//Backtrack:
Bt: c--;
    if(c==-1) return 0;
    r=0;
    while (board[r][c] !=0){
        r++;
    }
        board[r][c] =0;
        goto Nr;

//Print out all possible solutions and their outputs.
print:
    cout <<"Solution #" << ++numSolutions << ": " << endl;
    for(int i =0; i < 8; i++){
        for(int j =0; j < 8; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
    goto Bt;
}
