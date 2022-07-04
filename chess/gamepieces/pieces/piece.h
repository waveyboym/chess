/**
 * @file piece.h
 * @class piece
 * @author Michael
 * @brief aggregrates from Llist and piecedata
 */
#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <string>
#include <sstream>
#include "../linkedlist/Llist.h"

class piece {
    protected:

        /**
        * @brief a char representing the team color, whether it may be 'b' for black or 'w' for white
        * 
        */
        char teamColor;

        /**
        * @brief a char representing the piece type, whether it may be a king, queen, bishop, knight, rook or pawn
        * and contains a char like 'K','q','B','k,'r' or 'p' respectively
        * 
        */
        char pieceType;

        /**
        * @brief a pointer to a linked list which carries a list of open spots for a piece to move to
        *  and is used to verify if the co-ords chosen by the player is in the list
        * 
        */
        Llist* mylist;
        
    
    public:
        /**
        * @brief a piece constructor
        * 
        * @param teamcolor initialises the teamcolor member variable
        * @param piecetype initialises the pieceType member variable
        * 
        */
        piece(char teamcolour, char piecetype);

        /**
        * @brief virtual destructor for the pieces. Also deletes the linked list
        * 
        */
        virtual ~piece();

        /**
        * @brief gets the team colour of the piece on the board whether it may be 'b' for black or 'w' for white
        * 
        * @param none
        * 
        * @return char
        */
        char getTeamColour();

        /**
        * @brief gets the piece type, whether it may be a king, queen, bishop, knight, rook or pawn
        * and returns a char like 'K','q','B','k,'r' or 'p' respectively
        * 
        * @param none
        * 
        * @return char
        */
        char getPieceType();

        /**
        * @brief gets the piece type, whether it may be K','q','B','k,'r' or 'p'
        * and displays a string of it's full name like king, queen, bishop, knight, rook or pawn 
        * respectively and iterates through the linked list displaying the open
        * positions for this piece. It return false if the list is empty, meaning no spots were found
        * and true if it isn't empty
        * 
        * @param piecetype the piece type, whether it may be K','q','B','k,'r' or 'p'
        * 
        * @return bool
        */
        bool displayOpenPositions(char piecetype);

        /**
        * @brief verify's whether the chosen position to move a piece to is in the list or not
        * and clears the list for it to be used by another piece later. Returns true if the position is there, else false
        * 
        * @param x the x co-ord to move to
        * @param y the y co-ord to move to
        * 
        * @return bool
        */
        bool verifyChosenPosition(int x , int y);

        /**
        * @brief a pure virtual void function that is used by the pieces that inherit from the piece class
        * to change the x and y co-ords private members of the piece
        * 
        * @param newX the x co-ord to change to
        * @param newY the y co-ord to change to
        * 
        * @return void
        */
        virtual void changeX_and_Y_Pos(int newX, int newY) = 0;

        /**
        * @brief a pure virtual void function that is used by the pieces that inherit from the piece class
        * to check the possible spots a piece may move to for the piece that called this function
        * 
        * @param currentboard a pointer to the 2d board array of objects
        * 
        * @return void
        */
        virtual void checkOpenSpots(piece*** currentboard) = 0;

        /**
        * @brief a pure virtual std::string function that is used by the pieces that inherit from the piece class
        * to return a string of the piece's x and y co-ord, it's teamcolor and it's piecetype
        *  , whether it may be K','q','B','k,'r' or 'p'
        * 
        * @param none
        * 
        * @return std::string
        */
        virtual std::string positionString() = 0;

        //STATIC FUNCTIONS
        /**
        * @brief returns a string of a piece depending on the piecetype passed in. 
        *The piecetype may be 'K','q','B','k,'r' or 'p'
        *and returns a string like king, queen, bishop, knight, rook or pawn respectively
        * @param piecetype piecetype of a piece on the board
        * @return std::string
        */
        static std::string determinepieceName(char piecetype);

        /**
        * @brief checks if the x and y values passed in are still within the bounds of the 8x8 board
        * 
        * @param x the new x co-ord to validate
        * @param y the new y co-ord to validate
        * 
        * @return bool
        */
        static bool checkValidity(int x, int y);

        /**
        * @brief checks if the x and y co-ords are valid by calling the checkValidity() function
        * and returns true if the proposed spot is NULL on the board, else false
        * 
        * @param x the new x co-ord to validate
        * @param y the new y co-ord to validate
        * @param currentboard a pointer to the 2d board array of piece objects
        * 
        * @return bool
        */
        static bool checkValidityAndNull(int x, int y, piece*** currentboard);

        /**
        * @brief checks if the x and y co-ords are valid by calling the checkValidity() function
        * and returns true if the proposed spot is not NULL on the board and the teamcolor is not
        * the same as this piece's color, else returns false
        * 
        * @param x the new x co-ord to validate
        * @param y the new y co-ord to validate
        * @param currentboard a pointer to the 2d board array of piece objects
        * @param teamcol the team color of the piece calling this function whether 'b' for black or 'w' for white
        * 
        * @return bool
        */
        static bool checkValidityNotNullOppTeam(int x, int y, piece*** currentboard, char teamcol);

        /**
        * @brief checks if the x and y co-ords are valid by calling the checkValidity() function
        * and returns true if the proposed spot is not NULL on the board and the teamcolor is not
        * the same as this piece's color, else returns false
        * 
        * @param x the new x co-ord to validate
        * @param y the new y co-ord to validate
        * @param currentboard a pointer to the 2d board array of piece objects
        * @param teamcol the team color of the piece calling this function whether 'b' for black or 'w' for white
        * @param nofurthersearch a reference variable which is used to stop the search once a piece of the
        * opposite team that's blocking the path is found
        *
        * 
        * @return bool
        */
        static bool checkValidityNotNullOppTeam(int x, int y, piece*** currentboard, char teamcol, bool* nofurthersearch);

        /**
        * @brief checks if the x and y values passed in are still within the bounds of the 8x8 board
        *and that the x and y co-ords are null
        * 
        * @param x the new x co-ord to validate
        * @param y the new y co-ord to validate
        * @param currentboard a pointer to the current 2d board of piece objects
        * 
        * @return bool
        */
        static bool checkIfValid(int x, int y, piece*** currentboard);
};

#endif