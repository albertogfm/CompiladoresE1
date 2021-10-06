#ifndef LEXER_H
#define LEXER_H
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

//ANÁLISIS LÉXICO 

namespace COMPILADOR_C_1{    

    class Lexer
    {
    private:        
        const int INT = 1;
        const int FLOAT = 2;
        const int ELSE = 3;
        const int IF = 4;
        const int WHILE = 5;
        const int MAS = 6;
        const int MENOS = 7;
        const int MUL = 8;
        const int DIV = 9;
        const int ASIG = 10;
        const int LPAR = 11;
        const int RPAR = 12;
        const int ID = 13;
        const int PYC = 14;
        const int COMA = 15;
        const int NUM = 16;
        const int ESP = 17;
        const int ACEPTAR = 0;
        const int ERROR = -1;

        ifstream yyin;
        int **tableT;
        bool *acept;        
        string yytext;
        int yyline;
        char c;
        int numState, numTokens;
        map<char, int> alfabeto;

    public:
        Lexer(); //Constructor
        Lexer(string file); 
        ~Lexer(); //Destructor
        bool readAFD(string file);
        void getChar();
        bool openFile(string file);
        void closeFile();
        int yylex();
        int charToColumn();
        void printtableT();
        int token(int q);
        string getYytext();    
    };  
}

#endif