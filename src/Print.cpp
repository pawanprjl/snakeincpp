#include "Print.h"
#define N 20
#define M 40
#include <iostream>
using namespace std;

Print::Print(int Field[][M],int Head, int Score, int HighScore)
{
    for(int i=0; i<=M+1; i++)
    {
        if(i==0)
        {
            cout<<char(201);
        }
        else if(i==M+1)
        {
            cout<<char(187);
        }
        else
        {
            cout<<char(205);
        }
    }
    cout<<" Current Score: "<< Score << " HighScore: "<<HighScore;
    cout<<endl;
    for(int i=0; i<N; i++)
    {
        cout<<char(186);

        for(int j=0; j<M; j++)
        {
            if(Field[i][j]==0) cout<<" ";
            if(Field[i][j]>0 && Field[i][j]!=Head) cout<<char(176);
            if(Field[i][j]==Head) cout<<char(178);
            if(Field[i][j]==-1) cout<<char(15);
            if(j==M-1) cout<<char(186)<<endl;
        }
    }

    for(int i=0; i<=M+1; i++)
    {
        if(i==0)
        {
            cout<<char(200);
        }
        else if(i==M+1)
        {
            cout<<char(188);
        }
        else
        {
            cout<<char(205);
        }
    }
}

Print::~Print()
{
    //dtor
}
