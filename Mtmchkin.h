    #ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include "Cards/all_cards.h"
#include "Players/all_players.h"
#include <list>
#include <vector>
#include <memory>
#include "Exception.h"

class Mtmchkin {

public:
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string& fileName);

    Mtmchkin(const Mtmchkin &other) = delete;

    Mtmchkin operator=(Mtmchkin &other) = delete;

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;


private:
    static const int MINIMUM_CARDS = 5;
    static const char ALPHABET_BEGIN = 'a', ALPHABET_END = 'z';
    static const char UPPERCASE_BEGIN = 'A', UPPERCASE_END = 'Z';
    static const int MIN_TEAM_SIZE = 2;
    static const int MAX_TEAM_SIZE = 6;
    static const int MAX_LEVEL = 10;
    static const int MAX_NAME_LENGTH = 15;
    static const char SPACE_BAR = ' ';

    int m_rounds;  // how many rounds the game lasted.
    int m_num_players; //how many players are in the game.
    int m_line_number; //used for exceptions in input parsing.
    std::list <std::unique_ptr<Card>> m_cards_queue; //the game deck.
    std::list <std::unique_ptr<Player>> m_players_queue; //players still playing.
    std::list <std::unique_ptr<Player>> m_leaderboard; //players who already won.
    std::list <std::unique_ptr<Player>> m_loserboard; //players who already lost.

    /*
     * receives a string of 1 card name and generates an appropriate card.
     */
    std::unique_ptr<Card> cardMaker(const std::string &str) const;

    /*
     * generates a single Monster card.
     */
    static std::unique_ptr<Monster> monsterMaker(const std::string &str) ;

    /*
     * receives input to fill the gang with monster cards.
     */
    std::unique_ptr<Gang> gangMaker(std::ifstream &source);

    /*
     * receives a deck file, and generates an entire deck.
     */
    void getCards(const std::string& fileName);

    /*
     * receives input from the user until a valid name and class are written.
     */
    static std::unique_ptr<Player> getPlayer();

    /*
     * generate the players for the game.
     */
    void getPlayers();

    /*
     * checks if player is alive and moves him to the correct queue.
     */
    bool playerIsAlive(Player *player);

    /*
     * moves a player between 2 different queues.
     * can be used to move the player to the back of the queue.
     */
    static void copyPlayer(std::list<std::unique_ptr<Player>> &source,
                           std::list<std::unique_ptr<Player>> &destination, bool reverse_order = false);

    /*
     * is called to print the leaderboard/players_queue/loserboard at the end of every round.
     */
    static int printQueue(const std::list<std::unique_ptr<Player>> &queue, int index) ;

    /*
     * returns the number of players in the game.
     */
    static int getTeamSize();

    /*
     * checks if a string is a valid class name.
     */
    static bool validClass(std::string &class_string);

    /*
     * checks if a string is a valid player name.
     */
    static bool validName(const std::string &name);
};


#endif /* MTMCHKIN_H_ */
