#include <iostream>
#include "func.hpp"
#pragma once

class Lexer
{
    public:
        vector< Token > lex(string code)
        {
            for (int i = 0; code[i]!='\0'; i++)
            {
                char symbol = code[i];

                if ( now=="fun" )
                {
                    Token tmptoken = Token(Tokens::Function, symbol);
                    TokensRes.push_back(tmptoken);
                    now = "start";
                }
                else if ( now=="start" )
                {
                    Token tmptoken = Token(Tokens::Start, symbol);
                    TokensRes.push_back(tmptoken);
                    now = "val";
                }
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
