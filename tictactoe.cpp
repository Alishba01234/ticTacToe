#include <iostream>
using namespace std;
//int size = 3;
//char empty = ' ';
char playerX = 'X';
char playerO = 'O';
char table[3][3];
void drawtable(){
    for (int i=0 ; i<3 ; i++) {
        for (int j=0 ; j<3 ; j++) {
            cout<<table[i][j]<<" ";
            if (j<3-1) {
                cout<<"|";
            }
        }
        cout<<endl;
        if (i<3-1) {
            cout<<"--------"<<endl;
        }
    }
}
bool isTableFull(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(table[i][j]== ' '){
                return false;
            }
        }
    }
    return true;
}
bool checkWinner(char player){
    for(int i=0;i<3;i++){
        if(table[i][0]==player&&table[i][1]==player&&table[i][2]==player){
            return true;
        }
    }
    for(int i=0;i<3;i++){
        if(table[0][i]==player&&table[1][i]==player&&table[2][i]==player){
            return true;
        }
    }
    if(table[0][0]==player&&table[1][1]==player&&table[2][2]==player){
        return true;
    }
    if(table[0][2]==player&&table[1][1]==player&&table[2][0]==player){
        return true;
    }
    return false;
}
int main(){
    int playerRow;
    int playerCol;
    char currentPlayer = playerX;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            table[i][j]=' ';
        }
    }
    cout<<"WELCOME TO OUR \"TIC TAC TOE\" GAME"<<endl;
    while(true){
        drawtable();
        cout<<currentPlayer<<" Enter row(1, 2 or 3) then column(1, 2 or 3)"<<endl;
        cin>>playerRow>>playerCol;
        //cout<<"Enter your column(0, 1 or 2)"<<endl;
        //cin>>playerCol;
        if((table[playerRow-1][playerCol-1]!=' ')||(playerRow>3||playerRow<1||playerCol<1||playerCol>3)){
            cout<<"Cannot place here. Give row and column again"<<endl;
            continue;
        }
        table[playerRow-1][playerCol-1]=currentPlayer;
        if(checkWinner(currentPlayer)){
            drawtable();
            cout<<"Wohoo! "<<currentPlayer<<" won. Congratulations "<<currentPlayer<<endl;
            return 0;
        }
        else if(isTableFull()){
            drawtable();
            cout<<"No one won. It's a tie."<<endl;
            return 0;
        }
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;
    }
    return 0;
}
