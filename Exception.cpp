#include "Exception.h"

const std::string FORMAT_ERROR = "Deck File Error: File format error in line ";
const std::string DECK_FILE_ERROR = "Deck File Error: File not found";
const std::string INVALID_SIZE = "Deck File Error: Deck size is invalid";
const std::string THE_NAME = "The name:";
const std::string IS_INVALID = "is invalid";

MtmchkinException::MtmchkinException(const std::string &message) : m_message(message){
}

const char *MtmchkinException::what() const noexcept {
    return m_message.c_str();
}

InvalidName::InvalidName(const std::string &name) : MtmchkinException(THE_NAME + name + IS_INVALID){
}

DeckFileNotFound::DeckFileNotFound() : MtmchkinException(DECK_FILE_ERROR) {
}

DeckFileInvalidSize::DeckFileInvalidSize() : MtmchkinException(INVALID_SIZE){
}

DeckFileFormatError::DeckFileFormatError(int line_number) : MtmchkinException( FORMAT_ERROR + std::to_string(line_number)){
}


