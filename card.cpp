#include "card.h"
#include <QRandomGenerator>

card::card()
{
    QRandomGenerator* generator;
    generator = QRandomGenerator::global();
    int randomNumber = generator->generate();
    int randomNumberInt = generator->bounded(1,4);

    front = randomNumberInt;
    currState = 0;
}
void card::flip(){
    if(currState == front){
        currState = 0;

    }
    else{
        currState = front;
    }
}

int card::getState(){
    return currState;
}

void card::setState(int currState){
    this->currState = currState;
}

int card::getFront(){
    return front;
}
