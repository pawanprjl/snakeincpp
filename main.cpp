#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <Print.h>
#include <Position.h>

#define N 20
#define M 40

using namespace std;

int Field[N][M],i,j,x,y,Speed,Gy,Tail,Head,Game,Frogs,Score,a,b,HighScore;

char pos,var;


void snakeInitialization(){
    ifstream infile("high.txt");
    if(!infile){
        HighScore = 0;
    }else{
        infile>>HighScore;
    }



    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            Field[i][j]=0;
        }
    }

    x=N/2; y=M/2; Speed =99; Head = 5; Tail = 1; Score = 0; Frogs = 0; Gy = y; pos = 'd'; Game = 0;

    for(i=0;i<Head;i++){
        Gy++;
        Field[x][Gy-Head]=i+1;
    }
}

int getch_noblock(){
    if(_kbhit()){
        return _getch();
    }else{
        return -1;
    }
}

void TailRemove(){
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(Field[i][j]==Tail){
                Field[i][j]=0;
            }
        }
    }
    Tail++;
}

void Random(){
    a = 1 + rand() % 17;
    b = 1 + rand() % 7;

    if(Frogs==0 && Field[a][b]==0){
        Field[a][b] = -1;
        Frogs = 1;
        if(Speed>10 && Score!=0) Speed -= 5;
    }
}

void GameOver(){
    cout << '\a';
    Sleep(1500);
    system("CLS");

    if(Score>HighScore){
        cout<<"New Highsocre " << Score << "!!!!!";
        system("pause");
        ofstream outfile("high.txt");
        outfile<<Score<<endl;
    }

    cout<<"     Game Over !!!!!! \n\n";
    cout<<"     Press Enter to play again or ESC to exit.... \n";


    while(1){
        var = getch_noblock();
        if(var==13){
            Game=0;
            snakeInitialization();
            break;
        }else if(var==27){
            Game =1;
            break;
        }
    }
    system("CLS");
}

void ResetScreenPosition(){
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut,Position);
}

void Pozition(){
    var = getch_noblock();
    var = tolower(var);

    if(((var=='d' || var == 'a') || (var == 'w' || var == 's')) && (abs(pos-var)>5)) pos = var;

    Position p(Field,&x,&y,&Score,&Tail,&Frogs ,&Head, pos);

    if(p.GameStatus() == 1){
        GameOver();
    }

}

int main(){
    snakeInitialization();

        while(Game==0){
            Print p(Field,Head,Score,HighScore);
            Random();
            Pozition();
            TailRemove();
            Sleep(Speed);
            ResetScreenPosition( );
        }

    return 0;
}
