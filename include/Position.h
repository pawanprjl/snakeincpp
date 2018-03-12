#ifndef POSITION_H
#define POSITION_H
#define M 40

class Position
{
    public:
        Position(int Field[][M],int *x, int *y, int *Score, int *Tail, int *Frogs ,int *Head , char pos);
        virtual ~Position();
        int GameStatus();

    protected:

    private:
};

#endif // POSITION_H
