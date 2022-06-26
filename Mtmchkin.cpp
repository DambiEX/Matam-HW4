#include "Mtmchkin.h"
#include <memory>
#include <string>
#include <fstream>


//---------------------------------------game initialization functions-------------------------//

Mtmchkin::Mtmchkin(const std::string& fileName)
        : m_rounds(), m_num_players(), m_line_number(), m_cards_queue(), m_players_queue(), m_leaderboard(), m_loserboard() {
    printStartGameMessage();
    getCards(fileName);
    getPlayers();
}

std::unique_ptr<Monster> Mtmchkin::monsterMaker(const std::string &str)
{
    if (str == Goblin::GOBLIN) { return std::unique_ptr<Monster>(new Goblin); }
    else if (str == Vampire::VAMPIRE) { return std::unique_ptr<Monster>(new Vampire); }
    else if (str == Dragon::DRAGON) { return std::unique_ptr<Monster>(new Dragon);}
    else
    {
        throw;
    }
    return nullptr;
}

std::unique_ptr<Card> Mtmchkin::cardMaker(const std::string &str) const {
    if (str == Goblin::GOBLIN || str == Vampire::VAMPIRE || str == Dragon::DRAGON) {
        return monsterMaker(str);}
    //TODO: macros
    else if (str == Merchant::MERCHANT) { return std::unique_ptr<Merchant>(new Merchant); }
    else if (str == Pitfall::PITFALL) { return std::unique_ptr<Pitfall>(new Pitfall); }
    else if (str == Treasure::TREASURE) { return std::unique_ptr<Treasure>(new Treasure); }
    else if (str == Barfight::BARFIGHT) { return std::unique_ptr<Barfight>(new Barfight); }
    else if (str == Fairy::FAIRY) { return std::unique_ptr<Fairy>(new Fairy); }
    else {
        throw DeckFileFormatError(m_line_number);
    }
    return nullptr;
}

void Mtmchkin::getCards(const std::string& fileName) {
    std::ifstream source(fileName.c_str());
    if (!source) {
        throw DeckFileNotFound();
    }
    for (std::string line; getline(source, line);)
    {
        m_line_number++;
        if (line == Gang::GANG){
            m_cards_queue.push_back(gangMaker(source));
        }
        else{
            m_cards_queue.push_back(cardMaker(line));
        }
    }
    if (m_cards_queue.size() < MINIMUM_CARDS){
        throw DeckFileInvalidSize();
    }
}

int Mtmchkin::getTeamSize() {
    int size;
    while (true) {
        std::string input;
        printEnterTeamSizeMessage();
        std::getline(std::cin, input, '\n');
        if(Player::stringIsNumber(input))
        {
            size = std::stoi(input);
            if (size <= MAX_TEAM_SIZE && size >= MIN_TEAM_SIZE)
        {
            return size;
        } else {
            printInvalidTeamSize();
        }
        }
        else
        {
            printInvalidTeamSize();
        }
    }
}

bool Mtmchkin::validClass(std::string &class_string) {
    return (class_string == Rogue::ROGUE || class_string == Wizard::WIZARD || class_string == Fighter::FIGHTER);
}

std::unique_ptr<Player> playerMaker(std::string &name, std::string &player_class) {
    if (player_class == Rogue::ROGUE) {
        return std::unique_ptr<Rogue>(new Rogue(name));
    } else if (player_class == Wizard::WIZARD) {
        return std::unique_ptr<Wizard>(new Wizard(name));
    } else if (player_class == Fighter::FIGHTER) {
        return std::unique_ptr<Fighter>(new Fighter(name));
    }
    else
    {
        throw InvalidName(player_class);
    }
}

bool Mtmchkin::validName(const std::string& name) {
    if (name.size() > MAX_NAME_LENGTH || name.empty())
    {
        return false;
    }

    for (char letter : name)
    {
        if (!((letter >= ALPHABET_BEGIN && letter <= ALPHABET_END) ||
            (letter >= UPPERCASE_BEGIN && letter <= UPPERCASE_END))) //if not a letter
        {
            return false;
        }
    }
    return true;
}

std::unique_ptr<Player> Mtmchkin::getPlayer() {
    std::string name, player_class;
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        int position = input.find(SPACE_BAR); //location of the spacebar in the input
        name = input.substr(0, position); // name is everything until the spacebar.
        try{
            player_class = input.substr(position+1);
        }
        catch (...){
            printInvalidClass();
            continue;
        }
        if (!validName(name))
        {
            printInvalidName();
        }
        else if (!validClass(player_class))
        {
            printInvalidClass();
        }
        else
        {
            return playerMaker(name, player_class);
        }
    }
}

void Mtmchkin::getPlayers() {
    int size = getTeamSize();
    for (int i = 0; i < size; ++i) {
        printInsertPlayerMessage();
        m_players_queue.push_back(getPlayer());
    }
    m_num_players = size;
}



//----------------------------------------game execution functions--------------------------------------------//

bool Mtmchkin::playerIsAlive(Player *player) {
    if (player->isKnockedOut()) {
        copyPlayer(m_players_queue, m_loserboard, true);
        return false;
    }
    else if (player->getLevel() >= MAX_LEVEL) {
        copyPlayer(m_players_queue, m_leaderboard);
        return false;
    }
    else
    {
        copyPlayer(m_players_queue, m_players_queue);
        return true; //player still active
    }
}

void Mtmchkin::copyPlayer(std::list<std::unique_ptr<Player>> & source, std::list<std::unique_ptr<Player>> &destination, bool reverse_order){
    if (reverse_order)
    {
        destination.push_front(std::move(source.front()));
    }
    else
    {
        destination.push_back(std::move(source.front()));
    }
    source.pop_front();
}

int Mtmchkin::getNumberOfRounds() const {
    return m_rounds;
}

void Mtmchkin::playRound() {
    m_rounds++;
    printRoundStartMessage(getNumberOfRounds());
    int current_players = m_num_players;
    for (int i = 0; i < current_players; ++i)
    {
        Player *current_player = m_players_queue.front().get(); //regular pointer to the first player
        Card *current_card = m_cards_queue.front().get();
        printTurnStartMessage(current_player->getName());
        current_card->activate(current_player);

        //shuffle cards to bottom of the deck:
        m_cards_queue.push_back(std::move(m_cards_queue.front()));
        m_cards_queue.pop_front();
        if (!playerIsAlive(current_player))
        {
            m_num_players--;
        }
    }
    if(isGameOver())
    {
        printGameEndMessage();
    }
}

int Mtmchkin::printQueue(const std::list<std::unique_ptr<Player>> &queue, int index) {
    int updated_index = index;
    for(const std::unique_ptr<Player>& player : queue){
        printPlayerLeaderBoard(updated_index, *player);
        updated_index++;
    }
    return updated_index;
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int index = 1;
    index = printQueue(m_leaderboard, index);
    index = printQueue(m_players_queue, index);
    printQueue(m_loserboard, index);
}

bool Mtmchkin::isGameOver() const {
    if (m_num_players == 0) {
        return true;
    }
    return false;
}

std::unique_ptr<Gang> Mtmchkin::gangMaker(std::ifstream &source)
{

    std::unique_ptr<Gang> gang(new Gang);
    for (std::string line; getline(source, line);) {
        m_line_number++;
        std::unique_ptr<Monster> new_monster;
        if (line == Goblin::GOBLIN || line == Vampire::VAMPIRE || line == Dragon::DRAGON) {
            new_monster = std::move(monsterMaker(line));
            gang->addMonster(&new_monster);
        } else if (line == Gang::END_GANG) {
            return gang;
        } else {
            throw DeckFileFormatError(m_line_number);
        }
    }
    throw DeckFileFormatError(m_line_number+1);
}







