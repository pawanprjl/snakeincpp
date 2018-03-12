#include "Position.h"
#include <iostream>
using namespace std;
#define N 20
#define M 40

int gameValue = 0;

Position::Position(int Field[][M],int *x, int *y, int *Score, int *Tail, int *Frogs ,int *Head ,char pos)
{
    if(pos=='d'){
        (*y)++;

        if(Field[*x][*y]!=0 && Field[*x][*y]!=-1) gameValue=1;

        if(*y==M) *y=0;
        if(Field[*x][*y]==-1){
            *Score +=5;
            *Tail--;
            *Tail--;
            *Frogs = 0;
        }

        (*Head)++;
        Field[*x][*y] = *Head;
    }

    if(pos=='a'){
        (*y)--;

        if(Field[*x][*y]!=0 && Field[*x][*y]!=-1) gameValue=1;

        if(*y ==-1) *y=M-1;
        if(Field[*x][*y]==-1){
            *Score +=5;
            *Tail--;
            *Tail--;
            *Frogs = 0;
        }

        (*Head)++;
        Field[*x][*y] = *Head;
    }
    if(pos=='w'){
        (*x)--;
        if(*x == -1) *x=N-1;
        if(Field[*x][*y]!=0 && Field[*x][*y]!=-1) gameValue=1;


        if(Field[*x][*y]==-1){
            *Score +=5;
            *Tail--;
            *Tail--;
            *Frogs = 0;
        }

        (*Head)++;
        Field[*x][*y] = *Head;
    }
    if(pos=='s'){
        (*x)++;

        if(*x==N) *x=0;

        if(Field[*x][*y]!=0 && Field[*x][*y]!=-1) gameValue=1;


        if(Field[*x][*y]==-1){
            *Score +=5;
            *Tail--;
            *Tail--;
            *Frogs = 0;
        }

        (*Head)++;
        Field[*x][*y] = *Head;
    }
}

Position::~Position()
{
    //dtor
}


int Position::GameStatus(){
    return gameValue;
    gameValue = 0;
};

