#include "board.h"
#include "../gamepieces/pieces/pawn/pawn.h"
#include "../gamepieces/pieces/rook/rook.h"
#include "../gamepieces/pieces/knight/knight.h"
#include "../gamepieces/pieces/bishop/bishop.h"
#include "../gamepieces/pieces/queen/queen.h"
#include "../gamepieces/pieces/king/king.h"

/**
* @brief returns a string of a piece depending on the piecetype passed in. 
*The piecetype may be 'K','q','B','k,'r' or 'p'
*and returns a string like king, queen, bishop, knight, rook or pawn respectively
* @param piecetype piecetype of a piece on the board
* @return std::string
*/
std::string determinePieceName(char piecetype){
    if(piecetype == 'p')return "pawn";
    else if(piecetype == 'r') return "rook";
    else if(piecetype == 'k')   return "knight";
    else if(piecetype == 'B') return "bishop";
    else if(piecetype == 'q') return "queen";
    else return "king";//'K'
}

board::board(){
    this->board2D = new piece**[this->ROWSIZE];
    for(int i = 0; i < this->ROWSIZE; ++i){
        this->board2D[i] = new piece*[this->COLSIZE];
        for(int j = 0; j < this->COLSIZE; ++j){
            this->board2D[i][j] = NULL;
        }
    }
    this->blackkingEliminated = false;
    this->whiteKingEliminated = false;
    this->initialiseBoard();

    this->outputArr = new std::string*[this->ROWSIZE];
    for(int i = 0; i < this->ROWSIZE; ++i){
        this->outputArr[i] = new std::string[this->COLSIZE];
        for(int j = 0; j < this->COLSIZE; ++j){
            this->outputArr[i][j] = "";
        }
    }
}

board::~board(){
    if(this->board2D == NULL)return;
    for(int i = 0; i < this->ROWSIZE; ++i){
        for(int j = 0; j < this->COLSIZE; ++j){
            if(this->board2D[i][j] != NULL) delete this->board2D[i][j];
        }
        if(this->board2D[i] != NULL) delete[] this->board2D[i];
    }
    delete [] this->board2D;
    this->board2D = NULL;

    for(int i = 0; i < this->ROWSIZE; ++i){
        if(this->outputArr[i] != NULL){
            delete [] this->outputArr[i];
            this->outputArr[i] = NULL;
        }
        
    }
    delete [] this->outputArr;
    this->outputArr = NULL;
}

void board::initialiseBoard(){
    //BLACK PIECES

    //pawn
    this->board2D[6][0] = new pawn(0, 6, 'b', 'p');
    this->board2D[6][1] = new pawn(1, 6, 'b', 'p');
    this->board2D[6][2] = new pawn(2, 6, 'b', 'p');
    this->board2D[6][3] = new pawn(3, 6, 'b', 'p');
    this->board2D[6][4] = new pawn(4, 6, 'b', 'p');
    this->board2D[6][5] = new pawn(5, 6, 'b', 'p');
    this->board2D[6][6] = new pawn(6, 6, 'b', 'p');
    this->board2D[6][7] = new pawn(7, 6, 'b', 'p');

    //rook
    this->board2D[7][0] = new rook(0, 7, 'b', 'r');
    this->board2D[7][7] = new rook(7, 7, 'b', 'r');

    //knight
    this->board2D[7][1] = new knight(1, 7, 'b', 'k');
    this->board2D[7][6] = new knight(6, 7, 'b', 'k');

    //bishop
    this->board2D[7][2] = new bishop(2, 7, 'b', 'B');
    this->board2D[7][5] = new bishop(5, 7, 'b', 'B');

    //queen
    this->board2D[7][3] = new queen(3, 7, 'b', 'q');

    //king
    this->board2D[7][4] = new king(4, 7, 'b', 'K');



    //WHITE PIECES

    //pawn
    this->board2D[1][0] = new pawn(0, 1, 'w', 'p');
    this->board2D[1][1] = new pawn(1, 1, 'w', 'p');
    this->board2D[1][2] = new pawn(2, 1, 'w', 'p');
    this->board2D[1][3] = new pawn(3, 1, 'w', 'p');
    this->board2D[1][4] = new pawn(4, 1, 'w', 'p');
    this->board2D[1][5] = new pawn(5, 1, 'w', 'p');
    this->board2D[1][6] = new pawn(6, 1, 'w', 'p');
    this->board2D[1][7] = new pawn(7, 1, 'w', 'p');
    //rook
    this->board2D[0][0] = new rook(0, 0, 'w', 'r');
    this->board2D[0][7] = new rook(7, 0, 'w', 'r');

    //knight
    this->board2D[0][1] = new knight(1, 0, 'w', 'k');
    this->board2D[0][6] = new knight(6, 0, 'w', 'k');

    //bishop
    this->board2D[0][2] = new bishop(2, 0, 'w', 'B');
    this->board2D[0][5] = new bishop(5, 0, 'w', 'B');

    //queen
    this->board2D[0][4] = new queen(4, 0, 'w', 'q');

    //king
    this->board2D[0][3] = new king(3, 0, 'w', 'K');
}

void board::displayBoard(){
    if(this->board2D == NULL)return;
    for(int i = 0; i < this->ROWSIZE; ++i){
        for(int j = 0; j < this->COLSIZE; ++j){
            if(this->board2D[i][j] != NULL){
                this->outputArr[i][j] = this->board2D[i][j]->positionString() + "  ";
            }
            else if(this->board2D[i][j] == NULL){
                this->outputArr[i][j] = "[-,--,-]  ";
            }
        }
    }

    std::cout << "   [-,-0,-]  [-,-1,-]  [-,-2,-]  [-,-3,-]  [-,-4,-]  [-,-5,-]  [-,-6,-]  [-,-7,-]" << std::endl;
    for(int i = 0; i < this->ROWSIZE; ++i){
        std::cout << std::endl;
        std::cout << i << "  ";
        for(int j = 0; j < this->COLSIZE; ++ j){
            std::cout << this->outputArr[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void board::changePosition(int oldX, int oldY, int newX, int newY){
    if(this->board2D[newY][newX] != NULL){
        std::cout << "eliminated: " << this->board2D[newY][newX]->getTeamColour() << " " << determinePieceName(this->board2D[newY][newX]->getPieceType()) << std::endl;
        if(this->board2D[newY][newX]->getPieceType() == 'K' && this->board2D[newY][newX]->getTeamColour() == 'w'){
            this->whiteKingEliminated = true;
        }
        else if(this->board2D[newY][newX]->getPieceType() == 'K' && this->board2D[newY][newX]->getTeamColour() == 'b'){
            this->blackkingEliminated = true;
        }

        delete this->board2D[newY][newX];
    }
    this->board2D[newY][newX] = this->board2D[oldY][oldX];
    this->board2D[newY][newX]->changeX_and_Y_Pos(newX, newY);
    this->board2D[oldY][oldX] = NULL;
}

void board::upgradePawnToQueen(int currentX, int currentY, char teamcolor){
    if(teamcolor == 'b'){
        std::cout << "upgrading black pawn to queen" << std::endl;
        delete this->board2D[currentY][currentX];
        this->board2D[currentY][currentX] = new queen(currentX, currentY, 'b', 'q');
    }
    else if(teamcolor == 'w'){
        std::cout << "upgrading white pawn to queen" << std::endl;
        delete this->board2D[currentY][currentX];
        this->board2D[currentY][currentX] = new queen(currentX, currentY, 'w', 'q');
    }
}

bool board::spotsFound(int currentX, int currentY){
    if(this->board2D[currentY][currentX]->displayOpenPositions(this->board2D[currentY][currentX]->getPieceType()))return true;
    else return false;
}

bool board::isStaleMate(char teamcolor){
    if(teamcolor == 'b'){
        int countOfBlackPieces = 0;

        for(int i = 0; i < this->ROWSIZE; ++i){
            for(int j = 0; j < this->COLSIZE; ++j){
                if(this->board2D[i][j] != NULL && this->board2D[i][j]->getTeamColour() == 'b'){
                    ++countOfBlackPieces;
                }

                if(countOfBlackPieces >= 2)return false;
            }
        }
    }
    else{
        int countOfWhitePieces = 0;

        for(int i = 0; i < this->ROWSIZE; ++i){
            for(int j = 0; j < this->COLSIZE; ++j){
                if(this->board2D[i][j] != NULL && this->board2D[i][j]->getTeamColour() == 'w'){
                    ++countOfWhitePieces;
                }

                if(countOfWhitePieces >= 2)return false;
            }
        }
    }
    return true;
}

piece*** board::getBoard(){ return this->board2D;}

void board::findOpenSpots(int currentX, int currentY){this->board2D[currentY][currentX]->checkOpenSpots(this->board2D);}

bool board::verifyNewPos(int crrntX, int crrntY, int newX, int newY){return this->board2D[crrntY][crrntX]->verifyChosenPosition(newX, newY);}

char board::getPieceTypeBoard(int currentX, int currentY){return this->board2D[currentY][currentX]->getPieceType();}

char board::getTeamColourBoard(int currentX, int currentY){return this->board2D[currentY][currentX]->getTeamColour();}

bool board::blackischeck(){return this->blackkingEliminated;}

bool board::whiteischeck(){return this->whiteKingEliminated;}