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

game::game(){this->currentPlayerTurn = 1;this->boardgame = new board();}

game::~game(){delete this->boardgame;}

char game::playgame(){
    char endgame = 'c';
    this->boardgame->displayBoard();
    while(endgame != 'q' && endgame != 'r'){
        int currentX, currentY;
        std::cout << "player " << this->currentPlayerTurn << "'s turn" << std::endl;
        std::cout << "select a piece you would like to move by entering it's y and x co-ords" << std::endl;
        std::cout << "enter the x co-ord: ";
        std::cin >> currentX;
        std::cout << "enter the y co-ord: ";
        std::cin >> currentY;
        if(checkValidity(currentX, currentY, this->boardgame->getBoard())){

            //its player ones turn but selected white piece
            if(this->currentPlayerTurn == 1 && this->boardgame->getTeamColourBoard(currentX, currentY) == 'w'){
                std::cout << "you tried to select player 2's white pieces" << std::endl;
                continue;
            }
            //its player twos turn but selected black piece
            if(this->currentPlayerTurn == 2 && this->boardgame->getTeamColourBoard(currentX, currentY) == 'b'){
                std::cout << "you tried to select player 1's black pieces" << std::endl;
                continue;
            }

            this->boardgame->findOpenSpots(currentX, currentY);
            if(this->boardgame->spotsFound(currentX, currentY)){
                int newX, newY;
                std::cout << "enter the co-ords to move to" << std::endl;
                std::cout << "enter the x co-ord: ";
                std::cin >> newX;
                std::cout << "enter the y co-ord: ";
                std::cin >> newY;
                if(this->boardgame->verifyNewPos(currentX, currentY, newX, newY)){
                    this->boardgame->changePosition(currentX, currentY, newX, newY);
                    if((newY == 0 || newY == 7) && this->boardgame->getPieceTypeBoard(newX, newY) == 'p')
                        this->boardgame->upgradePawnToQueen(newX, newY, this->boardgame->getTeamColourBoard(newX, newY));
                    
                    if(this->currentPlayerTurn == 1){ this->currentPlayerTurn = 2;}
                    else if(this->currentPlayerTurn == 2){ this->currentPlayerTurn = 1;}
                }
            }
            else{
                if(this->currentPlayerTurn == 1 && this->boardgame->isStaleMate('b')){//check if the black king is the only remaining piece
                    std::cout << "game is a stalemate, enter r to replay or enter any other character to exit the program: ";
                    std::cin >> endgame;
                    break;
                }
                else if(this->currentPlayerTurn == 2 && this->boardgame->isStaleMate('w')){//check if the black king is the only remaining piece
                    std::cout << "game is a stalemate, enter r to replay or enter any other character to exit the program: ";
                    std::cin >> endgame;
                    break;
                }
                else{
                    std::cout << "there are no open spots for this piece" << std::endl;
                }
            }
        }
        else{
            std::cout << "those are invalid co-ords, please try again" << std::endl;
        }
        this->boardgame->displayBoard();
        
        if(this->boardgame->blackischeck() || this->boardgame->whiteischeck()){
            std::cout << "player " << playersnum(this->currentPlayerTurn) << " won. press r to restart the game\n or q to exit the game: ";
            std::cin >> endgame;
            return endgame;
        }
        std::cout << "press ctrl-c or q to exit the program\n";
        std::cout << "or enter any character to continue or press r to restart the game: ";
        std::cin >> endgame;
    }

    //returns a char containing r for replaying the game or any other character to exit the program
    return endgame;
}