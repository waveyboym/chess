#include "Llist.h"
#include <iostream>

Llist::Llist(){this->head = NULL; this->listSize = 0;}

Llist::~Llist(){
    if(this->head == NULL || this->listSize == 0)return;

    XYcoords* nodePtr = this->head;
    XYcoords* nextNode;

    while(nodePtr != NULL){
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = NULL;
        nodePtr = nextNode;
    }
    this->head = NULL;
}

int Llist::size(){return this->listSize;}

XYcoords* Llist::gethead(){return this->head;}

void Llist::displayListData(){
    if(this->head == NULL)return;

    XYcoords* nodePtr = this->head;

    while(nodePtr != NULL){
        std::cout << "[" << nodePtr->x << "," << nodePtr->y << "]" << " ";
        nodePtr = nodePtr->next;
    }
    std::cout << std::endl;
}

void Llist::displayListData(XYcoords* currentNode){
    if(currentNode == NULL)return;
    std::cout << "[" << currentNode->x << "," << currentNode->y << "]" << " ";
    this->displayListData(currentNode->next);
}

void Llist::push_back(XYcoords newData){
    XYcoords* newNode = new XYcoords;
    newNode->x = newData.x;
    newNode->y = newData.y;
    newNode->next = NULL;

    if(this->head == NULL)this->head = newNode;
    else{
        XYcoords* nodePtr = this->head;

        while(nodePtr->next != NULL)nodePtr = nodePtr->next;

        nodePtr->next = newNode;
    }
    ++this->listSize;
}

void Llist::push_back(XYcoords newData, XYcoords* currentNode){
    if(this->listSize == 0 || currentNode->next == NULL){
        XYcoords* newNode = new XYcoords;
        newNode->x = newData.x;
        newNode->y = newData.y;
        newNode->next = NULL;
        if(this->listSize == 0)this->head = newNode;
        else if(currentNode->next == NULL)currentNode->next = newNode;
        ++this->listSize;
        return;
    }
    this->push_back(newData, currentNode->next);
}

bool Llist::verifyChosen(int x, int y){
    if(this->head == NULL)return false;

    XYcoords* nodePtr = this->head;
    while(nodePtr != NULL){
        if(nodePtr->x == x && nodePtr->y == y)return true;
        else nodePtr = nodePtr->next;
    }
    return false;
}

bool Llist::verifyChosen(int x, int y, XYcoords* currentNode){
    if(currentNode == NULL)return false;
    else if(currentNode->x == x && currentNode->y == y)return true;
    else return this->verifyChosen(x, y, currentNode->next);
}

void Llist::clearList(){
    if(this->head == NULL)return;

    XYcoords* nodePtr = this->head;
    XYcoords* nextNode;

    while(nodePtr != NULL){
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = NULL;
        nodePtr = nextNode;
    }
    this->head = NULL;
    this->listSize = 0;
}

void Llist::clearList(XYcoords* currentNode){
    if(currentNode == NULL)return;

    this->clearList(currentNode->next);
    delete currentNode;
    currentNode = NULL;
    --this->listSize;
}