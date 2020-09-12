
#include <iostream>
#include <string>
#include "lexer.hpp"
#include "parser.hpp"

using std::cout, std::endl;

int main(int argc, char** argv)
{
    
    //std::string input = "( some another ( up ( ) ) )";
    
    auto lex = Lexer(argv[1]);
    std::cout << "Input: " << lex.input << std::endl;
    lex.scan_tokens();

    for (Token& token : lex.tokens) 
    {
        std::cout << "The value: " << token.token_value  << std::endl;
    }
    auto parser = Parser(lex.tokens);

    parser.parse_list();
    cout << "Number of tokens: " << lex.tokens.size() << endl;
    cout << "Position of cursor: " << parser.get_cursor_position() << endl;
    if (lex.tokens.size() == parser.get_cursor_position())
    {
        cout << "Parser accepted word" << endl;
    }
    else
    {
        cout << "Parser did not accept word." << endl;
    }
}