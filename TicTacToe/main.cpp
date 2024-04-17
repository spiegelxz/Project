//
//  main.cpp
//  TicTacToe
//
//  Created by Dastan Talantbek on 23/2/24.
//
#include <iostream>
#include <string>
using namespace std;
char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token = 'X';
bool draw = false;;
string p1 = " ";
string p2 = " ";
void functionOne(){
    
    
    
    cout<<"     |     |   "<<endl;
    cout<<space[0][0]<<"    | "<<space[0][1]<<"   |  "<<space[0][2]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |   "<<endl;
    cout<<space[1][0]<<"    | "<<space[1][1]<<"   |  "<<space[1][2]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |    "<<endl;
    cout<<space[2][0]<<"    | "<<space[2][1]<<"   |   "<<space[2][2]<<"  "<<endl;
    cout<<"     |     |   "<<endl;
    
    
}

void functionTwo(){
    int digit = 0;
    if (token == 'X'){
        cout<<p1<<" please enter a number "<<endl;
        cin>>digit;
    }
    if (token == 'O'){
        cout<<p2<<" please enter a number "<<endl;
        cin>>digit;
    
    }
    if (digit==1){
        row = 0;
        column = 0;
    }if (digit==2){
        row = 0;
        column = 1;
    }if (digit==3){
        row = 0;
        column = 2;
    }if (digit==4){
        row = 1;
        column = 0;
    }if (digit==5){
        row = 1;
        column = 1;
    }if (digit==6){
        row = 1;
        column = 2;
    }if (digit==7){
        row = 2;
        column = 0;
    }if (digit==8){
        row = 2;
        column = 1;
    }if (digit==9){
        row = 2;
        column = 2;
    }
    else if(digit<1 || digit>9) {
        cout<<" Invalid !! "<<endl;
    }
    if(token == 'X' && space[row][column] != 'X' && space[row][column] != 'O'){
        space[row][column] = 'X';
        token = 'O';
    }
    else if (token == 'O' && space[row][column] != 'X' && space[row][column] != 'O'){
        space[row][column] = 'O';
        token = 'X';
    }
    else{
        cout<<"There is no empty space! "<<endl;
        functionTwo();
    }
    functionOne();
    
    
}
bool functionThree(){
    for(int i = 0; i < 3; i++){
        if((space[i][0]==space[i][1] && space[i][0]==space[i][2]) || (space[0][i]==space[1][i] && space[0][i]==space[2][i]))
            return true;
    }
    if((space[0][0]==space[1][1] && space[1][1]==space[2][2]) || (space[0][2]==space[1][1] && space[1][1]==space[2][0]))
    {
        return true;
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(space[i][j]!= 'X' && space[i][j]!= 'O'){
                return false;
            }
           
        }
       
    }
    draw = true;
    return false;
    
}

int main(){
    cout<<" Enter the name of the first player: "<<endl;
    getline(cin, p1);
    cout<<" Enter the name of the second player: "<<endl;
    getline(cin, p2);
    cout<<p1<<" is player1 so he will move first "<<endl;
    cout<<p2<<" is player2 so he will move second "<<endl;
    
    while(!functionThree()){
        functionOne();
        functionTwo();
        functionThree();
        
    }
    if(token=='X' && draw == false){
        cout<<p2<<" is the Winner! "<<endl;
    }
         if (token == 'O' && draw == false){
        cout<<p1<<" is the Winner! "<<endl;
    }
    else
    {
        cout<<" It's a Draw! "<<endl;
        
}
}
