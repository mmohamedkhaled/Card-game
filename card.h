#ifndef CARD_H
#define CARD_H


class card
{
private:
    int currState;
    int front;
public:

    card();
    void flip();
    int getState();
    int getFront();
    void setState(int currState);
    void remove();

};

#endif // CARD_H
