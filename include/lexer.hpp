
#pragma once

#include <string>
#include <vector>

enum class TokenType 
{
    OPEN_PAREN,
    CLOSE_PAREN,
    ATOM
};

class Token
{
public:
    Token(std::string value, TokenType type);
    std::string token_value;
    TokenType token_type;
};


class Lexer
{
public:

    Lexer(std::string input);
    std::vector<Token> tokens;
    std::string input;
    bool scan_tokens();
    int position;
};
