#include "stack.h"
#include <iostream>

stack::stack(){this->topStack = NULL;}

stack::~stack(){
    if(this->topStack == NULL)return;

    previousMove* nodePtr = this->topStack;
    previousMove* nextNode;

    while(nodePtr != NULL){
        nextNode = nodePtr->below;
        delete nodePtr;
        nodePtr = NULL;
        nodePtr = nextNode;
    }
    this->topStack = NULL;
}

void stack::push(int newX, int newY, int oldX, int oldY, bool tookPiece, char piecetype, char teamcolor){
    previousMove* newNode = new previousMove;
    newNode->newX = newX;
    newNode->newY = newY;
    newNode->oldX = oldX;
    newNode->oldY = oldY;
    newNode->tookOutPiece = tookPiece;
    newNode->pieceTakenType = piecetype;
    newNode->pieceTakenCol = teamcolor;
    newNode->below = NULL;

    if(this->topStack == NULL)this->topStack = newNode;
    else{
        newNode->below = this->topStack;
        this->topStack = newNode;
    }
}

void stack::push(previousMove newdata){
    previousMove* newNode = new previousMove;
    newNode->newX = newdata.newX;
    newNode->newY = newdata.newY;
    newNode->oldX = newdata.oldX;
    newNode->oldY = newdata.oldY;
    newNode->tookOutPiece = newdata.tookOutPiece;
    newNode->pieceTakenType = newdata.pieceTakenType;
    newNode->pieceTakenCol = newdata.pieceTakenCol;
    newNode->below = NULL;

    if(this->topStack == NULL)this->topStack = newNode;
    else{
        newNode->below = this->topStack;
        this->topStack = newNode;
    }
}

previousMove stack::pop(){
    previousMove toReturn;
    if(this->topStack == NULL)return toReturn;
    
    toReturn.newX = this->topStack->newX;
    toReturn.newY = this->topStack->newY;
    toReturn.oldX = this->topStack->oldX;
    toReturn.oldY = this->topStack->oldY;
    toReturn.tookOutPiece = this->topStack->tookOutPiece;
    toReturn.pieceTakenType = this->topStack->pieceTakenType;
    toReturn.pieceTakenCol = this->topStack->pieceTakenCol;
    toReturn.below = NULL;

    previousMove* nodePtr = this->topStack;
    this->topStack = this->topStack->below;
    delete nodePtr;
    nodePtr = NULL;
    
    return toReturn;
}

void stack::clearStack(){
    if(this->topStack == NULL)return;

    previousMove* nodePtr = this->topStack;
    previousMove* nextNode;

    while(nodePtr != NULL){
        nextNode = nodePtr->below;
        delete nodePtr;
        nodePtr = NULL;
        nodePtr = nextNode;
    }
    this->topStack = NULL;
}