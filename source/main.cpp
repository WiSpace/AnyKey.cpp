#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "lexer.hpp"
#include "func.hpp"
#include "parser.hpp"


int main(int argc, char* argv[]) 
{
    if ( argc == 1 )
    {
        cout << "ERROR: No first argument (path to file)" << endl;
        system("pause");
        return 0;
    }

    // path to file
    string path = argv[1];

    // file
    ifstream fin(path);

    // if can't open the file
    if ( !fin.is_open() )
    {
        cout << "ERROR: Can't open file \"" << path << "\"!" << endl;
        system("pause");
        return 0;
    }
    // Read file
    string buff;
    string res;

    // read all file
    while( !fin.eof() )
    {
        getline( fin, buff );
        res += buff;
        if ( !fin.eof() ){
            res += '\n';
        }
    }
    // close file
    fin.close();

    if ( argc>2 ) {
        cout << 123 << endl;
        string path_to_syntax = argv[2];
        string buff_syntax;
        string res_syntax;

        ifstream syntax_fin(path_to_syntax);
        while( !syntax_fin.eof() )
        {
            getline( syntax_fin, buff_syntax);
            res_syntax += buff;
            if ( !fin.eof() ){
                res_syntax += '\n';
            }
        }
        cout << res_syntax << endl;
        // close file
        fin.close();
    }

    // Lexer
    Lexer lex;
    // Parser
    Parser parse;

    // get tokens
    vector< Token > TokensRes = lex.lex(res);

    // parsing
    parse.parse(TokensRes);

    return 0; 
}
