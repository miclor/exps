#include <regex>
#include <iostream>
#include <lexer.hpp>

Token::Token(std::string value, TokenType type)
{
    token_value = value;
    token_type = type;
};


Lexer::Lexer(std::string input)
{
    this->input = input;
    position = 0;
};


bool Lexer::scan_tokens()
{
    const std::regex atom("^[a-z]+");
    const std::regex white_space("^\\s+");
    const std::regex open_paren("^\\(");
    const std::regex close_paren("^\\)");

    std::smatch smatch;

    while (position < input.length())
    {
        auto remaining_input = input.substr(position, input.length());

        if (std::regex_search(remaining_input, smatch, white_space))
        {
            // std::cout << "matched white space" << std::endl;
            position += smatch.length();
        } else 
        if (std::regex_search(remaining_input, smatch, open_paren))
        {
            position += smatch.length();
            tokens.push_back(Token(smatch.str(), TokenType::OPEN_PAREN));
            // std::cout << "matched oparen " << std::endl;
        } else if (std::regex_search(remaining_input, smatch, close_paren))
        {
            position += smatch.length();
            tokens.push_back(Token(smatch.str(), TokenType::CLOSE_PAREN));
        } else if (std::regex_search(remaining_input, smatch, atom))
        {
            position += smatch.length();
            tokens.push_back(Token(smatch.str(), TokenType::ATOM));
        } else 
        {
            std::cout << "something else:" << remaining_input << std::endl;
            throw std::runtime_error("Unknown literal found:");
        }
    }
    return true;
};
