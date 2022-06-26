#include "Card.h"

Card::Card(const std::string &name) : m_name(name) {
    for (char letter: name) {
        if (!std::isalpha(letter) || std::isspace(letter)) {
            throw InvalidName(name);
        }
    }
}

void Card::printCard(std::ostream &stream) const {
    printCardDetails(stream, get_name());
    printEndOfCardDetails(stream);
}

std::ostream &operator<<(std::ostream &stream, Card &card) {
    card.printCard(stream);
    return stream;
}

std::string Card::get_name() const {
    return m_name;
}
