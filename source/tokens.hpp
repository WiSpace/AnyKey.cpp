#pragma once

namespace Tokens
{
    enum TokenList
    {
        Function,
        Start,
        Value,
        EndFun
    };
};

class Token {
    public:
        Tokens::TokenList TokenRes;
        char ValRes;

        Token(Tokens::TokenList Token, char val)
        {
            TokenRes = Token;
            ValRes = val;
        }
};
