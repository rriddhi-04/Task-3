#include<iostream>
using namespace std;

char space[3][3]= {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int col;
char token='X';
string n1= "";
string n2= "";
bool tie=false;

void functionOne(){
    cout<<"\n  |     |  \n";
    cout<<" "<<space[0][0]<<"| "<<space[0][1]<<"   | "<<space[0][2]<<"  \n";
    cout<<"__|_____|__\n";
    cout<<"  |     |  \n";
    cout<<" "<<space[1][0]<<"| "<<space[1][1]<<"   | "<<space[1][2]<<"  \n";
    cout<<"__|_____|__\n";
    cout<<"  |     |  \n";
    cout<<" "<<space[2][0]<<"| "<<space[2][1]<<"   | "<<space[2][2]<<"  \n";
    cout<<"  |     |  \n";
}

// cout<<" "<<space[0][0]<<"| "<<space[0][1]<<"   | "<<space[0][2]<<"  \n";
// cout<<" "<<space[1][0]<<"| "<<space[1][1]<<"   | "<<space[1][2]<<"  \n";
// cout<<" "<<space[2][0]<<"| "<<space[2][1]<<"   | "<<space[2][2]<<"  \n";
void functionTwo(){
    int digit;

    if(token=='X'){
        cout<<n1<<" please enter a number: ";
        cin>>digit ;
    }
    if(token=='O'){
        cout<<n2<<" please enter a number: ";
        cin>>digit ;
    }

    if(digit==1){
        row=0;
        col=0;
    }
    if(digit==2){
        row=0;
        col=1;
    }
    if(digit==3){
        row=0;
        col=2;
    }
    if(digit==4){
        row=1;
        col=0;
    }
    if(digit==5){
        row=1;
        col=1;
    }
    if(digit==6){
        row=1;
        col=2;
    }
    if(digit==7){
        row=2;
        col=0;
    }
    if(digit==8){
        row=2;
        col=1;
    }
    if(digit==9){
        row=2;
        col=2;
    }
    else if(digit<1 || digit>9){
        cout<<"Invalid!!!"<<endl;
    }

    if(token=='X' && space[row][col] != 'X' && space[row][col]!='O'){
        space[row][col]='X';
        token='O';
    }
    else if(token=='O' && space[row][col] != 'X' && space[row][col]!='O'){
        space[row][col]='O';
        token='X';
    }
    else if(tie==true) {

        cout<<"There is no empty space!"<<endl;
        functionTwo();
    }
   
    functionOne();
}

bool functionThree(){
    for(int i=0; i<3;i++){
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i])
        return true;
    }
    if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0]){
        return true;
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3;j++){
            if(space[i][j]!='X' && space[i][j]!='O'){
                return false;
            }
        }
    }

    tie=true;
    return true;
}

int main(){

    cout<<"Enter the name of the first player: ";
    getline(cin, n1);
    cout<<"Enter the name of the second player: ";
    getline(cin, n2);
    cout<<n1<<" is player1 so he/she will play first. \n";
    cout<<n2<<" is player2 so he/she will play second.  ";

    while(!functionThree()){
        functionOne();
        functionTwo();
        functionThree();
    }

    if(token=='X' && tie== false){
        cout<<n2<<" Wins!!"<<endl;
    }
    else if(token=='O' && tie==false){
        cout<<n1<<" Wins!!"<< endl;
    }
    else {
        cout<<"It's a draw!"<<endl;
    }
}