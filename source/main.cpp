#include <iostream>
#include <fstream>
#include <cstdlib>
#include "lexer.hpp"
#include "func.hpp"
#include "parser.hpp"


int main(int argc, char* argv[]) 
{
    if ( argc == 1 )
    {
        cout << "ERROR: No first argument (path to file)" << endl;
    }

    string path = argv[1];

    ifstream fin(path);

    if ( !fin.is_open() )
    {
        cout << "ERROR: Can't open file \"" << path << "\"!" << endl;
    }
    else
    {
        // Read file
        string buff;
        string res;
    
        while( !fin.eof() )
        {
            getline( fin, buff );
            res += buff;
            if ( !fin.eof() ){
                res += '\n';
            }
        }
        fin.close();

        Lexer lex;
        Parser parse;
        vector< Token > TokensRes = lex.lex(res);

        // for (int i = 0; i < TokensRes.size(); i++)
        // {
        //     switch (TokensRes[i].TokenRes)
        //     {
        //         case Tokens::Function:
        //             cout << "FUNCTION : ";
        //             break;
        //         case Tokens::Value:
        //             cout << "VALUE : ";
        //             break;
                
        //         default:
        //             cout << "ELSE : ";
        //             break;
        //     }

        //     cout << TokensRes[i].ValRes << endl;
        // }

        parse.parse(TokensRes);
        // Token token = Token(Tokens::EndFun, "abc");

        // lex.lex(path);
    }

    system("pause");
    return 0; 
}
