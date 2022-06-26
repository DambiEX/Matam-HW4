#ifndef GANG_H
#define GANG_H

#include <list>
#include <memory>
#include "Monster.h"

class Gang : public Card {
public:
    static const std::string GANG;
    static const std::string END_GANG;

    Gang();

    Gang(const Gang &other);

    Gang &operator=(const Gang &other);

    ~Gang() override = default;

    /*
     * makes every monster in the gang fight against the player.
     * if he loses to one he loses to all the following.
     */
    void activate(Player *player) override;

    /*
     * adds a monster to the gang from an existing cards queue.
     */
    void addMonster(std::unique_ptr<Monster> *monster_ptr);

private:
    std::list<std::unique_ptr<Monster>> m_monsters_queue;
};


#endif //GANG_H
