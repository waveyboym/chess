#include "piece.h"

int piece::posArr[2];

std::string piece::determinepieceName(char piecetype){
    if(piecetype == 'p')return "pawn";
    else if(piecetype == 'r') return "rook";
    else if(piecetype == 'k')   return "knight";
    else if(piecetype == 'B') return "bishop";
    else if(piecetype == 'q') return "queen";
    else return "king";//'K'
}

bool piece::checkValidity(int x, int y){
    if(x < 0 || x >= 8)return false;
    if(y < 0 || y >= 8)return false;
    return true;
}

bool piece::checkValidityAndNull(int x, int y, piece*** currentboard){
    if(checkValidity(x, y) && currentboard[y][x] == NULL) return true;
    else return false;
}

bool piece::checkValidityNotNullOppTeam(int x, int y, piece*** currentboard, char teamcol){
    if(checkValidity(x, y) && currentboard[y][x] != NULL && currentboard[y][x]->getTeamColour() != teamcol) return true;
    else return false;
}

bool piece::checkValidityNotNullOppTeam(int x, int y, piece*** currentboard, char teamcol, bool* nofurthersearch){
    if(checkValidity(x, y) && currentboard[y][x] != NULL && currentboard[y][x]->getTeamColour() != teamcol){ 
        *nofurthersearch = true;
        return true;
    }
    else return false;
}

bool piece::checkIfValid(int x, int y, piece*** currentboard){
    if(x < 0 || x >= 8)return false;
    if(y < 0 || y >= 8)return false;
    if(currentboard[y][x] == NULL)return false;
    return true;
}

piece::piece(char teamcolour, char piecetype){
    this->mylist = new Llist();  
    this->teamColor = teamcolour; 
    this->pieceType = piecetype;
}

piece::~piece(){ if(this->mylist != NULL) delete this->mylist;}

char piece::getTeamColour(){    return this->teamColor;}

char piece::getPieceType(){      return this->pieceType;}

bool piece::displayOpenPositions(char piecetype){
    if(this->mylist->size() == 0)return false;
    std::cout << "open spots for this " << determinepieceName(piecetype) << " are:" << std::endl;
    this->mylist->displayListData();
    std::cout << std::endl;
    return true;
}

bool piece::verifyChosenPosition(int x, int y){
    if(this->mylist->verifyChosen(x, y)){
        this->mylist->clearList();
        return true;
    }

    this->mylist->clearList();
    std::cout << "invalid position chosen" << std::endl;
    return false;
}