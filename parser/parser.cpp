#include <regex>
#include <iostream>
#include <vector>
#include <lexer.hpp>
#include <parser.hpp>
#include <stdexcept>

using std::cout, std::endl;

Parser::Parser(std::vector<Token> tokens)
{
    this->tokens = tokens;
    this->cursor = 0;
};

int Parser::get_cursor_position()
{
    return this->cursor;
}

void Parser::parse_atom() 
{
    if (this->tokens[this->cursor].token_type == TokenType::ATOM)
    {
        cout << "Found an atom" << endl;
        this->cursor++;
    }
    else
    {
        cout << "Did not find an atom at: " << this->cursor << endl;
        throw;
    }
    
    
};

void Parser::parse_list() 
{
    if (this->tokens[this->cursor].token_type == TokenType::OPEN_PAREN)
    {
        // ok, found open paren
        int tmp_cursor = 0;
        // now search for atoms and/or close paren
        cout << "Found oparen at: " << this->cursor << endl;
        this->cursor++;
        while (tmp_cursor < this->tokens.size())
        {
            if (this->tokens[this->cursor].token_type == TokenType::CLOSE_PAREN)
            {
                cout << "Found cparen at: " << this->cursor << endl;
                // return list
                this->cursor++;
                break;
            }
            else if (this->tokens[this->cursor].token_type == TokenType::OPEN_PAREN)
            {
                // recurse
                cout << "Found another oparen at: " << this->cursor << endl;
                parse_list();
            }
            else
            {
                // add atom
                cout << "Found an atom in a list at: " << this->cursor << endl;
                parse_atom();
            }   
        }
    }
    else
    {
        cout << "S-expression must start with open paren." << endl;
        throw;
    }
};

void Parser::parse_sexpr() 
{
    parse_atom();
    parse_list();
}



//<sexpr>    	:: <atom> | <list>
//<list>     	:: "(" <sexp>* ")" ;

// void parse_sexpr() { parse_atom(); parse_list()};
// void parse_atom() { is_atom };
// void parse_list() { parse_o_paren(); parse_atom; parse_atom(); ... parse_c_paren()}