/**
 * @file game.h
 * @class game
 * @author Michael
 * @brief aggregrates from board
 */
#ifndef GAME_H
#define GAME_H
#include "board/board.h"

class game{
    private:

        /**
        * @brief a pointer to a board object
        * 
        */
        board* boardgame;

        /**
        * @brief keeps track of which players turn it is
        * 
        */
        int currentPlayerTurn;
    public:

        /**
        * @brief game constructor initialises the boardgame pointer and starts a new game
        * @param none
        * 
        */
        game();

        /**
        * @brief deletes the boardgame pointer
        * 
        */
        ~game();

        /**
        * @brief begins playing the game, runs the game, handles user-input and controls if a game can end
        * @param none
        * 
        * @return char
        */
        char playgame();
};

#endif