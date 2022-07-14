#include "stack.h"
#include <iostream>

int main(){
    stack* newstack = new stack();
    newstack->push(0, 0, -3, -3, false, 'k', 'w');
    newstack->push(0, 0, 6, -3, true, 'K', 'b');
    newstack->push(0, 0, 8, -3, false, 'q', 'w');
    newstack->push(0, 5, -3, -3, true, 'p', 'b');
    newstack->push(0, 0, 9, -3, false, 'r', 'w');

    previousMove data = newstack->pop();
    std::cout << data.oldX << " " << data.oldY << " " << data.newX << " " << data.newY << " " << data.tookOutPiece
         << " " << data.pieceTakenType << " " << data.pieceTakenCol << std::endl;

    data = newstack->pop();
    std::cout << data.oldX << " " << data.oldY << " " << data.newX << " " << data.newY << " " << data.tookOutPiece
         << " " << data.pieceTakenType << " " << data.pieceTakenCol << std::endl;

    newstack->clearStack();

    delete newstack;
    return 0;
}