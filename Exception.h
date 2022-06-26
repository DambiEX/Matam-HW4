#ifndef CARD_CPP_EXCEPTION_H
#define CARD_CPP_EXCEPTION_H

#include <string>

class MtmchkinException : public std::exception{
public:
    explicit MtmchkinException(const std::string &message);
    const char *what() const noexcept override;
private:
    std::string m_message;
};

class InvalidName : public MtmchkinException{
public:
    explicit InvalidName(const std::string &name);
};

class DeckFileNotFound : public MtmchkinException {
public:
    explicit DeckFileNotFound();
};

class DeckFileInvalidSize : public MtmchkinException {
public:
    explicit DeckFileInvalidSize();
};

class DeckFileFormatError : public MtmchkinException {
public:
    explicit DeckFileFormatError(int line_number);
};

#endif //CARD_CPP_EXCEPTION_H
