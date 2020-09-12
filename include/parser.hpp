#pragma once
#include <vector>
#include "lexer.hpp"



class Parser
{
    
public:
    Parser(std::vector<Token> tokens);
    void parse_atom();
    void parse_list();
    void parse_sexpr();
    int get_cursor_position();

private:
    std::vector<Token> tokens;
    int cursor;

};
