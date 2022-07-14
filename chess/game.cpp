#include "game.h"

/**
* @brief validates that the entered x and y co-ords are indeed on the board and that they don't refer to a null spot on the board
* @param x x co-ord to verify   if in array bounds and is not a null spot in array
* @param y y co-ord to verify if in array bounds and is not a null spot in array
* @param board2d the game board for checking if x and y co-ord don't refer to a null spot on the board
* 
* @return bool
*/
bool checkValidity(int x, int y, piece*** board2d){
    if(x < 0 || x >= 8)return false;
    if(y < 0 || y >= 8)return false;
    if(board2d[y][x] == NULL)return false;
    return true;
}

int playersnum(int num){
    if(num == 1)return 2;
    else return 1;
}

char playercolor(int num){
    if(num == 1)return 'b';
    else return 'w';
}

game::game(){this->currentPlayerTurn = 1;this->boardgame = new board();}

game::~game(){delete this->boardgame;}

char game::playgame(){
    char endgame = 'c';
    this->boardgame->displayBoard();
    while(endgame != 'q' && endgame != 'r'){
        if(endgame == 'u')this->undoPrevMove();
        endgame = 'c';

        userInput selectedPiece = this->user_Prompt_PieceSelection();

        if(checkValidity(selectedPiece.x, selectedPiece.y, this->boardgame->getBoard())){

            if(this->correctPlayerPieceSelected(selectedPiece.x, selectedPiece.y))continue;

            this->boardgame->findOpenSpots(selectedPiece.x, selectedPiece.y);

            if(this->boardgame->spotsFound(selectedPiece.x, selectedPiece.y)){

                userInput moveTo = this->user_Prompt_PieceMoveTo();

                if(this->boardgame->verifyNewPos(selectedPiece.x, selectedPiece.y, moveTo.x, moveTo.y)){

                    this->boardgame->changePosition(selectedPiece.x, selectedPiece.y, moveTo.x, moveTo.y);
                    
                    if(this->boardgame->isKingInCheck(playercolor(this->currentPlayerTurn))
                    || this->boardgame->isKingStillInCheck(playercolor(this->currentPlayerTurn))){
                        std::cout << "you cannot play that move when your king is in risk of being checked" << std::endl;
                        this->boardgame->undoPreviousMove();
                        continue;
                    }

                    if((moveTo.x == 0 || moveTo.y == 7) && this->boardgame->getPieceTypeBoard(moveTo.x, moveTo.y) == 'p')
                        this->boardgame->upgradePawnToQueen(moveTo.x, moveTo.y, this->boardgame->getTeamColourBoard(moveTo.x, moveTo.y));
                    

                    if(this->currentPlayerTurn == 1){ this->currentPlayerTurn = 2;}
                    else if(this->currentPlayerTurn == 2){ this->currentPlayerTurn = 1;}
                }
                else{
                    std::cout << "those are invalid co-ords, please try again" << std::endl;
                }
            }
        }
        else{
            std::cout << "those are invalid co-ords, please try again" << std::endl;
        }
        this->boardgame->displayBoard();
        
        if(this->boardgame->isKingInCheck(playercolor(this->currentPlayerTurn))){
            std::cout << "your king is in risk of being checked. press r to restart the game\n";
            std::cout << "or q to exit the game or u to undo the previous move or any character to continue: ";
            std::cin >> endgame;
            continue;
        }
        std::cout << "press ctrl-c or q to exit the program\n";
        std::cout << "or enter any character to continue or press r to restart the game\n";
        std::cout << "or enter u to undo the previous move:\n";
        std::cin >> endgame;
    }
  
    if(this->boardgame->isKingStillInCheck(playercolor(this->currentPlayerTurn))){
        std::cout << "player " << playersnum(this->currentPlayerTurn) << " won.\n";
    }
    else{
        std::cout << "game has been forfeited or ended as a stalemate" << std::endl;
    }
    //returns a char containing r for replaying the game or any other character to exit the program
    return endgame;
}

void game::undoPrevMove(){
    this->boardgame->undoPreviousMove();
    this->boardgame->displayBoard();
    this->currentPlayerTurn = playersnum(this->currentPlayerTurn);
}

userInput game::user_Prompt_PieceSelection(){
    int currentX, currentY;
    std::cout << "player " << this->currentPlayerTurn << "'s turn" << std::endl;
    std::cout << "select a piece you would like to move by entering it's x and y co-ords" << std::endl;
    std::cout << "enter the x co-ord: ";
    std::cin >> currentX;
    std::cout << "enter the y co-ord: ";
    std::cin >> currentY;

    userInput data;
    data.x = currentX;
    data.y = currentY;
    return data;
}

bool game::correctPlayerPieceSelected(int currentX, int currentY){
    //its player ones turn but selected white piece
    if(this->currentPlayerTurn == 1 && this->boardgame->getTeamColourBoard(currentX, currentY) == 'w'){
        std::cout << "you tried to select player 2's white pieces" << std::endl;
        return false;
    }
    //its player twos turn but selected black piece
    if(this->currentPlayerTurn == 2 && this->boardgame->getTeamColourBoard(currentX, currentY) == 'b'){
        std::cout << "you tried to select player 1's black pieces" << std::endl;
        return false;
    }
    return true;
}

userInput game::user_Prompt_PieceMoveTo(){
    int newX, newY;
    std::cout << "enter the co-ords to move to" << std::endl;
    std::cout << "enter the x co-ord: ";
    std::cin >> newX;
    std::cout << "enter the y co-ord: ";
    std::cin >> newY;

    userInput data;
    data.x = newX;
    data.y = newY;
    return data;
}
