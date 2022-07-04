#include "knight.h"

bool knight::can_knight_check_king(int currentX, int currentY, char teamcolor, piece*** currentboard){
    
    /*****CHECKING KNIGHT****/
    //top left
    if(piece::checkIfValid(currentX - 1, currentY - 2, currentboard)
        && currentboard[currentY - 2][currentX - 1]->getPieceType() == 'k'
        && currentboard[currentY - 2][currentX - 1]->getTeamColour() != teamcolor){
            return true;
    }
    //top-right
    if(piece::checkIfValid(currentX + 1, currentY - 2, currentboard)
        && currentboard[currentY - 2][currentX + 1]->getPieceType() == 'k'
        && currentboard[currentY - 2][currentX + 1]->getTeamColour() != teamcolor){
            return true;
    }
    //left-top
    if(piece::checkIfValid(currentX - 2, currentY - 1, currentboard)
        && currentboard[currentY - 1][currentX - 2]->getPieceType() == 'k'
        && currentboard[currentY - 1][currentX - 2]->getTeamColour() != teamcolor){
            return true;
    }
    //right-top
    if(piece::checkIfValid(currentX + 2, currentY - 1, currentboard)
        && currentboard[currentY - 1][currentX + 2]->getPieceType() == 'k'
        && currentboard[currentY - 1][currentX + 2]->getTeamColour() != teamcolor){
            return true;
    }
    //bottom-left
    if(piece::checkIfValid(currentX - 1, currentY + 2, currentboard)
        && currentboard[currentY + 2][currentX - 1]->getPieceType() == 'k'
        && currentboard[currentY + 2][currentX - 1]->getTeamColour() != teamcolor){
            return true;
    }
    //bottom-right
    if(piece::checkIfValid(currentX + 1, currentY + 2, currentboard)
        && currentboard[currentY + 2][currentX + 1]->getPieceType() == 'k'
        && currentboard[currentY + 2][currentX + 1]->getTeamColour() != teamcolor){
            return true;
    }
    //left-bottom
    if(piece::checkIfValid(currentX - 2, currentY + 1, currentboard)
        && currentboard[currentY + 1][currentX - 2]->getPieceType() == 'k'
        && currentboard[currentY + 1][currentX - 2]->getTeamColour() != teamcolor){
            return true;
    }
    //right-bottom
    if(piece::checkIfValid(currentX + 2, currentY + 1, currentboard)
        && currentboard[currentY + 1][currentX + 2]->getPieceType() == 'k'
        && currentboard[currentY + 1][currentX + 2]->getTeamColour() != teamcolor){
            return true;
    }

    //all test cases failed thus no knight can check king in this position
    return false;
}

knight::knight(int newX, int newY, char teamcolour, char piecetype)
    : piece(teamcolour, piecetype){
    this->x_pos = newX;
    this->y_pos = newY;
}

void knight::changeX_and_Y_Pos(int newX, int newY){
    this->x_pos = newX;
    this->y_pos = newY;
}

void knight::checkOpenSpots(piece*** currentboard){
    char currentTeamColour = this->getTeamColour();
    //top-left
    if(checkValidityAndNull(this->x_pos - 1, this->y_pos - 2, currentboard)
        || checkValidityNotNullOppTeam(this->x_pos - 1, this->y_pos - 2, currentboard, currentTeamColour)){
            XYcoords newCoords = {this->x_pos - 1, this->y_pos - 2};
            this->mylist->push_back(newCoords);
    }
    //top-right
    if(checkValidityAndNull(this->x_pos + 1, this->y_pos - 2, currentboard)
        || checkValidityNotNullOppTeam(this->x_pos + 1, this->y_pos - 2, currentboard, currentTeamColour)){
            XYcoords newCoords = {this->x_pos + 1, this->y_pos - 2};
            this->mylist->push_back(newCoords);
    }
    //left-top
    if(checkValidityAndNull(this->x_pos - 2, this->y_pos - 1, currentboard)
        || checkValidityNotNullOppTeam(this->x_pos - 2, this->y_pos - 1, currentboard, currentTeamColour)){
            XYcoords newCoords = {this->x_pos - 2, this->y_pos - 1};
            this->mylist->push_back(newCoords);
    }
    //right-top
    if(checkValidityAndNull(this->x_pos + 2, this->y_pos - 1, currentboard)
        || checkValidityNotNullOppTeam(this->x_pos + 2, this->y_pos - 1, currentboard, currentTeamColour)){
            XYcoords newCoords = {this->x_pos + 2, this->y_pos - 1};
            this->mylist->push_back(newCoords);
    }
    //bottom-left
    if(checkValidityAndNull(this->x_pos - 1, this->y_pos + 2, currentboard)
        || checkValidityNotNullOppTeam(this->x_pos - 1, this->y_pos + 2, currentboard, currentTeamColour)){
            XYcoords newCoords = {this->x_pos - 1, this->y_pos + 2};
            this->mylist->push_back(newCoords);
    }
    //bottom-right
    if(checkValidityAndNull(this->x_pos + 1, this->y_pos + 2, currentboard)
        || checkValidityNotNullOppTeam(this->x_pos + 1, this->y_pos + 2, currentboard, currentTeamColour)){
            XYcoords newCoords = {this->x_pos + 1, this->y_pos + 2};
            this->mylist->push_back(newCoords);
    }
    //left-bottom
    if(checkValidityAndNull(this->x_pos - 2, this->y_pos + 1, currentboard)
        || checkValidityNotNullOppTeam(this->x_pos - 2, this->y_pos + 1, currentboard, currentTeamColour)){
            XYcoords newCoords = {this->x_pos - 2, this->y_pos + 1};
            this->mylist->push_back(newCoords);
    }
    //right-bottom
    if(checkValidityAndNull(this->x_pos + 2, this->y_pos + 1, currentboard)
        || checkValidityNotNullOppTeam(this->x_pos + 2, this->y_pos + 1, currentboard, currentTeamColour)){
            XYcoords newCoords = {this->x_pos + 2, this->y_pos + 1};
            this->mylist->push_back(newCoords);
    }

}

std::string knight::positionString(){ 
    std::string xPos, yPos;
    std::stringstream ss;
    ss << this->x_pos;
    ss >> xPos;
    std::stringstream sss;
    sss << this->y_pos;
    sss >> yPos;
    std::string data = "[" + xPos + "," + yPos + "," + this->teamColor + this->pieceType + "]";
    return data;
}