#include "game.h"

int main(){
    game* game_one = NULL;
    char gamestatus = 'r';
    std::string stars = "*********************************************************************************\n";
    std::string newGameBanner = stars + stars + "-------------------------------STARTING A NEW GAME-------------------------------\n" + stars + stars;

    while(gamestatus == 'r'){
        std::cout << newGameBanner << std::endl;
        game_one = new game();
        gamestatus = game_one->playgame();
        delete game_one;
        game_one = NULL;
    }

    if(game_one != NULL){
        delete game_one;
        game_one = NULL;
    }
    
    return 0;
}