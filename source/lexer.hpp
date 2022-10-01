#include <iostream>
#include "func.hpp"
#pragma once

class Lexer
{
    public:
        vector< Token > lex(string code)
        {
            // read all code
            for (int i = 0; code[i]!='\0'; i++)
            {
                // this symbol
                char symbol = code[i];
                
                // if now is function
                if ( now=="fun" )
                {
                    Token tmptoken = Token(Tokens::Function, symbol);
                    TokensRes.push_back(tmptoken);
                    now = "start";
                }
                // or if now is start of function
                else if ( now=="start" )
                {
                    Token tmptoken = Token(Tokens::Start, symbol);
                    TokensRes.push_back(tmptoken);
                    now = "val";
                }
                // or if this is a value of function
                else if ( now=="val" )
                {
                    Token tmptoken = Token(Tokens::Value, symbol);
                    TokensRes.push_back(tmptoken);
                    Token tmptoken2 = Token(Tokens::EndFun, symbol);
                    TokensRes.push_back(tmptoken2);
                    now = "fun";
                }
            }
            return TokensRes;
        }
    private:
        char* now = "fun";
        vector< Token > TokensRes;
};
