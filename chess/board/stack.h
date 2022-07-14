/**
 * @file stack.h
 * @class stack
 * @author Michael
 * @brief inherits from piece
 */
#ifndef STACK_H
#define STACK_H

struct previousMove{
    int newX;
    int newY;
    int oldX;
    int oldY;
    bool tookOutPiece;
    char pieceTakenType;
    char pieceTakenCol;
    previousMove* below;
};

class stack{
    private:
        /**
        * @brief the x co-ord of this king
        * 
        */
        previousMove* topStack;
    public:

        /**
        * @brief the stack constructor intialises topStack to null
        * 
        * @param none
        * 
        */
        stack();

        /**
        * @brief the stack destructor destroys the stack from memory
        *
        * 
        */
        ~stack();

        /**
        * @brief pushes the mot recently completed move onto the stack
        * 
        * @param newX the new x co-ord to change to
        * @param newX the new y co-ord to change to
        * @param oldX the new x co-ord to change to
        * @param oldY the new y co-ord to change to
        * @param tookPiece the new x co-ord to change to
        * @param piecetype the new y co-ord to change to
        * @param teamcolor the team color of the piece that was captured
        * 
        * @return void
        */
        void push(int newX, int newY, int oldX, int oldY, bool tookPiece, char piecetype, char teamcolor);

        /**
        * @brief pushes the mot recently completed move onto the stack
        * 
        * @param structData a struct containing data about the most recently completed move
        * 
        * @return void
        */
        void push(previousMove structData);

        /**
        * @brief returns a struct containing data about the most recently completed move
        * 
        * @param none
        * 
        * @return void
        */
        previousMove pop();

        /**
        * @brief removes all nodes in the stack data structure
        * 
        * @param none
        * 
        * @return void
        */
        void clearStack();
};

#endif