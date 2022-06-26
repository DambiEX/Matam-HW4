//#include "Mtmchkin.h"
//const int MAX_ROUNDS = 100;
//const std::string DECK_FILE = "deck.txt";
//
//int main(){
//    try
//    {
//        Mtmchkin game(DECK_FILE);
//        while(!game.isGameOver() && game.getNumberOfRounds() < MAX_ROUNDS){
//            game.playRound();
//            game.printLeaderBoard();
//        }
//    }
//    catch (std::exception &except)
//    {
//        std::cout << except.what();
//        return 0;
//    }
//    return 0;
//}