/**
 * @file game.h
 * @class game
 * @author Michael
 * @brief aggregrates from board
 */
#ifndef GAME_H
#define GAME_H
#include "board/board.h"

struct userInput{
    int x;
    int y;
};

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
  
        /**
        * @brief undoes the most recently completed move
        * @param none
        * 
        * @return void
        */
        void undoPrevMove();

        /**
        * @brief prompts the user for a piece to select
        * @param none
        * 
        * @return userInput
        */
        userInput user_Prompt_PieceSelection();

        /**
        * @brief checks that the current player did not attempt to select the other players pieces
        * @param currentX the x co-ord of the selected piece
        * @param currentY the y co-ord of the selected piece
        * 
        * @return bool
        */
        bool correctPlayerPieceSelected(int currentX, int currentY);

        /**
        * @brief prompts the user for a position to move the piece to
        * @param none
        * 
        * @return userInput
        */
        userInput user_Prompt_PieceMoveTo();
};

#endif